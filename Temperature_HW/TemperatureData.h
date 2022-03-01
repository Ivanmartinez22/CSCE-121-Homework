/*
 * TemperatureData.h
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
#include <string>
using std::string;

struct TemperatureData {
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
	// Put data members here
	string id;
	int year;
	int month;
	double temperature;
	
};

#endif /* TEMPERATUREDATA */