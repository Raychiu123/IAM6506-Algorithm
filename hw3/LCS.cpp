//------------------------ dev c++ ----------------------------//
#include "iostream"
#include "string"

using namespace std;

int n1, n2;
string s1, s2;
const int t=3;
int a[t];

void print_LCS(int i, int j, int **prev)
{
    if (i == 0 || j == 0) return;
 
    if (prev[i][j] == 0)        // 左上方
    {
        print_LCS(i-1, j-1, prev);
        cout << s1[i];  // 印出LCS的元素
    }
    else if (prev[i][j] == 1)   // 左方
        print_LCS(i, j-1, prev);
    else if (prev[i][j] == 2)   // 上方
        print_LCS(i-1, j, prev);
}

void LCS(string s1, string s2)
{
	const int len1 = n1+1;
	const int len2 = n2+1;	 

	int length[len1][len2];
	
	int **prev = new int *[len1+1];
	for(int i=0; i<len1; i++) prev[i] = new int[len2];
	
    for (int i=0; i<=n1; i++) length[i][0] = 0;
    for (int j=0; j<=n2; j++) length[0][j] = 0;
 
    for (int i=1; i<=n1; i++)
        for (int j=1; j<=n2; j++)
            if (s1[i] == s2[j])
            {
                length[i][j] = length[i-1][j-1] + 1;
                prev[i][j] = 0; // 左上方
            }
            else
            {
                if (length[i-1][j] < length[i][j-1])
                {
                    length[i][j] = length[i][j-1];
                    prev[i][j] = 1; // 左方
                }
                else
                {
                    length[i][j] = length[i-1][j];
                    prev[i][j] = 2; // 上方
                }
            }

    cout << "Length of LCS:\t" << length[n1][n2] << endl;
    cout << "LCS:\t";
    print_LCS(n1, n2, prev);
}


int main(){
	string x(" ");
	cout << "string1: "; cin >> s1;
	cout << "string2: "; cin >> s2;	
	
	n1 = s1.size();
	n2 = s2.size();

	s1 = x + s1;
	s2 = x + s2;
	
	LCS(s1,s2);
	return 0;
} 
