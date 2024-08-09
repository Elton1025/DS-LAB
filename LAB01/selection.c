
#include<stdio.h>

int main() {
    int n,i,j,small,temp;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n-1;i++) {
        small=i;
        for(j=i+1;j<n;j++)
        {

            if(arr[j]<arr[small]) {
                small=j;


            }


        }
        temp=arr[small];
        arr[small]=arr[i];
        arr[i]=temp;

    }
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

}
