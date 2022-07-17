#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "socios.h"
class Venta{
private:
    int ID, Cant, DNI;
    char CodArt[5];
    float Importe;
    Fecha FechadeVenta;
    bool Estado;

public:
    //sets
    void setDNI (int d){DNI=d;}
    void setCodArt (const char *c){strcpy(CodArt,c);}
    void setCant( int x){ Cant=x ; }
    void setID( int x){ ID=x ; }
    void setImporte( float x){ Importe = x ;}
    void setFechadeVenta( Fecha f){ FechadeVenta=f ;}
    void setEstado (bool x){ Estado= x;};
    //gets
    int getDNI(){return DNI;}
    const char *getCodArt(){return CodArt;}
    int getCant (){ return  Cant;}
    int getID(){return ID;}
    Fecha getFechadeVenta(){return FechadeVenta;}
    float getImporte(){return Importe;}
    bool getEstado(){ return Estado;}

    int grabarEnDisco(){
    FILE*p;
    int escribio;
    p= fopen("Ventas.dat", "ab");
    if(p==NULL) return -1;
    escribio= fwrite(this, sizeof(Venta),1,p);
    fclose(p);
    return escribio;
}
 int leerEnDisco( int pos){
    FILE*p;
    int leyo;
    p = fopen("Ventas.dat", "rb");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(Venta),SEEK_SET);
    leyo = fread(this, sizeof(Venta), 1, p);

    fclose(p);
    return leyo;
}
int modificarEnDisco(int pos){
    FILE*p;
    int escribio;
    p =fopen("Ventas.dat", "rb+");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(Venta), SEEK_SET);
    escribio = fwrite(this, sizeof(Venta), 1 ,p);
    fclose(p);
    return escribio;

}
void cargar(){
    cout<<"INGRESE ID DE VENTA: "<<endl;
    cin>>ID;
    cout<<"INGRESE CANTIDAD VENDIDA: "<<endl;
    cin>>Cant;
    cout<<"INGRESE FECHA DE VENTA: "<<endl;
    FechadeVenta.Cargar();

}
void Mostrar(){
    cout<<" INGRESE ID DE VENTA: "<<ID<<endl;
    cout<<" DNI DEL CLIENTE: "<<DNI<<endl;
    cout<<" CODIGO DE ARTICULO: "<<CodArt<<endl;
    cout<<" CANTIDAD VENDIDA: "<<Cant<<endl;
    cout<<" IMPORTE: "<<Importe<<endl;
    cout<<" FECHA DE VENTA: ";
    FechadeVenta.Mostrar();
}

};


/*PROTOTIPO*/
void MenuVentas();
int buscarPorCodigo(const char *v);
int AgregarVentas(Venta aux);
int ListarVentas();
int ListarID();
int buscarporid(int id);
float generarImpor( int Cant, int pos);
void actualizarStockVendido(int cant, int pos);


/*FUNCIONES*/
void actualizarStockVendido(int cant, int pos){
    Articulo reg;
    int stock;
    reg.leerEnDisco(pos);
    stock = reg.getstock()-cant;
    reg.setStock(stock);
    reg.modificarEnDisco(pos);
}

float generarImpor( int Cant, int pos){
    float importe;
    Articulo reg;
    reg.leerEnDisco(pos);
    importe = reg.getPu()*Cant;
    return importe;
}

int buscarPorCodigo(const char *cod){
    Articulo aux;
    int pos=0;
    while(aux.leerEnDisco(pos)==1){
        if(strcmp(aux.getCodigoAr(), cod)==0){
            return pos;
        }
        pos++;
    }
    return -1;
}

int AgregarVentas(Venta aux){
    int posArt, posDNI, cantV, dni;
    char cod[5];
    cout<<"INGRESE EL CODIGO DE ARTICULO: "<<endl;
    cargarCadena(cod,4);
    cout<<"INGRESE EL DNI DEL CLIENTE: "<<endl;
    cin>>dni;

    posArt = buscarPorCodigo(cod);
    posDNI = buscarporDNI(dni);
    if( posDNI>=0 && posArt>=0){
             aux.setCodArt(cod);
             aux.setDNI(dni);
             aux.cargar();
             cantV = aux.getCant();
            float importe=generarImpor(cantV, posArt);
            cout<<"IMPORTE: "<<importe<<endl;
            aux.setImporte(importe);
            actualizarStockVendido(cantV, posArt);
            aux.grabarEnDisco();
        return 1;
        }
  return -1;
}

int  ListarVentas(){
    Venta aux;
    int pos =0,contador=0;
    while(aux.leerEnDisco(pos)==1){
        contador++;
        aux.Mostrar();
        cout<<endl<<endl;
        pos++;

    }
    return contador;


}

int buscarporid(int id){
    Venta aux;
    int pos=0,i;
    while(aux.leerEnDisco(pos)==1){
        if(aux.getID()==id){
            return pos;
        }
        pos++;

    }
    return -1;
}
int ListarID(){
    Venta aux;
    int id, pos;
    cout<<"INGRESE ID : "<<endl;
    cin>>id;
    pos = buscarporid(id);
    system("cls");
    while(aux.leerEnDisco(pos)){
        aux.Mostrar();
        cout<<endl;
        pos++;
    }


    return -1;


}
void submenuListarVentas(){

    system("cls");
    Articulo aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ___________________________________"<<endl<<endl;
        cout<<"      MENU DE LISTADOS"<<endl;
        cout<<" ____________________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. LISTAR VENTAS POR ID"<<endl;
        cout<<" 2. LISTAR TODAS LAS VENTAS"<<endl;
        cout<<" 0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1:
             system("cls");

            if(ListarID()<0){
                cout<<"EL ID NO CORRESPONDE A UNA VENTA "<<endl;
            }
            system("pause");
        break;
         case 2:
            system("cls");

            if(ListarVentas()==0){
                cout<<"NO HAY VENTAS REGISTRADAS"<<endl;
            }
            system("pause");
        break;
    case 0: estado =false;
    break;

        }
}
}
void MenuVentas(){
int op;
Venta aux;
bool estado=true;
    while(estado==true){
        system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"       MENU VENTAS"<<endl;
        cout<<" ________________________"<<endl<<endl;
        cout<<endl;
        cout<<" 1. AGREGAR VENTAS"<<endl;
        cout<<" 2. MENU DE LISTADOS"<<endl;
        cout<<"------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: "<<endl;
        cin>>op;
        switch(op){
    case 1: system("cls");
            if(AgregarVentas(aux)==1){
            cout<<"VENTA REGISTRADA"<<endl;
            }else{cout<<"NO SE PUDO REGISTRAR LA VENTA"<<endl;}
            system("pause");
        break;
    case 2:system("cls");
        submenuListarVentas();
           system("pause");

            break;

    case 0:estado=false;
        break;



    }

    }



    system("cls");


}



#endif // VENTAS_H_INCLUDED
