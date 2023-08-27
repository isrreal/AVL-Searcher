#ifndef PESSOAPORCPF_HPP
#define PESSOAPORCPF_HPP

#include "Pessoa.hpp"

class PessoaPorCPF : public Pessoa {
public:
    static std::string normalizarCPF(std::string CPF);
    PessoaPorCPF(std::string CPF, std::string nome, std::string sobrenome,
            std::string dataDeNascimento,
            std::string cidadeNatal): Pessoa(CPF, nome, sobrenome, dataDeNascimento, cidadeNatal) {}
    PessoaPorCPF(std::string CPF): Pessoa(CPF) {}
    PessoaPorCPF() = default;
    ~PessoaPorCPF() = default;
    bool operator < (const PessoaPorCPF& pessoa);
    bool operator > (const PessoaPorCPF& pessoa);
    bool operator == (const PessoaPorCPF& pessoa);
};


#endif // PESSOAPORCPF_H
