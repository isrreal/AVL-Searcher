#ifndef NODE_HPP
#define NODE_HPP

#include "PersonByCPF.hpp"
#include "PersonByBirthDate.hpp"
#include "PersonByName.hpp"

template <typename T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    int height;
    Node<T>(T key, Node<T>* left = nullptr, Node<T>* right = nullptr,
            Node<T>* parent = nullptr, int height = 1):
            key(key), left(left), right(right), parent(parent), height(height) {}
    ~Node<T>();
};

template <>
struct Node<PersonByCPF> {
    PersonByCPF key;
    Node<PersonByCPF>* left;
    Node<PersonByCPF>* right;
    Node<PersonByCPF>* parent;
    int height;
    Node<PersonByCPF>(PersonByCPF key,
        Node<PersonByCPF>* left = nullptr,
        Node<PersonByCPF>* right = nullptr,
        Node<PersonByCPF>* parent = nullptr,
        int height = 1):
            key(key), left(left), right(right), parent(parent), height(height) {}
    ~Node<PersonByCPF>() = default;
};

template <>
struct Node<PersonByName> {
    PersonByName key;
    Node<PersonByName>* left;
    Node<PersonByName>* right;
    Node<PersonByName>* parent;
    int height;
    Node<PersonByName>(PersonByName key,
        Node<PersonByName>* left = nullptr,
        Node<PersonByName>* right = nullptr,
        Node<PersonByName>* parent = nullptr,
        int height = 1):
            key(key), left(left), right(right), parent(parent), height(height) {}
    ~Node<PersonByName>() = default;
};

template <>
struct Node<PersonByBirthDate> {
    PersonByBirthDate key;
    Node<PersonByBirthDate>* left;
    Node<PersonByBirthDate>* right;
    Node<PersonByBirthDate>* parent;
    int height;
    Node<PersonByBirthDate>(PersonByBirthDate key,
        Node<PersonByBirthDate>* left = nullptr,
        Node<PersonByBirthDate>* right = nullptr,
        Node<PersonByBirthDate>* parent = nullptr,
        int height = 1):
            key(key), left(left), right(right), parent(parent), height(height) {}
    ~Node<PersonByBirthDate>() = default;
};

#endif
