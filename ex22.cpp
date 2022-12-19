#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void add(node **head, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void input_ds(int arr[], int n, node* head)
{
    head = NULL;
    for (int i = n -1; i>= 0; i--)
    {
        add(&head, arr[i]);
    }
}

node* finnode(node* head, int k)
{
    int n = 0;
    node* p = head;
    for (int i = 0; p && i < k; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        return NULL;
    }
    while (p != NULL)
    {
      head = head->next;
      p = p->next;
    }
    return p;
}

int main()
{
    int keys[5];
    cout << "Nhap day: " << endl;
    for (int i =0; i < 5; i++)
    {
        cout << "keys[" << i <<"] = ";
        cin >> keys[i];
    }
    node* head = NULL;

    input_ds(keys, 5, head);

    int k = 3;
    cout << finnode(head, k);
    struct node* knode = finnode(head, k);
    if (knode != NULL)
    {
        cout << "k'th node from the end is " << knode->data;
    }
    return 0;
}