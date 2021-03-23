#include"Cart.h" 
#include<iomanip>//for output formatting setw()
#include"InputFunctions.h" //input validation
#include"Phones.h"
#include"Laptops.h"

using namespace userInput;//input functions namespace

using std::setw;
Cart::Cart() {}

Cart::~Cart() {}

//func to a product to cart

void Cart::addProduct(Store *myStore) {
	if (myStore->productsList.empty()) {
		cout << "\n\tNothing to Add, Store is empty!";
	}
	else {
		int index = 0;
		myStore->showProducts();
		cout << "\n\tEnter Index of the product to add ";
		index = readInt(0, myStore->productsList.size()-1);
		cartProductsList.push_back(myStore->productsList[index]);
		myStore->productsList.erase(myStore->productsList.begin() + index);
		cout << "\n\t\tPRODUCT AT INDEX " << index << " ADDED TO CART.";
	}
}

//func to display products in cart

void Cart::showProducts() {
	if (cartProductsList.empty()) {
		cout << "\n\tNothing to Show, Cart is empty!";
	}
	else {
		cout << "\t ---------------------------------------------------------------------------------------------------\n";
		cout << setw(20) << "Index" << setw(20) << "Serial Number" << setw(20) << "Product Name" << setw(20) << "Product Category" << setw(20) << "Base Price" << endl;
		cout << "\t ---------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < cartProductsList.size(); i++) {
			cout << setw(20) << i << setw(20) << cartProductsList[i].getSerialNumber() << setw(20) << cartProductsList[i].getProductName()
				<< setw(20) << cartProductsList[i].getProductCategory() << setw(20) << cartProductsList[i].getBasePrice() << endl;
		}
	}
}

//display function to print name of buyer and date of purchase 

void Cart::showProductsWithName() {
	for (int i = 0; i < cartProductsList.size(); i++) {
		cout << endl << "  " << i << " -- " << cartProductsList[i].getInfo() <<
			cartProductsList[i].getNameAndDate() << endl;
	}
}

//func. to remove product from cart and again add to store available items

void Cart::removeProduct(Store* myStore) {
	int index = 0;
	if (cartProductsList.empty()) {
		cout << "\n\tNothing to Remove, Cart is empty!";
	}
	else {
		showProducts();
		cout << "\n\tEnter Index of the product to remove : ";
		index = readInt(0, cartProductsList.size() - 1);
		cout << "\n\t\tPRODUCT AT INDEX " << index << " REMOVED";
		myStore->productsList.push_back(cartProductsList[index]);
		cartProductsList.erase(cartProductsList.begin()+index);
	}
}

//clear cart

void Cart::clearProducts(Store* myStore) {
	for (int i = 0; i < cartProductsList.size(); i++) {
		myStore->productsList.push_back(cartProductsList[i]);
	}
	cartProductsList.clear();
}

void Cart::clearCartProducts() {
	cartProductsList.clear();
}


//func to search item in cart by serial number

int Cart::getIndexBySerial() {
	int serialNumber, index = 0;
	bool flag = false;
	if (cartProductsList.empty()) {
		return -2;
	}
	else {
		cout << "\n\tEnter serial number : ";
		serialNumber = readInt();
		for (int i = 0; i < cartProductsList.size(); i++) {
			if (serialNumber == cartProductsList[i].getSerialNumber()) {
				index = i;
				flag = true;
				cout << "\t ---------------------------------------------------------------------------------------------------\n";
				cout << setw(20) << "Index" << setw(20) << "Serial Number" << setw(20) << "Product Name" << setw(20) << "Product Category" << setw(20) << "Base Price" << endl;
				cout << "\t ---------------------------------------------------------------------------------------------------\n";
				cout << setw(20) << index << setw(20) << cartProductsList[index].getSerialNumber() << setw(20) << cartProductsList[index].getProductName()
						<< setw(20) << cartProductsList[index].getProductCategory() << setw(20) << cartProductsList[index].getBasePrice() << endl;
				break;
			}
		}
		return flag == true ? index : -1;
	}
}

//func return Product pointer to the index specific item

Product* Cart::getPointerByIndex() {
	int index = 0;
	if (cartProductsList.empty()) {
		cout << "\n\tCart is empty!";
		return nullptr;
	}
	else {
		cout << "\n\tEnter Index of the product : ";
		return &(cartProductsList[index]);
	}
}

//func return total no of items in cart

int Cart::productsCount() {
	return cartProductsList.size();
}

//sum of base price of the products 

double Cart::productsBasePrice() {
	double allProductsBasePrice = 0;
	if (cartProductsList.empty()) {
		cout << "\n\tCart is empty!";
	}
	else {
		for (int i = 0; i < cartProductsList.size(); i++) {
			allProductsBasePrice += cartProductsList[i].getBasePrice();
		}
		return allProductsBasePrice;
	}
}

//sum of final price of the products

double Cart::productsFinalPrice() {
	double allProductsFinalPrice = 0;
	if (cartProductsList.empty()) {
		cout << "\n\tCart is empty!";
		return 0;
	}
	else {
		for (int i = 0; i < cartProductsList.size(); i++) {
			if (cartProductsList[i].getProductCategory()=="Phones") {
				allProductsFinalPrice+= phones.getFinalPrice(cartProductsList,i);
			}
			if (cartProductsList[i].getProductCategory()=="Laptops") {
				allProductsFinalPrice += laptops.getFinalPrice(cartProductsList, i);
			}
		}
		return allProductsFinalPrice;
	}
}

//buy all items from cart

void Cart::checkOut() {
	if (cartProductsList.empty()) {
		cout << "\n\tCart is empty!";
	}
	else {
		cout << "\n\tEnter your name : ";
		DateTime date = DateTime::getNow();
		string *name = new string(readLine());
		for (int i = 0; i < cartProductsList.size(); i++) {
			cartProductsList[i].purchaseItem(name);
		}
		system("cls");
		cout << "\t\t***********************************************************************************\n";
		cout << "\t\t                             Transaction Summary\n";
		cout << "\t\t***********************************************************************************\n";
		cout << "\t\t\tDate : "<< date.toString() <<"                        Name : "<<*name<<"\n\n";
		showProducts();
		cout << "\t ---------------------------------------------------------------------------------------------------\n";
		cout << "\t"<< setw(86)<<"Total : " << productsBasePrice()<<endl;
		cout << "\t"<< setw(86)<<"Taxes : "<<productsFinalPrice()-productsBasePrice() << endl;
		cout << "\t"<< setw(86)<<"Grand Total : " << productsFinalPrice() << endl;
		cout << "\n\n";
		system("pause");
		clearCartProducts();
		delete name;
		system("cls");
	}
} 
