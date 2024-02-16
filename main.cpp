#include "Car.h"
#include "ServiceRecord.h"
#include <iostream>
#include <functional>

void findInInventory(std::vector<std::reference_wrapper<Car>>::iterator it, std::vector<std::reference_wrapper<Car>> &inventory, int id){
	
	while(it != inventory.end()){
		if(it->get().getId() == id){
			break;
		}
		it++;
	}	
}

void makeTrade(std::vector<std::reference_wrapper<Car>> inventory, Car& tradein, Car& tradeout){
	ServiceRecord outInspection("Sale inspection.", 1.0);
	tradeout.addRecord(outInspection);

	ServiceRecord inInspection("Presale inspection.", 19.95);
	tradein.addRecord(inInspection);

	
	auto it=inventory.begin();
	std::cout << "tradein is: " << tradein << std::endl;
	std::cout << "tradeout is: " << tradeout << std::endl;
	findInInventory(it, inventory, tradeout.getId());

	
	if(it != inventory.end()){
		inventory.erase(it);
	}
	
	inventory.push_back(tradein);
}

int main(int argc, char** argv){
	Car a(1985, "Toyota Hilux");
	ServiceRecord first("Oil change.", 9.95f);
	a.addRecord(first);

	Car b(a);
	first = ServiceRecord("Radiator flush.", 19.95);
	b.addRecord(first);

	std::vector< std::reference_wrapper<Car> > inventory;
	inventory.push_back(a);
	inventory.push_back(b);
	
	Car c(b);
	c.setModel("Ford F150");

	std::cout << "Customer wants to trade in " << c << std::endl;
	std::cout << "They want to get " << a << std::endl;
	
	makeTrade(inventory, c, a);

	std::cout << "After trade, inventory is: " << std::endl;
	std::cout << "===========================" << std::endl;
	for(auto it = inventory.begin(); it != inventory.end(); ++it){
		std::cout << *it << std::endl;
	}


}
