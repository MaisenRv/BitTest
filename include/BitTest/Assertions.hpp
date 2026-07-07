#pragma once
#include <iostream>
#include <BitTest/types/SessionState.hpp>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#define BIT_ASSERT(condition) BitTest::engine::evaluateAssert(#condition,condition,__FILE__,__LINE__)

namespace BitTest::engine{
    void evaluateAssert(const char *expr, bool conditionResult, const char *fileName, int line){
        if(conditionResult){
            types::getSessionState().addPassed();
            std::cout << GREEN << "\t[TEST PASSED]" << RESET << std::endl;
            return;
        }
        types::getSessionState().addFailed();
        std::cout << RED << "\t[TEST FAILED]" <<
            "\n\t[FILE]: " << fileName << 
            "\n\t[LINE]: " << line << 
            "\n\t[EXPRESION]:" << 
            "\n\t\t" << expr << RESET << std::endl;
    }
}