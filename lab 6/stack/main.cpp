#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int size_array=50;
int top=-1;
int arr[size_array];

void Push(int num){
    if(top==(size_array-1)){
        cout<<"the stack is full"<<endl;
        return ;
    }
    top+=1;
    arr[top]=num;
}

void Pop(){
    if(top==-1){
        cout<<"the stack is empty"<<endl;
        return;
    }
    top-=1;
}


void Display(){
    if(top==-1){
        cout<<"the stack is empty"<<endl;
        return;
    }
    cout<<"the elements in the stack are :";
    for(int index=top;index>=0;index--){
        cout<<arr[index]<<" ";
    }

    cout<<endl;
    return;
}

bool isempty(){
    if(top==-1){
        return true;
    }
    return false;
}

bool isfull(){
    if(top==(size_array-1)){
        return true;
    }
    return false;
}


int stacktop(){
    if(top==-1){
        cout<<"the stack is empty"<<endl;
        return NULL;
    }
    return arr[top];
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

    cout << "the time taken by stack implemented using arrays: " << duration.count() << " microseconds" << endl;

    return 0;
}
