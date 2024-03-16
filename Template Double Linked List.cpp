#include <iostream>

using namespace std;
//doubly linked listin singly linked list ten tek farki previous diye fazlada bir isaretciye sahip olmasý ve bu isaretcinin ondeki sayiyi gostermesi
 template<typename T>
 class Node{
 private:
     T data;
     Node<T>* next;
      Node<T>* previous;
 public:
    Node(T data){
    this->data=data;
    this->next=nullptr;
       this->previous=nullptr;
    }

    template<typename A>
    friend class DoubleLinkedList;


 };
 template<typename T>
 class DoubleLinkedList{
 private:
  Node<T> *head;
  public:
    DoubleLinkedList(){
    this->head=nullptr;
    }
     void insertAtBegining(T data){
    Node<T>* newnode=new Node<T>(data);
    if(head==nullptr){

        head=newnode;
        return;
    }

   newnode->next=head;
   head->previous=newnode;
   head=newnode;


    }
    void insertAtEnd(T data){
     Node<T> *newnode=new Node<T>(data);
     Node<T> *temp=head;
      if(head==nullptr){

        head=newnode;

        return;
    }
     while(temp->next!=nullptr){
        temp=temp->next;

     }
  temp->next=newnode;
  newnode->previous=temp;

    }
    void removeAtEnd(){
        if(head==nullptr){
            cout<< "this linked list is empty\n";
            return;
        }
        if(head->next==head){
            delete head;
            head=nullptr;
            return;
        }
    Node<T> *temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    }
    void removeAtBegining(){
         if(head==nullptr){
            cout<< "this linked list is empty\n";
            return;
        }
        if(head->next==head){
            delete head;
            head=nullptr;
            return;
        }
        Node<T>*temp=head;


        head=head->next;

        delete temp;
        head->previous=nullptr;

    }
 void displayList(){
  if(head==nullptr){
            cout<< "this linked list is empty\n";
            return;
        }
        Node<T>*temp=head;
       while(temp!=nullptr){
            cout<< temp->data<<" ,";
            temp=temp->next;
        }
 }

 };

int main()
{
        DoubleLinkedList<string> CList;
   CList.insertAtEnd("ahmet");
    CList.insertAtEnd("osman");
    CList.insertAtEnd("mehmet ali ");
    CList.insertAtEnd("ibrahim ");
    CList.insertAtEnd("kubilay");
    CList.displayList();
    cout<< "\n*********************************************************\n";
    CList.insertAtBegining("cemil");
    CList.removeAtEnd();
       CList.displayList();
    return 0;
}
