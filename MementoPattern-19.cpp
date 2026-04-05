#include "MementoPattern-19.h"

using namespace std;

int main()
{
    // 主函数：演示备忘录模式的使用
    std::cout << "=== 游戏备忘录模式演示 ===" << std::endl;
    
    // 创建游戏角色
    GameOriginator player("冒险者");
    Caretaker caretaker(&player);
    
    std::cout << "\n--- 游戏开始 ---" << std::endl;
    player.display();
    
    // 进行游戏并保存状态
    std::cout << "\n--- 第1次游戏进程 ---" << std::endl;
    player.play_game();
    player.display();
    caretaker.backup();  // 保存状态1
    
    std::cout << "\n--- 第2次游戏进程 ---" << std::endl;
    player.play_game();
    player.display();
    caretaker.backup();  // 保存状态2
    
    std::cout << "\n--- 第3次游戏进程 ---" << std::endl;
    player.play_game();
    player.display();
    caretaker.backup();  // 保存状态3
    
    // 显示所有存档
    caretaker.show_history();
    
    // 恢复到第一个存档
    std::cout << "\n--- 恢复到存档1 ---" << std::endl;
    caretaker.undo(0);
    
    // 尝试另一个存档
    std::cout << "\n--- 恢复到存档2 ---" << std::endl;
    caretaker.undo(1);
    
    // 演示更多游戏进程而不保存
    std::cout << "\n--- 继续游戏（不保存） ---" << std::endl;
    player.play_game();
    player.play_game();
    player.display();
    
    // 再次恢复到存档
    std::cout << "\n--- 再次恢复到存档3 ---" << std::endl;
    caretaker.undo(2);
    
    std::cout << "\n=== 演示结束 ===" << std::endl;
    return 0;
}