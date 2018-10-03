// Copyrigth 2018 <Copyright Mtonin>
/**
* @file contador.cpp
* @brief Arquivo com as funcoes implementdas
*/
#include "../include/contador.hpp"

int abrir_arquivo(string nome_arq,ifstream& arq) {
	cout << nome_arq << endl;
    ifstream arq_aberto(nome_arq.c_str());
    if(!arq_aberto) {
    	cout << "Error ao abrir arquivo! Arquivo nao existe. " << endl;
    	return 0;
	} else {
		cout << "Arquivo aberto " << endl;
		arq.open(nome_arq.c_str());
		return 1;
	}	 
	
}