#include <iostream>
#include <string>
#include "complex.h"

using namespace std;

#define complex complex<double>

int main()
{
	complex x = complex("i+3i-1+25-24i-0+16+0i");
	complex y = complex(55, 1);

	x = x / y;
	cout << x;
	return 0;
}