#include "CommandPattern-18.h"

using namespace std;

int main()
{
    Receiver *rece = new Receiver();
    std::shared_ptr<WriteFileCommand> wr_cmd = std::make_shared<WriteFileCommand>("data.txt", rece);
    std::shared_ptr<DeleteFileCommand> del_cmd = std::make_shared<DeleteFileCommand>("data.txt", rece);

    Invoker invoke;
    invoke.set_command(wr_cmd);
    invoke.execute_command();
    invoke.set_command(del_cmd);
    invoke.execute_command();
    return 0;
}