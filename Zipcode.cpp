#include "zipcode.h"
#include <algorithm>
#include <iostream>
#include <string>

Zipcode::Zipcode() {
	code = "";
}

Zipcode::Zipcode(std::string zipcode) {
	code = zipcode;
}

bool Zipcode::hasVehicle(int type) {
	for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
		if(it->getType() == type)
			return true; 
	}
	return false;
}

void Zipcode::removeVehicle(int type) {
	for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
		if (it->getType() == type)
			vehicles.erase(it);
	}
}

void Zipcode::addVehicle(int type, int id) {
	Vehicle v(type, id);
	vehicles.push_back(v);
}

bool Zipcode::hasNeighbor(std::string code) {
	if (neighbors.find(code) == neighbors.end()) {
		return false;
	}
	return true;
}

void Zipcode::removeNeighbor(std::string code) { 
	auto it = neighbors.find(code);

	if (it != neighbors.end())
		neighbors.erase(it);
}

void Zipcode::addNeighbor(std::string code, int distance) {
	neighbors[code] = distance;
}

std::map<std::string, int> Zipcode::getNeighbors()
{
	return neighbors;
}

int Zipcode::getNeighborDistance(std::string code)
{
	if (hasNeighbor(code)) {
		return neighbors[code];
	}
	else {
		return -1;
	}
}

std::string Zipcode::getCode()
{
	return code;
}

void Zipcode::displayVechles() {
	std::cout << "Vehicles:";
	for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
		std::cout << " ID: " << it->getId() << " Type:" << it->getType();
	}
	std::cout << std::endl;
}

void Zipcode::displayNeighbors() {
	std::cout << "Neighbors:";
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		std::cout << " " << it->first << "->" << it->second;
	}
	std::cout << std::endl;
}




