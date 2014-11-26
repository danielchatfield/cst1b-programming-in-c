#include <stdio.h>

void _mergesort(int arr[], int start, int length, int tmp[]) {
    if(length < 2) {
        return;
    }


    // split into 2 parts
    int half_length = length / 2;
    int middle = start + half_length;


    // sort parts
    _mergesort(arr, start, half_length, tmp);
    _mergesort(arr, middle, length - half_length, tmp);

    //merge the lists
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < half_length && j < length - half_length) {
        int left = arr[start+i];
        int right = arr[middle+j];

        if (left < right) {
            tmp[k] = left;
            i++;
        } else {
            tmp[k] = right;
            j++;
        }
        k++;
    }

    // finish it off
    while (i < half_length) {
        tmp[k] = arr[start+i];
        i++;
        k++;
    }
    while (j < length - half_length) {
        tmp[k] = arr[middle+j];
        j++;
        k++;
    }

    // copy back into original array
    for(k = 0; k < length; k++) {
        arr[start+k] = tmp[k];
    }
}

void mergesort(int arr[], int length) {
    //not sure why compiler complains without the ampersand
    int tmp[length];
    _mergesort(arr, 0, length, tmp);
}

int main(void) {
    int items[] = {4, 6, 5, 1, 8, 2, 8, 6};
    int n = sizeof(items)/sizeof(int);
    mergesort(items, n);


    for (int i = 0; i < n; i++) {
        if(i != 0) {
            printf(",");
        }
        printf("%d", items[i]);
    }
    return 0;
}
