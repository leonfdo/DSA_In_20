#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct link{
    int num;
    link* next_link;
};

link* top=NULL;

void Push(int data){
    link* new_link=new link;
    new_link->num=data;
    new_link->next_link=top;
    top=new_link;
}


void Pop(){
    if(top==NULL){
        cout<<"the stack is empty"<<endl;
    }
    top=top->next_link;
}

bool isEmpty(){
    if(top==NULL){
        return true;
    }
    return false;
}


void Display(){
    if(top==NULL){
        cout<<"the stack is empty"<<endl;
        return;
    }
    link* temp=top;
    cout<<"the elements in the stack are :";
    while(temp!=NULL){
        cout<<temp->num<<" ";
        temp=temp->next_link;
    }

    cout<<endl;
}

void StackTop(){
     if(top==NULL){
        cout<<"the stack is empty"<<endl;
        return;
    }
    cout<<top->num<<endl;

}

int main()
{
    auto start = high_resolution_clock::now();


    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout<<endl;;
    cout<<"the time taken by the stack implemented using linked lists : " << duration.count() << " microseconds" << endl;

    return 0;
}
