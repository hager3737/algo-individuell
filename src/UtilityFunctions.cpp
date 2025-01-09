#include "../include/UtilityFunctions.h"
#include "../include/SensorData.h"
#include "../include/Customer.h"

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
}

std::chrono::seconds getTimeWaited(Customer& customer) {
    auto currentTime = std::chrono::steady_clock::now();
    auto waitTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - customer.getArrivalTime());
    return waitTime;
}

void generatePlayersFile(std::string& filename, int numPlayers) {
    std::ofstream file(filename);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> jerseyDist(1, 99);
    std::uniform_int_distribution<> teamDist(1, 30);

    for (int i = 1; i <= numPlayers; ++i) {
        file << i << ",Player" << i << "," << jerseyDist(gen) << ",Team" << teamDist(gen) << "\n";
    }
}

HockeyPlayer readPlayerFromFile(std::string& filename, int id) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int playerId, jersey;
        std::string name, teamName;

        char delimiter;
        iss >> playerId >> delimiter >> name >> delimiter >> jersey >> delimiter >> teamName;

        if (playerId == id) {
            return HockeyPlayer(playerId, name, jersey, teamName);
        }
    }
    throw std::runtime_error("Player not found");
}
