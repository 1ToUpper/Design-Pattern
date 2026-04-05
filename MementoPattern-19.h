/* @name 19.备忘录模式
 * @type 行为型模式
 * @define 保存一个对象的某个状态，以便在适当的时候恢复对象
 * @use 当需要提供一种撤销机制，允许用户回退到之前的状态时。
 * @advantages
 *      1\提供状态恢复机制  2\封装状态信息
 * @disadvantages
 *      1\资源消耗
 * @instance 
    场景描述
        GameMemento（备忘录）：存储游戏状态（玩家名称、等级、生命值、魔法值、位置）
        GameOriginator（原发器）：游戏角色，可以创建备忘录和从备忘录恢复状态
        Caretaker（负责人）：管理备忘录的存储和恢复
 */

#include <iostream>
#include <string>
#include <memory>
#include <vector>

//备忘录类：存储游戏状态
class GameMemento
{
    friend class GameOriginator;
public:
    GameMemento(const std::string &name, int lv, int hp, int mp, const std::string &loc)
        :player_name(name), level(lv), health(hp), mana(mp), location(loc) {    }
    void display() const 
    {
        std::cout << "存档: " << player_name 
            << " 等级:" << level 
            << " 生命:" << health 
            << " 魔法:" << mana 
            << " 位置:" << location << std::endl;
    }
private:
    std::string player_name;
    int level;
    int health;
    int mana;
    std::string location;
};

//原发器类：游戏角色
class GameOriginator
{
private:
    std::string player_name;
    int level;
    int health;
    int mana;
    std::string location;
public:
    GameOriginator(const std::string &name):player_name(name),level(1),health(50),mana(100),location("新手村") { }
    void display() const 
    {
        std::cout << "存档: " << player_name 
            << " 等级:" << level 
            << " 生命:" << health 
            << " 魔法:" << mana 
            << " 位置:" << location << std::endl;
    }
        // 修改状态（模拟游戏进行）
    void play_game() 
    {
        level++;
        health -= 10;
        mana -= 5;
        if (location == "新手村")
        {
            location = "森林";
        }
        else if (location == "森林") 
        {
            location = "城堡";
        }
        else 
        { 
            location = "地下城";
        }
        std::cout << player_name << " 进行游戏，状态发生变化..." << std::endl;
    }
    // 创建备忘录（保存状态）
    std::unique_ptr<GameMemento> save() 
    {
        std::cout << "保存游戏状态..." << std::endl;
        return std::make_unique<GameMemento>(player_name, level, health, mana, location);
    }
    // 设置状态（用于演示）
    void set_state(int lvl, int hp, int mp, const std::string& loc) 
    {
        level = lvl;
        health = hp;
        mana = mp;
        location = loc;
    }
    // 恢复状态
    void restore(const GameMemento* memento) 
    {
        std::cout << "从存档恢复游戏状态..." << std::endl;
    }
};

// 负责人类：管理备忘录
class Caretaker
{
private:
    std::vector<std::unique_ptr<GameMemento>> mementos;
    GameOriginator* obj;
public:
    Caretaker(GameOriginator* originator) : obj(originator) {   }
    void backup()
    {
        mementos.push_back(obj->save());
    }
    void undo(size_t index)
    {
        if (index < mementos.size()) 
        {
            obj->restore(mementos[index].get());
            std::cout << "已恢复存档" << index + 1 << ":" << std::endl;
            mementos[index]->display();
        } 
        else 
        {
            std::cout << "无效的存档索引!" << std::endl;
        }
    }
    // 显示所有备份
    void show_history() const 
    {
        std::cout << "\n=== 存档列表 ===" << std::endl;
        for (size_t i = 0; i < mementos.size(); ++i) 
        {
            std::cout << "存档" << i + 1 << ": ";
            mementos[i]->display();
        }
        if (mementos.empty()) 
        {
            std::cout << "暂无存档" << std::endl;
        }
    }
    
};