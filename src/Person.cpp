#include "Person.hpp"

    std::string Person::getCPF() const { return this->CPF; }
    std::string Person::getName() const { return this->name; }
    std::string Person::getSurname() const { return this->surname; }
    std::string Person::getBirthDate() const { return this->birthDate; }
    std::string Person::getHometown() const { return this->hometown; }
    std::ostream& operator <<(std::ostream& os, const Person& person) {
        os << person.name  << " " << person.surname << " " << person.CPF << \
            " " << person.birthDate << " " << person.hometown << std::endl;
        return os;
    }


