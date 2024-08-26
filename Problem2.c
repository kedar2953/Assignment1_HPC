#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads;

    //Number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Sequential Hello, World
    printf("Sequential Hello, World:\n");
    for (int i = 0; i < num_threads; i++) {
        printf("Hello, World from thread %d\n", i);
    }

    // Setting the number of threads for OpenMP
    omp_set_num_threads(num_threads);

    // Parallel Hello, World
    printf("\nParallel Hello, World:\n");
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Hello, World from thread %d\n", thread_id);
    }

    return 0;
}
