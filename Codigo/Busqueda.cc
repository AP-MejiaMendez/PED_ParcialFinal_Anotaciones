int LinearSearch(int arr[], int n, int objetivo) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == objetivo) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[], int n, int objetivo) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == objetivo) {
            return medio;
        } else if (arr[medio] < objetivo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}

int BinarySearchRec(int arr[], int inicio, int fin, int objetivo) {
    if (inicio > fin) {
        return -1;
    }

    int medio = inicio + (fin - inicio) / 2;

    if (arr[medio] == objetivo) {
        return medio;
    }

    if (arr[medio] > objetivo) {
        return BinarySearchRec(arr, inicio, medio - 1, objetivo);
    }

    return BinarySearchRec(arr, medio + 1, fin, objetivo);
}

int InterpolationSearch(int arr[], int n, int objetivo) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin && objetivo >= arr[inicio] && objetivo <= arr[fin]) {
        int pos = inicio + ((objetivo - arr[inicio]) * (fin - inicio)) /
                             (arr[fin] - arr[inicio]);

        if (arr[pos] == objetivo) {
            return pos;
        }

        if (arr[pos] < objetivo) {
            inicio = pos + 1;
        } else {
            fin = pos - 1;
        }
    }

    return -1;
}
