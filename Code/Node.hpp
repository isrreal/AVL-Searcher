#ifndef NODE_H
#define NODE_H

#include "PessoaPorCPF.hpp"
#include "PessoaPorDataDeNascimento.hpp"
#include "PessoaPorNome.hpp"

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
struct Node<PessoaPorCPF*> {
    PessoaPorCPF* key;
    Node<PessoaPorCPF*>* left;
    Node<PessoaPorCPF*>* right;
    Node<PessoaPorCPF*>* parent;
    int height;
    Node<PessoaPorCPF*>(PessoaPorCPF* key,
        Node<PessoaPorCPF*>* left = nullptr,
        Node<PessoaPorCPF*>* right = nullptr,
        Node<PessoaPorCPF*>* parent = nullptr,
        int height = 1):
            key(key), left(left), right(right), parent(parent), height(height) {}
    ~Node<PessoaPorCPF*>() = default;
};

template <>
struct Node<PessoaPorNome*> {
    PessoaPorNome* key;
    Node<PessoaPorNome*>* left;
    Node<PessoaPorNome*>* right;
    Node<PessoaPorNome*>* parent;
    int height;
    Node<PessoaPorNome*>(PessoaPorNome* key,
        Node<PessoaPorNome*>* left = nullptr,
        Node<PessoaPorNome*>* right = nullptr,
        Node<PessoaPorNome*>* parent = nullptr,
        int height = 1):
            key(key), left(left), right(right), parent(parent), height(height) {}
    ~Node<PessoaPorNome*>() = default;
};

template <>
struct Node<PessoaPorDataDeNascimento*> {
    PessoaPorDataDeNascimento* key;
    Node<PessoaPorDataDeNascimento*>* left;
    Node<PessoaPorDataDeNascimento*>* right;
    Node<PessoaPorDataDeNascimento*>* parent;
    int height;
    Node<PessoaPorDataDeNascimento*>(PessoaPorDataDeNascimento* key,
        Node<PessoaPorDataDeNascimento*>* left = nullptr,
        Node<PessoaPorDataDeNascimento*>* right = nullptr,
        Node<PessoaPorDataDeNascimento*>* parent = nullptr,
        int height = 1):
            key(key), left(left), right(right), parent(parent), height(height) {}
    ~Node<PessoaPorDataDeNascimento*>() = default;
};



#endif
