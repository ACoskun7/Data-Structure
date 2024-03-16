#include <iostream>

using namespace std;
class Node{  //determine to Node class
private:
    int data;
    Node*next;
public:
    Node(int data){
    this->data=data;
    this->next=nullptr;
    }
    friend class LinkedQueue; //for  linkedqueue  use Node class attributes


};
class LinkedQueue{ //determine linkedqueue
  public:
Node* head;      // a pointer for keep first adress of linked list
int sizeOfQueue; //size of queue

LinkedQueue(){ //constructor
head=nullptr; // initially value of head

sizeOfQueue=0; //initially value of size of linked list
}
  void Enqueue(int data){ // to insert to queue or linked list
Node* newNode=new Node(data); // create a new node
newNode->next=head; // pointer of newnode  assign head
head=newNode; // head indicate newnode so we always add new node on rear
sizeOfQueue++; //  we do not forget  increment of  sizeofNode
}
void Dequeue(){ //remove node
if(head==nullptr){  // if queue has no element
    cout<< "queue is empty\n";
    return;
}
if(head->next==nullptr){ //if there is only one element in the queue
    delete head; // we remove head because queue has just only element
    head->next=nullptr;
    sizeOfQueue--; //we do not forget to decrease the sizeofnode
}else{  //if there are many elements in the queue
Node* temp=head; //we create a now node and indicate head
while(temp->next->next!=nullptr){
    temp=temp->next; //we go to front of queue

}
delete temp->next; //we remove element that front of queue FIFO first in first out  or  LILO  last in last out
temp->next=nullptr; // we dont forget temp next assing nullptr
sizeOfQueue--;
}
}
int getFront(){ // return element that front queue
 if(head==nullptr){ // if no element in Queue
    cout<<"queue is empty\n";
   return -1;
 }else{
 Node* temp=head;
 while(temp->next!=nullptr){// go to front of queue
    temp=temp->next;
 }
 return temp->data;// return element of front of queue
 }

}
int getRear(){ // return elenment of end of queue
 if(head==nullptr){ // if no elements in queue
    cout<<"queue is empty\n";
   return -1;
}else{
return head->data;// return element of end of queue
}

}
int Size(){ //return size of queue
return sizeOfQueue;
}
void DisplayQueue(){ //display elements of in the queue
 if(head==nullptr){ // if no element in the queue
     cout<<"queue is empty\n";
   return ;
 }else{
 Node* temp=head;
 while(temp!=nullptr){
    cout<<temp->data<< " " ; //print value of in linkedlist queue
    temp=temp->next;

 }
 }

}


};
void exchage(LinkedQueue q1,LinkedQueue q2){ // to exchange values two queue
LinkedQueue temp;
temp=q1;
q1=q2;
q2=temp;
cout <<"Queue1 : \n";
  q1.DisplayQueue();
          cout<<"\n size of queue: "<<q1.Size();
          cout<<" \n front is : "<<q1.getFront();
          cout <<" \n rear is : " <<q1.getRear()<<"\n";
          cout <<"Queue2 : \n";
           q2.DisplayQueue();
          cout<<"\n size of queue: "<<q2.Size();
          cout<<" \n front is : "<<q2.getFront();
          cout <<" \n rear is : " <<q2.getRear()<<"\n";

}


int main()
{
  LinkedQueue q1,q2;
  q1.Enqueue(1);
    q1.Enqueue(2);
      q1.Enqueue(3);
        q1.Enqueue(4);
          q1.Enqueue(5);
           cout <<"Queue1 : \n";
          q1.DisplayQueue();

          cout<<"\n size of queue: "<<q1.Size();
          cout<<" \n front is : "<<q1.getFront();
          cout <<" \n rear is : " <<q1.getRear()<<"\n";
//          q1.Dequeue();
//              q1.Dequeue();
//                  q1.Dequeue();

             q2.Enqueue(6);
        q2.Enqueue(7);
          q2.Enqueue(8);
           q2.Enqueue(9);
        q2.Enqueue(42);
          q2.Enqueue(21);
          cout <<"Queue 2: \n";
          q2.DisplayQueue();
          cout<<"\n size of queue: "<<q2.Size();
          cout<<" \n front is : "<<q2.getFront();
          cout <<" \n rear is : " <<q2.getRear()<<"\n";
          exchage(q1,q2);


    return 0;

}
