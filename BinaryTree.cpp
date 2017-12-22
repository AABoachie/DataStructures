#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node * left;
	Node * right;
};

struct Tree{
	int count;
	Node * root;
	Tree(){
		count = 0;
		root = NULL;
	}
};

Node * findMin(Node * node);
Tree * createTree(){
	Tree * tree = new Tree();
	return tree;
}

Node * createNode(int data){
	Node * node = new Node();
	node->data = data;
	return node;
}

Node * findParentRecursive(Node * node, int data){
	if(node->data == data){
		return NULL;
	}
	if(data < node->data){
		if(node->left != NULL){
			if(node->left->data == data){
				return node;
			}
			else{
				findParentRecursive(node->left, data);
			}
		}else{
			return NULL;
		}
	}else{
		if(node->right != NULL){
			if(node->right->data == data){
				return node;
			}else{
				findParentRecursive(node->right, data);
			}
		}else{
			return NULL;
		}
	}
}

Node * findParent(Node * node, int data){
	return findParentRecursive(node, data);
}

Node * findNodeRecursive(Node * current, int data){
	if(current != NULL){
		if(data < current->data){		
			return findNodeRecursive(current->left, data);
		}
		else if(data > current->data){
			return findNodeRecursive(current->right, data);
		}else{
			return current;
		}
	}else{
		return NULL;
	}
}
Node * findNode(Node * node, int data){
	return findNodeRecursive(node, data);
}
void insertNode(Node * current, Node * data){
	if(data->data < current->data){
		if(current->left == NULL){
			current->left = data;
		}else{
			insertNode(current->left, data);
		}
	}else{
		if(current->right == NULL){
			current->right = data;
		}else{
			insertNode(current->right, data);
		}
	}
}
void insert(Tree * tree, Node * data){
	if(tree->root ==  NULL){
		tree->root = data;
	}else{
		insertNode(tree->root, data);
	}
}
bool containsRecursive(Node * current, int data){
	if(current != NULL){
		if(data < current->data){		
			return containsRecursive(current->left, data);
		}
		else if(data > current->data){
			return containsRecursive(current->right, data);
		}else{
			return true;
		}
	}else{
		return false;
	}
}
bool contains(Tree * tree, int data){
	return containsRecursive(tree->root, data);
}
bool deleteNodeRecursive(Node * root, int data){
	if (root == NULL){
		return false;
	}
	Node * node = findNode(root, data);
	Node * parent = findParent(root, data);
	
	if(node->left == NULL && node->right == NULL){
		if(node->data < parent->data){
			parent->left = NULL;
			delete node;			
		}else{
			parent->right = NULL;
			delete node;
		}		
	}else if(node->left == NULL && node->right != NULL){
		if(node->data < parent->data){
			parent->left = node->right;
			delete node;			
		}else{
			parent->right = node->right;
			delete node;
		}
	}else if(node->left != NULL && node->right == NULL){
		if(node->data < parent->data){
			parent->left = node->left;
			delete node;			
		}else{
			parent->right = node->left;
			delete node;
		}
	}else{
		Node * min = findMin(root->left);
		node->data = min->data;
		Node * minParent = findParent(root,  min->data);
		minParent->left = min->right;
		
	}	
	return true;
}
bool deleteNode(Tree * tree, int data){
	if(deleteNodeRecursive(tree->root, data)){
		tree->count -= 1;
		return true;
	}
	return false;		
}
Node * findMinRecursive(Node * node){
	if(node->left == NULL)
		return node;
	findMinRecursive(node->left);
}
Node * findMin(Node * node){
	return findMinRecursive(node);
}
Node * findMaxRecursive(Node * node){
	if(node->right == NULL)
		return node;
	findMaxRecursive(node->right);
}
Node * findMax(Node * node){
	return findMaxRecursive(node);
}
void preorderRecursive(Node * node){
	if (node != NULL){
		cout << node->data << endl;
		preorderRecursive(node->left);
		preorderRecursive(node->right);
	}
}
void preorder(Tree * tree){
	preorderRecursive(tree->root);
}
void postorderRecursive(Node * node){
	if (node != NULL){
		postorderRecursive(node->left);
		postorderRecursive(node->right);
		cout << node->data << endl;
	}
}
void postorder(Tree * tree){
	postorderRecursive(tree->root);
}
void inorderRecursive(Node * node){
	if (node != NULL){
		inorderRecursive(node->left);
		cout << node->data << endl;
		inorderRecursive(node->right);
	}
}
void inorder(Tree * tree){
	inorderRecursive(tree->root);
}
void levelorder(Tree * tree){
	queue <Node *> q;
	Node * node = tree->root;
	while(node != NULL){
		cout << node->data << endl;
		if(node->left != NULL)
			q.push(node->left);
		if(node->right != NULL)
			q.push(node->right);
		if(!q.empty()){
			node = q.front();
			q.pop();
		}else{
			node = NULL;
		}
	}
}
int main(){
	Tree * tree = new Tree();
	
	insert(tree, createNode(90));
	insert(tree, createNode(80));
	insert(tree, createNode(70));
	insert(tree, createNode(100));
	insert(tree, createNode(110));
	insert(tree, createNode(101));
	insert(tree, createNode(105));
	insert(tree, createNode(95));
	
	cout << tree->root->right->data << endl;
	cout << contains(tree, 110) << endl;
	
	Node * node = findParent(tree->root, 105);
	if(node)
		cout << node->data << endl;
	
	cout << "preorder" << endl;
	preorder(tree);
	cout << "done" << endl;
	
	deleteNode(tree, 100);
	node = findMin(tree->root);
	cout << node->data << endl;
	
	node = findMax(tree->root);
	cout << node->data << endl;
	
	cout << "preorder" << endl;
	preorder(tree);
	
	cout << "postorder" << endl;
	postorder(tree);
	
	cout << "inorder" << endl;
	inorder(tree);
	
	cout << "levelorder" << endl;
	levelorder(tree);
	
	return 0;
}
