#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    cout<<"enter rootdata"<<endl;
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        cout<<"enter the leftchild of "<<currentNode->data<<endl;
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cout<<"enter the rightchild of"<<currentNode->data<<endl;
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
/* 
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    BinaryTreeNode<int>* ans= NULL;
    if(root==NULL)
        return 0;
    if(root->data==k)
        return root;
    if(root->data>k)
        ans=searchInBST(root->left,k);
    else
        ans=searchInBST(root->right,k);
    return ans;

}
*/
void print(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left!=NULL)
    {
        cout<<'L'<<root->left->data<<endl;
    }
    if(root->right!=NULL)
    {
        cout<<'R'<<root->right->data<<endl;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    /* 
    int k;
    cout<<"enter k"<<endl;
    cin >> k;
    BinaryTreeNode<int> *ans = searchInBST(root, k);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    delete root;
*/
print(root);
}