#include "BinarySearchTreeAVL.hpp"

namespace Tools {

    void limparTela() {
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }

    std::vector<std::vector<std::string>> readCSV() {
        std::vector<std::vector<std::string>> data;
        std::ifstream arquivo("data.csv", std::fstream::in);
        std::string line;
        if (!arquivo) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return {};
        }

        while (std::getline(arquivo, line)) {
            std::vector<std::string> vetor;
            std::stringstream ss(line);
            std::string valor;
            while (std::getline(ss, valor, ','))
                vetor.push_back(valor); 
            data.push_back(vetor);
        }
        return data;
    }

    int menu() {
        char opcao; 
        std::vector<std::vector<std::string>> data = readCSV();
        if (data.empty())
            return -1;
        std::string entrada = "";
        std::string entrada2 = ""; 
        BinarySearchTreeAVL<PessoaPorCPF*> arvore;
        BinarySearchTreeAVL<PessoaPorNome*> arvore2;  
        BinarySearchTreeAVL<PessoaPorDataDeNascimento*> arvore3;  
        for (size_t i = 1; i < data.size(); ++i) {
            arvore.insert(new PessoaPorCPF(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]));
            arvore2.insert(new PessoaPorNome(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]));
            arvore3.insert(new PessoaPorDataDeNascimento(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]));
        }
            
        while (true) {
            std::cout << "Selecione:" << std::endl << "1: busca por CPF"\
                      << "\n2: busca por Nome"\
                      << "\n3: busca por data de nascimento\n"\
                      << "Qualquer outro botão para encerrar a aplicação" << std::endl;
            std::cin >> opcao;
            limparTela();      
            if (opcao == '1') {       
                std::cout << "Digite o CPF para a busca" << std::endl;     
                std::cin >> entrada;
                if (entrada.size() > 10 && entrada.size() < 15)
                    arvore.find(new PessoaPorCPF(entrada));
                else
                    std::cout << "O CPF digitado não é válido.";
                std::cin.ignore(1, '\n');
                std::cin.get();
            }

            else if (opcao == '2') {
                std::cout << "Digite o nome para a busca" << std::endl;  
                std::cin >> entrada;                
                arvore2.find(new PessoaPorNome(entrada)); 
                std::cin.ignore(1, '\n');
                std::cin.get();
            }
            
            else if (opcao == '3') {
                std::cout << "Digite os intervalos de busca: " << std::endl;
                std::cin >> entrada;
                std::cin >> entrada2;  
                std::vector<std::string> data = PessoaPorDataDeNascimento::normalizarData(entrada);
                std::vector<std::string> data2 = PessoaPorDataDeNascimento::normalizarData(entrada2);
                if (data.empty() || data2.empty())
                    std::cout << "Entrada inválida." << std::endl;
                else {
                    int dataDia = std::stoi(data[0]);
                    int dataMes = std::stoi(data[1]);
                    int dataAno = std::stoi(data[2]);
                    int data2Dia = std::stoi(data2[0]);
                    int data2Mes = std::stoi(data2[1]);
                    int data2Ano = std::stoi(data2[2]);
                    if ((dataDia > 0 && dataDia < 32) && (data2Dia > 0 && data2Dia < 32)
                        && (dataMes > 0 && dataMes < 13) && (data2Mes > 0 && data2Mes < 32)
                        && (dataAno > 0 && data2Ano > 0)) {
                        arvore3.find(new Node<PessoaPorDataDeNascimento*>(new PessoaPorDataDeNascimento(entrada)),
                                    new PessoaPorDataDeNascimento(entrada2));
                    }
                    else 
                        std::cout << "Digite uma data válida." << std::endl;
                }   
                std::cin.ignore(1, '\n');
                std::cin.get();
            }
            else {
                std::cout << "Encerrando a aplicação." << std::endl;
                break;
            }
            limparTela();      
        }
        return 0;
    }
};