#include "FlyWeigetPattern-12.h"

using namespace std;

int main()
{
    std::shared_ptr<Robot> R1 = Robot::get_instance(1);
    std::shared_ptr<Robot> R2 = Robot::get_instance(2);
    std::shared_ptr<Robot> R11 = Robot::get_instance(1);
    return 0;
}