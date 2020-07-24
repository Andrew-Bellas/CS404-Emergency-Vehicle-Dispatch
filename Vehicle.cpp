#include "Vehicle.h"

Vehicle::Vehicle(int i, int t) : id(i), type(t) {
	// empty
}

int Vehicle::getType() {
	return type;
}

int Vehicle::getId() {
	return id;
}
