#include<stdio.h>
#include<time.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j = low;j< high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
        swap(&arr[i+1],&arr[high]);
        return (i+1);
    }

    void quick_sort(int arr[],int low,int high){
        if(low<high){   
        int part_index=partition(arr,low,high);
        quick_sort(arr,low,part_index-1);
        quick_sort(arr,part_index+1,high);
    }
}

int main(){
     clock_t start,end;
     int arr[15000];
     int n = 500;
     
     while(n<=14500){
        for(int i=0;i<n ;i++){
            arr[i]=n-i;
        }
        start =clock();
        quick_sort(arr,0,n-1);
        end=clock();
        printf("\nTime taken to sort %d is %f secs",n,((double)(end-start))/(CLOCKS_PER_SEC));
        n=n+1000;
    }
    
     }
    
