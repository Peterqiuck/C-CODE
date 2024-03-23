

#include <iostream>

int main()
{
    int a=10;
    int send = ++a + 5;
    std::cout<<"send=" <<send<<" a=" <<a<< std::endl;
    a = 10;
    //send = a-- + 5;
    send = 5 + a--;
    
    std::cout << "send=" << send << " a=" << a << std::endl;

    //int end = b / 3;
    //int a = b % 4;//b除以4的余数
    //b= b % 6;//等于上面
    //std::cout << end<<std::endl;
    //std::cout << b;
}

