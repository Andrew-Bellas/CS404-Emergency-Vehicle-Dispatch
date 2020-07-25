#include "zipcode.h"
#include "request.h"
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>

using namespace std;

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

	std::tuple<Zipcode, int, int> exectuteRequest(Request);

private:
	map<std::string, Zipcode> zips;
};