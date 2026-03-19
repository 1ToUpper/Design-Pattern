/* @name 2.单例模式
 * @type 创建型模式
 * @define 类负责创建自己的对象，并且确保只有一个对象会被创建
 * @use 类只有一个实例，全局仅有一个访问点
 * @instance 
 *  1\实现一个单例类，构造一个编号成员变量
 *  2\每次获取对象后，都打印编号
 */

#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton* get_instance(int num)
    {
        if(instance_ == nullptr)
        {
            instance_ = new Singleton(num);
        }
        return instance_;
    }
    void show_number() 
    { 
        printf("这是编号%d的对象.\n",number_); 
    }
private:
    Singleton() : number_(0) { }
    Singleton(int num):number_(num) { }
    ~Singleton() 
    { 
        printf("释放singleton对象.\n"); 
        if(instance_)
        {
            delete instance_;
            instance_ = nullptr;
        }
    }
private:
    static Singleton* instance_;
    int number_;
};

Singleton* Singleton::instance_ = nullptr;

int main()
{
    Singleton::get_instance(5)->show_number();
    Singleton::get_instance(1)->show_number();
    Singleton::get_instance(2)->show_number();
    return 0;
}