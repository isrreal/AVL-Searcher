#include "PessoaPorCPF.hpp"

std::string PessoaPorCPF::normalizarCPF(std::string CPF) {
    std::string saida = "";
    for (auto caractere: CPF)
        if (std::isdigit(caractere))
            saida.push_back(caractere); 
    if (saida.empty())
        saida.push_back('0');
    return saida;
}

bool PessoaPorCPF::operator < (const PessoaPorCPF& pessoa) {
    return std::stoul(PessoaPorCPF::normalizarCPF(this->getCPF())) < std::stoul(PessoaPorCPF::normalizarCPF(pessoa.getCPF()));
}

bool PessoaPorCPF::operator > (const PessoaPorCPF& pessoa) {
    return std::stoul(PessoaPorCPF::normalizarCPF(this->getCPF())) > std::stoul(PessoaPorCPF::normalizarCPF(pessoa.getCPF()));
}

bool PessoaPorCPF::operator == (const PessoaPorCPF& pessoa) {
    return std::stoul(PessoaPorCPF::normalizarCPF(this->getCPF())) == std::stoul(PessoaPorCPF::normalizarCPF(pessoa.getCPF()));
}
