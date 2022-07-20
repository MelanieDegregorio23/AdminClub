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
        const int ANCHO_MENU = 50;
        const int ALTO_MENU = 29;
        const int POSMENUX = 33;
        const int POSMENUY = 3;
        setColor(LETRA);
        setBackgroundColor(FONDO);
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+18,POSMENUY+1);
        cout<<"ARTICULOS";
        locate(POSMENUX+15,POSMENUY+4);
     cout<<"Ingrese el Codigo : ";
     cargarCadena(CodigoAr, 4);
     locate(POSMENUX+15,POSMENUY+5);
     cout<<"Ingrese Descripcion del Articulo: ";
     locate(POSMENUX+15,POSMENUY+6);
     cargarCadena(Descripcion, 24);
     locate(POSMENUX+15,POSMENUY+7);
     cout<<"Ingrese el Precio unitario :  ";
     cin>>Pu;
     locate(POSMENUX+15,POSMENUY+8);
     cout<<"Ingrese la Cantidad en Stock :  ";
     cin>>Stock;
     Estado=true;
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
int buscarporCodigoArt(const char *cod);
int agregarArticulo(Articulo aux);
int listarArticulos();
int buscarPorPrecio(float *Pu);
int listarArticuloCod();
 int listarArticuloPrecio();
int eliminarArticulo();
int cambiarPrecio();
///FUNCIONES

int buscarporCodigoArt(const char* cod){
    Articulo reg;
    int pos=0;
    while(reg.leerEnDisco(pos)){
        if(strcmp(reg.getCodigoAr(), cod)==0){
            return pos;
        }
        pos++;
    }
    return -1;
}

int agregarArticulo(Articulo aux){///NO PERMITE INGRESAR CODIGOS QUE FUERON ELIMINADOS
    char codigo[5];
    aux.Cargar();
    strcpy(codigo, aux.getCodigoAr());
    if(buscarporCodigoArt(codigo)<0){ ///NO SE ENCONTRO NADA CON ESE CODIGO
        aux.grabarEnDisco();
            return 1;
    }
    return -1;

}
int listarArticulos(){
    Articulo aux;
    int pos=0, lectura=0, contador=0;
    while(aux.leerEnDisco(pos)==1){
        lectura=1;
        if(aux.getestado()==true){
        cout<<"ARTICULO N"<<(char)186<<contador+1<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;
        cout<<endl<<endl;
        contador++;
        }
        pos++;

    }
    return lectura;
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
        cout<<"ARTICULO N"<<(char)186<<aux.getCodigoAr()<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;
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
    pos = buscarporCodigoArt(codigo);
    if(pos>=0){
        system("cls");
        aux.leerEnDisco(pos);

        cout<<"ARTICULO N"<<(char)186<<aux.getCodigoAr()<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;



        return pos;
    }
    return -1;
}
void mostrarPosicionART(int pos, Articulo aux){

    if(aux.leerEnDisco(pos)==1){
        cout<<"ARTICULO N"<<(char)186<<aux.getCodigoAr()<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;
    }
}

int eliminarArticulo(){
    Articulo aux;
    int pos=0;
    char codigo[5];
    char confirmo;
    cout<<"INGRESE CODIGO DE ARTICULO :  ";
    cin>>codigo;
    pos = buscarporCodigoArt(codigo);
    if(pos>=0){
        mostrarPosicionART(pos, aux);
        cout<<endl;
        cout<<"QUIERE ELIMINAR ESTE ARTICULO ?  (S / N) ";
        cin>> confirmo;
        switch(confirmo){
        case 's':
              aux.setEstado(false);
            aux.modificarEnDisco(pos);
            return 1;
            break;
        case 'n':  return 2;
            break;
        }

    }
    return -1;
}
int cambiarPrecio(){
    Articulo aux;
    float precio;
    int pos;
    char codigo[5];
    separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU+17,LETRA,FONDO);
    locate(POSMENUX+17,POSMENUY+1);
    cout<<"DATOS DEL ARTICULOS";
    locate(POSMENUX+15,POSMENUY+4);
    cout<<"Ingrese el codigo del Articulo  :";
    cin>>codigo;
    pos=buscarporCodigoArt(codigo);

    if(pos>=0){
        locate(POSMENUX+15,POSMENUY+5);
        cout<<"Ingresar el nuevo Precio Unitario (PU):  ";
        cin>>precio;
        if(precio<0){
            locate(POSMENUX+15,POSMENUY+6);
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
void submenuListarArticulos(){

    system("cls");
    Articulo aux;
    bool estado = true;
    int key,opc, cursorX, cursorY;
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
        cout<<"MENU DE LISTADOS";
        locate(POSMENUX+14,POSMENUY+4);

        cout<<" LISTAR ARTICULOS";
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" LISTAR ARTICULOS POR CODIGO";
        locate(POSMENUX+14,POSMENUY+6);
        cout<<" LISTAR ARTICULOS POR PRECIO";
        locate(POSMENUX+14,POSMENUY+7);
        cout<<" VOLVER AL MENU ANTERIOR";
        locate(POSMENUX+14,POSMENUY+9);
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
            if(opc < 3){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 3){
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
          if(listarArticulos()==0){
        cout<<"NO HAY ARTICULOS REGISTRADOS "<<endl;
       }
        system("pause");
        break;
         case 1:
        system("cls");
        if(listarArticuloCod()<0){
            cout<<"NO SE ENCONTRO EL ARTICULO "<<endl;
        }
        system("pause");
        break;
        case 2:
        system("cls");
        if(listarArticuloPrecio()<0){
            cout<<"NO SE ENCONTRO EL ARTICULO "<<endl;
        }
        system("pause");
        break;
    case 3: estado =false;
    break;

        }
}
}

void menuArticulos(){

    Articulo aux;
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 10;
    bool estado = true;
     int key, opc, cursorX, cursorY;
       while (estado==true){
       cursorX=POSMENUX+13;
       cursorY=POSMENUY + 4;
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      opc=0;
      setColor(LETRA);
      setBackgroundColor(FONDO);
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+18,POSMENUY+1);
        cout << "MENU ARTICULOS";
        locate(POSMENUX+15,POSMENUY+4);
        cout<<" AGREGAR ARTICULO";
        locate(POSMENUX+15,POSMENUY+5);
        cout<<" ELIMINAR ARTICULO";
        locate(POSMENUX+15,POSMENUY+6);
        cout<<" MENU DE LISTADOS";
        locate(POSMENUX+15,POSMENUY+7);
        cout<<" MODIFICAR PRECIO";
        locate(POSMENUX+15,POSMENUY+8);
        cout<<" VOLVER AL MENU PRINCIPAL"<<endl;
        locate(POSMENUX+15,POSMENUY+9);
        cout<<endl;
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
            if(opc < 4){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 4){
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
        if(agregarArticulo(aux)==1){
                gotoxy(46,26);
            cout<<" ARTICULO AGREGADO"<<endl;
            }
            else{
                gotoxy(46,26);
        cout<<"EL CODIGO YA PERTENECE A UN ARTICULO EXISTENTE"<<endl;}
        gotoxy(42,28);
        system("pause");
         break;

    case 1: system("cls");

         if(eliminarArticulo()==1){
            cout<<"ARTICULO ELIMINADO "<<endl;
            }
        else{ cout<<"NO SE ELIMINO ARTICULO"<<endl;}
        system("pause");
        break;
        case 2: system("cls");
        submenuListarArticulos();
        system("pause");
        break;
    case 3:if(cambiarPrecio()>=0){

            cout<<"CAMBIO EXITOSO"<<endl;
        }else{ cout<<"NO HAY ARTICULO CON ESE CODIGO"<<endl; }
        system("pause");
        break;
        break;
    case 4: estado=false;
        break;
        }

       }
}

#endif // ARTICULOS_H_INCLUDED
