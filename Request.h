#include <string>

class Request {
public:
	/*
	* Constructor for a requests 
	*
	* @param reVehicle The requested vehicle type (1-3)
	* @param reqZipcode The requested zipcode (ex. 64145)
	*/
	Request(int reqVehichle, std::string reqZipcode);
	
	// Accessor for requestedVehicle 
	int getRequestedVehicle();

	// Accessor for requestedZipcode
	std::string getRequestedZipcode(); 

private:
	// The requested vehicle type (1-3)
	int requestedVehicle; 

	// The requested zipcode (ex. 64145)
	std::string requestedZipcode; 
};