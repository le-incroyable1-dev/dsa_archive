#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){

    int x = arr[r];
    int i = l-1;

    for(int j = l; j <= r-1; ++j){
        if(arr[j] <= arr[x]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[r]);
    return (i+1);
}


void quickSort(int arr[], int l, int r){

    if(l < r){

        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

int main(){

    int arr[] = {0, 1, 65, 32, 42, 5, 3, 2};
    quickSort(arr, 0, 7);

    for(auto x:arr)
    cout << x << " ";

    return 0;
}