#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct planta {
    string nomePopular;
    string nomeCientifico;
    int nCotiledones;
    int nPetalas;
    char classe; //M (monocotiletonea) ou D (dicotiledonea)
};

int main (){
    ifstream arquivo("arquivo.csv");
    int tam = 40;
    string linha="";
    planta *plantas = new planta[tam];
    const char delim = ','; //delimitador de campos 

    //verifica se o arquivo existe
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    getline(arquivo, linha); // ler e ignorar a primeira linha do arquivo (cabeçalho)

    //ler dados e armazenar no vetor:
    for (int i = 0; i < tam; i++) {
        if (getline(arquivo, linha)) {
            stringstream input(linha);

            getline(input, plantas[i].nomePopular, delim);
            getline(input, plantas[i].nomeCientifico, delim);
            input >> plantas[i].nCotiledones;
            input.ignore(); // ignorar o delimitador
            input >> plantas[i].nPetalas;
            input.ignore(); 
            input >> plantas[i].classe;
        } else {
            cout << "Erro ao ler dados ou fim do arquivo atingido." << endl;
            break;
        }
    }
    	
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


    delete [] plantas;
    return;
}

//apenas imprimir menu
void menu() {
    cout << "Menu de Opcoes:" << endl;
    cout << "1 - Inserir novo elemento" << endl;
    cout << "2 - Remover um elemento" << endl;
    cout << "3 - Buscar um registro" << endl;
    cout << "4 - Imprimir arquivo" << endl;
    cout << "5 - Ordenar dados" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opcao: ";
}