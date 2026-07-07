#pragma once

#include <string>
#include <functional>

#define BIT_TEST_CASE(nameTest) \
    void nameTest();\
        inline int _##nameTest = BitTest::TestRegistry::addTest({#nameTest, nameTest});\
    void nameTest() \

namespace BitTest{
    struct TestCase{
        std::string name;
        std::function<void()> funct;
    };
}