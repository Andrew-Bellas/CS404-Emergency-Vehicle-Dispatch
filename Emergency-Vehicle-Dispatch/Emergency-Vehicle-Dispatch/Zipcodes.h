#include "zipcode.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class Zipcodes {
public:
	Zipcodes();
	void addZip(Zipcode zip);
	bool hasZip(std::string code);
	Zipcode& getZip(std::string code);
	void printZips();

private:
	map<std::string, Zipcode> zips;
};