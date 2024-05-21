#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of process: ";
    cin>>n;
    int bt[n],at[n],tat[n],wt[n];
    double avgtat=0,avgwt=0;
    cout<<"Enter burst Time: ";
    for(int i=0; i<n; i++)
    {
        cout<<"For p"<<i+1<<":  ";
        cin>>bt[i];
    }
    int qt;
    cout<<"Enter quantam time: ";
    cin>>qt;
    for(int i=0; i<n; i++)
    {
        at[i] = 0;
    }
    int cnt=0,sum=0;
    for(int i=0; i<n; i++)
    {
        sum += bt[i];
    }
    cout<<sum;
    int i=0;
    while(cnt <= sum)
    {
        for(i=0; i<n; i++)
        {
            if(bt[i] >qt)
            {

                cnt += qt;
                bt[i] = bt[i] -qt;
                cout<<cnt;
            }
            else
            {
                cnt += bt[i];
                bt[i]=0;
            }
            if(bt[i]==0)
            {
                tat[i] = cnt;
            }
            else if(i == n)
            {
                i=0;
            }
            else
            {
                i++;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
      cout<<tat[i];
    }
    return 0;
}
