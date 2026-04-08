/* @name 20.状态模式
 * @type 行为型模式
 * @define 创建表示各种状态的对象和一个行为随着状态对象改变而改变的 context 对象
 * @use 允许对象在内部状态改变时改变其行为，使得对象在不同的状态下有不同的行为表现。
 *      通过将每个状态封装成独立的类，可以避免使用大量的条件语句来实现状态切换。
 * @advantages
 *      1\封装状态转换原则  2\易于拓展  3\集中状态相关行为  4\简化条件语句  5\状态共享
 * @disadvantages
 *      1\增加类和对象的数量  2\实现复杂  3\不满足开闭原则
 * @instance 
    场景描述
        创建一个State状态基类，派生出StartState、PauseState、StopState三个游戏状态，提供doAction接口
        创建一个Game游戏类，持有状态对象，并保持setState、getState
 */

#include <iostream>
#include <memory>
#include <string>

class State;
class Game
{
public:
    Game() : st(nullptr) { }
    std::shared_ptr<State> get_state() { return st; }
    void set_state(std::shared_ptr<State> state) { st = state; }
private:
    std::shared_ptr<State> st;
};
class State
{
public:
    virtual void do_action(std::shared_ptr<Game> game) = 0;
};

class StartState : public State
{
public:
    virtual void do_action(std::shared_ptr<Game> game)
    {
        std::cout << "Start game" << std::endl;
        game->set_state(std::make_shared<StartState>());
    }
};

class PauseState : public State
{
public:
    virtual void do_action(std::shared_ptr<Game> game)
    {
        std::cout << "Pause game" << std::endl;
        game->set_state(std::make_shared<PauseState>());
    }
};

class StopState : public State
{
public:
    virtual void do_action(std::shared_ptr<Game> game)
    {
        std::cout << "Stop game" << std::endl;
        game->set_state(std::make_shared<StopState>());
    }
};