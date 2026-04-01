/* @name 14.模板方法模式
 * @type 行为型模式
 * @define 一个抽象类公开定义了执行它的方法的方式/模板，高度抽象相同方法
 * @use 它的子类可以按需要重写方法实现，但调用将以抽象类中定义的方式进行。
 * @advantages
 *      1\封装固定部分  2\拓展可变部分  3\抽取公共代码
 * @disadvantages
 *      1\类数目增加
 * @instance 
    场景描述
        创一个Game的基类，有invite、start、end、setting方法，有ComputerGame和FriendGame两种，对基类中的接口进行重写
 */

#include <iostream>

class Game
{
public:
    //固定的游戏开始流程，final关键字修饰，子类不可以修改
    virtual void start() final
    {
        invite();
        setting();
        play();
        end();
    };
    virtual void invite() = 0;
    virtual void setting() = 0;
    virtual void play() = 0;
    virtual void end() = 0;
};

class ComputerGame : public Game
{
    void invite() override 
    {
        std::cout<<"Invite some fiends to play computer games."<<std::endl;
    }
    void setting() override 
    {
        std::cout<<"Set game settings."<<std::endl;
    }
    void play() override 
    {
        std::cout<<"Play the game with your friends."<<std::endl;
    }
    void end() override 
    {
        std::cout<<"End the game and close your computer."<<std::endl;
    }
};

class FriendGame : public Game
{
    void invite() override 
    {
        std::cout<<"Invite some fiends to play outhouse games."<<std::endl;
    }
    void setting() override 
    {
        std::cout<<"Talk about the game settings with your friends."<<std::endl;
    }
    void play() override 
    {
        std::cout<<"Play the game with your friends."<<std::endl;
    }
    void end() override 
    {
        std::cout<<"End the game and go home."<<std::endl;
    }
};