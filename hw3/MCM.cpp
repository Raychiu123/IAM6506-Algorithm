//------------------------ dev c++ ----------------------------//
#include<iostream>
using namespace std;

void Print_Optimal_Parens(int** s,int i,int j){
	if (i==j) 
		cout << "A" << i;
	else
	{
		cout << "(";
		Print_Optimal_Parens(s,i,s[i][j]);
		Print_Optimal_Parens(s,s[i][j]+1,j);
		cout << ")";
	}
} 

int MatrixChainMultiplication(int p[], int n)
{
	int **s = new int *[n];
	for(int i=0; i<n; i++) s[i] = new int[n];

    int m[n][n];
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;   
        
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q; 
                    s[i][j] = k;
                }
            }
        }
    }

	Print_Optimal_Parens(s,1,n-1);
	cout << endl;
    return m[1][n-1];   
 
}
 
int main()
{
    int n,i;
    cout<<"Enter number of matrices\n";
    cin>>n;
 
    n++;
 
    int arr[n];
 
    cout<<"Enter dimensions \n";
 
    for(i=0;i<n;i++)
    {
        cout<<"Enter d"<<i<<" :: ";
        cin>>arr[i];
    }

    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Minimum number of multiplications is " << MatrixChainMultiplication(arr, size);
 
    return 0;
}
