/*
Heaps
*/
#include<iostream> 
using namespace std; 

class Heap 
{ 
	public: 
	int arr[100]; 
	void getArray(int n);
	void printArray(int n); 
	void maxHeapify(int arr[],int n,int i); 
	void maxheapsort(int arr[],int n); 
	void minHeapify(int arr[],int n,int i); 
	void minheapsort(int arr[],int n); 
	
};

//Insert value 
void Heap:: getArray(int n) 
{ 
	for(int i=0;i<n;i++) 
	{
	cin>>arr[i]; 
	} 
} 

//display value 
void Heap::printArray(int n) 
{ 
	for(int i=0;i<n;i++) 
	{ 
	cout<<" "<<arr[i]; 
	} 
} 

//max heapify 
void Heap::maxHeapify(int arr[],int n,int i) 
{ 

	int max = i; 
	cout<<"\ni in maxheapify\n"<<i;
	cout<<"\nmax in maxheapify\n"<<max;
	cout<<"\n ----------------------------------------"<<endl; 
	
	int left = 2*i+1; 
	cout<<"\nleft in maxheapify\n"<<left;
	
	int right = 2*i+2; 
	cout<<"\nright in maxheapify\n"<<right;
	cout<<"\n ----------------------------------------"<<endl; 
	
	if (left < n && arr[left] > arr[max]) 
	
	{ 
	 max = left; 
	} 
	if (right < n && arr[right] > arr[max]) 
	{ 
	 max = right; 
	} 
	cout<<"\nmax_maxheap\n"<<max;
	cout<<"\ni_maxheap\n"<<i;
	cout<<"\n ----------------------------------------"<<endl; 
	
	if (max != i) 
	{
	swap(arr[i], arr[max]); 
	maxHeapify(arr, n, max); 
	} 
} 

//max heap sort 
void Heap::maxheapsort(int arr[],int n) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
	{ 
	maxHeapify(arr, n, i); 
	} 
	
	 for (int i = n - 1; i >= 0; i--) 
	 { 
	 swap(arr[0], arr[i]); 
	maxHeapify(arr, i, 0); 
	 } 
} 

//min heapify 
void Heap::minHeapify(int arr[],int n,int i) 
{ 
	int max = i; 
	cout<<"\ni in minheapify\n"<<i;
	cout<<"\nmax in minheapify\n"<<max;
	int left = 2*i+1; 
	cout<<"\nleft in minheapify\n"<<left;
	int right = 2*i+2; 
	cout<<"\nright in minheapify\n"<<right;
	cout<<"\n ----------------------------------------"<<endl; 
	
	
	if (left < n && arr[left] < arr[max]) 
	{ 
	max = left; 
	} 
	
	if (right < n && arr[right] < arr[max]) 
	{ 
	 max = right; 
	}
	cout<<"\nmax_minheap\n"<<max;
	cout<<"\ni_maxheap\n"<<i; 
	cout<<"\n ----------------------------------------"<<endl; 
	
	if (max != i) 
	{ 
	swap(arr[i], arr[max]); 
	maxHeapify(arr, n, max); 
	} 
} 
//min heapsort 
void Heap::minheapsort(int arr[],int n) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
	{ 
	minHeapify(arr, n, i); 
	} 
	
	for (int i = n - 1; i >= 0; i--) 
	{ 
	swap(arr[0], arr[i]); 
	minHeapify(arr, i, 0); 
	} 
} 

int main() 
{
	Heap h1; 
	int n,a=1; 
	
	cout<<"\n ----------------------------------------"<<endl; 
	cout<<"\n HEAP SORT \n"; 
	
	while(a==1) 
	{ 
		cout<<"\n ----------------------------------------"<<endl; 
		cout<<"\n Enter The Number of Elements: "; 
		cin>>n; 
		cout<<"\n Enter The Array Elements: "<<endl; 
		h1.getArray(n); 
		
		cout<<"\n ----------------------------------------"<<endl; 
		cout<<"\n Array Before Sorting:-"<<endl; h1.printArray(n); 
		cout<<"\n ----------------------------------------"<<endl; 
		
		h1.maxheapsort(h1.arr,n); 
		 cout<<"\n Array After Sorting(Max Heapify):- "<<endl; 
		h1.printArray(n); 
		
		cout<<"\n ----------------------------------------"<<endl; 
		h1.minheapsort(h1.arr,n); 
		 cout<<"\n Array After Sorting(Min Heapify):- "<<endl; 
		h1.printArray(n); 
		
		cout<<"\n ----------------------------------------"<<endl; 
		cout<<"\n Do You Want to Continue?"<<"\n"<<" Press 1 Else 0: "; 
		cin>>a; 
	} 
	return 0; 
}

/*
OUTPUT


 ----------------------------------------

 HEAP SORT

 ----------------------------------------

 Enter The Number of Elements: 3

 Enter The Array Elements:
4
5
6

 ----------------------------------------

 Array Before Sorting:-
 4 5 6
 ----------------------------------------

i in maxheapify
0
max in maxheapify
0
 ----------------------------------------

left in maxheapify
1
right in maxheapify
2
 ----------------------------------------

max_maxheap
2
i_maxheap
0
 ----------------------------------------

i in maxheapify
2
max in maxheapify
2
 ----------------------------------------

left in maxheapify
5
right in maxheapify
6
 ----------------------------------------

max_maxheap
2
i_maxheap
2
 ----------------------------------------

i in maxheapify
0
max in maxheapify
0
 ----------------------------------------

left in maxheapify
1
right in maxheapify
2
 ----------------------------------------

max_maxheap
1
i_maxheap
0
 ----------------------------------------

i in maxheapify
1
max in maxheapify
1
 ----------------------------------------

left in maxheapify
3
right in maxheapify
4
 ----------------------------------------

max_maxheap
1
i_maxheap
1
 ----------------------------------------

i in maxheapify
0
max in maxheapify
0
 ----------------------------------------

left in maxheapify
1
right in maxheapify
2
 ----------------------------------------

max_maxheap
0
i_maxheap
0
 ----------------------------------------

i in maxheapify
0
max in maxheapify
0
 ----------------------------------------

left in maxheapify
1
right in maxheapify
2
 ----------------------------------------

max_maxheap
0
i_maxheap
0
 ----------------------------------------

 Array After Sorting(Max Heapify):-
 4 5 6
 ----------------------------------------

i in minheapify
0
max in minheapify
0
left in minheapify
1
right in minheapify
2
 ----------------------------------------

max_minheap
0
i_maxheap
0
 ----------------------------------------

i in minheapify
0
max in minheapify
0
left in minheapify
1
right in minheapify
2
 ----------------------------------------

max_minheap
1
i_maxheap
0
 ----------------------------------------

i in maxheapify
1
max in maxheapify
1
 ----------------------------------------

left in maxheapify
3
right in maxheapify
4
 ----------------------------------------

max_maxheap
1
i_maxheap
1
 ----------------------------------------

i in minheapify
0
max in minheapify
0
left in minheapify
1
right in minheapify
2
 ----------------------------------------

max_minheap
0
i_maxheap
0
 ----------------------------------------

i in minheapify
0
max in minheapify
0
left in minheapify
1
right in minheapify
2
 ----------------------------------------

max_minheap
0
i_maxheap
0
 ----------------------------------------

 Array After Sorting(Min Heapify):-
 6 5 4
 ----------------------------------------

 Do You Want to Continue?
 Press 1 Else 0:

*/
