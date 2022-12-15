//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int k=l;
        int l1=m-l+1;
        int l2=r-m;
        int *arr1=new int[l1];
        int *arr2=new int[l2];
        
        for(int i=0;i<l1;i++)
        {
            arr1[i]=arr[k++];
        }
        for(int i=0;i<l2;i++)
        {
            arr2[i]=arr[k++];
        }
         k=l;
        int i=0;
        int j=0;
        while(i<l1 && j<l2)
        {
            if(arr1[i]<arr2[j])
            {
                arr[k]=arr1[i];
                i++;
                k++;
            }
            else
            {
                arr[k]=arr2[j];
                j++;
                k++;
            }
        }
        while(i<l1)
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        while(j<l2)
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        {
            return ;
        }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,(l+r)/2,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends