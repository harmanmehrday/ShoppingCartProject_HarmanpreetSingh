#pragma once
#include"Product.h"

class Laptops : public Product {
public:
	//constructor
	Laptops();
	//destructor
	~Laptops();
	
	//class methods
	string getType();
	double getFinalPrice(vector <Product>, int);
};
