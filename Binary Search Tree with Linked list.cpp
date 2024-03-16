#include <iostream>
#include <queue>

using namespace std;
class Node{ //create Node class
 private:
     int data;
     Node*left; //create left node for linked left child
     Node*right; //create right node for linked right child
 public:
    Node(int data){ // constructor Node class
    this->data=data;
    this->left=nullptr;
    this->right=nullptr;
    }
  friend class BinarySearchIterative;
};
 class BinarySearchIterative{
     private:
   Node*root;     //create root which root of tree
   public:
   BinarySearchIterative(){
    root=nullptr;
    }
    void addElement(int data){ // add elemement in tree
        Node* newNode=new Node(data); // create new node
        if(root==nullptr){ // if  no node in tree so if root is null
            root=newNode;  //  we add new elemen in root node
            return;// finish fonction
        }
        Node* current=root; // we backup root for we travel in tree
        Node* parent=nullptr; // we create  parent node for backup root
        while(current!=nullptr){ // while is true until is not empty in current node
            parent=current;
            if(data<current->data){ // if data  smaller  than data of in current node
                current=current->left; // we assigned current  to left node
            }else{ //if data of new node  bigger than data of in current node
            current=current->right; // we assigned current to right node
            }

        }
        //  so we go to under the tree
        if(data<parent->data){ // if  value of parent smaller than value of new node
            parent->left=newNode; // new node add left of parent

        }else{ // else value of parent bigger than value of new node
         parent->right=newNode; // new node add right of parent
        }


     }
     // REMOVE
     void  remove(int value){  // // take value of removing
          Node* temp=root; //  gezgin düğüm
        Node* parent=nullptr; // gezgin düğümün atası

          while(temp!=nullptr && temp->data!=value){   // Silinecek düğüm bulunana ya da sona gelinene kadar döngü
            parent=temp;
            if(value<temp->data){ // Eğer silinecek değer gezgin düğümün değerinden küçükse sola git
                temp=temp->left;
            }else{
            temp=temp->right;
            }
          } //while bittiğinde ya silinecek düğüm temp değrinde , ya silenecek değer bulunamadi,
          if(temp==nullptr){ // Silinecek düğüm bulunamazsa
            cout << "Can not find Node\n";
            return;
          }
           // case 1:silincek düðümün hiç  ya da bir çocuðu varsa
           if(temp->left==nullptr || temp->right==nullptr){ // silinecek düğümün sağında veya solunda düğüm olup olmadığı kontrol edilir.

            Node* temp1=nullptr; //  eğer sağda veya solda düğüm varsa onu tutması için temp1 i oluşturuyouz.

            if(temp->left==nullptr){ // Eğer silinecek (temp) düğümün sol çocuğu yoksa , sağ çocuğunu temp1 düğüme atar
                temp1=temp->right;  // temp1 e sağdaki düğümü atıyoruz.
            }else{
                temp1=temp->left; // sağda düğüm yoksa temp1 e soldaki düğümü atıyoruz.
            }
             // Silinecek düğümü bağlantılardan çıkar
            if(parent==nullptr) {  // Eğer silinecek(temp) düğüm kökse, temp1 düğümü yeni kök yapar
                root=temp1; // eğer boş ise root temp1 e eşitlenir.
            }else if(temp==parent->left){ // eğer silinecek değer parent ın solundaki çocuk ise

              parent->left=temp1;  //parent ın soluna temp1 i yani silinecek (temp) düğümün varsa solundaki düğümü bağlıyoruz
            }else{
             parent->right=temp1; // eğer silinecek düğüm sağda ise parent ın sağına temp1 bağlanır.
            }
            delete temp; //ve silinecek düğüm temp silinir.

           }
             //  case 2 silinecek düðümün iki çocuðu varsa
             else{
                Node* successor=findSuccessor(root); //Successor (yerine geçecek düğüm)
                int temp1=successor->data; // Successor'un verisi geçici bir değişkende saklanıyor
                remove(successor->data); // Successor düğümü silinerek, yerine geçecek düğümün verisi temp düğümüne kopyalanır
                temp->data=temp1; //Silinen düğümün yerine successor'un verisi koyuluyor
             }

     }
     //LEVEL BY LEVEL
     void levelOrder(){
     if(root==nullptr){ // Eğer ağaç boşsa ekrana mesaj yazdır ve fonksiyondan çık
        cout << "Tree is empty.\n";
        return;
     }
     queue<Node*> kuyruk; //BFS algoritması  için bir queue (kuyruk) oluştur
     kuyruk.push(root);
     while(!kuyruk.empty()){ // Kuyruk boş olana kadar devam et
        int levelSize=kuyruk.size(); // Mevcut seviyedeki düğüm sayısını al
        for(int i=0;i<levelSize;i++){
            Node* temp=kuyruk.front(); // Kuyruğun başındaki düğümü al
            kuyruk.pop(); // Kuyruktan o düğümü çıkar
            cout<< temp->data<< " "; // Düğümün değerini ekrana yazdır
            if(temp->left!=nullptr){  // Eğer sol çocuk varsa, kuyruğa ekle
                kuyruk.push(temp->left);

            }
            if(temp->right!=nullptr){// Eğer sağ çocuk varsa, kuyruğa ekle
                kuyruk.push(temp->right);
            }
        }
     }
  }

      // Successor u bulma
      Node* findSuccessor(Node* node){
          Node* temp=node->right;
          while(temp!=nullptr && temp->left!=nullptr){
            temp=temp->left;
          }
          return temp;
      }


  };

int main()
{
     BinarySearchIterative tree;

        tree.addElement(8);
        tree.addElement(4);
        tree.addElement(5);
        tree.addElement(6);
        tree.addElement(9);
        tree.addElement(10);
        tree.addElement(15);
          tree.addElement(2);
        tree.addElement(3);
        tree.addElement(14);

        cout << " Level Order Traversal: ";
          tree.levelOrder();
           tree.remove(8);
           cout<< endl;
        cout << "level order  after removing 8: ";
               tree.levelOrder();
    return 0;
}
