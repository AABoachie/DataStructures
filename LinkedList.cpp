#include <iostream>
using namespace std;

struct Node{
	int data;
	Node * next;
};
struct LinkedList{
	Node * head;
	Node * tail;
};
Node * createNode(int data){
	Node * node = new Node();
	node->data = data;
	node->next = NULL;
}
LinkedList * createList(){
	LinkedList * ll = new LinkedList();
	ll->head = NULL;
	ll->tail = NULL;
	return ll;
}
void insertNode(LinkedList * ll , Node * data){
	if (ll->head == NULL && ll->tail == NULL){
		ll->head = data;
		ll->tail = data;
	}else{
		ll->tail->next = data;
		ll->tail = data;
	}
}
void traverseList(LinkedList * ll){
	Node * current;
	current = ll->head;
	while(current != NULL){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
void reverseTraverseList(LinkedList * ll){
	Node * current, * previous;
	
	if(ll->tail != NULL){
		current = ll->tail;		
		while(current != ll->head){
			previous = ll->head;
			while(previous->next != current){
				previous = previous->next;
			}
			cout << current->data << " ";
			current = previous; 
		}
		
		cout << ll->head->data << endl;
	}
}
bool contains(LinkedList * ll, int data){
	Node * current;
	current = ll->head;
	while(current != NULL){
		if(current->data == data)
			return true;
		current = current->next;
	}
	return false;
}
bool deleteNode(LinkedList * ll, int data){	
	if(ll->head == NULL){
		//no list
		return false;
	}
	if(ll->head->data == data){
		if(ll->tail->data == data){
			//only one element
			ll->head = NULL;
			ll->tail = NULL;
			return true;			
		}
		//the first element
		Node * tmp = ll->head;
		ll->head = ll->head->next;		
		delete tmp;
		return true;		
	}
	Node * current, * previous;
	current = ll->head->next;
	previous = ll->head;
	while(current != ll->tail){
		if(current->data == data){			
			//in the middle of the lsit			
			previous->next = current->next;
			delete current;
			return true;			
		}
		current = current->next;
		previous = previous->next;
	}
	if(ll->tail->data == data){
		//the last item		
		ll->tail = previous;
		previous->next = NULL;
		delete current;
	}else{
		//not in the list
		return false;
	}
}
int main(){
	LinkedList * ll = createList();
	
	insertNode(ll, createNode(20));
	insertNode(ll, createNode(30));
	insertNode(ll, createNode(12));
	insertNode(ll, createNode(21));
	insertNode(ll, createNode(14));
	insertNode(ll, createNode(13));
	insertNode(ll, createNode(22));
	insertNode(ll, createNode(45));
	
	traverseList(ll);
	
	cout << contains(ll, 40) << endl;
	
	reverseTraverseList(ll);
	deleteNode(ll, 30);
	deleteNode(ll, 13);
	deleteNode(ll, 45);
	traverseList(ll);
}
