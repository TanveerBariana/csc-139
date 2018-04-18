#include<stdio.h>
int count,j,n,time,remain,flag=0,time_quantum= 2;
int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];

int GetMyId(int i){
  //arrival time is synonomouse wioth id for this implementation as the order they come in is one per second
  return at[i];
}
int GetStatus(int j){
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
        if(rt[j]<=time_quantum && rt[j]>0){
          time+=rt[j];
          rt[j]=0;
          flag=1;
        }
        else if(rt[j]>0){
          rt[j]-=time_quantum;
          time+=time_quantum;
        }
        if(rt[j]==0 && flag==1){
          printf("P[%d]\t|\t%d\t|\t%d\n",j+1,time-GetMyId(j),time-GetMyId(j)-bt[j]);
          wait_time+=time-GetMyId(j)-bt[j];
          turnaround_time+=time-GetMyId(j);
          flag=0;
        }
    return GetMyId(j);
}
int CreateThreads(){
    printf("4 Total:\t ");
    n=4;
    remain=n;
    //arrival time and burst time
    for(count=0;count<n;count++){
        &at[0]=0;
        &bt[0]=9;
        &at[1]=1;
        &bt[1]=5;
        &at[2]=2;
        &bt[2]=3;
        &at[3]=3;
        &bt[3]=4;
        rt[count]=bt[count];
    }
    return 0;
}

void GO() {
  CreateThreads();
  for(count=0;count<n;count++){
    GetStatus(count)
  }
}
int main(){
  CreateThreads();
  GO();
  return 0;
}
