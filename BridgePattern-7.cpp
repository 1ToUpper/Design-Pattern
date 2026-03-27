#include "BridgePattern-7.h"

using namespace std;

int main()
{   
    std::shared_ptr<Charger> charger_TypeC = std::make_shared<TypeC>();
    std::shared_ptr<Charger> charger_USB = std::make_shared<MicroUSB>();
    std::shared_ptr<Charger> charger_Lightning = std::make_shared<Lightning>();

    AndroidPhone Aphone(charger_TypeC);
    IPhone Iphone(charger_USB);

    Aphone.charge();
    Aphone.set_charger(charger_USB);
    Aphone.charge();
    Aphone.set_charger(charger_Lightning);
    Aphone.charge();

    Iphone.charge();
    Iphone.set_charger(charger_TypeC);
    Iphone.charge();
    Iphone.set_charger(charger_Lightning);
    Iphone.charge();
    return 0;
}