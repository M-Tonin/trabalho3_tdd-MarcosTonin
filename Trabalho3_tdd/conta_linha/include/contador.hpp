// Copyrigth 2018 <Copyright Mtonin>
/**
* @file contador.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes da pilha que foram solicitada no trabalho.
*/
#ifndef CONTADOR_HPP
#define CONTADOR_HPP
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

int abrir_arquivo(string nome_arq, ifstream& arq);
int conta_total_linhas(ifstream& arq);
int conta_linhas_branco(ifstream& arq);
int eh_vazio(const char *st);
int nao_eh_vazio_indice(const char *st);
int conta_comments(ifstream& arq);
int conta_final(ifstream& arq);
int fecha_arquivo(ifstream& arq);
#endif  // _HOME_MTONIN_DOCUMENTS_TRABALHO1_MARCOSTONIN_2_LISTA_INCLUDE_PILHA_H_