#include <iostream>

class list
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
		Node(int val) : data(val), next(nullptr), prev(nullptr) {}
	};

	Node* header = nullptr;
	Node* tail = nullptr;

public:
	
	void add(int item) {
		if (!header)
		{
			header = new Node(item);
			tail = header;
		}
		else
		{
			Node* new_mode = new Node(item);
			tail->next = new_mode;
			new_mode->prev = tail;
			tail = new_mode;
		}
	}

	void clear() {
		while (header)
		{
			Node* temp = header;
			header = header->next;
			delete temp;
		}
		tail = nullptr;
	}
	
	void remove(int value) {
		if (!header) {
			return;
		}
		if (header->data == value) {
			Node* temp = header;
			header = header->next;
			if (header) header->prev = nullptr;
			delete temp;
			return;
		}

		Node* current = header;
		while (current->next)
		{
			if (current->next->data == value) {
				Node* temp = current->next;
				current->next = current->next->next;
				if (current->next) current->next->prev = current;
				delete temp;
				return;
			}
			current = current->next;
		}
	}
	void insert(int item, int position) {
		if (position < 0) {
			std::cout << "Posicion invalida" << std::endl;
			return;
		}
		if (position == 0 || !header) {
			Node* new_mode = new Node(item);
			new_mode->next = header;
			if (header) header->prev = new_mode;
			header = new_mode;
			if (!tail) tail = header;
			return;
		}
		Node* current = header;
		int index = 0;
		while (current->next && index < position -1)
		{
			current = current->next;
			index++;
		}

		Node* new_mode = new Node(item);
		new_mode->next = current->next;
		if (current->next)current->next->prev = new_mode;
		current->next = new_mode;
		new_mode->prev = current;
	}

	void Print() {
		Node* current = header;
		while (current)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
	}
};


int main()
{
	list mylist;
	mylist.add(6);
	mylist.add(7);
	mylist.Print();
}

