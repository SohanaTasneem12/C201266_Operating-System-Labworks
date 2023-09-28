#include<bits/stdc++.h>
using namespace std;

int main() {
	int p, r;
	cout<<"Enter the number of processes : ";
    cin>>p;
	cout<<"Enter the number of resources : ";
    cin>>r;
	int allotment[p][r];
	cout<<"Enter the allotment matrix for each process : "<<endl;
	for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>allotment[i][j];
        }
    }
	int maximum[p][r];
    cout<<"Enter the maximum matrix for each process : "<<endl;
	for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>maximum[i][j];
        }
    }
	int available[r] ;
    cout<<"Enter the available resources : ";
	for(int i=0;i<r;i++)
    {
          cin>>available[i];
    }

	int f[p], res[p], ind = 0;
	for (int i = 0; i < p; i++) {
		f[i] = 0;
	}

	int requirement[p][r];
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < r; j++)
		requirement[i][j] = maximum[i][j] - allotment[i][j];
	}

	int a = 0;
	for (int i = 0; i < p; i++)
    {
		for (int j = 0; j < p; j++)//iterates through each process
		 {
			if (f[j] == 0)//when the process is not completed
            {
				int flag = 0;
				for (int k = 0; k < r; k++)
				{
					if (requirement[j][k] > available[k])
					{
						flag = 1;//when its not possible to allocate
						break;
					}
				}
				if (flag == 0)//all resources required by process j are available
				{
					res[ind++] = j;// add process j to result array
					for (a = 0; a < r; a++)
					available[a] += allotment[j][a]; //update the available resources by returning j process
					f[j] = 1; //mark process j as completed by setting f[j] = 1
				}
			}
		}
	}
//continue the loop until all processes are completed
	int flag = 1;
	if(flag==1) {
		cout << "Safe Sequence" << endl;
		for (int i = 0; i < p - 1; i++)
		cout << "P" << res[i] << " -> ";
		cout << "P" << res[p - 1] <<endl;
	}
	return (0);
}
