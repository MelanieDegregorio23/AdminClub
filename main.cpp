#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#include "articulos.h"
#include "reportes.h"
#include "socios.h"
#include "deportes.h"
#include "instructores.h"
#include "funcionesgenerales.h"

int main()
{
    int opc;
    bool estado = true;
       while (estado==true){
        cout<<"1. DEPORTES"<<endl;
        cout<<"2. MENU DE SOCIOS"<<endl;
        cout<<"3. MENU DE INSTRUCTORES"<<endl;
        cout<<"4. ARTICULOS A LA VENTA"<<endl;
        cout<<"5. REPORTES"<<endl;
        cout<<"0. SALIR DE MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<"INGRESE LA OPCION DESEADA: "<<endl;
        cin>>opc;
        switch(opc){
    case 1:
        menuDeportes();

        break;
    case 2:
        menuSocios();
        break;

    case 3:
        menuInstructores();
        break;
    case 4:
        menuArticulos();
        break;
    case 5:
        menuReportes();
        break;

    case 0: estado=false;
        break;
        }

       }



    return 0;
}
