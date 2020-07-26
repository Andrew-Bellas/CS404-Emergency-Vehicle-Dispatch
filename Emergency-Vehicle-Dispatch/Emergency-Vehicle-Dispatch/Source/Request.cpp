#include "Request.h"

Request::Request(int reqVehichle, std::string reqZipcode) : requestedVehicle(reqVehichle), requestedZipcode(reqZipcode) {
	// empty
}

int Request::getRequestedVehicle() {
	return requestedVehicle;
}

std::string Request::getRequestedZipcode() {
	return requestedZipcode;
}
