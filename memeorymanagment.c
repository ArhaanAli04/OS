#include<stdio.h>
#include<limits.h>
void printArray(int b,int block[b],int allocatedblock[b]){
    
    for(int i=0;i<b;i++){
        printf("%4d\t",block[i]);
    }
    printf("\n");
    for(int i=0;i<b;i++){
        printf("%4d\t",allocatedblock[i]);
    }
    printf("\n");
}

void first_fit(int b,int block[],int p,int process[]){
    int allocatedblock[b];
    for(int i=0;i<b;i++){
        allocatedblock[i]=-1;
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<b;j++){
            if(block[j]-process[i]>=0 && allocatedblock[j]==-1){
                allocatedblock[j]=process[i];
                break;
            }
        }
    }
    printArray(b,block,allocatedblock);
}
void best_fit(int b,int block[],int p,int process[]){
    int allocatedblock[b];
    for(int i=0;i<b;i++){
        allocatedblock[i]=-1;
    }

    for(int i=0;i<p;i++){
        int diff=INT_MAX;
        int index=-1;
        for(int j=0;j<b;j++){
            if(block[j]-process[i]<diff && block[j]-process[i]>=0 && allocatedblock[j]==-1){
                diff=block[j]-process[i];
                index=j;
            }
        }if(index!=-1){
            allocatedblock[index]=process[i];
        }
    } 
    printArray(b,block,allocatedblock);
}
void worst_fit(int b,int block[],int p,int process[]){
    int allocatedblock[b];
    for(int i=0;i<b;i++){
        allocatedblock[i]=-1;
    }

    for(int i=0;i<p;i++){
        int diff=INT_MIN;
        int index=-1;
        for(int j=0;j<b;j++){
            if(block[j]-process[i]>diff && block[j]-process[i]>=0 && allocatedblock[j]==-1){
                diff=block[j]-process[i];
                index=j;
            }
        }if(index!=-1){
            allocatedblock[index]=process[i];
        }
    } 
    printArray(b,block,allocatedblock);
}
int main(){
    int b;
    printf("Enter the number of blocks: ");
    scanf("%d",&b);
    int p;
    printf("\nEnter the number of processes: ");
    scanf("%d",&p);
    int block[b];
    printf("\nEnter the size of blocks: ");
    for(int i=0;i<b;i++){
        scanf("%d",&block[i]);
    }
    int process[p];
    printf("\nEnter the size of processes: ");
    for(int i=0;i<p;i++){
        scanf("%d",&process[i]);
    }
    printf("\nFirst Fit is given by: \n");
    first_fit(b,block,p,process);
    printf("\nBest Fit is given by: \n");
    best_fit(b,block,p,process);
    printf("\nWorst Fit is given by: \n");
    worst_fit(b,block,p,process);
    return 0;
}