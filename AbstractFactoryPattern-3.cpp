#include "AbstractFactoryPattern-3.h"

using namespace std;

std::unique_ptr<AbstractFactory> FactoryProducer::get_factory(Product pro)
{
    if(pro == PHONE_)
    {
        return std::make_unique<PhoneFactory>();
    }
    else if(pro == COMPUTER_)
    {
        return std::make_unique<ComputerFactory>();
    }
    return nullptr;
}

std::unique_ptr<AbstractorProductor> ComputerFactory::get_product(Level l, Color c)
{
    return std::make_unique<Computer>(l,c);
}

std::unique_ptr<AbstractorProductor> PhoneFactory::get_product(Level l, Color c)
{
    return std::make_unique<Phone>(l,c);
}

int main()
{
    std::unique_ptr<AbstractFactory> factory = FactoryProducer::get_factory(PHONE_);
    factory->get_product(SSS_, BLUE_)->show_info();
    factory->get_product(D_, RED_)->show_info();
    std::unique_ptr<AbstractFactory> factory2 = FactoryProducer::get_factory(COMPUTER_);
    factory2->get_product(A_, GREEN_)->show_info();
    factory2->get_product(D_, RED_)->show_info();
    return 0;
}