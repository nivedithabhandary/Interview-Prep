#include<iostream>
using namespace std;

struct node {
    int data;
    node * next;
};


void insert(node **head, int a) {
    node * newnode = new node();
    newnode->data=a;
    newnode->next = *head;
    *head = newnode;
}
void remove_duplicates(node *head) {

}

void print(node *head) {
    node *temp = head;
    while(temp!=NULL) {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
}

int main() {
    node * head = new node();
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    print(head);
}
