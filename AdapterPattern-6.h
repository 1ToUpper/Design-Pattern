/* @name 6.适配器模式
 * @type 行为型模式
 * @define 将一个类的接口转换为另一个接口，使得原本不兼容的类可以协同工作。
 * @use 在软件系统中，需要将现有的对象放入新环境，而新环境要求的接口与现有对象不匹配。
 * @instance 
    场景描述
    假设我们有以下接口不兼容的情况：
        目标接口：USBTypeC- 现代手机使用的USB-C接口
        被适配者：
            MicroUSBCharger- 老式Micro USB充电器
            LightningCharger- 苹果的Lightning接口充电器
            WirelessCharger- 无线充电器
    需要创建适配器，让这些旧的或不兼容的充电器能为USB-C手机充电。
 */

#include <iostream>
#include <string>
#include <memory>
#include <variant>
#include <vector>

// ========== 目标接口：USB-C ==========
class USBTypeC 
{
public:
    virtual ~USBTypeC() = default;
    virtual std::string charge_with_USBC() = 0;
};

// ========== 被适配的充电接口 ==========
//1.Micro USB 充电器
class MicroUSBChanger
{
public:
    std::string charge_with_micro_USB() { return "使用Micro USB接口充电，功率: 5V/2A"; }
    // Micro USB独有功能
    std::string get_micro_USB_status() { return "Micro USB连接状态: 正常"; }
};

// 2. Lightning充电器（苹果）
class LightningCharger {
public:
    std::string charge_with_lightning() { return "使用Lightning接口充电，功率: 5V/1A"; }
    std::string check_MFi_certification() { return "MFi认证: 已通过"; }
};

// ========== 具体适配器类 ==========
class MicroUSBToTypeCAdapter : public USBTypeC
{
private:
    // 关键：包含被适配对象的指针
    MicroUSBChanger *mic_usb_ptr;
public:
    explicit MicroUSBToTypeCAdapter(MicroUSBChanger* charger) : mic_usb_ptr(charger)
    {
        std::cout << "创建Micro USB转USB-C适配器" << std::endl;
    }

    //实现目标接口
    std::string charge_with_USBC() override
    {
        if(!mic_usb_ptr)
        {
            return "适配器错误，Micro USB充电器未连接";
        }
        //省略：电压、参数等调整
        std::string result = "通过适配器: ";
        result += mic_usb_ptr->charge_with_micro_USB();
        result += " (转换为USB-C标准)";
        return result;
    }

    // 适配器特有的功能
    void checkMicroUSBConnection() 
    {
        if (mic_usb_ptr) 
        {
            std::cout << mic_usb_ptr->get_micro_USB_status() << std::endl;
        }
    }

};

class LightingToTypeCAdapter:public USBTypeC
{
private:
    LightningCharger *lighting_charger_;
public:
    explicit LightingToTypeCAdapter(LightningCharger* charger) : lighting_charger_(charger)
    {
        std::cout << "创建Lighting转USB-C适配器" << std::endl;
    }
    std::string charge_with_USBC() override 
    {
        if (!lighting_charger_) 
        {
            return "适配器错误: Lighting充电器未连接";
        }
    
        // 可能需要额外的认证转换
        std::string result = "通过适配器: ";
        result += lighting_charger_->charge_with_lightning();
        result += " (Lighting转为USB-C有线连接)";
        return result;
    }

    void verifyMFi() 
    {
        if (lighting_charger_) 
        {
            std::cout << lighting_charger_->check_MFi_certification() << std::endl;
        }
    }
};

class Phone 
{
private:
    std::string name;
    USBTypeC* charger; //手机使用USB-C
public:
    Phone(const std::string& phone_name, USBTypeC* charger = nullptr) 
        : name(phone_name), charger(charger) { }
    void charge()
    {
        if (charger) 
        {
            std::cout << "[" << name << "] ";
            std::cout << charger->charge_with_USBC() << std::endl;
        } 
        else 
        {
            std::cout << "[" << name << "] 警告: 未连接充电器" << std::endl;
        }
    }

    void set_charger(USBTypeC* newCharger) 
    {
        charger = newCharger;
        std::cout << "[" << name << "] 更换充电器" << std::endl;
    }
};
