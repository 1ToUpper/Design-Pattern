/* @name 10.外观模式
 * @type 结构型模式
 * @define 隐藏系统内部细节，并向客户端提供了一个客户端可以访问系统的接口
 * @use 向现有的系统添加一个接口，来隐藏系统的复杂性
 * @advantages
 *      1\减少客户端与目标类的依赖,解耦  2\增大子系统的灵活性  3\隐藏子系统的内部细节
 * @disadvantages
 *      1\违反开闭原则,新增子系统时,需要修改外观类
 * @instance 
    场景描述
        创建一个 Shape 接口和实现了 Shape 接口的实体类。
        然后定义一个外观类 ShapeMaker。
        ShapeMaker 类使用实体类来代表用户对这些类的调用。FacadePatternDemo 类使用 ShapeMaker 类来显示结果。
 */

#include <iostream>
#include <string>
#include <memory>

class Shape
{
public:
    virtual void draw () = 0;
};

class Circle : public Shape
{
public:
    void draw() override { std::cout<<"绘制一个圆形"<<std::endl; }
};

class Rectangle : public Shape
{
public:
    void draw() override { std::cout<<"绘制一个三角形"<<std::endl; }    
};

class Square : public Shape
{
public:
    void draw() override { std::cout<<"绘制一个正方形"<<std::endl; }
};

class ShapeMaker
{
private:
    std::shared_ptr<Circle> circle_ptr_;
    std::shared_ptr<Square> square_ptr_;
    std::shared_ptr<Rectangle> rectangle_ptr_;
public:
    ShapeMaker() : 
        circle_ptr_(std::make_shared<Circle>()), 
        square_ptr_(std::make_shared<Square>()),
        rectangle_ptr_(std::make_shared<Rectangle>()) {   }
    void draw_cicle()
    {
        if(!circle_ptr_) 
        {
            circle_ptr_ = std::make_shared<Circle>();
        }
        circle_ptr_->draw();
    }
    void draw_square()
    {
        if(!square_ptr_) 
        {
            square_ptr_ = std::make_shared<Square>();
        }
        square_ptr_->draw();
    }
    void draw_rectangle()
    {
        if(!rectangle_ptr_) 
        {
            rectangle_ptr_ = std::make_shared<Rectangle>();
        }
        rectangle_ptr_->draw();
    }
};