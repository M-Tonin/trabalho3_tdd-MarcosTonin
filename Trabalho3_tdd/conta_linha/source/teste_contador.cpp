// Copyrigth 2018 <Copyright Mtonin>
/**
* @file contador.cpp
* @brief Arquivo com os testes feitos no contador de arquivo.
*/
#include "../include/contador.hpp"

int main() {
ifstream t0, t1, t2, erro;
    cout << "------- Erros -----------\n\n" << endl;
    abrir_arquivo("xx.cpp",erro);
    conta_total_linhas(erro);
    conta_linhas_branco(erro);
    conta_comments(erro);
    cout << "------- Exemplo24Stack -----------\n\n" << endl;
    abrir_arquivo("Exemplo24Stack.cpp", t0);
    conta_total_linhas(t0);
    conta_linhas_branco(t0);
    conta_comments(t0);
    conta_final(t0);
    abrir_arquivo("Exemplo18Enum2.cpp", t1);
    cout << "------- Exemplo18Enum2 -----------\n\n" << endl;
    conta_total_linhas(t1);
    conta_linhas_branco(t1);
    conta_comments(t1);
    conta_final(t1);
    cout << "------- Exemplo17Friend -----------\n\n" << endl;
    abrir_arquivo("Exemplo17Friend.cpp", t2);
    conta_total_linhas(t2);
    conta_linhas_branco(t2);
    conta_comments(t2);
    conta_final(t2);
    fecha_arquivo(t0);
    fecha_arquivo(t1);
    fecha_arquivo(t2);
    return 0;
}
