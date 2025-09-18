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
    void DisplaywithHeadRepeated(){
        Node* temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout<<head->data<<endl;

    }
};
    int main(){
        CircularLinkedList list;
        list.insertAtEnd(20);
        list.insertAtEnd(100);
        list.insertAtEnd(40);
        list.insertAtEnd(80);
        list.insertAtEnd(60);
        list.DisplaywithHeadRepeated();
        return 0;
    }
