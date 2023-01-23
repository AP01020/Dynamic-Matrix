//21BCA046 OM PATEL 
/* 
uses some of the Universal variable such as Size with 10 as a array Index.
*/
#include<stdio.h>
#include<math.h>//for using pow set of inbuilt command 
#define   SIZE  10 
/* 
function for the Inverse of Matrix This are Sub-> Sub Program Files
*/
float determinant(float [][25], float);
void cofactor(float [][25], float);
void transpose(float [][25], float [][25], float);
//----------------------------------------------------------------------------------
/* function for the main Switch statement*/
void matrix3();
void matrixs();
void matrix2();
void multimat();
void design();
// Main file begins
void main()
{
	int patel;
	
	
	printf("\n--------------------------------------------------------------------------------------");
	printf("\n \t\t\t\tMATRIX");
	printf("\n--------------------------------------------------------------------------------------");
	printf("\nSelect 1 = INVERSE OF MATRIX ");
	printf("\nSelect 2 = BASIC MATRIX ");			
	printf("\nSelect 3 = DETERMINANT OF MATRIX ");
	printf("\nSelect 4 = MULTIPLICATION OF MATRIX-----INCLUDES BOTH MATRIXES");
	printf("\nEnter your Choice : ");
	scanf("%d",&patel);
	switch(patel)
	{
	
		case 1:
			matrixs();
			printf("\n");
			design();
			printf("\t OMPATEL");
			break;
		case 2:
			matrix2();
			printf("\n");
			design();
			printf("\t OMPATEL");
			break;
		
		
		case 3:
			matrix3();
			printf("\n");
			design();
			printf("\t OMPATEL");
			break;
		case 4:
			multimat();
			printf("\n");
			design();
			printf("\t OMPATEL");
			break;
		default:
			printf("\n\aINVALID INPUT.");
			printf("\n");
			design();
			printf("\t OMPATEL");
	}
}
void matrix3()
{
		float a[SIZE][SIZE], x[SIZE], ratio, det=1;
	 int i,j,k,n;

	 /* Inputs */
	 /* 1. Reading number of unknowns */
	 printf("\n The element entered is to print matrix will print the matrix into M X M format.");
	 printf("\nEnter Order of Matrix: ");
	 scanf("%d", &n);

	 /* 2. Reading Matrix */
	 printf("\nEnter Coefficients of Matrix: \n");
	 for(i=0;i< n;i++)
	 {
		  for(j=0;j< n;j++)
		  {
			   printf("a[%d][%d]=",i,j);
			   scanf("%f", &a[i][j]);
		  }
	 }
	 for(i=0;i< n;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   
		  }
		  for(j=i+1;j< n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=0;k< n;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 /* Finding determinant by multiplying
	 elements in principal diagonal elements */
	 for(i=0;i< n;i++)
     {
         det = det * a[i][i];
     }

	 printf("\n\nDeterminant of given matrix is: %0.1f", det);

}
void matrixs()
{
	float a[25][25], k, d;
  int i, j;
  printf("\n--------------------------------------------------------------------------------------");
				printf("\n \t\t\t\tINVERSE OF MATRIX");
				printf("\n--------------------------------------------------------------------------------------\n");
  printf("Enter the order of the Matrix : ");
  scanf("%f", &k);
  printf("Enter the elements of %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &a[i][j]);
        }
    }
  d = determinant(a, k);
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   cofactor(a, k);
}
 
/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 
void cofactor(float num[25][25], float f)
{
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}
/*Finding transpose of matrix*/ 
void transpose(float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25], inverse[25][25], d;
 
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");
 
   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
     }	
}
	

void matrix2()
{
	int i, j, m, n;
    int matrix[10][20];
	int pom;
	
		printf("\n--------------------------------------------------------------------------------------");
		printf("\n \t\t\tBASIC MATRIX");
		printf("\n--------------------------------------------------------------------------------------");
		
		
		
		
			printf("\nEnter number of rows : ");
    scanf("%d", &m);
    printf("\nEnter number of columns : ");
    scanf("%d", &n);

    /* Input data in matrix */
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter data in [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    /* Display the matrix */
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

  	
}


void multimat()
{
	int a[10][10],b[10][10],mul[10][10],r,c,i,j,k;  
	printf("\n--------------------------------------------------------------------------------------");
		printf("\n \t\t\tMULTIPLICATION OF MATRIX");
		printf("\n--------------------------------------------------------------------------------------");   
printf("\nEnter the number of row=");    
scanf("%d",&r);    
printf("enter the number of column=");    
scanf("%d",&c);    
printf("enter the first matrix element=\n");    
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
scanf("%d",&a[i][j]);    
}    
}    
printf("enter the second matrix element=\n");    
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
scanf("%d",&b[i][j]);    
}    
}    
    
printf("multiply of the matrix=\n");    
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
mul[i][j]=0;    
for(k=0;k<c;k++)    
{    
mul[i][j]+=a[i][k]*b[k][j];    
}    
}    
}    
//for printing result    
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
printf("%d\t",mul[i][j]);    
}    
printf("\n");    
}    
	
	
	
	
	
	
}

void design()
{
	int i,j;
	printf("----------------------------------------------------------------------");
	for(i=0;i<5;i++)
	{
		for(j=0;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
		}	
			for(i=4;i>0;i--)	
	{
		for(j=1;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("---------------------------------------------------------------------->>");
}
