/* @name 22.中介者模式
 * @type 行为型模式
 * @define 定义了一个中介对象来封装一系列对象之间的交互。中介者使各对象之间不需要显式地相互引用，从而使其耦合松散，且可以独立地改变它们之间的交互。
 * @use 降低多个对象和类之间的通信复杂性。
 * @advantages
 *      1\降低复杂度  2\解耦合  3\符合迪米特法则
 * @disadvantages
 *      1\复杂度
 * @instance 
    场景描述
        聊天室实例来演示中介者模式。实例中，多个用户可以向聊天室发送消息，聊天室向所有的用户显示消息。我们将创建两个类 ChatRoom 和 User。
        User 对象使用 ChatRoom 方法来分享他们的消息。
 */

#include <iostream>

class User
{
public:
    User(const std::string& name) : name(name) { }
    inline void set_name(std::string& name) { name = name;}
    inline const std::string& get_name() const { return name;}
    void send_message(const std::string& msg);
private:
    std::string name;
};
class RoomChat
{
public:
    static void show_message(const User *user, const std::string& msg)
    {
        std::cout <<"user:"<<user->get_name() <<"说:"<< msg << std::endl;
    }
};

void User::send_message(const std::string& msg)
{
    RoomChat::show_message(this, msg);
}

