#include "Ejercicio01.h"
#include<cmath>
#include<string>
Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
   
    Node<int>* tmp = nullptr;
    Node<int>* tmp2 = nullptr;
    int carry = 0;
    Node<int>* headf = new Node<int>();
    int sum = 0;
    sum = l1->value + l2->value + carry;
    if (sum >= 10) {
        headf->value = (sum % 10);
        headf->next = nullptr;
        l1 = l1->next;
        l2 = l2->next;
        carry = 1;
    }
    else {
        headf->value = sum;
        headf->next = nullptr;
        l1 = l1->next;
        l2 = l2->next;
        carry = 0;
    }
    tmp = headf;
    while (l1 != nullptr && l2 != nullptr) {
        Node<int>* newNode = new Node<int>();
         sum = 0;
        sum = l1->value + l2->value + carry;
        if (sum >= 10) {
            newNode->value = (sum % 10);
            newNode->next = nullptr;
            tmp->next = newNode;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
            carry = 1;
        }
        else {
            newNode->value = sum;
            newNode->next = nullptr;
            tmp->next = newNode;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
            carry = 0;
        }

    }
    
        while (l1 != nullptr) {
            Node<int>* newNode = new Node<int>();
            int sum = 0;
            sum = l1->value + carry;
            if (sum >= 10) {
                newNode->value = (sum % 10);
                newNode->next = nullptr;
                tmp->next = newNode;
                tmp = tmp->next;
                l1 = l1->next;
                carry = 1;
            }
            else {
                newNode->value = sum;
                newNode->next = nullptr;
                tmp->next = newNode;
                tmp = tmp->next;
                l1 = l1->next;
                carry = 0;
            }

        }
    
    while (l2 != nullptr) {
            Node<int>* newNode = new Node<int>();
            int sum = 0;
            sum = l2->value + carry;
            if (sum >= 10) {
                newNode->value = (sum % 10);
                newNode->next = nullptr;
                tmp->next = newNode;
                tmp = tmp->next;
                l2 = l2->next;
                carry = 1;
            }
            else {
                newNode->value = sum;
                newNode->next = nullptr;
                tmp->next = newNode;
                tmp = tmp->next;
                l2 = l2->next;
                carry = 0;
            }

        }

    

    if (carry == 1) {
        Node<int>* newNode = new Node<int>();
        newNode->value = carry;
        newNode->next = nullptr;
        tmp->next = newNode;
        tmp = tmp->next;
    }
    return headf;
}