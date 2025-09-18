#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList
{
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAfter(int key, int val)
    {
        Node *temp = head;
        while (temp && temp->data != key)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Node " << key << " not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int key)
    {
        if (!head)
            return;
        Node *temp = head;

        if (temp->data == key)
        {
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node " << key << " not found!\n";
            return;
        }

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        delete temp;
    }

    void search(int key)
    {
        Node *temp = head;
        int pos = 1;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found!\n";
    }

    void display()
    {
        Node *temp = head;
        cout << "DLL: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    int choice, val, key;

    while (true)
    {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After Node\n";
        cout << "4. Delete Node\n5. Search Node\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter key to delete: ";
            cin >> key;
            list.deleteNode(key);
            break;
        case 5:
            cout << "Enter key to search: ";
            cin >> key;
            list.search(key);
            break;
        case 6:
            list.display();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
