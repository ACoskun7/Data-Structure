#include <iostream>

using namespace std;


class Node{
  private:
    int data;
    Node* next;
  public:
    Node(int data){
    this->data=data;
    this->next=nullptr;
    }
    friend class singlyList;

};
class singlyList{
  private:
      Node* head;
  public:
    singlyList(){
    this->head=nullptr;
    }
     void AddAtBegining(int data){
       Node* newNode=new Node(data);
       newNode->next=head;
       head=newNode;

     }
     void AddAtEnd(int data){
         Node* newNode=new Node(data);

          if(head==nullptr){
             head=newNode;
        return;
          }
          Node* temp=head;
       while(temp->next!=nullptr){
        temp=temp->next;
       }
       temp->next=newNode;

     }
     void DeleteAtBegining(){

       if(head==nullptr)return;
       if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
       }
       Node *temp=head;
       head=temp->next;
       delete temp;

     }
     void DeleteAtEnd(){
      if(head==nullptr)return;
      Node* temp=head;
      if(temp->next==nullptr){
        head=nullptr;
        delete temp;
      return;

      }
      while(temp->next->next!= nullptr){
        temp=temp->next;

      }
      delete temp->next;
      temp->next=nullptr;

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
    singlyList linkenList;
    linkenList.AddAtBegining(3);
    linkenList.AddAtBegining(2);
    linkenList.AddAtEnd(4);
    linkenList.AddAtEnd(5);
    linkenList.AddAtEnd(6);
    linkenList.AddAtBegining(1);
    cout<< "listemize 1 den 6 ya kadar elemanlarý ekledik ve sonuç \n";
    linkenList.print();
       linkenList.DeleteAtBegining();

       linkenList.DeleteAtEnd();
         cout<< "\n silme isleminden sonra\n";
    linkenList.print();
    return 0;
}
