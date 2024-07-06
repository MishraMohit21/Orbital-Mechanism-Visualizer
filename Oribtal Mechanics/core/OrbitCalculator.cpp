// src/core/OrbitCalculator.cpp

#include "OrbitCalculator.h"
#include <cmath>

OrbitalElements OrbitCalculator::calculateOrbitalElements(const SatelliteState& state, double mu) {
    OrbitalElements elements;

    double r = std::sqrt(state.position.x * state.position.x +
        state.position.y * state.position.y +
        state.position.z * state.position.z);

    double v = std::sqrt(state.velocity.x * state.velocity.x +
        state.velocity.y * state.velocity.y +
        state.velocity.z * state.velocity.z);

    elements.semiMajorAxis = 1 / (2 / r - (v * v) / mu);
    // Simplified calculation for demonstration purposes
    elements.eccentricity = 0.1;
    elements.inclination = 0.1;
    elements.RAAN = 0.1;
    elements.argumentOfPerigee = 0.1;
    elements.trueAnomaly = 0.1;

    return elements;
}

SatelliteState OrbitCalculator::propagateOrbit(const SatelliteState& state, double dt, double mu) {
    SatelliteState newState;
    Vector3 acceleration;
    double r = std::sqrt(state.position.x * state.position.x +
        state.position.y * state.position.y +
        state.position.z * state.position.z);
    acceleration.x = -mu * state.position.x / (r * r * r);
    acceleration.y = -mu * state.position.y / (r * r * r);
    acceleration.z = -mu * state.position.z / (r * r * r);

    newState.velocity.x = state.velocity.x + acceleration.x * dt;
    newState.velocity.y = state.velocity.y + acceleration.y * dt;
    newState.velocity.z = state.velocity.z + acceleration.z * dt;

    newState.position.x = state.position.x + newState.velocity.x * dt;
    newState.position.y = state.position.y + newState.velocity.y * dt;
    newState.position.z = state.position.z + newState.velocity.z * dt;

    return newState;
}
