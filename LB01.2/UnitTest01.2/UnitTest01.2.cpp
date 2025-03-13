#include "pch.h"
#include "CppUnitTest.h"
#include "../LB01.2/matrix.h"
#include "../LB01.2/matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrix
{
	TEST_CLASS(UnitTestMatrix)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			Matrix matrix(2, 3);
			Assert::AreEqual(matrix.getStatus(), 0);  // ѕерев≥р€Їмо, чи створилась матриц€ без помилок
		}

		TEST_METHOD(GetElementTest)
		{
			Matrix matrix(2, 2);
			matrix.setElement(0, 0, 5);
			Assert::AreEqual(matrix.getElement(0, 0), 5);
		}

		TEST_METHOD(OutOfBoundsTest)
		{
			Matrix matrix(2, 2);
			Assert::AreEqual(matrix.getElement(5, 5), 2);  // ћаЇ повернути 2 - вих≥д за меж≥
		}

		TEST_METHOD(MultiplyTest)
		{
			Matrix matrix(2, 2);
			matrix.setElement(0, 0, 2);
			matrix.setElement(0, 1, 3);
			matrix.setElement(1, 0, 4);
			matrix.setElement(1, 1, 5);

			matrix.multiply(2);

			Assert::AreEqual(matrix.getElement(0, 0), 4);
			Assert::AreEqual(matrix.getElement(0, 1), 6);
			Assert::AreEqual(matrix.getElement(1, 0), 8);
			Assert::AreEqual(matrix.getElement(1, 1), 10);
		}

		TEST_METHOD(SetElementTest)
		{
			Matrix matrix(3, 3);
			matrix.setElement(1, 1, 10);
			Assert::AreEqual(matrix.getElement(1, 1), 10);
		}
	};
}
