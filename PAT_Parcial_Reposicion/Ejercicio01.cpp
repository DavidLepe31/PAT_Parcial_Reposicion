#include "Ejercicio01.h"
#include<cmath>
#include<string>
Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
   
    
   
    Node<int>* head1 = new Node<int>();
    Node<int>* head2 = new Node<int>();
    head1->value = l1->value;
    head1->next = nullptr;
    head2->value = l2->value;
    head2->next = nullptr;
    l1 = l1->next;
    l2 = l2->next;
    while (l1!=nullptr)
    {
        Node<int>* tmp = new Node<int>();
        tmp->value = l1->value;
        tmp->next = head1;
        head1 = tmp;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        Node<int>* tmp2 = new Node<int>();
        tmp2->value = l2->value;
        tmp2->next = head2;
        head1 = tmp2;
        l2 = l2->next;
    }

    int carry = 0;
    Node<int>* headf = new Node<int>();
    int sum = 0;
    sum = head1->value + head2->value + carry;
    if (sum >= 10) {
        headf->value = (sum % 10);
        headf->next = nullptr;
        head1 = head1->next;
        head2 = head2->next;
        carry = 1;
    }
    else {
        headf->value = sum;
        headf->next = nullptr;
        head1 = head1->next;
        head2 = head2->next;
        carry = 0;
    }
    
    while (l1 != nullptr && l2 != nullptr) {
        Node<int>* newNode = new Node<int>();
         sum = 0;
        sum = l1->value + l2->value + carry;
        if (sum >= 10) {
            newNode->value = (sum % 10);
            newNode->next = headf;
            headf = newNode;
            head1 = head1->next;
            head2 = head2->next;
            carry = 1;
        }
        else {
            newNode->value = sum;
            newNode->next = headf;
            headf = newNode;
            head1 = head1->next;
            head2 = head2->next;
            carry = 0;
        }

    }
    
        while (l1 != nullptr) {
            Node<int>* newNode = new Node<int>();
            int sum = 0;
            sum = l1->value + carry;
            if (sum >= 10) {
                newNode->value = (sum % 10);
                newNode->next = headf;
                headf = newNode;
                head1 = head1->next;
                carry = 1;
            }
            else {
                newNode->value = sum;
                newNode->next = headf;
                headf = newNode;
                head1 = head1->next;
                carry = 0;
            }

        }
    
    while (l2 != nullptr) {
            Node<int>* newNode = new Node<int>();
            int sum = 0;
            sum = l2->value + carry;
            if (sum >= 10) {
                newNode->value = (sum % 10);
                newNode->next = headf;
                headf = newNode;
                head2 = head2->next;
                carry = 1;
            }
            else {
                newNode->value = sum;
                newNode->next = headf;
                headf = newNode;
                head2 = head2->next;
                carry = 0;
            }

        }

    

    if (carry == 1) {
        Node<int>* newNode = new Node<int>();
        newNode->value = carry;
        newNode->next = headf;
        headf = newNode;
       
    }
    return headf;
}