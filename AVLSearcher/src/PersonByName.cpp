#include "PersonByName.hpp"

std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> PersonByName::convert;
inline std::string PersonByName::normalizeName(std::wstring name) {
    std::string output;
    for (wchar_t character: name) {
        if (character == L'á' || character == L'à' || character == L'ã' || character == L'â' ||
            character == L'Á' || character == L'À' || character == L'Ã' || character == L'Â' || 
            character == L'A') 
            output += 'a';
        else if (character == L'é' || character == L'è' || character == L'ê'||
                character == L'É' || character == L'È' || character == L'Ê' || 
                character == L'E')
            output += 'e';
        else if (character == L'í' || character == L'ì' || character == L'Í' || character == L'Ì'
                || character == L'I')
            output += 'i';
        else if (character == L'ó' || character == L'ò' || character == L'õ' || character == L'ô' ||
                character == L'Ó' || character == L'Ò' || character == L'Õ' || character == L'Ô' ||
                character == L'O') 
            output += 'o';
        else if (character == L'ú' || character == L'ù' || character == L'Ú' || character == L'Ù'
                || character == L'U')
            output += 'u';
        else if (character == L'ç' || character == L'Ç') 
            output += 'c';   
        else 
            output += std::tolower(character);
    }
    return output;
}

bool PersonByName::operator < (const PersonByName& person) {
    std::string name = this->normalizeName(convert.from_bytes(this->getName()));
    std::string name2 = this->normalizeName(convert.from_bytes(person.getName()));
    std::string surname = this->normalizeName(convert.from_bytes(this->getSurname()));
    std::string surname2 = this->normalizeName(convert.from_bytes(person.getSurname()));
    return (name < name2)  || (((name < name2) && (surname < surname2)) || ((name == name2) && (surname < surname2)));
}

bool PersonByName::operator > (const PersonByName& person) {
    std::string name = this->normalizeName(convert.from_bytes(this->getName()));
    std::string name2 = this->normalizeName(convert.from_bytes(person.getName()));
    std::string surname = this->normalizeName(convert.from_bytes(this->getSurname()));
    std::string surname2 = this->normalizeName(convert.from_bytes(person.getSurname()));
    return (name > name2)  || (name > name2 && surname > surname2) || (name == name2 && surname > surname2);
}

bool PersonByName::operator == (const PersonByName& person) {
    size_t contName = 0;
    size_t contSurname = 0;
    std::string name = this->normalizeName(convert.from_bytes(this->getName()));
    std::string name2 = this->normalizeName(convert.from_bytes(person.getName()));
    std::string surname = this->normalizeName(convert.from_bytes(this->getSurname()));
    std::string surname2 = this->normalizeName(convert.from_bytes(person.getSurname()));
    size_t totalName = name.size() < name2.size() ? name.size() : name2.size();
    size_t totalSurname = surname.size() < surname2.size() ? surname.size() : surname2.size();
    for (size_t it = 0; it < totalName; ++it) {
        if (name.data()[it] == name2.data()[it])
            ++contName;    
        else
            return false;
    }

    for (size_t it = 0; it < totalSurname; ++it) {
        if (surname.data()[it] == surname2.data()[it])
            ++contSurname;
        else 
            return false;
    }

    return contName > 0 || (contName > 0 && contSurname > 0) ? true : false;
}
