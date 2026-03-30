/* @name 8.装饰器模式
 * @type 行为型模式
 * @define 允许向一个现有的对象添加新的功能，同时又不改变其结构。
 * @use 1、当需要在不增加大量子类的情况下扩展类的功能。2、当需要动态地添加或撤销对象的功能。
 * @instance 
    场景描述
        创建一个 Shape 接口和实现了 Shape 接口的实体类。然后创建一个实现了 Shape 接口的抽象装饰类 ShapeDecorator，并把 Shape 对象作为它的实例变量。
        RedShapeDecorator 是实现了 ShapeDecorator 的实体类。
        DecoratorPatternDemo 类使用 RedShapeDecorator 来装饰 Shape 对象。
 */

#include <iostream>
#include <string>
#include <memory>

class Shape
{
public:
    virtual void draw() const = 0;
};

class Circle : public Shape
{
private:
    std::string name;
public:
    Circle(const std::string & name = "三角形") : name(name) {  }
    virtual void draw() const override { std::cout << "画一个三角形" << std::endl; }
};

class Ractangle : public Shape
{
private:
    std::string name;
public:
    Ractangle(const std::string & name = "矩形") : name(name) {  }
    virtual void draw() const override { std::cout << "画一个矩形" << std::endl; }
};

class ShapeDecorator : public Shape
{
protected:
    std::shared_ptr<Shape> decorated_shape;
public:
    ShapeDecorator(std::shared_ptr<Shape> shape) : decorated_shape(shape) { }
    
    void draw() const override
    {
        if(decorated_shape)
        {
            decorated_shape->draw();
        }
    }
};

class RedShapeDecorator : public ShapeDecorator
{
public:
    RedShapeDecorator(std::shared_ptr<Shape> shape) : ShapeDecorator(shape) {   }

    void draw() const override
    {
        set_red_color();
        ShapeDecorator::draw();
    }

private:
    void set_red_color() const 
    {
        std::cout<<"染成红色"<<std::endl;
    }
};