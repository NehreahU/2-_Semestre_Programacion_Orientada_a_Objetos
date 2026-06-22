#include <gtest/gtest.h>
#include "../IMC.h"

TEST(IMCTest, CalcularIMC) {
    IMC imc;
    EXPECT_NEAR(imc.calcularIMC(70, 1.75), 22.86, 0.01);  // Prueba de cálculo de IMC
    EXPECT_NEAR(imc.calcularIMC(60, 1.60), 23.44, 0.01);  // Otro ejemplo de cálculo
}

TEST(IMCTest, EvaluarIMC) {
    IMC imc;
    EXPECT_EQ(imc.evaluarIMC(50, 1.75), "Por debajo del peso normal.");
    EXPECT_EQ(imc.evaluarIMC(70, 1.75), "Usted tiene un peso normal.");
    EXPECT_EQ(imc.evaluarIMC(85, 1.75), "Usted tiene sobrepeso.");
    EXPECT_EQ(imc.evaluarIMC(100, 1.75), "Usted tiene obesidad.");
}

// Función main para ejecutar todas las pruebas
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
