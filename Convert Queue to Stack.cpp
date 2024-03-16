#include <iostream>

using namespace std;

// we create node class for keep node of linked list
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // Constructor
    Node(T data) {
      this->data = data;     // value of  node
      this->next = nullptr;   // first value of pointer should be nullptr.
    }
    template<typename U>
    friend class  LinkList;
};

// LinkList
template<typename U>
class LinkList {
private:
    Node<U>* head; //we create head node for keep initially adress of linked list

public:
    // Constructor
    LinkList() {
        this->head = nullptr;//initially value is nullptr.
    }
        //Method for add  an element at the beginning of the list.
    void addAtBeginning(U data) {
        Node<U>* newNode = new Node<U>(data);  // created new node
        newNode->next = head;
        head = newNode;
    }
     //Method to add  an element at the end of the list.
    void addAtEnd(int data) {
        Node<U>* newNode = new Node<U>(data);
        if (head == nullptr) {  //if no element in list.
            head = newNode;
            return;   //Stop the method.
        }
        if(head->next==nullptr){
            head->next=newNode;
            return;
        }
        Node<U>* temp = head; //copy head for to move in list
        while (temp->next != nullptr) { // go till element of end of list.
            temp = temp->next;  //assign next address   to temp.
        }
        temp->next = newNode; //  adding new node to end of list.
    }


    // Method to remove  the element at the beginning of the list.
    void removeAtBeginning() {
        if (head == nullptr) {  //if no element in list.
            return;  //Stop the method.
        }
        Node<U>* temp = head;// copy head
        head = head->next; // head move one step
        delete temp;  //remove  the temp
    }



    //Method to remove the element at the end of the list.
    void removeAtEnd() {
        if (head == nullptr) {  //if no element in list.
            return;   // Stop the method .
        }
        if (head->next == nullptr) { // if list has one element.
            delete head; // remove  element.
            head = nullptr;  //  there is no element so initially value of head is should be nullptr.
            return;   // Stop the Method.
        }
        Node<U>* temp = head;
        while (temp->next->next != nullptr) { //go till  the element before the last element.
            temp = temp->next;
        }
        delete temp->next;// remove last element .
        temp->next = nullptr; // pointer of node that before last element indicate nullptr.
    }

    //display the first element of the list.
    U displayFirstElement() {
        if (head == nullptr) {   //if no element in list.
            cout << "This list is empty.";
        }
        return head->data;
    }

    //display  the last element of the list.
    U displayLastElement() {
        if (head == nullptr) {  //if no element in linked list.
            cout << "This list is empty";
        }
        Node<U>* temp = head;   //we copy head   to move between nodes.
        while (temp->next != nullptr) { //go till  the element of end of list .
            temp = temp->next;
        }
        return temp->data;
    }



    // display  the elements of the list.
    void displayList() {
        if (head == nullptr) {
            cout << "There is no element in the linked list" << "\n";
            return;
        }


        Node<U>* temp = head;    // create a temporary node.
        while (temp!= nullptr){  // go till  the last element.
            cout << temp->data << "\n"; //display  data.
            temp = temp->next; // pass next node
        }


    }

    //  get the size of the list.
    int getSize() {
        int listSize = 0;
        Node<U>* temp = head;
        while (temp != nullptr) {  // go till   element of end of list.
            listSize++;           //increase the size +1.
            temp = temp->next; // pass next node
        }
        return listSize;
    }
};
// Queue class.
template<typename Q>
class Queue {
private:
    LinkList<Q> linkList; // Composition

public:
    // enqueue an element into the queue.
    void enqueue(Q data) {
        linkList.addAtEnd(data);
    }

    //  dequeue an element from the queue.
    void dequeue() {
        linkList.removeAtBeginning();
    }

    // get the front element of the queue.
    Q frontOfList() {
       return linkList.displayFirstElement();
    }

    // get the rear element of the queue.
    Q rearOfList() {
       return linkList.displayLastElement();
    }

    //  check if the queue is empty.
    bool isEmpty() {
        return linkList.getSize() == 0;
    }

    // display the elements of the queue.
    void displayQueue() {
        cout << "Queue elements: \n";
        linkList.displayList();
    }
};

// Stack class .
template <typename S>
class Stack {
private:
    LinkList<S> linkList; // Composition

public:
    //display the top element of the stack.
    void top() {
        linkList.displayLastElement();   //
        cout << linkList.displayFirstElement();
    }

    //  push an element onto the stack.
    void push(S data) {
        linkList.addAtBeginning(data);
    }

    // pop an element from the stack.
    void pop() {
        linkList.removeAtBeginning();
    }

    // check if the stack is empty.
    bool isEmpty() {
        return linkList.getSize() == 0;
    }

    // display  the elements of the stack.
    void displayStack() {
        cout << "Stack elements: \n";
        linkList.displayList();
    }
};


// Function to convert a Queue to a Stack.
template <typename A, typename B>
Stack<A> convertToStack(Queue<B>& que) {
    Stack<A> stak;
    Queue<B> temp = que;
    while (!temp.isEmpty()) {
        stak.push(temp.frontOfList());
        temp.dequeue();
    }
    return stak;
}


// Main function program starts here.
int main() {


    // Create an Queue.
    Queue<int> myque;
    myque.enqueue(10);
    myque.enqueue(20);
    myque.enqueue(30);


    // Convert the Queue to a Stack.
   Stack<int> mystack = convertToStack<int>(myque);
   cout<< "top of Stack : ";
   mystack.top();



    // display the Stack.
    cout << "\nStack elements after converting from Queue: \n";
    mystack.displayStack();


    return 0;
}
