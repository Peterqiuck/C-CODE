
#include <iostream>

int main()
{
    enum class weaponlv :int//定义武器为类型，默认int
    {
        normal = 10, neck1 = normal,//左右平级
        high, neck2 = high,
        rare = 2, neck3 = rare,
        epic, neck4 = epic,
        legend, neck5 = legend,
        myth = 20, neck6 = myth

    };
    weaponlv equipA{ weaponlv::high };//定义初始化
    weaponlv equipB{ weaponlv::legend };

    short diff = (short)equipA - (short)equipB;//需要强制类型转换
    std::cout << "装备品质为" << (short)equipA << char(10);//需要强制类型转换
    std::cout << "装备差异化" << diff;
