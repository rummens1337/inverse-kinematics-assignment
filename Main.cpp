#include "Arm.hpp"

int main() {
    Arm arm(3, 1, 1000);
    arm.rotateToTarget({10, 20});
    arm.printArm();
}