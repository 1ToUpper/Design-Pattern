/* @name 3.抽象工厂模式
 * @type 创建型模式
 * @define 提供一个创造一系列相关产品族的接口
 * @use 需要根据不同条件创建多个相关或者依赖的对象
 * @instance 
 *  1/有一个抽象工厂类(AbstractFactory)，派生手机工厂(PhoneFactory)和电脑工厂(ComputerFactory)
 *  2/手机工厂可以生产手机(Phone),电脑工厂可以生产电脑(Computer)，手机和电脑都有颜色和等级，定价也不同
 *  3/用户(main)根据标志选择购买哪种产品
 */

//  抽象工厂模式分析报告
// 1. 模式识别
// ================
// 这段代码确实实现了抽象工厂模式（Abstract Factory Pattern）。

// 抽象工厂模式是一种创建型设计模式，它能创建一系列相关的对象，而无需指定其具体类。

// 2. 代码结构分析
// ================
// 模式角色对应关系：
// - AbstractFactory（抽象工厂）: 抽象基类，定义创建产品族的接口
// - PhoneFactory/ComputerFactory（具体工厂）: 实现抽象工厂接口，创建具体产品族
// - AbstractorProductor（抽象产品）: 抽弧产品基类，定义产品公共接口
// - Phone/Computer（具体产品）: 实现抽象产品接口的具体产品类
// - FactoryProducer（工厂生产者）: 客户端使用的工厂选择器

// 3. 模式特点
// ================
// 优点：
// - 产品族的一致性：确保同一工厂创建的产品属于同一族
// - 易于切换产品族：只需更换具体工厂实例
// - 符合开闭原则：增加新产品族时无需修改现有代码

// 缺点：
// - 增加新产品种类困难：需要修改抽象工厂接口
// - 代码复杂度较高：类的数量较多

// 4. 应用场景
// ================
// 适用于需要创建一系列相关或依赖对象的场景，如：
// - 跨平台UI组件创建
// - 游戏中不同风格的道具创建
// - 数据库访问层的实现

// 5. 改进建议
// ================
// - 添加虚析构函数确保正确销毁
// - 使用智能指针管理内存
// - 增加错误处理机制


#include <iostream>
#include <memory>

enum Product
{
    PHONE_ = 0,
    COMPUTER_
};

enum Color
{
    RED_ = 0,
    GREEN_,
    BLUE_,
    DEFAULT_
};

enum Level
{
    SSS_,
    A_,
    D_,
};

class FactoryProducer;
class AbstractFactory;
class PhoneFactory;
class ComputerFactory;
class AbstractorProductor;
class Phone;
class Computer;

class FactoryProducer
{
public:
    static std::unique_ptr<AbstractFactory> get_factory(Product pro);
};

class AbstractFactory
{
public:
    virtual std::unique_ptr<AbstractorProductor> get_product(Level l, Color c) = 0;
};

class PhoneFactory : public AbstractFactory
{
public:
    std::unique_ptr<AbstractorProductor> get_product(Level l, Color c) override;
};

class ComputerFactory : public AbstractFactory
{
public:
    std::unique_ptr<AbstractorProductor> get_product(Level l, Color c) override;
};

class AbstractorProductor
{
public:
    AbstractorProductor(Level l, Color c):le(l), clo(c) {   };
    void show_info()
    {
        std::string color_text = "黑色";
        if(clo == RED_)
        {
            color_text = "红色";
        }
        else if(clo == GREEN_)
        {
            color_text = "绿色";
        }
        else if(clo == BLUE_)
        {
            color_text = "蓝色";
        }
        std::string putout;
        putout += "这是价值"+std::to_string(price)+"元的"+color_text+name;
        std::cout << putout << std::endl;
    };
protected:
    std::string name;
    double price;
    Level le;
    Color clo; 
};

class Phone : public AbstractorProductor
{
public:
    Phone(Level le, Color co):AbstractorProductor(le, co)
    {
        if(le == SSS_)
        {
            price = 99998;
            name = "橘子手机";
        }
        else if(le == A_)
        {
            price = 5000;
            name = "大众手机";
        }
        else if(le == D_)
        {
            price = 998;
            name = "手榴弹";
        }
    }
};

class Computer : public AbstractorProductor
{
public:
    Computer(Level le, Color co):AbstractorProductor(le, co)
    {
        name = "电脑";
        if(le == SSS_)
        {
            price = 77777;
            name = "外星人电脑";
        }
        else if(le == A_)
        {
            price = 10000;
            name = "地球人电脑";
        }
        else if(le == D_)
        {
            price = 998;
            name = "下水道电脑";
        }
    }
};