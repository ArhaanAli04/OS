#include<stdio.h>
void findWaitingTime(int processes[],int n,int at[],int bt[],int wt[]){
    int service_time[n];
    service_time[0]=0;
    wt[0]=0;
    for(int i=1;i<n;i++){
        service_time[i]=service_time[i-1]+bt[i-1];
        wt[i]=service_time[i]-at[i];
        if(wt[i]<0){
            wt[i]=0;
        }
    }
}
void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}

void findAverageTime(int processes[],int n,int at[],int bt[]){
    int wt[n];
    int tat[n];
    findWaitingTime(processes,n,at,bt,wt);
    findTurnAroundTime(processes,n,bt,wt,tat);

    int total_wt=0;
    int total_tat=0;
    printf("Process\t\tAT\t\tBT\t\tWT\t\tTAT\n");
    for(int i=0;i<n;i++){
        total_tat += tat[i];
        total_wt += wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);

    }
    printf("\nAverage Waiting Time is: %f",(float)total_wt/(float)n);
    printf("\nAverage TurnAround  Time is: %f",(float)total_tat/(float)n);

}
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n];
    int at[n],bt[n];
    printf("\nEnter the Arrival time and Busrt time for processes: \n");
    for(int i=0;i<n;i++){
        printf("\nProcess %d",i+1);
        printf("\nArrival time: ");
        scanf("%d",&at[i]);
        printf("\nBusrt time: ");
        scanf("%d",&bt[i]);
        processes[i]=i+1;
    }
    findAverageTime(processes,n,at,bt);
    return 0;
}