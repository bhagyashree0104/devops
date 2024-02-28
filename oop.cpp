
#include <iostream>

class TemperatureSensor {
private:
    int currentTemperature;

public:
    TemperatureSensor() : currentTemperature(0) {}

    void setCurrentTemperature(int temperature) {
        currentTemperature = temperature;
    }

    int getCurrentTemperature() const {
        return currentTemperature;
    }
};

class WaterHeater {
private:
    int heatingTemperature;

public:
    WaterHeater() : heatingTemperature(0) {}

    void setHeatingTemperature(int temperature) {
        heatingTemperature = temperature;
    }

    int getHeatingTemperature() const {
        return heatingTemperature;
    }

    void heatWater(int requiredTemperature) const {
        std::cout << "Heating the water to " << requiredTemperature << " degrees Celsius." << std::endl;
    }
};

class SmartGeyser {
private:
    const TemperatureSensor& sensor;
    WaterHeater& heater;

public:
    SmartGeyser(const TemperatureSensor& tempSensor, WaterHeater& waterHeater)
        : sensor(tempSensor), heater(waterHeater) {}

    void activateGeyser() const {
        std::cout << "Geyser activated." << std::endl;
        int currentTemp = sensor.getCurrentTemperature();
        std::cout << "Current temperature detected: " << currentTemp << " degrees Celsius." << std::endl;
        int requiredTemp = calculateRequiredTemperature(currentTemp);
        heater.heatWater(requiredTemp);
    }

    int calculateRequiredTemperature(int currentTemperature) const {
        // Adjust temperature based on season (not implemented)
        // For simplicity, assuming a fixed temperature adjustment
        return currentTemperature - 10; // Adjusting for summer by reducing temperature
    }
};

class HomeOwner {
public:
    void getOutOfBed() const {
        std::cout << "Homeowner has gotten out of bed." << std::endl;
    }
};

int main() {
    TemperatureSensor sensor;
    WaterHeater heater;
    SmartGeyser geyser(sensor, heater);
    HomeOwner owner;

    int currentTemp;

    std::cout << "Enter the current temperature in degrees Celsius: ";
    std::cin >> currentTemp;

    sensor.setCurrentTemperature(currentTemp);

    owner.getOutOfBed();
    geyser.activateGeyser();

    return 0;
}
