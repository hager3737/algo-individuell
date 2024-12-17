#include "../include/SensorData.h"

SensorData::SensorData(SensorType sensorType, float value, time_t time) {
    this->value = value;
    this->sensorType = sensorType;
    this->time = time;
}

SensorType SensorData::GetSensorType() {
    return sensorType;
}

float SensorData::GetValue() {
    return value;
}

void SensorData::SetValue(float v) {
    value = v;
}

time_t SensorData::GetTime() {
    return time;
}
