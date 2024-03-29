#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include "rlutil.h"


using namespace std;
using namespace rlutil;
const int ANCHO_MENU = 40;
const int ALTO_MENU = 35;
const int POSMENUX = 33;
const int POSMENUY = 3;
const int COLOR_PANTALLA = BLACK;
const int LETRA = LIGHTCYAN;
const int FONDO = BLACK;

#include "utilidades.h"
#include "funciones.h"
#include "fecha.h"
#include "funcionesgenerales.h"
#include "persona.h"
#include "articulos.h"
#include "socios.h"
#include "deportes.h"
#include "instructores.h"
#include "pagosMes.h"
#include "ventas.h"
#include "reportes.h"
#include "configuracion.h"



int main()
{
    int opcionesMenu=-2;
    int Tecla;

    bool estado = true;
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 20;
    srand(time(NULL));
    int key, opc, cursorX, cursorY;
    while (estado==true)
    {
        cursorX=POSMENUX+13;
        cursorY=POSMENUY + 5;
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        opc=-2;
        setColor(LETRA);
        setBackgroundColor(FONDO);
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+17,POSMENUY+1);
        cout<<"MENU PRINCIPAL"<<endl;
        locate(POSMENUX+17,POSMENUY+5);
        cout<<" DEPORTES."<<endl;
        locate(POSMENUX+17,POSMENUY+6);
        cout<<" SOCIO."<<endl;
        locate(POSMENUX+17,POSMENUY+7);
        cout<<" INSTRUCTORES."<<endl;
        locate(POSMENUX+17,POSMENUY+8);
        cout<<" ARTICULOS."<<endl;
        locate(POSMENUX+17,POSMENUY+9);
        cout<<" REGISTRAR PAGOS."<<endl;
        locate(POSMENUX+17,POSMENUY+10);
        cout<<" VENTAS."<<endl;
        locate(POSMENUX+17,POSMENUY+11);
        cout<<" REPORTES."<<endl;
        locate(POSMENUX+17,POSMENUY+12);
        cout<<" CONFIGURACION."<<endl;
        locate(POSMENUX+17,POSMENUY+13);
        cout<<" FINALIZAR PROGRAMA."<<endl;
        locate(POSMENUX+18,POSMENUY+13);
        hidecursor();
        locate(cursorX,cursorY);
        cout<<">>";
        key = getkey();
        while(key != KEY_ENTER)
        {
            locate(cursorX,cursorY);
            cout<<" ";
            cout<<" ";
            switch(key)
            {
            case KEY_DOWN:
                if(opc < 6)
                {
                    opc++;
                }
                else
                {
                    opc=-2;
                }
                break;
            case KEY_UP:
                if(opc > 6)
                {
                    opc--;
                }
                else
                {
                    opc=-2;
                }
                break;
            }
            if(opc != 0)
            {
                cursorY = opc + POSMENUY + 7;
            }
            else
            {
                cursorY = POSMENUY + 7;
            }
            locate(cursorX,cursorY);
            cout<<">>";
            key = getkey();
        }
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        showcursor();

        switch(opc)
        {
        case -2:
            menuDeportes();

            break;
        case -1:
            menuSocios();
            break;

        case 0:
            menuInstructores();
            break;
        case 1:
            menuArticulos();
            break;

        case 2:
            menuPagoMes();

            break;

        case 3:
            MenuVentas();
            break;
        case 4:
            menuReportes();
            break;
        case 5:
            menuConfiguracion();

            break;


        case 6:
            estado=false;
            break;
        }



    }

    return 0;
}
