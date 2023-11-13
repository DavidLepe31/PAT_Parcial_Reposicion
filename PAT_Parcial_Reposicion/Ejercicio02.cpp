#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    Node<char>* tmp = head;
    Node<char>* tmp1 = head;
    Node<char>* tmp2 = nullptr;
    int  n = 0;
    int  i = 0;
    int  z = 0;
    int  j = 0;
    while (tmp)
    {
        tmp = tmp->next;
        n++;
    }
    j = n / k;
    while (i < j) 
    {
        z = 0;
        n = k * (i + 1);
        tmp1 = head;
        while (z < n && tmp1!=nullptr) 
        {
            tmp1 = tmp1->next;
            z++;
        }
        z = 0;
        while (z < n && tmp2 != nullptr && tmp1 != nullptr)
        {
            tmp2 = tmp->next;
            tmp->next = tmp1;
            tmp1 = tmp;
            tmp = tmp2;
            z++;
        }
        i++;
    }
    return head;
}
