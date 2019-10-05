/*
*A01379951
Ejercicio 4. LAS PAREJAS ESTABLES

Supongamos que tenemos n hombres y n mujeres y dos matrices M y H que contienen las preferencias de los unos por los otros. 
M�s concretamente, la fila M[i,�] es una ordenaci�n (de mayor a menor) de las mujeres seg�n las preferencias del i-�simo hombre y, 
an�logamente, la fila H[i,�] es una ordenaci�n (de mayor a menor) de los hombres seg�n las preferencias de la i-�sima mujer.

Dise�e un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y mujeres tal que todas las parejas formadas sean estables. 
Una pareja (h,m) es estable si no se da ninguna de estas dos circunstancias:

Existe una mujer m� (que forma la pareja (h�,m�)) tal que el hombre h la prefiere sobre la mujer m y adem�s la mujer m� tambi�n prefiere a h sobre h�. 
Existe un hombre h� (que forma la pareja (h�,m�)) tal que la mujer m lo prefiere sobre el hombre h y adem�s el hombre h� tambi�n prefiere a m sobre la mujer m�. 

* complejidad: O(n^2)
* Tecnica: Backtracking
*/

#include<iostream>

const int nPersonas = 4;
bool exito;

int x[nPersonas];
int y[nPersonas];

bool disponible[nPersonas] = {true};

bool estable (int h, int m, int p);
void parejas (int hombre, bool exito, int n);

using namespace std;

int preferenciasMujeres[nPersonas][nPersonas] = {{3,1,2,0},{3,2,0,1},{1,3,0,2},{2,1,3,0}};
int preferenciasHombres[nPersonas][nPersonas] = {{1,3,2,0},{0,2,3,1},{1,3,2,0},{2,1,3,0}};

int ordenMujeres[nPersonas][nPersonas] = {{3,0,2,1},{0,3,1,2},{3,0,2,1},{3,1,0,2}};
int ordenHombres[nPersonas][nPersonas] = {{3,1,2,0},{2,3,1,0},{2,0,3,1},{3,1,0,2}};

bool estable (int h, int m, int p)
{
    int mejorMujer, mejorHombre, i, limite;
    bool s = true;
    i = 0;

    while (i < p && s)
    {
        mejorMujer = preferenciasMujeres[h][i];
        if (disponible[mejorMujer] == false)
        {
            if (ordenMujeres[mejorMujer][h] > ordenMujeres[mejorMujer][y[mejorMujer]])
            {
                s = true;
            } else {
                s = false;
            }
        }
        i++;
    }

    i =0;
    limite = preferenciasHombres[m][h];
    while ((i < limite) && s)
    {
        mejorHombre = preferenciasHombres[m][i];
        if (mejorHombre < h)
        {
            if (ordenHombres[mejorHombre][m] > ordenHombres[mejorHombre][x[mejorHombre]])
            {
                s= true;
            } else {
                s = false;
            }
        }
        i++;
    }
    return s;
}

void parejas (int hombre, bool exito, int n)
{
    int mujer, prefiere;
    prefiere = 0;
    while (prefiere < n && exito != true)
    {
        mujer = preferenciasMujeres[hombre][prefiere];
        if (disponible[mujer] == true && estable(hombre,mujer,prefiere) == true)
        {
            x[hombre] = mujer;
            y[mujer] = hombre;
            disponible[mujer] = false;
            if (hombre < n)
            {
                parejas(hombre + 1, exito, n);
                if (!exito)
                    disponible[mujer] = true;
            } else {
                exito = true;
            }
        }
        prefiere++;
    }
}

int main()
{

    for(int i = 0; i < nPersonas; i++)
        disponible[i] = true;

    parejas(0, exito, nPersonas);


    for (int i = 0; i < nPersonas; i++)
    {
        cout << "La pareja del hombre  " << i << " es la mujer  " << x[i] << endl;
        cout << "La pareja de la mujer " << i << " es el hombre " << y[i] << endl;
    }



    return 0;
}
