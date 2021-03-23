#include"Product.h"
#include<iomanip> //for outputfomatting setw() 
#include"InputFunctions.h" //input validations

using std::to_string;
using namespace userInput;
using std::setw;

int Product::nextId = 9999; //initializing static variable

//default constructor
Product::Product():Product(productName,basePrice,productCategory,buyerName) {
}

//default destructor
Product::~Product() {
	delete dateOfPurchase;
}

//parametrized constructor
Product::Product(string productName, double basePrice, bool productCategory,string* buyerName) {
	this->serialNumber = nextId;
	this->nextId++;
	this->productName = productName;
	this->basePrice = basePrice;
	this->productCategory = productCategory;
	this->isPurchased = false;
	this->dateOfPurchase = nullptr;
	this->buyerName = buyerName;
}

//class member functions

int Product::getSerialNumber() {
	return serialNumber;
}

string Product::getProductName() {
	return productName;
}

string Product::getProductCategory() {
	return productCategory == true ? "Phones" : "Laptops";
}

double Product::getBasePrice() {
	return basePrice;
}

double Product::getFinalPrice() {
	return basePrice*1.15;
}

string Product::getType() {
	return "Product";
}

string Product::toString() {
	return "Serial Number : " + to_string(getSerialNumber()) + "| Name : " + getProductName() + 
		"| Category : " + getProductCategory();
}

string Product::getInfo() {
	return "Serial Number : " + to_string(getSerialNumber()) + "| Name : " + getProductName() +
		"| Category : " + getProductCategory() + "| is Purchased : " + isItemPurchased();
}

//returns buyer name and date of purchase
string Product::getNameAndDate() {
	return "| Name : " + getBuyerName() + " | Date : " + getBuyingDate();
}

//return only purchase date
string Product::getBuyingDate() {
	dateOfPurchase = new DateTime(DateTime::getNow());
	return  dateOfPurchase->toString();
}

//return only buyer name
string Product::getBuyerName(){
	return *buyerName;
}

//set availability of item
string Product::isItemPurchased() {
	return isPurchased == true ? "Purchased" : "Not Purchased";
}

//set buyerName to name of the buyer
void Product::purchaseItem(string *name) {
	this->isPurchased = true;
	this->buyerName = name;
}
