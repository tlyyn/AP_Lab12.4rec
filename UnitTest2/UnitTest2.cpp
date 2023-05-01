#include "../AP_Lab12.4rec/Source.cpp" // assuming the given code is in a file named "code.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListUnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(test_CountNegative)
        {
            Elem* L = NULL;
            insert(L, 1);
            insert(L, -2);
            insert(L, 3);
            insert(L, -4);
            insert(L, 5);
            int count = CountNegative(L, L);
            Assert::AreEqual(count, 2);
        }
    };
}