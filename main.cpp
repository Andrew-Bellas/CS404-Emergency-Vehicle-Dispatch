#include "Zipcodes.h"
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

Zipcode generateTestZipcode(std::string code, Zipcodes zips) {
	if (!zips.hasZip(code)) {
		return Zipcode(code);
	}
	else {
		return zips.getZip(code);
	}
}

std::queue<Request> generateTestRequests() {
	/*
	std::vector<std::string> req = { "1", "64156", "3", "64152", "2", "64156", "3", "64153", "1", "64159", "3",
		"64153", "3", "64154", "1", "64151", "3", "64150", "2", "64155", "2", "64156", "1",
		"64151", "1", "64153", "2", "64156", "1", "64150", "1", "64151", "1", "64158", "1",
		"64155", "1", "64153", "2", "64152", "1", "64151", "3", "64151", "1", "64156", "2",
		"64152", "3", "64155", "3", "64156", "1", "64158", "1", "64154", "2", "64154", "3",
		"64155", "1", "64154", "3", "64156", "2", "64159", "2", "64159", "1", "64156", "1",
		"64152", "2", "64159", "3", "64154", "3", "64159", "3", "64159", "2", "64158", "1",
		"64158", "1", "64151", "3", "64158", "3", "64150", "2", "64155", "1", "64155", "2",
		"64159", "3", "64153", "3", "64151" };
	*/

	std::vector<std::string> req = { "3", "64163", "3", "64152", "2", "64156", "3", "64153", "1", "64159", "3",
	"64153", "3", "64154", "1", "64151", "3", "64150", "2", "64155", "2", "64156", "1",
	"64151", "1", "64153", "2", "64156", "1", "64150", "1", "64151", "1", "64158", "1",
	"64155", "1", "64153", "2", "64152", "1", "64151", "3", "64151", "1", "64156", "2",
	"64152", "3", "64155", "3", "64156", "1", "64158", "1", "64154", "2", "64154", "3",
	"64155", "1", "64154", "3", "64156", "2", "64159", "2", "64159", "1", "64156", "1",
	"64152", "2", "64159", "3", "64154", "3", "64159", "3", "64159", "2", "64158", "1",
	"64158", "1", "64151", "3", "64158", "3", "64150", "2", "64155", "1", "64155", "2",
	"64159", "3", "64153", "3", "64151" };

	std::queue<Request> requests;

	for (int i = 0; i < req.size(); i = i + 2) {
		requests.push(Request(std::stoi(req[i]), req[i + 1]));
	}
	return requests; 
}

Zipcodes generateTestZipcodes() {
	std::vector<string> distances = { "64150", "64151", "6", "64151", "64152", "10", "64152",
		"64153", "4", "64153", "64154", "3", "64154", "64155", "4", "64155", "64156",
		"8", "64156", "64157", "2", "64157", "64158", "1", "64158", "64159", "4",
		"64159", "64160", "10", "64160", "64161", "5", "64161", "64162", "9", "64162",
		"64163", "2", "64163", "64164", "3", "64164", "64165", "4" };

	/*
	std::vector<string> vehicles = { "1","64150","1","64150","2","64151","2","64151","3","64152",
		"2","64152","2","64153","2","64153","1","64154","3","64154","3","64155","1","64155",
		"3","64156","3","64156","3","64157","2","64157","3","64158","1","64158","3","64159",
		"3","64159","1","64160","3","64160","1","64161","3","64161","1","64162","1","64162",
		"3","64163","3","64163","3","64164","1","64164","2","64165","1","64165" };
	*/

	std::vector<string> vehicles = { "1","64150","2","64150","3","64151","1","64151","1","64152",
	"1","64152","1","64153","1","64153","1","64154","1","64154","1","64155","1","64155",
	"1","64156","1","64156","1","64157","1","64157","1","64158","1","64158","1","64159",
	"1","64159","1","64160","1","64160","1","64161","1","64161","2","64162","1","64162",
	"1","64163","1","64163","1","64164","1","64164","1","64165","1","64165" };

	Zipcodes zipcodes;
	for (int i = 0; i < distances.size(); i = i + 3) {
		std::string code1 = distances[i];
		std::string code2 = distances[i + 1];
		int dist = stoi(distances[i + 2]);

		Zipcode zip1 = generateTestZipcode(code1, zipcodes);
		Zipcode zip2 = generateTestZipcode(code2, zipcodes);

		zip1.addNeighbor(code2, dist);
		zip2.addNeighbor(code1, dist);

		zipcodes.addZip(zip1);
		zipcodes.addZip(zip2);
	}

	for (int i = 0, j = 0; i < vehicles.size(); i = i + 2, j++) {
		Zipcode* z = &zipcodes.getZip(vehicles[i + 1]);
		z->addVehicle(j, stoi(vehicles[i]));
	}

	return zipcodes;
}

int main() {
	// generate test data
	Zipcodes testZipcodes = generateTestZipcodes();
	std::queue<Request> testRequests = generateTestRequests(); 

	// run application
	std::cout << "      ***| Emergency Vehicle Dispatch |***" << std::endl;
	while (true) {
		int actionSelection; 

		// prompt user for the action 
		std::cout << " Please Select an Action- " << std::endl;
		std::cout << "    (1) Execute Next Queued Request" << std::endl;
		std::cout << "    (2) View Current Zipcode Information" << std::endl;
		std::cout << "    (3) Exit" << std::endl << "  ";
		std::cin >> actionSelection;
		std::cout << std::endl; 

		if (actionSelection == 1) {
			try {
				Request req = testRequests.front();
				std::cout << "Requesting Vehicle Type " << req.getRequestedVehicle() << 
					" for zipcode " << req.getRequestedZipcode() << std::endl;
				std::tuple<Zipcode, int, int> result = testZipcodes.exectuteRequest(req);
				std::cout << "Dispatching vehicle from " << std::get<0>(result).getCode() << 
					" (ID: " << std::get<2>(result) << ") with distance " << std::get<1>(result) 
					<< std::endl << std::endl;
			} 
			catch (std::logic_error error) {
				std::cout << error.what() << std::endl << std::endl;
			}
			testRequests.pop();
		}
		else if (actionSelection == 2) {
			std::cout << "        *| Current Zipcode Information |*" << std::endl << std::endl;
			testZipcodes.printZips();
		}
		else if (actionSelection == 3) {
			std::cout << "      ***| Exiting Program |***" << std::endl << std::endl;
			return 0;
		}
		
		// prevent infinte loop from invalid input 
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}