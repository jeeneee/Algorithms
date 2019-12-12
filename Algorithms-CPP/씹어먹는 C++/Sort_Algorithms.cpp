#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int sorted[1000000];

void selectionSort (int a[], int size) {
    int index = 0;
    
    for (int i = 0; i < size; i++) {
        int min = 9999;
        for (int j = i; j < size; j++) {
            if (a[j] < min) {
                min = a[j];
                index = j;
            }
        }
        int temp = a[index];
        a[index] = a[i];
        a[i] = temp;
    }
}

void bubbleSort (int a[], int size) {
    for (int i=1; i < size; i++) {
        for (int j=0; j<size-i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void insertSort (int a[], int size) {
    for (int i = 0; i < size-1; i++) {
        int j = i;
        while (a[j] > a[j+1] && j >= 0) {
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            j--;
        }
    }
}

void merge (int a[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        }
        else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    for (int t = m; t <= n; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort (int a[], int m, int n) {
    if (m < n) {
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}

void quickSort (int a[], int start, int end) {
    if (start >= end) {
        return;
    }
    int key = start;
    int i = start + 1;
    int j = end;
    
    while (i <= j) { // 엇갈릴때까지
        while (i <= end && a[i] <= a[key]) {
            i++;
        }
        while (j > start && a[j] >= a[key]) {
            j--;
        }
        if (i > j) {
            int temp = a[j];
            a[j] = a[key];
            a[key] = temp;
        }
        else {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    
    quickSort(a, start, j-1);
    quickSort(a, j+1, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr;
    int n, num;
    
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    int *arr4 = new int[n];
    int *arr5 = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
        arr4[i] = num;
        arr5[i] = num;
        arr.push_back(num);
    }
    
    /* sort STL */
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    
    /* mergeSort */
    mergeSort(arr1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << ' ';
    }
    cout << endl;
    
    /* selectionSort */
    selectionSort(arr2, n);
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << ' ';
    }
    cout << endl;
    
    /* bubbleSort */
    bubbleSort(arr3, n);
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << ' ';
    }
    cout << endl;
    
    /* insertSort */
    insertSort(arr4, n);
    for (int i = 0; i < n; i++) {
        cout << arr4[i] << ' ';
    }
    cout << endl;
    
    /* quickSort */
    quickSort(arr5, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr5[i] << ' ';
    }
    cout << endl;
}
