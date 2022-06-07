#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED

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

///PROTOTIPOS
void menuArticulos();


///FUNCIONES




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
        switch(opc){
    case 1:

        break;
    case 2:
        break;
    case 3:
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
