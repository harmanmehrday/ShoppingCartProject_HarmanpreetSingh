#include"Laptops.h"

//constructor
Laptops::Laptops(){}
//destructor
Laptops::~Laptops() {}

//return type of the product
string Laptops::getType() {
	return "Laptops";
}

//final price with tax calculation specific to laptops
double Laptops::getFinalPrice(vector <Product> list, int index) {
	//laptops own tax calculations
	double otherCalculations = 0;

	return otherCalculations+list[index].getFinalPrice();
}