#include "zipcodes.h"
#include <iostream>
#include <algorithm>


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
	std::set<std::pair<int, std::string>>* availableZipcodes = new std::set<std::pair<int, std::string>>;
	std::set<std::string>* visitedZipcodes = new std::set<std::string>;

	int reqVehicle = req.getRequestedVehicle();
	std::string reqZipcode = req.getRequestedZipcode();

	// if requested zip has vehicle
	if (getZip(reqZipcode).hasVehicle(reqVehicle)) {
		return std::pair<Zipcode, int>(getZip(reqZipcode), 0);
	}
	visitedZipcodes->insert(reqZipcode);

	// adding first neighbors 
	std::map<std::string, int> neighbors = getZip(reqZipcode).getNeighbors();
	addNeighborsAvailableZipcodes(availableZipcodes, neighbors, 0, visitedZipcodes);

	while (size() > visitedZipcodes->size()) {

		// check smallest available zipcode for vehicle
		Zipcode smallestZipcode = getZip(availableZipcodes->begin()->second);
		int currentDistance = availableZipcodes->begin()->first;
		if (smallestZipcode.hasVehicle(reqVehicle)) {
			return std::make_pair(getZip(availableZipcodes->begin()->second), currentDistance);
		}
		else {
			availableZipcodes->erase(availableZipcodes->begin());
			addNeighborsAvailableZipcodes(availableZipcodes, smallestZipcode.getNeighbors(), currentDistance, visitedZipcodes);
			visitedZipcodes->insert(smallestZipcode.getCode());
		}
	}
	// throw exception here 
}

int Zipcodes::size() {
	return zips.size();
}

void Zipcodes::addNeighborsAvailableZipcodes(std::set<std::pair<int, std::string>>* availableZipcodes,
	std::map<std::string, int> neighbors,
	int currentDistance, 
	std::set<std::string>* visitedZipcodes) {
		for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
			availableZipcodes->insert((std::make_pair(it->second + currentDistance, it->first)));
		}
}



