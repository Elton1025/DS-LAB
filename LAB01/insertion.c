
#include<stdio.h>

int main() {
    int n,i,j,key;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=1;i<n;i++)
    {
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;

    }

    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }



}