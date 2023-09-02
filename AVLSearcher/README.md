The following code is intended to carry out search and insertion operations implemented in templates based on search keys by person: CPF, name and date of birth. Such operations have a logarithmic time complexity of O(lg n), for that, the data structure of a "self-balancing" binary search tree, AVL, is used, based on the information that was read from the CSV file("COMMA SEPARATED FILE" ), "data.csv". Search operations in said tree are distinguished by the following parameters:

CPF: receives the CPF at the entrance and returns the information of the searched CPF. error message --> (if not found).

Name: takes a substring on input, and returns all names that have at least that substring. error message --> (if there are no matches).

Date: receives two dates and returns all the information of the people present in that interval. error message --> (if ranges are not valid).

Classes PersonByCPF, PersonByName, PersonByDataDeNascimento are subinstances of the parent class, called Person, used with the intention of overloading the comparison operators in a disparate way.

The different templates for each sub-instance of Person were implemented with the respective overloaded comparison operations underpinning them.

Here is the default compilation mode for the code:

g++ *.cpp -o main -std=c++17 && ./main
