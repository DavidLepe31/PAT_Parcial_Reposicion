#include "Ejercicio01.h"
#include<cmath>
#include<string>
Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
   
    
   
    Node<int>* head1 = l1;
    Node<int>* head2 = l2;
    Node<int>* tmp = nullptr;
    Node<int>* tmp2 = nullptr;
    while (head1 != nullptr)
    {
        tmp2 = head1->next;
        head1->next = tmp;
        tmp = head1;
        head1 = tmp2;
    }
    head1 = tmp;
    tmp = nullptr;
    tmp2 = nullptr;
    while (head2 != nullptr)
    {
        tmp2 = head2->next;
        head2->next = tmp;
        tmp = head2;
        head2 = tmp2;
    }
    head2 = tmp;
    

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
    
    while (head1 != nullptr && head2 != nullptr) {
        Node<int>* newNode = new Node<int>();
         sum = 0;
        sum = head1->value + head2->value + carry;
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
    
        while (head1 != nullptr) {
            Node<int>* newNode = new Node<int>();
            int sum = 0;
            sum = head1->value + carry;
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
    
    while (head2 != nullptr) {
            Node<int>* newNode = new Node<int>();
            int sum = 0;
            sum = head2->value + carry;
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