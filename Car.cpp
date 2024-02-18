//Author: Ethan Wilson


#include "Car.h"
#include "ServiceRecord.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

int Car::current_id = 0;

Car::Car(int year, std::string model){
	this->id = Car::current_id++;
	this->year = year;
	this->model = model;
}


Car::Car(const Car& copy){
	this->records = copy.records;
	this->id = Car::current_id++;
	this->year = copy.year;
	this->model = copy.model;
}

bool Car::operator<(const Car& other) const{

        double sum_other = 0.0, sum_this = 0.0;

        for(const auto& record : this->records){
                sum_this += record.getCost();
        }
        for(const auto& record : other.records){
                sum_other += record.getCost();
        }

        return sum_this < sum_other;
}

bool Car::compCars(const std::reference_wrapper<Car>& a, const std::reference_wrapper<Car>& b) {

        return a.get() < b.get();

}

int Car::getId() const {
	return this->id;
}

void Car::setYear(int year){
	this->year = year;
}

int Car::getYear() const {
	return year;
}

void Car::setModel(std::string model){
	this->model = model;
}

std::string Car::getModel() const {
	return model;
}

std::vector<ServiceRecord> Car::getRecords() const {
	return records;
}

void Car::addRecord(ServiceRecord record){
	records.push_back(record);
}

std::ostream& operator<<(std::ostream& os, const Car& car){
	os << car.id << ":" << car.year << " " << car.model << std::endl;
	os << "=========================" << std::endl;
	for(auto it=car.records.begin(); it != car.records.end(); ++it){
		os << "\t" << it->getCost() << ": " << it->getNotes() << std::endl;
	}
	return os;
}
