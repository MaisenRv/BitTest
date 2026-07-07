#pragma once

#include <vector>
#include <BitTest/TestCase.hpp>

namespace BitTest{
    struct TestRegistry{
        private:
            inline static std::vector<TestCase> tests{};
        public:
            static int addTest(TestCase test){ 
                tests.push_back(test);
                return 0;
            }

            static const std::vector<TestCase>& getTests() { return tests; }
    };
}