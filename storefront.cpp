#include "storefront.h"

int storefront_c::get_seller_id() {
	return this->seller_id;
}

vector<int>* storefront_c::get_ad_ids() {
	return &this->ad_ids;
}
bool storefront_c::get_is_boosted() {
	return this->is_boosted;
}

void storefront_c::set_seller_id(int id) {
	this->seller_id = id;
}

void storefront_c::set_ad_ids(vector<int>* ids) {
	this->ad_ids = *ids;
}

void storefront_c::set_is_boosted(bool is_boosted) {
	this->is_boosted = is_boosted;
}