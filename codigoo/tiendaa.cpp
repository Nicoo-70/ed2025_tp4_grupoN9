#include <iostream>
#include <string>
using namespace std;

// Clase base Producto
class Producto {
private:
    string nombre;
    float precio;
    string codigo;
    int stock;
public:
    Producto(string nombre, float precio, string codigo, int stock) {
        this->nombre = nombre;
        this->precio = precio;
        this->codigo = codigo;
        this->stock = stock;
    }
    // Getters
    string getNombre() { return nombre; }
    float getPrecio() { return precio; }
    string getCodigo() { return codigo; }
    int getStock() { return stock; }

    // Setter
    void setStock(int nuevoStock) {
        this->stock = nuevoStock;
    }
    void mostrarProducto() {
        cout << "Producto: " << nombre
             << " | Precio: $" << precio
             << " | Stock: " << stock << endl;
    }
};
