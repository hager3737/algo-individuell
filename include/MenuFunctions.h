#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include <iostream>
#include "UtilityFunctions.h"
#include "Queue.h"
#include "Customer.h"
#include "ATM.h"
#include "Account.h"
#include "LRUCache.h"

#include <vector>
#include <iostream>

void choiceOne(std::vector<SensorData>& sensorData);
void choiceTwo(std::vector<SensorData>& sensordata);
void choiceTree(std::vector<SensorData>& sensordata);
void choiceFour(Queue& queue, int &nextQueueNumber);
void choiceFive(ATM& atm);
void choiceSix(LRUCache& cache);

#endif // MENUFUNCTIONS_H