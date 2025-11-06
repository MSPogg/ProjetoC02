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
	cout << "3 | Devolver carro" << endl;
	cout << "4 | Cadastrar carros" << endl;
	cout << "5 | Sair" << endl;
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
 
// Função Cadastrar Carro (Marcelo)
/*Carros CadastrarCarro()
{
	Carros carro;
	cout << "Digite o modelo do carro:" << endl;
	getline(cin >> ws, carro.modelo);
	cout << "Digite a placa do carro:" << endl;
	getline(cin >> ws, carro.placa);
	cout << "Digite o valor do aluguel:" << endl
<< "R$: ";
	cin >> carro.precoDia;
	return carro;
}
 
// Funções Menu (Wendel)
/* void menuA()
{
	string CarrosDisponiveisParaLocacao;
 
	ifstream arq;
	arq.open("carrosDisponiveis.txt", ifstream::in);
 
	while (!arq.eof())
	{
		getline(arq, CarrosDisponiveisParaLocacao);
		cout << CarrosDisponiveisParaLocacao << endl;
	}
 
	//funçao do Murilo "entra" aqui, o "cout" de status e "cin" do modelo que o cliente que escolher vai estar na função dele //
 
	arq.close();
} */
 
void alugarCarro(Carros carro[])
{
	string escolha;
	bool encontrado = false;
 
	cout << "Modelo que gostaria de alugar: ";
	getline(cin >> ws, escolha);
 
	for (int i = 0; i < 50; i++)
	{
		if (carro[i].modelo == escolha)
		{
			encontrado = true;
 
			if (carro[i].disponivel)
			{
				carro[i].disponivel = false;
				cout << "Carro alugado com sucesso!" << endl;
			}
			else
			{
				cout << "Esse carro já está alugado." << endl;
			}
 
			break;
		}
	}
 
	if(!encontrado)
	{
		cout << "Nenhum carro encontrado";
	}
}
 
void menuB()
{
	string CarrosAlugados;
 
	ifstream arq;
	arq.open("carrosAlugados.txt", ifstream::in);
 
	while (!arq.eof())
	{
		getline(arq, CarrosAlugados);
		cout << CarrosAlugados << endl;
	}
 
	arq.close();
}
void menuC()
{
	string DevolverCarro;
	cout << "Digite o modelo do veículo para realizar a devolucao" << endl;
	cout << endl;
	cin >> DevolverCarro;
	cout << endl;
	cout << "Devolucao cadastrada com sucesso - Agradecemos a preferencia" << endl;
}
void menuD()
{
	string Email, Senha, nQuantidadesDeCarros;
	cout << "=Login=" << endl;
	while (Email != "wendel.gabriel@inatel.br")
	{
		cin >> Email;
		if (Email == "wendel.gabriel@inatel.br")
		{
			cout << "Digite sua senha" << endl;
		}
		else
		{
			cout << "Login incorreto, tente novamente" << endl;
		}
	}
 
	while (Senha != "123nnn")
	{
		cin >> Senha;
		if (Senha != "123nnn")
		{
			cout << "Senha incorreta, tente novamente" << endl;
		}
	}
	cout << "             CENTRAL DE CADASTRO             " << endl;
	cout << endl;
	cout << "Quantos carros deseja cadastrar?" << endl;
 
	cin >> nQuantidadesDeCarros;
}
 
// Função Listar Carro (Wendel)
 
// Funções Alugar e Devolver Carro (Murilo)
void devolverCarro()
{
}
 
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
 
	while (OpcaoDeEscolhaNoMenu != 5)
	{
		cin >> OpcaoDeEscolhaNoMenu;
 
		switch (OpcaoDeEscolhaNoMenu)
		{
		case 1:
			arqLeitura.open ("carrosDisponiveis.txt");
			while (!arqLeitura.eof())
			{
				getline(arqLeitura, carrosDisponiveis);
				cout << carrosDisponiveis << endl;
			}
			alugarCarro(carro);
			arqLeitura.close();
			break;
		case 2:
			menuB();
			break;
		case 3:
			menuC();
			break;
		case 4:
			menuD();
			break;
		case 5:
			return 0;
		}
		exibirMenu();
	}
}
