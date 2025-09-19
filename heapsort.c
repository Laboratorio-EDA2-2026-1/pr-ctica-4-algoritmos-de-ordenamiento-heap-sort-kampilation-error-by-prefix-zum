/*
 * Objetivo: Completar las funciones Max-Heapify, Build-Max-Heap y Heap-Sort.
 * Entradas (stdin):
 *   n

 *   a1 a2 ... an

 * Salida (stdout):
 *   a1 a2 ... an  // en orden ascendente
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


/* PROTOTIPOS: NO CAMBIAR LAS FIRMAS */
void max_heapify(int a[], int n, int i);
void build_max_heap(int a[], int n);
void heap_sort(int a[], int n);

/* MAIN de prueba mínima */
int main(void) {
    int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = (int*)malloc(sizeof(int) * n);
    if (!a) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    heap_sort(a, n);

    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar(' ');

    free(a);
    return 0;
}

/* IMPLEMENTAR AQUÍ */
void max_heapify(int a[], int n, int i) {
    /* TODO */
    int largest = i; //inicializamos en i
    int l = 2*i + 1, r = 2*i + 2; //inicializamos indices de l y r

    if(l<n && a[l] > a[largest]) //Si el elemento en l es mayor al de i, largest ahora va a ser el indice l
        largest = l;

    if(r<n && a[r] > a[largest]) //Si el elemento en r es mayor al de i, largest se convierte en r
        largest = r;

    if(largest != i){ //Si se cumplió alguna de las anteriores, intercambia los elementos en el índice i y largest (ahora l o r) y se llama recursivamente con i = largest
        swap(&a[i], &a[largest]);
        max_heapify(a, n, largest);
    }
}

void build_max_heap(int a[], int n) {
    /* TODO */
    for(int i = n-1; i>0; i--){ //Para todos los elementos empezando por el último hasta el primero, intercambia el indice 0 con el indice i
        swap(&a[0], &a[i]);
        max_heapify(a, i, 0); //Llama a la funcion max_heapify con i como n y 0 como i
    }
}

void heap_sort(int a[], int n) {
    /* TODO */
    for(int i = n/2 -1; i>=0; i--){ //Para cada elemento desde la mitad del arreglo hasta el principio
        max_heapify(a, n, i); //Llama a max_heapify con n, e i
    }

    build_max_heap(a, n);
}
