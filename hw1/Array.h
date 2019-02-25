#if !defined(___class_Array)
	#define	___class_Array

class Array{
	private:
		int num;
		int *array; 
		int location;
	public: 
		//int num;
		//int *array;
		Array(int n);
		~Array();
		void swap(int *a, int *b);
		void insertion_sort();
		void merge_sort_recursive(int p, int r);
		void merge_sort(int p, int r);
		void merge(int p, int q, int r);
		void print_output();
		void insert2array(int m);
};

#endif
