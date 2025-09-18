#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        do
        {
            if (temp->data == key)
            {
                Node *newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node" << key << "Not found!" << endl;
    }

    void deleteNode(int key)
    {
        if (head == NULL)
        {
            return;
        }
        Node *curr = head, *prev = NULL;

        do
        {
            if (curr->data == key)
            {
                if (curr == head)
                {
                    Node *last = head;
                    while (last->next != head)
                    {
                        last = last->next;
                    }
                    if (head == head->next)
                    {
                        head = NULL;
                    }
                    else
                    {
                        head = head->next;
                        last->next = head;
                    }
                    delete curr;
                }
                else
                {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node " << key << " not found!\n";
    }

    void search(int key)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        int pos = 1;
        do
        {
            if (temp->data == key)
            {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found!\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "CLL is empty\n";
            return;
        }
        Node *temp = head;
        cout << "CLL: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main()
{
    CircularLinkedList list;
    int choice, val, key;

    while (true)
    {
        cout << "-- Circular Linked List Menu --" << endl;
        cout << "1. Insert at Beginning." << endl;
        cout << "2. Insert at End." << endl;
        cout << "3. Insert after Node." << endl;
        cout << "4. Delete Node." << endl;
        cout << "5. Search Node." << endl;
        cout << "6. Display." << endl;
        cout << "7. Exit." << endl;

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
        cout<<"Exiting Program.."<<endl;
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
