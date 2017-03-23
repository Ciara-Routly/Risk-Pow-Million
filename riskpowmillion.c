/* Ciara Routly
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRSIZE 1000000

// Function prototypes
void mergeSort(int[], int, int, int);
void merge(int[], int, int);
int findDefeats(int[], int[], int);

int main()
{
    int * arr;
    int * arr2;
    
    arr = malloc(sizeof(int) * ARRSIZE);
    arr2 = malloc(sizeof(int) * ARRSIZE);
    
    int i, n, c, k;
    
    // Number of test cases
    scanf("%d", &c);
    for(k=0;k<c;k++){
        
        // Scan in attacking array
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        // Call merge function to execute mergeSort
        merge(arr, 0, n-1);
        
        /* for(i=0; i<n; i++)
         printf("%d ",arr[i]);
         getchar(); */
        
        // Scan in defending array
        for(i=0;i<n;i++){
            scanf("%d", &arr2[i]);
        }
        // Call merge function to execute mergeSort again for second array
        merge(arr2, 0, n-1);
        
        /* for(i=0;i<n;i++)
         printf("%d ", arr2[i]);
         getchar(); */
        
        printf("%d", findDefeats(arr, arr2, n));
        printf("\n");
        
    }
    
    free(arr);
    free(arr2);
    
    return 0;
    
}

// Function to find max number of defeats that can be made
int findDefeats(int arr[], int arr2[], int n){
    
    int j, i = 0, TOTAL = 0;
    
    // Discover least number in defending array that is greater than the first num in attacking array
    for(j=0;j<n;j++){
        if (arr2[j] > arr[i]){
            // Add one to total
            TOTAL++;
            // Increase index of first array / attacking array
            i++;
        }
    }
    
    return(TOTAL);
    
}

// Function merge calls mergeSort
void merge(int arr[],int min,int max)
{
    int mid;
    // If lowest val in array is less than highest, continue
    if(min < max)
    {
        // Determine mid value - divide in half
        mid = (min+max)/2;
        // Call merge function again - mid becomes high for left side
        merge(arr,min,mid);
        // Mid + 1 becomes low for right side
        merge(arr,mid+1,max);
        mergeSort(arr,min,mid,max);
    }
}

// Function to sort the arrays
void mergeSort(int arr[], int min, int mid, int max)
{
    int temp[30];
    int i,j,k,m;
    j = min;
    m = mid+1;
    
    // Loops through entire array
    for(i=min;j<=mid && m<=max;i++){
        // Within array
        if(arr[j] <= arr[m]){
            temp[i] = arr[j];
            // Increase j towards mid
            j++;
        }
        else {
            // Set temp array
            temp[i] = arr[m];
            // Increase m towards max
            m++;
        }
    }
    // If j is greater than mid val, loop from m to max
    if(j > mid){
        for(k=m;k<=max;k++)
        {
            // Set temp array
            temp[i] = arr[k];
            // Increase min towards max
            i++;
        }
    }
    else {
        for(k=j;k<=mid;k++){
            // Set temp
            temp[i] = arr[k];
            i++;
        }
    }
    // Final one sorted array
    for(k=min;k<=max;k++)
        arr[k] = temp[k];
}
