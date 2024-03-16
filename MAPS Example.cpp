#include <iostream>
#include <string>
#include <cctype>


using namespace std;
class Person{ // create person  class for keep the information of key-value
    public:
int number; // for keep key
string name; // for keep value

friend class Node;

};
class Node{ //create node class for creating double linked list
    private:
 Person person; //create person from Person class
 Node* previous; // create  pointer for show previous node
 Node* next; // create pointer for show next node adress
 public:
 Node(int key,string value){ // constructor
     person.name=value;
      person.number=key;
      previous=nullptr;
      next=nullptr;
 }
  Node(){} //create empty constructor
 friend class Maps;
};
class Maps{ //create Maps class for  add ,delete,search, storing and sort data
    private:
  Node* head; // head pointer  show us first node
    public:
  Maps(){ //constructor
  head=nullptr;// we assing nullptr to head pointer
  }

        void AddElement(int key, string value ){ //  fonction is add new key-value in the store
            value[0]=toupper(value[0]); //  toupper fonction is upper first element of string
            Node* newNode=new Node(key,value); // create new node
         if(head==nullptr){ // if head is nullptr we assing head to newNode
                head=newNode;

         }else{ // if maps is not empty
            if(head->next==nullptr){ // just one element in the maps
                head->next=newNode;
                newNode->previous=head;
            }else{ // at least two element in the maps
                Node* current=head; // create current for travel in the maps
              while(current->next!=nullptr){ //for go end of the double linked list
                current=current->next;
              }
               current->next=newNode; // adding node and create linking of between last node and new node
               newNode->previous=current;
            }
         }
        }
        void display(){ // for display double linked list
        if(head==nullptr){ // if list is empty
            cout<<"map is empty!!";
            return;
        }else{ // list is not empty
            Node* current=head; //create current for travel in the maps
         while(current!=nullptr){
            cout<<current->person.number<< " --> "<< current->person.name; // print key and value in the node
            current=current->next;
            printf("\n");
         }
        }

        }
         void searchName(string name){ // search special name that is send as parameter
             name[0]=toupper(name[0]);//firs element of name  string is upper
           if (head==nullptr){ // if list is empty
            cout<< "phone book is empty !!";
            return;
           }else{
            Node* temp=head; //create temp node for travel in the double linked list
            while(temp!=nullptr){ // travel in the double linked list

                 if(name==temp->person.name){ //  if name is same name in the node
                    cout<< temp->person.name<< "---> "<<temp->person.number<<endl; // print key and value(name) in the node

                 }

                temp=temp->next; // pass next node
            }
           }
         }




         void sortList(){ // sorting according to alphabetical order
             Node*current=head; //create node for travel in the list
             if(head==nullptr){// if list is empty
                cout<<"Phone book is empty!!";
                return;
             }else if(head->next==nullptr){// if list have a element
                 cout<< head->person.name << "---> "<< head->person.number;
                 return;
              }else{ // if list have two or more element
                     while(current!=nullptr){ //travel in the list
                    Node* nextNode=current->next; // create another node for compare
                    while(nextNode!=nullptr){// create another node for compare
                         if (current->person.name.compare(nextNode->person.name) > 0){ // compare values in the node and if order is wrong ,change addressig of them
                                Node* temp=new Node(); // for backup value
                         temp->person=current->person; // exchange nodes
                         current->person=nextNode->person;
                         nextNode->person=temp->person;

                 }
                 nextNode=nextNode->next;// pass next node
                    }
                current=current->next; // pass next node
             }
                Node* temp=head;
         while(temp!=nullptr){ // print sorted list
            cout<<temp->person.number<< " --> "<< temp->person.name;
            temp=temp->next;
            printf("\n");

        }




         }
         }
         void printBetweenTwoName(string name1,string name2){ // print  names of between name1 and name2.  user send parameter as name1 and name2
             name1[0]=toupper(name1[0]);// first element of name1 is upper
             name2[0]=toupper(name2[0]);
          if(head==nullptr || head->next==nullptr){ // if list is empty or have a element
            cout<<"There is a person or no registering";
            return;
          }else{
            Node *temp=head; // for travel create a node
            int counter=0; // for check presence of name1 and name2
            while(temp!=nullptr){
                 if(temp->person.name==name1||temp->person.name==name2){counter++;}

                 temp=temp->next;
            }
            if(counter==2){ // if counter ==2 there are  name1 and name2 in the list

                    Node *current=head;// for travel in the list
             while(current!=nullptr){ //travel in the list
                if(current->person.name==name1||current->person.name==name2){ // if name1 or name2 same name in the node
                    while(current!=nullptr){ // run this loop and print key and value in the nodes
                        cout<<current->person.name<< "--->"<<current->person.number;
                        cout<<endl;
                        current=current->next;
                        if(current->person.name==name1||current->person.name==name2){ // if name same name1 or name2
                                 cout<<current->person.name<< "--->"<<current->person.number; // print name of node
                            return; //and finish function
                        }
                    }
                }
            current=current->next; // pass  the other node
             }

            }else{ // other cases
            cout<<"there are not name of you entered";}
          }



         }
         void Delete(string name){ // delete function. giving parameter from user name of deleting
                 name[0]=toupper(name[0]); // to upper first element of deleting name
             if(head==nullptr){ // if list is empty
                cout<<"There is no register.";
                return;
             }else{ //other cases
                     Node* temp=head;//bakup head
           while(temp!=nullptr){ // travel in the list
            if(temp->person.name==name){ // if name of in the node equals to deleting name
                temp->previous->next=temp->next; // create new linking
                temp->next->previous=temp->previous;
                delete temp; // delete temp
            }
            temp=temp->next;// pass next node
           }
              }



         }
         void setNumber(string name, int number){ // change key in the node
          name[0]=toupper(name[0]);
            if(head==nullptr){
                cout<<"There is no register.";
                return;
             }
                Node* temp=head;
                while(temp!=nullptr){
            if(temp->person.name==name){
                temp->person.number=number;
            }
            temp=temp->next;
           }

         }
         void sizeOfList(){ // print size of list
             int size=0;
            if(head==nullptr){
                cout<<"There is no register.";
                return;
             }
                Node* temp=head;
                while(temp!=nullptr){
              size++;
            temp=temp->next;
           }
             cout<<"Size of phone book : "<< size<< "\n";

         }




};

int main()
{
    Maps phoneBook;

      phoneBook.AddElement(351787714,"ibrahim");
      phoneBook.AddElement(51478174,"osman");
      phoneBook.AddElement(511875,"kubilay");
       phoneBook.AddElement(641514156,"busra");
          phoneBook.AddElement(5411871,"ahmet");
     phoneBook.AddElement(54151777,"mehmet");
     phoneBook.AddElement(7477717,"abdullah");
     phoneBook.AddElement(841777117,"defne");
      phoneBook.display();
      cout<< "----------------------------\n";
      cout<< "seach name of ahmet : ";
        phoneBook.searchName("ahmet");

     phoneBook.sortList();
       cout<< "\n----------------------------\n";
       phoneBook.printBetweenTwoName("ahmet","defne");
       cout<<"\nAfter delete Mehmet registiry \n";
       phoneBook.Delete("mehmet");
     phoneBook.display();
      phoneBook.printBetweenTwoName("ahmet","defne");
       cout<<"\nAfter update number of ahmet \n";
       phoneBook.setNumber("ahmet",15);
     phoneBook.display();
     phoneBook.sizeOfList();

    return 0;
}
