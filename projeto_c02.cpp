#include <iostream>
#include <fstream>
 
using namespace std;
 
void menuA()
{
	string y;
	int cod;
 
	ifstream arq;
	arq.open("carrosDisponiveis.txt", ifstream::in);
 
	while(!arq.eof())
	{
		getline (arq, y);
		cout << y << endl;
	}
 
	cout << "digite o codigo do carro desejado" << endl;
	cin >> cod;
 
	arq.close();
 
}
 
void menuB()
{
	string w;
	string t;
 
	ifstream arq;
	arq.open("carrosAlugados.txt", ifstream::in);
 
	while(!arq.eof())
	{
		getline (arq, w);
		cout << w << endl;
	}
 
	arq.close();
}
 
void menuC()
{
	int d;
	cout << "Digite o codigo do carro para realizar a devolucao" << endl;
	cout << endl;
	cin >> d;
	cout << endl;
	cout << "Devolucao cadastrada com sucesso - Agrademos a preferencia" << endl;
 
}
 
void menuD()
{
	string e, f, p;
	cout << "=Login=" << endl;
	while (e != "wendel.gabriel@inatel.br")
	{
		cin >> e;
		if (e == "wendel.gabriel@inatel.br" )
		{
			cout << "Digite sua senha" << endl;
		}
		else
		{
			cout << "Login incorreto, tente novamente" << endl;
		}
	}
 
	while (f != "123nnn")
	{
		cin >> f;
		if (f != "123nnn" )
		{
			cout << "Senha incorreta, tente novamente" << endl;
		}
	}
	cout << "             CENTRAL DE CADASTRO             " << endl;
	cout << endl;
	cout << "Quantos carros deseja cadastrar?" << endl;
 
	cin >> p;
}
 
	void exibirMenu() 
	{ 
		cout << "              LOCACAO DE CARROS              " << endl;
	cout << "1 | Carros disponiveis para locacao" << endl;
	cout << "2 | Carros alugados" << endl;
	cout << "3 | Devolver carro" << endl;
	cout << "4 | Cadastrar carros" << endl;
	cout << "5 | Sair" << endl;
	cout << endl;
	cout << "Escolha a opcao desejada" << endl; 
	} 
int main()
{
	int x = 0;
 
	exibirMenu();
 
	while (x != 5)
	{
		cin >> x;
 
		switch(x)
		{
		case 1:
			menuA();
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
