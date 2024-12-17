#include "include/UtilityFunctions.h"
#include <vector>
#include <iostream>

int main() {

    std::vector<SensorData> sensorData;
    FillData(sensorData);

	while(true) {
		int choice = 0;
		ShowMenu();
		std::cin >> choice; 

		if(choice == 1) {
			registeredAltitudeCount(sensorData);
		}
		else if(choice == 2) {
			maxSpeedCheck(sensorData);
		}
		else if(choice == 3) {
			fuelConsumptionUpdate(sensorData);
		}
	}

    return 0;
}