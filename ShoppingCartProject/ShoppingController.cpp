#include"ShoppingController.h"
#include"ConsoleMenu.h"

using namespace consoleMenu;
using namespace userInput;

//destructor
ShoppingController::~ShoppingController() {}
//constructor
ShoppingController::ShoppingController(Store* myStore, Cart* myCart) {
	this->myStore = myStore;
	this->myCart = myCart;
}

//main menu display

void ShoppingController::displayMainMenu() {
	
	cout << endl << "***************************************************************";
	cout << endl << "                     WELCOME TO STORE";
	cout << endl << "***************************************************************";
	
	vector<string> optionsMainMenu = { "Manage Store","Manage Cart","About","Exit Application" };
	
	ConsoleMenu controlMainMenu = ConsoleMenu("\n********** Main Menu **********", "Please choose option ", optionsMainMenu);
	while (true) {
		switch (controlMainMenu.displayAndGetSelection()) {
		case 1: system("cls"); displayStoreMenu(); break;
		case 2: system("cls"); displayCartMenu(); break;
		case 3: system("cls"); aboutApplication(); break;
		case 4: system("cls"); displayExitStatement(); break;
		default: cout << "\n\tInvalid choice"; break;
		}
	}
}


//store menu 
void ShoppingController::displayStoreMenu() {
	
	vector<string> optionsStoreMenu = {"Display All Products", "Add Product","Remove Product","Clear Store","Search Product by Serial Number","Main Menu","Exit Application" };
	
	ConsoleMenu controlStoreMenu = ConsoleMenu("\n************** Store Menu **************", "Please choose option ", optionsStoreMenu);
	int index = 0;
	while (true) {
		switch (controlStoreMenu.displayAndGetSelection()) {
		case 1: system("cls"); myStore->showProducts(); break;
		case 2: system("cls"); myStore->addProduct(); break;
		case 3: system("cls"); myStore->removeProduct(); break;
		case 4: system("cls"); myStore->clearProducts();break;
		case 5: system("cls"); 
			index = myStore->getIndexBySerial();
			if (index == -1) {
				cout << "\n\tProduct not found!!";
			}
			else if (index == -2) {
				cout << "\n\tStore is Empty Cannot Search..";
				break;
			}
			else {
				cout << "\n\tProduct Found at index : " << index;
			}
			break;
		case 6: system("cls"); displayMainMenu(); break;
		case 7: system("cls"); displayExitStatement(); break;
		default: cout << "\n\tInvalid choice"; break;
		}
	}
}

//cart menu
void ShoppingController::displayCartMenu() {
	
	vector<string> optionsCartMenu = { "Display All Products","Check Out", "Add Product","Remove Product","Clear Cart","Search Product by Serial Number","Main Menu","Exit Application" };

	ConsoleMenu controlCartMenu = ConsoleMenu("\n************** Cart Menu **************", "Please choose option ", optionsCartMenu);
	int index = 0;
	while (true) {
		switch (controlCartMenu.displayAndGetSelection()) {
		case 1: system("cls"); myCart->showProducts(); break;
		case 2: system("cls"); myCart->checkOut(); break;
		case 3: system("cls"); myCart->addProduct(myStore); break;
		case 4: system("cls"); myCart->removeProduct(myStore); break;
		case 5: system("cls"); myCart->clearProducts(myStore); cout << "\n\t\tALL PRODUCTS REMOVED"; break;
		case 6: system("cls"); 
			index = myCart->getIndexBySerial();
			if (index == -1) {
				cout << "\n\tProduct not found!!";
			}
			else if (index == -2) {
				cout << "\n\tCart is Empty Cannot Search..";
				break;
			}
			else {
				cout << "\n\tProduct Found at index : " << index;
			}
			break;
		case 7: system("cls"); displayMainMenu(); break;
		case 8: system("cls"); displayExitStatement(); break;
		default: cout << "\n\tInvalid choice"; break;
		}
	}
}

//about application
void ShoppingController::aboutApplication() {
	cout << endl <<   "************************ Final Project ************************\n";
	cout << endl << "\n  COURCE: D03 C++ Introduction to object-oriented programming.";
	cout << endl << "\n  Title : Shopping Cart Project";
	cout << endl << "\n  Developed by : Harmanpreet Singh, Abhin Shiny James Allil";
	cout << endl << "\n  Submitted to : Braden Chevalier\n";
	cout << endl << "\n***************************************************************\n";
}

//exit function
void ShoppingController::displayExitStatement() {
	cout << "\nThankyou For Using Store Manager. Have a Good Day . . . .\n\n";
	system("pause");
	exit(0);
}
