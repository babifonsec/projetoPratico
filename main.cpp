#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

struct planta {
    string nomePopular;
    string nomeCientifico;
    int nCotiledones;
    int nPetalas;
    char classe; //M (monocotiletonea) ou D (dicotiledonea)
};

//apenas imprimir menu
void menu() {
    cout << "Menu de Opções:" << endl;
    cout << "1 - Inserir novo elemento" << endl;
    cout << "2 - Remover um elemento" << endl;
    cout << "3 - Buscar um registro" << endl;
    cout << "4 - Imprimir arquivo" << endl;
    cout << "5 - Ordenar dados" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opção: ";
}

//ler dados do arquivo e preencher o vetor
void lerDados(ifstream &arquivo, planta *&plantas, int &tam) {
    string linha;
    const char delim = ',';
    int i;
    
    for (i = 0; i < tam; i++) {
        if (getline(arquivo, linha)) {
            stringstream input(linha);
            getline(input, plantas[i].nomePopular, delim);
            getline(input, plantas[i].nomeCientifico, delim);
            input >> plantas[i].nCotiledones;
            input.ignore();
            input >> plantas[i].nPetalas;
            input.ignore(); 
            input >> plantas[i].classe;
        } else {
            cout << "Erro ao ler dados ou fim do arquivo atingido." << endl;
            break;
        }
    }
    i=tam;

}

//aumentar o tamanho do vetor
void aumentarVetor(planta *&plantas, int &tam) {
    int novoTam = tam + 10;
    planta *novoPlantas = new planta[novoTam];
    memcpy(novoPlantas, plantas, sizeof(planta) * tam);
    delete[] plantas;
    plantas = novoPlantas;
    tam = novoTam;
}

//imprimir vetor
void imprimirVetor(planta *plantas, int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Planta " << i + 1 << ": "
             << plantas[i].nomePopular << ", "
             << plantas[i].nomeCientifico << ", "
             << plantas[i].nCotiledones << ", "
             << plantas[i].nPetalas << ", "
             << plantas[i].classe << endl;
    }
}

int main (){
    ifstream arquivo("arquivo.csv");
    int tam = 40;
    string linha="";
    planta *plantas = new planta[tam];

    //verifica se o arquivo existe
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
    getline(arquivo, linha); // ler e ignorar a primeira linha do arquivo
    const char delim = ',';
    
    for (int i = 0; i < tam; i++) {
        if (getline(arquivo, linha)) {
            stringstream input(linha);
            getline(input, plantas[i].nomePopular, delim);
            getline(input, plantas[i].nomeCientifico, delim);
            input >> plantas[i].nCotiledones;
            input.ignore();
            input >> plantas[i].nPetalas;
            input.ignore(); 
            input >> plantas[i].classe;
        } else {
            cout << "Erro ao ler dados ou fim do arquivo atingido." << endl;
            break;
        }
    }

    // aumenta o vetor em +10 e continua preenchendo
    aumentarVetor(plantas, tam);
    lerDados(arquivo, plantas, tam);
    	
    int opc;
    do {
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            //chamada da funcao de inserir novo elemento
            break;
        case 2:
            //chamada da funcao de remover elemento
            break;
        case 3:
            //chamada buscar registro
        break;
        case 4:
            //chamada da funcao de imprimir arquivo
            break;
        case 5:
            //chamda da funcao ordenar dados;
            break;
        case 0:
            cout<<"Saindo..."<<endl;
            break;
        default:
            cout<<"Opção inválida"<<endl;
            break;
        }

    } while (opc!=0);

    imprimirVetor(plantas, tam);

    delete [] plantas;
    return 0;
}