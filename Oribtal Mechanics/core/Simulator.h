// src/core/Simulator.h

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "OrbitCalculator.h"
#include "DataStructures.h"

class Simulator {
public:
    Simulator(double mu);
    void initialize(const SatelliteState& initialState);
    void update(double dt);
    SatelliteState getCurrentState() const;

private:
    OrbitCalculator orbitCalculator;
    SatelliteState currentState;
    double gravitationalParameter;
};

#endif // SIMULATOR_H
