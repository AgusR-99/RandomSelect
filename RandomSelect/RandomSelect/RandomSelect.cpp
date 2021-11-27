#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>
#include <Windows.h>
#include "Funcs.h";
int main(){
    srand(time(NULL));
    const int n = 10;
    bool arr[n] = { false };
    std::vector<bool*> ptr;
    for (int i = 0; i < n; i++) {
        ptr.push_back(&arr[i]);
    }
    int contador = 0, intentos = 0;
    std::cout << "Seleccion de elementos aleatorios sin repeticion en un array de "<< n <<" elementos\n";
    system("pause>nul");
    std::cout << "Metodo viejo - Fuerza Bruta\n";
    while (contador < n) {
        int victima = generarVictima(0, n - 1);
        if (metodoViejo(ptr, victima)) contador++;
        intentos++;
        gotoxy(0, 2);
        mostrarSerie(arr, n);
        std::cout << "\nIntentos >>" << intentos;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

    }
    
    std::cout << std::endl;
    resetearSerie(ptr);
    contador = 0, intentos = 0;
    
    std::cout << "Metodo nuevo - Seleccion inteligente\n";
    while (contador < n) {
        int victima = generarVictima(0, ptr.size() - 1);
        *ptr[victima] = true;
        ptr.erase(ptr.begin() + victima);
        intentos++;
        contador++;
        gotoxy(0, 5);
        mostrarSerie(arr, n);
        std::cout << "\nIntentos >>" << intentos;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    
    std::cout << std::endl;

    return 0;
}
