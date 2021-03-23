#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"InputFunctions.h"  //input validation
#include"DateTime.h"  //for date functions

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using utility::Date;
using utility::DateTime;
using utility::Strings;


class Product {
//private attributes/class members

private:
	static int nextId;
	int serialNumber;
	
	string productName;
	double basePrice;
	
	bool isPurchased;
	bool productCategory;
	DateTime* dateOfPurchase;
	string* buyerName;

public:
	//public attributes

	//constructors
	Product();
	Product(string productName, double basePrice, bool productCategory, string* buyerName);
	virtual ~Product();
	//class methods
	int getSerialNumber();
	string getProductName();
	string getProductCategory();
	double getBasePrice();
	string isItemPurchased();
	virtual double getFinalPrice();
	virtual string getType();
	virtual string toString();
	virtual string getInfo();
	string getNameAndDate();
	void purchaseItem(string*);
	string getBuyerName();
	string getBuyingDate();
};