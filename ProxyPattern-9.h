/* @name 9.代理模式
 * @type 结构型模式
 * @define 通过引入一个代理对象来控制对原对象的访问
 * @use 创建具有现有对象的对象，以便向外界提供功能接口。
 * @advantages
 *      1\控制访问和业务逻辑分离,解耦合  2\可以灵活地增加功能
 * @disadvantages
 *      1\代理类开销变大  2\某些代理的复杂度比较高
 * @instance 
    场景描述
        创建一个 Image 接口和实现了 Image 接口的实体类。
        ProxyImage 是一个代理类，减少 RealImage 对象加载的内存占用。
        ProxyPatternDemo 类使用 ProxyImage 来获取要加载的 Image 对象，并按照需求进行显示。
 */

#include <iostream>
#include <string>

class Image
{
public:
    virtual void display() = 0;
};

class RealImage : public Image
{
public:
    RealImage(const std::string& filename): file_name_(filename) { load_from_disk(); };
    virtual void display() override { std::cout << "展示内容:" << file_name_ << std::endl; }
private:
    void load_from_disk() { std::cout << "从硬盘中读取" << file_name_ << "..." << std::endl; }
private:
    std::string file_name_;
};

class ProxyImage : public Image
{
public:
    ProxyImage(const std::string& filename): file_name_(filename), real_image_(nullptr) { std::cout << "创建代理对象" << std::endl; };
    ~ProxyImage() { if(real_image_) delete real_image_; }
    virtual void display() override 
    {
        if(!real_image_)
        {
            real_image_ = new RealImage(file_name_);
        }
        real_image_->display();
    }
private:
    std::string file_name_;
    RealImage* real_image_;
};