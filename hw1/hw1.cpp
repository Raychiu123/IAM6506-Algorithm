#include <iostream>
#include "Array.h"

using namespace std;

int main(){
	int number,value;
	cout << "input numbers: "; cin >> number;
	Array ARRAY1(number);
	for(int i=0; i<number; i++){
		cout << i+1 << ":\t"; cin >> value;
		ARRAY1.insert2array(value);
	}
	
	
	//ARRAY1.insertion_sort();
	ARRAY1.merge_sort_recursive(0,number-1);
	ARRAY1.~Array();
	
	system("pause");
	return 0;
}
