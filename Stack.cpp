#include <iostream>

using namespace std;
 const int MAX_SIZE=5;
class Stack{
 private:
     int top;
     int arr[MAX_SIZE];
 public:
    Stack(){
    top=-1;
    }
    bool isEmpty(){
       return(top==-1);
    }
    bool isFull(){
        return(top==MAX_SIZE-1);
    }

    void push(int data){
    if(top<MAX_SIZE-1){ //if(!isFull()){} diye de kullanabiliriz
        top++;
        arr[top]=data;
        cout<< "pushed element   "<< data<<" onto the stack \n";
    }else{
    cout<<"Stack is full. can not push "<< data<< "in stack\n ";
    }

    }
    void pop(){
        if(!isEmpty()){
            int poppedElement=arr[top];
            top--;
            cout << "popped element  "<< poppedElement<< " from the stack \n";
        }else{
        cout<<"can not pop element because stack is empty\n"; }

    }
    int topElement(){
        if(!isEmpty()){
         return arr[top];
        }else{
        cout<< "stack is empty\n ";
        }

    }


};

int main()
{
   Stack myStack;
 for(int i=0;i<5;i++){
    myStack.push(i+1);
 }
myStack.push(6);
while(!myStack.isEmpty()){
    myStack.pop();
}
    return 0;
}
