/* @name 11.组合模式
 * @type 结构型模式
 * @define 部分整体模式，是用于把一组相似的对象当作一个单一的对象。
 * @use 表示对象的层次结构时,使用树形结构处理，如文件系统或组织结构。
 * @advantages
 *      1\客户端可以统一处理所有类型的节点 2\可以轻松添加新的叶子类型或树枝类型
 * @disadvantages
 *      1\违背依赖倒置原则
 * @instance 
    场景描述
        一个类 Employee，该类被当作组合模型类。使用 Employee 类来添加部门层次结构，并打印所有员工。
 */

#include <iostream>
#include <list>
#include <string>

class Employee
{
private:
    std::string name;
    std::string dept;
    double salary;
    std::list<Employee> subordinates;
public:
    Employee(const std::string &na, const std::string &dp, double sal):name(na), dept(dp), salary(sal) {    };
    bool operator==(const Employee& ee) const
    {
        return (ee.name == this->name && ee.dept == this->dept && this->salary == ee.salary && this->subordinates == ee.subordinates);
    }
    void add (Employee ee) { subordinates.push_back(ee); }
    void remove(Employee ee) { subordinates.remove(ee); }
    std::list<Employee> get_subordinates() { return subordinates; }
    std::string to_string() 
    {
        return ("Employee :[ Name : "+ name +", dept : "+ dept + ", salary :" + std::to_string(salary) +" ]");}
};