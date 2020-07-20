#include <vector>
#include <string>
#include <map>

using namespace std; 

class Zipcodes {
public:
	Zipcodes();
	void addZipcode(std::string code, std::string neighbor, int neighborDistance);
	void addNeighbor(std::string code, std::string neighbor, int neighborDistance);
	bool zipExists(std::string code);
	std::map<string, vector<pair<string, int>>> zips;
	void printZips(); 
};