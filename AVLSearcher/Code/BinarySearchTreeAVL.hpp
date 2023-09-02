#ifndef BINARYSEARCHTREEAVL_HPP
#define BINARYSEARCHTREEAVL_HPP

#include "Node.hpp" 

// An AVL tree is a BST that has the balancing factor, i.e.
// the difference between the heights of the left and right subtrees is at most 1.

// using the template for different key types
int contador = 0;
template <typename T>

class BinarySearchTreeAVL {
private:
    Node<T>* root;
    void bShow(Node<T>* node, std::string str) const;
    int sizeRecursive(Node<T>* node) const;
    int getBalance(Node<T>* node) const;
    int height(Node<T>* node) const;
    Node<T>* findRecursive(Node<T>* node, T value);
    Node<T>* minRecursive(Node<T>* node) const;
    Node<T>* maxRecursive(Node<T>* node) const;
    Node<T>* insertRecursive(Node<T>* node, T value);
    Node<T>* rightRotation(Node<T>* node);
    Node<T>* leftRotation(Node<T>* node);
    Node<T>* clear(Node<T>* node);
public:
    BinarySearchTreeAVL<T>();
    ~BinarySearchTreeAVL<T>();
    void insert(T value);
    void bShow();
    void deleteKey(T value);
    void find(T value);
    Node<T>* clear();    
};


template <>

class BinarySearchTreeAVL<PersonByCPF*> {
private:
    Node<PersonByCPF*>* root;
    void bShow(Node<PersonByCPF*>* node, std::string str) const;
    int sizeRecursive(Node<PersonByCPF*>* node) const;
    int height(Node<PersonByCPF*>* node) const;
    int getBalance(Node<PersonByCPF*>* node) const;
    Node<PersonByCPF*>* findRecursive(Node<PersonByCPF*>* node, PersonByCPF* value);
    Node<PersonByCPF*>* insertRecursive(Node<PersonByCPF*>* node, PersonByCPF* value);
    Node<PersonByCPF*>* rightRotation(Node<PersonByCPF*>* node);
    Node<PersonByCPF*>* leftRotation(Node<PersonByCPF*>* node);
    Node<PersonByCPF*>* clear(Node<PersonByCPF*>* node);
public:
    BinarySearchTreeAVL<PersonByCPF*>();
    ~BinarySearchTreeAVL<PersonByCPF*>();
    void insert(PersonByCPF* value);
    void bShow();
    void find(PersonByCPF* value);
    Node<PersonByCPF*>* clear();
};


template <>

class BinarySearchTreeAVL<PersonByName*> {
private:
    Node<PersonByName*>* root;
    void bShow(Node<PersonByName*>* node, std::string str) const;
    int height(Node<PersonByName*>* node) const;
    int getBalance(Node<PersonByName*>* node) const;
    Node<PersonByName*>* findRecursive(Node<PersonByName*>* node, PersonByName* value);
    Node<PersonByName*>* minRecursive(Node<PersonByName*>* node) const;
    Node<PersonByName*>* maxRecursive(Node<PersonByName*>* node) const; 
    Node<PersonByName*>* insertRecursive(Node<PersonByName*>* node, PersonByName* value);
    Node<PersonByName*>* rightRotation(Node<PersonByName*>* node);
    Node<PersonByName*>* leftRotation(Node<PersonByName*>* node);
    Node<PersonByName*>* clear(Node<PersonByName*>* node);

public:
    BinarySearchTreeAVL<PersonByName*>();
    ~BinarySearchTreeAVL<PersonByName*>();
    void insert(PersonByName* value);
    void bShow();
    void find(PersonByName* value);
    Node<PersonByName*>* clear();
};


template <>

class BinarySearchTreeAVL<PersonByBirthDate*> {
private:
    Node<PersonByBirthDate*>* root;
    void bShow(Node<PersonByBirthDate*>* node, std::string str) const;
    int sizeRecursive(Node<PersonByBirthDate*>* node) const;
    int height(Node<PersonByBirthDate*>* node) const;
    int getBalance(Node<PersonByBirthDate*>* node) const;
    Node<PersonByBirthDate*>* findRecursive(Node<PersonByBirthDate*>* node, PersonByBirthDate* value);
    Node<PersonByBirthDate*>* minRecursive(Node<PersonByBirthDate*>* node) const;
    Node<PersonByBirthDate*>* maxRecursive(Node<PersonByBirthDate*>* node) const; 
    Node<PersonByBirthDate*>* insertRecursive(Node<PersonByBirthDate*>* node, PersonByBirthDate* value);
    Node<PersonByBirthDate*>* rightRotation(Node<PersonByBirthDate*>* node);
    Node<PersonByBirthDate*>* leftRotation(Node<PersonByBirthDate*>* node);
    Node<PersonByBirthDate*>* clear(Node<PersonByBirthDate*>* node);
    Node<PersonByBirthDate*>* sucessor(Node<PersonByBirthDate*>* node);
    Node<PersonByBirthDate*>* predecessor(Node<PersonByBirthDate*>* node);
public:
    BinarySearchTreeAVL<PersonByBirthDate*>();
    ~BinarySearchTreeAVL<PersonByBirthDate*>();
    void insert(PersonByBirthDate* value);
    void bShow();
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteKey(PersonByBirthDate* value);
    int getSize();
    Node<PersonByBirthDate*>* getMin();
    Node<PersonByBirthDate*>* getMax();
    Node<PersonByBirthDate*>* getRaiz();
    void find(PersonByBirthDate* value);
    void find(Node<PersonByBirthDate*>* node, PersonByBirthDate* value);
    Node<PersonByBirthDate*>* clear();
};

// PersonByCPF

//constructor
    BinarySearchTreeAVL<PersonByCPF*>::BinarySearchTreeAVL(): root(nullptr) {}

// destructor
    BinarySearchTreeAVL<PersonByCPF*>::~BinarySearchTreeAVL() {
        BinarySearchTreeAVL<PersonByCPF*>::clear(this->root);
    }

// private methods
    int BinarySearchTreeAVL<PersonByCPF*>::height(Node<PersonByCPF*>* node) const {
        return !node ? 0: node->height;
    }

    Node<PersonByCPF*>* BinarySearchTreeAVL<PersonByCPF*>::leftRotation(Node<PersonByCPF*>* node) {
        Node<PersonByCPF*>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PersonByCPF*>* BinarySearchTreeAVL<PersonByCPF*>::rightRotation(Node<PersonByCPF*>* node) {
        Node<PersonByCPF*>* temp = node->left;
        node->left = temp->right;
        temp->right = node;        
        
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PersonByCPF*>* BinarySearchTreeAVL<PersonByCPF*>::insertRecursive(Node<PersonByCPF*>* node, PersonByCPF* value) {
        if (!node) 
            return new Node<PersonByCPF*>(value);

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

    Node<PersonByCPF*>* BinarySearchTreeAVL<PersonByCPF*>::findRecursive(Node<PersonByCPF*>* node, PersonByCPF* value) {
        if (!node)
            return nullptr;
        else if (*node->key == *value)
            return node;
        else if (*node->key < *value)
            return findRecursive(node->right, value);
        else
            return findRecursive(node->left, value);
    }

    int BinarySearchTreeAVL<PersonByCPF*>::getBalance(Node<PersonByCPF*>* node) const {
        return height(node->right) - height(node->left);
    }

    int BinarySearchTreeAVL<PersonByCPF*>::sizeRecursive(Node<PersonByCPF*>* node) const {
        return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
    }

    Node<PersonByCPF*>* BinarySearchTreeAVL<PersonByCPF*>::clear(Node<PersonByCPF*>* node) {
        if(node) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        return nullptr;
    }

    void BinarySearchTreeAVL<PersonByCPF*>::bShow(Node<PersonByCPF*>* node, std::string heritage) const {
        if(node && (node->left || node->right))
            BinarySearchTreeAVL<PersonByCPF*>::bShow(node->right , heritage + "r");
        for (int i = 0; i < (int) heritage.size() - 1; i++)
            std::cout << (heritage[i] != heritage[i + 1] ? "│   " : "    ");
        if (heritage != "")
            std::cout << (heritage.back() == 'r' ? "┌───" : "└───");
        if (!node) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << *node->key << std::endl;
        if (node && (node->left || node->right))
            this->bShow(node->left, heritage + "l");
    }

// public methods

    void BinarySearchTreeAVL<PersonByCPF*>::bShow() { this->bShow(this->root, ""); }

    void BinarySearchTreeAVL<PersonByCPF*>::find(PersonByCPF* value) { 
        Node<PersonByCPF*>* temp = this->findRecursive(this->root, value);
        if (!temp)
            std::cout << "Not found CPF" << std::endl;
        else
            std::cout << *temp->key;
    }

    void BinarySearchTreeAVL<PersonByCPF*>::insert(PersonByCPF* value) {        
        this->root = insertRecursive(this->root, value);
    }































// PersonByName

//constructor
    BinarySearchTreeAVL<PersonByName*>::BinarySearchTreeAVL(): root(nullptr) {}

// destructor
    BinarySearchTreeAVL<PersonByName*>::~BinarySearchTreeAVL() { this->clear(this->root); }

// private methods
    Node<PersonByName*>* BinarySearchTreeAVL<PersonByName*>::leftRotation(Node<PersonByName*>* node) {
        Node<PersonByName*>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PersonByName*>* BinarySearchTreeAVL<PersonByName*>::rightRotation(Node<PersonByName*>* node) {
        Node<PersonByName*>* temp = node->left;
        node->left = temp->right;
        temp->right = node;        
        
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PersonByName*>* BinarySearchTreeAVL<PersonByName*>::findRecursive(Node<PersonByName*>* node, PersonByName* value) {
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

    Node<PersonByName*>* BinarySearchTreeAVL<PersonByName*>::insertRecursive(Node<PersonByName*>* node, PersonByName* value) {
        if (!node)
            return new Node<PersonByName*>(value);
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

    int BinarySearchTreeAVL<PersonByName*>::getBalance(Node<PersonByName*>* node) const {
        return this->height(node->right) - this->height(node->left);
    }

    int BinarySearchTreeAVL<PersonByName*>::height(Node<PersonByName*>* node) const {
        return !node ? 0: node->height;
    }

    Node<PersonByName*>* BinarySearchTreeAVL<PersonByName*>::clear(Node<PersonByName*>* node) {
        if(node) {
            node->left = this->clear(node->left);
            node->right = this->clear(node->right);
            delete node;
        }
        return nullptr;
    }
     void BinarySearchTreeAVL<PersonByName*>::bShow(Node<PersonByName*>* node, std::string heritage) const {
        if(node && (node->left || node->right))
            this->bShow(node->right , heritage + "r");
        for (int i = 0; i < (int) heritage.size() - 1; i++)
            std::cout << (heritage[i] != heritage[i + 1] ? "│   " : "    ");
        if (heritage != "")
            std::cout << (heritage.back() == 'r' ? "┌───" : "└───");
        if (!node) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << *node->key << std::endl;
        if (node && (node->left || node->right))
            this->bShow(node->left, heritage + "l");
    }

// public methods

    void BinarySearchTreeAVL<PersonByName*>::insert(PersonByName* value) {
        this->root = this->insertRecursive(this->root, value);
    }

    void BinarySearchTreeAVL<PersonByName*>::bShow() {
        this->bShow(this->root, "");
    }
    
    void BinarySearchTreeAVL<PersonByName*>::find(PersonByName* value) { 
        std::string name = PersonByName::normalizeName(PersonByName::convert.from_bytes(value->getName().append(value->getSurname())));
        Node<PersonByName*>* temp = this->findRecursive(this->root, new PersonByName(name));
        if (!temp)
            std::cout << "There is no match." << std::endl;
    }



























// PersonByBirthDate

//constructor
    BinarySearchTreeAVL<PersonByBirthDate*>::BinarySearchTreeAVL(): root(nullptr) {}

// destructor
    BinarySearchTreeAVL<PersonByBirthDate*>::~BinarySearchTreeAVL() {
        BinarySearchTreeAVL<PersonByBirthDate*>::clear(this->root);
    }

// private methods
    int BinarySearchTreeAVL<PersonByBirthDate*>::height(Node<PersonByBirthDate*>* node) const {
        return !node ? 0: node->height;
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::leftRotation(Node<PersonByBirthDate*>* node) {
        Node<PersonByBirthDate*>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::rightRotation(Node<PersonByBirthDate*>* node) {
        Node<PersonByBirthDate*>* temp = node->left;
        node->left = temp->right;
        temp->right = node;        
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::insertRecursive(Node<PersonByBirthDate*>* node, PersonByBirthDate* value) {
    if (!this->root) {
        this->root = new Node<PersonByBirthDate*>(value);
        return this->root;
    }
    Node<PersonByBirthDate*>* iterator = this->root;
    while (iterator) {
        if (*value < *iterator->key) {
            if (!iterator->left) {
                iterator->left = new Node<PersonByBirthDate*>(value);
                iterator->left->parent = iterator;
                break;
            }
            iterator = iterator->left;
        } 
        else if (*value > *iterator->key || *value == *iterator->key ) {
            if (!iterator->right) {
                iterator->right = new Node<PersonByBirthDate*>(value);
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
    
    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::findRecursive(Node<PersonByBirthDate*>* node, PersonByBirthDate* value) {
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

    int BinarySearchTreeAVL<PersonByBirthDate*>::getBalance(Node<PersonByBirthDate*>* node) const {
        return height(node->right) - height(node->left);
    }

    int BinarySearchTreeAVL<PersonByBirthDate*>::sizeRecursive(Node<PersonByBirthDate*>* node) const {
        return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::minRecursive(Node<PersonByBirthDate*>* node) const {
        if (!node)
            return nullptr;
        if (node->left)
            return minRecursive(node->left);
        else
            return node;
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::maxRecursive(Node<PersonByBirthDate*>* node) const {
        if (!node)
            return nullptr;
        else if (node->right)
            return maxRecursive(node->right);
        else
            return node;
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::sucessor(Node<PersonByBirthDate*>* node) {
        Node<PersonByBirthDate*>* temp = findRecursive(this->root, minRecursive(node)->key);
        if (node->right) 
            return minRecursive(node->right);
        else {
            Node<PersonByBirthDate*>* current = node->parent;
            while (current && node == current->right) {
                node = current;
                current = current->parent;
            }
            return current ? current : nullptr;
        }
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::predecessor(Node<PersonByBirthDate*>* node) {
        Node<PersonByBirthDate*>* temp = findRecursive(this->root, node->key);
        if (!temp)
            return nullptr;
        else if (*getMin()->key == *temp->key)
            return node;
        else if (node->left) 
            return maxRecursive(node->left);
        else {
            Node<PersonByBirthDate*>* current = node->parent;
            while (current && node == current->left) {
                node = current;
                current = current->parent;
            }
            return current ? current : nullptr;
        }
    }

    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::clear(Node<PersonByBirthDate*>* node) {
        if(node) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        return nullptr;
    }

    void BinarySearchTreeAVL<PersonByBirthDate*>::bShow(Node<PersonByBirthDate*>* node, std::string heritage) const {
        if(node && (node->left || node->right))
            BinarySearchTreeAVL<PersonByBirthDate*>::bShow(node->right , heritage + "r");
        for (int i = 0; i < (int) heritage.size() - 1; i++)
            std::cout << (heritage[i] != heritage[i + 1] ? "│   " : "    ");
        if (heritage != "")
            std::cout << (heritage.back() == 'r' ? "┌───" : "└───");
        if (!node) {
            std::cout << "#" << std::endl;
            return;
        }
        std::cout << *node->key << std::endl;
        if (node && (node->left || node->right))
            this->bShow(node->left, heritage + "l");
    }

// public methods


    void BinarySearchTreeAVL<PersonByBirthDate*>::bShow() { this->bShow(this->root, ""); }
    
    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::getMin() { return this->minRecursive(this->root); }
    
    Node<PersonByBirthDate*>* BinarySearchTreeAVL<PersonByBirthDate*>::getMax() { return this->maxRecursive(this->root); }
    
    int BinarySearchTreeAVL<PersonByBirthDate*>::getSize() { return this->sizeRecursive(this->root); }
    
    void BinarySearchTreeAVL<PersonByBirthDate*>::find(Node<PersonByBirthDate*>* node, PersonByBirthDate* value) { 
        if (*node->key > *value || *value < *node->key) {
            std::cout << "Invalid range" << std::endl;
            return;
        }
        PersonByBirthDate* lowerBound = findRecursive(this->root, node->key)->key;
        PersonByBirthDate* upperBound = findRecursive(this->root, value)->key;
        std::stack<Node<PersonByBirthDate*>*> stack;
        Node<PersonByBirthDate*>* iterator = this->root;
        while (iterator || !stack.empty()) {
            while (iterator) {
                stack.push(iterator);
                iterator = iterator->left;
            }

            if (!stack.empty()) {
                iterator = stack.top();
                stack.pop();

                if (*iterator->key > *upperBound)
                    break;

                if (*iterator->key > *lowerBound || *iterator->key == *lowerBound)
                    std::cout << *iterator->key << " ";

                iterator = iterator->right;
            }
        }
    }
    
    void BinarySearchTreeAVL<PersonByBirthDate*>::insert(PersonByBirthDate* value) { 
        this->root = insertRecursive(this->root, value); 
    }

#endif