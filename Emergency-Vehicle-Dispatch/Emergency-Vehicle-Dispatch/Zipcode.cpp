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
	if (std::find(vehicles.begin(), vehicles.end(), type) == vehicles.end()) {
		return false;
	}
	return true;
}

void Zipcode::removeVehicle(int type) {
	auto it = std::find(vehicles.begin(), vehicles.end(), type);

	if (it != vehicles.end())
		vehicles.erase(it);
}

void Zipcode::addVehicle(int type) {
	vehicles.push_back(type);
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
	std::cout << std::endl << "Available vehicles for " << code << ":";
	for (auto it = vehicles.begin(); it != vehicles.end(); it++) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void Zipcode::displayNeighbors() {
	std::cout << std::endl << "Neighbors of " << code << ":";
	for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
		std::cout << " " << it->first << "->" << it->second;
	}
	std::cout << std::endl;
}




