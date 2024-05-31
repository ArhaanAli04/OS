#include<stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int hitain[n][n];
    printf(" Matrix hitain is given by: \n");
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    printf("He  ",hitain[i][j]);
     }
     printf("\n");
      }
    return 0;
}