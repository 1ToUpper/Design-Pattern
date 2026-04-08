#include "StatePattern-20.h"

using namespace std;

int main()
{
    std:shared_ptr<Game> my_game = std::make_shared<Game>();
    StartState start_st;
    StopState stop_st;
    PauseState pause_st;

    start_st.do_action(my_game);
    pause_st.do_action(my_game);
    stop_st.do_action(my_game);
    return 0;
}