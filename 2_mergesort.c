#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r) {
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int *L = (int*)malloc(n1*sizeof(int));
	int *R = (int*)malloc(n2*sizeof(int));
	
	for(i = 0; i<n1 ;i++){
		L[i] = arr[p+i];
	}
	for(j = 0; j<n2 ; j++){
		R[j] = arr[q+1+j];
	}
	
	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
 }
}

int main() {
	printf("Name : Om Mahajan\nPRN : 25070521165 \n");
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements of array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array : ");
      for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf(" \n");
    mergeSort(arr, 0, n - 1);
    printf("Sort array : ");
      for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;

}