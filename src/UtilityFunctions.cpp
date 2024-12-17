#include "../include/UtilityFunctions.h"
#include "../include/SensorData.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void ShowMenu() {
    std::cout << "OPTIONS: " << std::endl;
    std::cout << "1. Altitude sensor register." << std::endl;
    std::cout << "2. SpeedInKm sensor register." << std::endl;
    std::cout << "3. Fuel consumtion update." << std::endl;
}

void FillData(std::vector<SensorData>& v) {
    srand(time(NULL));

    time_t tid = CreateTime(2012, 1, 1, 1, 1, 1);
    for (int i = 0; i < 1000000; i++) {
        SensorType type = static_cast<SensorType>(rand() % 3);
        float value = 0.0f;
        if (type == SensorType::Altitude)
            value = rand() % 1000;
        else if (type == SensorType::FuelConsumption)
            value = rand() * 3.0f;
        else if (type == SensorType::SpeedInKmh)
            value = rand() % 110;

        v.push_back(SensorData(type, value, tid));
        tid = tid + rand() % 10 + 1;
    }
}

time_t CreateTime(int year, int month, int day, int hour, int minute, int second) {
    struct tm tid = { 0 };
    tid.tm_year = year - 1900;
    tid.tm_mon = month - 1;
    tid.tm_mday = day;
    tid.tm_hour = hour;
    tid.tm_min = minute;
    tid.tm_sec = second;
    return mktime(&tid);
}

void registeredAltitudeCount(std::vector<SensorData> sensorData) {
    time_t startOfDay = CreateTime(2012, 1, 2, 0, 0, 0);
    time_t endOfDay = CreateTime(2012, 1, 2, 23, 59, 59);

    int count = 0;
    for (SensorData& data : sensorData) {
        if (data.GetSensorType() == SensorType::Altitude && data.GetTime() >= startOfDay && data.GetTime() <= endOfDay) {
            count++;
        }
    }

    if (count > 0) {
        std::cout << "Antalet registreringar för Altitude den 2012-01-02: " << count << std::endl;
    } else {
        std::cout << "Inga registreringar för Altitude den 2012-01-02." << std::endl;
    }
}

void maxSpeedCheck(std::vector<SensorData> sensorData) {
    for (SensorData& data : sensorData) {
        if (data.GetSensorType() == SensorType::SpeedInKmh && data.GetValue() > 99.9) {
            std::cout << "Maxhastighet uppnådd" << std::endl;
            return;
        }
    }
    std::cout << "Ingen maxhastighet uppnådd" << std::endl;
}

void fuelConsumptionUpdate(std::vector<SensorData>& sensorData) {
    std::cout << "Before changes: " << std::endl;
    for (SensorData& data : sensorData) {
        if (data.GetSensorType() == SensorType::FuelConsumption) {
            std::cout << data.GetValue() << std::endl;
            float temp = 0.75 * data.GetValue();
            data.SetValue(temp + data.GetValue());
        }
    }
    std::cout << "After changes: " << std::endl;
    std::cout << "***************************" << std::endl;
    for (SensorData& data : sensorData) {
        if (data.GetSensorType() == SensorType::FuelConsumption) {
            std::cout << data.GetValue() << std::endl;
        }
    }
}
