// Copyrigth 2018 <Copyright Mtonin>
/**
* @file contador.hpp
* @brief Arquivo com as funcoes que sao usadas para implementar as funcoes que contaram o numero de linhas. 
*/
#ifndef TRABALHO3_TDD_CONTA_LINHA_INCLUDE_CONTADOR_HPP_
#define TRABALHO3_TDD_CONTA_LINHA_INCLUDE_CONTADOR_HPP_
// includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

/**
*   @fn int abrir_arquivo(string nome_arq, ifstream& arq);
*   @brief Funcao que abri o arquivo de nome "nome_arq" e retorna em arq seu ponteiro
*   @param nome_arq -> String contendo o nome do arquivo
*   @param arq Representa o tipo stream que sera retornado
*   @return Retorna um se deu certo e zero caso de errado
*   @attention Assertivas entradas -- dado pelos clientes:
*   @pre nome_arq != NULL (correspondendo a um nome de arquivo)
*   @post arq != NULL, deve estar preparado para receber ponteiro, deve ser do tipo correto 
*   @attention Assertiva Saida - dado pelo Servidor:
*   @post se criado arq com sucesso - retorno 1
*   @post se deu erro - retorno 0
*/
int abrir_arquivo(string nome_arq, ifstream& arq);
/**
*   @fn int conta_total_linhas(ifstream& arq);
*   @brief Conta o numero total de linhas do arquivo 
*   @param arq Representa o tipo stream que sera usado
*   @return Retorna o total de linhas do arquivo em questao
*   @attention Assertivas entradas - dado pelos Clientes:
*   @pre arq != NULL e do tipo correto, referente ao arq atual
*   @attention Assertiva Saida - dado pelo Servidor:
*   @post Se deu erro retorna zero ou
*   @post Ou o numero de linhas totais
*/
int conta_total_linhas(ifstream& arq);
/**
*   @fn int conta_linhas_branco(ifstream& arq);
*   @brief Conta o numero total de linhas em branco
*   @param arq Representa o tipo stream que sera usado
*   @return Retorna o total de linhas em branco do arquivo em questao
*   @attention Assertivas entradas - pelos clientes :
*   @pre arq != NULL, referente ao arq atual, deve ser do mesmo tipo
*   @attention Assertiva Saida - pelo Servidor :
*   @post Se deu erro retorna zero ou
*   @post Ou o numero de linhas totais em branco
*/
int conta_linhas_branco(ifstream& arq);
/**
*   @fn int eh_vazio(const char *st);
*   @brief Dado uma linha verifica se eh vazia ou se nao eh
*   @param *st -> string que contem a linha toda 
*   @attention Assertivas entradas - pelos clientes:
*   @return 1: linha esta vazia "em branco" e 0: nao esta em branco
*   @pre st != NULL, a string deve existir
*   @attention Assertiva Saida - pelo Servidor:
*   @post Se so houver espaco ou tab retorna 1, ou
*   @post retorna 1 caso contrario
*/
int eh_vazio(const char *st);
/**
*   @fn int nao_eh_vazio_indice(const char *st);
*   @brief Dado uma linha verifica qual o primeiro char que nao eh nulo "" ou tab
*   @param *st -> string que contem a linha toda 
*   @return -1 caso nao seja encontrada, ou retorna o indice que foi encontrado algum char
*   @attention Assertivas entradas - pelos Clientes:
*   @pre st != NULL, a string deve existir e deve ser string
*   @attention Assertiva Saida - pelo Servidor:
*   @post retorna -1 caso nao tenha, ou
*   @post retorna o indice do primeiro elemento diferente de tab ou espaco
*/
int nao_eh_vazio_indice(const char *st);
/**
*   @fn int conta_comments(ifstream& arq);
*   @brief Conta o numero total de linhas que sao comentadas
*   @param arq Representa o tipo stream que sera usado
*   @return Retorna o total de linhas que foram comentadas do arquivo em questao
*   @attention Assertivas entradas - pelo Clientes:
*   @pre arq != NULL, referente ao arq atual, devendo ser do certo
*   @attention Assertiva Saida - pelo Servidor :
*   @post Se deu erro retorna zero ou
*   @post Ou o numero de linhas comentadas
*/
int conta_comments(ifstream& arq);
/**
*   @fn int conta_final(ifstream& arq);
*   @brief Calcula o numero de linhas realmente usadas
*   @param arq Representa o tipo stream que sera usado
*   @return Retorna o total de linhas realmente uteis
*   @attention Assertivas entradas - pelos clientes :
*   @pre arq != NULL, referente ao arq atual devendo ser do tipo certo
*   @attention Assertiva Saida - pelo Servidor:
*   @post Retorna total - comentada - branco
*/
int conta_final(ifstream& arq);

/**
*   @fn int fecha_arquivo((ifstream& arq);
*   @brief Fecha o arquivo
*   @param arq Representa o tipo stream que sera usado
*   @return 1- se conseguiu fechar e 0 se nao deu certo
*   @attention Assertivas entradas - pelos clientes :
*   @pre arq != NULL, referente ao arq atual
*   @attention Assertiva Saida - pelo Servidor :
*   @post 1 caso tenha fechado com sucesso. 
*/
int fecha_arquivo(ifstream& arq);
#endif  // TRABALHO3_TDD_CONTA_LINHA_INCLUDE_CONTADOR_HPP_
