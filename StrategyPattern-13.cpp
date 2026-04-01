#include "StrategyPattern-13.h"

using namespace std;

int main()
{
    AddOp* add_op = new AddOp();
    MulOp* mul_op = new MulOp();

    Context context;
    int res = 0;
    res = context.do_op(2, 3);
    std::cout<<"res = "<<res<<std::endl;
    context.set_strategy(add_op);
    res = context.do_op(2, 3);
    std::cout<<"res = "<<res<<std::endl;
    context.set_strategy(mul_op);
    res = context.do_op(2, 3);
    std::cout<<"res = "<<res<<std::endl;
    return 0;
}