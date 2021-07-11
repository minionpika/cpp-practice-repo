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
        next = NULL;
    }
};

void printList(Node *n)
{
    cout << "ami asi" << endl;
    Node *temp = n;
    while (temp != NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        if (temp != NULL)
            cout<<"->";
    }
    cout<< endl;
}

Node* append(Node* output, Node *temp)  
{
    if (output == NULL)  
    {  
        output = temp;
        return output;
    }

    Node *last = output;
    while (last->next != NULL)  
        last = last->next;  
  
    last->next = temp;  
    return output;  
} 

Node *merge2List(Node *h1, Node *h2)
{
    if (!h1) return h2;
    if (!h2) return h1;

    Node* temp = NULL;
    Node* m = NULL;
    Node* h1_curr=h1; 
    Node* h2_curr=h2;

    while (h1_curr && h2_curr)
    {
        if (h1_curr->data <= h2_curr->data)
        {
            temp = new Node(h1_curr->data);
            h1_curr = h1_curr->next;
            cout << temp->data << endl;
        }
        else
        {
            temp = new Node(h2_curr->data);
            h2_curr = h2_curr->next;
            cout << temp->data << endl;
        }
        m = append(m, temp);
    }

    if (h1_curr)
        m = append(m, h1_curr);
    else
        m = append(m, h2_curr);
    
    return m;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    printList(head1);
    
    Node *head2 = new Node(0);
    head2->next = new Node(2);
    head2->next->next = new Node(4);
    printList(head2);


    Node *mergedList = merge2List(head1, head2);
    printList(mergedList);
}