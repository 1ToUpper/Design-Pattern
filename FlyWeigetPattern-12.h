/* @name 12.享元模式
 * @type 结构型模式
 * @define 用于减少创建对象的数量，以减少内存占用和提高性能。
 * @use 尝试重用现有的同类对象，如果未找到匹配的对象，则创建新对象。
 * @advantages
 *      1\减少内存消耗  2\减少对象创建时间
 * @disadvantages
 *      1\增加系统复杂度  2\线程安全问题
 * @instance 
    场景描述
        一个类 Robot，设置一个全局静态的map，用于映射机器人id和robot对象。
        使用单例模式进行获取对象。
 */

#include <iostream>
#include <memory>
#include <map>

class Robot;
static std::map<int, std::shared_ptr<Robot>> g_s_Robot_;

class Robot
{
private:
    int id_;
public:
    static std::shared_ptr<Robot> get_instance(int id)
    {
        auto it = g_s_Robot_.find(id);
        if(it == g_s_Robot_.end())
        {
            g_s_Robot_[id] = std::shared_ptr<Robot>(new Robot(id));
            std::cout<<"Robot["<<id<<"]对象不存在，创建新对象"<<std::endl;
        }
        else
        {
            std::cout<<"Robot["<<id<<"]对象已存在，直接获取"<<std::endl;
        }
        return g_s_Robot_[id];
    }
private:
    Robot(int id) : id_(id) {   }
};