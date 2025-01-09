#include "../include/MenuFunctions.h"

void ShowMenu() {
    std::cout << "OPTIONS: " << std::endl;
    std::cout << "1. Altitude sensor register." << std::endl;
    std::cout << "2. SpeedInKm sensor register." << std::endl;
    std::cout << "3. Fuel consumtion update." << std::endl;
	std::cout << "4. Queue" << std::endl;
	std::cout << "5. Cash machine" << std::endl;
	std::cout << "6. LRU Cache" << std::endl;
}

void choiceOne(std::vector<SensorData>& sensorData) {
    registeredAltitudeCount(sensorData);
}

void choiceTwo(std::vector<SensorData>& sensorData) {
    maxSpeedCheck(sensorData);
}

void choiceTree(std::vector<SensorData>& sensorData) {
    fuelConsumptionUpdate(sensorData);
}

void choiceFour(Queue& queue, int &nextQueueNumber) {
    int selection = 0;
		while(selection != 9) {
			std::cout << "Press 1 to add a person to the queue.\nPress 2 to call in the next person in the queue.\nPress 9 to exit." << std::endl;
			std::cin >> selection;
				
			if(selection == 1) {
				std::string name;
				std::cout << "Please write your name: " << std::endl;
				std::cin >> name;
				Customer newCustomer(name, nextQueueNumber++);
				queue.addCustomer(newCustomer);

				std::cout << "Customer added with queue number: " << newCustomer.getQueueTicket() << std::endl;
			}
			else if(selection == 2) {
				Customer* nextCustomer = queue.getNextCustomer();
				if(nextCustomer == nullptr) {
					std::cout << "Queue is empty." << std::endl;
					return;
				}
				auto waitTime = getTimeWaited(*nextCustomer);
				(nextQueueNumber)--;
				std::cout << "Next customer is " << nextCustomer->getQueueTicket() << " Name: " << nextCustomer->getName() <<". Time waited: " << waitTime.count() << " seconds." << std::endl;
			}
		}
}

void choiceFive(ATM& atm) {
	int selection = 0;
	std::string accountNumber;
	bool loggedIn = false;
	while(selection != 9) {
		if(selection == 9) {
			loggedIn = false;
		}
		if(!loggedIn) {
		std::cout << "---ATM MENU----" << std::endl;
		std::cout << "Login or create an account to deposit or withdraw." << std::endl;
		std::cout << "1. Create account" << std::endl;
		std::cout << "2. Login to account" << std::endl;
		std::cout << "9. Exit" << std::endl;
		}
		else if(loggedIn) {
			std::cout << "3. Deposit money to account" << std::endl;
			std::cout << "4. Withdraw money from account" << std::endl;
			std::cout << "9. Exit" << std::endl;
		}
		std::cin >> selection;

		if(selection == 1) {
			std::cout << "Please enter a account number:" << std::endl;
			std::cin >> accountNumber;
			atm.createAccount(accountNumber);
		}
		else if(selection == 2) {
			std::cout << "Please enter an account number to login with:" << std::endl;
			std::cin >> accountNumber;
			std::cout << "Signing in to account: " << accountNumber << "..." << std::endl;
			if(atm.login(accountNumber)) {
				loggedIn = true;
				std::cout << "You are now logged in. Our services are below." << std::endl;
			}
			else {
				std::cout << "Error logging in, try again or create an account." << std::endl;
			}
		}
		else if(selection == 3 && loggedIn) {
			double amount;
			std::cout << "Please enter the amount you would like to deposit into your account:" << std::endl;
			std::cin >> amount;
			atm.deposit(accountNumber, amount);
		}
		else if(selection == 4 && loggedIn) {
			double amount;
			std::cout << "Please enter the amount you would like to withdraw from your account:" << std::endl;
			std::cin >> amount;
			atm.withdraw(accountNumber, amount);
		}
	}
}

void choiceSix(LRUCache& cache) {
	std::string fileName = "hockey_players.txt";
	generatePlayersFile(fileName, 100000);
	int playerId = 1;

	while(playerId != 0){
		std::cout << "Enter player id between 1 and 100 000 to find a player in our record. Enter 0 to exit." << std::endl;
		std::cin >> playerId;
		HockeyPlayer* player = cache.getPlayer(playerId);
		if(player) {
			std::cout << "Player found in cache: " << player->name << std::endl;;
		}
		else if(!player){
			std::cout << "Player not found in cache: Loading player from file: " << playerId << "\n";
			auto newPlayer = readPlayerFromFile(fileName, playerId);
			if(!newPlayer) {
				std::cout << "No player with that id found in our record." << std::endl;
			}
			else {
				cache.addPlayer(*newPlayer);
				std::cout << "Found player: " << "ID: " << newPlayer->id << " Name: " << newPlayer->name << " Jersey: " << newPlayer->jersey << " Team: " << newPlayer->teamName << std::endl; 
			}
		}
	}
}