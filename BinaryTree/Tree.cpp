#include<iostream> 
#include "Tree.h" 

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    delete_tree(root);
}

// Удаление эл-тов бинарного дерева
void Tree::delete_tree(Node* node) {
    if (node != nullptr) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

// Функция добавления нового элемента со значением value в дерево
// Если дерево пустое, создается корневой узел с переданным значением.
// В противном случае вызывается вспомогательная функция insertHelp(Node * node, int value),
// которая рекурсивно ищет место для нового элемента в дереве.
void Tree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
    }
    else {
        insertHelp(root, value);
    }
}

// Функция, рекурсивно ищущая место для добавления нового эл-та
// Если значение равно значению текущего узла, ничего не делается.
// Если значение меньше значения текущего узла, перемещаемся влево по ветви
// Если значение больше значения текущего узла, перемещаемся вправо по ветви
// Когда наконец нашли место для нашего эл-та, добавляем его в дерево
void Tree::insertHelp(Node* node, int value) {
    if (value == node->data) {
        return;
    }

    if (value < node->data) {
        if (node->left == nullptr) {
            node->left = new Node(value);
        }
        else {
            insertHelp(node->left, value);
        }
    }
    else {
        if (node->right == nullptr) {
            node->right = new Node(value);
        }
        else {
            insertHelp(node->right, value);
        }
    }
}


// Функция для вывода бинарного дерева в консоль (вертикально)
void Tree::printTreeH(Node* root, std::string prefix, bool isLeft) {
    if (root != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        std::cout << root->data << std::endl;
        printTreeH(root->right, prefix + (isLeft ? "|   " : "    "), true);
        printTreeH(root->left, prefix + (isLeft ? "|   " : "    "), false);

    }
}
// Функция вызова вывода 1
void Tree::printTree() {
    return printTreeH(root, "", true);
}

//Симметричный обход
void Tree::InfHelp(Node* root) {
    if (root != nullptr) {
        InfHelp(root->left);
        std::cout << root->data << " ";
        InfHelp(root->right);
    }
}

void Tree::Inf() {
    return InfHelp(root);
}

//Прямой обход
void Tree::PrefHelp(Node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        PrefHelp(root->left);
        PrefHelp(root->right);
    }
}

void Tree::Pref() {
    return PrefHelp(root);
}

//Обратный обход
void Tree::PostfHelp(Node* root) {
    if (root != nullptr) {
        PostfHelp(root->left);
        PostfHelp(root->right);
        std::cout << root->data << " ";
    }
}

void Tree::Postf() {
    return PostfHelp(root);
}