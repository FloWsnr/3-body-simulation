#ifndef PHYSICS_HPP
#define PHYSICS_HPP


const double GRAVITATIONAL_CONSTANT = 6.674e-11;


double acceleration(Mass &m1, Mass &m2, double distance) {
    return GRAVITATIONAL_CONSTANT * m1.mass * m2.mass / pow(distance, 2);
}

#endif