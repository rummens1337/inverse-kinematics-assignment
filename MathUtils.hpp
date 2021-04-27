#ifndef INVERSE_KINEMATICS_ASSIGNMENT_MATH_UTILS_H
#define INVERSE_KINEMATICS_ASSIGNMENT_MATH_UTILS_H

#include "iostream"
#include <vector>
#include <cmath>

class MathUtils {
private:

public:
    /**
     * Calculate dot product / scalar (merge two vectors to single value)
     */
    static double dotProduct(std::vector<double> vect1, std::vector<double> vect2);

    /**
     * Calculate cross product
     */
    static std::vector<double> crossProduct(std::vector<double> vect1, std::vector<double> vect2);

    /**
     * Calculate the length of a vector
     */
    static double calculateVectorLength(std::vector<double> vect1);

    /**
     * Calculate angle between two vectors.
     */
    static double calculateAngle(const std::vector<double> &vect1, const std::vector<double> &vect2);
};

#endif  