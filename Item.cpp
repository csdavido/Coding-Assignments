//function definitions
#include "Item.hpp"

using namespace std;

Item::Item() {
	newName = "";
	newPrice = 0.0;
	newQuantity = 0;
}
Item::Item(string name, double price, int quantity) {
	newName = name;
	newPrice = price;
	newQuantity = quantity;
}

