#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
	

        TEST_METHOD(TestFindSumOfMaxInOddColumns)
        {
            const int rowCount = 3;
            const int colCount = 5;
            int* a[rowCount];

            int row0[] = { 1, 3, 5, 7, 9 };
            int row1[] = { 2, 8, 6, 4, 10 };
            int row2[] = { 3, 1, 7, 8, 11 };
            a[0] = row0;
            a[1] = row1;
            a[2] = row2;

            int expectedSum = 8 + 8;
            int actualSum = 0;

            for (int j = 1; j < colCount; j += 2)
            {
                int max = a[0][j];
                for (int i = 0; i < rowCount; i++)
                {
                    if (a[i][j] > max)
                    {
                        max = a[i][j];
                    }
                }
                actualSum += max;
            }
            Assert::AreEqual(expectedSum, actualSum);

        }
    };
}
