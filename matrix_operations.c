#include<stdio.h>
#include<malloc.h>
/*Create a Matrix and perform the following operations on it : 1. Exchange the Diagonals 2. Find Determinant 3. Find Rank of the Matrix*/
/* matrix as a structure */
typedef struct matrix{
    int rows;
    int cols;
    int *a[30];
}Matrix;

/* Print everything in it */
/* Matrix again */
/* Creates a Matrix */ 
Matrix * matrix_create(){
    Matrix *A;
    A=malloc(sizeof(Matrix));
    printf("Enter thr rows, cols:");
    scanf("%d %d",&(A->rows),&(A->cols));
    printf("Allocating...\n");
    for(int i=0;i<A->rows;i++){                              //Alocating for every row size of cols
        A->a[i]=malloc(sizeof(int)*(A->cols));
    }
    printf("Allocation done\n");
    return A;
}
Matrix * matrix_create_noInp(int rows, int cols){
    Matrix *A;
    A=malloc(sizeof(Matrix));
/* I know, no allocation handeling! too lazy sorry */
    A->rows=rows;
    A->cols=cols;
    for(int i=0;i<A->rows;i++){                              //Alocating for every row size of cols
        A->a[i]=malloc(sizeof(int)*(A->cols));
    }
    return A;
}
/* Dumps everthing in matrix to user */
void matrix_print(Matrix *A){
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++)
            printf(" %d",A->a[i][j]);
        printf("\n");
    }
}

/* Flushes everything in matrix with 0 */
void matrix_flush(Matrix *A){
    printf("Flushing matrix...\n");
    for(int i=0;i<A->rows;i++)
        for(int j=0;j<A->cols;j++)
            A->a[i][j]=0;
}

/* Inputs everyelement from user */
void matrix_input(Matrix *A){
    for(int i=0;i<A->rows;i++)
        for(int j=0;j<A->cols;j++){
            printf("Enter row:%d cols:%d :",i,j);
            scanf("%d",&(A->a[i][j]));
        }
}

/* Exchange diagonals of a matrix */
void matrix_digonalExchange(Matrix *A){
    int temp;
    if(A->rows==A->cols){
        for(int i=0;i<(A->rows);i++){
            temp=A->a[i][i];
            A->a[i][i]=A->a[i][(A->rows-1)-i];
            A->a[i][(A->rows-1)-i]=temp;
        }
    }
    else
        printf("Not possible to exchange digonals.\n");
}
Matrix * matrix_det(Matrix * A){
    int a,b,c,d,e,f,g;  // lol
    Matrix * ans;
    if(A->rows==2 && A->cols==2){
        c=A->a[0][0]*A->a[1][1];
        c-=((A->a[0][1])*(A->a[1][0]));
        ans=matrix_create_noInp(1,1);
        ans->a[0][0]=c;
        return ans;
    }
    else{
        d=0;
        e=1;
        for(a=0;a<A->cols;a++){ //Traversing through first row in major
            ans=matrix_create_noInp((A->rows)-1,(A->cols)-1);
            for(b=0;b<(A->rows)-1;b++){ //Traversing through rows new matrix
                for(c=0;c<(A->cols)-1;c++){ //Traversing through cols new matrix 
                    ans->a[b][c]=A->a[b+1][(a+1)%A->cols];
                }
            }
            d+=e*matrix_det(ans)->a[0][0];
            e*=-1;
        }
    }

Matrix *Final;
Final->rows=0;
Final->cols=0;
matrix_flush(Final);
Final->a[0][0]=d;
matrix_print(Final);
return Final;

}


void row_exchange(Matrix *A,int m,int n){
	Matrix temp;
	temp=*A;
	printf("flag1\n");
	temp.a[0]=A->a[m];
	printf("flag2\n");
	A->a[m]=A->a[n];
	printf("flag3\n");
	A->a[n]=temp.a[0];
	matrix_print(A);

}

int row_zero(Matrix *A,int n){
	int flag=1;
	for(int i=0;i<A->cols;i++){
		if(A->a[n][i]!=0){
			flag=0;
			break;
		}
	}
	return flag;
}

void rank(Matrix *B){
	float k;
        Matrix temp=*B;
	//printf("%d",temp.rows);
	for(int p=0;p<temp.cols-1;p++){
		for(int i=temp.rows-1;i>=1;i--){
			float num1=temp.a[i][p];
			float num2=temp.a[p][p];
			if(num1==0){
				continue;
			}
			if(num2==0){
				printf("Exchanging rows %d and %d\n",p,temp.rows-1);
				row_exchange(&temp,p,temp.rows-1);
				matrix_print(&temp);
				i++;
				continue;
			}
			if(i==p){
				continue;
			}
			k=num1/num2;
			printf("performing %f divides %f is %f\n",num1,num2,k);
			for(int j=p;j<temp.cols;j++){
				temp.a[i][j]=temp.a[i][j]-k*temp.a[p][j];
			}	
			matrix_print(&temp);
	
		}
	
	}
		
	//matrix_print(&temp);	
}


int main(){
    Matrix *A=matrix_create();
    matrix_flush(A);
    matrix_print(A);
    matrix_input(A);
    matrix_print(A);
    printf("\n");
    //printf("diagonal exchange is\n");
    //matrix_digonalExchange(A);
    matrix_print(A);
    //printf("\nMatrix Determinant\n");
    //A=matrix_det(A);
    //matrix_print(A);
    printf("to find rank\n");
    rank(A);
   
}
