/* @name 15.迭代器模式
 * @type 行为型模式
 * @define 提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露其内部的表示。
 * @use -
 * @advantages
 *      1\支持多种遍历方式  2\简化聚合类  3\多遍历支持  4\拓展性好
 * @disadvantages
 *      1\新增聚合类需要增加对应的迭代器类
 * @instance 
    场景描述
        创建一个叙述导航方法的 Iterator 接口和一个返回迭代器的 Container 接口。实现了 Container 接口的实体类将负责实现 Iterator 接口。  
        IteratorPatternDemo，我们的演示类使用实体类 NamesRepository 来打印 NamesRepository 中存储为集合的 Names。
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>

//1.Iterator接口
class Iterator
{
public:
    virtual bool has_next() = 0;
    virtual std::string next() = 0;
};

//2.Container接口
class Container
{
public:
    virtual std::shared_ptr<Iterator> get_Iterator() = 0;
};

class NameRepository : public Container
{
private:
    std::vector<std::string> names;
public:
    NameRepository()
    {
        names = {"Robot", "John", "Julie"};
    }
    std::shared_ptr<Iterator> get_Iterator() override;
    void add_name(const std::string& name)
    {
        names.push_back(name);
    }
    const std::vector<std::string>& get_names() const
    {
        return names;
    }
};

class NameIterator : public Iterator
{
private:
    NameRepository* name_res;
    int index;
public:
    explicit NameIterator(NameRepository* res) : name_res(res), index(0) { }
    bool has_next() override
    {
        auto &names = name_res->get_names();
        return index < names.size();
    }
    std::string next() override 
    {
        auto& names = name_res->get_names();
        if(has_next())
        {
            return names[index++];
        } 
        return "";
    }
};

// 在类外定义getIterator方法
std::shared_ptr<Iterator> NameRepository::get_Iterator() 
{
    return std::make_shared<NameIterator>(this);
}