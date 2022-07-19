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
    cout<<endl;
    cout<<"  EL DEPORTE CON MENOR CANTIDAD DE SOCIOS ES "<<dep<<endl;
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
    cout<<endl;
    cout<<"  EL DEPORTE CON MAYOR CANTIDAD DE SOCIOS ES "<<dep<<endl;
    cout<<endl;
}

void importePorVentas(){
    cout<<endl;
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
            cout<<"IMPORTE ACUMULADO EN EL  "<<i+2018<<" :   $"<<n[i]<<endl;
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
        cout<<"CANTIDAD DE SOCIOS POR DEPORTE "<<endl;
        cout<<endl;

        while(aux.LeerEnDisco(pos)){
            int id = aux.getCodDep();
            int cant = contarS(id);
            if(cant>0){
                cout<<"CANTIDAD DE SOCIOS EN "<<aux.getDescripcion()<<"    :    "<<cant<<endl;
                cout<<endl;
            }
            pos++;
    }
    }




void mostrarArt(int *v,int tam){
int i;

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
    int opc;
    bool estado = true;
       while (estado==true){
            system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU REPORTES"<<endl;
        cout<<" ________________________"<<endl<<endl;


        cout<<"1. CANTIDAD DE ARTICULOS VENDIDOS POR MES."<<endl;
        cout<<"2. IMPORTE ANUAL ACUMULADO POR VENTAS."<<endl;
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
    case 2:
        system("cls");
        importePorVentas();
        system("pause");
        break;
    case 3:
        ///a desarrollar
        break;
    case 4:
        system("cls");
        CantSociosPorD();
        system("pause");
        break;
    case 5:
        system("cls");
        informarMayorS();
        system("pause");
        break;
    case 6:
        system("cls");
        informarMenorS();
        system("pause");
        break;
    case 0: estado=false;
        break;
        }

       }
}

#endif // REPORTES_H_INCLUDED
