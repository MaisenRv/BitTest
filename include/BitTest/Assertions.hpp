#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <BitTest/types/SessionState.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


#define BIT_FAIL(expr) BitTest::engine::fail(true,#expr,__FILE__,__LINE__)
#define BIT_PASS() BitTest::engine::pass()

// ASSERT
#define BIT_ASSERT(condition) BitTest::engine::evaluateAssert(#condition,condition,__FILE__,__LINE__)
#define BIT_ASSERT_EQ(expected, actual) BitTest::engine::evaluateAssertEquals<decltype(expected),decltype(actual)>(expected,actual,#expected,#actual,__FILE__,__LINE__)
#define BIT_ASSERT_TRUE(cond)  BitTest::engine::evaluateBoolean(true, cond, true, #cond, __FILE__, __LINE__)
#define BIT_ASSERT_FALSE(cond) BitTest::engine::evaluateBoolean(false, cond, true, #cond, __FILE__, __LINE__)
#define BIT_ASSERT_THROWS(expression) \
    try { \
        static_cast<void>(expression); \
        BitTest::engine::fail(true, #expression, __FILE__, __LINE__); \
    } catch (...) { BitTest::engine::pass(); }

// EXPECT
#define BIT_EXPECT(condition) BitTest::engine::evaluateExpect(#condition,condition,__FILE__,__LINE__)
#define BIT_EXPECT_EQ(expected, actual) BitTest::engine::evaluateExpectEquals<decltype(expected),decltype(actual)>(expected,actual,#expected,#actual,__FILE__,__LINE__)
#define BIT_EXPECT_TRUE(cond)  BitTest::engine::evaluateBoolean(true, cond, false, #cond, __FILE__, __LINE__)
#define BIT_EXPECT_FALSE(cond) BitTest::engine::evaluateBoolean(false, cond, false, #cond, __FILE__, __LINE__)
#define BIT_EXPECT_THROWS(expression) \
    try { \
        static_cast<void>(expression); \
        BitTest::engine::fail(false, #expression, __FILE__, __LINE__); \
    } catch (...) { BitTest::engine::pass(); }


namespace BitTest::engine{
    inline void fail(bool isFatal, const char *expr,const char *fileName, int line){
        types::getSessionState().addFailed();
        std::cout << (isFatal ? RED : YELLOW) << "\t[TEST FAILED]" <<
            "\n\t[FILE]: " << fileName << 
            "\n\t[LINE]: " << line << 
            "\n\t[EXPRESION]:" << 
            "\n\t\t" << expr << RESET << std::endl;
        if (isFatal) throw std::runtime_error("");
    }
    inline void pass(){
        types::getSessionState().addPassed();
        std::cout << GREEN << "\t[TEST PASSED]" << RESET << std::endl;
    }

    inline void evaluateBoolean(bool expected, bool actual, bool isFatal, const char* strResult, const char *fileName, int line) {
        if (actual == expected) {
            BitTest::engine::pass();
            return;
        }
        std::stringstream ss;
        ss << "Expected [" << strResult << "] to be " << (expected ? "TRUE":"FALSE" ) << ", but it evaluated to " << (actual ? "TRUE":"FALSE" );
        BitTest::engine::fail(isFatal, ss.str().c_str(), fileName, line);
    }

    inline void evaluateAssert(const char *expr, bool conditionResult, const char *fileName, int line){
        if(conditionResult){
            BitTest::engine::pass();
            return;
        }
        BitTest::engine::fail(true,expr,fileName,line);
    }
    template <typename T1, typename T2>
    inline void evaluateAssertEquals(T1 expected, T2 actual, const char* strExpected, const char* strActual, const char *fileName, int line){
        if (actual == expected) {
            BitTest::engine::pass();
            return;
        }
        std::stringstream ss;
        ss << strExpected << " == " << strActual << "| Expected " << expected << ", it was obtained " << actual;
        BitTest::engine::fail(true, ss.str().c_str(), fileName, line);
    }
    
    inline void evaluateExpect(const char *expr, bool conditionResult, const char *fileName, int line){
        if(conditionResult){
            BitTest::engine::pass();
            return;
        }
        BitTest::engine::fail(false,expr,fileName,line);
    }

    template <typename T1, typename T2>
    inline void evaluateExpectEquals(T1 expected, T2 actual, const char* strExpected, const char* strActual, const char *fileName, int line){
        if (actual == expected) {
            BitTest::engine::pass();
            return;
        }
        std::stringstream ss;
        ss << strExpected << " == " << strActual << "| Expected " << expected << ", it was obtained " << actual;
        BitTest::engine::fail(false, ss.str().c_str(), fileName, line);
    }
}
