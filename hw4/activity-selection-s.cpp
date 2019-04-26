#include "iostream"
#include "algorithm"

using namespace std;

class Activity{
	friend class Activity_Select;
	public:
		int s;
		int f;
		int crc;
		int index;
};

class Activity_Select{
	private:
		int total;
		Activity* a;
		Activity* sort_a;
		
		void return_select_act(){
			cout << "-------actitbity seleced------" << endl;
			for(int i=total-1; i>=0; i--){
				if(sort_a[i].crc == 1){
					cout << "ACTIVITY "<< sort_a[i].index << endl;
				}
			}
		}
		
	public:
		Activity_Select(int num){
			total = num;
			int *start = new int[num];
			a = new Activity[num];
			sort_a = new Activity[num];
						
			for(int i=0; i<num; i++){
				cout << "--------ACTIVITY " << i+1 << "---------" << endl;
				cout << "s"<< i+1 << ":\t"; cin >> a[i].s;
				cout << "f"<< i+1 << ":\t"; cin >> a[i].f;
				while(a[i].f < a[i].s){
					cout << "WARNING: finish time is earlier than begin time" << endl;
					cout << "f"<< i+1 << ":\t"; cin >> a[i].f;
				}
				a[i].index = i+1;
				a[i].crc = 0;
				start[i] = a[i].s;
			}
			
			//sort activity
			sort(start,start+total);
			reverse(start,start+total);
			
			for(int i=0; i<num; i++){
				for(int j=0; j<num; j++){
					if(start[i] == a[j].s && a[j].crc != 1 ){
						sort_a[i] = a[j];
						a[j].crc = 1;
						break;
					}					
				}
			}
		}
		
		void select_act(){
			int k=0;
			sort_a[0].crc = 1; //1 means that activiy had been slelected
			for(int m=1; m<total; m++){
				if(sort_a[m].f <= sort_a[k].s){
					sort_a[m].crc = 1;
					k = m;
				}
			}
			return_select_act();
		}
		
};

int main(){
	int total;
	cout << "number of activities: "; cin >> total;
	
	Activity_Select AS(total);
	AS.select_act();
	return 0;
} 
