#include "ChainOfResponsibilityPattern-16.h"

using namespace std;

int main()
{
    std::shared_ptr<InfoLogger> info_log = std::make_shared<InfoLogger>();
    std::shared_ptr<WarnLogger> warn_log = std::make_shared<WarnLogger>();
    std::shared_ptr<ErrorLogger> error_log = std::make_shared<ErrorLogger>();

    warn_log->set_next_logger(info_log);
    info_log->set_next_logger(error_log);

    warn_log->print(AbstractLogger::INFO_, "这是消息！");
    warn_log->print(AbstractLogger::WARN_, "这是警告！！");
    warn_log->print(AbstractLogger::ERROR_, "这是报错！！！");
    return 0;
}