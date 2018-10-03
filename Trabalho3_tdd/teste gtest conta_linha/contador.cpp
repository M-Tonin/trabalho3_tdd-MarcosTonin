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
	int conta_total_linhas(ifstream& arq) {
    string texto_linha;
    int num_lin=0;
    if(!arq.is_open()) {
    	cout << "Arquivo nao esta aberto"<< endl;
    	return 0;
	}	
	while(getline(arq,texto_linha)) {
		num_lin++;
		}
	//cout << "arqq " << num_lin << endl;
	return num_lin;
}

int conta_linhas_branco(ifstream& arq){
    arq.clear();
    arq.seekg(0, ios::beg);
    string texto_linha;
    int linha_branco=0;
    if(!arq.is_open()) {
    	cout << "Arquivo nao esta aberto"<< endl;
    	return 0;
	}	
	int i=0;
	while(getline(arq,texto_linha)) {
		if(texto_linha.length() == 0){
			//cout << "Tamanho nulo =>";
			linha_branco++;
		}
		else if(eh_vazio(texto_linha.c_str())) {
			//cout << "Eh vazio => ";
			linha_branco++;
		}
		//cout << texto_linha << "tamanho = " << texto_linha.length() << endl;
		}
	//cout << linha_branco << endl;	
	return linha_branco;	
	
}

int eh_vazio(const char *st) {
	  while (*st) {
    if (!isspace(*st) && *st != '/t')
      return 0;
    st++;
  }
  return 1;
	}