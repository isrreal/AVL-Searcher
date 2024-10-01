#include "PersonByCPF.hpp"

std::string PersonByCPF::normalizeCPF(std::string CPF) {
    std::string output = "";
    for (auto character: CPF)
        if (std::isdigit(character))
            output.push_back(character); 
    if (output.empty())
        output.push_back('0');
    return output;
}

bool PersonByCPF::operator < (const PersonByCPF& person) {
    return std::stoul(PersonByCPF::normalizeCPF(this->getCPF())) < std::stoul(PersonByCPF::normalizeCPF(person.getCPF()));
}

bool PersonByCPF::operator > (const PersonByCPF& person) {
    return std::stoul(PersonByCPF::normalizeCPF(this->getCPF())) > std::stoul(PersonByCPF::normalizeCPF(person.getCPF()));
}

bool PersonByCPF::operator == (const PersonByCPF& person) {
    return std::stoul(PersonByCPF::normalizeCPF(this->getCPF())) == std::stoul(PersonByCPF::normalizeCPF(person.getCPF()));
}
