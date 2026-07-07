
#include <iostream>
#include <BitTest/BitTest.hpp>

BIT_TEST_CASE(SumaCorrecta) {
        int resultado = 2 + 3;
        BIT_ASSERT(resultado == 5);
    }

// Test 2: Va a fallar a propósito para probar tu reporte de errores
BIT_TEST_CASE(SumaIncorrecta) {
    int resultado = 10 + 10;
    BIT_ASSERT(resultado == 42); // Esto va a fallar
}

int main(){
    BitTest::runAllTests();
    return 0;
}