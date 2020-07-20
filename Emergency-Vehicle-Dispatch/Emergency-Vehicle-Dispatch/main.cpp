#include "Zipcodes.h"
#include <string>
#include <vector>

Zipcodes generateTestData() {
	std::vector<string> distances = { "64150", "64151", "6", "64151", "64152", "10", "64152",
		"64153", "4", "64153", "64154", "3", "64154", "64155", "4", "64155", "64156",
		"8", "64156", "64157", "2", "64157", "64158", "1", "64158", "64159", "4",
		"64159", "64160", "10", "64160", "64161", "5", "64161", "64162", "9", "64162",
		"64163", "2", "64163", "64164", "3", "64164", "64165", "4" };

	Zipcodes zip; 
	for (int i = 0; i < distances.size(); i=i+3) {
		if (zip.zipExists(distances[i])) {
			zip.addNeighbor(distances[i], distances[i + 1], std::stoi(distances[i + 2]));
		}
		else {
			zip.addZipcode(distances[i], distances[i + 1], std::stoi(distances[i + 2]));
		}
	}
	return zip;
}

int main() {
	Zipcodes zip = generateTestData();
	zip.printZips(); 
	system("pause");
}
