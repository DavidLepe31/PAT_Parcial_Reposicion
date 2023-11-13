#include "Ejercicio03.h"
#include<vector>

Node<int>* Ejercicio03::detectCycle(Node<int>* head)
{
	Node<int>* tmp = new Node<int>();
	
	while (head!=nullptr)
	{
		if (head->next == nullptr)
		{
			return nullptr;
		}
		if (head->next == tmp)
		{
			return tmp;
		}

		Node<int>* next = head->next;
		head->next = tmp;
		head = next;
	}
	return nullptr;
}
