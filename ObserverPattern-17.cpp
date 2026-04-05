#include "ObserverPattern-17.h"

using namespace std;

int main()
{
    Subject* sub = new Subject();
    std::shared_ptr<LowObserver> lower = std::make_shared<LowObserver>(sub);
    std::shared_ptr<HighObserver> higher = std::make_shared<HighObserver>(sub);

    sub->attach(lower);
    sub->attach(higher);
    sub->set_state(1);
    sub->set_state(199);
    return 0;
}