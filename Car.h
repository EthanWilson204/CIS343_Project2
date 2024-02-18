#ifndef			__H__CAR__
#define			__H__CAR__

#include "ServiceRecord.h"
#include <string>
#include <vector>
#include <algorithm>

class Car {
	public:
		Car(int, std::string);
		Car(const Car& copy);
		bool Car::operator<(const Car& other);
		int getId() const;
		void setYear(int);
		int getYear() const;
		void setModel(std::string);
		std::string getModel() const;
		std::vector<ServiceRecord> getRecords() const;
		void addRecord(ServiceRecord);

		friend std::ostream& operator<<(std::ostream& of, const Car& car);
	private:
		static int current_id;
		int id;
		int year;
		std::string model;
		std::vector<ServiceRecord> records;

};


#endif
