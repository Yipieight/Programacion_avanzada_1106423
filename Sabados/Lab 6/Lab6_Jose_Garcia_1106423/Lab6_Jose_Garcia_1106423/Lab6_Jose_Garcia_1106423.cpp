#include <iostream>



class List
{
private:
    struct Node
    {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* header = nullptr;

public:
    void Add(int item)
    {
        if (!header)
        {
            header = new Node(item);
        }
        else
        {
            Node* current = header;
            while (current->next)
            {
                current = current->next;
            }
            current->next = new Node(item);
        }
    }



    void Clear()
    {
        while (header)
        {
            Node* temp = header;
            header = header->next;
            delete temp;
        }
    }



    // Método para eliminar un elemento por valor
    void Remove(int value)
    {
        if (!header)
        {
            return;
        }



        if (header->data == value)
        {
            Node* temp = header;
            header = header->next;
            delete temp;
            return;
        }



        Node* current = header;
        while (current->next)
        {
            if (current->next->data == value)
            {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }



    // Método para insertar un elemento en una posición específica
    void Insert(int item, int position)
    {
        if (position < 0)
        {
            std::cout << "Posición inválida" << std::endl;
            return;
        }



        if (position == 0 || !header)
        {
            Node* new_node = new Node(item);
            new_node->next = header;
            header = new_node;
            return;
        }



        Node* current = header;
        int index = 0;
        while (current->next && index < position - 1)
        {
            current = current->next;
            index++;
        }



        Node* new_node = new Node(item);
        new_node->next = current->next;
        current->next = new_node;
    }



    void Print()
    {
        Node* current = header;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};



int main()
{
    List myList;



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



    return 0;
}