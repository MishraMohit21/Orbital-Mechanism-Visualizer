// src/core/DataStructures.h

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

struct Vector3 {
    double x, y, z;
};

struct SatelliteState {
    Vector3 position;
    Vector3 velocity;
};

struct OrbitalElements {
    double semiMajorAxis;
    double eccentricity;
    double inclination;
    double RAAN; // Right Ascension of Ascending Node
    double argumentOfPerigee;
    double trueAnomaly;
};

#endif // DATA_STRUCTURES_H
