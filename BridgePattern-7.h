/* @name 7.桥接模式
 * @type 行为型模式
 * @define 将抽象与实现分离，让两者独立变化(使用组合的方式)
 * @use 预先设计：规划两个独立变化的维度，而非适配器的单一适配
 * @instance 
    场景描述
    假设我们有以下接口不兼容的情况：
        维度1：手机类型(Android、iPhone、Nokia)
        维度2：充电器类型(TypeC、MicroUSB、Lightning)
    假设手机厂商达成统一，设计出来的手机适配所有的充电器型号
 */

#include <iostream>
#include <memory>

class Charger
{
public:
    virtual void charge() = 0;
    virtual std::string get_type() = 0;
};

class TypeC : public Charger
{
public:
    virtual void charge() override { std::cout << "使用 TypeC 充电器充电" << std::endl;}
    virtual std::string get_type() override { return "TypeC"; } 
};

class MicroUSB : public Charger
{
public:
    virtual void charge() override { std::cout << "使用 MicroUSB 充电器充电" << std::endl;}
    virtual std::string get_type() override { return "MicroUSB"; } 
};

class Lightning : public Charger
{
public:
    virtual void charge() override { std::cout << "使用 Lightning 充电器充电" << std::endl;}
    virtual std::string get_type() override { return "Lightning"; } 
};

class Phone
{
public:
    Phone(std::shared_ptr<Charger> Cc) : charger(Cc) { }
    virtual ~Phone() = default;
    virtual inline void charge() const { charger->charge(); };
    void set_charger(std::shared_ptr<Charger> Cc) { charger = Cc;}
protected:
    std::shared_ptr<Charger> charger;
};

class AndroidPhone : public Phone
{
public:
    AndroidPhone(std::shared_ptr<Charger> Cc) : Phone(Cc) {}
    inline void charge() const override
    {
        std::cout << "AndroidPhone: ";
        Phone::charge();
    }
};

class IPhone : public Phone
{
public:
    IPhone(std::shared_ptr<Charger> Cc) : Phone(Cc) {}
    inline void charge() const override
    {
        std::cout << "IPhone: ";
        Phone::charge();
    }
};