#include <iostream>
#include <vector>
using namespace std;

struct MinHeap{
	vector <int> arr;
};

MinHeap * createHeap(){
	return new MinHeap;
}

void minHeapifyUp(MinHeap * heap, int indexC){
	int indexP = (indexC - 1) / 2;
	int valueP = heap->arr[indexP];
	int valueC = heap->arr[indexC];
	
	//recursive
	/*
	if(valueC < valueP){
		int temp = valueC;
		heap->arr[indexC] = heap->arr[indexP];
		heap->arr[indexP] = temp;
		minHeapifyUp(heap, indexP);
	}else{
		return;
	}*/
		
	//opimization linear	
	while(indexC > 0){
		valueP = heap->arr[indexP];
		valueC = heap->arr[indexC];
		if(valueC < valueP){
			int temp = valueC;
			heap->arr[indexC] = heap->arr[indexP];
			heap->arr[indexP] = temp;
			indexC = indexP;
			indexP = (indexC - 1) / 2;
		}
	}
}

void minHeapifyDown(MinHeap * heap, int index){
	int LCIndex = 2 * index + 1;
	int RCIndex = 2 * index + 2;
	int SIZE = heap->arr.size();
	int & value = heap->arr[index];
	int LCValue = -1;
	int RCValue = -1;
	
	if(LCIndex < SIZE - 1){
		LCValue = heap->arr[LCIndex];
	}
	if (RCIndex < SIZE - 1){
		RCValue = heap->arr[RCIndex];
	}
	
	if(LCValue != -1 && RCValue != -1){
		int minIndex;
		if(LCValue < RCValue)
			minIndex = LCIndex;
		else
			minIndex = RCIndex;
		//swap
	}
	
	if(LCValue != -1){
		
	}
	
	if(RCValue != -1){
		
	}
}

int findNode(MinHeap * heap, int data){
	//straight
	/*
	for(int i = 0; i < heap->arr.size(); i++){
		if (heap->arr[i] == data)
			return true;		
		return false;
	}*/
	
	//optimization
	int start = 0;
	int nodes = 1;
	int SIZE = heap->arr.size();
	while(start < SIZE){
		start = nodes - 1;
		int end = start + nodes;
		int count = 0;
		while(start < SIZE && start < end ){
			if(data == heap->arr[start]){
				return start;
			}else{
				int indexP = (start - 1) / 2;
				int valueP = heap->arr[indexP];
				if(data > valueP && data < heap->arr[start]){
					count += 1;
				}
				start += 1 ;
			}			
		}
		if(count == start){
			return -1;
		}
		nodes *= 2;
	}
	return -1;
}

bool remove(MinHeap * heap, int data){
	int removeIndex = findNode(heap, data);
	heap->arr[removeIndex] = data;
	minHeapifyDown(heap, removeIndex);
}

bool insert(MinHeap * heap, int data){
	heap->arr.push_back(data);
	minHeapifyUp(heap, heap->arr.size() - 1);
}

int main(){
	MinHeap * heap = createHeap();
	insert(heap, 10);
	insert(heap, 9);
	
	cout << findNode(heap, 10) << " " << heap->arr[0] << endl;
}
