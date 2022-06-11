#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED

#include "funcionesgenerales.h"

class Articulo
{
private:
    char CodigoAr[5], Descripcion[25];
    float Pu;
    int Stock;
    bool Estado;
public:
    void Cargar();
    void Mostrar();
    int grabarEnDisco();
    int leerEnDisco(int pos);
    int modificarEnDisco(int pos);
    //sets
    void setCodigoAr(const char *a) {strcpy(CodigoAr,a);}
    void setDescripcion ( const char *d) {strcpy(Descripcion,d);}
    void setPu(float p){Pu=p;}
    void setStock(int s){Stock=s;}
    void setEstado(bool e){Estado=e;}
    //gets
    const char* getCodigoAr() {return CodigoAr;}
    const char* getDescripcion(){return Descripcion;}
    float getPu(){return Pu;}
    int getstock (){return Stock;}
    bool getestado (){return Estado;}
};

void Articulo::Cargar(){
    cout<<"Ingrese el Codigo del Articulo: "<<endl;
     cargarCadena(CodigoAr, 4);
     cout<<"Ingrese Descripcion del Articulo: "<<endl;
     cargarCadena(Descripcion, 4);
     cout<<"Ingrese el Precio unitario :  "<<endl;
     cin>>Pu;
     cout<<"Ingrese la Cantidad en Stock :  "<<endl;
     cin>>Stock;
 }

void Articulo::Mostrar(){
    if(Estado==true){
    cout<<"CODIGO DE ARTICULO:  " <<CodigoAr<<endl;
    cout<<"DESCRIPCION: "<<Descripcion<<endl;
    cout<<"PRECIO UNITARIO: "<<Pu<<endl;
    cout<<"STOCK: "<<Stock<<endl<<endl;
    }
}
int  Articulo::grabarEnDisco(){
    FILE*p;
    int escribio;
    p= fopen("Articulos.dat", "ab");
    if(p==NULL) return -1;
    escribio= fwrite(this, sizeof(Articulo),1,p);
    fclose(p);
    return escribio;

 }
int Articulo::leerEnDisco( int pos){
    FILE*p;
    int leyo;
    p = fopen("Articulos.dat", "rb");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(Articulo),SEEK_SET);
    leyo = fread(this, sizeof(Articulo), 1, p);

    fclose(p);
    return leyo;
}
int Articulo::modificarEnDisco(int pos){
    FILE*p;
    int escribio;
    p =fopen("Articulos.dat", "rb+");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(Articulo), SEEK_SET);
    escribio = fwrite(this, sizeof(Articulo), 1 ,p);
    fclose(p);
    return escribio;

}

///PROTOTIPOS
void menuArticulos();

int agregarArticulo(Articulo aux);
void listarArticulos();
int buscarPorCodigo(const char *codigo);
int listarArticuloCod();
int eliminarArticulo();

///FUNCIONES

int agregarArticulo(Articulo aux){
    char codigo [5];
    aux.Cargar();
    strcpy(codigo, aux.getCodigoAr());
    if(buscarPorCodigo(codigo)<0){ ///NO SE ENCONTRO NADA CON ESE CODIGO
        aux.grabarEnDisco();
            return 1;
    }
    return -1;

}
void listarArticulos(){
    Articulo aux;
    int pos =0;
    while(aux.leerEnDisco(pos)==1){
        aux.Mostrar();
        cout<<endl<<endl;
        pos++;


    }
}
 int buscarPorCodigo(const char *codigo){
    Articulo aux;
    int pos=0;
    while(aux.leerEnDisco(pos)==1){
        if(strcmp(codigo, aux.getCodigoAr())==0){///si coincide el codigo
            return pos;
        }
        pos++;

    }
    return -1;
 }
 int listarArticuloCod(){
    Articulo aux;
    int pos;
    char codigo[5];
    cout<<"Ingresar Codigo:  ";
    cin>>codigo;
    pos = buscarPorCodigo(codigo);
    if(pos>=0){
        system("cls");
        aux.leerEnDisco(pos);
        aux.Mostrar();
        return pos;
    }
    return -1;
}

int eliminarArticulo(){
    Articulo aux;
    char codigo[5];
    int pos;
    cout<<"INGRESE EL CODIGO DEL ARTICULO : ";
    cin>>codigo;
    pos = buscarPorCodigo(codigo);
    if(pos>=0){
        aux.leerEnDisco(pos);
        aux.setEstado(false);
        aux.modificarEnDisco(pos);
        return pos;
    }
    return -1;
    }

void menuArticulos(){
    system("cls");
    int opc;
    bool estado = true;
       while (estado==true){

        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU ARTICULOS"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1.AGREGAR ARTICULO"<<endl;
        cout<<" 2.LISTAR ARTICULOS"<<endl;
        cout<<" 3.LISTAR ATICULOS POR ID"<<endl;
        cout<<" 4.LISTAR ARTICULOS POR PRECIO"<<endl;
        cout<<" 5.REGISTRAR VENTA"<<endl;
        cout<<" 6.ACTUALIZAR STOCK"<<endl;
        cout<<" 7.ELIMINAR ARTICULO"<<endl;
        cout<<" 8.CONFIGURACION"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        system("cls");
        switch(opc){

    case 1: system("cls");
        if(agregarArticulo(aux)==1){
            cout<<" ARTICULO AGREGADO"<<endl;
        }else{cout<<"EL CODIGO YA PERTENECE A UN ARTICULO EXISTENTE"<<endl;}
        system("pause");
         break;

    case 2: system("cls");
        listarArticulos();
        system("pause");
        break;
    case 3:  system("cls");
        listarArticulos();
        system("pause");
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 0: estado=false;
        break;
        }

       }
       system("cls");
}


#endif // ARTICULOS_H_INCLUDED
