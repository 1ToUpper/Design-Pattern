#include "BuilderPattern-4.h"

double Computer::get_total_price() const
{
    double total_price = 0.0;
    if(cpu_) total_price += cpu_->get_price();
    if(ram_) total_price += ram_->get_price();
    if(hdd_) total_price += hdd_->get_price();
    if(mother_board_) total_price += mother_board_->get_price();
    return total_price;
}

void Computer::show_config() const 
{
    std::cout << "电脑配置清单：" << std::endl;
    if (cpu_) std::cout << "CPU: " << cpu_->get_grade() << " (价格: " << cpu_->get_price() << ")" << std::endl;
    if (mother_board_) std::cout << "主板: " << mother_board_->get_grade() << " (价格: " << mother_board_->get_price() << ")" << std::endl;
    if (ram_) std::cout << "内存: " << ram_->get_grade() << " (价格: " << ram_->get_price() << ")" << std::endl;
    if (hdd_) std::cout << "固态硬盘: " << hdd_->get_grade() << " (价格: " << hdd_->get_price() << ")" << std::endl;
    std::cout << "总报价: " << get_total_price() << std::endl;
}

void HigherComputerBuilder::build_cpu()
{
    computer_->set_CPU(std::make_unique<CPU>("i19-18800K", 9888));
}
void HigherComputerBuilder::build_hdd()
{
    computer_->set_HDD(std::make_unique<HDD>("西部数据plus+", 3688));
}
void HigherComputerBuilder::build_mother_board()
{
    computer_->set_MotherBoard(std::make_unique<MotherBoard>("Z790旗舰主板+", 899));
}
void HigherComputerBuilder::build_ram()
{
    computer_->set_RAM(std::make_unique<RAM>("超容量64G彗星内存", 5899));
}

void MiddleComputerBuilder::build_cpu()
{
    computer_->set_CPU(std::make_unique<CPU>("i9-14600K", 4650));
}
void MiddleComputerBuilder::build_hdd()
{
    computer_->set_HDD(std::make_unique<HDD>("闪迪二代", 1688));
}
void MiddleComputerBuilder::build_mother_board()
{
    computer_->set_MotherBoard(std::make_unique<MotherBoard>("A11旗舰主板", 500));
}
void MiddleComputerBuilder::build_ram()
{
    computer_->set_RAM(std::make_unique<RAM>("32G彗星内存", 2200));
}

void LowerComputerBuilder::build_cpu()
{
    computer_->set_CPU(std::make_unique<CPU>("i7-19400K", 2800));
}
void LowerComputerBuilder::build_hdd()
{
    computer_->set_HDD(std::make_unique<HDD>("爱国者新一代16GB", 900));
}
void LowerComputerBuilder::build_mother_board()
{
    computer_->set_MotherBoard(std::make_unique<MotherBoard>("A11旗舰主板", 500));
}
void LowerComputerBuilder::build_ram()
{
    computer_->set_RAM(std::make_unique<RAM>("16G月球内存", 600));
}

int main()
{
    ComputerAssembler assember;
    HigherComputerBuilder higher_builder;
    assember.set_Builder(&higher_builder);
    Computer* high_cmp = assember.assembleComputer();

    std::cout << "=== 高性能游戏电脑 ===" << std::endl;
    high_cmp->show_config();
    std::cout << std::endl;

    MiddleComputerBuilder middler_builder;
    assember.set_Builder(&middler_builder);
    Computer* mid_cmp = assember.assembleComputer();

    std::cout << "=== 中端办公电脑 ===" << std::endl;
    mid_cmp->show_config();
    std::cout << std::endl;

    LowerComputerBuilder lower_builder;
    assember.set_Builder(&lower_builder);
    Computer* low_cmp = assember.assembleComputer();

    std::cout << "=== 低端学习电脑 ===" << std::endl;
    low_cmp->show_config();
    std::cout << std::endl;
    return 0;
}