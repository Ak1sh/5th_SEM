#include<bits/stdc++.h>
using namespace std;
#include <cinttypes>

class Node{
    public:
    int data;
    Node *npx;
};
Node *Xor(Node *a, Node*b)
{
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
}
void insert_from_beginning(Node**head_ref,int val)
{
    Node *new_node= new Node();
    new_node->data= val;
    new_node->npx=*head_ref;
    if(*head_ref!=NULL)
    {
        (*head_ref)->npx= Xor(new_node,(*head_ref)->npx);
    }

    *head_ref=new_node;
}
void traverse(Node *temp)
{
    Node *curr=temp;
    Node *prev=NULL;
    Node *next;
    while (curr!=NULL)
    {
        cout<<curr->data<<" ";
        next=Xor(curr->npx,prev);
        prev=curr;
        curr=next;
    }
}
void del(Node **head)
{
    if (*head == NULL) cout << "List is empty";
    else
    {
       Node* curr = *head;
       Node* prev = NULL;
       Node* next;
        while (Xor(curr->npx, prev) != NULL)
        {
            next = Xor(prev, curr->npx);
            prev = curr;
            curr = next;
        }
        if (prev != NULL) {
            prev->npx = Xor(prev->npx, curr);
        }

        else {
            *head = NULL;
        }
        delete(curr);
    }

}
int main()
{
    Node * head =nullptr ;
    cout<<"Before Deletion :";
    insert_from_beginning(&head,5);
    insert_from_beginning(&head,7);
    insert_from_beginning(&head,3);
    insert_from_beginning(&head,10);
    traverse(head);
    cout<<"\nAfter Deletion :";
    del(&head);
    traverse(head);

    return 0;
}
