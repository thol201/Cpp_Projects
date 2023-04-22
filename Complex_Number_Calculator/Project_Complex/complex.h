#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class complex
{
private:
	T re;
	T im;
public:
	complex();
	complex(T, T);
	friend ostream& operator << <>(ostream& o, const complex& x);
	friend istream& operator << (istream& o, complex& x);
	T getre();
	T getim();
	complex& operator = (const complex&);
	complex(string);
	complex(const complex&);
	~complex();

	// dodawanie
	complex operator + (T);
	complex operator + (const complex&) const;
	template<typename T, typename K> friend complex<T> operator + (K, const complex<T>&);
	complex operator += (T);
	complex operator += (const complex&);

	// odejmowanie
	complex operator - (T);
	complex operator - (const complex&) const;
	template<typename T, typename K> friend complex<T> operator - (K, const complex<T>&);
	complex operator -= (T);
	complex operator -= (const complex&);

	// mnozenie
	complex operator * (T);
	complex operator * (const complex&) const;
	template<typename T, typename K> friend complex<T> operator * (K, const complex<T> &x);
	complex operator *= (T);
	complex operator *= (const complex&);

	// dzielenie
	complex operator / (T);
	complex operator / (const complex&) const;
	template<class T, class K> friend complex<T> operator / (K, const complex<T>&);
	complex operator /= (T);
	complex operator /= (const complex&);

	// arytmetyczne
	bool operator == (const complex);
	bool operator != (const complex);

};

template <class T>
complex<T>::complex()
{
	re = 0;
	im = 0;
}


template <class T>
complex<T>::complex(T x, T y)
{
	re = x;
	im = y;
}

template<class T> 
T complex<T>::getre()
{
	return re;
}

template<class T>
T complex<T>::getim()
{
	return im;
}

template <class T>
complex<T>& complex<T>::operator=(const complex& x)
{
	re = x.re;
	im = x.im;
	return *this;
}

template <class T>
inline complex<T>::complex(string txt)
{
	string tmp="";
	re = 0; im = 0;
	tmp += txt[0];
	for (int i = 1; i < txt.length(); i++)
	{
		while (txt[i]&&txt[i] != '+' && txt[i] != '-')
		{
			tmp += txt[i];
			i++;
		}
		if (tmp.find('i') != string::npos)
		{
			if (!tmp[1])
				im += 1;
			else if ((tmp[0] == '+') && tmp[1] == 'i')
				im += 1;
			else if ((tmp[0] == '-') && tmp[1] == 'i')
				im -= 1;
			else
			im += stold(tmp);
			tmp = "";
		}
		else
		{
			re += stold(tmp);
			tmp = "";
		}
		tmp += txt[i];
	}


}

template <class T>
complex<T>::complex(const complex<T>& x)
{
	re = x.re;
	im = x.im;
}

template<class T>
complex<T>::~complex()
{

}


template <class T>
ostream& operator << (ostream& o, const complex<T>& x)
{
	if(x.re)
	o << x.re;
	if (x.im > 0)
	{
		if (x.re)
			o << "+" << x.im<<"i";
		else
			o << x.im<<"i";
	}
	else if(x.im<0)
		o << x.im<<"i";
	return o;
}

template <class T>
istream& operator >> (istream& o, complex<T>& x)
{
	string k;
	o >> k;
	complex<T> z(k);
	x = k;
	return o;
}

// dodawanie

template <class T>
complex<T> complex<T>::operator+(T x)
{
	complex<T> n;
	n.re = re+x;
	n.im = im;
	return n;
}

template <class T>
complex<T> complex<T>::operator+(const complex& x)const
{
	complex<T> n;
	n.re = re + x.re;
	n.im = im + x.im;
	return n;
}

template<class T, class K>
complex<T> operator + (K val, const complex<T>& x)
{
	complex<T> n;
	n.re = x.re + val;
	n.im = x.im;
	return n;
}

template <class T>
complex<T> complex<T>::operator+=(T x)
{
	re += x;
	return *this;
}

template <class T>
complex<T> complex<T>::operator+=(const complex& x)
{
	re += x.re;
	im += x.im;
	return *this;
}

// odejmowanie

template <class T>
complex<T> complex<T>::operator-(T x)
{
	complex<T> n;
	n.re = re - x;
	n.im = im;
	return n;
}

template <class T>
complex<T> complex<T>::operator-(const complex& x)const
{
	complex<T> n;
	n.re = re - x.re;
	n.im = im - x.im;
	return n;
}

template<class T, class K>
complex<T> operator - (K val, const complex<T>& x)
{
	complex<T> n;
	n.re = x.re - val;
	n.im = x.im;
	return n;
}

template <class T>
complex<T> complex<T>::operator-=(T x)
{
	re -= x;
	return *this;
}

template <class T>
complex<T> complex<T>::operator-=(const complex& x)
{
	re -= x.re;
	im -= x.im;
	return *this;
}


// mnozenie

template <class T>
complex<T> complex<T>::operator*(T x)
{
	complex<T> n;
	n.re = re * x;
	n.im = im * x;
	return n;
}

template<class T>
complex<T> complex<T>::operator * (const complex<T>& x)const
{
	complex<T> n;
	n.re = re * x.re - im * x.im;
	n.im = re * x.im + im * x.re;
	return n;
}

template <class T,typename K>
complex<T> operator * (K val, const complex<T> &x)
{
	complex<T> n;
	n.re = x.re * val;
	n.im = x.im * val;
	return n;
}

template <class T>
complex<T> complex<T>::operator*=(T x)
{
	re *= x;
	im *= x;
	return *this;
}

template <class T>
complex<T> complex<T>::operator*=(const complex& x)
{
	T tmp;
	tmp = (re * x.re) - (im * x.im);
	im = (re * x.im) + (im * x.re);
	re = tmp;
	return *this;
}

// dzielenie

template <class T>
complex<T> complex<T>::operator/(T x)
{
	complex<T> n;
	
	if (x == 0)
	{
		cout << "division by 0" << endl;
		return n;
	}
		n.re = re / x;
		n.im = im / x;
	
	
	return n;
}

template <class T>
complex<T> complex<T>::operator/(const complex& x)const
{
	complex<T> n;
	if (x.re == 0 || x.im == 0)
	{
		cout << "division by 0" << endl;
		return n;
	}
	n.re = (re * x.re + im * x.im) / (x.re * x.re + x.im * x.im);
	n.im = (im * x.re - re * x.im) / (x.re * x.re + x.im * x.im);
	return n;
}

template<class T, class K>
complex<T> operator / (K val, const complex<T>& x)
{
	complex<T> n,v;
	if (val == 0||x.im==0||x.re==0)
	{
		cout << "division by 0" << endl;
		return n;
	}
	n.re = val;
	v.re = (n.re * x.re + n.im * x.im) / (x.re * x.re + x.im * x.im);
	v.im = (n.im * x.re - n.re * x.im) / (x.re * x.re + x.im * x.im);
	return v;
}

template <class T>
complex<T> complex<T>::operator/=(T x)
{
	complex<T> n;
	if (x == 0)
	{
		cout << "division by 0" << endl;
		return n;
	}
	re /= x;
	im /= x;
	return *this;
}

template <class T>
complex<T> complex<T>::operator/=(const complex& x)
{
	complex<T> n;
	T tmp; 
	if (x.im == 0 || x.re == 0)
	{
		cout << "division by 0" << endl;
		return n;
	}
	tmp = (re * x.re + im * x.im) / (x.re * x.re + x.im * x.im);
	im = (im * x.re - re * x.im) / (x.re * x.re + x.im * x.im);
	re = tmp;
	return *this;
}

// operatory

template <class T>
bool complex<T>::operator==(const complex x)
{
	if (re == x.re && im == x.im)
		return true;
	else return false;
}

template <class T>
bool complex<T>::operator!=(const complex x)
{
	if (re == x.re && im == x.im)
		return false;
	else return true;
}
