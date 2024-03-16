#include <iostream>

using namespace std;
/*double linked list ile singly linked list arasindaki tek fark bir isaretcinin fazla olmasýdýr */


class Node{
 public:
    int data;
    Node* next;
    Node* previous;
  public:
    Node(int data){
    this->data=data;
    previous=next=nullptr;
    }
    friend class doubleList;

};
class doubleList{
  private:
      Node* head;
  public:
    doubleList(){
    this->head=nullptr;
    }



     void AddAtBegining(int data){
      Node* newNode=new Node(data);
      if(head==nullptr){
        head=newNode;
        return;
      }
      newNode->next=head;
      head->previous=newNode;
      head=newNode;

     }
     void AddAtEnd(int data){
        Node* newNode=new Node(data);
        if(head==nullptr){
            head=newNode;
            return;
        }
        if(head->next==nullptr){
            head->next=newNode;
            newNode->previous=head;
            return;

        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->previous=temp;



     }
     void DeleteAtBegining(){
    if(head==nullptr)return;
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
    Node* temp=head;
    head=temp->next;
    delete temp;
    head->previous=nullptr;



     }
     void DeleteAtEnd(){
       if(head==nullptr)return;
       if(head->next==nullptr){
        delete head;
        head=nullptr;
       }
       Node* temp=head;
       while(temp->next!=nullptr){
        temp=temp->next;
       }
      Node* temp1=temp->previous;
       delete temp;
       temp1->next=nullptr;

     }
     void print(){
      if(head==nullptr)return;
      Node *temp=head;
      while(temp!=nullptr){
        cout<< temp->data <<", ";
        temp=temp->next;
      }


     }


};

int main()
{
    doubleList linkenList;
    linkenList.AddAtBegining(3);
    linkenList.AddAtBegining(2);
    linkenList.AddAtEnd(4);
    linkenList.AddAtEnd(5);
    linkenList.AddAtEnd(6);
    linkenList.AddAtBegining(1);
    cout<< "listemize 1 den 6 ya kadar elemanlari ekledik ve sonuc \n";
    linkenList.print();
     linkenList.DeleteAtBegining();

       linkenList.DeleteAtEnd();
         cout<< "silme iþleminden sonra\n";
    linkenList.print();
    return 0;
}
