#include <iostream>
#include <string>
using namespace std;

// Ejercicio 1: Encontrar el carácter que más se repite
void ejercicio1() {
    string cadena;
    cout << "Ingrese una cadena: ";
    cin >> cadena;

    int contador[256] = {0}; // Para contar caracteres ASCII
    for (char c : cadena) {
        contador[c]++;
    }

    char caracterMasFrecuente = cadena[0];
    int maxFrecuencia = 0;

    for (int i = 0; i < 256; i++) {
        if (contador[i] > maxFrecuencia) {
            maxFrecuencia = contador[i];
            caracterMasFrecuente = static_cast<char>(i);
        }
    }

    cout << "El carácter que más se repite es: '" << caracterMasFrecuente << "' con " << maxFrecuencia << " ocurrencias." << endl;
}

// Ejercicio 2: Potencia y búsqueda en array
void ejercicio2() {
    int numeros[10];
    cout << "Ingrese 10 números: ";
    for (int i = 0; i < 10; i++) {
        cin >> numeros[i];
    }

    int valor;
    cout << "Ingrese un valor para calcular la potencia: ";
    cin >> valor;

    int potencia = 1;
    for (int i = 0; i < valor; i++) {
        potencia *= 2; // Por ejemplo, calcular 2^valor
    }
    cout << "2 elevado a " << valor << " es: " << potencia << endl;

    // Búsqueda del valor en el array
    cout << "Ingrese un número a buscar en el array: ";
    cin >> valor;

    bool encontrado = false;
    for (int i = 0; i < 10; i++) {
        if (numeros[i] == valor) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << "El número " << valor << " se encuentra en el array." << endl;
    } else {
        cout << "El número " << valor << " NO se encuentra en el array." << endl;
    }
}

// Ejercicio 3: Control de entrada a la fiesta
void ejercicio3() {
    string listaHombres[100];
    string listaMujeres[100];
    bool ingresadoHombres[100] = {false};
    bool ingresadoMujeres[100] = {false};
    string nombre;
    int numHombres = 0, numMujeres = 0;

    cout << "Ingrese nombres para la lista de hombres (ingresar 'fin' para terminar):" << endl;
    while (true) {
        cin >> nombre;
        if (nombre == "fin") break;
        listaHombres[numHombres++] = nombre;
    }

    cout << "Ingrese nombres para la lista de mujeres (ingresar 'fin' para terminar):" << endl;
    while (true) {
        cin >> nombre;
        if (nombre == "fin") break;
        listaMujeres[numMujeres++] = nombre;
    }

    while (true) {
        cout << "Ingrese el nombre para verificar ingreso (o 'salir' para terminar): ";
        cin >> nombre;
        if (nombre == "salir") break;

        bool encontrado = false;
        for (int i = 0; i < numHombres; i++) {
            if (listaHombres[i] == nombre) {
                encontrado = true;
                if (!ingresadoHombres[i]) {
                    ingresadoHombres[i] = true; // Marca como ingresado
                    cout << nombre << " ha ingresado sin pagar." << endl;
                } else {
                    cout << nombre << " ya ingresó, debe pagar." << endl;
                }
                break;
            }
        }

        if (!encontrado) {
            for (int i = 0; i < numMujeres; i++) {
                if (listaMujeres[i] == nombre) {
                    encontrado = true;
                    if (!ingresadoMujeres[i]) {
                        ingresadoMujeres[i] = true; // Marca como ingresado
                        cout << nombre << " ha ingresado sin pagar." << endl;
                    } else {
                        cout << nombre << " ya ingresó, debe pagar." << endl;
                    }
                    break;
                }
            }
        }

        if (!encontrado) {
            cout << "Nombre no reconocido." << endl;
        }
    }
}

// Ejercicio 4: Suma de matrices
void ejercicio4() {
    int matrizA[3][3], matrizB[3][3], matrizSuma[3][3];

    cout << "Ingrese los datos de la matriz A: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matrizA[i][j];
        }
    }

    cout << endl;

    cout << "Ingrese los datos de la matriz B: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matrizB[i][j];
        }
    }

    // Sumar las matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizSuma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    // Mostrar la matriz resultante
    cout << "\nLa matriz suma es: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrizSuma[i][j] << " ";
        }
        cout << endl;
    }
}

// Función principal
int main() {
    int opcion;

    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Encontrar el carácter que más se repite." << endl;
        cout << "2. Calcular potencia y buscar en array." << endl;
        cout << "3. Control de entrada a la fiesta." << endl;
        cout << "4. Sumar matrices." << endl;
        cout << "0. Salir." << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 4:
                ejercicio4();
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}
