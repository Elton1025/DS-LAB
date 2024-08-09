#include<stdio.h>

int main() {

    int n,i,key,m;

    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++) {
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched:");
    scanf("%d",&key);
    insertion(arr,n);
    int s=0;
    int e=n-1;
    while(s<=e) {
        m=(s+e)/2;
        if(arr[m]==key) {
            printf("%d found at %d",key,m+1);
            break;
        }
        else if(arr[m]>key) {
            e=m;
            m=(s+e)/2;

        }
        else if(arr[m]<key) {
            s=m;
            m=(s+e)/2;
        }

    }



}
void insertion(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;

        while(j>=0 && temp <= a[j])
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = temp;
    }
}

