#include <stdio.h>
int main() {
    int n=4;
    int arr[4][4]={10, 20, 30, 40,15, 25, 34, 41,27, 29, 35, 45,32, 33, 38, 49};
    int i=0, j=n-1,key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    while(i<n && j>=0)
    {
        if(arr[i][j]==key)
        {
            printf("Key found at (%d, %d)", i, j);
            return 0;
        }
        else if(arr[i][j]>key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    printf("Key not found"); 
       return 0;
    }
