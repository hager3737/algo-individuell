#include "../include/UtilityFunctions.h"
#include "../include/SensorData.h"


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

    int count = std::count_if( std::begin(sensorData), std::end(sensorData),
        [startOfDay, endOfDay](SensorData &s) {return s.GetSensorType() == SensorType::Altitude && s.GetTime() >= startOfDay && s.GetTime() <= endOfDay;}
     );

    if (count > 0) {
        std::cout << "Amount of registrations for Altitude on 2012-01-02: " << count << std::endl;
    } else {
        std::cout << "No registrations for Altitude on 2012-01-02." << std::endl;
    }
}

void maxSpeedCheck(std::vector<SensorData> sensorData) {

    auto iterator = std::find_if(sensorData.begin(), sensorData.end(), [](SensorData& data) {
        return data.GetSensorType() == SensorType::SpeedInKmh && data.GetValue() > 99.9;
    });

    if(iterator != sensorData.end()) {
        std::cout << "Max speed reached" << std::endl;
    } 
    else { 
        std::cout << "Max speed not reached" << std::endl;
    }
}

void fuelConsumptionUpdate(std::vector<SensorData>& sensorData) {

    std::cout << "5 first measuremnets before 75% increase" << std::endl;
    for(int i = 0; i <= 5; i++) {
        SensorData& data = sensorData[i];
        if(data.GetSensorType() == SensorType::FuelConsumption) {
            std::cout << "Meassurement " << i + 1 << ": " << data.GetValue() << std::endl;
        }
    }

    std::for_each(sensorData.begin(), sensorData.end(), [](SensorData& data) {
        if(data.GetSensorType() == SensorType::FuelConsumption) {
            data.SetValue(data.GetValue() * 1.75);
        }
    });

    std::cout << "\nAfter increase:" << std::endl;
    for(int i = 0; i <= 5; i++) {
        SensorData& data = sensorData[i];
        if(data.GetSensorType() == SensorType::FuelConsumption) {
            std::cout << "Meassurement " << i + 1 << ": " << data.GetValue() << std::endl;
        }
    }

    // std::cout << "Before changes: " << std::endl;
    // for (SensorData& data : sensorData) {
    //     if (data.GetSensorType() == SensorType::FuelConsumption) {
    //         std::cout << data.GetValue() << std::endl;
    //         float temp = 0.75 * data.GetValue();
    //         data.SetValue(temp + data.GetValue());
    //     }
    // }
    // std::cout << "After changes: " << std::endl;
    // std::cout << "***************************" << std::endl;
    // for (SensorData& data : sensorData) {
    //     if (data.GetSensorType() == SensorType::FuelConsumption) {
    //         std::cout << data.GetValue() << std::endl;
    //     }
    // }
}
