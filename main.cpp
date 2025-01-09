#include "include/UtilityFunctions.h"
#include "include/Queue.h"
#include "include/MenuFunctions.h"
#include <vector>
#include <iostream>

int main() {

    std::vector<SensorData> sensorData;
    FillData(sensorData);
	Queue queue;
	int nextQueueNumber = 1;
	ATM atm;
	LRUCache cache(10);

	while(true) {
		int choice = 0;
		ShowMenu();
		std::cin >> choice; 

		if(choice == 1) {
			choiceOne(sensorData);
		}
		else if(choice == 2) {
			maxSpeedCheck(sensorData);
			
		}
		else if(choice == 3) {
			fuelConsumptionUpdate(sensorData);
		}
		else if(choice == 4) {
			choiceFour(queue, nextQueueNumber);
		}
		else if(choice == 5) {
			choiceFive(atm);
		}
		else if(choice == 6) {
			choiceSix(cache);
		}
	}

    return 0;
}