/*
* A01379951
Ejercicio 3. LA SUBSECUENCIA COM�N M�XIMA

Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia de X (siendo k = m) si existe una 
secuencia creciente {i1 i2 ... ik} de �ndices de X tales que para todo j = 1, 2, ..., k tenemos xij = zj.
Dadas dos secuencias X e Y, se dice que Z es una subsecuencia com�n de X e Y si es subsecuencia de X y subsecuencia de Y. 
Dise�e un algoritmo que permita determinar la subsecuencia de longitud m�xima com�n a dos secuencias.


*Complejidad O(n^2)
*Tecnica: Algoritmo Avido
*/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

int aux[100][100];
int tmp[100][100];

void LCS(char * x, char * y, int sizeX, int sizeY);
void imprimir(char * x, int i, int j);


int main() {

    const int sizeX = 11;
    const int sizeY = 7;
    char xchar[sizeX] = {'1','q','w','e','r','t','y','u','3','o','9'};
    char ychar[sizeY] = {'2','q','w','e','r','t','y'};

    cout << "Complejidad O(n^2)" << endl << endl;

    LCS(xchar, ychar, sizeX, sizeY);
    cout << "Resultado: ";
    imprimir(xchar, sizeX-1, sizeY-1);
    cout << endl;

    return 0;
}

void LCS(char * X, char * Y, int sizeX, int sizeY)
{
    int m,n;
    m = sizeX;
    n = sizeY;

    for(int i = 1; i <= m; i++)
         tmp[i][0] = 0;

    for(int j = 0; j <= n; j++)
        tmp[0][j] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j])
            {
                tmp[i][j] = tmp[i-1][j-1] + 1;
                aux[i][j] = 1;
            } else {
                if (tmp[i-1][j] >= tmp[i][j-1])
                {
                    tmp[i][j] = tmp[i-1][j];
                    aux[i][j] = 2;
                } else {
                    tmp[i][j] = tmp[i][j-1];
                    aux[i][j] = 3;
                }
            }
        }
    }
}

void imprimir(char * x, int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (aux[i][j] == 1)
    {
        imprimir(x, i - 1, j - 1);
        cout << x[i];
    } else {
        if (aux[i][j] == 2)
            imprimir(x, i - 1, j);
        else
            imprimir(x, i, j -1);
    }
}
