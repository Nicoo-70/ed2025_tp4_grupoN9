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
// Clase ProductoFisico hereda de Producto
class ProductoFisico : public Producto {
public:
    ProductoFisico(string nombre, float precio, string codigo, int stock)
        : Producto(nombre, precio, codigo, stock) {}
};


// Clase ProductoDigital hereda de Producto
class ProductoDigital : public Producto {
public:
    ProductoDigital(string nombre, float precio, string codigo)
        : Producto(nombre, precio, codigo, 9999) {}
};

//clase cliente 
class Cliente {
private:
    string nombre;     
    int id;                
    vector<string> historial;

public:

    Cliente(string nombre, int id) {
        this->nombre = nombre;
        this->id = id;
    }

    // Método para agregar un detalle de compra al historial
    void agregarCompra(string detalle) {
        historial.push_back(detalle);
    }

    // Mostrar historial de compras del cliente
    void mostrarHistorial() {
        cout << "Historial de compras de " << nombre << ":" << endl;
        for (string compra : historial) {
            cout << "- " << compra << endl;
        }
    }
};

// Clase que representa el carrito de compras
class Carrito {
    private:
        vector<Producto*> productos; // Lista de punteros a productos agregados
    
    public:
        // Agrega un producto al carrito si hay stock disponible
        void agregarProducto(Producto* p) {
            if (p->getStock() > 0) {
                productos.push_back(p);
                p->setStock(p->getStock() - 1);
                cout << "Producto agregado al carrito: " << p->getNombre() << endl;
            } else {
                cout << "No hay stock disponible para " << p->getNombre() << endl;
            }
        }
    
        // Contenido del carrito
        void mostrarCarrito() {
            cout << "\n Carrito:\n";
            for (Producto* p : productos) {
                p->mostrarProducto();
            }
        }
        float calcularTotal() {
            float total = 0;
            for (Producto* p : productos) {
                total += p->getPrecio();
            }
            return total;
        }
        vector<Producto*> getProductos() {
            return productos;
        }
    };