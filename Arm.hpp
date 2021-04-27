#ifndef INVERSE_KINEMATICS_ASSIGNMENT_ARM_H
#define INVERSE_KINEMATICS_ASSIGNMENT_ARM_H

#include "ArmSegment.hpp"
#include <list>
#include <memory>
#include "MathUtils.hpp"

using namespace std;

class Arm {

private:
    vector<ArmSegment *> _segments;
    double _endEffectorRange;
    int _maxAttempts;

    /**
     * @brief Determines whether end effector has reached @param targetPoint with a threshold of @p _endEffectorRange.
     * 
     * @param targetPoint 
     * @return true 
     * @return false 
     */
    bool targetReached(vector<double> targetPoint);

public:

    /**
     * @brief Construct a new Arm object
     * 
     * @param numberOfSegments Number of _segments the arm is made of.
     * @param endEffectorRange Minimum threshold that determines whether the object is in range for the end effector.
     */
    Arm(int numberOfSegments, double endEffectorRange, int maxAttempts);

    /**
     * @brief Print vectors of the _segments attached to the arm.
     * 
     */
    void printArm();

    /**
     * @brief Rotates all _segments using CCD so that the end effector reaches targetPoint within a threshold of _endEffectorRange.
     * 
     * @param targetPoint A vector representing an {X,Y} value.
     */
    void rotateToTarget(vector<double> const &targetPoint);
};

#endif //INVERSE_KINEMATICS_ASSIGNMENT_ARM_H