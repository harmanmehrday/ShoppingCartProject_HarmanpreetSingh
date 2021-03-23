#include"Store.h"
#include<iomanip>
using namespace userInput;
using std::setw;

//constructor
Store::Store(){}
//destructor
Store::~Store() {}

//addproduct just by passing values for adding dummy data to the program
void Store::addProduct(string productName, double basePrice, bool productCategory, string buyerName) {
	productsList.push_back(Product(productName, basePrice, productCategory, &buyerName));
}

//function overloading addProduct() to add a product by user input
void Store::addProduct() {
	
	string newProductName;
	double newPoductPrice;
	bool newProductCategory;
	string buyersName = "";
	
	cout << "\n\tEnter Name of the product : ";
	newProductName = readLine();
	cout << "\n\tEnter base price of the product : ";
	newPoductPrice = readDouble();
	cout << "\n\tEnter Product Category (1 for Phones | 0 for Laptops) : ";
	newProductCategory = readBool();
	productsList.push_back(Product(newProductName,newPoductPrice,newProductCategory,&buyersName));
}

//func to display products in cart

void Store::showProducts() {
	if (productsList.empty()) {
		cout << "\n\tNothing to Show, Store is empty!";
	}
	else {
		cout << "\t ---------------------------------------------------------------------------------------------------\n";
		cout << setw(20) << "Index" << setw(20) << "Serial Number" << setw(20) << "Product Name"<< setw(20) << "Product Category" << setw(20) << "Base Price" << endl;
		cout << "\t ---------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < productsList.size(); i++) {
			//cout << endl << "  " << i << " -- " << productsList[i].getInfo() << endl;
			cout << setw(20) << i << setw(20) << productsList[i].getSerialNumber() << setw(20) << productsList[i].getProductName()
				<< setw(20) << productsList[i].getProductCategory() << setw(20) << productsList[i].getBasePrice() << endl;
		}
	}
}

//func. to remove product from store

void Store::removeProduct() {
	int index = 0;
	if (productsList.empty()) {
		cout << "\n\tNothing to Remove, Store is empty!";
	}
	else {
		showProducts();
		cout << "\n\tEnter Index of the product to remove : ";
		index = readInt(0, productsList.size() - 1);
		cout << "\n\t\tPRODUCT AT INDEX " << index << " REMOVED\n";
		productsList.erase(productsList.begin() + index);
	}
}

//clear store, delete all store items

void Store::clearProducts() {
	productsList.clear();
	cout << "\n\t\tALL PRODUCTS REMOVED\n";
}

//func to search item in store by serial number

int Store::getIndexBySerial() {
	
	int serialNumber=0,index=0;
	bool flag=false;
	
	if (productsList.empty()) {
		return -2;
	}
	else {
		cout << "\n\tEnter serial number : ";
		serialNumber = readInt();
		for (int i = 0; i < productsList.size(); i++) {
			if (serialNumber == productsList[i].getSerialNumber()) {
				index = i;
				flag = true;
				cout << "\t ---------------------------------------------------------------------------------------------------\n";
				cout << setw(20) << "Index" << setw(20) << "Serial Number" << setw(20) << "Product Name" << setw(20) << "Product Category" << setw(20) << "Base Price" << endl;
				cout << "\t ---------------------------------------------------------------------------------------------------\n";
			    cout << setw(20) << index << setw(20) << productsList[index].getSerialNumber() << setw(20) << productsList[index].getProductName()
				<< setw(20) << productsList[index].getProductCategory() << setw(20) << productsList[index].getBasePrice() << endl;
				break;
			}
		}
		return flag == true ? index : -1;
	}
}

//func return Product pointer to the index specific item

Product* Store::getPointerByIndex() {
	
	int index=0;
	if (productsList.empty()) {
		cout << "\n\tStore is empty!";
		return nullptr;
	}
	else {
		cout << "\n\tEnter Index of the product : ";
		return &(productsList[index]);
	}
}

//func return total no of items in cart

int Store::productsCount() {
	return productsList.size();
}