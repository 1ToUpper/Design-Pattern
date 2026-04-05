/* @name 17.命令模式
 * @type 行为型模式
 * @define 将一个请求封装为一个对象，从而使你可以用不同的请求对客户进行参数化
 * @use 解决在软件系统中请求者和执行者之间的紧耦合问题，特别是在需要对行为进行记录、撤销/重做或事务处理等场景。
 * @advantages
 *      1\降低耦合  2\易于拓展
 * @disadvantages
 *      1\过多命令类
 * @instance 
    场景描述
        创建一个command抽象基类，创建写文件，删除文件的指令Command，其中有execute()、redo()、undo()的接口
 */

#include <iostream>
#include <string>
#include <memory>

class Receiver
{
public:
    void writeFile(const std::string& filename) 
    {
        std::cout << "Receiver: 写入文件 '" << filename << "'" << std::endl;
    }
    void deleteFile(const std::string& filename) 
    {
        std::cout << "Receiver: 删除文件 '" << filename << "'" << std::endl;
    }
};


class Command
{
public:
    virtual void execute() = 0;
    virtual std::string get_name() = 0;
};

class WriteFileCommand : public Command
{
public:
    WriteFileCommand(const std::string &file, Receiver* re) : file(file), receiver_(re), cmd_name("写入") { }
    std::string get_name() override { return cmd_name; }
    virtual void execute() override
    {
        if(receiver_) receiver_->writeFile(file);
    }
private:
    std::string file, cmd_name;
    Receiver* receiver_;  // 关联的接收者
};

class DeleteFileCommand : public Command
{
public:
    DeleteFileCommand(const std::string &file, Receiver* re) : file(file), receiver_(re), cmd_name("删除") { }
    std::string get_name() override { return cmd_name; }
    virtual void execute() override
    {
        if(receiver_) receiver_->deleteFile(file);
    }
private:
    std::string file, cmd_name;
    Receiver* receiver_;  // 关联的接收者
};

class Invoker {
public:
    // 设置单个命令
    void set_command(std::shared_ptr<Command> command) 
    {
        command_ = command;
    }
    
    // 执行当前命令
    void execute_command() 
    {
        if (command_) 
        {
            std::cout << "Invoker: 执行命令 - " << command_->get_name() << std::endl;
            command_->execute();
            command_ = nullptr;
        } 
        else 
        {
            std::cout << "Invoker: 没有设置命令" << std::endl;
        }
    }
    
    
private:
    std::shared_ptr<Command> command_;  // 持有的命令（对应UML图中的聚合关系）
};