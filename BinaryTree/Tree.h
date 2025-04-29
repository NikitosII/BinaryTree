#pragma once
#include "Node.h" 
//  В этом файле объявляется класс Tree, который представляет структуру бинарного дерева поиска.

class Tree {
private:
    Node* root;
    void delete_tree(Node* root);
public:
    Tree();
    ~Tree();
    void printTreeH(Node* root, std::string prefix, bool isLeft);
    void printTree();
    void insert(int value);
    void insertHelp(Node* node, int value);
    void InfHelp(Node* root);
    void Inf();
    void PrefHelp(Node* root);
    void Pref();
    void PostfHelp(Node* root);
    void Postf();


};