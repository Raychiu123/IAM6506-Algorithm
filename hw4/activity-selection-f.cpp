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
	public:
		Activity_Select(int num){
			total = num;
			int *finish = new int[num];
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
				finish[i] = a[i].f;
			}
			
			//sort activity
			sort(finish,finish+total);
			for(int i=0; i<num; i++){
				for(int j=0; j<num; j++){
					if(finish[i] == a[j].f && a[j].crc != 1 ){
						sort_a[i] = a[j];
						a[j].crc = 1;
						break;
					}					
				}
			}
		}
		
		void return_select_act(){
			cout << "-------actitbity seleced------" << endl;
			for(int i=0; i<total; i++){
				if(sort_a[i].crc == 2){
					cout << "ACTIVITY "<< sort_a[i].index << endl;
				}

			}
		}
		
		void select_act(){
			int k=0;
			sort_a[0].crc = 2; //2 means that activiy had been slelected
			for(int m=1; m<total; m++){
				if(sort_a[m].s >= sort_a[k].f){
					sort_a[m].crc = 2;
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
