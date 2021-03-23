#pragma once
#include"Cart.h"
#include"Store.h"
class ShoppingController {
private:
	//public members

	//Cart and Store class pointer objects to manage cart and store 
	//through ShoppingController class
	Cart *myCart;
	Store *myStore;
public:
	//constructor
	ShoppingController(Store* myStore, Cart* myCart);
	//destructor
	~ShoppingController();
	//class methods
	void displayMainMenu();
	void displayCartMenu();
	void displayStoreMenu();
	void displayExitStatement();
	void aboutApplication();
};
