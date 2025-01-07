#include "include/UtilityFunctions.h"
#include "include/Queue.h"
#include <vector>
#include <iostream>

int main() {

    std::vector<SensorData> sensorData;
    FillData(sensorData);
	Queue queue;

	while(true) {
		int choice = 0;
		ShowMenu();
		std::cin >> choice; 
		int queueNumber = 0;

		if(choice == 1) {
			registeredAltitudeCount(sensorData);
		}
		else if(choice == 2) {
			maxSpeedCheck(sensorData);
		}
		else if(choice == 3) {
			fuelConsumptionUpdate(sensorData);
		}
		else if(choice == 4) {
			int selection = 0;
			std::cin >> selection;
			std::cout << "Press 1 to add a person to the queue.\nPress 2 to call in the next person in the queue" << std::endl;
			if(selection == 1) {
				std::string name;
				std::cout << "Please write your name: " << std::endl;
				std::cin >> name;
				Customer customer(name, queue);
				queue.addCustomer(customer);
				queue.getAllCustomers();
			}
		}
	}

    return 0;
}