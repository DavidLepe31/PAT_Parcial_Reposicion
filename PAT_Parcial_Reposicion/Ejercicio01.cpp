#include "Ejercicio01.h"
#include<cmath>
#include<string>
Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
    int sum = 0, i = 0;
    std::string suma = "";
    std::string digit = "";
    int num1 = 0, num2 = 0;
    Node<int>* tmp = l1;
    Node<int>* tmp2 = l2;
    Node<int>* NewNode = new Node<int>();
    Node<int>*headf = NewNode;
    i = 1;
    while (i <= sizeL1)
    {

        num1 += tmp->value * pow(10, sizeL1 - i);
        tmp = tmp->next;
        i++;
    }
    i = 1;
    while (i <= sizeL2)
    {

        num2 += tmp2->value * pow(10, sizeL2 - i);
        tmp2 = tmp2->next;
        i++;
    }
    sum = num1 + num2;
    suma = std::to_string(sum);
    digit = suma[0];
    NewNode->value = stoi(digit);
    i = 1;
    while (i < suma.size())
    {
        Node<int>* newNode = new Node<int>();
        digit = suma[i];
        newNode->value = stoi(digit);
        headf->next = newNode;
    }
    return NewNode;
}