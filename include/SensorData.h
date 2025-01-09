#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <ctime>

enum class SensorType {
    Altitude,
    SpeedInKmh,
    FuelConsumption
};

class SensorData {
    float value;
    SensorType sensorType;
    time_t time;
    
public:
    SensorData(SensorType sensorType, float value, time_t time);
    SensorType GetSensorType();
    float GetValue();
    void SetValue(float v);
    time_t GetTime();
};

#endif // SENSORDATA_H
