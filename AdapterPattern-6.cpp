#include "AdapterPattern-6.h"

using namespace std;

int main()
{
    std::cout << "===== 适配器演示：手机充电器兼容 ===== \n" << std::endl;

    MicroUSBChanger micro_USB_charger;
    LightningCharger lightning_charger;

    MicroUSBToTypeCAdapter USB_adapter(&micro_USB_charger);
    LightingToTypeCAdapter Lighting_adapter(&lightning_charger);

    Phone myPhone("Android手机", &USB_adapter);
    myPhone.charge();
    myPhone.set_charger(&Lighting_adapter);
    myPhone.charge();

    Phone yourPhone("Apple手机", &Lighting_adapter);
    yourPhone.charge();
    yourPhone.set_charger(&USB_adapter);
    yourPhone.charge();
    return 0;
}