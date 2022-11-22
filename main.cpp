#include "connection.h"
#include "service_header.h"

user_service u_service;
seller_service s_service;
buyer_service b_service;
ad_service a_service;
vehicle_service v_service;
admin_service adm_service;

void printPrimaryMenu() {
    cout << "\n\nDo you wish to\n\t1.Log in\n\t2.Sign up\n\t0.Exit" << endl;
}

void printUserTypesMenu() {
    cout << "\n\nDo you wish to\n\t1.Sell\n\t2.Buy\n\t0.Exit" << endl;
}

void actionsMenu(user_c* logged_user, int* command);

void profileManagementMenu(user_c* logged_user, int* command);

void adminManageAds();

void adminManageObjects();

int main()
{
    user_c l_u;
    user_c* logged_user = &l_u;
    int command = -1;
    
    while (true) {
        printPrimaryMenu();
        cin >> command;
        if (command == 1)
        {
            try {
                logged_user = u_service._log_in();
                while (command != 0) {
                    actionsMenu(logged_user, &command);
                }
            }
            catch (InvalidArgumentException ex) {
                cerr << ex.what() << endl;
            }
        } 
        else if (command == 2) {
            printUserTypesMenu();
            cin >> command;
            if (command == 1)
            {
                s_service._create();
            }
            else if (command == 2) {
                b_service._create();
            }
            else if (command == 0) {
                break;
            }
            else {
                cerr << "Invalid command! Try Again!" << endl;
            }
        }
        else if (command == 0) {
            break;
        }
        else {
            cerr << "Invalid command! Try Again!" << endl;
        }
    }
}


void actionsMenu(user_c* logged_user, int* command) {
    cout << "1.Manage your profile" << endl;
    if (logged_user->get_type() == "seller") {
        cout << "2.View personal storefront" << endl;
        cout << "3.Create an ad" << endl;
        cout << "4.Update an ad" << endl;
        cout << "5.Delete an ad" << endl;
        cout << "0.Log out" << endl;

        cin >> *command;
        if (*command == 1) {
            profileManagementMenu(logged_user, command);
        }
        else if (*command == 2) {
            a_service.load_user_ads(logged_user->get_id());
        }
        else if (*command == 3) {
            int typeIdx= -1;
            cout << "Category of vehicle you're selling:\n1.Sedan\n2.Truck\n3.Motorcycle" << endl;
            cin >> typeIdx;
            
            string type = typeIdx == 1 ? "SEDANS" : typeIdx == 2 ? "TRUCKS" : "MOTORCYCLES";
            cout << "Choose your vehicle (Please enter the corresponding id):" << endl;
            v_service.get_many(type);
            
            int vehicle_id = -1;
            cin >> vehicle_id;

            a_service._create(logged_user->get_id(), vehicle_id, type);
        }
        else if (*command == 4) {
            cout << "Choose which ad you want to update:" << endl;
            a_service.load_user_ads(logged_user->get_id());
            int id; 
            cin >> id;
            a_service._update(id);
        }
        else if (*command == 5) {
            cout << "Choose which ad you want to delete:" << endl;
            a_service.load_user_ads(logged_user->get_id());
            int id;
            cin >> id;
            a_service._delete(id);
        }
        else if (*command == 0) {
            return;
        }
    }
    else if (logged_user->get_type() == "buyer") {
        cout << "2.View all storefronts\n3.View storefront of certain seller\n4.Buy by ad id" << endl;
        cin >> *command;
        if (*command == 1) {
            profileManagementMenu(logged_user, command);
        }
        else if (*command == 2) {
            a_service.load_user_ads(-1);
        }
        else if (*command == 3) {
            u_service.get_many("SELLERS");
            cout << "Enter seller id" << endl;
            int id;
            cin >> id;
            a_service.load_user_ads(id);
        }
        else if (*command == 4) {
            int ad_id;
            cout << "Enter ad id to buy" << endl;
            cin >> ad_id;

            buyer_c* buyer = b_service.get_one(logged_user->get_id());
            a_service.sell(ad_id, buyer);
        }
        
    }
    else if (logged_user->get_type() == "admin") {
        cout << "2.Manage ads\n3.Manage objects\n0.Return\n" << endl;
        cin >> *command;
        if (*command == 2) {
            adminManageAds();
        }
        else if (*command == 3 ) {
            adminManageObjects();
        }
    }
}

void profileManagementMenu(user_c* logged_user, int* command) {
    if (logged_user->get_type() == "admin") {
        cout << "Admin cannot make changes on own profile!" << endl;
        return;
    }
    cout << "1.Update profile\n2.Delete profile" << endl;
    cin >> *command;
    int id = logged_user->get_id();
    if (*command == 1) {
        if (logged_user->get_type() == "seller")
        {
            s_service._update(id);
        }
        else if (logged_user->get_type() == "buyer") {
            b_service._update(id);
        }
    }
    else if (*command == 2) {
        if (logged_user->get_type() == "seller")
        {
            s_service._delete(id);
        }
        else if (logged_user->get_type() == "buyer") {
            b_service._delete(id);
        }
    }
    else {
        cerr << "Invalid command!" << endl;
    }
};

void adminManageAds() {
    a_service.load_user_ads(-1);
    cout << "Ad id to delete: (Press 0 to exit)" << endl;
    int id;
    cin >> id;

    if (id == 0) {
        return;
    }

    a_service._delete(id);
};

void adminManageObjects() {
    int action;
    cout << "1.Update\n2.Delete" << endl;
    cin >> action;

    cout << "1.Buyers\n2.Sellers\n3.Admins\n4.Sedans\n5.Trucks\n6.Motorcycles\n0.Return\n";
    int object;
    cin >> object;
    if (object == 0) {
        return;
    }
    string type = object == 1 ? "buyers" : object == 2 ? "sellers" : object == 3 ? "admins" : object == 4 ? "sedans" : object == 5 ? "trucks" : "motorcycles";

    if (object < 4) {
        u_service.get_many(type);
    }
    else {
        v_service.get_many(type);
    }

    cout << "Enter id:\n";
    int id;
    cin >> id;

    if (action == 1) {
        adm_service._update(id, type);
    }
    else if (action == 2) {
        adm_service._delete(id, type);
    }
    else {
        cerr << "Invalid command\n";
    }
};