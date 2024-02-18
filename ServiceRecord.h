#ifndef		__H__SERVICE_RECORD__
#define		__H__SERVICE_RECORD__

#include <chrono>
#include <string>

class ServiceRecord {
	public:
		ServiceRecord(std::string, double);
		std::chrono::time_point<std::chrono::system_clock> getTimestamp() const;
		std::string getNotes() const;
		double getCost() const;
	
	private:
		std::chrono::time_point<std::chrono::system_clock> timestamp;
		std::string notes;		
		double cost;
};


#endif
