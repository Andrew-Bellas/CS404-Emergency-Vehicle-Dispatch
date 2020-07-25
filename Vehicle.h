
class Vehicle {
public:
	// Constructor 
	Vehicle(int id, int type);
	
	// Accessor for type
	int getType();

	// Accessor for id
	int getId();

private:

	// The unique id for the vehicle
	int id;

	/*
	*  The vehicle type id
	*
	*  ID    Type 
	*  1     Ambulance
	*  2     Fire Truck
	*  3     Police Car 
	*/
	int type;

};