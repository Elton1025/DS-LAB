#include<stdio.h>

int main() {

    int n,i,key;

    printf("Enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements:");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched:");
    scanf("%d",&key);

    int result = binary(arr,n,key);
    if(result !=-1) {
        printf("Element found at %d", result);
    }
    else {
        printf("Element not found");
    }
}
int binary(int arr[],int n,int key) {
    int m;
    int s=0;
    int e=n-1;
    while(s<=e) {
        m=s+(e-s)/2;
        if(arr[m]==key) {
            return m+1;
        }
        else if(arr[m]>key) {
            e=m-1;

        }
        else if(arr[m]<key) {
            s=m+1;
        }

    }
    return -1;
}

