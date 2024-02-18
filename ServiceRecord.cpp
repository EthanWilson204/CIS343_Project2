//Author - Ethan Wilson

#include "ServiceRecord.h"

#include <chrono>
#include <string>

ServiceRecord::ServiceRecord(std::string notes, double cost){
	this->timestamp = std::chrono::system_clock::now();
	this->notes = notes;
	this->cost = cost;
}

std::chrono::time_point<std::chrono::system_clock> ServiceRecord::getTimestamp() const {
	return timestamp;
}

std::string ServiceRecord::getNotes() const {
	return notes;
}

double ServiceRecord::getCost() const {
	return cost;
}


