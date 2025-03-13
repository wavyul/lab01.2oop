#include "pch.h"
#include "CppUnitTest.h" 
#include "../LB.01.3/longLong.h"
#include "../LB.01.3/longLong.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLongLong
{
	TEST_CLASS(UnitTestLongLong)
	{
	public:

		TEST_METHOD(TestAddition)
		{
			LongLong num1(1, 2000000000);
			LongLong num2(2, 1000000000);
			LongLong expectedSum(4, 3000000000); // Очікуване значення

			LongLong result = num1 + num2;
	
		}

		TEST_METHOD(TestMultiplication)
		{
			LongLong num1(2, 1000000000);
			LongLong num2(3, 2000000000);
			LongLong expectedProduct(6, 2000000000); // Очікуване значення

			LongLong result = num1 * num2;
			
		}

		TEST_METHOD(TestComparison)
		{
			LongLong num1(1, 2000000000);
			LongLong num2(2, 1000000000);

			Assert::IsTrue(num1 < num2);
			Assert::IsFalse(num1 > num2);
			Assert::IsFalse(num1 >= num2);
		}
	};
}
