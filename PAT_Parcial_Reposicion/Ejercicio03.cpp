#include "Ejercicio03.h"

Node<int>* Ejercicio03::detectCycle(Node<int>* head)
{
	Node<int>* fast = head;
	Node<int>* slow = head;

	while (fast!=nullptr && fast->next!=nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			return fast;
		}
	}
	return nullptr;
}
