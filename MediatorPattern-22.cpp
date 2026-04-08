#include "MediatorPattern-22.h"

using namespace std;

int main()
{
    User u1("三儿");
    User u2("小鹏展翅");
    u1.send_message("How are you?");
    u2.send_message("I'm fine. Thank you, and you?");
    return 0;
}