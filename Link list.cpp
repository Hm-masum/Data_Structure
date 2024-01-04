#include<bits/stdc++.h>
using namespace std;

struct linked_list
{
    int data;
    struct linked_list *next;
};
typedef struct linked_list node;

int main()
{
    node *start, *ptr;
    int i, n;
    start = (node *) malloc(sizeof(node));
    ptr = start;
    cout << "How many data: ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << "Enter value: ";
        cin >> ptr->data;

        if (i != n) {
            ptr->next = (node *) malloc(sizeof(node));
            ptr = ptr->next;
        }
    }
    ptr->next = NULL;

    ptr = start;
    int x;
    int flag=0;
    cout<<"Enter a number for searce: ";
    cin>>x;
    cout << "Printing list: ";
    while (ptr != NULL) {
        cout << ptr->data << " ";
        if(ptr->data==x){
            flag++;
        }
        ptr = ptr->next;
    }
    cout<<endl;
    if(flag==0){
        cout<<"NOT FOUND";
    }
    else
        cout<<"FOUND";

    return 0;
}
