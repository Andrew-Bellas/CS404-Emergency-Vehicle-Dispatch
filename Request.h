#include <string>

class Request {
public:
	Request(int reqVehichle, std::string reqZipcode);
	
	int getRequestedVehicle();
	std::string getRequestedZipcode(); 

private:
	int requestedVehicle; 
	std::string requestedZipcode; 
};