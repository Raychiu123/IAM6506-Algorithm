#include <iostream>
#include "Array.h"
#include <math.h>
using namespace std;

Array::Array(int n){
	num = n;
	array = new int[num];
	location = 0;
}

void Array::swap(int *a, int *b){
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

Array::~Array(){
	delete[] array;
} 

void Array::insertion_sort(){
	for(int i=1;i<num;i++){
		int key = array[i];
		int j=i-1;
		while(key<array[j] && j>=0){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}
	cout << "\nafter insertion sort...\n";
	print_output();
}

void Array::print_output(){
	cout << '\n';
	for(int i=0;i<num;i++){
		cout << i+1 << ":\t" << array[i] << '\n';
		}
	}

void Array::insert2array(int m){
	array[location] = m;
	location++;
}

void Array::merge_sort_recursive(int p, int r){
	merge_sort(p,r);
	cout << "\nafter merge sort...\n";
	print_output();
}

void Array::merge_sort(int p, int r){
	if(p<r){
		int q = floor((r+p)/2);
		//cout << "q = "<<q;
		merge_sort(p,q);
		merge_sort(q+1,r);
		merge(p,q,r);
	}
}

void Array::merge(int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	for(int i=1;i<=n1;i++){
		L[i-1] = array[p+i-1];
	}
	for(int j=1;j<=n2;j++){
		R[j-1] = array[q+j];
	}
	L[n1] = 500000;
	R[n2] = 500000;
	int i=0;
	int j=0;
	for(int k = p; k<=r;k++){
		if (L[i] <= R[j]){
			array[k] = L[i];
			i++;
		}
		else{
			array[k] = R[j];
			j++;
		}
	} 
	delete[] R;
	delete[] L;
}
