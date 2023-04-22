//#pragma once
#include<iostream>
#include<string>
using namespace std;
template <class T>
class wielomian
{
private:
    int lenght;
    T* ptr;
public:
    
    void print();
    void clear();
    T* get_ptr();
    int get_lenght();
    wielomian();
    wielomian(const wielomian&);
    wielomian(string);
    wielomian(int);
    wielomian(int,T*);
	wielomian operator + (const wielomian&)const;
	T operator [] (size_t);

	wielomian operator * (const wielomian&)const;
	wielomian<T> operator * (long double);
    template<typename T,typename K> friend wielomian<T> operator* (K, const wielomian<T> &p);

	bool operator == (const wielomian&);
	wielomian& operator = (const wielomian&);

	friend ostream& operator << <>(ostream& o, const wielomian& p);

};

template <class T>
wielomian<T>::wielomian()
{
	lenght = 0;
	ptr = NULL;
}
template <class T>
wielomian<T>::wielomian(const wielomian<T>& k)
{
	lenght = k.lenght;
	ptr = new T[k.lenght];
	memcpy(ptr, k.ptr, lenght * sizeof(int));
}
template <class T>
wielomian<T>::wielomian(string txt)
{
	int i = 0, pow = 0, leng = txt.length(), tmp_int = 0;
	string tmp = "";
	while (i < leng)
	{
		if (txt[i] == 'X' && txt[i + 1] != '^')
			if (tmp_int < 1)
				tmp_int = 1;
		if (txt[i] == '^')
		{
			i++;
			while (i < leng && txt[i] != '+' && txt[i] != '-')
			{
				tmp += txt[i];
				i++;
			}
			if (stold(tmp) > tmp_int)
				tmp_int = stold(tmp);
			tmp = "";
		}
		i++;
	}
	lenght = (tmp_int + 1);
	ptr = new T[lenght];
	for (int i = 0; i < lenght; i++)
		ptr[i] = 0;
	tmp = "";
	for (int i = 0; i < leng; i++)
		if (txt[i] == 'X' && i + 1 < leng && txt[i + 1] == '^')
		{
			if (tmp == "" || tmp == "+")
				tmp_int = 1;
			else if (tmp == "-")
				tmp_int = -1;
			else
				tmp_int = stold(tmp);
			tmp = "";
			i += 2;
			while (i < leng && txt[i] != '+' && txt[i] != '-')
			{
				tmp += txt[i];
				i++;
			}
			i--;
			pow = stold(tmp);
			tmp = "";
			*(ptr + pow) += tmp_int;
			tmp_int = 1;
		}
		else if (txt[i] == 'X' && (i + 1 <= leng || txt[i + 1] != '^'))
		{
			if (tmp == "-")
				*(ptr + 1) += -1;
			else if (tmp == "+" || tmp == "")
				*(ptr + 1) += 1;
			else
				*(ptr + 1) += stold(tmp);
			tmp = "";
		}
		else if (tmp != "" && (txt[i] == '+' || txt[i] == '-'))
		{
			*(ptr) += stold(tmp);
			tmp = txt[i];
		}
		else
			tmp += txt[i];
	if (tmp != "")
		ptr[0] += stold(tmp);
}
template <class T>
wielomian<T>::wielomian(int a)
{
	ptr = new T[a];
	lenght = a;
	for (int i = 0; i < lenght; i++)
		ptr[i] = 0;
}
template <class T>
wielomian<T>::wielomian(int a, T* pt)
{
	ptr = new T[a];
	lenght = a;
	for (int i = 0; i < lenght; i++)
		ptr[i] = pt[i];
	free(pt);
}
template <class T>
void wielomian<T>::clear()
{
	delete[]ptr;
}

template <class T>
T* wielomian<T>::get_ptr()
{
	return ptr;
}
template <class T>
int wielomian<T>::get_lenght()
{
	return lenght;
}

template <class T>
void wielomian<T>::print()
{
	for (int i = 0; i < lenght; i++)
		cout << ptr[i] << endl;
}
template <class T>
wielomian<T> wielomian<T>::operator + (const wielomian<T>& a)const
{
	wielomian<T> n;

	if (a.lenght > lenght)
	{
		n = wielomian<T>(a);
		for (int i = 0; i < lenght; i++)
			n.ptr[i] += ptr[i];
	}
	else
	{
		n = wielomian<T>(*this);
		for (int i = 0; i < a.lenght; i++)
			n.ptr[i] += a.ptr[i];
	}
	return n;
}
template <class T>
wielomian<T>& wielomian<T>::operator = (const wielomian<T>& x)
{
	delete[] ptr;
	lenght = x.lenght;
	ptr = new T[x.lenght];
	memcpy(ptr, x.ptr, lenght * sizeof(int));

	return *this;
}

template <class T>
T wielomian<T>::operator [] (size_t i)
{
	return ptr[i];
}
template <class T>
ostream& operator << (ostream & o, const wielomian<T>& w)
{
	for (int i = w.lenght - 1; i >= 0; i--)
	{
		if (w.ptr[i] != 0)
			if (i == 0)
				if (w.lenght == 1)
					o << w.ptr[i];
				else if (w.ptr[i] > 0)
					o << "+" << w.ptr[i];
				else
					o << w.ptr[i];
			else if (i == 1)
				if (w.ptr[i] > 0)
					if (i == w.lenght - 1)
						o << "X";
					else if (w.ptr[i] == 1)
						o << "+X";
					else
						o << "+" << w.ptr[i] << "X";
				else
					if (w.ptr[i] == -1)
						o << "-X";
					else
						o << w.ptr[i] << "X";
			else if (i == w.lenght - 1)
				if (w.ptr[i] == 1)
					o << "X^" << i;
				else if (w.ptr[i] == -1)
					o << "-X^" << i;
				else
					o << w.ptr[i] << "X^" << i;
			else
				if (w.ptr[i] > 0)
					if (w.ptr[i] == 1)
						o << "+" << "X^" << i;
					else
						o << "+" << w.ptr[i] << "X^" << i;
				else
					if (w.ptr[i] == -1)
						o << "-X^" << i;
					else
						o << w.ptr[i] << "X^" << i;
	}
	return o;
}
template <class T>
bool wielomian<T>::operator==(const wielomian<T>& w)
{
	if (lenght != w.lenght)
		return false;
	for (int i = 0; i < lenght; i++)
	{
		if (ptr[i] != w.ptr[i])
			return false;
	}
	return true;
}
template <class T>
wielomian<T> wielomian<T>::operator * (const wielomian<T>& x)const
{

	wielomian<T> n;
	n.lenght = lenght + x.lenght - 1;
	n.ptr = new T[n.lenght];
	for (int i = 0; i < n.lenght; i++)
		n.ptr[i] = 0;

	for (int i = 0; i < lenght; i++)
	{
		for (int k = 0; k < x.lenght; k++)
		{
			n.ptr[i + k] += ptr[i] * x.ptr[k];
		}
	}

	return n;
}


template <class T>
wielomian<T> wielomian<T>::operator * (long double k)
{
	wielomian<T> z(*this);
	for (int i = 0; i < lenght; i++)
		z.ptr[i] *= k;
	return z;
}	

template<class T,class K>
wielomian<T> operator* (K z, const wielomian<T> &k)
{
	wielomian<T> f(k);
	for (int i = 0; i < k.lenght; i++)
		f.ptr[i] *= z;
	return f;
}

