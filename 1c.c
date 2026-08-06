#include <stdio.h>
int main() {
    int n=3;
    int arr[3][3]={{0,1,1},{0,1,1},{1,1,1}};
    int i=0,j=n-1,row=1;
    while(i<n && j>=0)
    {
        if(arr[i][j]==1)
        {
            j--;
        }
        else
        {
            i++;
            row++;
        }
    }
    printf("Row with maximum number of 1s is %d", row);
    return 0;
}
