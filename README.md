# ProjetoC02
Projeto de Locadora de Carros
🎯 Objetivo
Desenvolver um sistema em C++ para gerenciar uma locadora de carros. O sistema deve
permitir cadastrar carros, listar os disponíveis e alugados, realizar locações e devoluções, e
armazenar as informações em arquivo para manter os dados após o encerramento do
programa.
🧠 Funcionalidades Principais
1. Cadastrar Carro – adiciona novos veículos ao sistema.
2. Listar Carros – exibe todos, apenas disponíveis ou apenas alugados.
3. Alugar Carro – marca um veículo como alugado.
4. Devolver Carro – marca o carro como disponível e calcula o valor total.
5. Salvar e Carregar Dados – grava e lê as informações no arquivo carros.txt.
👥 Divisão de Tarefas
• Marcelo: Criação da struct Carro e função cadastrarCarro() – responsável por cadastrar
novos veículos.
• Murilo: Funções alugarCarro() e devolverCarro() – responsável pela lógica de locação e
devolução de veículos.
• Wendel: Funções de listagem (listarCarros()) e menu principal – responsável pela
exibição e navegação do sistema.
• Adonay: Funções salvarCarros() e carregarCarros() – responsável por implementar a
persistência de dados (arquivo).
