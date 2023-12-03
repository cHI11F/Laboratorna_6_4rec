#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB6_4rec/LAB6_4rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
  TEST_CLASS(UnitTest1)
  {
  public:
    
        TEST_METHOD(productPositiveElements_PositiveNumbers) {
            double arr[] = { 1.0, 2.0, 3.0, 4.0 };
            Assert::AreEqual(productPositiveElements(arr, 4), 24.0);
        }

        TEST_METHOD(productPositiveElements_NegativeNumbers) {
            double arr[] = { -1.0, -2.0, -3.0, -4.0 };
            Assert::AreEqual(productPositiveElements(arr, 4), 1.0);
        }

        TEST_METHOD(productPositiveElements_MixedNumbers) {
            double arr[] = { -1.0, 2.0, -3.0, 4.0 };
            Assert::AreEqual(productPositiveElements(arr, 4), 8.0);
        }

        TEST_METHOD(sumElementsBeforeMinimum_NoMinimum) {
            double arr[] = { 1.0, 2.0, 3.0, 4.0 };
            Assert::AreEqual(sumElementsBeforeMinimum(arr, 4, 0), 10.0);
        }

        TEST_METHOD(sumElementsBeforeMinimum_MinimumAtStart) {
            double arr[] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
            Assert::AreEqual(sumElementsBeforeMinimum(arr, 5, 0), 0.0);
        }

        TEST_METHOD(sumElementsBeforeMinimum_MinimumAtEnd) {
            double arr[] = { 1.0, 2.0, 3.0, 4.0, 0.0 };
            Assert::AreEqual(sumElementsBeforeMinimum(arr, 5, 0), 10.0);
        }

        TEST_METHOD(orderEvenOddElements_EvenOddNumbers) {
            double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
            orderEvenOddElements(arr, 6);
            double expected[] = { 2.0, 4.0, 6.0, 1.0, 3.0, 5.0 };
            for (int i = 0; i < 6; i++) {
                Assert::AreEqual(arr[i], expected[i], 3);
            }
        }
  };
}