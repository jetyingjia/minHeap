#ifndef _minHeap_hpp_
#define _minHeap_hpp_

//definition of minHeap
template<typename T>
class minHeap {
private:
	//T *heapArray;
	int maxSize;
	int currentSize;
	
public:
	T *heapArray;
// 	int maxSize;
// 	int currentSize;
	minHeap(int size);  //default constructor function
	//minHeap(T a[],int n);

	minHeap(T *a,int n);

	virtual ~minHeap(){
		delete[] heapArray;
	}
	bool isEmpty();
	bool isLeaf(int pos);
	int leftChild(int pos);
	int rightChild(int pos);
	int parent(int pos);
	bool insert(T temp);
	bool remove(int pos);
	bool removeMin();
	void siftUp(int position);
	void siftDown(int pos);
	void buildHeap();
	//void minHeapDown(T &a,int i,int n);

};

template<typename T>
minHeap<T>::minHeap(int size){
	maxSize=size;
	currentSize=0;
	heapArray=new T[size];
}

//template<typename T>
// minHeap<T>::minHeap(T a[],int n){
// 	heapArray=a;
// 	currentSize=n;
// 	maxSize=n;
// }

template<typename T>
minHeap<T>::minHeap(T *a,int n){
	heapArray=a;
	currentSize=maxSize=n;
}

template <typename T>
int minHeap<T>::leftChild(int pos){
	return (2*pos)+1;
}

template <typename T> 
int minHeap<T>::rightChild(int pos){
	return (2*pos)+2;
}

template<typename T>
int minHeap<T>::parent(int pos){
	return (pos-1)/2;
}

// template<typename T>
// void minHeap<T>::minHeapDown(T &a,int i,int n){
// 	T temp=a[i];
// 	j=2*i+1;
// 	while(j<n){
// 		if((j+1)<n&&a[j]<a[j+1]){
// 			j++;
// 		}
// 		if(temp<a[j]){
// 			break;
// 		}
// 		a[i]=a[j];
// 		i=j;
// 		j=leftChild(j);
// 	}
// 	a[i]=temp;
// 
// }



template <typename T>
void minHeap<T>::buildHeap(){
	for(int i=(currentSize-1)/2;i>=0;i--){
		siftDown(i);
	}
}

template<typename T>
void minHeap<T>::siftDown(int pos){
	T temp=heapArray[pos];
	int j=2*pos+1;
	while(j<currentSize){//考虑右子树不存在的情况
		if((j+1<currentSize)&&heapArray[j]>heapArray[j+1]){
			j++;
		}
		if(temp<heapArray[j]){
			break;
		}
		heapArray[pos]=heapArray[j];
		pos=j;
		j=leftChild(j);
	}
	heapArray[pos]=temp;
}

template<typename T>
void minHeap<T>::siftUp(int pos){
	int tempos=pos;
	T temp=heapArray[tempos];
	while( (tempos>0) && (temp<heapArray[parent(tempos)]) ){
		heapArray[tempos]=heapArray[parent(tempos)];
		tempos=parent(tempos);
	}
	heapArray[tempos]=temp;

}

template<typename T>
bool minHeap<T>::remove(int pos){
	if(pos<0||pos>currentSize){
		return false;
	}
	heapArray[pos]=heapArray[--currentSize];
	if(heapArray[pos]<heapArray[parent(pos)])
		siftUp(pos);
	else 
		siftDown(pos);
	return true;
}

template <typename T>
bool minHeap<T>::removeMin(){
	if (currentSize==0){
		std::cout<<"No element";
		return false;
	}
	T temp;
	temp=heapArray[0];
	heapArray[0]=heapArray[--currentSize];
	heapArray[currentSize]=temp;
	if(currentSize>1)
		siftDown(0);
	return true;
}

template<typename T>
bool minHeap<T>::insert(T temp){
	if(currentSize==maxSize){
		std::cout<<"The minHeap is full:";
		return false;
	}
	else {
		heapArray[currentSize]=temp;
		siftUp(currentSize);
		currentSize++;
		return true;
	}
}

#endif