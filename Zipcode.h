#include "vehicle.h"
#include <iostream>
#include <vector>
#include <map>

class Zipcode {
public:
	Zipcode();
	Zipcode(std::string code);
	bool hasVehicle(int type);
	void removeVehicle(int type);
	void addVehicle(int type, int id);

	bool hasNeighbor(std::string code);
	void removeNeighbor(std::string code);
	void addNeighbor(std::string code, int distance);

	std::map<std::string, int> getNeighbors(); 
	int getNeighborDistance(std::string code);
	std::string getCode();

	void displayVechles();
	void displayNeighbors();

private:
	// map: neighbor's code -> neighbor's distance 
	std::map<std::string, int> neighbors;

	std::vector<Vehicle> vehicles;
	std::string code;
};



