XXXXXXXX#include <iostream>
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

    // Clase que representa un pedido 
class Pedido {
private:
    vector<Producto*> productosComprados;
    float total;

public:
    // Constructor que recibe los productos y calcula el total
    Pedido(vector<Producto*> productos) {
        this->productosComprados = productos;
        total = 0;
        for (Producto* p : productos) {
            total += p->getPrecio();
        }
    }

    // Devuelve el total del pedido
    float getTotal() {
        return total;
    }

    // Muestra la factura detallada del pedido
    void mostrarFactura() {
        cout << "\n🧾 FACTURA:\n";
        for (Producto* p : productosComprados) {
            cout << "- " << p->getNombre() << " $" << p->getPrecio() << endl;
        }
        cout << "Total a pagar: $" << total << endl;
};

int main() {
    // Crear productos
    ProductoFisico p1("Mouse", 3500, "P001", 5);
    ProductoFisico p2("Teclado", 6000, "P002", 3);
    ProductoDigital p3("Curso Online", 10000, "D001");

    // Crear cliente
    Cliente cliente1("Camila", 101);

    // Crear carrito y agregar productos
    Carrito carrito;
    carrito.agregarProducto(&p1);
    carrito.agregarProducto(&p2);
    carrito.agregarProducto(&p3);

    // Mostrar carrito y total
    carrito.mostrarCarrito();
    cout << "Total del carrito: $" << carrito.calcularTotal() << endl;

    // Confirmar pedido y mostrar factura
    Pedido pedido(carrito.getProductos());
    pedido.mostrarFactura();

    // Agregar historial de compras al cliente
    cliente1.agregarCompra("Pedido por $" + to_string(pedido.getTotal()));
    cliente1.mostrarHistorial();

    return 0;
}