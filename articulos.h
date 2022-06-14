#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED

#include "funcionesgenerales.h"

class Articulo{
private:
    char CodigoAr[5], Descripcion[25];
    float Pu;
    int Stock;
    bool Estado;
public:
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
    //funciones
 void Cargar(){
    cout<<"Ingrese el Codigo del Articulo: "<<endl;
     cargarCadena(CodigoAr, 4);
     cout<<"Ingrese Descripcion del Articulo: "<<endl;
     cargarCadena(Descripcion, 24);
     cout<<"Ingrese el Precio unitario :  "<<endl;
     cin>>Pu;
     cout<<"Ingrese la Cantidad en Stock :  "<<endl;
     cin>>Stock;
 }
  void Mostrar(){
    if(Estado==true){
    cout<<"CODIGO DE ARTICULO:  " <<CodigoAr<<endl;
    cout<<"DESCRIPCION: "<<Descripcion<<endl;
    cout<<"PRECIO UNITARIO: "<<Pu<<endl;
    cout<<"STOCK: "<<Stock<<endl<<endl;
    }
 }
 int grabarEnDisco(){
    FILE*p;
    int escribio;
    p= fopen("Articulos.dat", "ab");
    if(p==NULL) return -1;
    escribio= fwrite(this, sizeof(Articulo),1,p);
    fclose(p);
    return escribio;
}
int leerEnDisco( int pos){
    FILE*p;
    int leyo;
    p = fopen("Articulos.dat", "rb");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(Articulo),SEEK_SET);
    leyo = fread(this, sizeof(Articulo), 1, p);

    fclose(p);
    return leyo;
}
int modificarEnDisco(int pos){
    FILE*p;
    int escribio;
    p =fopen("Articulos.dat", "rb+");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(Articulo), SEEK_SET);
    escribio = fwrite(this, sizeof(Articulo), 1 ,p);
    fclose(p);
    return escribio;

}
};

///PROTOTIPOS
void menuArticulos();
int agregarArticulo(Articulo aux);
int listarArticulos();
int buscarPorCodigo(const char *codigo);
int buscarPorPrecio(float *Pu);
int listarArticuloCod();
 int listarArticuloPrecio();
int eliminarArticulo();
int cambiarPrecio();
///FUNCIONES

int agregarArticulo(Articulo aux){///NO PERMITE INGRESAR CODIGOS QUE FUERON ELIMINADOS
    char codigo[5];
    aux.Cargar();
    strcpy(codigo, aux.getCodigoAr());
    if(buscarPorCodigo(codigo)<0){ ///NO SE ENCONTRO NADA CON ESE CODIGO
        aux.grabarEnDisco();
            return 1;
    }
    return -1;

}
int listarArticulos(){
    Articulo aux;
    int pos =0, lectura=0;
    while(aux.leerEnDisco(pos)==1){
        lectura=1;
        aux.Mostrar();
        cout<<endl<<endl;
        pos++;

    }
    return lectura;
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
 int buscarPorPrecio(float pu){
  Articulo aux;
  int pos=0;
   while(aux.leerEnDisco(pos)==1){
        if(aux.getPu()==pu){
            return pos;
        }
        pos++;

    }
    return -1;

 }
  int listarArticuloPrecio(){
    Articulo aux;
    int pos;
    float pu;
    cout<<"Ingresar Precio:  ";
    cin>>pu;
    pos = buscarPorPrecio(pu);
    if(pos>=0){
        system("cls");
        aux.leerEnDisco(pos);
        aux.Mostrar();
        return pos;
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
int cambiarPrecio(){
    Articulo aux;
    float precio;
    int pos;
    char codigo[5];
    cout<<"Ingrese el codigo del Articulo  : ";
    cin>>codigo;
    pos=buscarPorCodigo(codigo);

    if(pos>=0){
        cout<<"Ingresar el nuevo Precio Unitario (PU):  ";
        cin>>precio;
        if(precio<0){
            cout<<"EL PRECIO TIENE QUE SER POSITIVO, INGRESE OTRO : ";
            cin>>precio;
        }
        aux.leerEnDisco(pos);
        aux.setPu(precio);
        aux.modificarEnDisco(pos);
        return pos;
    }
    return -1;
}

void menuArticulos(){


    int opc;
    Articulo aux;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout << " ________________________" << endl << endl;
        cout << "      MENU ARTICULOS" << endl;
        cout << " ________________________" << endl << endl;
        cout<<"1.AGREGAR ARTICULO"<<endl;
        cout<<"2.LISTAR ARTICULOS"<<endl;
        cout<<"3.LISTAR ATICULOS POR CODIGO"<<endl;
        cout<<"4.LISTAR ARTICULOS POR PRECIO"<<endl;
        cout<<"5.REGISTRAR VENTA"<<endl;
        cout<<"6.ACTUALIZAR STOCK"<<endl;
        cout<<"7.ELIMINAR ARTICULO"<<endl;
        cout<<"8.MODIFICAR PRECIO"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<"INGRESE LA OPCION DESEADA: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){

    case 1: system("cls");
        if(agregarArticulo(aux)==1){
            cout<<" ARTICULO AGREGADO"<<endl;
            }
            else{cout<<"EL CODIGO YA PERTENECE A UN ARTICULO EXISTENTE"<<endl;}
        system("pause");
         break;

    case 2: system("cls");
        if(listarArticulos()==0){
        cout<<"NO HAY ARTICULOS REGISTRADOS "<<endl;
       }
        system("pause");
        break;
    case 3:  system("cls");
        if(listarArticuloCod()<0){
            cout<<"NO SE ENCONTRO EL ARTICULO "<<endl;
        }
        system("pause");
        break;
    case 4:system("cls");
        if(listarArticuloPrecio()<0){
            cout<<"NO SE ENCONTRO EL ARTICULO "<<endl;
        }
        system("pause");
        break;
    case 5:
        break;
    case 6:
        break;
    case 7: system("cls");
         if(eliminarArticulo()>0){
            cout<<"ARTICULO ELIMINADO "<<endl;
            }
        else{ cout<<"NO SE ENCONTRO ARTICULO CON ESE CODIGO"<<endl;}
        system("pause");
        break;
    case 8:if(cambiarPrecio()>=0){
            cout<<"CAMBIO EXITOSO"<<endl;
        }else{ cout<<"NO HAY ARTICULO CON ESE CODIGO"<<endl; }
        system("pause");
        break;
        break;
    case 0: estado=false;
        break;
        }

       }
}

#endif // ARTICULOS_H_INCLUDED
