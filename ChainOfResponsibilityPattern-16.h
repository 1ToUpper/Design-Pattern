/* @name 16.责任链模式
 * @type 行为型模式
 * @define 创建了一个接收者对象的链。
 * @use 通过将多个处理器（处理对象）以链式结构连接起来，使得请求沿着这条链传递，直到有一个处理器处理该请求为止。
 * @advantages
 *      1\降低耦合  2\简化对象  3\责任处理灵活  4\容易拓展
 * @disadvantages
 *      1\请求可能不会被处理  2\链式传递影响性能
 * @instance 
    场景描述
        创建抽象类 AbstractLogger，带有详细的日志记录级别。然后我们创建三种类型的记录器，都扩展了 AbstractLogger。
        每个记录器消息的级别是否属于自己的级别，如果是则相应地打印出来，否则将不打印并把消息传给下一个记录器。
 */

#include <iostream>
#include <memory>
#include <string>

class AbstractLogger
{
public:
    enum LoggerLevel
    {
        INFO_ = 1,
        WARN_,
        ERROR_,
    };
    AbstractLogger(LoggerLevel lv) : level(lv) { }
    virtual void set_next_logger(std::shared_ptr<AbstractLogger> abs_logger)
    {
        next_logger = abs_logger;
    }
    virtual void print(LoggerLevel lv, const std::string& msg)
    {
        if(lv != level)
        {
            if(next_logger)
            {
                next_logger->print(lv, msg);
            }
            else
            {
                std::cout<<"未知等级报错信息！"<<std::endl;
            }
        }
        else 
        {
            if(lv == INFO_)
            {
                std::cout<<"消息级别: "<<msg<<std::endl;
            }
            else if(lv == WARN_)
            {
                std::cout<<"警告级别: "<<msg<<std::endl;
            }
            else if(lv == ERROR_)
            {
                std::cout<<"错误级别: "<<msg<<std::endl;
            }
        }
    }
protected:
    std::shared_ptr<AbstractLogger> next_logger;
    LoggerLevel level;
};

class InfoLogger : public AbstractLogger
{
public:
    InfoLogger() : AbstractLogger(INFO_) { }
    void set_next_logger(std::shared_ptr<AbstractLogger> abs_logger) override
    {
        next_logger = abs_logger;
    }
};

class WarnLogger : public AbstractLogger
{
public:
    WarnLogger() : AbstractLogger(WARN_) { }
};

class ErrorLogger : public AbstractLogger
{
public:
    ErrorLogger() : AbstractLogger(ERROR_) { }
};