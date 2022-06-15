#include <iostream>
#include "pizza_fabric.h"


int main() {

	pf::NYStore ny_store;
	pf::ChicagoStore chi_store;

	chi_store.orderPizza("cheese");
	ny_store.orderPizza("cheese");

	return 0;
}