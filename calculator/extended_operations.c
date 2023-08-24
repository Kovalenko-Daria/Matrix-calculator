#include "operations.h"

void find_det(double** matrix, int n, int m) {
    if (n != m) {
        printf("Error. Try again\n");
    }
    else {
        printf("Determinant of this matrix is %.2lf\n", det(matrix, n));
    }
}

double det(double **matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    double ans = 0;
    int k;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            k = -1;
        } else {
            k = 1;
        }
        double **mat = NULL;
        cut_matrix(matrix, n, 0, i, &mat);
        double opr = det(mat, n - 1);
        ans = ans + k * matrix[0][i] * opr;
        free(mat);
    }
    return ans;
}

void cut_matrix(double **init_matrix, int n, int x, int y, double ***matrix) {
    *matrix = malloc((n - 1) * (n - 1) * sizeof(double) + (n - 1) * sizeof(double *));
    double *start = (double *)(*matrix + (n - 1));
    for (int i = 0; i < (n - 1); i++) {
        (*matrix)[i] = start + (n - 1) * i;
    }
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; i++) {
        k2 = 0;
        if (i != x) {
            for (int j = 0; j < n; j++) {
                if (j != y) {
                    (*matrix)[k1][k2] = init_matrix[i][j];
                    k2++;
                }
            }
            k1++;
        }
    }
}

void inverse_matrix(double*** matrix, int n, int m) {
    if (n != m) {
        printf("Error. Try again\n");
    }
    else if (invert(matrix, n)) {
        printf("Inverse matrix:\n");
        output(*matrix, n, m);
    }
    else {
        printf("There is no inverse matrix for the entered one\n");
    }
}

double invert(double ***matrix, int n) {
    double opr = det(*matrix, n);
    if (opr) {
    double mn = 1.0 / opr;
    transpose(matrix, &n, &n);
    double **matrix_result = malloc(n * n * sizeof(double) + n * sizeof(double *));
    double *start = (double *)(matrix_result + n);
    for (int i = 0; i < n; i++) {
        matrix_result[i] = start + n * i;
    }
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2) {
                k = -1;
            } else {
                k = 1;
            }
            double **opr_alg = NULL;
            cut_matrix(*matrix, n, i, j, &opr_alg);
            double min_opr = det(opr_alg, n - 1);
            matrix_result[i][j] = min_opr * k * mn;
            free(opr_alg);
        }
    }
    free(*matrix);
    *matrix = matrix_result;}
    return opr;
}

void matr_for_kr(double **init_matrix, double *col_y, int n, int x, double ***matrix) {
    *matrix = malloc(n * n * sizeof(double) + n * sizeof(double *));
    double *start = (double *)(*matrix + n);
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = start + n * i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == x) {
                (*matrix)[i][j] = col_y[i];
            } else {
                (*matrix)[i][j] = init_matrix[i][j];
            }
        }
    }
}

void create_matr(double **init_matrix, double ***matrix, int n) {
    *matrix = malloc(n * n * sizeof(double) + n * sizeof(double *));
    double *start = (double *)(*matrix + n);
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = start + n * i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*matrix)[i][j] = init_matrix[i][j];
        }
    }
}

void create_ans_col(double **init_matrix, double **col_y, int n) {
    *col_y = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        (*col_y)[i] = init_matrix[i][n];
    }
}

int sle(double **matrix, int n, int m, double **roots) {
    int f = 1;
    double **matrix1 = NULL;
    double *col_y = NULL;
    create_ans_col(matrix, &col_y, n);
    create_matr(matrix, &matrix1, n);
    double osn_opr = det(matrix1, n);
    if (osn_opr) {
        *roots = malloc((m - 1) * sizeof(double));
        for (int i = 0; i < m - 1; i++) {
            double **matr_for_kram = NULL;
            matr_for_kr(matrix1, col_y, n, i, &matr_for_kram);
            double min_opr = det(matr_for_kram, n);
            (*roots)[i] = min_opr / osn_opr;
            free(matr_for_kram);
        }
    } else {
        f = 0;
    }
    free(matrix1);
    free(col_y);
    return f;
}

void solve_sle(double** matrix, int n, int m) {
    if (n != m - 1) {
        printf("Error. Try again\n");
    }
    else{
        double* ans = NULL;
        if (sle(matrix, n, m, &ans)) {
            printf("Answers:\n");
            print_array(ans, n);
            free(ans);
        }
        else {
            printf("There is no inverse matrix for the entered one\n");
        }
    }
}