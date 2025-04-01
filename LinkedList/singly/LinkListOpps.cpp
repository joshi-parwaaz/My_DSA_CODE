#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node * head = new Node;

void create(int arr[], int n)
{
    head->data = arr[0];
    head->next = nullptr;
    Node *last = head;
    for (int i = 1; i < n; i++)
    {
        last->next = new Node;
        last=last->next;
        last->data = arr[i];
        last->next = nullptr;
    }
}

void CountAndSum(Node *head)
{
    int count=0, sum=0;
    Node *p = head;
    while (p != nullptr)
    {
        sum += p->data;
        count++;
        p = p->next;
    }
    cout<<"The number of nodes are = "<<count<<endl;
    cout<<"The sum of all elements = "<<sum<<endl;
}

void max(Node *head)
{
    Node *p = head->next;
    int max = head->data;
    while (p != nullptr)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    cout<<"Maximum element is: "<<max<<endl;
}

void freememory(Node *head)
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    } 
}

int main()
{
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;

    int *arr = new int[n];
    cout<<"Enter elements for linked list: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    create(arr, n);
    CountAndSum(head);
    max(head);
    
    delete []arr;
    freememory(head);
    return 0;
}       