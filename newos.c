#include<stdio.h>
#include<stdlib.h>

int disk_size =199;
void sort(int n,int requests[n]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(requests[j]>requests[j+1]){
                //swap requests[j] and requests[j+1]
                int temp=requests[j];
                requests[j]=requests[j+1];
                requests[j+1]=temp;
            }
        }
    }
}

int fcfs(int n,int requests[n],int head){
    int seek=0;
    for(int i=0;i<n;i++){
        seek +=abs(requests[i]-head);
        head=requests[i];
    }
    return seek;
}

int scan(int n,int requests[n],int head){
    sort(n,requests);
    int i=0;
    for(i=0;i<n;i++){
        if(requests[i]>head){
            break;
        }
    }
    int k=0;
    int new[n+2];
    new[k++]=head;
    for(int j=i;j<n;j++){
        new[k++]=requests[j];
    }
    new[k++]=disk_size;
   // new[k++]=0;

    for(int j=i-1;j>=0;j--){
        new[k++]=requests[j];
    }
    //calculate seek time
    int seek=0;
    for(i=0;i<n+2;i++){
        seek +=abs(new[i]-head);
        head=new[i];
    }
    return seek;
}
int cscan(int n,int requests[n],int head){
    sort(n,requests);
    int i=0;
    for(i=0;i<n;i++){
        if(requests[i]>head){
            break;
        }
    }
    int k=0;
    int new[n+2];
    new[k++]=head;
    for(int j=i;j<n;j++){
        new[k++]=requests[j];
    }
    new[k++]=disk_size;
    new[k++]=0;

    for(int j=0;j<i;j++){
        new[k++]=requests[j];
    }
    //calculate seek time
    int seek=0;
    for(i=0;i<n+2;i++){
        seek +=abs(new[i]-head);
        head=new[i];
    }
    return seek;
}
int main(){
    int n;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    int requests[n];
    printf("\nEnter the requests: ");
    for(int i=0;i<n;i++){
        scanf("%d",&requests[i]);
    }
    int head;
    printf("\nEnter the head position: ");
    scanf("%d",&head);
    printf("\nThe seek time for fcfs is given by: %d",fcfs(n,requests,head));
    printf("\nThe seek time for scan is given by: %d",scan(n,requests,head));
    printf("\nThe seek time for c scan is given by: %d",cscan(n,requests,head));
    return 0;
}