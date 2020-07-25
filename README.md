# CS404-Emergency-Vehicle-Dispatch
Project for COMP-SCI 404 (Algorithms and Complexity)

**Assumptions** 
---
*Assumptions: List any assumptions that you made that aren’t mentioned of the project description.*

* Whenever an applicable vehicle is found, that vehicle is removed from the zipcode's available vehicles
* Not every zipcode will have the requested vehicle available
* Based on the example distance data, each zip code has two neighbors

**Explanation**
---
*Brief Explanation of the Idea: Explain your idea briefly with some diagrams and text.*

* In order to efficiently dispatch emergency vehicles, we want to find the closest location with the requested vehicle type. This would start with the location requesting the vehicle. If zipcode 'A' is requesting a vehicle that is already available, then we first want to use it. 
* If zipcode 'A' does not have the appropriate vehicle, then we want to search neighbor zipcodes. We check vehicle availability of the requested vehicle type on neighbor with the shortest distance and if a match is found we return the zipcode it was found at and the distance to the requesting zipcode.
* As we navigate through the zipcodes we accumulate a running total distance based on previous distance and the distance to the next neighbor zipcode
* The zipcodes containing the desired vehicle will then have their distances to the requested zipcode compared. We want the most efficient selection to be made, so we choose the zip with the shortest distance to travel
* After the selection has been made, we then remove the vehicle from the zipcode it was found at

**Algorithm Mapping Diagram**
---
![Algorithm Mapping Diagram](Algorithm Mapping Diagram.png)

**Efficiency**
---
*Efficiency of Algorithms: Mention the Big-O of the required functions (just the significant functions, not minor things like setters and getters).  Mention if it is possible to do better.*

* addNeighborAvailableZipcodes
* executeRequest
 
**References**
---
*References: Cite any references that you used.*

* Sets: https://www.geeksforgeeks.org/set-in-cpp-stl/
* Maps: http://www.cplusplus.com/reference/map/map/?kw=map 
