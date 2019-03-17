#include "iostream"

using namespace std;

class ARRAY{
	private:
		int *array;
		int size, location;
	public:
		int lowsofar, highsofar, maxsofar;
		
		ARRAY(int number){
			size = number;
			array = new int[size];
			location = 0;
		}
		~ARRAY(){
			delete[] array;
		} 
		void insert2array(int value){
			array[location] = value;
			location++;
		}
		void print_output(){
			cout << '\n';
			for(int i=0; i<location;i++){
				cout << i+1 << ":\t" << array[i] << '\n';
			}
		}
		void swap(int *a, int *b){
			int tmp = *a;
			*a = *b;
			*b = tmp;
		}
		void heapify(int i=1){
			int L = 2*i; 
			int R = 2*i+1;
			int largest = i;
			
			if(L <= size && array[L-1]>array[largest-1]){
				largest = L;
			}
			if(R <= size && array[R-1]>array[largest-1]){
				largest = R;
			}
			if(largest != i){
				swap(&array[i-1],&array[largest-1]);
				heapify(largest);
			}
		}
		void build_max_heap(){
			//int length = size;
			for(int i=(size/2); i>0; i--){
				heapify(i);
			}
		}
		void heapsort(){
			cout << "After heapsort..." << endl;
			build_max_heap();
			for(int i=location; i>=1; i--){
				swap(&array[0],&array[i-1]);
				size = size - 1;
				heapify(1);
			}
			print_output();
		}
		void find_max_subarray(int low=0, int high=0){
			cout << "find max subarray..." << endl;
			//initialization
			int lowhere, highhere, maxhere;
			
			lowhere = highhere = lowsofar = highsofar = low;
			maxhere = maxsofar = array[low];
			
			for(int i = low+1; i<=high; i++){
				if(array[i]>=maxhere+array[i]){ //maxhere < 0
					lowhere = highhere = i;
					maxhere = array[i];
				}
				else{ //maxhere > 0
					highhere = i; 
					maxhere = maxhere + array[i];
				}
				
				if(maxhere>=maxsofar){
					lowsofar = lowhere;
					highsofar = highhere;
					maxsofar = maxhere;
				}
			}
		}
}; 

int main(){
	int number,value;
	
	cout << "input numbers: "; cin >> number;
	ARRAY ARRAY1(number);
	ARRAY ARRAY2(number);
	
	for(int i=0; i<number; i++){
		cout << i+1 << ":\t"; cin >> value;
		ARRAY1.insert2array(value);
		ARRAY2.insert2array(value);
	}	
	
	ARRAY1.heapsort();
	
	ARRAY2.find_max_subarray(0, number-1);
	cout << "\nlow:\t" << ARRAY2.lowsofar+1;
	cout << "\nhigh:\t" << ARRAY2.highsofar+1;
	cout << "\nmaxarray:\t" << ARRAY2.maxsofar << endl;
	
	// deconstructor
	ARRAY1.~ARRAY();
	
	system("pause");
	return 0;
}
 
