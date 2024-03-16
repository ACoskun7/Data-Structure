#include <iostream>
using namespace std;

class Node { //node sýnýfý olusturuldu
public:
    int key; // node içindeki degeri tutmasý icin key degiskeni tanýmlandý
    Node *left, *right; //soldaki ve sagdaki cocuklarý tutmalari için left ve right pointerlarý oluþturuldu.
    int height;//node un bulunduðu yüksekliði tutmak için height deðiþkeni tanýmlandý

    Node(int k) { //consturoctor
        key = k; //gelen deðer key deðiþkenine atandý
        left = nullptr; // left ve right iþarteçilerine baþlangýc deðeri olarak nullptr atandý.
        right = nullptr;
        height = 1; /*`height` deðiþkenine baþlangýç deðeri olarak Node sýnýfýnýn constructor'ýnda
        1 deðeri atanmasýnýn sebebi, bu deðerin, eðer bir düðüm oluþturulduðunda, o
         düðümün yüksekliðini temsil etmesidir.

Yeni oluþturulan bir düðümün yüksekliði genellikle 1 olarak atanýr, çünkü bu düðüm yapýsýnýn
yapýcý fonksiyonu, bir yapýnýn en altýnda olduðunu ve hiç çocuðu olmadýðýný belirtir. Dolayýsýyla,
bu düðümün yüksekliði 1'dir çünkü bu düðüm tek baþýna bir yaprak düðümüdür.

Bu deðer daha sonra, düðüme çocuk düðümler eklenirken veya dengelendirme iþlemleri sýrasýnda,
 gerçek yüksekliði temsil edecek þekilde güncellenir. Bu sayede, düðümün yüksekliði her zaman doðru
  bir þekilde hesaplanabilir ve aðacýn dengelenmesi saðlanabilir.*/
    }
};
/* Node sýnýfý, her bir aðaç düðümünü temsil eder.
key düðümün deðerini, left ve right sol ve sað çocuk düðümlerini,
 height ise düðümün yüksekliðini tutar. Yapýcý fonksiyon,
  key deðeri verilen düðümü oluþturur.*/

class AVLTree { //AVL tree sýnýfý oluþturuldu
public:
    Node* root; //root duðümü yani kök düðüm oluþturuldu

    int max(int a, int b) { /*a > b ifadesi kontrol edilir.
Eðer bu ifade doðruysa (true ise), yani a, b'den büyükse, fonksiyon a'yý döndürür.
Eðer bu ifade yanlýþsa (false ise), yani b, a'dan büyükse veya eþitse, fonksiyon b'yi döndürür.*/
        return (a > b) ? a : b;
    }

    int height(Node* node) { //gönderilen düðümün yüksekliðini geri döndürür.
        if (node == nullptr) // aðaç boþ ise root==nullptr olur
            return 0; //sýfýr deðeri geri döndürülür
        return node->height;
    }
    /*AVLTree sýnýfý, AVL aðacýný temsil eder.
     root deðiþkeni aðacýn kök düðümünü iþaret eder.
     max fonksiyonu, iki sayý arasýndaki maksimum deðeri döndürür.
      height fonksiyonu, bir düðümün yüksekliðini hesaplar.*/

    Node* rightRotate(Node* y) {   /*rightRotate fonksiyonu, saða dönüþ iþlemi yapar.
    AVL aðacýnda dengesizliði gidermek için kullanýlýr.
    Burada düðümler yeniden düzenlenir ve yükseklikler güncellenir.*/
        Node* x = y->left; // x düðümü oluþturulup gelen y düðümünün solundaki düðüm atanýr
        Node* T2 = x->right;// T2 adýnda bir düðüm oluþturulup x in saðýnaki düðüm atanýr.

        x->right = y;// x in saðý gelen düðüme eþitlenir
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
    /*leftRotate fonksiyonu, sola dönüþ iþlemi yapar.
    AVL aðacýnda dengesizliði gidermek için kullanýlýr.
    Burada düðümler yeniden düzenlenir ve yükseklikler güncellenir.*/

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }
    /*getBalance fonksiyonu, bir düðümün denge faktörünü hesaplamak
     için kullanýlýr. Denge faktörü, bir düðümün sol alt aðacýnýn
     yüksekliði ile sað alt aðacýnýn yüksekliði arasýndaki farktýr.
     Bu fark, -1, 0 veya 1 olmalýdýr ki aðaç dengeli olsun.
     Eðer denge faktörü bu sýnýrlarýn dýþýndaysa, aðaç yeniden
     dengelenmelidir. getBalance fonksiyonu, bir düðümün denge
     faktörünü hesaplayarak, aðacýn dengesiz kýsýmlarýný tespit
     etmeye yardýmcý olur.*/

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
    /*insert fonksiyonu, bir düðüm eklemek için kullanýlýr.
     Eðer düðüm zaten varsa, ekleme iþlemi gerçekleþtirilmez.
     Düðüm eklenirken aðacýn dengesi korunur.*/

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }
    /*minValueNode fonksiyonu ise, bir aðaçtaki
     en küçük deðere sahip düðümü bulmak için kullanýlýr.
      AVL aðaçlarýnda, soldaki en alt düðüm genellikle en
      küçük deðere sahip olur. Bu fonksiyon, verilen bir düðüm
  altýndaki en küçük deðere sahip düðümü bulur ve geri döndürür.*/

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
    /*deleteNode fonksiyonu, belirli bir düðümü aðaçtan siler.
    Silme iþlemi gerçekleþtirilirken aðacýn dengesi korunur.
Bu kod, AVL aðaçlarýnýn temel özelliklerini saðlayan ve
 dengeli bir aðaç yapýsýný koruyan iþlevleri içerir.
 Bu fonksiyonlar, aðaç düðümlerini ekleme, silme ve döndürme gibi
  iþlemler yaparak aðacýn dengesini korur.*/

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
