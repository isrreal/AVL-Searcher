#ifndef PESSOAPORNOME_HPP
#define PESSOAPORNOME_HPP

#include "Pessoa.hpp"

class PessoaPorNome : public Pessoa {    
public:
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    static std::string normalizarNome(std::wstring nome);
    PessoaPorNome(std::string CPF, std::string nome, std::string sobrenome,
            std::string dataDeNascimento,
            std::string cidadeNatal): Pessoa(CPF, nome, sobrenome, dataDeNascimento, cidadeNatal) {}
    PessoaPorNome(std::string nome): Pessoa("", nome) {}
    PessoaPorNome() = default;
    ~PessoaPorNome() = default;
    bool operator < (const PessoaPorNome& pessoa);
    bool operator > (const PessoaPorNome& pessoa);
    bool operator == (const PessoaPorNome& pessoa);
};


#endif // PESSOAPORNOME_H
