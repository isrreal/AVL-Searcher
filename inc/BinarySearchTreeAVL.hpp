#ifndef BINARYSEARCHTREEAVL_HPP
#define BINARYSEARCHTREEAVL_HPP

#include "Node.hpp" 

// An AVL tree is a BST that has the balancing factor, i.e.
// the difference between the heights of the left and right subtrees is at most 1.

// using the template for different key types

template <typename T>

class BinarySearchTreeAVL {
private:
    Node<T>* root;
    void bShow(Node<T>* node, std::string str) const;
    size_t sizeRecursive(Node<T>* node) const;
    short getBalance(Node<T>* node) const;
    size_t height(Node<T>* node) const;
    Node<T>* findRecursive(Node<T>* node, const T& value);
    Node<T>* minRecursive(Node<T>* node) const;
    Node<T>* maxRecursive(Node<T>* node) const;
    Node<T>* insertRecursive(Node<T>* node, T value);
    Node<T>* rightRotation(Node<T>* node);
    Node<T>* leftRotation(Node<T>* node);
    Node<T>* clear(Node<T>* node);
    
    Node<T>* sucessor(Node<T>* node);
    Node<T>* predecessor(Node<T>* node);
public:
    BinarySearchTreeAVL<T>();
    ~BinarySearchTreeAVL<T>();
    void insert(T value);
    void bShow();
    void deleteKey(T value);
    Node<T>* getMin();
    Node<T>* getMax();
    size_t getSize();
    void find(T value);
    void find(T lower_value, T upper_value);
    void find(Node<T>* lower_value, T upper_value);
    Node<T>* clear();    
};

//constructor
	template <typename T>
    BinarySearchTreeAVL<T>::BinarySearchTreeAVL(): root(nullptr) {}

// destructor
	template <typename T>
    BinarySearchTreeAVL<T>::~BinarySearchTreeAVL() {
        BinarySearchTreeAVL<T>::clear(this->root);
    }

// private methods
	template <typename T>
    size_t BinarySearchTreeAVL<T>::height(Node<T>* node) const {
        return !node ? 0: node->height;
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::leftRotation(Node<T>* node) {
        Node<T>* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::rightRotation(Node<T>* node) {
        Node<T>* temp = node->left;
        node->left = temp->right;
        temp->right = node;        
        
        node->height = 1 + std::max(this->height(node->left), this->height(node->right));
        temp->height = 1 + std::max(this->height(temp->left), this->height(temp->right));
        return temp;
    }

	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::insertRecursive(Node<T>* node, T value) {
        if (!node) {
            return new Node<T>(value);
		}
        else if (value > node->key) {
            node->right = insertRecursive(node->right, value);
        }
        else if (value < node->key) {
            node->left = insertRecursive(node->left, value);
        }
        else {
            return node;
		}
		
        node->height = 1 + std::max(height(node->left), height(node->right));        
        short balance = getBalance(node);

        if (balance > 1 && value < node->right->key) {
            node->right = rightRotation(node->right);
            node = leftRotation(node);
        }

        else if (balance > 1 && value > node->right->key) {
            node = leftRotation(node); 
        }
        
        else if (balance < -1 &&  value < node->left->key) {
            node = rightRotation(node);
        }

        else if (balance < -1 && value > node->left->key) {
            node->left = leftRotation(node->left);
            node = rightRotation(node);
        }

        return node;
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::sucessor(Node<T>* node) {
        if (node->right) {
            return minRecursive(node->right);
        }
        else {
            Node<T>* current = node->parent;
            while (current && node == current->right) {
                node = current;
                current = current->parent;
            }
            return current ? current : nullptr;
        }
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::predecessor(Node<T>* node) {
        Node<T>* temp = findRecursive(this->root, node->key);
        if (!temp) {
            return nullptr;
        }
        else if (getMin()->key == temp->key) {
            return node;
        }
        else if (node->left) {
            return maxRecursive(node->left);
        }
        else {
            Node<T>* current = node->parent;
            while (current && node == current->left) {
                node = current;
                current = current->parent;
            }
            return current ? current : nullptr;
        }
    }
    
	template <typename T>
    short BinarySearchTreeAVL<T>::getBalance(Node<T>* node) const {
        return height(node->right) - height(node->left);
    }
    
	template <typename T>
    size_t BinarySearchTreeAVL<T>::sizeRecursive(Node<T>* node) const {
        return !node ? 0 : 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::clear(Node<T>* node) {
        if(node) {
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
        }
        
        return nullptr;
    }
    
	template <typename T>
    void BinarySearchTreeAVL<T>::bShow(Node<T>* node, std::string heritage) const {
        if(node && (node->left || node->right))
            BinarySearchTreeAVL<T>::bShow(node->right , heritage + "r");
        for (int i = 0; i < (int) heritage.size() - 1; i++)
            std::cout << (heritage[i] != heritage[i + 1] ? "│   " : "    ");
        if (heritage != "") {
            std::cout << (heritage.back() == 'r' ? "┌───" : "└───");
        }
        if (!node) {
            std::cout << "#\n";
            return;
        }
        std::cout << node->key << '\n';
        if (node && (node->left || node->right)) {
            this->bShow(node->left, heritage + "l");
        }
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::minRecursive(Node<T>* node) const {
        if (!node) {
            return nullptr;
        }  
        if (node->left) {
            return minRecursive(node->left);
        }
        else {
            return node;
        }
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::maxRecursive(Node<T>* node) const {
        if (!node) {
            return nullptr;
        }
        else if (node->right) {
            return maxRecursive(node->right);
        }
        else {
            return node;
        }
    }
    
    template<>
	Node<PersonByCPF>* BinarySearchTreeAVL<PersonByCPF>::findRecursive(Node<PersonByCPF>* node, const PersonByCPF& value) {
        if (!node)
            return nullptr;
        else if (node->key == value)
            return node;
        else if (node->key < value)
            return findRecursive(node->right, value);
        else
            return findRecursive(node->left, value);
    }
    
    template<>
    Node<PersonByName>* BinarySearchTreeAVL<PersonByName>::findRecursive(Node<PersonByName>* node, const PersonByName& value) {
        if (!node) {
            return nullptr;
        }

        if (node->key == value) {
            this->findRecursive(node->left, value);
            std::cout << node->key << '\n';
            this->findRecursive(node->right, value);
            return node;
        }

        else if (node->key > value)
            return this->findRecursive(node->left, value);
        else
            return this->findRecursive(node->right, value);
    }
    
    template<>
    Node<PersonByBirthDate>* BinarySearchTreeAVL<PersonByBirthDate>::findRecursive(Node<PersonByBirthDate>* node, const PersonByBirthDate& value) {
        if (!node) {
            return nullptr;
        }
        if (node->key == value) {
            return node;
        }
        else if (node->key < value && (!node->right)) {
            return node;
        }
        else if (node->key < value && (node->right && (node->right->key > value) && (sucessor(node)->key > value))) {
            return node;
        }
        else if (node->key > value && (!node->left)) {
            return node;
        }
        else if (node->key > value && (node->left && (node->left->key > value) && (predecessor(node)->key < value))) {
            return node;
        }
        else if (node->key < value) {
            return this->findRecursive(node->right, value);  
        }
        else {
            return this->findRecursive(node->left, value);     
        }          
    } 
   	
    template<>
    void BinarySearchTreeAVL<PersonByCPF>::find(PersonByCPF value) { 
        Node<PersonByCPF>* temp = this->findRecursive(this->root, value);
        if (!temp) {
            std::cout << "Not found CPF\n";
        }
        else {
            std::cout << temp->key;
        }
    }
    
    template<>
    void BinarySearchTreeAVL<PersonByName>::find(PersonByName value) { 
        std::string name = PersonByName::normalizeName(PersonByName::convert.from_bytes(value.getName().append(value.getSurname())));
        Node<PersonByName>* temp = this->findRecursive(this->root, PersonByName(name));
        if (!temp) {
            std::cout << "There is no match.\n";
        }
    }
    	
    template<>
    void BinarySearchTreeAVL<PersonByBirthDate>::find(PersonByBirthDate lower_value, PersonByBirthDate upper_value) { 
    	if (lower_value > upper_value || upper_value < lower_value) {
            std::cout << "Invalid range\n";
            return;
        }

        PersonByBirthDate lowerBound = findRecursive(this->root, lower_value)->key;
        PersonByBirthDate upperBound = findRecursive(this->root, upper_value)->key;
        std::stack<Node<PersonByBirthDate>*> stack;
        Node<PersonByBirthDate>* iterator = this->root;

        while (iterator || !stack.empty()) {
            while (iterator) {
                stack.push(iterator);
                iterator = iterator->left;
            }

            if (!stack.empty()) {
                iterator = stack.top();
                stack.pop();

                if (iterator->key > upperBound) {
                    break;
                }

                if (iterator->key > lowerBound || iterator->key == lowerBound) {
                    std::cout << iterator->key << " ";
                }

                iterator = iterator->right;
            }
        }
    }

// public methods

	template <typename T>
    void BinarySearchTreeAVL<T>::bShow() { this->bShow(this->root, ""); }

	template <typename T>
    void BinarySearchTreeAVL<T>::find(T value) { 
        Node<T>* temp = this->findRecursive(this->root, value);
        if (!temp) {
            std::cout << "Not found\n";
        }
        
        else {
            std::cout << temp->key;
        }
    }
    
	template <typename T>
    void BinarySearchTreeAVL<T>::insert(T value) {        
        this->root = insertRecursive(this->root, value);
    }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::getMin() { return this->minRecursive(root); }
    
	template <typename T>
    Node<T>* BinarySearchTreeAVL<T>::getMax() { return this->maxRecursive(root); }
    
	template <typename T>
    size_t BinarySearchTreeAVL<T>::getSize() { return this->sizeRecursive(root); }

#endif
