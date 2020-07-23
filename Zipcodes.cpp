#include "zipcodes.h"
#include <vector>
#include <map>
#include <string>
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



