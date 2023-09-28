#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    cout<<"Total number of process in the system: ";
    cin>>n;
    y = n;

    for(i=0; i<n; i++)
    {
    cout<<"\nEnter the Arrival and Burst time of the Process "<< i+1<<endl;
    printf("Arrival time is: ");
    cin>>at[i];
    printf("Burst time is: \t");
    cin>>bt[i];
    temp[i] = bt[i]; // store the burst time in temp array
    }

    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);

    //Display the process No, burst time, Turn Around Time and the waiting time
    printf("\nProcess No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for(sum=0, i = 0; y!=0; )
    {
        if(temp[i] <= quant && temp[i] > 0) //
        {
            sum = sum + temp[i];//sum = finish time
            temp[i] = 0;
            count=1;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;// sum = finish time
        }

        if(temp[i]==0 && count==1)//if first if condition satisfies
        {
            y--; //decrement the process no.
            printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
            wt = wt+sum-at[i]-bt[i];///WT = TAT - BT = CT-AT-BT
            tat = tat+sum-at[i]; ///TAT = CT-AT
            count =0;
        }

        if(i==n-1)///for last process
        {
            i=0;
        }
        else if(at[i+1]<=sum)///if a new process arrived in a timestamp
        {
            i++;
        }
        else/// if no new process came, it'll work on itself again
        {
            i=0;
        }
}

    avg_wt = wt * 1.0/n;
    avg_tat = tat * 1.0/n;
    cout<<"\nAverage Turn Around Time: "<<avg_wt;
    cout<<"\nAverage Waiting Time: "<<avg_tat;

}
