#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

#include "configuracion.h"
#include "fecha.h"
#include "funcionesgenerales.h"
#include "persona.h"
#include "articulos.h"
#include "reportes.h"
#include "socios.h"
#include "deportes.h"
#include "instructores.h"
#include "pagosMes.h"
#include "ventas.h"



int main()
{
    int opc;
    bool estado = true;
       while (estado==true){
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU PRINCIPAL"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1. DEPORTES"<<endl;
        cout<<" 2. SOCIOS"<<endl;
        cout<<" 3. INSTRUCTORES"<<endl;
        cout<<" 4. ARTICULOS"<<endl;
        cout<<" 5. REGISTRAR PAGO"<<endl;
        cout<<" 6. VENTAS"<<endl;
        cout<<" 7. REPORTES"<<endl;
        cout<<" 8. CONFIGURACION"<<endl;
        cout<<" 9. SALIR DE MENU PRINCIPAL"<<endl;
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

    case 5:menuPagoMes();

    case 6:
        MenuVentas();
        break;
    case 7:
        menuReportes();
        break;
    case 8:menuConfiguracion();

        break;


    case 0: estado=false;
        break;
        }

       }



    return 0;
}
