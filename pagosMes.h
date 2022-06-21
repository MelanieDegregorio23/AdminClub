#ifndef PAGOSMES_H_INCLUDED
#define PAGOSMES_H_INCLUDED
#include "deportes.h"
#include "socios.h"
class pagos{
private:
    float valorCuota;
    int idpagos;
    int dni;
    Fecha fechadePago;

public:

    void setidpagos(int i){idpagos=i;}
    void setdni(int d){dni=d;}
    void setfechadePago(Fecha f){fechadePago=f;}
    void setValorCuota(float x){valorCuota=x;}


    int getidpagos(){return idpagos;}
    int getdni(){return dni;}
    Fecha getfechadePago(){return fechadePago;}
    float getValorCuota(){return valorCuota;}


    void Cargar(){
     system("cls");
     cout<<"INGRESAR DNI DE SOCIO"<<endl;
     cin>>dni;
     cout<<endl;
     cout<<"INGRESAR ID DE PAGOS"<<endl;
     cin>>idpagos;
     cout<<endl;
     cout<<"CARGAR FECHA DE PAGO"<<endl;
     fechadePago.Cargar();



};
void Mostrar(){
        cout<<"ID DE PAGOS: "<<idpagos<<endl;
        cout<<"DNI DE SOCIO: "<<dni<<endl;
        cout<<"FECHA DE PAGO: ";
        fechadePago.Mostrar();



};
int GrabarEnDisco(){
    FILE*p;
    int escribio;
    p= fopen("Pagos.dat", "ab");
    if(p==NULL) return -1;
    escribio= fwrite(this, sizeof(pagos),1,p);
    fclose(p);
    return escribio;

}
int LeerEnDisco(int pos){
    FILE*p;
    int leyo;
    p = fopen("Pagos.dat", "rb");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(pagos),SEEK_SET);
    leyo = fread(this, sizeof(pagos), 1, p);

    fclose(p);
    return leyo;

}
int ModificarEnDisco(int pos){
    FILE*p;
    int escribio;
    p =fopen("Pagos.dat", "rb+");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(pagos), SEEK_CUR);
    escribio = fwrite(this, sizeof(pagos), 1 ,p);
    fclose(p);
    return escribio;



}




};

///PROTOTIPOS

void menuPagoMes();
int agregarPagos(pagos aux);
float buscarValordeCuota(int depo);
void listarPagoporDNI();


///DESARROLLO



void listarPagoporDNI(){
    pagos aux;
    int dni,pos=0;
    cout<<"INGRESE DNI DE SOCIO : "<<endl;
    cin>>dni;
    system("cls");
    if(buscarporDNI(dni)>=0){
        while(aux.LeerEnDisco(pos)==1){
        if(aux.getdni()==dni){
            aux.Mostrar();
            cout<<endl;
        }
        pos++;
    }

    }

}

float buscarValordeCuota(int depo){
    int pos;
    float valor;
    deporte reg;
    pos = buscarporCod(depo);
    if(reg.LeerEnDisco(pos)==1){
        valor= reg.getValorCuota();
    }

    return valor;
}


int agregarPagos(pagos aux){
    int dni, pos;
    socio obj;
    aux.Cargar();
    dni = aux.getdni();
    pos = buscarporDNI(dni);
    if(pos>=0){ //encontro dni en el registro
        if(obj.LeerEnDisco(pos)==1){
            int deporte = obj.getIdDeporte();
            float valorCuota = buscarValordeCuota(deporte);
            aux.setValorCuota(valorCuota);
            aux.GrabarEnDisco();
            return 1;
        }

    }
    return -1;
}



void menuPagoMes()
{
   system("cls");
    pagos aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"   MENU PAGOS MENSUALES "<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. AGREGAR PAGOS"<<endl;
        cout<<" 2. LISTAR PAGOS POR DNI DE SOCIO"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1: system("cls");
        if(agregarPagos(aux)==1){
                cout<<"EL PAGO FUE AGREGADO CON EXITO"<<endl;
        }else{
                cout<<"EL PAGO NO PUDO SER AGREGADO"<<endl;

        }
            system("pause");
        break;
    case 2: system("cls");
            listarPagoporDNI();
         system("pause");
        break;

    case 0: estado=false;
        break;
        }

       }
       system("cls");
}


#endif // PAGOSMES_H_INCLUDED
