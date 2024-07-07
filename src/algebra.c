#include "../inc/algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    int rows, cols;
    if(a.rows == b.rows&&a.cols == b.cols)
    {
        rows = a.rows;
        cols = a.cols;
        Matrix c = create_matrix(rows, cols);
        int i,j;
        for ( i = 0; i < rows; i++)
        {
            for ( j = 0; j < cols; j++)
            {
                c.data[i][j] = a.data[i][j]+b.data[i][j];
            }
        }
        return c;
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    int rows, cols;
    if(a.rows == b.rows&&a.cols == b.cols)
    {
        rows = a.rows;
        cols = a.cols;
        Matrix c = create_matrix(rows, cols);
        int i,j;
        for ( i = 0; i < rows; i++)
        {
            for ( j = 0; j < cols; j++)
            {
                c.data[i][j] = a.data[i][j]-b.data[i][j];
            }
        }
        return c;
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    int rows, cols;
    if(a.cols == b.rows)
    {
        rows = a.rows;
        cols = b.cols;
        Matrix c = create_matrix(rows, cols);
        int i,j;
        for ( i = 0; i < rows; i++)
        {
            for ( j = 0; j < cols; j++)
            {
                int k;
                for ( k = 0; k < a.cols; k++) 
                {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }
        return c;
    }
    else
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);
    }
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    int rows, cols;
    rows = a.rows;
    cols = a.cols;
    Matrix c = create_matrix(rows, cols);
    int i,j;
        for ( i = 0; i < rows; i++)
        {
            for ( j = 0; j < cols; j++)
            {
                c.data[i][j] = k*a.data[i][j];
            }
        }
        return c;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    int rows, cols;
    rows = a.cols;
    cols = a.rows;
    Matrix c = create_matrix(rows, cols);
    int i,j;
        for ( i = 0; i < rows; i++)
        {
            for ( j = 0; j < cols; j++)
            {
                c.data[i][j] = a.data[j][i];
            }
        }
        return c;
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    int rows, cols;
    rows = a.cols;
    cols = a.rows;
    Matrix c = create_matrix(rows-1, cols-1);
    if(rows==cols)
    {
        int n =rows;
        double det = 0;
        if (n == 2) 
        {
            return (a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0]);
        } 
        else
        {
            int x,i,j;
            for ( x = 0; x < n; x++)
            {
                int subi = 0;
                for ( i = 1; i < n; i++) 
                {
                    int subj = 0;
                    for ( j = 0; j < n; j++) 
                    {
                        if (j == x)
                            continue;
                        c.data[subi][subj] = a.data[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * a.data[0][x] * det_matrix(c));
            }
        }
        return det;
    }
    else
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    int rows, cols;
    rows = a.cols;
    cols = a.rows;
    Matrix c = create_matrix(rows-1, cols-1);
    if( rows==cols && det_matrix(a)!=0)
    {
        int n =rows;
        int x,k,i,j;
        Matrix d = create_matrix(rows, cols);
        for(k = 0;k < n;k++)
        {
            for ( x = 0; x < n; x++)
            {
                int subi = 0;
                for ( i = 0; i < n; i++) 
                {
                    if(i==k)
                        continue;
                    int subj = 0;
                    for ( j = 0; j < n; j++) 
                    {
                        if (j == x)
                            continue;
                        c.data[subi][subj] = a.data[i][j];
                        subj++;
                    }
                    subi++;
                }
                d.data[k][x] = pow(-1, k+x) * det_matrix(c);
            }
        }
        return d;
    }
    else
    {
        printf("Error: The matrix must be a square matrix.\n");
        return create_matrix(0, 0);
    }
    
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    int rows, cols;
    rows = a.cols;
    cols = a.rows;
    if(rows==cols)
    {
        int i;
        double det = 0;
        for(i =0;i < rows;i++)
        {
            det = det + a.data[i][i];
        }
        return det;
    }
    else
    {
        printf("Error: The matrix must be a square matrix.\n");
    }
    return 0;
}

void print_matrix(Matrix a)
{
    int i,j;
    for (i = 0; i < a.rows; i++)
    {
        for (j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}