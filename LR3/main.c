#include<stdio.h>
#include<conio.h>
#include<math.h>

#define MAX_N 10 // Maximum dimension for the matrix

int N, M; // Matrix dimension
double a[MAX_N][MAX_N];
void gauss(void);
void sprositMatr(void);
void otvet(void);

int main()
{
    sprositMatr();
    gauss();
    otvet();
    scanf("%d");
}

void delimStr(int s,double lam)
{
    if (lam == 0.0)
        return;
    for (int j = 0; j < M; j++)
        a[s][j] /= lam;
}

void vichestStr(int s1,int s2,double lam)
{
    for(int j=0;j<M;j++)
        a[s1][j]-=a[s2][j]*lam;
}
void meniaemStr(int s1,int s2)
{
    double temp;
    for(int j=0;j<M;j++)
    {
        temp=a[s1][j];
        a[s1][j]=a[s2][j];
        a[s2][j]=temp;
    }
}
int nomerStrSNenulElem(int ns, int *n, int *m)
{
    for(int i=ns; i<N; i++) {
        for(int j=ns;j<M;j++)
            if(a[i][j]!=0)
            {
                *n = i;
                *m = j;
                return i;
            }
    }
    return N;
}
void zanulimStlb(int ns)
{
    double lam; int nst;
    int n, m;
    if(a[ns][ns]==0)
    {
        nst=nomerStrSNenulElem(ns, &n, &m);
        if(nst==N)
        {
            return;
        }
        meniaemStr(ns,nst);
    }
    for(int i=0;i<N;i++)
    {
        if(i!=ns)
        {
            lam=a[i][m]/a[ns][m];
            vichestStr(i,ns,lam);
        }
    }
}

void sprositMatr(void)
{
    FILE *file = fopen("matrix.txt", "r"); // Open the file for reading
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    if (fscanf(file, "%d %d", &N, &M) != 2)
    {
        printf("Error reading matrix dimension from the file.\n");
        fclose(file);
        return;
    }

    if (N <= 0 || N > MAX_N)
    {
        printf("Invalid matrix dimension in the file.\n");
        fclose(file);
        return;
    }

    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (fscanf(file, "%lf", &a[i][j]) != 1)
            {
                printf("Error reading from the file.\n");
                fclose(file);
                return;
            }
        }
    }
    otvet();
    fclose(file); // Close the file
}

void otvet(void)
{
    int i,j;
    printf("\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++) printf("%6.2f",a[i][j]);
        printf("\n");
    }
    int rank = 0;
    for (i=0; i<N; i++) {
        for (j=0;j<M;j++) {
            if (a[i][j] != 0.0) {
                rank++;
                break;
            }
        }
    }
    printf("matrix rank is %d", rank);
}

void gauss(void)
{
    for(int i=0;i<N;i++)
        zanulimStlb(i);
    for(int i=0;i<N;i++)
        delimStr(i,a[i][i > M ? M : i]);
}