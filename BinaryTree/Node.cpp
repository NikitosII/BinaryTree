#include "Node.h" 
#include <iostream> 
// ¬ этом файле реализуютс€ методы конструкторов структуры Node.
//  онструктор без параметров инициализирует данные узла NULL, а указатели на ветви как nullptr. 
//  онструктор с параметром инициализирует данные узла переданным значением и указатели на ветви как nullptr.
Node::Node() {
    data = NULL;
    left = nullptr;
    right = nullptr;
}

Node::Node(int num) {
    data = num;
    left = nullptr;
    right = nullptr;
}