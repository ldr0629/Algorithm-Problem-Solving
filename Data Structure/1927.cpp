#include <iostream>
#include <stdlib.h>
#define MAX 100001

using namespace std;

int heap[MAX];
int heap_size = 0;

void insert_max_heap(int item);
int delete_max_heap();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int n, x;
	cin>>n;
	
	for(int i = 0; i<n; i++) {
		cin>>x;
		if(x==0) cout<<delete_max_heap()<<"\n";
		else insert_max_heap(x);
	}
} 

// 원소의 개수가 heap_size인 힙에 item을 삽입하는 함수 
void insert_max_heap(int item) {
	int i = ++heap_size;
	
	// 트리를 거슬러 올라가며 부모 노드와 비교하는 과정 
	while((i!=1)&&(item<heap[i/2])) {
		heap[i] = heap[i/2];
		i/=2;
	}
	heap[i] = item; // 새로운 노드 삽입 
}

// 힙 트리에서의 삭제함수 
int delete_max_heap() {
	if(heap_size == 0) {
		return 0;
	}
	
	int parent = 1, child = 2;
	int item, temp;
	
	item = heap[1]; 
	temp = heap[heap_size--];
	
	parent = 1;
	child = 2;
	
	while(child <= heap_size) {
		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다. 
		if((child<heap_size)&&heap[child] > heap[child+1]) {
			child++;
		}
		if(temp<=heap[child]) {
			break;
		}
		// 한 단계 아래로 이동. 
		heap[parent] = heap[child];
		parent = child;
		child*=2;
	}
	heap[parent] = temp;
	return item;
}
