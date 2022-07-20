#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
#include "articulos.h"
#include "ventas.h"

///DECLARACIONES

void menuReportes();
void ArtMes();
void mostrarArt(int *v,int tam);
void CantSociosPorD();
void importePorVentas();
int contarS(int cod);
void informarMayorS();
void informarMenorS();


///DESARROLLO


void informarMenorS(){
    deporte aux;
    int cantS=0, pos=0;
    char dep[30];
    while(aux.LeerEnDisco(pos)){
            int x = contarS(aux.getCodDep());
        if(x<cantS || pos==0 ){
            cantS = x;
            strcpy(dep, aux.getDescripcion());
        }
        pos++;
    }
      const int ANCHO_MENU = 50;
      const int ALTO_MENU = 8;
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+20,POSMENUY+1);
    cout<<"REPORTES"<<endl;
    locate(POSMENUX+6,POSMENUY+4);
    cout<<"EL DEPORTE CON MENOR CANTIDAD DE SOCIOS ES: "<<endl;
    locate(POSMENUX+6,POSMENUY+5);
    cout<<dep;
    cout<<endl;
}


void informarMayorS(){
    deporte aux;
    int cantS =0, pos=0;
    char dep[30];
    while(aux.LeerEnDisco(pos)){
        int x = contarS(aux.getCodDep());
        if(x>cantS){
            cantS = x;
            strcpy(dep, aux.getDescripcion());
        }
        pos++;
    }
    const int ANCHO_MENU = 50;
      const int ALTO_MENU = 8;
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+20,POSMENUY+1);
      cout<<"REPORTES"<<endl;
    locate(POSMENUX+6,POSMENUY+4);
    cout<<"  EL DEPORTE CON MAYOR CANTIDAD DE SOCIOS ES "<<endl;
    locate(POSMENUX+6,POSMENUY+5);
    cout<<dep;
}

void importePorVentas(){
    const int ANCHO_MENU = 50;
      const int ALTO_MENU = 8;
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+10,POSMENUY+1);
    cout<<"SE REGISTRAN VENTAS A PARTIR DEL 2018 "<<endl;
    cout<<endl<<endl;
     int n[5]={0}, pos=0;
     Venta aux;
     while(aux.leerEnDisco(pos)){
        if(n[aux.getFechadeVenta().getAnio()-2018]+= aux.getImporte());
        pos++;
 }
    for(int i=0; i<5 ; i++){
        if(n[i]>0){
            locate(POSMENUX+10,POSMENUY+4);
            cout<<"IMPORTE ACUMULADO EN EL  "<<i+2018<<" :"<<endl;
            locate(POSMENUX+10,POSMENUY+5);
            cout<<n[i]<<endl;
        }
    }

}

int contarS(int cod){
    socio reg;
    int pos =0,cant=0;
    while(reg.LeerEnDisco(pos)){
        if(reg.getIdDeporte()==cod){
            cant++;
        }
        pos++;
    }
    return cant;
}


void CantSociosPorD(){
        int cant, pos =0;
        deporte aux;
      const int ANCHO_MENU = 50;
      const int ALTO_MENU = 8;
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+10,POSMENUY+1);
        cout<<"CANTIDAD DE SOCIOS POR DEPORTE "<<endl;
        cout<<endl;

        while(aux.LeerEnDisco(pos)){
            int id = aux.getCodDep();
            int cant = contarS(id);
            if(cant>0){
                locate(POSMENUX+10,POSMENUY+4);
                cout<<"CANTIDAD DE SOCIOS EN "<<aux.getDescripcion()<<": "<<endl;
                locate(POSMENUX+10,POSMENUY+5);
                cout<<cant<<endl;
            }
            pos++;
    }
    }




void mostrarArt(int *v,int tam){
int i;
      const int ANCHO_MENU = 60;
      const int ALTO_MENU = 15;

    cout<<"LA CANTIDAD DE ARTICULOS VENDIDOS POR MES ES: "<<endl;
    for (i=0; i<tam;i++){
        if(v[i]>0){
            cout<<"MES : "<<i+1<<"            CANTIDAD VENDIDA: "<<v[i]<<endl;
        }

}
}
void ArtMes(){
Venta aux;
Fecha obj;
int pos=0;
int v[12]={0};

    while(aux.leerEnDisco(pos)==1){
        v[aux.getFechadeVenta().getMes()-1]+=aux.getCant();

        pos++;
    }

      mostrarArt(v,12);




}


void menuReportes(){
    system("cls");
    const int ANCHO_MENU = 64;
    const int ALTO_MENU = 18;
    bool estado = true;
     int key, opc, cursorX, cursorY;
       while (estado==true){
       cursorX=POSMENUX+9;
       cursorY=POSMENUY + 4;
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      opc=0;
      setColor(LETRA);
      setBackgroundColor(FONDO);
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+24,POSMENUY+1);
        cout<<" MENU REPORTES"<<endl;
        locate(POSMENUX+12,POSMENUY+4);
        cout<<" CANTIDAD DE ARTICULOS VENDIDOS POR MES."<<endl;
        locate(POSMENUX+12,POSMENUY+5);
        cout<<" IMPORTE ANUAL ACUMULADO POR VENTAS."<<endl;
        locate(POSMENUX+12,POSMENUY+6);
        cout<<" IMPORTE ACUMULADO POR MES SEGUN EL DEPORTE."<<endl;
        locate(POSMENUX+12,POSMENUY+7);
        cout<<" CANTIDAD DE SOCIOS POR DEPORTE."<<endl;
        locate(POSMENUX+12,POSMENUY+8);
        cout<<" INFORMAR EL DEPORTE CON MAYOR NUMERO DE SOCIOS."<<endl;
        locate(POSMENUX+12,POSMENUY+9);
        cout<<" INFORMAR EL DEPORTE CON MENOR NUMERO DE SOCIOS."<<endl;
        locate(POSMENUX+12,POSMENUY+10);
        cout<<" VOLVER AL MENU PRINCIPAL"<<endl;
        locate(POSMENUX+8,POSMENUY+11);

        hidecursor();
        locate(cursorX,cursorY);
        cout<<">>";
        key = getkey();
        while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 6){
                opc--;
            }else{
                opc=0;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 4;
        }else{
            cursorY = POSMENUY + 4;
        }
        locate(cursorX,cursorY);
        cout<<">>";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
        switch(opc){
    case 0:system("cls");
            ArtMes();



            system("pause");
        break;
    case 1:
        system("cls");
        importePorVentas();
        locate(POSMENUX+6,POSMENUY+7);
        system("pause");
        break;
    case 2:
        ///a desarrollar
        break;
    case 3:
        system("cls");
        CantSociosPorD();
        locate(POSMENUX+6,POSMENUY+7);
        system("pause");
        break;
    case 4:
        system("cls");
        informarMayorS();
        locate(POSMENUX+6,POSMENUY+7);
        system("pause");
        break;
    case 5:
        system("cls");
        informarMenorS();
        locate(POSMENUX+6,POSMENUY+7);
        system("pause");
        break;
    case 6: estado=false;
        break;
        }

       }
}

#endif // REPORTES_H_INCLUDED
