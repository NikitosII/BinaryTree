#pragma once
#include <iostream> 
//  В этом файле объявляется структура Node, которая представляет узел дерева.

struct Node {
    int data;
    Node* left;
    Node* right;

    Node();
    Node(int num);
};
