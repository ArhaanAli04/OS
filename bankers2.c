#include<stdio.h>
void printMatrix(int n,int m,int matrix[n][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%4d ",matrix[i][j]);
        }printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d",&n);
    int m;
    printf("\nEnter the number of Resources: ");
    scanf("%d",&m);
    int alloc[n][m];
    printf("\nEnter the allocation Matrix:");
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        scanf("%d",&alloc[i][j]);
       }
    }
    printf("\nThe allocation matrix is given by: \n");
    printMatrix(n,m,alloc);
    int max_need[n][m];
    printf("\nEnter the Maximum Need Matrix:");
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        scanf("%d",&max_need[i][j]);
       }
    }
    printf("\nThe Maximum Need matrix is given by: \n");
    printMatrix(n,m,max_need);

    int avail[m];
    printf("\nEnter the available matrix: ");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    printf("\nThe Available matrix is given by: ");
    for(int i=0;i<m;i++){
        printf("%d ",avail[i]);
    }

    int f[n],ans[n];
    for(int i=0;i<n;i++){
        f[i]=0;
    }

    int need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max_need[i][j]-alloc[i][j];
        }
    }
    printf("\nThe need matrix is given by: \n");
    printMatrix(n,m,need);

    int y=0;
    int ind=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(f[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[ind++]=i;
                    for(y=0;y<m;y++){
                        avail[y]+=alloc[i][y];
                    }f[i]=1;
                }
            }
        }
    }

    int flag1=1;
    for(int i=0;i<n;i++){
        if(f[i]==0){
            printf("\nThe system is not safe");
            flag1=0;
            break;
        }
    }

    if(flag1==1){
        printf("\nThe safe sequence is given by: ");
        for(int i=0;i<n-1;i++){
            printf("P%d -->",ans[i]);
        }printf("P%d",ans[n-1]);
    }

    return 0;
}