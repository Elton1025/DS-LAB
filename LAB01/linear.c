#include<stdio.h>

int main() {


    int key,i,n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter element to be searched:");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(arr[i]==key) {
            printf("%d found at %d",key,i+1);
            return;
        }
    }
    printf("Element not found");

}
