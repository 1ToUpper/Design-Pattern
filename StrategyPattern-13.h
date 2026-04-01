/* @name 13.策略模式
 * @type 行为型模式
 * @define 一个类的行为或其算法可以在运行时更改。
 * @use 定义了一系列算法或策略，并将每个算法封装在独立的类中，使得它们可以互相替换。
 * @advantages
 *      1\算法切换自由  2\消除复杂的if-else判断  3\拓展性好
 * @disadvantages
 *      1\复杂性高，每增加一个算法就要增加一个类  2\所有的策略类都要暴露
 * @instance 
    场景描述
        创建一个定义活动的 Strategy 接口和实现了 Strategy 接口的实体策略类。Context 是一个使用了某种策略的类。
        使用Context 和策略对象来演示 Context 在它所配置或使用的策略改变时的行为变化。
 */

#include <iostream>

class Strategy
{
public:
    virtual int do_operator(int n1, int n2) = 0;
};

class AddOp : public Strategy
{
public:
    int do_operator(int n1, int n2) override 
    {
        return n1 + n2;
    }
};

class MulOp : public Strategy
{
public:
    int do_operator(int n1, int n2) override 
    {
        return n1 * n2;
    }
};

class Context
{
private:
    Strategy* strategy;
public:
    Context() : strategy(nullptr) {    }
    void set_strategy(Strategy* st) 
    {
        strategy = st;
    }
    int do_op(int n1, int n2)
    {
        int res = -99999;
        if(strategy)
        {
            res = strategy->do_operator(n1, n2);
        }
        return res;
    }
};