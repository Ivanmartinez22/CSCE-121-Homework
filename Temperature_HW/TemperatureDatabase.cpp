#include "TemperatureDatabase.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream ifs (filename);
	if (!ifs.is_open()) {
    	cout << "Error: Unable to open input.dat" << endl;
		return;
  	}
	string individual_line;
	while(getline(ifs, individual_line)){
		bool insert = true;
		string id_ = "";
		string year_ = "";
		string month_ = "";
		string temperature_ = "";
		int year_i;
		int month_i;
		double temp_d;
		istringstream ss(individual_line);
		ss >> id_;
		ss >> year_;
		ss >> month_;
		ss >> temperature_;
		
		if(id_ == ""){
			cout << "Error: Other invalid input" << id_ << endl;
			insert = false;
		}
		if(year_ == ""){
			cout << "Error: Other invalid input" << year_ << endl;
			insert = false;
		}
		if(month_ == ""){
			cout << "Error: Other invalid input" << month_ << endl;
			insert = false;
		}
		if(temperature_ == ""){
			cout << "Error: Other invalid input" << temperature_ << endl;
			insert = false;
		}
		if(year_.find(".") != -1){
			cout << "Error: Other invalid input" << endl;
			insert = false;
		}
		if(month_.find(".") != -1){
			cout << "Error: Other invalid input" << endl;
			insert = false;
		}
		if(insert){
			year_i = stoi(year_);
			month_i = stoi(month_);
			temp_d = stod(temperature_);
		}
		if(year_i < 1800 || year_i > 2021){
			cout << "Error: Invalid year " << year_i << endl;
			insert = false;
		}
		if(month_i < 1 || month_i > 12){
			cout << "Error: Invalid month " << month_i << endl;
			insert = false;
		}
		if(temp_d < -50.0 || temp_d > 50.0){
			cout << "Error: Invalid temperature " << temp_d << endl;
			insert = false;
		}
		if(insert){
			records.insert(id_, year_i, month_i, temp_d);
		}
		
	}
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	ifstream ifs (filename);
	if (!ifs.is_open()) {
    	cout << "Error: Unable to open input.dat" << endl;
		return;
  	}
	ofstream newFile;
	newFile.open("result.dat");
	string individual_line;
	while(getline(ifs, individual_line)){
		bool insert = true;
		string id_ = "";
		string year1_s = "";
		string year2_s = "";
		string type = "";
		int year1;
		int year2;
		int month_i;
		double temp_d;
		istringstream ss(individual_line);
		ss >> id_;
		ss >> type;
		ss >> year1;
		ss >> year2;
		if(id_ == ""){
			// cout << "Error: Other invalid input" << id_ << endl;
			insert = false;
		}
		if(year1_s == ""){
			// cout << "Error: Other invalid input" << year1 << endl;
			insert = false;
		}
		if(year2_s == ""){
			// cout << "Error: Other invalid input" << year2 << endl;
			insert = false;
		}
		if(type == ""){
			// cout << "Error: Other invalid input" << type << endl;
			insert = false;
		}
		if(year1_s.find(".") != -1){
			// cout << "Error: Other invalid input" << endl;
			insert = false;
		}
		if(year2_s.find(".") != -1){
			// cout << "Error: Other invalid input" << endl;
			insert = false;
		}
		if(type != "AVG" && type != "MODE" ){
			cout << "Error: Unsupported query" << type << endl;
			insert = false;
		}
		if(insert){
			year1 = stoi(year1_s);
			year2 = stoi(year2_s);
		}
		if(year1 < 1800 || year1 > 2021){
			insert = false;
		}
		if(year2 < 1800 || year2 > 2021){
			insert = false;
		}
		if(!insert){
			cout << "Error: Invalid range " << year1 << "-" << year2 << endl;
		}
		if(year2 > year1){
			cout << "Error: Invalid range " << year1 << "-" << year2 << endl;
			insert = false;
		}
		bool else_ = true;
		if(insert){
			else_ = false;
			if(type == "AVG"){
				Node* starting_point = records.getHead();
				Node* traveler = starting_point;
				double avg_temp = 0;
				int counter = 0;
				while(traveler != nullptr){
					if(traveler->data.id == id_ && traveler->data.year >= year1 && traveler->data.year <= year2){
						avg_temp += traveler->data.temperature;
						counter++;
					}
					traveler = traveler->next;
				}
				avg_temp /= counter;
				newFile << id_ << " " << type << " " << year1 << " " << year2 << endl; // change to file write 
			}
			if(type == "MODE"){
				Node* starting_point = records.getHead();
				Node* traveler = starting_point;
				double avg_temp = 0;
				int counter = 0;
				while(traveler != nullptr){
					if(traveler->data.id == id_ && traveler->data.year >= year1 && traveler->data.year <= year2){
						avg_temp += traveler->data.temperature;
						counter++;
					}
					traveler = traveler->next;
				}
				avg_temp /= counter;
				newFile << id_ << " " << type << " " << year1 << " " << year2 << endl; // change to file write 
			}	
		}
		if(else_){
			newFile << id_ << " " << type << " " << year1 << " " << year2 << endl;
		}
		newFile.close();
	}
	//  Leave it blank for part 1
}
