// Bibliotecas
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
 
void exibirMenu()
{
	cout << "              LOCACAO DE CARROS              " << endl;
	cout << "1 | Alugar carro" << endl;
	cout << "2 | Carros alugados" << endl;
	cout << "2 | Devolver carro" << endl;
	cout << "3 | Cadastrar carros" << endl;
	cout << "4 | Sair" << endl;
	cout << endl;
	cout << "Escolha a opcao desejada" << endl;
}
 
// Struct (Marcelo)
struct Carros
{
	string modelo;
	string placa;
	float precoDia;
	bool disponivel;
};
 
void CadastrarCarro(Carros carro[])
{
	int n;
	cout << "Entre com a quantidade de carros a serem cadastrados: ";
	cin >> n;

	for (int t = 0; t < n; t++)
	{
		cout << "Digite o modelo do carro: ";
		getline(cin >> ws, carro[t].modelo);
		arqEscrita << carro[t].modelo << ";";

		cout << "Digite a placa do carro: ";
		getline(cin >> ws, carro[t].placa);
		arqEscrita << carro[t].placa << ";";

		cout << "Digite o valor do aluguel R$: ";
		cin >> carro[t].precoDia;
		arqEscrita << fixed << setprecision(2) << carro[t].precoDia << ";";

		carro[t].disponivel = true;
		arqEscrita << (carro[t].disponivel ? 1 : 0); // interrogação funciona como if ou else, ou seja, operador condicional, se for verdadeiro "disponivel" (True = 1) se for falso "indisponivel"(falso = 0)
		arqEscrita << endl;
 
		cout << "carro cadastrado com sucesso" << endl;
		
		//Verificar manualmente (olhar o arquivo) se os carros estáo sendo cadastrados
	}
}

void salvarCarros(Carros carros[])
{
    ofstream arqEscrita("carrosDisponiveis.txt");
    for (int i = 0; i < 50; i++)
    {
        arqEscrita << carros[i].modelo << ";"
            << carros[i].placa << ";"
            << carros[i].precoDia << ";"
            << (carros[i].disponivel ? "1" : "0")
    }
    arqEscrita.close();
}

// Funções Alugar e Devolver Carro (Murilo)
void atualizarDisponibilidade(Carros carro[], bool novoStatus)
{
    string escolha;
    bool encontrado = false;
	bool novoStatus;

    cout << "Modelo: ";
    getline(cin >> ws, escolha);

    for (int i = 0; i < 50; i++)
    {
        if (carro[i].modelo == escolha)
        {
            encontrado = true;

            if (novoStatus == false) // Aluga o carro
            {
                if (!carro[i].disponivel)
                {
                    cout << "Esse carro já está alugado." << endl;
                    return;
                }

                carro[i].disponivel = false;
                cout << "Carro alugado com sucesso!" << endl;
            }
            else // Devolve o carro
            {
                if (carro[i].disponivel)
                {
                    cout << "Esse carro já está disponível!" << endl;
                    return;
                }

                carro[i].disponivel = true;
                cout << "Carro devolvido com sucesso!" << endl;
            }

            salvarCarros(carro);
            return;
        }
    }

    if (!encontrado)
        cout << "Modelo não encontrado!" << endl;
}


// Função Listar Carro (Wendel)
 
// Main
int main()
{
	SetConsoleOutputCP(CP_UTF8); // Para saídas com acento
 
	int OpcaoDeEscolhaNoMenu = 0;
	Carros carro[50];
	ifstream arqLeitura;
	ofstream arqEscrita;
	string carrosDisponiveis;
 
	exibirMenu();
 
	while (true)
	{
		cin >> OpcaoDeEscolhaNoMenu;
 
		switch (OpcaoDeEscolhaNoMenu)
		{
		case 1: // Alugar carros
			arqLeitura.open ("carrosDisponiveis.txt");
			//Listar carros
			atualizarDisponibilidade(carro, false);
			arqLeitura.close();
			break;
		case 2: //Devolver carros
			arqLeitura.open ("carrosDisponiveis.txt");
			//Listar carros
			atualizarDisponibilidade(carro, true);
			arqLeitura.close();
			break;
		case 3: // Cadastrar carros
			arqEscrita.open("carrosDisponiveis.txt");
			CadastrarCarro(carro);
			arqLeitura.close();
			break;
		case 4: // Sair
			return 0;
		}
		exibirMenu();
	}
}
