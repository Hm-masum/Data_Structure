#include <iostream>
using namespace std;

const int MAX_SIZE=4;
int DATA[MAX_SIZE+1];
int TOP=0;

void push(int x)
{
    if(TOP==MAX_SIZE)
    {
        cout<<"Over flow.\n\n";
    }
    else
    {
        TOP++;
        DATA[TOP]=x;
        cout<<x<<" is pushed.\n\n";
    }
}

void pop(){
    if(TOP>0)
    {
        cout<<DATA[TOP]<<" is popped.\n\n";
        TOP--;
    }
    else
    {
        cout<<"Under flow.\n\n";
    }
}

void top(){
    if(TOP>0){
        cout<<"TOP : "<<DATA[TOP]<<endl<<endl;
    }
     else {
        cout << "Stack is empty.\n\n";
    }
}

void show(){
     if (TOP > 0) {
        for (int i = TOP; i > 0; i--) {
            cout << DATA[i] << " ";
        }
        cout << endl<<endl;
    }
    else {
        cout << "Stack is empty.\n\n";
    }
}


int main(){
    int choich,x;

    do{
        cout<<"1 : Push\n";
        cout<<"2 : Pop\n";
        cout<<"3 : Top\n";
        cout<<"4 : Show\n";
        cout<<"5 : Exit\n";

        cout<<"Enter your choich : ";
        cin>>choich;

        switch(choich)
        {
        case 1:
            cout<<"Enter The Data : ";
            cin>>x;
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            top();
            break;
        case 4:
            show();
            break;
        case 5:
            cout<<"Thank you. Take love......\n";
            break;
        default:
             cout << "Invalid choice. Try again.\n\n";


        }
    }
    while(choich != 5);

}
