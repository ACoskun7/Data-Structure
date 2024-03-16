#include <iostream>

using namespace std;
//actually singly linked list hem bir queue hem de bir stack kullan�m�d�r
// linked listin i�ine alacagimiz elemanlari bastan ekleyip bastan c�kart�rsak bu bir stack kullan�m� oluyor  tersi de olur sondan ekleyip sondan cikartabiliriz(L�FO)
// ama linked listin icine alacagimiz elemanlar� ba�tan ekleyip sondan cikartirsak bu da bir queue ornegidir tam tersi de olur sondan ekleyip bastan da c�kartabiliriz (FIFO)
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
     friend class LinkedListQueue  ;


};
template <typename T>
class LinkedListQueue{
public:
     Node<T>* head;
     LinkedListQueue(){
     this->head=nullptr;
     }
     void push(T data){
     Node<T>*newnode=new Node<T>(data);
      Node<T>*temp=head;
     if(head==nullptr){
        head=newnode;
        return;
     }else{
         while(temp->next!=nullptr){
            temp=temp->next;
         }
   temp->next=newnode;// burada sondan ekleme yaptigimiz icin bastan cikarmam lazim ;
     }


     }
     void pop(){

      T temp1;
      if(head==nullptr){
    cout<< "\n the queue is empty";
    return;
      }
      if(head->next==nullptr){
            temp1=head->data;
        delete head;
      cout<< temp1 <<" popped from the queue \n";
        head=nullptr;
      }else{
          Node<T>*temp=head;// bas kopyalandi
            temp1=head->data; // burada bastaki eleman kopyalandi
           head=head->next; //bas bir kaydirildi

           delete temp; //bastaki eleman silindi
       cout<< temp1 <<" popped from the queue \n";

      }



     }
     void display(){
      if(head==nullptr){
        cout<<" this queue is empty\n";
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
        cout<<" this queue is empty\n";
        return;
      }
      Node<T>*temp=head;
      int sizeofStack =0;
      while(temp!=nullptr){
        sizeofStack++;
        temp=temp->next;
      }
      cout<< "size of queue : "<<sizeofStack<<"\n\n";
     }
};

int main()
{
    LinkedListQueue<int> listQueue ;
    listQueue.push(1);
    listQueue.push(2);
    listQueue.push(3);
    listQueue.push(4);
    listQueue.push(5);
    listQueue.display();
    listQueue.sizeStack();
    listQueue.pop();
    listQueue.pop();
    cout<<"\n********************************************************\n";
     listQueue.display();
    listQueue.sizeStack();
    return 0;
}
