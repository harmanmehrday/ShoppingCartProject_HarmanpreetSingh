#include"Phones.h"

//constructor
Phones::Phones() {}
//destructor
Phones::~Phones() {}

//return type of the product
string Phones::getType() {
	return "Phones";
}

//final price with tax calculation specific to phones
double Phones::getFinalPrice(vector <Product> list,int index) {


	//phones own tax calculations
	double otherCalculations = 0;

	return otherCalculations+list[index].getFinalPrice();
}