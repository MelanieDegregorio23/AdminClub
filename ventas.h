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

    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 20;
    const int POSMENUX = 33;
    const int POSMENUY = 3;
    setColor(LETRA);
    setBackgroundColor(FONDO);
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
    separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
    locate(POSMENUX+18,POSMENUY+1);
    cout<<"VENTAS"<<endl;
     locate(POSMENUX+16,POSMENUY+5);
    cout<<"INGRESE ID DE VENTA: ";
    cin>>ID;
    locate(POSMENUX+16,POSMENUY+6);
    cout<<"INGRESE CANTIDAD VENDIDA: ";
    cin>>Cant;
    locate(POSMENUX+16,POSMENUY+7);
    cout<<"INGRESE FECHA DE VENTA: "<<endl;
    locate(POSMENUX+16,POSMENUY+8);
    FechadeVenta.fechaHoy();
    FechadeVenta.Mostrar();

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
        if(strcmp(aux.getCodigoAr(), cod)==0 && aux.getestado()==true){
            return pos;
        }
        pos++;
    }
    return -1;
}

int AgregarVentas(Venta aux){
    int posArt, posDNI, cantV, dni;
    char cod[5];
    separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU+17,LETRA,FONDO);
    locate(POSMENUX+20,POSMENUY+1);
    cout<<"VENTAS";
    locate(POSMENUX+12,POSMENUY+5);
    cout<<"INGRESE EL CODIGO DE ARTICULO: ";
    cargarCadena(cod,4);
    locate(POSMENUX+12,POSMENUY+6);
    cout<<"INGRESE EL DNI DEL CLIENTE: ";
    cin>>dni;
    posArt = buscarPorCodigo(cod);
    posDNI = buscarporDNI(dni);
    if( posDNI>=0 && posArt>=0){
             aux.setCodArt(cod);
             aux.setDNI(dni);
             aux.cargar();
             cantV = aux.getCant();
            float importe=generarImpor(cantV, posArt);
            locate(POSMENUX+12,POSMENUY+7);
            cout<<"IMPORTE: "<<importe<<endl;
            aux.setImporte(importe);
            actualizarStockVendido(cantV, posArt);
            aux.grabarEnDisco();
        return 1;
        }
        if(posArt<0){
                locate(POSMENUX+12,POSMENUY+8);
            cout<<"EL CODIGO DE ARTICULO NO EXISTE EN NUESTRA BASE DE DATOS: "<<endl;
        }
        if(posDNI<0){
            locate(POSMENUX+12,POSMENUY+9);
            cout<<"EL DNI INGRESADO NO PERTENECE A NINGUN SOCIO DEL CLUB: "<<endl;
        }
  return -1;
}

int  ListarVentas(){
    Venta aux;
    int pos =0,contador=0, contador2=0;
    while(aux.leerEnDisco(pos)==1){
        contador++;
        cout<<"VENTAS N"<<(char)186<<contador2+1<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;
        cout<<endl<<endl;
        contador2++;
        pos++;

    }
    return contador;


}

int buscarporid(int id){
    Venta aux;
    int pos=0;
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
    pos=buscarporid(id);
    while(aux.leerEnDisco(pos)==1){
        if(aux.getID()==id){
        cout<<"VENTAS N"<<(char)186<<aux.getID()<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;
        cout<<endl<<endl;
        return 1;
        }
        pos++;
    }


    return -1;


}
void submenuListarVentas(){

    system("cls");
    Articulo aux;
    int opc;
    bool estado = true;
    int key, cursorX, cursorY;
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 10;
       while (estado==true){
        cursorX=POSMENUX+11;
        cursorY=POSMENUY + 4;
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        opc=0;
        system("cls");
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+18,POSMENUY+1);
        cout<<" MENU DE LISTADOS"<<endl;
        locate(POSMENUX+14,POSMENUY+4);
        cout<<" LISTAR VENTAS POR ID"<<endl;
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" LISTAR TODAS LAS VENTAS"<<endl;
        locate(POSMENUX+14,POSMENUY+6);
        cout<<" VOLVER AL MENU ANTERIOR"<<endl;
        locate(POSMENUX+13,POSMENUY+7);

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
            if(opc < 2){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 2){
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
    case 0:
             system("cls");

            if(ListarID()<0){
                cout<<"EL ID NO CORRESPONDE A UNA VENTA "<<endl;
            }
            system("pause");
        break;
         case 1:
            system("cls");

            if(ListarVentas()==0){
                cout<<"NO HAY VENTAS REGISTRADAS"<<endl;
            }
            system("pause");
        break;
    case 2: estado =false;
    break;

        }
}
}
void MenuVentas(){
Venta aux;
    int opc;
    bool estado = true;
    int key, cursorX, cursorY;
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 10;
       while (estado==true){
        cursorX=POSMENUX+11;
        cursorY=POSMENUY + 4;
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        opc=0;
        system("cls");
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+18,POSMENUY+1);
        cout<<"MENU VENTAS"<<endl;
        locate(POSMENUX+14,POSMENUY+4);
        cout<<" AGREGAR VENTAS."<<endl;
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" MENU DE LISTADOS."<<endl;
        locate(POSMENUX+14,POSMENUY+6);
        cout<<" VOLVER AL MENU PRINCIPAL."<<endl;
        locate(POSMENUX+13,POSMENUY+7);

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
            if(opc < 2){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 2){
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
    case 0: system("cls");
            if(AgregarVentas(aux)==1){
                    gotoxy(46,26);
            cout<<"VENTA REGISTRADA"<<endl;
            }else{
                gotoxy(46,26);
            cout<<"NO SE PUDO REGISTRAR LA VENTA"<<endl;}
            gotoxy(42,28);
            system("pause");
        break;
    case 1:system("cls");
        submenuListarVentas();
           system("pause");

            break;

    case 2:estado=false;
        break;



    }

    }



    system("cls");


}



#endif // VENTAS_H_INCLUDED
