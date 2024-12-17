#include <fstream>
#include <iostream>

using namespace std;

struct Carros {
    int id;
    string nome;
    int ano;
    int potencia;
    string classe;
    bool removido;
};

Carros *alocacao(Carros *vet, int &tam) {
    Carros *novo = new Carros[tam + 1];
    for (int i = 0; i < tam; ++i) {
        novo[i] = vet[i];
    }
    tam++;
    delete[] vet;
    vet = novo;
    return vet;
}

void buscaNome(Carros vet[], int quant) {
    string buscarNome;
    cout << "Insira o nome do carro: ";
    getline(cin, buscarNome);
    bool naoAchou = true;
    for (int i = 0; i < quant; i++) {
        if (!vet[i].removido && buscarNome == vet[i].nome) {
            cout << "Identificador: " << vet[i].id << endl;
            cout << "Nome: " << vet[i].nome << endl;
            cout << "Ano: " << vet[i].ano << endl;
            cout << "Potência em cv: " << vet[i].potencia << endl;
            cout << "Classe: " << vet[i].classe << endl;
            naoAchou = false;
        }
    }
    if (naoAchou) {
        cout << "Carro não encontrado!" << endl;
    }
}

void buscaAno(Carros vet[], int quant) {
    int buscarAno;
    cout << "Insira o ano do carro: ";
    cin >> buscarAno;
    cin.ignore();
    bool naoAchou = true;
    for (int i = 0; i < quant; i++) {
        if (!vet[i].removido && buscarAno == vet[i].ano) {
            cout << "Identificador: " << vet[i].id << endl;
            cout << "Nome: " << vet[i].nome << endl;
            cout << "Ano: " << vet[i].ano << endl;
            cout << "Potência em cv: " << vet[i].potencia << endl;
            cout << "Classe: " << vet[i].classe << endl;
            naoAchou = false;
        }
    }
    if (naoAchou) {
        cout << "Carro não encontrado!" << endl;
    }
}

Carros *lerCSV(Carros *vet, int &tam, int &quant) {
    char lixo;
    ifstream arq("Grupo_57_Porsche.csv");
    int i = 0;
    quant = 0;
    while (arq >> vet[i].id) {
        arq >> lixo;
        getline(arq, vet[i].nome, ',');
        arq >> vet[i].ano;
        arq >> lixo;
        arq >> vet[i].potencia;
        arq >> lixo;
        getline(arq, vet[i].classe);
        vet[i].removido = false;
        i++;
        quant++;
        if (i == tam) {
            vet = alocacao(vet, tam);
        }
    }
    arq.close();
    cout << "Dados importados com sucesso" << endl;
    return vet;
}

void inserir(Carros *vet, int &quant) {
    Carros novo;
    cout << "Digite o identificador do carro: ";
    cin >> novo.id;
    cin.ignore();
    cout << "Digite o nome do carro: ";
    getline(cin, novo.nome);
    cout << "Digite o ano de fabricação do carro: ";
    cin >> novo.ano;
    cout << "Digite a potência (em cv) do carro: ";
    cin >> novo.potencia;
    cin.ignore();
    cout << "Digite a classe do carro: ";
    getline(cin, novo.classe);

    vet[quant] = novo;
    quant++;
}

void listar(Carros vet[], int quant) {
    for (int i = 0; i < quant; i++) {
        if (!vet[i].removido) {
            cout << "Identificador: " << vet[i].id << endl;
            cout << "Nome: " << vet[i].nome << endl;
            cout << "Ano: " << vet[i].ano << endl;
            cout << "Potência: " << vet[i].potencia << endl;
            cout << "Classe: " << vet[i].classe << endl;
            cout << endl;
        }
    }
}

void ordenarPorNome(Carros vet[], int quant) {
    for (int i = 0; i < quant - 1; i++) {
        for (int j = 0; j < quant - i - 1; j++) {
            if (!vet[j].removido && !vet[j + 1].removido && vet[j].nome > vet[j + 1].nome) {
                Carros temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
    cout << "Ordenado por nome." << endl;
}

void ordenarPorAno(Carros vet[], int quant) {
    for (int i = 0; i < quant - 1; i++) {
        for (int j = 0; j < quant - i - 1; j++) {
            if (!vet[j].removido && !vet[j + 1].removido && vet[j].ano > vet[j + 1].ano) {
                Carros temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
    cout << "Ordenado por ano." << endl;
}

Carros *marcarRemovido(Carros *vet, int &quant) {
    int idRemover;
    cout << "Digite o identificador do carro a ser removido: ";
    cin >> idRemover;
    for (int i = 0; i < quant; i++) {
        if (vet[i].id == idRemover && !vet[i].removido) {
            vet[i].removido = true;
            cout << "Carro marcado como removido!" << endl;
            return vet;
        }
    }
    cout << "Carro não encontrado ou já removido!" << endl;
    return vet;
}

void atualizarArquivo(Carros vet[], int quant) {
    ofstream arq("Grupo_57_Porsche.csv");
    for (int i = 0; i < quant; ++i) {
        if (!vet[i].removido) {
            arq << vet[i].id << ", " << vet[i].nome << ", " << vet[i].ano << ", "
                << vet[i].potencia << ", " << vet[i].classe << endl;
        }
    }
    arq.close();
    cout << "Arquivo atualizado com sucesso" << endl;
}

void imprimir(const Carros vet[], int inicio, int fim, int quant) {
    if (inicio >= 0 && inicio <= fim && fim < quant) {
        for (int i = inicio; i <= fim; ++i) {
            cout << "Identificador: " << vet[i].id << endl;
            cout << "Nome: " << vet[i].nome << endl;
            cout << "Ano: " << vet[i].ano << endl;
            cout << "Potência: " << vet[i].potencia << endl;
            cout << "Classe: " << vet[i].classe << endl;
            cout << endl;
        }
    } else {
        cout << "Intervalo inválido!" << endl;
    }
}

int main() {
    int tam = 50;
    int quant = 0;
    Carros *vet = new Carros[tam];
    char opcao = '1';
    while (opcao != '0') {
        cout << endl << "Escolha uma opção abaixo:" << endl;
        cout << "Opção 1: Importar dados CSV" << endl;
        cout << "Opção 2: Buscar carro por nome" << endl;
        cout << "Opção 3: Buscar carro por ano" << endl;
        cout << "Opção 4: Inserir dados" << endl;
        cout << "Opção 5: Listar dados" << endl;
        cout << "Opção 6: Ordenar por nome" << endl;
        cout << "Opção 7: Ordenar por ano" << endl;
        cout << "Opção 8: Remover carro" << endl;
        cout << "Opção 9: Imprimir intervalo de elementos" << endl;
        cout << "Opção 0: Sair" << endl;
        cin >> opcao;
        cin.ignore();
        if (opcao == '1') {
            vet = lerCSV(vet, tam, quant);
        } else if (opcao == '2') {
            buscaNome(vet, quant);
        } else if (opcao == '3') {
            buscaAno(vet, quant);
        } else if (opcao == '4') {
            inserir(vet, quant);
        } else if (opcao == '5') {
            listar(vet, quant);
        } else if (opcao == '6') {
            ordenarPorNome(vet, quant);
        } else if (opcao == '7') {
            ordenarPorAno(vet, quant);
        } else if (opcao == '8') {
            vet = marcarRemovido(vet, quant);
            atualizarArquivo(vet, quant);
        } else if (opcao == '9') {
            int inicio, fim;
            cout << "Digite o índice de início: ";
            cin >> inicio;
            cout << "Digite o índice de fim: ";
            cin >> fim;
            cin.ignore();
            imprimir(vet, inicio, fim, quant);
        } else if (opcao == '0') {
            cout << "Saindo..." << endl;
        } else {
            cout << "Opção inválida!" << endl;
        }
    }
    delete[] vet;
    return 0;
}
