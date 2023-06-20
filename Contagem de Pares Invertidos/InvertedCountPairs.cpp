#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int invCount = 0;

    int i = left;      
    int j = mid + 1;    
    int k = left;       

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // Conta as inversões
        }
    }

    // Copia os elementos restantes da sublista esquerda (se houver)
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copia os elementos restantes da sublista direita (se houver)
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copia de volta os elementos mesclados para o vetor original
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// Função auxiliar para a contagem de inversões recursiva
int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Conta as inversões nas sublistas esquerda e direita
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // Mescla as sublistas e conta as inversões durante a mesclagem
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }

    return invCount;
}

// Função principal para contar as inversões em um vetor
int countInversions(vector<int>& arr) {
    int n = arr.size(); 
    vector<int> temp(n); // Vetor temporário para a mesclagem

    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    vector<int> arr = {4, 2, 1, 3, 5};
    int inversions = countInversions(arr);

    cout << "O número de inversões no vetor é: " << inversions << endl;

    return 0;
}
