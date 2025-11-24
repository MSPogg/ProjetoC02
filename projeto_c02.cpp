// Bibliotecas
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;

// Menu
void exibirMenu()
{
    string azul = "\033[34m";
    string reset = "\033[0m";
    
    cout << azul << "              LOCAÇÃO DE CARROS              " << reset << endl << endl;
    cout << azul << "1 - " << reset << "Alugar carro" << endl;
    cout << azul << "2 - " << reset << "Devolver carro" << endl;
    cout << azul << "3 - " << reset << "Cadastrar carro" << endl;
    cout << azul << "4 - " << reset << "Sair" << endl;
    cout << endl;
    cout << "Escolha a opcao desejada: ";
}

// Struct
struct Carros
{
    string modelo;
    string placa;
    float precoDia;
    bool disponivel;
};

// Leitura do arquivo 
int lerCarros(Carros carro[])
{
    ifstream arq("carrosDisponiveis.txt");
    if (!arq.is_open()) return 0;

    int total = 0;

    while (arq >> carro[total].modelo
   	   	   	   >> carro[total].placa
				>> carro[total].precoDia
                >> carro[total].disponivel)
    {
        total++;
    }

    return total;
}

// Salvar no arquivo
void salvarCarros(Carros carros[], int total)
{
    ofstream arq("carrosDisponiveis.txt");

    for (int i = 0; i < total; i++)
    {
        arq << carros[i].modelo << " "
            << carros[i].placa << " "
            << fixed << setprecision(2) << carros[i].precoDia << " "
            << (carros[i].disponivel ? 1 : 0);

        if (i < total - 1) arq << endl;
    }
}

// Cadastro de carros
void CadastrarCarro(Carros carro[], int &total)
{
	string verde = "\033[32m";
	string reset = "\033[0m";
	 
    ofstream arq("carrosDisponiveis.txt", ios::app);
    if (!arq.is_open()) {
        cout << "Erro ao abrir arquivo!" << endl;
        return;
    }

    int n;
    cout << "Quantidade de carros para cadastrar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Modelo: ";
        getline(cin >> ws, carro[total].modelo);

        cout << "Placa: ";
        getline(cin >> ws, carro[total].placa);

        cout << "Preço por dia: ";
        cin >> carro[total].precoDia;

        carro[total].disponivel = true;

        arq << carro[total].modelo << " "
            << carro[total].placa << " "
            << fixed << setprecision(2) << carro[total].precoDia << " 1\n";
        total++;
        cout << verde << "Carro cadastrado com sucesso!" << reset << endl << endl;
    }

    arq.close();
}

// Alugar ou devolver
void atualizarDisponibilidade(Carros carro[], int total, bool novoStatus)
{
	string verde = "\033[32m";
	string reset = "\033[0m";
    string escolha;
    cout << "Digite o modelo do carro: ";
    getline(cin >> ws, escolha);
    cout << endl;

    for (int i = 0; i < total; i++)
    {
        if (carro[i].modelo == escolha)
        {
            if (carro[i].disponivel == novoStatus)
            {
                cout << (novoStatus ? "Esse carro já está disponível." : "Esse carro já está alugado.") << endl << endl;
                return;
            }
            
            if (novoStatus == true)
			{
			    int dias;
			    cout << "Por quantos dias o carro foi utilizado? ";
			    cin >> dias;
			    cout << endl;
			
			    float totalPagar = dias * carro[i].precoDia;
			
			    cout << "Valor total a pagar: R$ " 
			         << fixed << setprecision(2) << totalPagar << endl << endl;
			    cin.ignore();
			}
			
            carro[i].disponivel = novoStatus;

            cout << verde << (novoStatus ? "Carro devolvido com sucesso!" : "Carro alugado com sucesso!") << reset << endl << endl;

            salvarCarros(carro, total);
            return;
        }
    }

    cout << "Modelo não encontrado!" << endl;
}

// Listar carros
void listarCarros(Carros carro[], int total)
{
    cout << "              CARROS CADASTRADOS              " << endl << endl;
    
    for (int i = 0; i < total; i++)
    {
        cout << carro[i].modelo << " | " << carro[i].placa << " | R$ " << carro[i].precoDia << " | " 
		<< (carro[i].disponivel ? "Disponível" : "Alugado")<< endl;
    }
    
    cout << endl;
}

// Main
int main()
{
    setlocale(LC_ALL, "Portuguese");

    Carros carro[50];
    int total = lerCarros(carro);
    int opcao;

    while (true)
    {
        exibirMenu();
        cin >> opcao;
        cout << endl;
        cin.ignore();

        switch (opcao)
        {
        case 1:
        	listarCarros(carro, total);
            atualizarDisponibilidade(carro, total, false);
            break;

        case 2:
            atualizarDisponibilidade(carro, total, true);
            break;

        case 3:
            CadastrarCarro(carro, total);
            break;

        case 4:
            return 0;

        default:
            cout << "Opção inválida!" << endl;
        }
    }
}
