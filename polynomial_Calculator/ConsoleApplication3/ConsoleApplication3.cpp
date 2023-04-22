#include <iostream>
#include <string>
#include"wielomian.h"
#include"functions.h"
#include "ConsoleApplication3.h"
using namespace std;

int main()
{
	string* str = new string[2];
	wielomian<float>* ptrs = new wielomian<float>[4];
	do
	{
		cout << "wprowadz pierwszy wielomian w formacie X^y+X^b..." << endl;
		getline(cin, str[0]);
		//str[0] = "5-15X^8-10X^5+100X";
		//cout << str[0]<<endl;
	}
	while (test_string(str[0])==false);

	do
	{
		cout << "wprowadz drugi wielomian w formacie X^y+X^b..." << endl;
		getline(cin, str[1]);
		//str[1] = "1-X-12X^2+22X^4+12X^8";
		//cout << str[1] << endl;

	}
	while (test_string(str[1]) == false);
	
	for (int i = 0; i < 2; i++)
	{
		ptrs[i] = wielomian<float>(str[i]);
	}

	//ptrs[2]= 1.145*ptrs[1]*3.3;
	//ptrs[2] = 2 * ptrs[1] * 3;
	//ptrs[2] = ptrs[1]*ptrs[1];
	//cout <<ptrs[2];

	ptrs[2] = ptrs[0] + ptrs[1];

	cout << ptrs[2] << endl;

	for (int i = 0; i < 3; i++)
		ptrs[i].clear();
	delete[] ptrs;
	delete[] str;
	return 0;
}
//12X^3-2X^2+5X-55
//2X^5-22X-5