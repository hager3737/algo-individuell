#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "SensorData.h"

void ShowMenu();
void FillData(std::vector<SensorData>& v);
time_t CreateTime(int year, int month, int day, int hour, int minute, int second);
void registeredAltitudeCount(std::vector<SensorData> sensorData);
void maxSpeedCheck(std::vector<SensorData> sensorData);
void fuelConsumptionUpdate(std::vector<SensorData>& sensorData);

#endif // UTILITYFUNCTIONS_H
