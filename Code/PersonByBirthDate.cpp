#include "PersonByBirthDate.hpp"

std::vector<std::string> PersonByBirthDate::normalizeDate(std::string date) {
    std::string day = ""; 
    std::string month = "";
    std::string year = "";
    if (date[2] == '/' && date[5] == '/') {
        day.push_back(date[0]);
        day.push_back(date[1]);
        month.push_back(date[3]);
        month.push_back(date[4]);
        year.push_back(date[6]);
        year.push_back(date[7]);
        year.push_back(date[8]);
        year.push_back(date[9]);
    }

    else if (date[2] == '/' && (date[4] == '/')) {
        day.push_back(date[0]);
        day.push_back(date[1]);
        month.push_back(date[3]);
        year.push_back(date[5]);
        year.push_back(date[6]);
        year.push_back(date[7]);
        year.push_back(date[8]);
    }

    else if (date[1] == '/' && date[3] == '/') {
        day.push_back(date[0]);
        month.push_back(date[2]);
        year.push_back(date[4]);
        year.push_back(date[5]);
        year.push_back(date[6]);
        year.push_back(date[7]);
    }

    else if (date[1] == '/' && date[4] == '/') {
        day.push_back(date[0]);
        month.push_back(date[2]);
        month.push_back(date[3]);
        year.push_back(date[5]);
        year.push_back(date[6]);
        year.push_back(date[7]);
        year.push_back(date[8]);
    }

    if ((day.empty() || month.empty() || year.empty())
        || day.size() > 2 || month.size() > 2 || year.size() > 4) {
        return {};
    }
    else
        return {day, month, year};
}

bool PersonByBirthDate::operator < (const PersonByBirthDate& person) {
    return (std::stoi(normalizeDate(this->getBirthDate())[2]) == std::stoi(normalizeDate(person.getBirthDate())[2])
            && std::stoi(normalizeDate(this->getBirthDate())[1]) == std::stoi(normalizeDate(person.getBirthDate())[1])
            && std::stoi(normalizeDate(this->getBirthDate())[0]) < std::stoi(normalizeDate(person.getBirthDate())[0])) 
            || (std::stoi(normalizeDate(this->getBirthDate())[2]) == std::stoi(normalizeDate(person.getBirthDate())[2]))
            && std::stoi(normalizeDate(this->getBirthDate())[1]) < std::stoi(normalizeDate(person.getBirthDate())[1])
            || std::stoi(normalizeDate(this->getBirthDate())[2]) < std::stoi(normalizeDate(person.getBirthDate())[2]);
}

bool PersonByBirthDate::operator > (const PersonByBirthDate& person) {
        return (std::stoi(normalizeDate(this->getBirthDate())[2]) == std::stoi(normalizeDate(person.getBirthDate())[2])
            && std::stoi(normalizeDate(this->getBirthDate())[1]) == std::stoi(normalizeDate(person.getBirthDate())[1])
            && std::stoi(normalizeDate(this->getBirthDate())[0]) > std::stoi(normalizeDate(person.getBirthDate())[0])) 
            || (std::stoi(normalizeDate(this->getBirthDate())[2]) == std::stoi(normalizeDate(person.getBirthDate())[2]))
            && std::stoi(normalizeDate(this->getBirthDate())[1]) > std::stoi(normalizeDate(person.getBirthDate())[1])
            || std::stoi(normalizeDate(this->getBirthDate())[2]) > std::stoi(normalizeDate(person.getBirthDate())[2]);
}

bool PersonByBirthDate::operator == (const PersonByBirthDate& person) {
    return std::stoi(normalizeDate(this->getBirthDate())[2]) == std::stoi(normalizeDate(person.getBirthDate())[2])
        && std::stoi(normalizeDate(this->getBirthDate())[1]) == std::stoi(normalizeDate(person.getBirthDate())[1])
        && std::stoi(normalizeDate(this->getBirthDate())[0]) == std::stoi(normalizeDate(person.getBirthDate())[0]);
}
