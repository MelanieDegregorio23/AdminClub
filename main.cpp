#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

#include "fecha.h"
#include "funcionesgenerales.h"
#include "persona.h"
#include "articulos.h"
#include "reportes.h"
#include "socios.h"
#include "deportes.h"
#include "instructores.h"


int main()
{
    int opc;
    bool estado = true;
       while (estado==true){
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU PRINCIPAL"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1. DEPORTES"<<endl;
        cout<<" 2. MENU DE SOCIOS"<<endl;
        cout<<" 3. MENU DE INSTRUCTORES"<<endl;
        cout<<" 4. ARTICULOS A LA VENTA"<<endl;
        cout<<" 5. REPORTES"<<endl;
        cout<<" 0. SALIR DE MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
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
