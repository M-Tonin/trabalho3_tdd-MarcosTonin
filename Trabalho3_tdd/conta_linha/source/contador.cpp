// Copyrigth 2018 <Copyright Mtonin>
/**
* @file contador.cpp
* @brief Arquivo com as funcoes implementdas
*/
#include "../include/contador.hpp"

int abrir_arquivo(string nome_arq, ifstream& arq) {
    cout << nome_arq << endl;
    ifstream arq_aberto(nome_arq.c_str());
    if (!arq_aberto) {
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
    int num_lin = 0;
    if (!arq.is_open()) {
        cout << "Arquivo nao esta aberto"<< endl;
        return 0;
    }
    while (getline(arq, texto_linha)) {
        num_lin++;
        }
    // cout << "arqq " << num_lin << endl;
    return num_lin;
}

int conta_linhas_branco(ifstream& arq) {
    arq.clear();
    arq.seekg(0, ios::beg);
    string texto_linha;
    int linha_branco = 0;
    if (!arq.is_open()) {
        cout << "Arquivo nao esta aberto"<< endl;
        return 0;
    }
    int i = 0;
    while (getline(arq, texto_linha)) {
        if (texto_linha.length() == 0) {
            // cout << "Tamanho nulo =>";
            linha_branco++;
        } else if (eh_vazio(texto_linha.c_str())) {
            // cout << "Eh vazio => ";
            linha_branco++;
        }
        // cout << texto_linha << "tamanho = " << texto_linha.length() << endl;
        }
    // cout << linha_branco << endl;
    return linha_branco;
}

int eh_vazio(const char *st) {
      while (*st) {
    if (!isspace(*st) && *st != '\t')
      return 0;
    st++;
  }
  return 1;
    }
int nao_eh_vazio_indice(const char *st) {
    int indice = 0;
    while (*st) {
         if (!isspace(*st) && *st != '\t') {
            return indice;
            }
            st++;
            indice++;
         }
  return -1;
}



int conta_comments(ifstream& arq) {
    arq.clear();
    arq.seekg(0, ios::beg);
    string texto_linha;
    int linha_comments = 0;
    if (!arq.is_open()) {
        cout << "Arquivo nao esta aberto"<< endl;
        return 0;
    }
    while (getline(arq, texto_linha)) {
    int indice = nao_eh_vazio_indice(texto_linha.c_str());
    // cout << indice << endl;
    if (indice != -1) {
    // cout << texto_linha[indice]<< texto_linha[indice + 1] << endl;
    if (texto_linha[indice] == '/' && texto_linha[indice+1] == '/') {
       // cout << "Comentario detectado " << texto_linha <<endl;
        linha_comments++;
    }
    if (texto_linha[indice] == '/' && texto_linha[indice+1] == '*') {
        // cout << "Comentario detectado " << texto_linha <<endl;
        linha_comments++;
        while (getline(arq, texto_linha)) {
            indice = nao_eh_vazio_indice(texto_linha.c_str());
                if (indice != -1) {
                    if (!(texto_linha[indice+1] == '/' &&
                                                texto_linha[indice] == '*')) {
                        linha_comments++;
                         // cout << "Comentario detectado"<<texto_linha<<endl;
                    } else if (texto_linha[indice+1] == '/' &&
                                              texto_linha[indice] == '*') {
                        linha_comments++;
                        // cout << "Comentario detectado "<<texto_linha<<endl;
                        break;
                    }
                }
        }
    }
    }
    }
    // cout << "comentadods " <<linha_comments << endl;
    return linha_comments;
}

int conta_final(ifstream& arq) {
    arq.clear();
    arq.seekg(0, ios::beg);
    int val_total, val_branco, val_comment;
    val_total = conta_total_linhas(arq);
    val_branco = conta_linhas_branco(arq);
    val_comment = conta_comments(arq);
    cout << "Todas linhas contadas : " << val_total <<endl;
    cout << "Todas linhas em branco : " << val_branco <<endl;
    cout << "Todas linhas comentadas : " << val_comment <<endl;
    int total = val_total -(val_branco + val_comment);
    cout << "Total de linhas uteis : "  << total << endl;
}

int fecha_arquivo(ifstream& arq) {
  arq.close();
}
