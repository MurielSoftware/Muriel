#include "stdafx.h"
#include "ObjectFactory.h"
#include "AssertUtils.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GlmlTest
{		
	TEST_CLASS(Mat3x3Test)
	{
	private:
		Mat3x3 m;
		Mat3x3 m1;
		Mat3x3 m2;
	public:
		TEST_METHOD_INITIALIZE(Initialize)
		{
			m = CreateMat3x3(1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f);
			m1 = CreateMat3x3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
			m2 = CreateMat3x3(9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
		}

		TEST_METHOD(TestMultipleByMat3x3)
		{
			Mat3x3 actual = m1 * m2;

			Mat3x3 expected = CreateMat3x3(30.0f, 24.0f, 18.0f, 84.0f, 69.0f, 54.0f, 138.0f, 114.0f, 90.0f);
			Assert::IsTrue(AreMatricesEqual(expected, actual));
		}

		TEST_METHOD(TestInvert)
		{			
			Mat3x3 actual = Mat3x3::INVERT(m);

			Mat3x3 expected = CreateMat3x3(1.0f, 0.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f);
			Assert::IsTrue(AreMatricesEqual(expected, actual));
		}
	};
}