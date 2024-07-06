// src/main.cpp

#include <iostream>
#include "core/Simulator.h"

int main() {
    double mu = 398600; // Earth's gravitational parameter in km^3/s^2
    double dt = 10;     // Time step in seconds

    SatelliteState initialState;
    initialState.position = { 7000, 0, 0 }; // Initial position in km
    initialState.velocity = { 0, 7.5, 0 };  // Initial velocity in km/s

    Simulator simulator(mu);
    simulator.initialize(initialState);

    for (int i = 0; i < 100; ++i) {
        simulator.update(dt);
        SatelliteState state = simulator.getCurrentState();
        std::cout << "Time: " << i * dt << " s, Position: ("
            << state.position.x << ", "
            << state.position.y << ", "
            << state.position.z << ") km" << std::endl;
    }
    system("pause");
    return 0;
}
