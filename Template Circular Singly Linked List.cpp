#include <iostream>

using namespace std;
//circular singly link list in singly linked listen tek farký son dugumun baslangýc  dugumunu gostermesidir.
//bunun için sona eleman ekledigimiz zaman sondaki dugumun isaretcisini de head e assign ediyoruz
 template<typename T>
 class Node{
 private:
     T data;
     Node<T>* next;
 public:
    Node(T data){
    this->data=data;
    this->next=nullptr;
    }

    template<typename A>
    friend class CircularSingly;


 };
 template<typename T>
 class CircularSingly{
 private:
  Node<T> *head;
  public:
    CircularSingly(){
    this->head=nullptr;
    }
     void insertAtBegining(T data){
    Node<T>* newnode=new Node<T>(data);
    if(head==nullptr){

        head=newnode;
        head->next=head;
        return;
    }
    Node<T>* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=head;
    head=newnode;
    temp->next=head;


    }
    void insertAtEnd(T data){
     Node<T> *newnode=new Node<T>(data);
     Node<T> *temp=head;
      if(head==nullptr){

        head=newnode;
        head->next=head;
        return;
    }
     while(temp->next!=head){
        temp=temp->next;

     }
     newnode->next=head;
     temp->next=newnode;

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
    while(temp->next->next!=head){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=head;
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
        Node<T>*temp1=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        head=head->next;
        delete temp1;
        temp->next=head;

    }
 void displayList(){
  if(head==nullptr){
            cout<< "this linked list is empty\n";
            return;
        }
        Node<T>*temp=head;
       do{
            cout<< temp->data<<" ,";
            temp=temp->next;
        } while(temp!=head);
 }

 };

int main(){
       CircularSingly<string> CList;
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
