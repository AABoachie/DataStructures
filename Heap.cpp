#include <iostream>
#include <vector>
using namespace std;

struct MinHeap{
	vector <int> arr;
};

MinHeap * create(){
	return new MinHeap;
}

void minHeapifyUp(MinHeap * heap, int indexC){
	int indexP = (indexC - 1) / 2;
	int valueP = heap->arr[indexP];
	int valueC = heap->arr[indexC];
	if(valueC < valueP){
		int temp = valueC;
		heap->arr[indexC] = heap->arr[indexP];
		heap->arr[indexP] = temp;
		minHeapify(heap, indexP);
	}else{
		return;
	}
}

bool contains(MinHeap * heap, int data){
	for(int i = 0; i < heap->arr.size(); i++){
	
	}
}

bool insert(MinHeap * heap, int data){
	heap->arr.push_back(data);	
	minHeapifyUp(heap, heap->arr.size() - 1);
}

int main(){
	
}
