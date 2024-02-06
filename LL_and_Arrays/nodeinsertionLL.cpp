#include <iostream>
using namespace std;

class Node // Creating a node
{
public:
    int data;
    Node *next;
};

class linkedList // creating a linked list
{
public:
    Node *Head, *Tail;
    linkedList()
    {
        Head = NULL;
        Tail = NULL;
    }

    void insertNodeAtFront(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (Head == NULL)
        {
            Tail = newNode;
            Head = newNode;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
    }
    void insertNodeAtEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
            return;
        }
        else
        {
            Tail->next = newNode;
            Tail = newNode;
            return;
        }
    }

    void displayLinkedList()
    {
        Node *current = Head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void countList()
    {
        Node *cur = Head;
        int count = 0;
        while (cur != NULL)
        {
            count++;
            cur = cur->next;
        }
        cout << "The number of nodes in the LL are: " << count;
    }
    void insertAtAnyPostion(int position, int value)
    {
        Node *prev = new Node; // Declared for traversal purposes
        Node *current = new Node;
        current = Head;
        Node *newNode = new Node; // The new node
        newNode->data = value;
        newNode->next = NULL;

        if (position < 1)
        {
            cout << "Cant place here";
        }
        else if (position == 1)
        {
            newNode->next = Head;
            Head = newNode;
        }
        else
        {
            for (int i = 1; i < position; i++)
            {
                prev = current;
                current = current->next;
                if (current == NULL)
                {
                    cout << "Invalid Position";
                    return;
                }
            }
        }
        prev->next = newNode;
        newNode->next = current;
    }

    void searchElement(int value)
    {
        Node *current = Head;
        while (current != NULL)
        {
            if (current->data == value)
            {
                cout << "Element" << value << "is found";
                return;
            }
            current = current->next;
        }
        cout << "Element not found in list";
    }

    void deleteNode(int value)
    {
        bool flag = false;
        Node *current = new Node;
        Node *previous = new Node;
        previous = NULL, current = Head;

        while (current != NULL)
        {
            if (current->data == value && current == Head)
            {
                Head = current->next;
                free(current);
                flag = true;
                break;
            }
            else if (current->data = value)
            {
                previous->next = current->next;
                if (current == Tail)
                {
                    Tail = previous;
                }
                free(current);
                flag = true;
                break;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (flag == true)
            cout << "Element Deleted";
        else
            cout << "Element not found";
    }

    void reverse()
    {
        // Initialize current, previous and next pointers
        Node *current = Head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        Head = prev;
    }
}; // linked list ends here

int main()
{
    linkedList lst;
    //lst.insertNodeAtFront(50);
    //lst.insertNodeAtFront(90);
    lst.insertNodeAtEnd(100);
    lst.insertNodeAtEnd(80);
    // cout << endl;
    // lst.searchElement(1000);
    // cout << endl;
    // lst.deleteNode(50);
    // cout << endl;
    // lst.countList();
    lst.displayLinkedList();
}