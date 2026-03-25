/* @name 4.原型模式
 * @type 创建型模式
 * @define 使用原型实例指定要创建对象的种类，并通过拷贝这些原型创建新的对象。
 * @use 在运行时动态建立和删除原型。
 * 优点：性能提高/避免构造函数的约束。
 * 缺点：配备克隆方法需要全面考虑类的功能，对已有类可能较难实现。
 * @instance 
 *  1/原型接口（Prototype Interface）：定义一个用于克隆自身的接口，通常包括一个 clone() 方法。
 *  2/具体原型类（Concrete Prototype）：实现原型接口的具体类，负责实际的克隆操作。这个类需要实现 clone() 方法，通常使用浅拷贝或深拷贝来复制自身。
 *  3/客户端（Client）：使用原型实例来创建新的对象。客户端调用原型对象的 clone() 方法来创建新的对象，而不是直接使用构造函数。
 */
#include <iostream>
#include <memory>

using namespace std;

class PrototypeAbstract
{
public:
    PrototypeAbstract() = default;
    virtual std::shared_ptr<PrototypeAbstract> clone() const = 0;

};

class Prototype : public PrototypeAbstract
{
public:
    Prototype():num(0) { }
    Prototype(int n):num(n) { }
    Prototype(const Prototype& obj) : num(obj.num) 
    {
        std::cout<< "调用拷贝构造函数进行深拷贝操作" <<std::endl;
    }
    std::shared_ptr<PrototypeAbstract> clone() const override
    {
        return std::make_shared<Prototype>(*this);
    }
    inline void set_num(int n) {num = n;}
    inline int get_num() const {return num;} 

protected:
    int num;
};

int main()
{
    Prototype pp(10);
    std::cout<<"old对象的值:"<<pp.get_num()<<std::endl;
    auto pi = std::dynamic_pointer_cast<Prototype>(pp.clone());
    std::cout<<"new对象clone的值:"<<pi->get_num()<<std::endl;
    pi->set_num(7);
    std::cout<<"new对象修改后的值:"<<pi->get_num()<<std::endl;
    return 0;
}