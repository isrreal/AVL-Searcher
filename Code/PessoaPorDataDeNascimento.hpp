#ifndef PESSOAPORDATADENASCIMENTO_HPP
#define PESSOAPORDATADENASCIMENTO_HPP

#include "Pessoa.hpp"

class PessoaPorDataDeNascimento: public Pessoa {    
public:
    static std::vector<std::string> normalizarData(std::string data);
    PessoaPorDataDeNascimento(std::string CPF, std::string nome, std::string sobrenome,
            std::string dataDeNascimento,
            std::string cidadeNatal): Pessoa(CPF, nome, sobrenome, dataDeNascimento, cidadeNatal) {}
    PessoaPorDataDeNascimento(std::string dataDeNascimento): Pessoa("", "", "", dataDeNascimento) {}
    PessoaPorDataDeNascimento() = default;
    ~PessoaPorDataDeNascimento() = default;
    bool operator < (const PessoaPorDataDeNascimento& pessoa);
    bool operator > (const PessoaPorDataDeNascimento& pessoa);
    bool operator == (const PessoaPorDataDeNascimento& pessoa);
};

#endif // PESSOAPORDATADENASCIMENTO_H
