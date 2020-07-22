#include "Zipcodes.h"
#include <string>
#include <vector>

Zipcodes generateTestData() {
	std::vector<string> distances = { "64150", "64151", "6", "64151", "64152", "10", "64152",
		"64153", "4", "64153", "64154", "3", "64154", "64155", "4", "64155", "64156",
		"8", "64156", "64157", "2", "64157", "64158", "1", "64158", "64159", "4",
		"64159", "64160", "10", "64160", "64161", "5", "64161", "64162", "9", "64162",
		"64163", "2", "64163", "64164", "3", "64164", "64165", "4" };

	std::vector<string> vehicles = { "1","64150","1","64150","2","64151","2","64151","3","64152",
		"2","64152","2","64153","2","64153","1","64154","3","64154","3","64155","1","64155",
		"3","64156","3","64156","3","64157","2","64157","3","64158","1","64158","3","64159",
		"3","64159","1","64160","3","64160","1","64161","3","64161","1","64162","1","64162",
		"3","64163","3","64163","3","64164","1","64164","2","64165","1","64165" };

	Zipcodes zip;
	for (int i = 0; i < distances.size(); i = i + 3) {
		if (zip.zipExists(distances[i])) {
			zip.addNeighbor(distances[i], distances[i + 1], std::stoi(distances[i + 2]));
		}
		else {
			zip.addZipcode(distances[i], distances[i + 1], std::stoi(distances[i + 2]));
		}
	}

	for (int i = 0; i < vehicles.size(); i = i + 2) {
		zip.addVehicle(vehicles[i + 1], std::stoi(vehicles[i]));
	}

	return zip;
}

int main() {
	Zipcodes zip = generateTestData();
	zip.printZips();
	zip.printVehicles();
	system("pause");
}
