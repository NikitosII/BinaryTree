#pragma once
#include <iostream> 
//  � ���� ����� ����������� ��������� Node, ������� ������������ ���� ������.

struct Node {
    int data;
    Node* left;
    Node* right;

    Node();
    Node(int num);
};
