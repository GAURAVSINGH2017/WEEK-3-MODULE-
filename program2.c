// Organizing product prices 

#include<stdio.h>

// global or large temperory array to handle constraints safely up to N=100000
int temp[100000];

//function to merge two halves of the array 
void merge(int arr[],int st,int mid,int end){
    int i=st; //starting index for the left half
    int j=mid+1;// starting index for the right half
    int k=st;// starting index for the temperory array

    //compare and copy elements from both halves in sorted order
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }

    //copy any remaining elements of the left half
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }

    //copy any remaining elements of the right half 
    while(j<=end){
        temp[k]=arr[j];
        j++;
        k++;
    }

    //copy the sorted elements back into the original array 
    for(i=st;i<=end;i++){
        arr[i]=temp[i];
    }
}

//function to recursively split the array 
void mergesort(int arr[],int st,int end){
    if(st<end){
        int mid=(st+end)/2; //find the middle value

        mergesort(arr,st,mid); //sort the left half
        mergesort(arr,mid+1,end);//sort the right half

        merge(arr,st,mid,end);//merge the two halves
    }
}

int main(){
    int n;

    //read the number of products 
    printf("enter the number of products:");
    scanf("%d",&n);

    int prices[n]; // create an array of name prices

    //read the product prices 
    for(int i=0;i<n;i++){
        printf("enter the %d product price:",i+1);
        scanf("%d",&prices[i]);
    }

    //call merge sort on the entire array      
    mergesort(prices,0,n-1);

    //print the sorted prices seperated by spaces 
    for(int i=0;i<n;i++){
        printf("%d",prices[i]);
        if(i<n-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}                