#include<stdio.h>

int main() {
    int n,i,temp;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++) {
        for(int j=1;j<n-i;j++)
        {
            if(arr[j]<arr[j-1])
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    printf("Sorted List:");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

}
