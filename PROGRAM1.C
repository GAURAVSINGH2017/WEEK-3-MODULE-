//Rank students by marks 
  
#include<stdio.h>
void merge(int arr[],int st,int mid,int end){
  int i=st; //starting index for left half
  int j=mid+1; // starting index for right half
  int k=st; // starting index for temperory array 
  int temp[100000]; // temperory array to store merge elements;

  // compare and copy elements for both halves in sorted order 
  while(i<=mid &&j<=end){
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

  // copy any remaining elements of the left half
  while(i<=mid){
    temp[k]=arr[i];
    i++;
    k++;
  }

  // copy any remaining elements of the right half
  while(j<=end){
    temp[k]=arr[j];
    j++;
    k++;
  }

  // copy the sorted elements back into the original array 
  for(i=st;i<=end;i++){
    arr[i]=temp[i];
  }
}

// function to recursively  split the array 
void mergesort(int arr[],int st,int end){
  if(st<end){
    
    int mid=(st+end)/2; // find the middle value

    mergesort(arr,st,mid); // sort the left half
    mergesort(arr,mid+1,end); // sort the right half
 
    merge(arr,st,mid,end); // merge the two halves
  }
}

int main(){
  int n;


  //enter the number of students
  printf("enter the number of students:");
  scanf("%d",&n);

  int marks[n]; //create an array of named marks 

  //enter the marks of the students 
  for(int i=0;i<n;i++){
    printf("enter the marks of the student %d :",i+1);
    scanf("%d",&marks[i]);
  }

  //call merge sort on the entire array
  mergesort(marks,0,n-1);

  // print the sorted marks seperated by spaces
  for(int i=0;i<n;i++){
    printf("%d",marks[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}