#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <cctype>
#include <codecvt>
#include <locale>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <climits>

class Pessoa {
    private:
        std::string CPF;
        std::string nome;
        std::string sobrenome;
        std::string dataDeNascimento;
        std::string cidadeNatal;
    public:        
        Pessoa(std::string CPF = "", std::string nome = "", std::string sobrenome = "",
                std::string dataDeNascimento = "",
                std::string cidadeNatal = ""): CPF(CPF), nome(nome),
                sobrenome(sobrenome), dataDeNascimento(dataDeNascimento),
                cidadeNatal(cidadeNatal) {}
        std::string getCPF() const;
        std::string getNome() const;
        std::string getSobreNome() const;
        std::string getDataDeNascimento() const;
        std::string getCidadeNatal() const;
        friend std::ostream& operator << (std::ostream& os, const Pessoa& pessoa);
 };    
    
#endif
