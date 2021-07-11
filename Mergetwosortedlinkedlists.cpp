#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

void printList(Node *n)
{
    Node *temp = n;
    while (temp!=nullptr)
    {
        cout<<temp->data;
        temp=temp->next;
        if (temp != nullptr)
            cout<<"->";
    }
    cout<< endl;
}

void append(Node** output, Node *temp)  
{
    if (*output == NULL)  
    {  
        *output = temp;  
        return;
    }

    Node *last = *output;
    while (last->next != NULL)  
        last = last->next;  

    last->next = temp;  
    return;  
} 

Node *merge2List(Node *h1, Node *h2)
{
    if (!h1) return h2;
    if (!h2) return h1;

    Node *temp = nullptr, *m = nullptr, *h1_curr=h1, *h2_curr=h2;

    while (h1_curr && h2_curr)
    {
        if (h1_curr->data <= h2_curr->data)
        {
            temp = new Node(h1_curr->data);
            h1_curr = h1_curr->next;
        }
        else
        {
            temp = new Node(h2_curr->data);
            h2_curr = h2_curr->next;
        }

        append(&m, temp);
    }

    if (h1_curr)
        append(&m, h1_curr);
    else
        append(&m, h2_curr);
    
    return m;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(10);
    
    Node *head2 = new Node(0);
    head2->next = new Node(2);
    head2->next->next = new Node(4);

    Node *mergedList = merge2List(head1, head2);
    printList(mergedList);
}