#include "Node.h" 
#include <iostream> 
// � ���� ����� ����������� ������ ������������� ��������� Node.
// ����������� ��� ���������� �������������� ������ ���� NULL, � ��������� �� ����� ��� nullptr. 
// ����������� � ���������� �������������� ������ ���� ���������� ��������� � ��������� �� ����� ��� nullptr.
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