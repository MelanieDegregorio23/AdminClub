#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
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
    void setEstado (bool x){ Estado= x;};
    //gets
    int getDNI(){return DNI;}
    const char *getCodArt(){return CodArt;}
    int getCant (){ return  Cant;}
    int getID(){return ID;}
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
    cout<<"INGRESE DNI DEL CLIENTE: "<<endl;
    cin>>DNI;
    cout<<"INGRESE CODIGO DE ARTICULO: "<<endl;
    cargarCadena(CodArt,4);
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
int AgregarVentas(Venta aux);
void ListarVentas();
int ListarID();
int buscarporid(int id);



/*FUNCIONES*/

int AgregarVentas(Venta aux){
    int posArt, posDNI;
    aux.cargar();
    posArt = buscarPorCodigo( aux.getCodArt());
    posDNI = buscarPorDNI( aux.getDNI() );
    if( posDNI>=0 && posArt>=0){
        float importe=generarImpor(aux, posArt);
        aux.setImporte(importe);
        aux.grabarEnDisco();
        return 1;}
  return -1;
}

void ListarVentas(){
    Venta aux;
    int pos =0;
    while(aux.leerEnDisco(pos)==1){
        aux.Mostrar();
        cout<<endl<<endl;
        pos++;

    }


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
    if(pos>=0){
        system("cls");
        aux.leerEnDisco(pos);
        aux.Mostrar();
        return pos;
    }
    return -1;


}
void MenuVentas(){
int op;
Venta aux;
bool estado=true;
    while(estado==true){
        system("cls");
        cout<<"MENU VENTAS"<<endl;
        cout<<"------------------"<<endl;
        cout<<endl;
        cout<<"1. AGREGAR VENTAS"<<endl;
        cout<<"2. LISTAR VENTAS POR ID"<<endl;
        cout<<"3. LISTAR TODAS LAS VENTAS"<<endl;
        cout<<"------------------"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
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
    case 2:
            system("cls");

            if(ListarID()<0){
                cout<<"EL ID NO CORRESPONDE A UNA VENTA: "<<endl;
            }
            system("pause");
            break;
    case 3:
            system("cls");

            ListarVentas();
            system("pause");
        break;
    case 4:

        break;
    case 0:estado=false;
        break;



    }

    }














}



#endif // VENTAS_H_INCLUDED
