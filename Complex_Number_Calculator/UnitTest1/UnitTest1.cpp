#include "pch.h"
#include "CppUnitTest.h"
#include "../../Project_Complex/Project_Complex/complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
#define complex complex<double>


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			complex x(12, 12);
			complex y(55, 1);
			complex z = x + y;

			Assert::AreEqual(67., z.getre());
			Assert::AreEqual(13., z.getim());

			z = z + 2;
			Assert::AreEqual(69., z.getre());

			z = 2 + z;
			Assert::AreEqual(71., z.getre());

			z += 2;
			Assert::AreEqual(73., z.getre());

			z += y;
			Assert::AreEqual(128., z.getre());
			Assert::AreEqual(14., z.getim());

			Assert::AreEqual(12., x.getre());
			Assert::AreEqual(12., x.getim());
			Assert::AreEqual(55., y.getre());
			Assert::AreEqual(1., y.getim());
		}
		TEST_METHOD(TestSubstract)
		{
			complex x(12, 12);
			complex y(55, 1);
			complex z = x - y;

			Assert::AreEqual(-43., z.getre());
			Assert::AreEqual(11., z.getim());

			z = z - 2;
			Assert::AreEqual(-45., z.getre());

			z = 2 - z;
			Assert::AreEqual(-47., z.getre());

			z -= 2;
			Assert::AreEqual(-49., z.getre());

			z -= y;
			Assert::AreEqual(-104., z.getre());
			Assert::AreEqual(10., z.getim());

			Assert::AreEqual(12., x.getre());
			Assert::AreEqual(12., x.getim());
			Assert::AreEqual(55., y.getre());
			Assert::AreEqual(1., y.getim());
		}
		TEST_METHOD(TestMultiply)
		{
			complex x(12, 12);
			complex y(55, 1);
			complex z = x * y;

			Assert::AreEqual(648., z.getre());
			Assert::AreEqual(672., z.getim());

			z = z * 2;
			Assert::AreEqual(1296., z.getre());
			Assert::AreEqual(1344., z.getim());

			z = 2 * z;
			Assert::AreEqual(2592., z.getre());
			Assert::AreEqual(2688., z.getim());

			z *= 2;
			Assert::AreEqual(5184., z.getre());
			Assert::AreEqual(5376., z.getim());

			z *= y;
			Assert::AreEqual(279744., z.getre());
			Assert::AreEqual(300864., z.getim());

			Assert::AreEqual(12., x.getre());
			Assert::AreEqual(12., x.getim());
			Assert::AreEqual(55., y.getre());
			Assert::AreEqual(1., y.getim());
		}
		TEST_METHOD(TestDivide)
		{
			complex x(600, 720);
			complex y(55, 5);
			complex z = x/y;

			Assert::AreEqual(12., z.getre());
			Assert::AreEqual(12., z.getim());

			z = z / 2;
			Assert::AreEqual(6., z.getre());
			Assert::AreEqual(6., z.getim());

			z = 2 / z;
			Assert::AreEqual(1./6., z.getre());
			Assert::AreEqual(-1./6., z.getim());

			z /= 2;
			Assert::AreEqual(1./12., z.getre());
			Assert::AreEqual(-1./12., z.getim());

			x /= y;
			Assert::AreEqual(12., x.getre());
			Assert::AreEqual(12., x.getim());

			Assert::AreEqual(55., y.getre());
			Assert::AreEqual(5., y.getim());
		}
		TEST_METHOD(TestString)
		{
			complex x("12+12i");

			Assert::AreEqual(12., x.getre());
			Assert::AreEqual(12., x.getim());

			complex y("i+3i-1+25-24i-0+16+0i");

			Assert::AreEqual(40., y.getre());
			Assert::AreEqual(-20., y.getim());

			complex z("-0+0-4.5i-1.0+25.9-0+0i+0i");

			Assert::AreEqual(24.9, z.getre());
			Assert::AreEqual(-4.5, z.getim());
		}
		TEST_METHOD(TestBool)
		{
			complex x(12, 12);
			complex y(55, 1);

			Assert::AreEqual(true, x == x);
			Assert::AreEqual(false, x == y);
			Assert::AreEqual(false, x != x);
			Assert::AreEqual(true, x != y);


		}
	};
}
