#ifndef INVERSE_KINEMATICS_ASSIGNMENT_ARM_SEGMENT_H
#define INVERSE_KINEMATICS_ASSIGNMENT_ARM_SEGMENT_H

#include <vector>
#include <cmath>
#include <iostream>
#include "MathUtils.hpp"
#include "ArmSegment.hpp"
#include <memory>

using namespace std;

class ArmSegment {

private:
    double _length;
    double _angle; // radians.
    double _maxAngle; // radians.
    double _totalAngle; // radians.
    vector<double> _endPoint;
    vector<double> _mountPoint;
    vector<double> _segmentVector; // Vector of endPoint - mountPoint.
    ArmSegment *_previousSegment;

public:
    /**
     * @brief Construct a new Arm Segment object.
     *
     * @param length Length of the segment.
     * @param angle Angle based on previous segment.
     * @param maxAngle Max angle of the segment.
     * @param previousSegment Segment that is connected prior to this segment.
     */
    ArmSegment(double length, double angle, double maxAngle, ArmSegment *previousSegment);

    /**
     * @brief Get the End Point object.
     * 
     * @return vector<double> endPoint.
     */
    vector<double> getEndPoint();

    /**
     * @brief Calculate X and Y position relative to other segments.
     * 
     */
    void calculatePosition();

    /**
     * @brief Print the @p mountPoint and @p endPoint of this segment.
     * 
     */
    void printVector();

    /**
     * @brief Rotate arm segment endpoint inline with targetPoint.
     * 
     * @param targetPoint Target to rotate the segment to.
     */
    void rotateSegment(vector<double> targetPoint);
};

#endif  