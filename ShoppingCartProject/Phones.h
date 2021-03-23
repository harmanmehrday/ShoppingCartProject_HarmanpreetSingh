#pragma once
#include"Product.h"

class Phones : public Product {
public:
	//constructor
	Phones();
	Phones(string productName, double basePrice, bool productCategory, string buyerName);
	//destructor
	~Phones();
	//class members
	string getType();
	double getFinalPrice(vector <Product>,int);
};
