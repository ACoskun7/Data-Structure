#include <iostream>

using namespace std;
template <typename T>
class Node{
private:
    T data;
    Node<T>* next;
    public:
    Node(T data){
    this->data=data;
     this->next=nullptr;
     }
     template <typename U>
     friend class LinkedListStack ;


};
template <typename T>
class LinkedListStack{
public:
     Node<T>* head;
     LinkedListStack(){
     this->head=nullptr;
     }
     void push(T data){
     Node<T>*newnode=new Node<T>(data);
     if(head==nullptr){
        head=newnode;
     }else{
     newnode->next=head;
     head=newnode;
     }


     }
     void pop(){
      Node<T>*temp=head;
      head=head->next;
      delete temp;

     }
     void display(){
      if(head==nullptr){
        cout<<" this stack is empty\n";
        return;
      }
      Node<T>*temp=head;
      while(temp!=nullptr){
        cout<< temp->data<<" ,";
        temp=temp->next;
      }
     }
     void sizeStack(){
         if(head==nullptr){
        cout<<" this stack is empty\n";
        return;
      }
      Node<T>*temp=head;
      int sizeofStack =0;
      while(temp!=nullptr){
        sizeofStack++;
        temp=temp->next;
      }
      cout<< "size of stack : "<<sizeofStack<<"\n\n";
     }
};

int main()
{
    LinkedListStack<int> listStack ;
    listStack.push(1);
    listStack.push(2);
    listStack.push(3);
    listStack.push(4);
    listStack.push(5);
    listStack.display();
    listStack.sizeStack();
    listStack.pop();
    listStack.pop();
     listStack.display();
    listStack.sizeStack();
    return 0;
}
