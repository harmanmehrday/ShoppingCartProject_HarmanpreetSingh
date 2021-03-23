#pragma once
#include"Product.h"
#include"Store.h"
#include"Phones.h"
#include"Laptops.h"

class Cart {
	//private attributes/class members
	
private:
	vector <Product> cartProductsList;
	Phones phones;
	Laptops laptops;
public:
	//public attributes
	
	//constructor
	Cart();
	//destructor
	~Cart();
	//class methods
	void addProduct(Store*);
	void showProducts();
	void showProductsWithName();
	void removeProduct(Store*);
	void clearProducts(Store*);
	void clearCartProducts();
	int getIndexBySerial();
	Product* getPointerByIndex();
	int productsCount();
	double productsBasePrice();
	double productsFinalPrice();
	void checkOut();
};

