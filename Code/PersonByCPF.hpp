#ifndef PERSONBYCPF_HPP
#define PERSONBYCPF_HPP

#include "Person.hpp"

class PersonByCPF : public Person {
public:
    static std::string normalizeCPF(std::string CPF);
    PersonByCPF(std::string CPF, std::string name, std::string surname,
            std::string birthDate,
            std::string hometown): Person(CPF, name, surname, birthDate, hometown) {}
    PersonByCPF(std::string CPF): Person(CPF) {}
    PersonByCPF() = default;
    ~PersonByCPF() = default;
    bool operator < (const PersonByCPF& person);
    bool operator > (const PersonByCPF& person);
    bool operator == (const PersonByCPF& person);
};


#endif // PersonByCPF_H
