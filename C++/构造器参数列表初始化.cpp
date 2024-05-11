#include <iostream>
#include<string>
using namespace std;
class A
{
public:
	A(const char* ps)  //注意这里需要const
		:name(ps),len(strlen(name.c_str())){}  //构造器参数列表初始化
	void print()
	{
		cout << len << endl;
	}
private:            //初始化列表中的初始化顺序与声明顺序有关，与前后赋值顺序无关，	  
	int len;        //这里先初始化len，而此时len为随机值，有溢出风险（不同编译器值不同），
	string name;    //更换len与name的位置，或者在构造器参数列表中的len赋值公式移到后面的花括号里，
};                  //移name的赋值公式没有效果

int main()
{
	A s("china");
	s.print();
	return 0;
}


