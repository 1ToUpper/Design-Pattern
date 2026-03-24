/* @name 4.建造者模式
 * @type 创建型模式
 * @define 将一个复杂对象的构建过程与其表示相分离，从而可以创建具有不同表示形式的对象。
 * @instance 
 *  1/创建一个电脑组装工厂ComputerBuilder.cpp
 *  2/电脑中包含主要硬件 CPU类、主板board类、GPU类、内存RAM、固态硬盘HDD
 *  3/电脑有一个测评跑分benchMark()的功能，不同品级的硬件分数不同
 */

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Product
{
public:
    Product(const std::string& g, double p) : grade_(g), price_(p) { };
    inline std::string get_grade() const { return grade_; }
    inline double get_price() const { return price_; }
protected:
    std::string grade_;
    double price_;
};

class CPU : public Product
{
public:
    CPU(const std::string& g, double p) : Product(g, p) { };
};

class RAM : public Product
{
public:
    RAM(const std::string& g, double p) : Product(g, p) { };
};

class MotherBoard : public Product
{
public:
    MotherBoard(const std::string& g, double p) : Product(g, p) { };
};

class HDD : public Product
{
public:
    HDD(const std::string& g, double p) : Product(g, p) { };
};

class Computer
{
public:
    void set_CPU(std::unique_ptr<CPU> cpu) {cpu_ = std::move(cpu);}
    void set_RAM(std::unique_ptr<RAM> ram) {ram_ = std::move(ram);}
    void set_HDD(std::unique_ptr<HDD> hdd) {hdd_ = std::move(hdd);}
    void set_MotherBoard(std::unique_ptr<MotherBoard> mb) {mother_board_ = std::move(mb);}
    double get_total_price() const;
    void show_config() const;
private:
    std::unique_ptr<CPU> cpu_;
    std::unique_ptr<RAM> ram_;
    std::unique_ptr<HDD> hdd_;
    std::unique_ptr<MotherBoard> mother_board_;
};

class ComputerBuilder
{
protected:
    std::unique_ptr<Computer> computer_;
public:
    ComputerBuilder() { computer_ = std::make_unique<Computer>(); }

    Computer* get_computer() { return computer_.release();} 

    virtual void build_cpu() = 0;
    virtual void build_hdd() = 0;
    virtual void build_mother_board() = 0;
    virtual void build_ram() = 0;
};

class HigherComputerBuilder : public ComputerBuilder
{
public:
    virtual void build_cpu() override;
    virtual void build_hdd() override;
    virtual void build_mother_board() override;
    virtual void build_ram() override;
};

class MiddleComputerBuilder : public ComputerBuilder
{
public:
    virtual void build_cpu() override;
    virtual void build_hdd() override;
    virtual void build_mother_board() override;
    virtual void build_ram() override;
};

class LowerComputerBuilder : public ComputerBuilder
{
public:
    virtual void build_cpu() override;
    virtual void build_hdd() override;
    virtual void build_mother_board() override;
    virtual void build_ram() override;
};

class ComputerAssembler
{
private:
    ComputerBuilder* builder_;
public:
    inline void set_Builder(ComputerBuilder* builder) { builder_ = builder; }
    Computer* assembleComputer()
    {
        if(!builder_)
        {
            return nullptr;
        }
        else
        {
            builder_->build_cpu();
            builder_->build_hdd();
            builder_->build_mother_board();
            builder_->build_ram();
            return builder_->get_computer();
        }
    }
};