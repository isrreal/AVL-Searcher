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
    ~Node<T>() {};
};

#endif
