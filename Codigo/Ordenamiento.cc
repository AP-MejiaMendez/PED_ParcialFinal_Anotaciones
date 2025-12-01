void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                //std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int indice_minimo = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[indice_minimo]) {
                indice_minimo = j;
            }
        }
        //std::swap(arr[i], arr[indice_minimo]);
    }
}

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int clave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = clave;
    }
}

void Merge(int arr[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    int left[n1], right[n2];

    for (int i = 0; i < n1; ++i) left[i] = arr[inicio + i];
    for (int j = 0; j < n2; ++j) right[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void MergeSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        MergeSort(arr, inicio, medio);
        MergeSort(arr, medio + 1, fin);
        Merge(arr, inicio, medio, fin);
    }
}