#include "PessoaPorNome.hpp"
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> PessoaPorNome::converter;
inline std::string PessoaPorNome::normalizarNome(std::wstring nome) {
    std::string resultado;
    for (wchar_t caractere : nome) {
        if (caractere == L'á' || caractere == L'à' || caractere == L'ã' || caractere == L'â' ||
            caractere == L'Á' || caractere == L'À' || caractere == L'Ã' || caractere == L'Â' || 
            caractere == L'A') 
            resultado += 'a';
        else if (caractere == L'é' || caractere == L'è' || caractere == L'ê'||
                caractere == L'É' || caractere == L'È' || caractere == L'Ê' || 
                caractere == L'E')
            resultado += 'e';
        else if (caractere == L'í' || caractere == L'ì' || caractere == L'Í' || caractere == L'Ì'
                || caractere == L'I')
            resultado += 'i';
        else if (caractere == L'ó' || caractere == L'ò' || caractere == L'õ' || caractere == L'ô' ||
                caractere == L'Ó' || caractere == L'Ò' || caractere == L'Õ' || caractere == L'Ô' ||
                caractere == L'O') 
            resultado += 'o';
        else if (caractere == L'ú' || caractere == L'ù' || caractere == L'Ú' || caractere == L'Ù'
                || caractere == L'U')
            resultado += 'u';
        else if (caractere == L'ç' || caractere == L'Ç') 
            resultado += 'c';   
        else 
            resultado += std::tolower(caractere);
    }
    return resultado;
}

bool PessoaPorNome::operator < (const PessoaPorNome& pessoa) {
    std::string nome = this->normalizarNome(converter.from_bytes(this->getNome()));
    std::string nome2 = this->normalizarNome(converter.from_bytes(pessoa.getNome()));
    std::string sobreNome = this->normalizarNome(converter.from_bytes(this->getSobreNome()));
    std::string sobreNome2 = this->normalizarNome(converter.from_bytes(pessoa.getSobreNome()));
    return (nome < nome2)  || (nome < nome2 && sobreNome < sobreNome2 || (nome == nome2 && sobreNome < sobreNome2));
}

bool PessoaPorNome::operator > (const PessoaPorNome& pessoa) {
    std::string nome = this->normalizarNome(converter.from_bytes(this->getNome()));
    std::string nome2 = this->normalizarNome(converter.from_bytes(pessoa.getNome()));
    std::string sobreNome = this->normalizarNome(converter.from_bytes(this->getSobreNome()));
    std::string sobreNome2 = this->normalizarNome(converter.from_bytes(pessoa.getSobreNome()));
    return (nome > nome2)  || (nome > nome2 && sobreNome > sobreNome2) || (nome == nome2 && sobreNome > sobreNome2);
}

bool PessoaPorNome::operator == (const PessoaPorNome& pessoa) {
    size_t contNome = 0;
    size_t contSobrenome = 0;
    std::string nome = this->normalizarNome(converter.from_bytes(this->getNome()));
    std::string nome2 = this->normalizarNome(converter.from_bytes(pessoa.getNome()));
    std::string sobreNome = this->normalizarNome(converter.from_bytes(this->getSobreNome()));
    std::string sobreNome2 = this->normalizarNome(converter.from_bytes(pessoa.getSobreNome()));
    size_t totalNome = nome.size() < nome2.size() ? nome.size() : nome2.size();
    size_t totalSobrenome = sobreNome.size() < sobreNome2.size() ? sobreNome.size() : sobreNome2.size();
    for (auto it = 0; it < totalNome; ++it) {
        if (nome.data()[it] == nome2.data()[it])
            ++contNome;    
        else
            return false;
    }

    for (auto it = 0; it < totalSobrenome; ++it) {
        if (sobreNome.data()[it] == sobreNome2.data()[it])
            ++contSobrenome;
        else 
            return false;
    }

    return contNome > 0 || (contNome > 0 && contSobrenome > 0) ? true : false;
}