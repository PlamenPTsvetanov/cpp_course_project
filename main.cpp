#include "u_user_service.h"
#include "connection.h"
int main()
{	
	user user;
	user.set_family("Nov");
	user.set_name("Test");
	user.set_password("123213");
	user.set_role("Admin");
	user.set_username("t3st");

	connection con;
	try {
		con.init();
		int idx = 1;

		PreparedStatement* pstmt = con.set_prepared_statement("INSERT INTO USERS VALUES(?, ?, ?, ?, ?, ?)");
		pstmt->setInt(idx++, 0);
		pstmt->setString(idx++, user.get_name());
		pstmt->setString(idx++, user.get_family());
		pstmt->setString(idx++, user.get_username());
		pstmt->setString(idx++, user.get_password());
		pstmt->setString(idx, user.get_role());
		
		pstmt->execute();
	}
	catch (sql::SQLException e) {
		cout << "Error message: " << e.what() << endl;
	}

    return 0;
}