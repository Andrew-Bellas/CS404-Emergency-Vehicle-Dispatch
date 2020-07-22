#include <vector>
#include <string>
#include <map>

using namespace std;

class Zipcodes {
public:
	Zipcodes();
	void addZipcode(std::string code, std::string neighbor, int neighborDistance);
	void addNeighbor(std::string code, std::string neighbor, int neighborDistance);
	void addVehicle(std::string code, int vehicleType);
	bool zipExists(std::string code);
	std::map<string, vector<pair<string, int>>> zips;
	std::map<string, vector<int>> vehicles;
	void printZips();
	void printVehicles();
};