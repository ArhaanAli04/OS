#include<stdio.h>
void printMatrix(int n,int m,int matrix[n][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%4d",matrix[i][j]);
        }printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int m;
    printf("\nEnter the number of resoruces:" );
    scanf("%d",&m);
    int alloc[n][m];
    printf("\nEnter the allocation matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nAllocation matrix is given by: ");
    printMatrix(n,m,alloc);
    int max_need[n][m];
    printf("\nEnter the maximum need matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max_need[i][j]);
        }
    }
    printf("\nMax need matrix is given by: ");
    printMatrix(n,m,max_need);
    int avail[m];
    printf("\nEnter the available matrix: ");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }

    int need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max_need[i][j]-alloc[i][j];

        }
    }
    printf("\nNeed Matrix is given by: ");
    printMatrix(n,m,need);

    int f[n];
    for(int i=0;i<n;i++){
        f[i]=0;

    }

    int ans[n];
    int ind=0;
    int y=0;
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
                        f[i]=1;
                    }
                }
            }
        }
    }

    int flag1=1;
    for(int i=0;i<n;i++){
        if(f[i]==0){
            flag1=0;
            printf("\nThe system is not in asafe state");
            break;
        }
    }

    if(flag1==1){
        for(int i=0;i<n-1;i++){
            printf("P%d-->",ans[i]);
        }printf("P%d",ans[n-1]);
    }
    return 0;
}