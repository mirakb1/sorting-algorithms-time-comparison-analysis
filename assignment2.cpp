#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void fillNumRandomly(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void copyNums(int from[], int to[], int n) {
    for (int i = 0; i < n; i++) {
        to[i] = from[i];
    }
}

int findMin(int arr[], int start, int n) {
    int minindex = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[minindex]) {
            minindex = i;
        }
    }
    return minindex;
}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minindex = findMin(arr, i, n);
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

void insertionsort(int arr[], int n) {
    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;

        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }

        arr[i + 1] = key;
    }
}

void merge(int arr[], int start, int mid, int end) {
    int* B = new int[end + 1];
    int i, j, k;

    i = start;
    j = mid + 1;
    k = i;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            i++;
            k++;
        }
        else {
            B[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end) {
        B[k] = arr[j];
        j++;
        k++;
    }

    for (k = start; k <= end; k++) {
        arr[k] = B[k];
    }

    delete[] B;
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void swapNums(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int partitionArr(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (i <= right && arr[i] <= pivot) {
            i++;
        }

        while (j >= left && arr[j] > pivot) {
            j--;
        }

        if (i >= j) {
            swapNums(arr[left], arr[j]);
            return j;
        }
        else {
            swapNums(arr[i], arr[j]);
        }
    }
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int h = partitionArr(arr, left, right);
        quicksort(arr, left, h - 1);
        quicksort(arr, h + 1, right);
    }
}

void shiftdown(int v[], int i, int n) {
    int temp = v[i];
    int flag = 0;

    while (2 * i <= n && !flag) {
        int child = 2 * i;

        if (child + 1 <= n && v[child] < v[child + 1]) {
            child = child + 1;
        }

        if (v[child] > temp) {
            v[i] = v[child];
            i = child;
        }
        else {
            flag = 1;
        }
    }

    v[i] = temp;
}

void heapinsert(int v[], int& n, int value) {
    n = n + 1;
    int i = n;

    while (i > 1 && value > v[i / 2]) {
        v[i] = v[i / 2];
        i = i / 2;
    }

    v[i] = value;
}

void heapsort(int arr[], int n) {
    int* v = new int[n + 1];
    int heapsize = 0;

    for (int i = 0; i < n; i++) {
        heapinsert(v, heapsize, arr[i]);
    }

    for (int i = n; i >= 2; i--) {
        swapNums(v[1], v[i]);
        shiftdown(v, 1, i - 1);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = v[i + 1];
    }

    delete[] v;
}

void countingsort(int arr[], int n) {
    int count[101] = { 0 };
    int* output = new int[n];

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));

    int choice;
    const int sizes[4] = { 10000, 20000, 30000, 50000 };

    cout << "1.selection sort" << endl;
    cout << "2.insertion sort" << endl;
    cout << "3.merge sort" << endl;
    cout << "4.quick sort" << endl;
    cout << "5.heap sort" << endl;
    cout << "6.counting sort" << endl;
    cout << "enter your choice: "<<endl;
    cout << "------------------------ " << endl;
    cin >> choice;

    for (int k = 0; k < 4; k++) {
        int n = sizes[k];

        int* original = new int[n];
        int* arr = new int[n];

        fillNumRandomly(original, n);
        copyNums(original, arr, n);

        clock_t start = clock();

        if (choice == 1) {
            selectionsort(arr, n);
        }
        else if (choice == 2) {
            insertionsort(arr, n);
        }
        else if (choice == 3) {
            mergesort(arr, 0, n - 1);
        }
        else if (choice == 4) {
            quicksort(arr, 0, n - 1);
        }
        else if (choice == 5) {
            heapsort(arr, n);
        }
        else if (choice == 6) {
            countingsort(arr, n);
        }
        else {
            cout << "wrong choice" << endl;
            delete[] original;
            delete[] arr;
            return 0;
        }

        clock_t stop = clock();
        double totaltime = double(stop - start) / CLOCKS_PER_SEC;

        cout << "array size = " << n << endl;

        if (choice == 1) {
            cout << "selection sort time = " << totaltime << " seconds" << endl;
        }
        else if (choice == 2) {
            cout << "insertion sort time= " << totaltime << " seconds" << endl;
        }
        else if (choice == 3) {
            cout << "merge sort time = " << totaltime << " seconds" << endl;
        }
        else if (choice == 4) {
            cout << "quick sort time = " << totaltime << " seconds" << endl;
        }
        else if (choice == 5) {
            cout << "heap sort time = " << totaltime << " seconds" << endl;
        }
        else if (choice == 6) {
            cout << "counting sort time = " << totaltime << " seconds" << endl;
        }

        if (isSorted(arr, n)) {
            cout << "sorted done" << endl;
        }
        else {
            cout << "there is a problen" << endl;
        }

        cout << "----------------------" << endl;

        delete[] original;
        delete[] arr;
    }
}