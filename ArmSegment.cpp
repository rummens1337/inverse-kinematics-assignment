#include "ArmSegment.hpp"

ArmSegment::ArmSegment(double length, double angle, double maxAngle, ArmSegment *previousSegment) :
        _length(length), _angle(angle), _maxAngle(maxAngle), _previousSegment(previousSegment), _totalAngle(0) {
    calculatePosition();
}

/**
 * sos cas toa
 * sin = overstaand / schuinezijde => sin * schuinezijde = overstaand(y)
 *      => bereken lengte van Overstaand = y
 * cos = aanliggende / schuinezijde => cos * schuinezijde = aanliggende(x)
 *      => bereken lengte van Aanliggend = x
 */
void ArmSegment::calculatePosition() {
    if (!_previousSegment) { // Base segment.
        _totalAngle = _angle;
        _mountPoint = {0, 0, 0};
        _endPoint = {_length * cos(_totalAngle), _length * sin(_totalAngle)};
    } else { // Other _segments.
        _totalAngle = _angle + _previousSegment->_totalAngle;
        _mountPoint = _previousSegment->_endPoint;
        _endPoint = {_mountPoint[0] + _length * cos(_totalAngle),
                     _mountPoint[1] + _length * sin(_totalAngle)};
    }
    // SegmentVector requires 3th dimension for cross product calculation.
    _segmentVector = {_endPoint[0] - _mountPoint[0], _endPoint[1] - _mountPoint[1], 0};
}

vector<double> ArmSegment::getEndPoint() {
    return _endPoint;
}

void ArmSegment::printVector() {
    cout << "Mountpoint: " << _mountPoint[0] << " - " << _mountPoint[1] << " | ";
    cout << "Endpoint: " << _endPoint[0] << " - " << _endPoint[1] << " | ";
    cout << "Angle: " << _angle << endl;
}

void ArmSegment::rotateSegment(vector<double> targetPoint) {
    // Draw vector to target point.
    vector<double> targetVector = {targetPoint[0] - _mountPoint[0], targetPoint[1] - _mountPoint[1], 0};

    // Calculate angle between targetVector and segmentVector.
    double calculatedAngle = MathUtils::calculateAngle(targetVector, _segmentVector);

    // Determine which way to turn based on cross product.
    if (MathUtils::crossProduct(targetVector, _segmentVector)[2] < 0.0)
        calculatedAngle > _maxAngle ? _angle = -_maxAngle : _angle = -calculatedAngle;
    else
        calculatedAngle > _maxAngle ? _angle = _maxAngle : _angle = calculatedAngle;

    // Recalculate position based on new angle.
    calculatePosition();
}
