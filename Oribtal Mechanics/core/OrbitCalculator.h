// src/core/OrbitCalculator.h

#ifndef ORBIT_CALCULATOR_H
#define ORBIT_CALCULATOR_H

#include "DataStructures.h"

class OrbitCalculator {
public:
    OrbitalElements calculateOrbitalElements(const SatelliteState& state, double mu);
    SatelliteState propagateOrbit(const SatelliteState& state, double dt, double mu);
};

#endif // ORBIT_CALCULATOR_H
