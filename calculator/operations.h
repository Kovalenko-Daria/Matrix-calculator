#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

void show_menu();
void option2(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second,
    int(*func)(double**, int, int, double**, int, int, double***, int*, int*));
void option1(double **matrix_first, int n_first, int m_first, int(*func)(double***, int*, int*));
int input(double ***matrix, int *n, int *m);
void output(double **matrix, int n, int m);
int sum(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second,
        double ***matrix_result, int *n_result, int *m_result);
int sub(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second,
        double ***matrix_result, int *n_result, int *m_result);
int transpose(double ***matrix, int *n, int *m);
int mul(double **matrix_first, int n_first, int m_first, double **matrix_second, int n_second, int m_second,
        double ***matrix_result, int *n_result, int *m_result);
int mul_num(double ***matrix_first, int* n_first, int* m_first);
void find_det(double** matrix, int n, int m);
void inverse_matrix(double*** matrix, int n, int m);
double det(double **matrix, int n);
void cut_matrix(double **init_matrix, int n, int x, int y, double ***matrix);
double invert(double ***matrix, int n);
void solve_sle(double** matrix, int n, int m);
int sle(double **matrix, int n, int m, double **roots);
void matr_for_kr(double **init_matrix, double *col_y, int n, int x, double ***matrix);
void create_matr(double **init_matrix, double ***matrix, int n);
void create_ans_col(double **init_matrix, double **col_y, int n);
int choose_oper(int *op);
void print_array(double *array, int length);
int read_size(int *rows, int *columns);
int input_row(double *row, int len);
void print_array(double *array, int length);

#endif