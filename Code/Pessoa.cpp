#include "Pessoa.hpp"

    std::string Pessoa::getCPF() const { return this->CPF; }
    std::string Pessoa::getNome() const { return this->nome; }
    std::string Pessoa::getSobreNome() const { return this->sobrenome; }
    std::string Pessoa::getDataDeNascimento() const { return this->dataDeNascimento; }
    std::string Pessoa::getCidadeNatal() const { return this->cidadeNatal; }
    std::ostream& operator <<(std::ostream& os, const Pessoa& pessoa) {
        os << pessoa.nome  << " " << pessoa.sobrenome << " " << pessoa.CPF << \
            " " << pessoa.dataDeNascimento << " " << pessoa.cidadeNatal << std::endl;
        return os;
    }


