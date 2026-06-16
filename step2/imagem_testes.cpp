#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "imageGenerator.cpp"

TEST_CASE("Testa a criação de uma imagem com largura e altura específicas") {
    Image img(100, 50);
    CHECK(img.getColumns() == 100);
    CHECK(img.getLines() == 50);
}

TEST_CASE("Testa a modificação e acesso aos pixels da imagem") {
    Image img(10, 10);
    Pixel vermelho = {255, 0, 0};
    img.setPixel(vermelho, 5, 5);

    CHECK(img.checkPixel(5, 5).getRed() == 255);
    CHECK(img.checkPixel(5, 5).getGreen() == 0);
    CHECK(img.checkPixel(5, 5).getBlue() == 0);
}

TEST_CASE("Testa a leitura de uma imagem em formato PPM") {
    Image img(0, 0);
    img.setImage("imagem.ppm");
    CHECK(img.getColumns() == 3);
    CHECK(img.getLines() == 2);

    CHECK(img.checkPixel(0, 0).getRed() == 255);
    CHECK(img.checkPixel(0, 0).getGreen() == 0);
    CHECK(img.checkPixel(0, 0).getBlue() == 0);

    CHECK(img.checkPixel(1, 0).getRed() == 0);
    CHECK(img.checkPixel(1, 0).getGreen() == 255);
    CHECK(img.checkPixel(1, 0).getBlue() == 0);

    CHECK(img.checkPixel(0, 1).getRed() == 255);
    CHECK(img.checkPixel(0, 1).getGreen() == 255);
    CHECK(img.checkPixel(0, 1).getBlue() == 0);

    CHECK(img.checkPixel(1, 1).getRed() == 255);
    CHECK(img.checkPixel(1, 1).getGreen() == 255);
    CHECK(img.checkPixel(1, 1).getBlue() == 255);
}

TEST_CASE("Testa a salvamento da imagem em formato PPM") {
    Image img(2, 2);
    img.setPixel({255, 0, 0}, 0, 0);
    img.setPixel({0, 255, 0}, 1, 0);
    img.setPixel({0, 0, 255}, 0, 1);
    img.setPixel({255, 255, 0}, 1, 1);
    //img(0, 0) = {255, 0, 0};   // vermelho
    //img(1, 0) = {0, 255, 0};   // verde
    //img(0, 1) = {0, 0, 255};   // azul
    //img(1, 1) = {255, 255, 0}; // amarelo

    img.createImage("teste.ppm");

    // Verifica se o arquivo foi criado corretamente
    std::ifstream arquivo("teste.ppm");
    CHECK(arquivo.is_open());

    std::string conteudo;
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "P3");
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "2 2");
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "255");

    std::getline(arquivo, conteudo);
    CHECK(conteudo == "255 0 0");
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "0 255 0");
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "0 0 255");
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "255 255 0");

    arquivo.close();
}