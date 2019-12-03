#include "Menu.h"

Menu::Menu(){
    op = -1;
    g = new Grafo;
    g->insertarVertice(5);
    g->insertarVertice(9);
    g->insertarVertice(4);
    g->insertarVertice(15);
    g->insertarVertice(25);
    g->insertarVertice(45);
    g->insertarVertice(10);

    g->insertarArista(5,15);
    g->insertarArista(5,25);
    g->insertarArista(5,5);
    g->insertarArista(5,4);
    g->insertarArista(5,5);

    g->insertarArista(9,25);
    g->insertarArista(9,45);
    g->insertarArista(9,45);

    
}

int Menu::mostrarMenu(){
    int x;
    //std::system("clear");
    cout << endl;
    cout << "-----MENU-----"<< endl;
    cout << "1) Insertar vertice" << endl;
    cout << "2) Insertar arista" << endl;
    cout << "3) Imprimir grafo" << endl;
    cout << "4) Eliminar arista" << endl;
    cout << "5) Eliminar toda arista" << endl;
    cout << "6) Eliminar vertice" << endl;
    cout << "7) Eliminar todo vertice" << endl;
    cout << "0) Salir" << endl;
    cin >> x;

    return x;

}

void Menu::presentarMenu(){
    while (op != 0){

        op = mostrarMenu();
        switch (op){
            case 1:
                cout << "Ingrese el vertice: ";
                cin >> bf;
                g->insertarVertice(bf);
                break;
            case 2:
                cout << "Ingrese el vertice y arista: ";
                cin >> bf >> bf2;
                g->insertarArista(bf,bf2);
                break;
            case 3:
                g->imprimirGrafo();
                break;
            case 4:
                cout << "Ingrese el vertice y arista: ";
                cin >> bf >> bf2;
                g->eliminarArista(bf,bf2);
                break;
            case 5:
                cout << "Ingrese el vertice: ";
                cin >> bf;
                g->eliminarTodaArista(bf);
                break;
            case 6:
                cout << "Ingrese el vertice: ";
                cin >> bf;
                g->eliminarVertice(bf);
                break;
            case 7:
                g->eliminarTodoVertice();
                break;
            
            default:
                break;
        }
    }
}

Menu::~Menu(){
}