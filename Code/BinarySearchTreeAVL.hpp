#ifndef BINARY_SEARCH_TREE_AVL_HPP
#define BINARY_SEARCH_TREE_AVL_HPP

#include "Node.hpp" 

// uma árvore AVL é uma BST que possui o fator de balanceamento, isto é,
// a diferença entre as alturas das subárvores esquerda e direita, é no máximo 1.

// usando o template para tipos diferentes de chave
int contador = 0;
template <typename T>

class BinarySearchTreeAVL {
private:
    Node<T>* root;
    void bShow(Node<T>* node, std::string str) const;
    int sizeRecursive(Node<T>* node) const;
    int getBalance(Node<T>* node) const;
    int height(Node<T>* node) const;
    void printPreOrderRecursive(Node<T>* node) const;
    void printInOrderRecursive(Node<T>* node) const;
    void printPostOrderRecursive(Node<T>* node) const;
    Node<T>* findRecursive(Node<T>* node, T value);
    Node<T>* minRecursive(Node<T>* node) const;
    Node<T>* maxRecursive(Node<T>* node) const;
    Node<T>* insertRecursive(Node<T>* node, T value);
    Node<T>* deleteRecursive(Node<T>* node, T value);
    Node<T>* rightRotation(Node<T>* node);
    Node<T>* leftRotation(Node<T>* node);
    Node<T>* clear(Node<T>* node);
public:
    BinarySearchTreeAVL<T>();
    ~BinarySearchTreeAVL<T>();
    void insert(T value);
    void bShow();
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteKey(T value);
    int getSize();
    Node<T>* getMin();
    Node<T>* getMax();
    Node<T>* getRaiz();
    void find(T value);
    Node<T>* clear();    
};


template <>

class BinarySearchTreeAVL<PessoaPorCPF*> {
private:
    Node<PessoaPorCPF*>* root;
    void bShow(Node<PessoaPorCPF*>* node, std::string str) const;
    int sizeRecursive(Node<PessoaPorCPF*>* node) const;
    int height(Node<PessoaPorCPF*>* node) const;
    int getBalance(Node<PessoaPorCPF*>* node) const;
    void printPreOrderRecursive(Node<PessoaPorCPF*>* node) const;
    void printInOrderRecursive(Node<PessoaPorCPF*>* node) const;
    void printPostOrderRecursive(Node<PessoaPorCPF*>* node) const;
    Node<PessoaPorCPF*>* findRecursive(Node<PessoaPorCPF*>* node, PessoaPorCPF* value);
    Node<PessoaPorCPF*>* minRecursive(Node<PessoaPorCPF*>* node) const;
    Node<PessoaPorCPF*>* maxRecursive(Node<PessoaPorCPF*>* node) const; 
    Node<PessoaPorCPF*>* insertRecursive(Node<PessoaPorCPF*>* node, PessoaPorCPF* value);
    Node<PessoaPorCPF*>* deleteRecursive(Node<PessoaPorCPF*>* node, PessoaPorCPF* value);
    Node<PessoaPorCPF*>* rightRotation(Node<PessoaPorCPF*>* node);
    Node<PessoaPorCPF*>* leftRotation(Node<PessoaPorCPF*>* node);
    Node<PessoaPorCPF*>* clear(Node<PessoaPorCPF*>* node);
public:
    BinarySearchTreeAVL<PessoaPorCPF*>();
    ~BinarySearchTreeAVL<PessoaPorCPF*>();
    void insert(PessoaPorCPF* value);
    void bShow();
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteKey(PessoaPorCPF* value);
    int getSize();
    PessoaPorCPF* getMin();
    PessoaPorCPF* getMax();
    Node<PessoaPorCPF*>* getRaiz();
    void find(PessoaPorCPF* value);
    Node<PessoaPorCPF*>* clear();
};


template <>

class BinarySearchTreeAVL<PessoaPorNome*> {
private:
    Node<PessoaPorNome*>* root;
    void bShow(Node<PessoaPorNome*>* node, std::string str) const;
    int sizeRecursive(Node<PessoaPorNome*>* node) const;
    int height(Node<PessoaPorNome*>* node) const;
    int getBalance(Node<PessoaPorNome*>* node) const;
    void printPreOrderRecursive(Node<PessoaPorNome*>* node) const;
    void printInOrderRecursive(Node<PessoaPorNome*>* node) const;
    void printPostOrderRecursive(Node<PessoaPorNome*>* node) const;
    Node<PessoaPorNome*>* findRecursive(Node<PessoaPorNome*>* node, PessoaPorNome* value);
    Node<PessoaPorNome*>* minRecursive(Node<PessoaPorNome*>* node) const;
    Node<PessoaPorNome*>* maxRecursive(Node<PessoaPorNome*>* node) const; 
    Node<PessoaPorNome*>* insertRecursive(Node<PessoaPorNome*>* node, PessoaPorNome* value);
    Node<PessoaPorNome*>* deleteRecursive(Node<PessoaPorNome*>* node, PessoaPorNome* value);
    Node<PessoaPorNome*>* rightRotation(Node<PessoaPorNome*>* node);
    Node<PessoaPorNome*>* leftRotation(Node<PessoaPorNome*>* node);
    Node<PessoaPorNome*>* clear(Node<PessoaPorNome*>* node);

public:
    BinarySearchTreeAVL<PessoaPorNome*>();
    ~BinarySearchTreeAVL<PessoaPorNome*>();
    void insert(PessoaPorNome* value);
    void bShow();
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteKey(PessoaPorNome* value);
    int getSize();
    PessoaPorNome* getMin();
    PessoaPorNome* getMax();
    Node<PessoaPorNome*>* getRaiz();
    void find(PessoaPorNome* value);
    Node<PessoaPorNome*>* clear();
};


template <>

class BinarySearchTreeAVL<PessoaPorDataDeNascimento*> {
private:
    Node<PessoaPorDataDeNascimento*>* root;
    void bShow(Node<PessoaPorDataDeNascimento*>* node, std::string str) const;
    int sizeRecursive(Node<PessoaPorDataDeNascimento*>* node) const;
    int height(Node<PessoaPorDataDeNascimento*>* node) const;
    int getBalance(Node<PessoaPorDataDeNascimento*>* node) const;
    void printPreOrderRecursive(Node<PessoaPorDataDeNascimento*>* node) const;
    void printInOrderRecursive(Node<PessoaPorDataDeNascimento*>* node) const;
    void printPostOrderRecursive(Node<PessoaPorDataDeNascimento*>* node) const;
    Node<PessoaPorDataDeNascimento*>* findRecursive(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value);
    Node<PessoaPorDataDeNascimento*>* minRecursive(Node<PessoaPorDataDeNascimento*>* node) const;
    Node<PessoaPorDataDeNascimento*>* maxRecursive(Node<PessoaPorDataDeNascimento*>* node) const; 
    Node<PessoaPorDataDeNascimento*>* insertRecursive(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value);
    Node<PessoaPorDataDeNascimento*>* deleteRecursive(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value);
    Node<PessoaPorDataDeNascimento*>* rightRotation(Node<PessoaPorDataDeNascimento*>* node);
    Node<PessoaPorDataDeNascimento*>* leftRotation(Node<PessoaPorDataDeNascimento*>* node);
    Node<PessoaPorDataDeNascimento*>* clear(Node<PessoaPorDataDeNascimento*>* node);
    Node<PessoaPorDataDeNascimento*>* sucessor(Node<PessoaPorDataDeNascimento*>* node);
    Node<PessoaPorDataDeNascimento*>* predecessor(Node<PessoaPorDataDeNascimento*>* node);
public:
    BinarySearchTreeAVL<PessoaPorDataDeNascimento*>();
    ~BinarySearchTreeAVL<PessoaPorDataDeNascimento*>();
    void insert(PessoaPorDataDeNascimento* value);
    void bShow();
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteKey(PessoaPorDataDeNascimento* value);
    int getSize();
    Node<PessoaPorDataDeNascimento*>* getMin();
    Node<PessoaPorDataDeNascimento*>* getMax();
    Node<PessoaPorDataDeNascimento*>* getRaiz();
    void find(PessoaPorDataDeNascimento* value);
    void find(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value);
    Node<PessoaPorDataDeNascimento*>* clear();
};

// PessoaPorCPF

//constructor
    BinarySearchTreeAVL<PessoaPorCPF*>::BinarySearchTreeAVL(): root(nullptr) {}

// destructor
    BinarySearchTreeAVL<PessoaPorCPF*>::~BinarySearchTreeAVL() {
        BinarySearchTreeAVL<PessoaPorCPF*>::clear(this->root);
    }

// private methods
    int BinarySearchTreeAVL<PessoaPorCPF*>::height(Node<PessoaPorCPF*>* node) const {
        return !node ? 0: node->height;
    }
    // Quando o nó é desbalanceado pela sua subárvore direita
    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::leftRotation(Node<PessoaPorCPF*>* node) {
        Node<PessoaPorCPF*>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        // recalcular as alturas de p e de u
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    // Quando o nó é desbalanceado pela sua subárvore esquerda
    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::rightRotation(Node<PessoaPorCPF*>* node) {
        Node<PessoaPorCPF*>* temp = node->left;
        node->left = temp->right;
        temp->right = node;        
        // recalcular as alturas de p e de u
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::insertRecursive(Node<PessoaPorCPF*>* node, PessoaPorCPF* value) {
        if (!node)
            return new Node<PessoaPorCPF*>(value);
        else if (*value > *node->key)
            node->right = insertRecursive(node->right, value);
        else if (*value < *node->key)
            node->left = insertRecursive(node->left, value);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));        
        int balance = getBalance(node);

        if (balance > 1 && *value < *node->right->key) {
            node->right = rightRotation(node->right);
            node = leftRotation(node);
        }

        else if (balance > 1 && *value > *node->right->key)
            node = leftRotation(node); 
        
        else if (balance < -1 &&  *value < *node->left->key)
            node = rightRotation(node);

        else if (balance < -1 && *value > *node->left->key) {
            node->left = leftRotation(node->left);
            node = rightRotation(node);
        }

        return node;
    }
    
    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::deleteRecursive(Node<PessoaPorCPF*>* node, PessoaPorCPF* value) {
        if (!node)
            return nullptr;
        else if (*node->key > *value)
            return deleteRecursive(node->left, value);
        else if (*node->key < *value)
            return deleteRecursive(node->right, value);
        else {
            // não tem subárvore esquerda
            if (!node->left) {
                Node<PessoaPorCPF*>* temp = node->right;
                delete node;
                return temp;
            }
            // não tem subárvore direita
            else if (!node->right) {
                Node<PessoaPorCPF*>* temp = node->left;
                delete node;
                return temp;
            }
            // tem ambas as subárvores
            else {
                Node<PessoaPorCPF*>* temp = minRecursive(node->right);
                node->key->getCPF() = temp->key->getCPF();
                node->right = deleteRecursive(node->right, temp->key);
            }

            node->height = 1 + std::max(height(node->left), height(node->right));

            int balance = getBalance(node);

            if (balance > 1 && getBalance(node->left) >= 0)
                return rightRotation(node);

            if (balance > 1 && getBalance(node->left) < 0) {
                node->left = leftRotation(node->left);
                return rightRotation(node);
            }

            if (balance < -1 && getBalance(node->right) <= 0)
                return leftRotation(node);

            if (balance < -1 && getBalance(node->right) > 0) {
                node->right = rightRotation(node->right);
                return leftRotation(node);
            }

            return node;
        }
    }

    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::findRecursive(Node<PessoaPorCPF*>* node, PessoaPorCPF* value) {
        if (!node)
            return nullptr;
        else if (*node->key == *value)
            return node;
        else if (*node->key < *value)
            return findRecursive(node->right, value);
        else
            return findRecursive(node->left, value);
    }

    int BinarySearchTreeAVL<PessoaPorCPF*>::getBalance(Node<PessoaPorCPF*>* node) const {
        return height(node->right) - height(node->left);
    }

    int BinarySearchTreeAVL<PessoaPorCPF*>::sizeRecursive(Node<PessoaPorCPF*>* node) const {
        return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
    }

    void BinarySearchTreeAVL<PessoaPorCPF*>::printPreOrderRecursive(Node<PessoaPorCPF*>* node) const {
        if (node) {
            std::cout << *node->key << " ";
            printPreOrderRecursive(node->left);
            printPreOrderRecursive(node->right);
        }
    }
    void BinarySearchTreeAVL<PessoaPorCPF*>::printInOrderRecursive(Node<PessoaPorCPF*>* node) const {
        if (node) {
            printInOrderRecursive(node->left);
            std::cout << *node->key << " ";
            printInOrderRecursive(node->right);
        }
    }

    void BinarySearchTreeAVL<PessoaPorCPF*>::printPostOrderRecursive(Node<PessoaPorCPF*>* node) const {
        if (node) {
            printPostOrderRecursive(node->left);
            printPostOrderRecursive(node->right);
            std::cout << *node->key << " ";
        }
    }

    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::minRecursive(Node<PessoaPorCPF*>* node) const {
        if (!node)
            return nullptr;
        if (node->left)
            return minRecursive(node->left);
        else
            return node;
    }

    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::maxRecursive(Node<PessoaPorCPF*>* node) const {
        if (!node)
            return nullptr;
        else if (node->right)
            return maxRecursive(node->right);
        else
            return node;
    }

    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::clear(Node<PessoaPorCPF*>* node) {
        if(node) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        return nullptr;
    }

    void BinarySearchTreeAVL<PessoaPorCPF*>::bShow(Node<PessoaPorCPF*>* node, std::string heranca) const {
        if(node && (node->left || node->right))
            BinarySearchTreeAVL<PessoaPorCPF*>::bShow(node->right , heranca + "r");
        for (int i = 0; i < (int) heranca.size() - 1; i++)
            std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if (heranca != "")
            std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
        if (!node) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << *node->key << std::endl;
        if (node && (node->left || node->right))
            this->bShow(node->left, heranca + "l");
    }

// public methods

    void BinarySearchTreeAVL<PessoaPorCPF*>::preOrder() {
        if (!this->root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            this->printPreOrderRecursive(this->root);
    }

    void BinarySearchTreeAVL<PessoaPorCPF*>::inOrder() {
        if (!this->root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            this->printInOrderRecursive(this->root);
    }

    
    void BinarySearchTreeAVL<PessoaPorCPF*>::postOrder() {
        if (!this->root)
            std::cout << "Empty tree" << std::endl;
        else
            this->printPostOrderRecursive(this->root);
    }

    void BinarySearchTreeAVL<PessoaPorCPF*>::bShow() { this->bShow(this->root, ""); }
    
    PessoaPorCPF* BinarySearchTreeAVL<PessoaPorCPF*>::getMin() { return this->minRecursive(this->root)->key; }
    
    PessoaPorCPF* BinarySearchTreeAVL<PessoaPorCPF*>::getMax() { return this->maxRecursive(this->root)->key; }
    
    Node<PessoaPorCPF*>* BinarySearchTreeAVL<PessoaPorCPF*>::getRaiz() { return this->root; }

    int BinarySearchTreeAVL<PessoaPorCPF*>::getSize() { return this->sizeRecursive(this->root); }

    void BinarySearchTreeAVL<PessoaPorCPF*>::find(PessoaPorCPF* value) { 
        Node<PessoaPorCPF*>* temp = this->findRecursive(this->root, value);
        if (!temp)
            std::cout << "CPF não encontrado" << std::endl;
        else
            std::cout << *temp->key;
    }

    void BinarySearchTreeAVL<PessoaPorCPF*>::insert(PessoaPorCPF* value) {
        this->root = insertRecursive(this->root, value);
    }































// PessoaPorNome

//constructor
    BinarySearchTreeAVL<PessoaPorNome*>::BinarySearchTreeAVL(): root(nullptr) {}

// destructor
    BinarySearchTreeAVL<PessoaPorNome*>::~BinarySearchTreeAVL() { this->clear(this->root); }

// private methods
    // Quando o nó é desbalanceado pela sua subárvore direita
    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::leftRotation(Node<PessoaPorNome*>* node) {
        Node<PessoaPorNome*>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        // recalcular as alturas de p e de u
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    // Quando o nó é desbalanceado pela sua subárvore esquerda
    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::rightRotation(Node<PessoaPorNome*>* node) {
        Node<PessoaPorNome*>* temp = node->left;
        node->left = temp->right;
        temp->right = node;        
        // recalcular as alturas de p e de u
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::findRecursive(Node<PessoaPorNome*>* node, PessoaPorNome* value) {
        if (!node)
            return nullptr;
        if (*node->key == *value) {
            this->findRecursive(node->left, value);
            std::cout << *node->key << std::endl;
            this->findRecursive(node->right, value);
            return node;
        }

        else if (*node->key > *value)
            return this->findRecursive(node->left, value);
        else
            return this->findRecursive(node->right, value);
    }

    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::insertRecursive(Node<PessoaPorNome*>* node, PessoaPorNome* value) {
        if (!node)
            return new Node<PessoaPorNome*>(value);
        else if (*value < *node->key)
            node->left = this->insertRecursive(node->left, value);
        else if (*value > *node->key || *value == *node->key)
            node->right = this->insertRecursive(node->right, value);
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        int balance = this->getBalance(node);

        if (balance > 1 && *value < *node->right->key) {
            node->right = this->rightRotation(node->right);
            node = this->leftRotation(node);
        }

        else if (balance > 1 && *value > *node->right->key)
            node = this->leftRotation(node);  
    
        else if (balance < -1 &&  *value < *node->left->key)
            node = this->rightRotation(node);

        else if (balance < -1 && *value > *node->left->key) {
            node->left = this->leftRotation(node->left);
            node = this->rightRotation(node);
        }

        return node;
    }
    
    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::deleteRecursive(Node<PessoaPorNome*>* node, PessoaPorNome* value) {
        if (!node)
            return nullptr;
        else if (node->key > value)
            return BinarySearchTreeAVL<PessoaPorNome*>::deleteRecursive(node->left, value);
        else if (node->key < value)
            return BinarySearchTreeAVL<PessoaPorNome*>::deleteRecursive(node->right, value);
        else {
            // não tem subárvore esquerda
            if (!node->left) {
                Node<PessoaPorNome*>* temp = node->right;
                delete node;
                return temp;
            }
            // não tem subárvore direita
            else if (!node->right) {
                Node<PessoaPorNome*>* temp = node->left;
                delete node;
                return temp;
            }
            // tem ambas as subárvores
            else {
                Node<PessoaPorNome*>* temp = BinarySearchTreeAVL<PessoaPorNome*>::minRecursive(node->right);
                node->key = temp->key;
                node->right = BinarySearchTreeAVL<PessoaPorNome*>::deleteRecursive(node->right, temp->key);
            }

            int balance = BinarySearchTreeAVL<PessoaPorNome*>::getBalance(node);

            if (balance > 1 && BinarySearchTreeAVL<PessoaPorNome*>::getBalance(node->left) >= 0)
                return BinarySearchTreeAVL<PessoaPorNome*>::rightRotation(node);

            if (balance > 1 && BinarySearchTreeAVL<PessoaPorNome*>::getBalance(node->left) < 0) {
                node->left = this->leftRotation(node->left);
                return this->rightRotation(node);
            }

            if (balance < -1 && BinarySearchTreeAVL<PessoaPorNome*>::getBalance(node->right) <= 0)
                return this->leftRotation(node);

            if (balance < -1 && BinarySearchTreeAVL<PessoaPorNome*>::getBalance(node->right) > 0) {
                node->right = this->rightRotation(node->right);
                return BinarySearchTreeAVL<PessoaPorNome*>::leftRotation(node);
            }

            return node;
        }
    }

    int BinarySearchTreeAVL<PessoaPorNome*>::getBalance(Node<PessoaPorNome*>* node) const {
        return this->height(node->right) - this->height(node->left);
    }

    int BinarySearchTreeAVL<PessoaPorNome*>::sizeRecursive(Node<PessoaPorNome*>* node) const {
        return !node ? 0 : 1 + this->sizeRecursive(node->left) + this->sizeRecursive(node->right);
    }

    void BinarySearchTreeAVL<PessoaPorNome*>::printPreOrderRecursive(Node<PessoaPorNome*>* node) const {
        if (node) {
            std::cout << *node->key << " ";
            this->printPreOrderRecursive(node->left);
            this->printPreOrderRecursive(node->right);
        }
    }
    void BinarySearchTreeAVL<PessoaPorNome*>::printInOrderRecursive(Node<PessoaPorNome*>* node) const {
        if (node) {
            this->printInOrderRecursive(node->left);
            std::cout << *node->key << " ";
            this->printInOrderRecursive(node->right);
        }
    }

    void BinarySearchTreeAVL<PessoaPorNome*>::printPostOrderRecursive(Node<PessoaPorNome*>* node) const {
        if (node) {
            this->printPostOrderRecursive(node->left);
            this->printPostOrderRecursive(node->right);
            std::cout << *node->key << " ";
        }
    }

    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::minRecursive(Node<PessoaPorNome*>* node) const {
        if (!node)
            return nullptr;
        else if (node->left)
            return this->minRecursive(node->left);
        else
            return node;
    }

    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::maxRecursive(Node<PessoaPorNome*>* node) const {
        if (!node)
            return nullptr;
        else if (node->right)
            return this->maxRecursive(node->right);
        else
            return node;
    }

    int BinarySearchTreeAVL<PessoaPorNome*>::height(Node<PessoaPorNome*>* node) const {
        return !node ? 0: node->height;
    }

    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::clear(Node<PessoaPorNome*>* node) {
        if(node) {
            node->left = this->clear(node->left);
            node->right = this->clear(node->right);
            delete node;
        }
        return nullptr;
    }
     void BinarySearchTreeAVL<PessoaPorNome*>::bShow(Node<PessoaPorNome*>* node, std::string heranca) const {
        if(node && (node->left || node->right))
            this->bShow(node->right , heranca + "r");
        for (int i = 0; i < (int) heranca.size() - 1; i++)
            std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if (heranca != "")
            std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
        if (!node) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << *node->key << std::endl;
        if (node && (node->left || node->right))
            this->bShow(node->left, heranca + "l");
    }

// public methods

    void BinarySearchTreeAVL<PessoaPorNome*>::preOrder() {
        if (!this->root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            this->printPreOrderRecursive(this->root);
    }

     void BinarySearchTreeAVL<PessoaPorNome*>::inOrder() {
        if (!this->root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            this->printInOrderRecursive(this->root);
    }

    
    void BinarySearchTreeAVL<PessoaPorNome*>::postOrder() {
        if (!this->root)
            std::cout << "Empty tree" << std::endl;
        else
            printPostOrderRecursive(this->root);
    }

    
    void BinarySearchTreeAVL<PessoaPorNome*>::insert(PessoaPorNome* value) {
        this->root = this->insertRecursive(this->root, value);
    }

    void BinarySearchTreeAVL<PessoaPorNome*>::bShow() {
        this->bShow(this->root, "");
    }
    
    PessoaPorNome* BinarySearchTreeAVL<PessoaPorNome*>::getMin() { return this->minRecursive(this->root)->key; }
    
    PessoaPorNome* BinarySearchTreeAVL<PessoaPorNome*>::getMax() { return this->maxRecursive(this->root)->key; }

    Node<PessoaPorNome*>* BinarySearchTreeAVL<PessoaPorNome*>::getRaiz() { return this->root; }
   
    int BinarySearchTreeAVL<PessoaPorNome*>::getSize() { return this->sizeRecursive(this->root); }
    
    void BinarySearchTreeAVL<PessoaPorNome*>::find(PessoaPorNome* value) { 
        std::string nome = PessoaPorNome::normalizarNome(PessoaPorNome::converter.from_bytes(value->getNome().append(value->getSobreNome())));
        Node<PessoaPorNome*>* temp = this->findRecursive(this->root, new PessoaPorNome(nome));
        if (!temp)
            std::cout << "Não há correspondências." << std::endl;
    }



























// PessoaPorDataDeNascimento

//constructor
    BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::BinarySearchTreeAVL(): root(nullptr) {}

// destructor
    BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::~BinarySearchTreeAVL() {
        BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::clear(this->root);
    }

// private methods
    int BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::height(Node<PessoaPorDataDeNascimento*>* node) const {
        return !node ? 0: node->height;
    }
    // Quando o nó é desbalanceado pela sua subárvore direita
    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::leftRotation(Node<PessoaPorDataDeNascimento*>* node) {
        Node<PessoaPorDataDeNascimento*>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        // recalcular as alturas de p e de u
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    // Quando o nó é desbalanceado pela sua subárvore esquerda
    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::rightRotation(Node<PessoaPorDataDeNascimento*>* node) {
        Node<PessoaPorDataDeNascimento*>* temp = node->left;
        node->left = temp->right;
        temp->right = node;        
        // recalcular as alturas de p e de u
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::insertRecursive(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value) {
    if (!this->root) {
        this->root = new Node<PessoaPorDataDeNascimento*>(value);
        return this->root;
    }
    Node<PessoaPorDataDeNascimento*>* iterator = this->root;
    while (iterator) {
        if (*value < *iterator->key) {
            if (!iterator->left) {
                iterator->left = new Node<PessoaPorDataDeNascimento*>(value);
                iterator->left->parent = iterator;
                break;
            }
            iterator = iterator->left;
        } 
        else if (*value > *iterator->key || *value == *iterator->key ) {
            if (!iterator->right) {
                iterator->right = new Node<PessoaPorDataDeNascimento*>(value);
                iterator->right->parent = iterator;
                break;
            }
            iterator = iterator->right;
        }
    }

    node->height = 1 + std::max(height(node->left), height(node->right));        
    int balance = getBalance(node);
    if (balance > 1 && *value < *node->right->key) {
        node->right = rightRotation(node->right);
        node = leftRotation(node);
    }

    else if (balance > 1 && *value > *node->right->key)
        node = leftRotation(node); 
    
    else if (balance < -1 &&  *value < *node->left->key)
        node = rightRotation(node);

    else if (balance < -1 && *value > *node->left->key) {
        node->left = leftRotation(node->left);
        node = rightRotation(node);
    }

    return node;
}
    
    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::deleteRecursive(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value) {
        if (!node)
            return nullptr;
        else if (*node->key > *value)
            return deleteRecursive(node->left, value);
        else if (*node->key < *value)
            return deleteRecursive(node->right, value);
        else {
            // não tem subárvore esquerda
            if (!node->left) {
                Node<PessoaPorDataDeNascimento*>* temp = node->right;
                delete node;
                return temp;
            }
            // não tem subárvore direita
            else if (!node->right) {
                Node<PessoaPorDataDeNascimento*>* temp = node->left;
                delete node;
                return temp;
            }
            // tem ambas as subárvores
            else {
                Node<PessoaPorDataDeNascimento*>* temp = minRecursive(node->right);
                node->key->getCPF() = temp->key->getCPF();
                node->right = deleteRecursive(node->right, temp->key);
            }

            node->height = 1 + std::max(height(node->left), height(node->right));

            int balance = getBalance(node);

            if (balance > 1 && getBalance(node->left) >= 0)
                return rightRotation(node);

            if (balance > 1 && getBalance(node->left) < 0) {
                node->left = leftRotation(node->left);
                return rightRotation(node);
            }

            if (balance < -1 && getBalance(node->right) <= 0)
                return leftRotation(node);

            if (balance < -1 && getBalance(node->right) > 0) {
                node->right = rightRotation(node->right);
                return leftRotation(node);
            }

            return node;
        }
    }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::findRecursive(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value) {
        if (!node)
            return nullptr;
        if (*node->key == *value)
            return node;
        else if (*node->key < *value && (!node->right))
            return node;
        else if (*node->key < *value && (node->right && (*node->right->key > *value) && (*sucessor(node)->key > *value)))
            return node;
        else if (*node->key > *value && (!node->left))
            return node;
        else if (*node->key > *value && (node->left && (*node->left->key > *value) && (*predecessor(node)->key < *value)))
            return node;
        else if (*node->key < *value)
            return this->findRecursive(node->right, value);  
        else    
            return this->findRecursive(node->left, value);               
    }   

    int BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::getBalance(Node<PessoaPorDataDeNascimento*>* node) const {
        return height(node->right) - height(node->left);
    }

    int BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::sizeRecursive(Node<PessoaPorDataDeNascimento*>* node) const {
        return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
    }

    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::printPreOrderRecursive(Node<PessoaPorDataDeNascimento*>* node) const {
        if (node) {
            std::cout << *node->key << " ";
            printPreOrderRecursive(node->left);
            printPreOrderRecursive(node->right);
        }
    }
    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::printInOrderRecursive(Node<PessoaPorDataDeNascimento*>* node) const {
        if (node) {
            printInOrderRecursive(node->left);
            std::cout << *node->key << " ";
            printInOrderRecursive(node->right);
        }
    }

    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::printPostOrderRecursive(Node<PessoaPorDataDeNascimento*>* node) const {
        if (node) {
            printPostOrderRecursive(node->left);
            printPostOrderRecursive(node->right);
            std::cout << *node->key << " ";
        }
    }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::minRecursive(Node<PessoaPorDataDeNascimento*>* node) const {
        if (!node)
            return nullptr;
        if (node->left)
            return minRecursive(node->left);
        else
            return node;
    }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::maxRecursive(Node<PessoaPorDataDeNascimento*>* node) const {
        if (!node)
            return nullptr;
        else if (node->right)
            return maxRecursive(node->right);
        else
            return node;
    }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::sucessor(Node<PessoaPorDataDeNascimento*>* node) {
        Node<PessoaPorDataDeNascimento*>* temp = findRecursive(this->root, minRecursive(node)->key);
        if (node->right) 
            return minRecursive(node->right);
        else {
            Node<PessoaPorDataDeNascimento*>* atual = node->parent;
            while (atual && node == atual->right) {
                node = atual;
                atual = atual->parent;
            }
            return atual ? atual : nullptr;
        }
    }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::predecessor(Node<PessoaPorDataDeNascimento*>* node) {
        Node<PessoaPorDataDeNascimento*>* temp = findRecursive(this->root, node->key);
        if (!temp)
            return nullptr;
        else if (*getMin()->key == *temp->key)
            return node;
        else if (node->left) 
            return maxRecursive(node->left);
        else {
            Node<PessoaPorDataDeNascimento*>* atual = node->parent;
            while (atual && node == atual->left) {
                node = atual;
                atual = atual->parent;
            }
            return atual ? atual : nullptr;
        }
    }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::clear(Node<PessoaPorDataDeNascimento*>* node) {
        if(node) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        return nullptr;
    }

    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::bShow(Node<PessoaPorDataDeNascimento*>* node, std::string heranca) const {
        if(node && (node->left || node->right))
            BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::bShow(node->right , heranca + "r");
        for (int i = 0; i < (int) heranca.size() - 1; i++)
            std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if (heranca != "")
            std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
        if (!node) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << *node->key << std::endl;
        if (node && (node->left || node->right))
            this->bShow(node->left, heranca + "l");
    }

// public methods

    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::preOrder() {
        if (!this->root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            this->printPreOrderRecursive(this->root);
    }

    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::inOrder() {
        if (!this->root) {
            std::cout << "Empty tree" << std::endl;
            return;
        }
        else
            this->printInOrderRecursive(this->root);
    }

    
    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::postOrder() {
        if (!this->root)
            std::cout << "Empty tree" << std::endl;
        else
            this->printPostOrderRecursive(this->root);
    }

    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::bShow() { this->bShow(this->root, ""); }
    
    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::getMin() { return this->minRecursive(this->root); }
    
    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::getMax() { return this->maxRecursive(this->root); }

    Node<PessoaPorDataDeNascimento*>* BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::getRaiz() { return this->root; }

    
    int BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::getSize() { return this->sizeRecursive(this->root); }
    
    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::find(Node<PessoaPorDataDeNascimento*>* node, PessoaPorDataDeNascimento* value) { 
        if (*node->key > *value || *value < *node->key) {
            std::cout << "Intervalo inválido" << std::endl;
            return;
        }
        PessoaPorDataDeNascimento* limitanteInferior = findRecursive(this->root, node->key)->key;
        PessoaPorDataDeNascimento* limitanteSuperior = findRecursive(this->root, value)->key;
        std::stack<Node<PessoaPorDataDeNascimento*>*> pilha;
        Node<PessoaPorDataDeNascimento*>* iterator = this->root;
        while (iterator || !pilha.empty()) {
            while (iterator) {
                pilha.push(iterator);
                iterator = iterator->left;
            }

            if (!pilha.empty()) {
                iterator = pilha.top();
                pilha.pop();

                if (*iterator->key > *limitanteSuperior)
                    break;

                if (*iterator->key > *limitanteInferior || *iterator->key == *limitanteInferior)
                    std::cout << *iterator->key << " ";

                iterator = iterator->right;
            }
        }
    }
    
    void BinarySearchTreeAVL<PessoaPorDataDeNascimento*>::insert(PessoaPorDataDeNascimento* value) {
        this->root = insertRecursive(this->root, value);
    }
#endif