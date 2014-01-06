#include <iostream>
#include "minHeap.h"

void main()
{
	//自己输入数据
	int N;
	std::cout<<"Please input N numbers: ";
	std::cin>>N;
	minHeap<int> heap1(N);
	for(int i=0;i<N;i++){
		int temp;
		std::cin>>temp;
	    heap1.insert(temp);
	}
	std::cout<<"The minHeap is: ";
	for(int i=0;i<N;i++){
		std::cout<<heap1.heapArray[i]<<" ";
	}

	//根据已知数据建立最小堆
	int key[10]={3,19, 65, 25, 40, 49,50,80,123,2};
	minHeap<int> heap2(key,10);
	heap2.buildHeap();
	for(int i=0;i<10;i++){
		std::cout<<heap2.heapArray[i]<<" ";	
	}
	system("pause");



}