#include "Arm.hpp"

Arm::Arm(int numberOfSegments, double endEffectorRange, int maxAttempts) :
        _endEffectorRange(endEffectorRange), _maxAttempts(maxAttempts) {

    _segments.push_back(new ArmSegment(10, 1, M_PI, nullptr));

    for (int i = 0; i < numberOfSegments - 1; ++i)
        _segments.push_back(new ArmSegment(10, 1, M_PI, _segments[i]));
}

void Arm::printArm() {
    for (auto segment : _segments)
        segment->printVector();
}

void Arm::rotateToTarget(vector<double> const &targetPoint) {
    int count = 0;

    while (!targetReached(targetPoint) && count < _maxAttempts) {
        count++;
        for (auto segment : _segments)
            segment->rotateSegment(targetPoint);
    }

    if (count >= _maxAttempts)
        cout << "Failure, max attempts reached! -- Count of attempts: " << count << endl;
    else
        cout << "Success! -- Count of attempts: " << count << endl;
}

bool Arm::targetReached(vector<double> targetPoint) {
    // // draw vector from targetPoint to end effector (last segment of the arm).
    std::vector<double> targetVector = {targetPoint[0] - _segments.back()->getEndPoint()[0],
                                        targetPoint[1] - _segments.back()->getEndPoint()[1]};

    // calculate length of vector which indicates the distance.
    double distanceToEndpoint = MathUtils::calculateVectorLength(targetVector);

    // If distanceToEndPoint is within threshold of _endEffectorRange, return true.
    return (distanceToEndpoint <= this->_endEffectorRange);
}
