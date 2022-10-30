#include <iostream>

#include "ParkingSystem.h"

int main() {
    auto * parkingSystem = new ParkingSystem(1,1,0);
    std::cout<<parkingSystem->addCar(1)<<std::endl;
    std::cout<<parkingSystem->addCar(2)<<std::endl;
    std::cout<<parkingSystem->addCar(3)<<std::endl;
    std::cout<<parkingSystem->addCar(1)<<std::endl;

    return 0;
}
