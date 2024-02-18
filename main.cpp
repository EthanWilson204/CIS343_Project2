#include "Car.h"
#include "ServiceRecord.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

void findInInventory(std::vector<std::reference_wrapper<Car>>::iterator it, std::vector<std::reference_wrapper<Car>> &inventory, int id){

	while(it != inventory.end()){
		if(it->get().getId() == id){
			break;
		}
		it++;
	}	
}

void makeTrade(std::vector<std::reference_wrapper<Car>>& inventory, Car& tradein, Car& tradeout){
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

	//sort old inventory
	/*
	printf("Inventory after sorting will be:\n");
	std::sort(inventory.begin(), inventory.end());
	for(auto it = inventory.begin(); it != inventory.end(); ++it){
		std::cout << *it << std::endl;
	}
	
	//create a new vector with 5 new cars
	*/
	std::vector<std::reference_wrapper<Car>> newInventory;
		
	Car d(2015, "Ford Raptor");
	Car e(2020, "Toyota Rav4");
	Car f(2015, "Toyota Tacoma");
	Car g(2015, "Audi A8");
	Car h(2002, "Honda S2000");
	
	ServiceRecord one("Oil change.", 10.00f);
	ServiceRecord two("Oil change.", 20.00f);
	ServiceRecord three("Oil change.", 30.00f);
	ServiceRecord four("Oil change.", 40.00f);
	ServiceRecord five("Oil change.", 15.00f);

	d.addRecord(one);
	e.addRecord(two);
	f.addRecord(three);
	g.addRecord(four);
	h.addRecord(five);


	newInventory.push_back(d);
	newInventory.push_back(e);
	newInventory.push_back(f);
	newInventory.push_back(g);
	newInventory.push_back(h);
	
	//add random service records to each vehicle
	
	printf("\nNew inventory before sorting is:\n");
	
	for(auto new_it = newInventory.begin(); new_it != newInventory.end(); ++new_it){
		std::cout << *new_it << std::endl;
	}
	
	std::sort(newInventory.begin(), newInventory.end(), compCars);

	printf("Inventory after sorting will be:\n");
	for(auto new_it = newInventory.begin(); new_it != newInventory.end(); ++new_it){
		std::cout << *new_it << std::endl;
	}


}
