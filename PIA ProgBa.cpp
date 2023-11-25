#include <iostream>
#include <fstream>
#include <ctime>
#include<conio.h>

using namespace std;

struct Item
{
    char nombre[60];
    float precio;
};

struct Order
{
    int venta;
    char nombreVendedor[60];
    Item item;
    float IVA;
    float descuento;
    float total;
    string formaPago;
    string fechaHora;
};

const int MAX_ORDERS = 60;

Order lista[MAX_ORDERS];
int contador = 0;

void addOrder();
void deleteOrder();
void listOrders();
void archive();
void modify();
void back();

int main()
{
    char opc;

    do
    {
        cout << "Restaurante Burguer With Moustache - Menu de opciones:\n";
        cout << "1. Alta de ordenes\n";
        cout << "2. Modificar orden\n";
        cout << "3. Cancelar orden\n";
        cout << "4. Lista de ordenes\n";
        cout << "5. Generar archivo de texto\n";
        cout << "6. Salir\n";
        cout << "Elije una opcion: ";
        cin >> opc;

        switch (opc)
        {
        case '1':
            system("cls");
            addOrder();
            system("pause");
            system("cls");
            break;

        case '2':
            system("cls");
            modify();
            system("pause");
            system("cls");
            break;

        case '3':
            system("cls");
            deleteOrder();
            system("pause");
            system("cls");
            break;

        case '4':
            system("cls");
            listOrders();
            system("pause");
            system("cls");
            break;

        case '5':
            system("cls");
            archive();
            system("pause");
            system("cls");
            break;

        case '6':
            exit(0);
            break;

        default:
            cout << "OPCION NO VALIDA\n";
            break;
        }
    } while (opc != '6');

    return 0;
}

void addOrder()
{
    if (contador < MAX_ORDERS)
    {
        lista[contador].venta = contador + 1;

        cin.ignore();
        cout << "- Ingresa nombre del vendedor:\n";
        cin.getline(lista[contador].nombreVendedor, 60);

        cout << "- Selecciona la forma de pago (Efectivo, Tarjeta, Otro):\n";
        cin >> lista[contador].formaPago;

        Item menu[] = { {"Hamburguesa", 10.00}, {"Papas Fritas", 5.00}, {"Bebida", 2.00} };

        cout << "\n--- Menu de Articulos ---\n";
        for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); ++i)
        {
            cout << i + 1 << ". " << menu[i].nombre << " - $" << menu[i].precio << endl;
        }

        cout << "Seleccione el articulo (1-" << sizeof(menu) / sizeof(menu[0]) << "):\n";
        int opcionArticulo;
        cin >> opcionArticulo;

        if (opcionArticulo >= 1 && opcionArticulo <= sizeof(menu) / sizeof(menu[0]))
        {
            strcpy_s(lista[contador].item.nombre, menu[opcionArticulo - 1].nombre);
            lista[contador].item.precio = menu[opcionArticulo - 1].precio;
        }
        else
        {
            strcpy_s(lista[contador].item.nombre, "Desconocido");
            lista[contador].item.precio = 0.00;
        }

        // Calcular IVA y total
        lista[contador].IVA = lista[contador].item.precio * 0.16;

        // Descuento del 10%
        lista[contador].descuento = lista[contador].item.precio * 0.10;

        // Aplicar descuento al total
        lista[contador].total = lista[contador].item.precio + lista[contador].IVA - lista[contador].descuento;

        // Obtener la fecha y hora actual
        time_t now = time(0);
        tm* ltm = localtime(&now);
        lista[contador].fechaHora = asctime(ltm);

        system("cls");

        // Mostrar el ticket
        cout << "--- Ticket de Venta ---\n";
        cout << "Fecha y Hora: " << lista[contador].fechaHora;
        cout << "Nombre del Vendedor: " << lista[contador].nombreVendedor << endl;
        cout << "Articulo: " << lista[contador].item.nombre << endl;
        cout << "Precio: $" << lista[contador].item.precio << endl;
        cout << "IVA: $" << lista[contador].IVA << endl;
        cout << "Descuento: $" << lista[contador].descuento << endl;
        cout << "Total: $" << lista[contador].total << endl;
        cout << "Forma de Pago: " << lista[contador].formaPago << endl;
        cout << "Gracias por su compra\n\n";

        contador++;
    }
    else
    {
        cout << "No se pueden agregar más ordenes. Capacidad máxima alcanzada.\n";
    }
}

// Resto de las funciones (sin cambios)
// ...
