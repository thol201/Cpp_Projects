#include "pch.h"
#include "../ConsoleApplication3/wielomian.h"
#include "../ConsoleApplication3/functions.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#define wielomian wielomian<int>
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestOperatorPlus)
		{
			wielomian x("X+X^4");
			wielomian y("1-X-12X^2+22X^4-12X^8");
			wielomian z=x+y;

			int* wynik = new int[9]{ 1,0,-12,0,23,0,0,0,-12 };

			for(int i=0;i<z.get_lenght();i++)
			Assert::AreEqual(wynik[i],z.get_ptr()[i]);
		}
		TEST_METHOD(TestOperatorMultiply)
		{
			int* t1 = new int[4]{ 1, 2, 4, 5 };
			int* t2 = new int[4]{ 1, 2, 4, 5 };
			int* wynik = new int[7]{ 1,4,12,26,36,40,25 };

			wielomian x(4, t1);
			wielomian y(4, t2);
			wielomian z = x * y;

			for (int i = 0; i < z.get_lenght(); i++)
				Assert::AreEqual(wynik[i], z.get_ptr()[i]);
		}
		TEST_METHOD(TestConstructorString)
		{
			string* test_strs = new string[11] {"1","-1","X","-X","X^2","-X^2","-12X^4-5X^2-2X-5",
				"12X^4+5X^2+2X+5","12X^4-5X^2+2X-5","-1+44X^7-22X^2+X+12X^8","5+12X-5X^6-5+2X+22X^6-55X-5" };
			for(int i=0;i<11;i++)
			if (test_string(test_strs[i]) == false)
				Assert::Fail();

			wielomian x1(test_strs[0]); // wielomian podstawa 0 dodatni "1"
			int* wynik1 = new int[1]{ 1 };
			for (int i = 0; i < x1.get_lenght(); i++)
				Assert::AreEqual(wynik1[i],x1.get_ptr()[i]);
			
			wielomian x2(test_strs[1]);// wielomian podstawa 0 ujemny "-1"
			int* wynik2 = new int[1]{ -1 };
			for (int i = 0; i < x2.get_lenght(); i++)
				Assert::AreEqual(wynik2[i], x2.get_ptr()[i]);
			
			wielomian x3(test_strs[2]);// wielomian podstawa 1 dodatni "X"
			int* wynik3 = new int[2]{ 0,1 };
			for (int i = 0; i < x3.get_lenght(); i++)
				Assert::AreEqual(wynik3[i], x3.get_ptr()[i]);
			
			wielomian x4(test_strs[3]);// wielomian podstawa 1 ujemny "-X"
			int* wynik4 = new int[2]{ 0,-1 };
			for (int i = 0; i < x4.get_lenght(); i++)
				Assert::AreEqual(wynik4[i], x4.get_ptr()[i]);
			
			wielomian x5(test_strs[4]);// wielomian podstawa 2 dodatni "X^2"
			int* wynik5 = new int[3]{ 0,0,1 };
			for (int i = 0; i < x5.get_lenght(); i++)
				Assert::AreEqual(wynik5[i], x5.get_ptr()[i]);

			wielomian x6(test_strs[5]);// wielomian podstawa 2 ujemny "-X^2"
			int* wynik6 = new int[3]{ 0,0,-1 };
			for (int i = 0; i < x6.get_lenght(); i++)
				Assert::AreEqual(wynik6[i], x6.get_ptr()[i]);

			wielomian x7(test_strs[6]);// wielomian poprawnie zapisany ujemny "-12X^4-5X^2-2X-5"
			int* wynik7 = new int[5]{ -5,-2,-5,0,-12 };
			for (int i = 0; i < x7.get_lenght(); i++)
				Assert::AreEqual(wynik7[i], x7.get_ptr()[i]);

			wielomian x8(test_strs[7]);// wielomian poprawnie zapisany dodatni "12X^4+5X^2+2X+5"
			int* wynik8 = new int[5]{ 5,2,5,0,12 };
			for (int i = 0; i < x8.get_lenght(); i++)
				Assert::AreEqual(wynik8[i], x8.get_ptr()[i]);

			wielomian x9(test_strs[8]);// wielomian poprawnie zapisany mieszany "12X^4-5X^2+2X-5"
			int* wynik9 = new int[5]{ -5,2,-5,0,12 };
			for (int i = 0; i < x9.get_lenght(); i++)
				Assert::AreEqual(wynik9[i], x9.get_ptr()[i]);

			wielomian x10(test_strs[9]);// wielomian niepoprawnie zapisany v1 "-1+44X^7-22X^2+X+12X^8"
			int* wynik10 = new int[9]{ -1,1,-22,0,0,0,0,44,12 };
			for (int i = 0; i < x10.get_lenght(); i++)
				Assert::AreEqual(wynik10[i], x10.get_ptr()[i]);
				
			wielomian x11(test_strs[10]);// wielomian niepoprawnie zapisany v2 "5+12X-5X^6-5+2X+22X^6-55X-5"
			int* wynik11 = new int[7]{ -5,-41,0,0,0 ,0,17 };
			for (int i = 0; i < x11.get_lenght(); i++)
				Assert::AreEqual(wynik11[i], x11.get_ptr()[i]);
		}
	};
}
