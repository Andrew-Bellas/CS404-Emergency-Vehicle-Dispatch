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
		addNeighbor(neighbor, code, distance);
	}
	else {
		addZipcode(neighbor, code, distance);
	}
}

void Zipcodes::printZips() {
	for (auto it = zips.begin(); it != zips.end(); it++) {
		cout << it->first.data() << ":";
		for (auto i = it->second.begin(); i != it->second.end(); i++) {
			cout << "(" << i->first << ", " << i->second << "), ";
		}
		cout << endl;
	}
}

void Zipcodes::addNeighbor(std::string code, std::string neighbor, int neighborDistance) {
	zips[code].push_back(std::make_pair(neighbor, neighborDistance));
	zips[neighbor].push_back(std::make_pair(code, neighborDistance));
}

bool Zipcodes::zipExists(std::string code) {
	if (zips.find(code) == zips.end()) {
		return false;
	}
	return true;
}



