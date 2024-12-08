#ifndef PERSONBYNAME_HPP
#define PERSONBYNAME_HPP

#include "Person.hpp"

class PersonByName : public Person {    
public:
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
    static std::string normalizeName(std::wstring name);
    
    PersonByName(std::string CPF, std::string name, std::string surname,
            std::string birthDate,
            std::string homeTown): Person(CPF, name, surname, birthDate, homeTown) {}
    PersonByName(std::string name): Person("", name) {}
    PersonByName() = default;
    ~PersonByName() = default;
    bool operator < (const PersonByName& person);
    bool operator > (const PersonByName& person);
    bool operator == (const PersonByName& person);
};


#endif // PersonByName_H
