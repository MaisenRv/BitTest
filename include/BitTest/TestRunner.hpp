#pragma once
#include <BitTest/TestRegistry.hpp>
#include <BitTest/Assertions.hpp>
#include <iostream>

namespace BitTest{
    inline void runAllTests(){
        for (auto& test: TestRegistry::getTests()){
            std::cout << BLUE << "[TEST NAME]: " << test.name << RESET << std::endl;
            try{
                test.funct();
            } catch(const std::runtime_error& e){}
        }
        std::cout << GREEN <<"\n Test passed: " << types::getSessionState().getPassed() << RESET << std::endl;
        std::cout << RED <<" Test failed: " << types::getSessionState().getFailed() << RESET << std::endl;
    }
}
