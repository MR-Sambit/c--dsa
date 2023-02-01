#include<stdio.h>
void insertionsort(){
    int a[100];
    int n;
    printf("Enter Your array size - ");
    scanf("%d", &n);
    printf("Enter Your array elements - ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int i, j, temp;
    for(i=1; i<n; i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
// void printarray(int a[],int n){
//     int i;
//     for(i=0; i<n; i++){
//         printf("%d ", a[i]);
//     }

int main(){
    insertionsort();

    return 0;
}