/* @name 21.访问者模式
 * @type 行为型模式
 * @define 使用了一个访问者类，它改变了元素类的执行算法，元素的执行算法可以随着访问者改变而改变。
 * @use 当需要对一个对象结构中的对象执行多种不同的且不相关的操作时，尤其是这些操作需要避免"污染"对象类本身。
 * @advantages
 *      1\单一职责原则  2\易于拓展  3\灵活性
 * @disadvantages
 *      1\违背迪米特法则  2\元素难以变更  3\违背依赖倒置原则
 * @instance 
    场景描述
        创建一个Visitor抽象类，派生出ComputerPartDisplayVisitor电脑部件访问者类
        创建一个ComputerPart电脑元素类，派生Computer、KeyBoard、Mouse具体元素类
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Computer;
class Mouse;
class KeyBoard;
class ComputerPartVisitor 
{
public:
    virtual void visit(Computer *computer) = 0;
    virtual void visit(Mouse *mouse) = 0;
    virtual void visit(KeyBoard *keyboard) = 0;
};

class ComputerPartDisplayVisitor:public ComputerPartVisitor 
{
public:
    void visit(Computer *computer) override
    {
        std::cout<<"访问电脑部件"<<std::endl;
    }
    void visit(Mouse *mouse) override
    {
        std::cout<<"访问鼠标部件"<<std::endl;
    }
    void visit(KeyBoard *keyboard) override
    {
        std::cout<<"访问键盘部件"<<std::endl;
    }
};

class ComputerPart
{
public:
    virtual void accept(std::shared_ptr<ComputerPartVisitor> cpdv) = 0;
};

class Computer:public ComputerPart
{
private:
    std::vector<std::shared_ptr<ComputerPart>> part_vec;
public:
    Computer(); 
    void accept(std::shared_ptr<ComputerPartVisitor> cpdv)
    {
        for(auto item: part_vec)
        {
            item->accept(cpdv);
        }
        cpdv->visit(this);
    }
};

class KeyBoard:public ComputerPart
{
public:
    void accept(std::shared_ptr<ComputerPartVisitor> cpdv)
    {
        cpdv->visit(this);
    }
};

class Mouse:public ComputerPart
{
public:
    void accept(std::shared_ptr<ComputerPartVisitor> cpdv)
    {
        cpdv->visit(this);
    }
};

Computer::Computer() 
{
    part_vec.push_back(std::make_shared<Mouse>());
    part_vec.push_back(std::make_shared<KeyBoard>());
}