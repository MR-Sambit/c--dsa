#include<stdio.h>

void selectionsort(int a[], int n){
    int i, j, min, temp;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

}
void printarray(int a[],int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}
int main(){
    int a[100];
    int n;
    
    printf("Enter Your array size - ");
    scanf("%d", &n);
    printf("Enter Your array elements - ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionsort(a, n);
    printarray(a, n);
    

    return 0;

}