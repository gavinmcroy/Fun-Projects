//
// Created by Gavin T McRoy on 10/30/2022.
//

#ifndef DESIGN_PARKING_SYSTEM_PARKINGSYSTEM_H
#define DESIGN_PARKING_SYSTEM_PARKINGSYSTEM_H

#include <map>

class ParkingSystem {
private:
    std::map<int, int> parkingMap;

public:
    ParkingSystem(int big, int medium, int small) {
        parkingMap[1] = big;
        parkingMap[2] = medium;
        parkingMap[3] = small;
    }

    bool addCar(int carType) {
        if (parkingMap[carType] > 0) {
            /* Spot has been taken */
            parkingMap[carType]--;
            return true;
        }
        return false;
    }
};


#endif //DESIGN_PARKING_SYSTEM_PARKINGSYSTEM_H
