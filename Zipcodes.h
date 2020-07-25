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
	Zipcodes();
	void addZip(Zipcode zip);
	bool hasZip(std::string code);
	Zipcode& getZip(std::string code);
	void printZips();
	std::pair<Zipcode, int> exectuteRequest(Request);
	int size(); 

private:
	map<std::string, Zipcode> zips;
	void addNeighborsAvailableZipcodes(
		std::set<std::pair<int, std::string>>* availableZipcodes,
		std::map<std::string, int> neighbors,
		int currentDistance,
		std::set<std::string>* visitedZipcodes
	);
};