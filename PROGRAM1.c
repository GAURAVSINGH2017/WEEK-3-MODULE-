//Race timing analysis       

#include<stdio.h>

// Function to sort the array using a simple quick sort method 
void quicksort(int arr[],int st,int end){
  if(st<end){
    int pivot=st; //set the first element as the pivot 
    int i=st;
    int j=end;
    int temp;

    //Rearrange elements around the pivot
    while(i<j){
      while(arr[i]<=arr[pivot] && i<end){
        i++;
      }
      while(arr[j]>arr[pivot]){
        j--;
      }
      if(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }

    // swap the pivot element into its correct sorted position 
    temp=arr[pivot];
    arr[pivot]=arr[j];
    arr[j]=temp;

    //Recursively sort the left and right parts 
    quicksort(arr,st,j-1);
    quicksort(arr,j+1,end);
  }
}

int main(){
  int n;

  //Read total number of elements
  printf("enter the number of elements:");
  scanf("%d",&n);

  int timings[n]; //creating an array of named timings 

  //Read the timings dataset 
  for(int i=0;i<n;i++){
    printf("enter the %d timings:",i+1);
    scanf("%d",&timings[i]);
  }

  //Run simple quicksort from index 0 to n-1
  quicksort(timings,0,n-1);

  //print the sorted elements seperated by the spaces 
  for(int i=0;i<n;i++){
    printf("%d",timings[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}