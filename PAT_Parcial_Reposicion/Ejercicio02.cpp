#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    Node<char>* headf = head;
    Node<char>* next = nullptr;
    Node<char>* prev = nullptr;
    int s = 0;

    Node<char>* tmp = head;
    while (tmp != nullptr && s < k) {
        tmp = tmp->next;
        s++;
    }


    if (s == k) {
        while (s > 0) {
            next = headf->next;
            headf->next = prev;
            prev = headf;
            headf = next;
            s--;
        }


        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
    else {
        return head;
    }
}
