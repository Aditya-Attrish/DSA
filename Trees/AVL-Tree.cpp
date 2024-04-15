/*Tree is hierarchical Data
Structures.*/
/*AVL tree solves problem of BST.*/
/*Which Balance Factor is -1, 0 or
1 is called AVL Tree.*/
/*One of the most popular balanced
tree was introduced by Adelson-Velskii
and landis (AVL).*/
/*BF = h(LT) - h(RT) */
/*Rotation
LL & RR rotation //It makes 'A''s child 'B'
RL & LR rotation //It makes 'C''s child 'A' and 'B'
*/
#include<iostream>
#include<stdio.h>
using namespace std;

class AvlTree {
	
	// private members
	struct Node
	{
		int info;
		short Height;
		Node *left,
		*right;
		Node(int data) {
			Height = 0;
			info = data;
			left = NULL;
			right = NULL;
		}
	};
	Node *root;
	inline short height(Node *curr){
		return curr ? curr->Height : -1;
	}
	Node* RR_rotation(Node *curr) {
		Node *p,
		*Cnext = curr->right;
		p = Cnext->left;
		Cnext->left = curr;
		curr->right = p;
		curr->Height = max(height(curr->right), height(curr->right))+1;
		//Cnext->Height = max(height(Cnext->right), height(Cnext->right))+1;
		return Cnext;
	}
	Node* LL_rotation(Node *curr) {
		Node *p,
		*Cnext = curr->left;
		p = Cnext->right;
		Cnext->right = curr;
		curr->left = p;
		curr->Height = max(height(curr->right), height(curr->right))+1;
		//Cnext->Height = max(height(Cnext->right), height(Cnext->right))+1;
		return Cnext;
	}
	Node* LR_rotation(Node *curr) {
		Node *NLR = curr->left->right;
		NLR->right = curr;
		NLR->left = curr->left;
		curr->left->right = NULL;
		curr->left = NULL;
		curr->Height = max(height(curr->right), height(curr->right))+1;
		NLR->left->Height = max(height(NLR->left->right), height(NLR->left->right))+1;
		return NLR;
	}
	Node* RL_rotation(Node *curr){
		// assign  left node  of right of curr pointer in NRL pointer
		Node *NRL = curr->right->left;
		
		// assign curr pointer in NRL's left pointer
		NRL->left = curr;
		
		// assign curr's right pointer in NRL's right pointer
		NRL->right = curr->right;
		
		// assign NULL
		curr->right = curr->right->left = NULL;
		
		// set Height children
		NRL->left->Height = max(height(NRL->left->left), height(NRL->left->right))+1;
		NRL->right->Height = max(height(NRL->right->left), height(NRL->right->right))+1;
		
		return NRL;
	}
	Node* recursive_insert(Node *troot, int data) {
		if(troot == NULL)
			return new Node(data);
			
		if(troot->info > data) {
			troot->left = recursive_insert(troot->left, data);
			if(height(troot->left) - height(troot->right) == 2) {
				if(data < troot->left->info)
					troot = LL_rotation(troot);
				else
					troot = LR_rotation(troot);
			}
		}
		else if(troot->info < data) {
			troot->right = recursive_insert(troot->right, data);
			if(height(troot->right) - height(troot->left) == 2) {
				if(data > troot->right->info)
    				troot = RR_rotation(troot);
    			else
    				troot = RL_rotation(troot);
			}
		}
		troot->Height = max(height(troot->left), height(troot->right))+1;
		return troot;
	}
	
	void preOrder(Node *r) {
		if(r) {
			cout<<r->info<<" ";
			preOrder(r->left);
			preOrder(r->right);
		}
	}
	void delete_all_nodes(Node *r) {
		if(r) {
			delete_all_nodes(r->left);
			delete_all_nodes(r->right);
			delete r;
		}
	}
	Node* findMax(Node *root) {
		if(root->right == NULL)
			return root;
		else
			return findMax(root->right);
	}
	Node* recursive_delete_node(Node *root, int key) {
		if(!root)
			return NULL;
		
		if(root->info > key) {
			root->left = recursive_delete_node(root->left, key);
		}
		else if(root->info < key){
			root->right = recursive_delete_node(root->right, key);
		}
		else
		{
			Node *temp;
			if(root->left && root->right) {
				temp = findMax(root->left);
				root->info = temp->info;
				root->left = recursive_delete_node(root->left, root->info);
			}
			else {
				temp = root;
				if(root->right)
					root = root->right;
				else if(root->left)
					root = root->left;
			 	else // left and right both are NULL
					root = NULL;
				delete temp;
				return root;
			}
		}
		root->Height = max(height(root->left), height(root->right))+1;
		return root;
	}
	
	// public members
	public:
	AvlTree(){
		root = NULL;
	}
	
	~AvlTree(){
		delete_all_nodes(root);
	}
	
	inline void insert(int data){
		this->root = recursive_insert(this->root, data);
	}
	
	inline void delete_node(int data){
		this->root = recursive_delete_node(this->root,data);
	}
	
	void print(){
		preOrder(this->root);
		cout<<endl;
	}
	
	inline short getHeight(){
		return height(this->root)+1;
	}
	
	int Search(int data) {
		Node *s = this -> root;
		while(s) {
			if(s->info < data)
				s = s->right;
			else if(s->info > data)
				s = s->left;
			else
				return s->info;
		}
		return -1;
	}
};

int main() {
	
	AvlTree avl;
	avl.insert( 5); //2
    avl.insert( 7); //1
    avl.insert( 19); //0
    avl.insert( 12);
    avl.insert( 10);
    avl.insert( 15);
    avl.insert( 18);
    avl.insert( 20);
    avl.insert( 25);
    avl.insert( 23);
    cout<<avl.getHeight()<<endl;
//    recursive_delete_node(root, 12);
//	root = recursive_delete_node(root, 5);
	avl.print();
	return 0;
}