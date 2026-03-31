#include "CompositePattern-11.h"

using namespace std;

int main()
{
    Employee CEO("王总", "CEO", 30000);

    Employee Manager_1("张经理", "技术管理", 15000);
    Employee Tech_1("吴工", "技术工", 10000);
    Employee Tech_2("刘工", "技术工", 15000);
    
    Employee Manager_2("李经理", "内务管理", 12000);
    Employee Cleaner("刘保洁", "保洁员", 3000);
    Employee Financer("周财务", "财务", 12000);

    CEO.add(Manager_1);
    CEO.add(Manager_2);
    Manager_1.add(Tech_1);
    Manager_1.add(Tech_2);
    Manager_2.add(Cleaner);
    Manager_2.add(Financer);

    std::cout<<CEO.to_string() <<std::endl;
    std::cout<<Manager_1.to_string() <<std::endl;
    std::cout<<Tech_1.to_string() <<std::endl;
    std::cout<<Tech_2.to_string() <<std::endl;
    std::cout<<Manager_2.to_string() <<std::endl;
    std::cout<<Cleaner.to_string() <<std::endl;
    std::cout<<Financer.to_string() <<std::endl;
    return 0;
}