#include "Zipcodes.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

Zipcodes::Zipcodes() {
	// empty 
}

void Zipcodes::addZipcode(std::string code, std::string neighbor, int distance) {
	std::pair<std::string, int> n(neighbor, distance);
	std::vector<std::pair<std::string, int>> v = { n };
	zips.insert({ code, v });

	if (zipExists(neighbor)) {
		//addNeighbor(neighbor, code, distance);
	}
	else {
		addZipcode(neighbor, code, distance);
	}
}

void Zipcodes::printZips() {
	cout << endl << "Zipcodes and Neighbors" << endl;
	for (auto it = zips.begin(); it != zips.end(); it++) {
		cout << it->first.data() << ":";
		for (auto i = it->second.begin(); i != it->second.end(); i++) {
			cout << "(" << i->first << ", " << i->second << "), ";
		}
		cout << endl;
	}
}

void Zipcodes::printVehicles() {
	cout << endl << "Zipcodes and available vehicles" << endl;
	map<string, vector<int>>::iterator itr;
	for (itr = vehicles.begin(); itr != vehicles.end(); ++itr) {
		cout << itr->first << ": ";
		vector<int> v = itr->second;
		std::vector<int>::iterator it = v.begin();
		for (it; it != v.end(); ++it) {
			cout << *it << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

void Zipcodes::addNeighbor(std::string code, std::string neighbor, int neighborDistance) {
	zips[code].push_back(std::make_pair(neighbor, neighborDistance));
	zips[neighbor].push_back(std::make_pair(code, neighborDistance));
}

void Zipcodes::addVehicle(std::string code, int vehicleType) {
	if (vehicles.find(code) == vehicles.end()) {
		vehicles.insert({ code,{vehicleType} });
	}
	else {
		vector<int> v = vehicles[code];
		v.push_back(vehicleType);
		vehicles[code] = v;
	}

}

bool Zipcodes::zipExists(std::string code) {
	if (zips.find(code) == zips.end()) {
		return false;
	}
	return true;
}



