#pragma once
#include <iostream>
#include <string>

using namespace std;

bool test_string(string txt)
{
	string comp = "`~,<>/?;:'[{]}=_)(*&%$#@!| QWERTYUIOPASDFGHJKLZCVBNMqwertyuiopasdfghjklzcxvbnm";
	string* ss = new string[4];
	ss[0] = "++", ss[1] = "+-", ss[2] = "--", ss[3] = "-+";
	for (int j = 0; j < comp.length(); j++)
	{
		if (txt.find(comp[j]) != string::npos)
		{
			cout << "b³edny argument" << endl;
			return false;
		}
	}
	for (int j = 0; j < 4; j++)
	{
		if (txt.find(ss[j]) != string::npos)
		{
			cout << "b³edny argument" << endl;
			return false;
		}
	}
	return true;
}

int get_max_pow(string txt)
{
	int i = 0;
	int leng = txt.length();
	int tmp_int=0;
	string tmp = "";
	if (!test_string(txt))
		return 0;

	while (i < leng)
	{
		if (txt[i] == 'X' && txt[i + 1] != '^')
		{
			if(tmp_int<1)
			tmp_int = 1;
		}
		if (txt[i] == '^')
		{
			i++;
			while (i < leng && txt[i] != '+' && txt[i] != '-')
			{
				tmp += txt[i];
				i++;
			}
			if (stoi(tmp) > tmp_int)
			{
				tmp_int = stoi(tmp);
			}
			tmp = "";
		}
		i++;
	}
	return (tmp_int+1);

}


int* transform(string txt)
{
	int pw= get_max_pow(txt);
	int* tab= new int[pw];
	for (int i = 0; i < pw; i++)
		tab[i] = 0;


	int leng = txt.length();
	int pow = 0, tmp_int = 0;
	string tmp = "";

	for (int i = 0; i < leng; i++)
	{
		if (txt[i] == 'X' && i + 1 < leng && txt[i + 1] == '^')
		{
			if (tmp == "" || tmp == "+")
				tmp_int = 1;
			else if (tmp == "-")
				tmp_int = -1;
			else
				tmp_int = stoi(tmp);
			tmp = "";
		}
		else if (txt[i] == 'X' && (i + 1 <= leng || txt[i + 1] != '^'))
		{
			*(tab+1) = stoi(tmp);
			tmp = "";
		}
		else if (txt[i] == '^')
		{
			i++;
			while (i < leng && txt[i] != '+' && txt[i] != '-')
			{
				tmp += txt[i];
				i++;
			}
			i--;
			pow = stoi(tmp);
			tmp = "";
			*(tab + pow) = tmp_int;
			tmp_int = 1;
		}
		else if (tmp!=""&&tmp.length()>0 && (txt[i] == '+' || txt[i] == '-'))
		{
			*(tab) = stoi(tmp);
			tmp = txt[i];
		}
		else
			tmp += txt[i];
	}
	if (tmp != "")
	{
		tab[0] = stoi(tmp);
	}
	return tab;
}
template <class L>
L* sort(L tab[],int z)
{
	int temp;
	L *n = new L[z];
	for (int i = 0; i < z; i++)
		for (int k = 0; k < z; k++)
			if (tab[k] > tab[i])
			{
				temp = tab[i];
				tab[i] = tab[k];
				tab[k] = temp;
			}
	memcpy(n, tab, sizeof(L)*z);
	delete[] tab;
	return n;
}