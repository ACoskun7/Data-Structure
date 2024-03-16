#include <iostream>
using namespace std;

class Node { //node s�n�f� olusturuldu
public:
    int key; // node i�indeki degeri tutmas� icin key degiskeni tan�mland�
    Node *left, *right; //soldaki ve sagdaki cocuklar� tutmalari i�in left ve right pointerlar� olu�turuldu.
    int height;//node un bulundu�u y�ksekli�i tutmak i�in height de�i�keni tan�mland�

    Node(int k) { //consturoctor
        key = k; //gelen de�er key de�i�kenine atand�
        left = nullptr; // left ve right i�arte�ilerine ba�lang�c de�eri olarak nullptr atand�.
        right = nullptr;
        height = 1; /*`height` de�i�kenine ba�lang�� de�eri olarak Node s�n�f�n�n constructor'�nda
        1 de�eri atanmas�n�n sebebi, bu de�erin, e�er bir d���m olu�turuldu�unda, o
         d���m�n y�ksekli�ini temsil etmesidir.

Yeni olu�turulan bir d���m�n y�ksekli�i genellikle 1 olarak atan�r, ��nk� bu d���m yap�s�n�n
yap�c� fonksiyonu, bir yap�n�n en alt�nda oldu�unu ve hi� �ocu�u olmad���n� belirtir. Dolay�s�yla,
bu d���m�n y�ksekli�i 1'dir ��nk� bu d���m tek ba��na bir yaprak d���m�d�r.

Bu de�er daha sonra, d���me �ocuk d���mler eklenirken veya dengelendirme i�lemleri s�ras�nda,
 ger�ek y�ksekli�i temsil edecek �ekilde g�ncellenir. Bu sayede, d���m�n y�ksekli�i her zaman do�ru
  bir �ekilde hesaplanabilir ve a�ac�n dengelenmesi sa�lanabilir.*/
    }
};
/* Node s�n�f�, her bir a�a� d���m�n� temsil eder.
key d���m�n de�erini, left ve right sol ve sa� �ocuk d���mlerini,
 height ise d���m�n y�ksekli�ini tutar. Yap�c� fonksiyon,
  key de�eri verilen d���m� olu�turur.*/

class AVLTree { //AVL tree s�n�f� olu�turuldu
public:
    Node* root; //root du��m� yani k�k d���m olu�turuldu

    int max(int a, int b) { /*a > b ifadesi kontrol edilir.
E�er bu ifade do�ruysa (true ise), yani a, b'den b�y�kse, fonksiyon a'y� d�nd�r�r.
E�er bu ifade yanl��sa (false ise), yani b, a'dan b�y�kse veya e�itse, fonksiyon b'yi d�nd�r�r.*/
        return (a > b) ? a : b;
    }

    int height(Node* node) { //g�nderilen d���m�n y�ksekli�ini geri d�nd�r�r.
        if (node == nullptr) // a�a� bo� ise root==nullptr olur
            return 0; //s�f�r de�eri geri d�nd�r�l�r
        return node->height;
    }
    /*AVLTree s�n�f�, AVL a�ac�n� temsil eder.
     root de�i�keni a�ac�n k�k d���m�n� i�aret eder.
     max fonksiyonu, iki say� aras�ndaki maksimum de�eri d�nd�r�r.
      height fonksiyonu, bir d���m�n y�ksekli�ini hesaplar.*/

    Node* rightRotate(Node* y) {   /*rightRotate fonksiyonu, sa�a d�n�� i�lemi yapar.
    AVL a�ac�nda dengesizli�i gidermek i�in kullan�l�r.
    Burada d���mler yeniden d�zenlenir ve y�kseklikler g�ncellenir.*/
        Node* x = y->left; // x d���m� olu�turulup gelen y d���m�n�n solundaki d���m atan�r
        Node* T2 = x->right;// T2 ad�nda bir d���m olu�turulup x in sa��naki d���m atan�r.

        x->right = y;// x in sa�� gelen d���me e�itlenir
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }


    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
    /*leftRotate fonksiyonu, sola d�n�� i�lemi yapar.
    AVL a�ac�nda dengesizli�i gidermek i�in kullan�l�r.
    Burada d���mler yeniden d�zenlenir ve y�kseklikler g�ncellenir.*/

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }
    /*getBalance fonksiyonu, bir d���m�n denge fakt�r�n� hesaplamak
     i�in kullan�l�r. Denge fakt�r�, bir d���m�n sol alt a�ac�n�n
     y�ksekli�i ile sa� alt a�ac�n�n y�ksekli�i aras�ndaki farkt�r.
     Bu fark, -1, 0 veya 1 olmal�d�r ki a�a� dengeli olsun.
     E�er denge fakt�r� bu s�n�rlar�n d���ndaysa, a�a� yeniden
     dengelenmelidir. getBalance fonksiyonu, bir d���m�n denge
     fakt�r�n� hesaplayarak, a�ac�n dengesiz k�s�mlar�n� tespit
     etmeye yard�mc� olur.*/

    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    /*insert fonksiyonu, bir d���m eklemek i�in kullan�l�r.
     E�er d���m zaten varsa, ekleme i�lemi ger�ekle�tirilmez.
     D���m eklenirken a�ac�n dengesi korunur.*/

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }
    /*minValueNode fonksiyonu ise, bir a�a�taki
     en k���k de�ere sahip d���m� bulmak i�in kullan�l�r.
      AVL a�a�lar�nda, soldaki en alt d���m genellikle en
      k���k de�ere sahip olur. Bu fonksiyon, verilen bir d���m
  alt�ndaki en k���k de�ere sahip d���m� bulur ve geri d�nd�r�r.*/

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
    /*deleteNode fonksiyonu, belirli bir d���m� a�a�tan siler.
    Silme i�lemi ger�ekle�tirilirken a�ac�n dengesi korunur.
Bu kod, AVL a�a�lar�n�n temel �zelliklerini sa�layan ve
 dengeli bir a�a� yap�s�n� koruyan i�levleri i�erir.
 Bu fonksiyonlar, a�a� d���mlerini ekleme, silme ve d�nd�rme gibi
  i�lemler yaparak a�ac�n dengesini korur.*/

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
};


int main() {
    AVLTree tree;
    tree.root = nullptr;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    cout << "Inorder traversal of the constructed AVL tree is \n";
    tree.inorder(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 30);

    cout << "Inorder traversal after deletion of 30 \n";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
