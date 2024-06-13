#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    //constructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public :
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; //intializing ROOT is null
    }

    void insert(string element) //insert a node in the binary search tree
    {
        Node* newNode = new Node(element, nullptr, nullptr); //allocate memory for the new node
        newNode->info = element; //assign value to the data field of the new node
        newNode->leftchild = nullptr; //Make left child of the new node point to null
        newNode->rightchild = nullptr; //Make right child of the new node point to null

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //locate the node which will be the parent of the node to be insert

        if (parent == nullptr) //if the parent is NULL (Tree is empty)
        {
            ROOT = newNode; //Mark the new node as ROOT
            return; //Exit
        }

        if (element < parent->info) //if the value in the data field in the node is less than that of the
        {
            parent->leftchild = newNode; //make the left child of the parent point to the new node
        }

        else if (element > parent->info) //if the value in the data field of the new node is greater than that
        {
            parent->rightchild = newNode;
        }
    }
    void search(string element, Node*& parent, Node*& currentNode)
    {
        //this function searches the currentNode of the specified Node as well as the current Node of its parent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void inorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node* ptr)
    {
        if (ROOT == nullptr)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }
};

int main()
{
}