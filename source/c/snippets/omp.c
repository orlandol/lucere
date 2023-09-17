#include <stdio.h>
#include <omp.h>

int main() {
    int i, n = 10;
    int a[n], b[n], c[n];

    // Initialize arrays
    for (i = 0; i < n; i++) {
        a[i] = i * i;
        b[i] = i;
    }

    // PARALLEL directive
    #pragma omp parallel
    {
        printf("Hello from thread %d out of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
    }

    // PARALLEL FOR directive
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
        printf("Thread %d computes c[%d] = %d\n", omp_get_thread_num(), i, c[i]);
    }

    // SECTIONS directive
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("This is section 1 executed by thread %d\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("This is section 2 executed by thread %d\n", omp_get_thread_num());
        }
    }

    // SINGLE directive
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("This is executed by a single thread: %d\n", omp_get_thread_num());
        }
    }

    // CRITICAL directive
    int sum = 0;
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        #pragma omp critical
        {
            sum += c[i];
        }
    }
    printf("Sum is %d\n", sum);

    // PARALLEL FOR with REDUCTION clause
    int prod = 1;
    #pragma omp parallel for reduction(*:prod)
    for (i = 1; i <= n; i++) {
        prod *= i;
    }
    printf("Factorial of %d is %d\n", n, prod);

    return 0;
}
