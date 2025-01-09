#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "SensorData.h"
#include <chrono>
#include <fstream>
#include <random>
#include <sstream>
#include "Customer.h"
#include "HockeyPlayer.h"

void ShowMenu();
void FillData(std::vector<SensorData>& v);
time_t CreateTime(int year, int month, int day, int hour, int minute, int second);
void registeredAltitudeCount(std::vector<SensorData> sensorData);
void maxSpeedCheck(std::vector<SensorData> sensorData);
void fuelConsumptionUpdate(std::vector<SensorData>& sensorData);
std::chrono::seconds getTimeWaited(Customer& customer);
void generatePlayersFile(std::string& filename, int numPlayers);
HockeyPlayer readPlayerFromFile(std::string& filename, int id);

#endif // UTILITYFUNCTIONS_H
