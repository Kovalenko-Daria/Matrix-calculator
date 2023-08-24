#include "operations.h"

int choose_oper(int *op) {
    float x;
    int f = 1;
    if (scanf("%f", &x) && x == (int)x && x >= 1 && x <= 9) {
        *op = (int)x;
    } else {
        f = 0;
    }
    return f;
}

int input(double ***matrix, int *n, int *m) {
    printf("Input amount of rows and columns: ");
    int f = read_size(n, m);
    if (f) {
        printf("Input matrix:\n");
        *matrix = malloc((*n) * (*m) * sizeof(double) + (*n) * sizeof(double *));
        double *start = (double *)(*matrix + (*n));
        for (int i = 0; i < (*n); i++) {
            (*matrix)[i] = start + (*m) * i;
            f = input_row((*matrix)[i], (*m));
            if (!f) {
                break;
            }
        }
    }
    return f;
}

int read_size(int *rows, int *columns) {
    float row, col;
    int f = 1;
    if (scanf("%f %f", &row, &col) == 2 && row == (int)row && col == (int)col) {
        *rows = (int)row;
        *columns = (int)col;
    } else {
        f = 0;
    }
    return f;
}

int input_row(double *row, int len) {
    char sym;
    double num;
    int amount = 0, f = 1;
    while (f) {
        if (scanf("%lf%c", &num, &sym) == 2 && (sym == 32 || sym == 10)) {
            if (amount <= len) {
                row[amount] = num;
                amount++;
            } else {
                f = 0;
                break;
            }
        } else {
            f = 0;
            break;
        }
        if (sym == 10) {
            if (amount != len) {
                f = 0;
            }
            break;
        }
    }
    return f;
}

void output(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        print_array(matrix[i], m);
    }
}

void print_array(double *array, int length) {
    for (double *p = array; p - array < length; p++) {
        printf("%.2lf", *p);
        if (p - array != length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int sum(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second,
        double ***matrix_result, int *n_result, int *m_result) {
    int f = (n_first == n_second && m_first == m_second);
    if (f) {
        *n_result = n_first;
        *m_result = m_first;
        *matrix_result = malloc((*n_result) * (*m_result) * sizeof(double) + (*n_result) * sizeof(double *));
        double *start = (double *)(*matrix_result + (*n_result));
        for (int i = 0; i < (*n_result); i++) {
            (*matrix_result)[i] = start + (*m_result) * i;
        }
        for (int i = 0; i < (*n_result); i++) {
            for (int j = 0; j < (*m_result); j++) {
                (*matrix_result)[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }
    return f;
}

int sub(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second,
        double ***matrix_result, int *n_result, int *m_result) {
    int f = (n_first == n_second && m_first == m_second);
    if (f) {
        *n_result = n_first;
        *m_result = m_first;
        *matrix_result = malloc((*n_result) * (*m_result) * sizeof(double) + (*n_result) * sizeof(double *));
        double *start = (double *)(*matrix_result + (*n_result));
        for (int i = 0; i < (*n_result); i++) {
            (*matrix_result)[i] = start + (*m_result) * i;
        }
        for (int i = 0; i < (*n_result); i++) {
            for (int j = 0; j < (*m_result); j++) {
                (*matrix_result)[i][j] = matrix_first[i][j] - matrix_second[i][j];
            }
        }
    }
    return f;
}

int mul_num(double ***matrix_first, int* n_first, int* m_first) {
    printf("Enter number: ");
    double num;
    int f = 1;
    if (scanf("%lf", &num)) {
        for (int i = 0; i < (*n_first); i++) {
            for (int j = 0; j < (*m_first); j++) {
                (*matrix_first)[i][j] = (*matrix_first)[i][j]*num;
            }
        }}
    else {
        f = 0;
    }
    return f;
}

int transpose(double ***matrix, int *n, int *m) {
    int k = *n;
    *n = *m;
    *m = k;
    double **matrix_result = malloc((*n) * (*m) * sizeof(double) + (*n) * sizeof(double *));
    double *start = (double *)(matrix_result + (*n));
    for (int i = 0; i < (*n); i++) {
        (matrix_result)[i] = start + (*m) * i;
    }
    for (int i = 0; i < (*n); i++) {
        for (int j = 0; j < (*m); j++) {
            matrix_result[i][j] = (*matrix)[j][i];
        }
    }
    free(*matrix);
    *matrix = matrix_result;
    return 1;
}
int mul(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second,
        double ***matrix_result, int *n_result, int *m_result) {
    int f = (m_first == n_second);
    if (f) {
        *n_result = n_first;
        *m_result = m_second;
        *matrix_result = malloc((*n_result) * (*m_result) * sizeof(double) + (*n_result) * sizeof(double *));
        double *start = (double *)(*matrix_result + (*n_result));
        for (int i = 0; i < (*n_result); i++) {
            (*matrix_result)[i] = start + (*m_result) * i;
        }
        for (int i = 0; i < (*n_result); i++) {
            for (int j = 0; j < (*m_result); j++) {
                int sum = 0;
                for (int k = 0; k < m_first; k++) {
                    sum = sum + matrix_first[i][k] * matrix_second[k][j];
                }
                (*matrix_result)[i][j] = sum;
            }
        }
    }
    return f;
}

void option2(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second, 
int(*func)(double**, int, int, double**, int, int, double***, int*, int*)) {
    double **result = NULL;
    int nr, mr;
    if (func(matrix_first, n_first, m_first, matrix_second, n_second, m_second, &result, &nr, &mr)) {
        printf("Answer:\n");
        output(result, nr, mr);
        free(result);
    } else {
        printf("Error. Try again\n");
    }
}

void option1(double **matrix_first, int n_first, int m_first, int(*func)(double***, int*, int*)) {
    if (func(&matrix_first, &n_first, &m_first)) {
        printf("Answer:\n");
        output(matrix_first, n_first, m_first);
    } else {
        printf("Error. Try again\n");
    }
}