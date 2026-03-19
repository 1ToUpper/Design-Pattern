/* @name 1.工厂模式
 * @type 创建型模式
 * @define 创建对象的过程与使用对象的过程分离
 * @use 需要根据不同条件创建对象
 * @instance 
 *  1/有一个工厂类(Factory)，可以生产手机(Phone)和电脑(Computer)
 *  2/用户(main)根据标志选择购买哪种产品，由工厂类生产
 */

#include <iostream>
#include <memory>

using namespace std;

enum ProductType
{
    NONE_ = -1,
    PHONE_ = 0,
    COMPUTER_,
};

class Factory;
class AbstractProduct;
class PhoneProduct;
class ComputerProduct;
class AbstractProduct
{
public:
    virtual void show_information() = 0;
};

class PhoneProduct : public AbstractProduct
{
public:
    void show_information() override
    {
        printf("这是果子派手机.\n");
    }
};

class ComputerProduct : public AbstractProduct
{
public:
    void show_information() override
    {
        printf("这是果子派电脑.\n");
    }
};

class NoneProduct : public AbstractProduct
{
public:
    void show_information() override
    {
        printf("该产品不存在.\n");
    }
};
class Factory
{
public:
    std::unique_ptr<AbstractProduct> produce_product(ProductType pt)
    {
        if(pt == PHONE_)
        {
            return std::make_unique<PhoneProduct>();
        }
        else if(pt == COMPUTER_)
        {
            return std::make_unique<ComputerProduct>();
        }
        else
        {
            return std::make_unique<NoneProduct>();
        }
    }
};

int main()
{
    //main
    Factory fac;
    std::unique_ptr<AbstractProduct> pro1, pro2;
    pro1 = fac.produce_product(PHONE_);
    pro1->show_information();
    pro2 = fac.produce_product(COMPUTER_);
    pro2->show_information();
    return 0;
}