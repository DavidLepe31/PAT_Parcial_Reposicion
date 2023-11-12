#include "Ejercicio01.h"
#include<cmath>
#include<string>
Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
    int i=0,carry=1, n=0;
    bool banse = true;
    Node<int>* headf =nullptr;
    Node<int>* tmp =l1;
    Node<int>* tmp2 = l2;
    Node<int>* tmp3 = headf;
    if (sizeL1 < sizeL2)
    {
        n = sizeL1;
   }
    else
    {
        n = sizeL2;
        banse = false;
    }
    while (i < n)
    {
        if (tmp->value + tmp2->value>10)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        if (!headf)
        {
            Node<int>* newNode = new Node<int>();
            newNode->value = (tmp->value + tmp2->value) % 10;
            newNode->next = nullptr;
            headf = newNode;
            tmp3 = headf;
            tmp = tmp->next;
            tmp2 = tmp2->next;
            i++;
            continue;
        }
        if (carry==1)
        {
            Node<int>* newNode = new Node<int>();
            newNode->value = (tmp->value + tmp2->value +1 ) % 10;
            newNode->next = nullptr;
            tmp3->next = newNode;
            tmp3 = tmp3->next;
        }
        else {
            Node<int>* newNode = new Node<int>();
            newNode->value = (tmp->value + tmp2->value) % 10;
            newNode->next = nullptr;
            tmp3->next = newNode;
            tmp3 = tmp3->next;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
        i++;
    }
    if (banse)
    {
        while (i<sizeL2)
        {
            tmp3->next = tmp2;
            tmp3 = tmp3->next;
            i++;
        }
    }
    else
    {
        while (i < sizeL1)
        {
            tmp3->next = tmp;
            tmp3 = tmp3->next;
            i++;
        }
    }
    return headf;
}