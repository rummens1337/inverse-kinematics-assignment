#include "MathUtils.hpp"

// https://www.geeksforgeeks.org/program-dot-product-cross-product-two-vector/
double MathUtils::dotProduct(std::vector<double> vect1, std::vector<double> vect2) {
    double product = 0;

    for (int i = 0; i < vect1.size(); i++)
        product = product + vect1[i] * vect2[i];

    return product;
}

// https://www.geeksforgeeks.org/program-dot-product-cross-product-two-vector/
std::vector<double> MathUtils::crossProduct(std::vector<double> vect1, std::vector<double> vect2) {
    std::vector<double> crossProduct(3, 0);

    crossProduct[0] = vect1[1] * vect2[2] - vect1[2] * vect2[1];
    crossProduct[1] = vect1[2] * vect2[0] - vect1[0] * vect2[2];
    crossProduct[2] = vect1[0] * vect2[1] - vect1[1] * vect2[0];

    return crossProduct;
}

// https://www.onemathematicalcat.org/Math/Precalculus_obj/formulaLengthOfVector.htm
double MathUtils::calculateVectorLength(std::vector<double> vect1) {
    return sqrt(pow(vect1[0], 2) + pow(vect1[1], 2));
}

// https://www.wikihow.com/Find-the-Angle-Between-Two-Vectors#:~:text=An%20easier%20way%20to%20find,cos(X)%20%3D%202i. (1)
double MathUtils::calculateAngle(const std::vector<double> &vect1, const std::vector<double> &vect2) {
    return acos(MathUtils::dotProduct(vect1, vect2) / (calculateVectorLength(vect1) * calculateVectorLength(vect2)));
}

