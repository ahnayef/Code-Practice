#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for (int  aiv = 0; aiv < n; aiv++)
    {
        scanf("%d",&arr[aiv]);
    }
    


    int q;
    scanf("%d",&q);
    int i,v;

    for (int  j = 0; j < q; j++)
    {
        scanf("%d %d",&i,&v);
        arr[i]=arr[i]+v;
    }
    
    for (int k = 0; k < n; k++)
    {
        printf("%d ",arr[k]);
    }
    

}