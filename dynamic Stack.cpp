#include <iostream>

using namespace std;

class Stack{
 private:
     int top;
    int cap;
    int*arr;
     void wider(int boyut);

 public:
    Stack(){
    top=-1;
    arr=0;
    cap=0;
    wider(4);

    }
    void wider(int boyut){
    int yeniAlan=new int[boyut+cap];
    for(int i=0;i<=top;i++){
        yeniAlan[i]=arr[i];
    }
    if(arr)delete[] arr;
    arr=yeniAlan;
    cap+=boyut;

    }
    bool isEmpty(){
       return(top==-1);
    }
//    bool isFull(){
//        return(top==MAX_SIZE-1);
//    }

    void push(int data){
    if(top==cap-1){
      wider(cap);
    }
     top++;
        arr[top]=data;
        cout<< "pushed element   "<< data<<" onto the stack \n";
    }
    void pop(){
        if(!isEmpty()){
            int poppedElement=arr[top];
            top--;
            cout << "popped element  "<< poppedElement<< " from the stack \n";
        }else{
        cout<<"can not pop element because stack is empty\n"; }

    }
//    int topElement(){
//        if(!isEmpty()){
//         return arr[top];
//        }else{
//        cout<< "stack is empty\n ";
//        }
//
//    }
~Stack(){
delete[] arr; }


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
