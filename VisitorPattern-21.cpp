#include "VisitorPattern-21.h"

using namespace std;

int main()
{
    Computer* computer = new Computer();
    computer->accept(std::make_shared<ComputerPartDisplayVisitor>());
    return 0;
}