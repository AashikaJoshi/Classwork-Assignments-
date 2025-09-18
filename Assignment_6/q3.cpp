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
    void SizeOfList()
    {
        Node *temp = head;
        int count = 1;
        if (head == NULL)
        {
            return;
        }
        do
        {
            count++;
            temp = temp->next;
        } while (temp->next != head);

        cout<<"The size of list is : "<<count<<endl;
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
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.display();
    list.SizeOfList();
    return 0;
}