/* @name 17.观察者模式
 * @type 行为型模式
 * @define 定义了一种一对多的依赖关系，当一个对象的状态发生改变时，其所有依赖者都会收到通知并自动更新。
 * @use -
 * @advantages
 *      1\抽象耦合  2\自动触发机制 
 * @disadvantages
 *      1\性能问题  2\循环依赖  3\观察者不知道变化的细节
 * @instance 
    场景描述
        使用三个类 Subject、Observer 和 Client。Subject 对象带有绑定观察者到 Client 对象和从 Client 对象解绑观察者的方法。
        创建 Subject 类、Observer 抽象类和扩展了抽象类 Observer 的实体类。
 */

#include <iostream>
#include <vector>
#include <memory>

class Subject;
class Observer;

class Observer
{
public:
    Subject* subject;
public:
    Observer(Subject* sub) : subject(sub) { }
    virtual void update() = 0;
};

class LowObserver : public Observer
{
public:
    LowObserver(Subject* sub) : Observer(sub) { }
    void update() override;
};

class HighObserver : public Observer
{
public:
    HighObserver(Subject* sub) : Observer(sub) { }
    void update() override;
};

class Subject
{
private:
    std::vector<std::shared_ptr<Observer>> obs;
    int state;
public:
    Subject() : state(0) {  }
    inline int get_state() const { return state; }
    inline void set_state(int st) { state = st; notify_all_observer(); }
    void attach(std::shared_ptr<Observer> ob) 
    {
        obs.push_back(ob);
    }
    void notify_all_observer();
};

void LowObserver::update()
{
    std::cout << "低级观察者观测到状态:" << subject->get_state() << std::endl;
}

void HighObserver::update()
{
    std::cout << "高级观察者观测到状态:" << subject->get_state() << std::endl;
}

void Subject::notify_all_observer()
{
    for(auto &ob : obs)
    {
        ob->update();
    }
}