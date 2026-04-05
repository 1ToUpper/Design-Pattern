#include "IteratorPattern-15.h"

using namespace std;

int main()
{
    NameRepository nameRes;
    nameRes.add_name("Michal");
    nameRes.add_name("Sarah");

    std::shared_ptr<Iterator> iter = nameRes.get_Iterator();

    std::cout<<"遍历所有的名称："<<std::endl;
    while(iter->has_next())
    {
        std::string name = iter->next();
        std::cout << "名称: " << name << std::endl;
    }
    // 重置迭代器（如果需要的话，可以创建一个新的）
    std::cout << "\n重新遍历（获取新迭代器）：" << std::endl;
    iter = nameRes.get_Iterator();
    while (iter->has_next()) 
    {
        std::cout << iter->next() << " ";
    }
    std::cout << std::endl;
    return 0;
}