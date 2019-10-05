#include <iostream>

//A01379951
/*
Ejercicio 1. EL CAMIONERO CON PRISA

Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un camión que le permite, 
con el tanque de gasolina lleno, recorrer n kilómetros sin parar. El camionero dispone de un mapa de 
carreteras que le indica las distancias entre las gasolineras que hay en su ruta. Como va con prisa, 
el camionero desea detenerse a abastecer gasolina el menor número de veces posible.

*/
//Complejidad O(n) porque recorre el numero de gasolineras que hay en en camino en el ciclo while
//tecnica: avido


int cargarGas(int kmRecorridos, int n, int *gas, int gasolinerias, int distancia);

int cargarGas(int kmRecorridos, int n, int *gas, int gasolinerias, int distancia){
	
	int i = 0;
	kmRecorridos = n;
	int tanques = (distancia/n);
  
	std::cout <<"Distancia a Acapulto: " << distancia << std::endl;
	std::cout <<"Rendimiento por tanque lleno: " << n << std::endl;
	std::cout <<"Paradas necesarias para cargar gasolina: " << tanques << std::endl;
	std::cout <<"\n" << std::endl;
	
  	while (gasolinerias > i){
    	if( n <= gas[i]){
    		std::cout << "Detente en la gasolineria del kilometro " << gas[i] << std::endl;
      		n = n + kmRecorridos;
      		tanques--;      	
    	}

    	if (tanques==0){
    		std::cout <<"\nNo hace falta cargar mas gasolina" << std::endl;
			return 0;
			}
       
    	i++;

  }
}
  
  int main(){

	int distancia = 1000; //distancia a acapulco
	int n = 300; //rendimiento en km por tanque
	int numeroDeGasolinerias = 8;
	
	//km en donde se encuentran las gasolineras
	int gasolinerias[numeroDeGasolinerias] = {10, 50, 120, 300, 350, 600, 800, 900};
	cargarGas(0, n, gasolinerias, numeroDeGasolinerias,distancia);
	
	return 0;
}


