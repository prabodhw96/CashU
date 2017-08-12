/*This program gives only the amount of money in transaction before and after minimizing the cash flow*/

#include <iostream>
#include <cstdio>
using namespace std;

int mat[1000][1000];
int rsum[1000], csum[1000];

int main()
{
	int n, i, j, sum, diff;
	cout<<"No. of parties: ";
	cin>>n;
    for(i=sum=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i == j)
            {
                mat[i][j] = 0;
                continue;
            }
            cout<<"P#"<<i<<" has to pay P#"<<j<<": ";
            cin>>mat[i][j];
            sum += mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        for(rsum[i] = csum[i]=j=0; j<n; j++)
        {
            rsum[i] += mat[i][j];
            csum[i] += mat[j][i];
        }
    }
    for(i=diff=0; i<n; i++)
        if(rsum[i] > csum[i])
            diff += rsum[i] - csum[i];
    cout<<"\nTotal amount involved in transaction: "<<sum<<endl;
    cout<<"After minimizing the cash flow: "<<diff<<endl;
	return 0;
}
