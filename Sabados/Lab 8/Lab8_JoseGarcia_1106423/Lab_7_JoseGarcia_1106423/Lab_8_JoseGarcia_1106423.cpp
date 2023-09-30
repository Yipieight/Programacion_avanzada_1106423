#include <iostream>

class List
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
    void Add(int item)
    {
        Node* new_node = new Node(item);
        if (!header)
        {
            header = new_node;
            tail = new_node;
            header->next = header;
            header->prev = header;
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = header;
            header->prev = new_node;
            tail = new_node;
        }
    }

    void Clear()
    {
        while (header)
        {
            Node* temp = header;
            header = header->next;
            delete temp;
            if (header == tail) // Si solo queda un nodo, lo borramos y establecemos tail y header en nullptr.
            {
                delete header;
                header = nullptr;
                tail = nullptr;
            }
        }
    }

    void Remove(int value)
    {
        if (!header)
        {
            return;
        }

        Node* current = header;

        do
        {
            if (current->data == value)
            {
                if (current == header)
                {
                    header = header->next;
                    header->prev = tail;
                    tail->next = header;
                }
                else if (current == tail)
                {
                    tail = tail->prev;
                    tail->next = header;
                    header->prev = tail;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        } while (current != header);
    }

    void Insert(int item, int position)
    {
        if (position < 0)
        {
            std::cout << "Posición inválida" << std::endl;
            return;
        }

        if (position == 0 || !header)
        {
            Add(item);
            return;
        }

        Node* current = header;
        int index = 0;

        do
        {
            if (index == position)
            {
                Node* new_node = new Node(item);
                new_node->next = current;
                new_node->prev = current->prev;
                current->prev->next = new_node;
                current->prev = new_node;
                if (current == header) header = new_node;
                return;
            }
            current = current->next;
            index++;
        } while (current != header);

        std::cout << "Posición fuera de rango" << std::endl;
    }

    void Print()
    {
        if (!header)
        {
            std::cout << "Lista vacía" << std::endl;
            return;
        }

        Node* current = header;

        do
        {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != header);

        std::cout << std::endl;
    }
    int Get(int index)
    {
        if (!header || index < 0)
        {
            std::cout << "Índice fuera de rango o lista vacía" << std::endl;
            return -1; // Valor predeterminado si el índice está fuera de rango o la lista está vacía
        }

        Node* current = header;
        int currentIndex = 0;

        do
        {
            if (currentIndex == index)
            {
                return current->data;
            }
            current = current->next;
            currentIndex++;
        } while (current != header);

        std::cout << "Índice fuera de rango" << std::endl;
        return -1; // Valor predeterminado si el índice está fuera de rango
    }

    int Size()
    {
        if (!header)
        {
            return 0;
        }

        Node* current = header;
        int count = 0;

        do
        {
            count++;
            current = current->next;
        } while (current != header);

        return count;
    }

    bool IsEmpty()
    {
        return (header == nullptr);
    }
};
class Stack
{
private:
    List list;

public:
    void Push(int item) {
        list.Add(item);
    }
    void pop() {
        if (list.IsEmpty()) {
            std::cout << "La pila está vacia. " << std::endl;
        }
        list.Remove(list.Size());
    }

    int top() {
        if (list.IsEmpty()) {
            std::cout << "La pila esta vacia" << std::endl;
            return -1;
        }
        return list.Get(list.Size() - 1);
    }
    void Print() {
        list.Print();
    }
};
class Queue
{
private:
    List list;

public:

    void Enqueue(int item) {
        list.Add(item);
    }

    void Dequeue() {
        if (list.IsEmpty()) {
            std::cout << "La cola esta vacia." << std::endl;
            return;
        }
        list.Remove(0);
    }
    int Front() {
        if (list.IsEmpty()) {
            std::cout << "La cola esta vacia." << std::endl;
            return -1;
        }
        return list.Get(0);
    }
    bool IsEmpty() {
        return list.IsEmpty();
    }
    int Size() {

        return list.Size();

    }
    void Print() {
        list.Print();
    }
};
int main()
{
    List myList;
    Stack myStack;
    Queue myQueue;

    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);

    std::cout << "Elemento en la cima de la pila: " << myStack.top() << std::endl;
    myStack.pop();
    myStack.Print();
    std::cout << "Elemento en la cima de la pila despues del pop: " << myStack.top() << std::endl;

    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);

    std::cout << "Elemento frontal de la cola: " << myQueue.Front() << std::endl;
    myQueue.Dequeue();
    myQueue.Print();
    std::cout << "Elemento frontal de la cola despues del dequeue " << myQueue.Front() << std::endl;

    myList.Add(1);
    myList.Add(2);
    myList.Add(3);

    std::cout << "Lista original: ";
    myList.Print();

    myList.Remove(2);
    std::cout << "Después de eliminar el elemento 2: ";
    myList.Print();

    myList.Insert(4, 1);
    std::cout << "Después de insertar el elemento 4 en la posición 1: ";
    myList.Print();

    myList.Clear();
    std::cout << "Después de borrar la lista: ";
    myList.Print();
}