#include <iostream>

using namespace std; // singly circular linked list
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
      friend class circularList<T>;

 };
template <typename T>
 class circularList{
     private:
   Node<T>* head;
  public:
      circularList(){
       this->head=nullptr;}
       void AddAtBegining(T data){
        Node<T>* newNode=new Node<T>( data);
        if(head==nullptr){
            head=newNode;
            head->next=head;
            return;
        }
        newNode->next=head;
        head=newNode;
       }


       void AddAtEnd(T data){
       Node<T>* newNode=new Node<T>(data);
       if(head==nullptr){
        head=newNode;
        head->next=head;

       }
       Node<T>* temp=head;
       while(temp->next!=nullptr){
        temp=temp->next;
       }
       newNode->next=head;
       temp->next=newNode;

       }

       void DeleteAtBegining(){
       if(head==nullptr)return;
       if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
       }
       Node<T>* temp=head;
       head=temp->next;
       delete temp;
          }

    void DeleteAtEnd(){
        if(head==nullptr)return;
       if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
       }
       Node<T>* temp=head;
       while(temp->next->next!=nullptr){
        temp=temp->next;

       }
       delete temp->next;
       temp->next=head;

    }
    void print(){
     if(head==nullptr)return;
     Node<T>* temp=head;
     do{
        cout<< temp->data<< ", ";
     }while(temp!=head);

    }

 };

int main()
{
     circularList<int> linkenList;
    linkenList.AddAtBegining(3);
//    linkenList.AddAtBegining(2);
//    linkenList.AddAtEnd(4);
//    linkenList.AddAtEnd(5);
//    linkenList.AddAtEnd(6);
//    linkenList.AddAtBegining(1);
    cout<< "listemize 1 den 6 ya kadar elemanlari ekledik ve sonuc \n";
//    linkenList.print();
//     linkenList.DeleteAtBegining();
//
//       linkenList.DeleteAtEnd();
//         cout<< "silme iþleminden sonra\n";
//    linkenList.print();
    return 0;
}
