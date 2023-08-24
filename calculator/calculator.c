#include "operations.h"

int main() {
    double **a1 = NULL;
    double **a2 = NULL;
    int n1, m1, n2, m2, op, f = 1;
    while (f){
        show_menu();
    if (choose_oper(&op)) {
        if (op == 9) {
            f = 0;
        }
        else if (input(&a1, &n1, &m1) && (op >= 4 || input(&a2, &n2, &m2))) {
            switch (op) {
                case 1: {
                    option2(a1, n1, m1, a2, n2, m2, sum);
                    break;
                }
                case 2: {
                    option2(a1, n1, m1, a2, n2, m2, sub);
                    break;
                }
                case 3: {
                    option2(a1, n1, m1, a2, n2, m2, mul);
                    break;
                }
                case 4: {
                    option1(a1, n1, m1, mul_num);
                    break;
                }
                case 5: {
                    option1(a1, n1, m1, transpose);
                    break;
                }
                case 6: {
                    find_det(a1, n1, m1);
                    break;
                }
                case 7: {
                    inverse_matrix(&a1, n1, m1);
                    break;
                }
                case 8: {
                    solve_sle(a1, n1, m1);
                    break;
                }
            }
        } else {
            printf("Error. Try again\n");
        }
    } else {
        printf("Error. Try again\n");
    }
    }
    if (a1) {
        free(a1);
    }
    if (a2) {
        free(a2);
    }
    return 0;
}

void show_menu() {
    printf("1. Addition of two matrices\n2. Subtracting of two matrices\n");
    printf("3. Multiplication of two matrices\n4. Multiplying a matrix by a number\n");
    printf("5. Matrix transposition\n6. Determinant of a square matrix\n");
    printf("7. Inverse square matrix\n8. System of linear equation\n9. Exit\n");
    printf("Choose an option: ");
}