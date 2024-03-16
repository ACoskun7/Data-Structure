#include <iostream>
#include <algorithm>
const int  MAX=5;

using namespace std;
// stack kullnýmý
template<typename T>
class Stack{
 private:
     int top;
      int sizeOfStack;
   T arr[MAX];
 public:
    Stack(){
    top=-1;
    sizeOfStack=0;
    }
     bool isEmpty(){
     if(top==-1)
        return true;
        return false;

     }
      bool isFull(){
     if(top==MAX-1)
        return true;
        return false;
     }
     void push(T data){
     if(!isFull()){
        top++;
        arr[top]=data;
        sizeOfStack++;
     }else{
     cout<<"this stack is full\n";
     }
     }
     void pop(){
     if(!isEmpty()){
        T temp;
        temp=arr[top];
        top--;
        cout<<temp <<" is poped in the stack\n";
        sizeOfStack--;
     }else{
     cout<<"this stack is empty\n";
     }

     }
     void topElement(){
     if(!isEmpty()){
        cout<< arr[top]<< "is top element in this stack \n";
     }else{
     cout<<"this stack is empty\n";
     }
     }
     void sizeStack(){
     cout<<"size of stack : "<< sizeOfStack;
     }
     void display(){
     T ary[MAX];
      copy(begin(arr),end(arr),begin(ary));
      cout<<"\n element in the stack \n";
      while(!isEmpty()){
         T temp;
        temp=ary[top];
        top--;

      }

     }

};

int main()
{
   Stack<string> stc;
   stc.push("ibrahim");
    stc.push("mehmet ali");
     stc.push("osman");
      stc.push("kubilay");
       stc.push("ahmet");
       stc.pop();
       stc.sizeStack();
       stc.display();

    return 0;
}
