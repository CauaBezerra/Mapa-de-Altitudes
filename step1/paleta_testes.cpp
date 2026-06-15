#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "colorPalet.cpp"


TEST_CASE("Testa a criação de uma paleta padrão (sem nenhuma cor)") {
    Palet paleta;
    CHECK(paleta.pixelNum() == 0);
}

TEST_CASE("Testa a adição de cores uma paleta vazia") {
    Palet paleta;
    paleta.addPixel(Pixel {255, 0, 0});

    CHECK(paleta.pixelNum() == 1);
    CHECK(paleta.getPixel(0).getRed() == 255);
    CHECK(paleta.getPixel(0).getGreen() == 0);
    CHECK(paleta.getPixel(0).getBlue() == 0);
}

TEST_CASE("Testa a obtenção de uma cor com índice inválido") {
    Palet paleta;
    paleta.addPixel(Pixel {100, 150, 200});

    Pixel corInvalida = paleta.getPixel(5); // índice inválido (maior que o tamanho)

    // deve retornar uma cor padrão (preto)
    CHECK(corInvalida.getRed() == 0);
    CHECK(corInvalida.getGreen() == 0);
    CHECK(corInvalida.getBlue() == 0);
}

TEST_CASE("Testa a criação de uma paleta a partir de um arquivo válido") {
    // o arquivo "cores.hex" foi fornecido junto com o projeto.
    // verifique se ele se encontra na mesma pasta que o executável do teste.
    Palet paleta("./cores.hex");

    // verifica se as cores foram carregadas corretamente
    CHECK(paleta.pixelNum() == 30);
    CHECK(paleta.getPixel(0).getRed() == 113);
    CHECK(paleta.getPixel(0).getGreen() == 171);
    CHECK(paleta.getPixel(0).getBlue() == 216);

    CHECK(paleta.getPixel(1).getRed() == 121);
    CHECK(paleta.getPixel(1).getGreen() == 178);
    CHECK(paleta.getPixel(1).getBlue() == 222);
    
    //... outras cores

    CHECK(paleta.getPixel(29).getRed() == 255);
    CHECK(paleta.getPixel(29).getGreen() == 255);
    CHECK(paleta.getPixel(29).getBlue() == 255);
}

TEST_CASE("Testa a criação de uma paleta a partir de um arquivo inexistente") {
    Palet paleta("arquivo_inexistente.txt");

    // a paleta deve estar vazia
    CHECK(paleta.pixelNum() == 0);
}