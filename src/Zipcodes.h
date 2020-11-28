#include "zipcode.h"
#include "request.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <set>

class Zipcodes {
public:
	// Default constructor
	Zipcodes();

	/*
	* Adds a zipcode
	*
	* @param zip The Zipcode object to add 
	*/
	void addZip(Zipcode zip);

	/*
	* Checks if there is a zipcode with a certain code 
	*
	* @param code Code of the zipcode
	* @return True if there is Zipcode with the code
	*/
	bool hasZip(std::string code);

	/*
	* Gets a zipcode from the collection
	*
	* @param code The code for the zipcode 
	* @return A reference to the zipcode 
	*/
	Zipcode& getZip(std::string code);
	
	// Displays all zipcode information
	void printZips();
	
	// Returns the number of zipcodes
	int size(); 

	/*
	* Processes a dispatch request, looks for the closest zipcode with the 
	* requested vehicle type if there is not an applicable vehicle at the requested zipcode
	* it returns the closest vehicle of the specified type to the requested zipcode. 
	* Throws std::logic_error if no match exists
	* 
	* @param req The Request object to execute 
	* @return A std::tuple containing:
	*	Zipcode- The Zipcode object containing the vehicle
	*	int- The distance from the requested zip to the vehicle
	*	int- The unique id of the vehicle 
	*/
	std::tuple<Zipcode, int, int> exectuteRequest(Request req);

private:
	std::unordered_map<std::string, Zipcode> zips;
};