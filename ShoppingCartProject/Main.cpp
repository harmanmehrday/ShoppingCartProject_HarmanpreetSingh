#include"ShoppingController.h"

void main() {

    //myStore Store class object for managing store
    Store* myStore = new Store();
    //myCart Cart class object for managing store
    Cart* myCart = new Cart(); 
    
    //dummy 
    myStore->addProduct("iPhone 11", 1533.35, 1, "");
    myStore->addProduct("Acer Predator", 999.32, 0,"");
    myStore->addProduct("HP NoteBook 2000", 2424.13, 0,"");
    myStore->addProduct("iPhone X", 2412.342, 1,"");

    //controller class for GUI
    ShoppingController c = ShoppingController(myStore,myCart);
    c.displayMainMenu();
    cout << endl << endl << endl << endl;
    
    //releasing dynamically allocated memory
    delete myStore;
    delete myCart;
    system("pause");
}