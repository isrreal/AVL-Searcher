#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <cctype>
#include <codecvt>
#include <locale>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <climits>

class Person {
    private:
        std::string CPF;
        std::string name;
        std::string surname;
        std::string birthDate;
        std::string hometown;
    public:        
        Person(std::string CPF = "", std::string name = "", std::string surname = "",
                std::string birthDate = "",
                std::string hometown = ""): CPF(CPF), name(name),
                surname(surname), birthDate(birthDate),
                hometown(hometown) {}
        std::string getCPF() const;
        std::string getName() const;
        std::string getSurname() const;
        std::string getBirthDate() const;
        std::string getHometown() const;
        friend std::ostream& operator << (std::ostream& os, const Person& person);
 };    
    
#endif
