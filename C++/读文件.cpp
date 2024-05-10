#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
	//"0",
	//"1",
	//"22",
	//"333",
	//"4444",
	//"55555",
	//"666666",
	//"7777777",
	//"88888888",
	//"999999999" 
	vector<string>Array;
	FILE* pf = fopen("text.tt", "r");
	if (pf == NULL)
		return 0;
	char ss[1024];
	while (fgets(ss, 1024, pf) != NULL)
	{
		Array.push_back(ss);
	}
	for (int i = 0; i < Array.size(); i++)
	{
		cout << Array[i];
	}
	return 0;
}