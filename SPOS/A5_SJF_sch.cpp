#include<iostream>
using namespace std;
int main()
{
int BT[20],P[20],WT[20],TAT[20],PR[20],i,j,n,tot=0,Ps,temp;
float avg_WT,avg_TAT;
cout<<"SJF";
cout<<"\nEnter Total Number of Process:";
cin>>n;
cout<<"\nEnter Burst Time\n";
for(i=0;i<n;i++)
{

cout<<"\nP("<<i+1<<")\n";

cout<<"Burst Time:";
cin>>BT[i];
P[i]=i+1;
}
for(i=0;i<n;i++)
{
Ps=i;
for(j=i+1;j<n;j++)
{
if(BT[j]<BT[Ps])
Ps=j;
}
temp=BT[i];
BT[i]=BT[Ps];
BT[Ps]=temp;

temp=P[i];
P[i]=P[Ps];
P[Ps]=temp;
}
WT[0]=0;
for(i=1;i<n;i++)
{
WT[i]=0;
for(j=0;j<i;j++)
WT[i]+=BT[j];

tot+=WT[i];
}
avg_WT=tot/n;
tot=0;
for(i=0;i<n;i++)
{
TAT[i]=BT[i]+WT[i];
tot+=TAT[i];
}
avg_TAT=tot/n;
for(i=0;i<n;i++)
{
cout<<"\nProcess\t Burst Time \tWaiting Time\tTurnaround Time";
cout<<"\nP["<<P[i]<<"]\t\t "<<BT[i]<<"\t\t "<<WT[i]<<"\t\t\t "<<TAT[i];
}
cout<<"\n\nAverage Waiting Time="<<avg_WT;
cout<<"\n\nAverage TAT="<<avg_TAT;
return 0;
}

