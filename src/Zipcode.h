#include "vehicle.h"
#include <iostream>
#include <vector>
#include <unordered_map>

class Zipcode {
public:
	// Default constructor
	Zipcode();

	/*
	* Constructor
	*
	* @param code The code for the zipcode 
	*/
	Zipcode(std::string code);

	/*
	* Checks if the zipcode has a vehicle of a certain type 
	*
	* @param type Type of the vehicle
	* @return True if there is vehicle with the type
	*/
	bool hasVehicle(int type);

	/*
	* Removes a vehicle
	*
	* @param type The type of vehicle to remove
	* @return the unique id for the removed vehicle
	*/
	int removeVehicle(int type);

	/*
	* Adds a vehicle
	*
	* @param type The type of vehicle to remove
	* @param id The unique vehicle id
	*/
	void addVehicle(int type, int id);

	/*
	* Checks for a specified neighbor 
	*
	* @param code The code of the neighbor 
	* @return True if there is a neighbor with the specified code
	*/
	bool hasNeighbor(std::string code);
	
	/*
	* Removes a specified  neighbor if the neighbor is valid
	*
	* @param code The code of the neighbor 
	*/
	void removeNeighbor(std::string code);

	/*
	* Adds a neighbor
	*
	* @param code The code of the neighbor
	* @param distance The distance to the neighbor
	*/
	void addNeighbor(std::string code, int distance);

	// Accessor for neighbors
	std::unordered_map<std::string, int> getNeighbors(); 

	// Accessor for code 
	std::string getCode();

	// Displays all vehicles 
	void displayVechles();

	// Display all neighbors
	void displayNeighbors();

private:
	/*
	* Neighbors to the zipcode in the form of a 
	* map for quick distance lookup.
	* 
	*   String: the code of the neighbor (ex. 64154)
	*   Int: the distance to the neighbor 
	*/
	std::unordered_map<std::string, int> neighbors;

	// All vehicles at the zipcode 
	std::vector<Vehicle> vehicles;

	// The code (ex. 64145)
	std::string code;
};



