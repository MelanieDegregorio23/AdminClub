#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
#include "articulos.h"
#include "ventas.h"

///DECLARACIONES

void menuReportes();
void ArtMes();
void mostrarArt(int *v,int tam);
void CantSociosPorD();
void cargarVec();

///DESARROLLO
/*void cargarVec(){
    socio
}*/

void CantSociosPorD(){
    int cant, pos =0;
    deporte aux;
    while(aux.LeerEnDisco(pos)){

        pos++;
    }
}

void mostrarArt(int *v,int tam){
int i;

    cout<<"LA CANTIDAD DE ARTICULOS VENDIDOS POR MES ES: "<<endl;
    for (i=0; i<tam;i++){
        if(v[i]>0){
        cout<<"MES: "<<i+1<<" CANTIDAD VENDIDA: "<<v[i]<<endl;
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
    int opc;
    bool estado = true;
       while (estado==true){
            system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU REPORTES"<<endl;
        cout<<" ________________________"<<endl<<endl;


        cout<<"1. CANTIDAD DE ARTICULOS VENDIDOS POR MES."<<endl;
        cout<<"2. IMPORTE TOTAL ACUMULADO POR ENIO POR VENTAS."<<endl;
        cout<<"3. IMPORTE ACUMULADO POR MES SEGUN EL DEPORTE."<<endl;
        cout<<"4. CANTIDAD DE SOCIOS POR DEPORTE."<<endl;
        cout<<"5. INFORMAR EL DEPORTE CON MAYOR NUMERO DE SOCIOS."<<endl;
        cout<<"6. INFORMAR EL DEPORTE CON MENOR NUMERO DE SOCIOS."<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<"INGRESE LA OPCION DESEADA: "<<endl;
        cin>>opc;
        switch(opc){
    case 1:system("cls");
        ArtMes();
            system("pause");
        break;
    case 4:
        system("cls");
        CantSociosPorD();
        system("pause");
        break;
    case 0: estado=false;
        break;
        }

       }
}

#endif // REPORTES_H_INCLUDED
