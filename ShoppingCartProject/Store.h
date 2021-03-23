#pragma once
#include"Product.h"

class Store {
public:
	//products vector to store products available in the store to purchase
	vector <Product> productsList;
public:
	//constructor
	Store();
	//destructor
	~Store();
	//class methods
	void addProduct(string,double,bool,string);
	void addProduct();
	void showProducts();
	void removeProduct();
	void clearProducts();
	int getIndexBySerial();
	Product *getPointerByIndex();
	int productsCount();
};