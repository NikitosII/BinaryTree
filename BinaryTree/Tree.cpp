#include<iostream> 
#include "Tree.h" 

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    delete_tree(root);
}

// �������� ��-��� ��������� ������
void Tree::delete_tree(Node* node) {
    if (node != nullptr) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

// ������� ���������� ������ �������� �� ��������� value � ������
// ���� ������ ������, ��������� �������� ���� � ���������� ���������.
// � ��������� ������ ���������� ��������������� ������� insertHelp(Node * node, int value),
// ������� ���������� ���� ����� ��� ������ �������� � ������.
void Tree::insert(int value) {
    if (root == nullptr) {
        root = new Node(value);
    }
    else {
        insertHelp(root, value);
    }
}

// �������, ���������� ������ ����� ��� ���������� ������ ��-��
// ���� �������� ����� �������� �������� ����, ������ �� ��������.
// ���� �������� ������ �������� �������� ����, ������������ ����� �� �����
// ���� �������� ������ �������� �������� ����, ������������ ������ �� �����
// ����� ������� ����� ����� ��� ������ ��-��, ��������� ��� � ������
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


// ������� ��� ������ ��������� ������ � ������� (�����������)
void Tree::printTreeH(Node* root, std::string prefix, bool isLeft) {
    if (root != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        std::cout << root->data << std::endl;
        printTreeH(root->right, prefix + (isLeft ? "|   " : "    "), true);
        printTreeH(root->left, prefix + (isLeft ? "|   " : "    "), false);

    }
}
// ������� ������ ������ 1
void Tree::printTree() {
    return printTreeH(root, "", true);
}

//������������ �����
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

//������ �����
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

//�������� �����
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