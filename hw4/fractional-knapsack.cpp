#include "iostream"
#include "algorithm"

using namespace std;

class Item{
	friend class F_Knapsack_Select;
	public:
		int index;
		float value;
		float weight;
		float crc;
		float cp;
};

class F_Knapsack_Select{
	private:
		int total;
		Item* a;
		Item* sort_a;
		
		void return_select_item(){
			int profit=0;
			cout << "-------item seleced------" << endl;
			for(int i=0; i<total; i++){
				if(sort_a[i].crc > 0){
					profit += (sort_a[i].crc * sort_a[i].value);
					cout << "ITEM "<< sort_a[i].index << ":\t" << sort_a[i].crc << endl;
				}
			}
			cout << endl << "Total Profit: " << profit;
		}
	public:
		F_Knapsack_Select(int num){
			total = num;
			a = new Item[num];
			sort_a = new Item[num];
			float* cp_tmp = new float[num]; 
			
			for(int i=0; i<num; i++){
				cout << "--------ITEM " << i+1 << "---------" << endl;
				cout << "weight"<< i+1 << ": "; cin >> a[i].weight;
				cout << "value"<< i+1 << ": "; cin >> a[i].value;
				a[i].cp = a[i].value/a[i].weight;
				cp_tmp[i] = a[i].cp;
				a[i].index = i+1;
			}
			
			sort(cp_tmp, cp_tmp+num);
			reverse(cp_tmp, cp_tmp+num);
			
			for(int i=0; i<num; i++){
				for(int j=0; j<num; j++){
					if(cp_tmp[i] == a[j].cp && a[j].crc != 1 ){
						sort_a[i] = a[j];
						a[j].crc = 1;
						break;
					}					
				}
			}
		}
		
		void select_knapsack(float W){
			float T = 0;
			for(int i=0; i<total; i++){
				T+=sort_a[i].weight;
				if(T<W){ 
					sort_a[i].crc = 1;
				}
				else{
					T-=sort_a[i].weight;
					sort_a[i].crc = ((W-T)/(sort_a[i].weight));
					break;
				}
			}
			return_select_item();
		}
};

int main(){
	int total; 
	float bound;
	cout << "total: "; cin >> total;
	cout << "capacity: "; cin >> bound;
	
	F_Knapsack_Select FKS(total);
	FKS.select_knapsack(bound);
	
	return 0;
}
