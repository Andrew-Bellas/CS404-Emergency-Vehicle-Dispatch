#include "zipcodes.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>

Zipcodes::Zipcodes() {
	// empty 
}

void Zipcodes::addZip(Zipcode zip) {
	zips[zip.getCode()] = zip;
}

bool Zipcodes::hasZip(std::string code) {
	if (zips.find(code) == zips.end()) {
		return false;
	}
	return true;
}

Zipcode& Zipcodes::getZip(std::string code) {
	return zips.at(code);
}

void Zipcodes::printZips() {
	for (auto it = zips.begin(); it != zips.end(); it++) {
		std::cout << "  Zipcode: " << it->second.getCode() << std::endl;
		it->second.displayNeighbors(); 
		it->second.displayVechles();
		std::cout << endl; 
	}
}

std::pair<Zipcode, int> Zipcodes::exectuteRequest(Request req) {
	int distance = 0;

	// string: zipcode, int: distance to requested zipcode 
	std::list<std::pair<int, std::string>> availableZipcodes;
	int reqVehicle = req.getRequestedVehicle();
	std::string reqZipcode = req.getRequestedZipcode();

	// if requested zip has vehicle
	if (getZip(reqZipcode).hasVehicle(reqVehicle)) {
		return std::pair<Zipcode, int>(getZip(reqZipcode), 0);
	}

	// adding neighbors 
	std::map<std::string, int> neighbors = getZip(reqZipcode).getNeighbors();
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		availableZipcodes.push_back(std::make_pair(neighbors.at(reqZipcode), it->first));
		availableZipcodes.sort(); // sort() uses standard < operator and std::pair.first by default
	}

	// check smallest neighbor for vehicle
	if (getZip(availableZipcodes.front().second).hasVehicle(reqVehicle)) {
		distance += distance + neighbors.at(reqZipcode);
		return std::make_pair(getZip(availableZipcodes.front().second), distance);
	}


	
}



