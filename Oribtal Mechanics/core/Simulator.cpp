// src/core/Simulator.cpp

#include "Simulator.h"

Simulator::Simulator(double mu) : gravitationalParameter(mu) {}

void Simulator::initialize(const SatelliteState& initialState) {
    currentState = initialState;
}

void Simulator::update(double dt) {
    currentState = orbitCalculator.propagateOrbit(currentState, dt, gravitationalParameter);
}

SatelliteState Simulator::getCurrentState() const {
    return currentState;
}
