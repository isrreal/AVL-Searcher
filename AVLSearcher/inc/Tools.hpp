#include "BinarySearchTreeAVL.hpp"

namespace Tools {

    void clearScreen() {
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }

    std::vector<std::vector<std::string>> readCSV() {
        std::vector<std::vector<std::string>> data;
        std::ifstream file("data.csv", std::fstream::in);
        std::string line;
        if (!file) {
            std::cerr << "Error to read the file!" << std::endl;
            return {};
        }

        while (std::getline(file, line)) {
            std::vector<std::string> vector;
            std::stringstream ss(line);
            std::string value;
            while (std::getline(ss, value, ','))
                vector.push_back(value); 
            data.push_back(vector);
        }
        return data;
    }

    int menu() {
        char option; 
        std::vector<std::vector<std::string>> data = readCSV();
        if (data.empty())
            return -1;
        std::string input = "";
        std::string input2 = ""; 
        BinarySearchTreeAVL<PersonByCPF*> tree1;
        BinarySearchTreeAVL<PersonByName*> tree2;  
        BinarySearchTreeAVL<PersonByBirthDate*> tree3;
        tree1.insert(new PersonByCPF(data[1][0], data[1][1], data[1][2], data[1][3], data[1][4]));  
        for (size_t i = 1; i < data.size(); ++i) {
            tree1.insert(new PersonByCPF(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]));
            tree2.insert(new PersonByName(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]));
            tree3.insert(new PersonByBirthDate(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4]));
        }
            
        while (true) {
            std::cout << "Select a search type: " << std::endl;
            std::cout << "1: CPF"\
                      << "\n2: Name"\
                      << "\n3: Birth date\n"\
                      << "Press any button to close aplication" << std::endl;
            std::cin >> option;
            clearScreen();      
            if (option == '1') {       
                std::cout << "Insert a valid CPF for search" << std::endl;     
                std::cin >> input;
                if (input.size() > 10 && input.size() < 15)
                    tree1.find(new PersonByCPF(input));
                else
                    std::cout << "The inserted CPF is not valid.";
                std::cin.ignore(1, '\n');
                std::cin.get();
            }

            else if (option == '2') {
                std::cout << "Insert one name for search" << std::endl;  
                std::cin >> input;                
                tree2.find(new PersonByName(input)); 
                std::cin.ignore(1, '\n');
                std::cin.get();
            }
            
            else if (option == '3') {
                std::cout << "Insert the date range: " << std::endl;
                std::cin >> input;
                std::cin >> input2;  
                std::vector<std::string> date = PersonByBirthDate::normalizeDate(input);
                std::vector<std::string> date2 = PersonByBirthDate::normalizeDate(input2);
                if (date.empty() || date2.empty())
                    std::cout << "Invalid input." << std::endl;
                else {
                    int dateDay = std::stoi(date[0]);
                    int dateMonth = std::stoi(date[1]);
                    int dateYear = std::stoi(date[2]);
                    int date2Day = std::stoi(date2[0]);
                    int date2Month = std::stoi(date2[1]);
                    int date2Year = std::stoi(date2[2]);
                    if ((dateDay > 0 && dateDay < 32) && (date2Day > 0 && date2Day < 32)
                        && (dateMonth > 0 && dateMonth < 13) && (date2Month > 0 && date2Month < 32)
                        && (date2Year > 0 && date2Year > 0)) {
                        tree3.find(new Node<PersonByBirthDate*>(new PersonByBirthDate(input)),
                                    new PersonByBirthDate(input2));
                    }
                    else 
                        std::cout << "Insert a valid date." << std::endl;
                }   
                std::cin.ignore(1, '\n');
                std::cin.get();
            }
            else {
                std::cout << "Closing the aplication." << std::endl;
                break;
            }
            clearScreen();      
        }
        return 0;
    }
};
