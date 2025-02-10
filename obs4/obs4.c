#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **mat, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** createMatrix(int r, int c) {
    int **mat = (int**) malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        mat[i] = (int*) malloc(c * sizeof(int));
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");
    printMatrix(mat, r, c);

    return mat;
}

int** addMatrices() {
  int r, c;
  do {
    printf("Row & Col for Matrix (r>0 c>0): ");
    scanf("%d %d", &r, &c);
  } while (r < 1 || c < 1);

  int **mat1 = createMatrix(r, c);
  int **mat2 = createMatrix(r, c);

  int **matAdd = (int**) malloc(r * sizeof(int*));
  for (int i = 0; i < r; i++) {
    matAdd[i] = (int*) malloc(c * sizeof(int));
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      matAdd[i][j] = mat1[i][j] + mat2[i][j];
    }
  }

  printMatrix(matAdd, r, c);
  return matAdd;
}

int** subMatrices() {
  int r, c;
  do {
    printf("Row & Col for Matrix (r>0 c>0): ");
    scanf("%d %d", &r, &c);
  } while (r < 1 || c < 1);

  int **mat1 = createMatrix(r, c);
  int **mat2 = createMatrix(r, c);

  int **matSub = (int**) malloc(r * sizeof(int*));
  for (int i = 0; i < r; i++) {
    matSub[i] = (int*) malloc(c * sizeof(int));
    for (int j = 0; j < c; j++) 
      matSub[i][j] = mat1[i][j] - mat2[i][j];
  }

  printMatrix(matSub, r, c);
  return matSub;
}

int** multiMatrix(){
    int r1, c1, r2, c2;
    do {
        printf("Row & Col for Matrix1(r>0 c>0): "); scanf("%i %i", &r1, &c1);
        printf("Row & Col for Matrix2(r>0 c>0): "); scanf("%i %i", &r2, &c2);
        printf("\n");
    } while (c1 != r2 || (r1<1) || r2 < 1 || c1 < 1 || c2 < 1);

    int **mat1 = createMatrix(r1, c1);
    int **mat2 = createMatrix(r2, c2);
    int **matMulti = (int**) malloc(r1 * sizeof(int*));
    for (int i=0; i<r1; i++)
        matMulti[i] = (int*) malloc(c2*sizeof(int));

    for (int i=0; i < r1; i++)
        for (int j=0; j < c2; j++)
            for (int k=0; k < c1; k++)
                matMulti[i][j] += mat1[i][k] * mat2[k][j];

    printMatrix(matMulti, r1, c2);
    return matMulti;
}

int** transMatrix(){
    int r, c;
    do {
        printf("Row & Col for Matrix(r>0 c>0): "); scanf("%i %i", &r, &c);
    } while ((r<1) || (c<1));

    int **mat = createMatrix(r,c);
    int **matTrans = (int**) malloc(c * sizeof(int*));
    for (int i=0; i<c; i++)
        matTrans[i] = (int*) malloc(r * sizeof(int));

    for (int i=0; i<c; i++)
        for (int j=0; j<r; j++)
            matTrans[i][j]=mat[j][i];

    printMatrix(matTrans, c, r);
    return matTrans;
}

int main (int argc, char *argv[]) {

    int choice = 0;

    while (choice != 5) {

        printf("1.Add\n2.Sub\n3.Multi\n4.Trans\n5.Exit\nEnter The Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addMatrices();
                break;

            case 2:
                subMatrices();
                break;

            case 3:
                multiMatrix();
                break;

            case 4:
                transMatrix();
                break;

            case 5:
                printf("Bye Bye!\n");
                break;

            default:
                printf("Invalid Choice!\n");
                break;

        }

        printf("\n");

    }

    return 0;
}
