#include "PessoaPorDataDeNascimento.hpp"

std::vector<std::string> PessoaPorDataDeNascimento::normalizarData(std::string data) {
    std::string dia = ""; 
    std::string mes = "";
    std::string ano = "";
    if (data[2] == '/' && data[5] == '/') {
        dia.push_back(data[0]);
        dia.push_back(data[1]);
        mes.push_back(data[3]);
        mes.push_back(data[4]);
        ano.push_back(data[6]);
        ano.push_back(data[7]);
        ano.push_back(data[8]);
        ano.push_back(data[9]);
    }

    else if (data[2] == '/' && (data[4] == '/')) {
        dia.push_back(data[0]);
        dia.push_back(data[1]);
        mes.push_back(data[3]);
        ano.push_back(data[5]);
        ano.push_back(data[6]);
        ano.push_back(data[7]);
        ano.push_back(data[8]);
    }

    else if (data[1] == '/' && data[3] == '/') {
        dia.push_back(data[0]);
        mes.push_back(data[2]);
        ano.push_back(data[4]);
        ano.push_back(data[5]);
        ano.push_back(data[6]);
        ano.push_back(data[7]);
    }

    else if (data[1] == '/' && data[4] == '/') {
        dia.push_back(data[0]);
        mes.push_back(data[2]);
        mes.push_back(data[3]);
        ano.push_back(data[5]);
        ano.push_back(data[6]);
        ano.push_back(data[7]);
        ano.push_back(data[8]);
    }

    if ((dia.empty() || mes.empty() || ano.empty())
        || dia.size() > 2 || mes.size() > 2 || ano.size() > 4) {
        return {};
    }
    else
        return {dia, mes, ano};
}

bool PessoaPorDataDeNascimento::operator < (const PessoaPorDataDeNascimento& pessoa) {
    return (std::stoi(normalizarData(this->getDataDeNascimento())[2]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[2])
            && std::stoi(normalizarData(this->getDataDeNascimento())[1]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[1])
            && std::stoi(normalizarData(this->getDataDeNascimento())[0]) < std::stoi(normalizarData(pessoa.getDataDeNascimento())[0])) 
            || (std::stoi(normalizarData(this->getDataDeNascimento())[2]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[2]))
            && std::stoi(normalizarData(this->getDataDeNascimento())[1]) < std::stoi(normalizarData(pessoa.getDataDeNascimento())[1])
            || std::stoi(normalizarData(this->getDataDeNascimento())[2]) < std::stoi(normalizarData(pessoa.getDataDeNascimento())[2]);
}

bool PessoaPorDataDeNascimento::operator > (const PessoaPorDataDeNascimento& pessoa) {
        return (std::stoi(normalizarData(this->getDataDeNascimento())[2]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[2])
            && std::stoi(normalizarData(this->getDataDeNascimento())[1]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[1])
            && std::stoi(normalizarData(this->getDataDeNascimento())[0]) > std::stoi(normalizarData(pessoa.getDataDeNascimento())[0])) 
            || (std::stoi(normalizarData(this->getDataDeNascimento())[2]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[2]))
            && std::stoi(normalizarData(this->getDataDeNascimento())[1]) > std::stoi(normalizarData(pessoa.getDataDeNascimento())[1])
            || std::stoi(normalizarData(this->getDataDeNascimento())[2]) > std::stoi(normalizarData(pessoa.getDataDeNascimento())[2]);
}

bool PessoaPorDataDeNascimento::operator == (const PessoaPorDataDeNascimento& pessoa) {
    return std::stoi(normalizarData(this->getDataDeNascimento())[2]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[2])
        && std::stoi(normalizarData(this->getDataDeNascimento())[1]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[1])
        && std::stoi(normalizarData(this->getDataDeNascimento())[0]) == std::stoi(normalizarData(pessoa.getDataDeNascimento())[0]);
}
