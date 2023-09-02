#ifndef PERSONBYBIRTHDATE_HPP
#define PERSONBYBIRTHDATE_HPP

#include "Person.hpp"

class PersonByBirthDate: public Person {    
public:
    static std::vector<std::string> normalizeDate(std::string date);
    PersonByBirthDate(std::string CPF, std::string name, std::string surname,
            std::string birthDate,
            std::string homeTown): Person(CPF, name, surname, birthDate, homeTown) {}
    PersonByBirthDate(std::string birthDate): Person("", "", "", birthDate) {}
    PersonByBirthDate() = default;
    ~PersonByBirthDate() = default;
    bool operator < (const PersonByBirthDate& person);
    bool operator > (const PersonByBirthDate& person);
    bool operator == (const PersonByBirthDate& person);
};

#endif // PERSONBYBIRTHDATE_HPP
