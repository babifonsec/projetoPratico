#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Planta {
		int id;
		string nome;
		string nomeCientifico;	
		int nCotiledones;
		int nPetalas;
		char classe;
};

Planta *alocacao(Planta *vet, int &tam) {
    int novoTam = tam + 5;
    Planta *novo = new Planta[novoTam];
    for (int i = 0; i < tam; ++i) {
        novo[i] = vet[i];
    }
    delete[] vet;
    tam = novoTam;  // Atualiza tam para novo tamanho
    return novo;
}


Planta *importarCSV(Planta *vet, int &quant, int &tam){
	string lixo;
	ifstream arquivo ("arquivo.csv");
	int i=0;
	quant=0;
	
	getline(arquivo,lixo);
	while (arquivo >> vet[i].id){
	arquivo>>lixo;
	arquivo >> vet[i].nome;
	arquivo>>lixo;
	getline(arquivo, vet[i].nomeCientifico, ',');
	arquivo>>lixo;
	arquivo>>vet[i].nCotiledones;
	arquivo>>lixo;
	arquivo>>vet[i].nPetalas;
	arquivo>>lixo;
	arquivo>>vet[i].classe;
	i++;
	quant++;
	if(tam==i){
		vet=alocacao(vet,tam);
		}
	}
	arquivo.close();
	cout << "Dados importados com sucesso" << endl;
    return vet;
	}

//imprimir vetor
void imprimirVetor(Planta vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Planta " << i + 1 << ": "
             << vet[i].nome << ", "
             << vet[i].nomeCientifico << ", "
             << vet[i].nCotiledones << ", "
             << vet[i].nPetalas << ", "
             << vet[i].classe << endl;
    }
}

void menu (){
		cout<< "Escolha uma opção abaixo:" << endl;
        cout << "Opção 1: Importar dados CSV" << endl;
        cout << "Opção 2: Busca" << endl;
        cout << "Opção 3: Inserir dados" << endl;
        cout << "Opção 4: Listar dados" << endl;
        cout << "Opção 5: Ordenar" << endl;
        cout << "Opção 6: Remover" << endl;
        cout << "Opção 7: Imprimir intervalo de elementos" << endl;
        cout << "Opção 0: Sair" << endl;	
}


int main (){
	int tam = 40, quant=0, opc;
	Planta *vet = new Planta [tam];
	
	do{
		menu();
		cin>>opc;
		
		switch(opc){
			case 1: 
			importarCSV(vet,quant,tam);
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			imprimirVetor(vet,tam);
			break;
			
		}
	}while(opc!=0);
	
delete [] vet;
return 0;
}	
