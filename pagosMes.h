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

    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 20;
    const int POSMENUX = 33;
    const int POSMENUY = 3;
    setColor(LETRA);
    setBackgroundColor(FONDO);
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
    separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
    locate(POSMENUX+16,POSMENUY+1);
    cout<<"PAGO DE COUTAS: ";
     locate(POSMENUX+16,POSMENUY+5);
     cout<<"INGRESAR ID DE PAGOS: ";
     cin>>idpagos;
     locate(POSMENUX+16,POSMENUY+6);
     cout<<"CARGAR FECHA DE PAGO: "<<endl;
     locate(POSMENUX+16,POSMENUY+7);
     fechadePago.fechaHoy();
     fechadePago.Mostrar();



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
int listarPagoporDNI();


///DESARROLLO





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
    separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU+17,LETRA,FONDO);
    locate(POSMENUX+20,POSMENUY+1);
    cout<<"DATOS DEL SOCIO";
    locate(POSMENUX+12,POSMENUY+5);
    cout<<"INGRESE EL DNI DEL SOCIO";
    locate(POSMENUX+12,POSMENUY+7);
    cout<<"DNI: ";
    cin>>dni;

    pos = buscarporDNI(dni);
    if(pos>=0){


        if(obj.LeerEnDisco(pos)==1){

            int deporte = obj.getIdDeporte();
            float valorCuota = buscarValordeCuota(deporte);
            aux.setValorCuota(valorCuota);
            aux.setdni(dni);
            aux.Cargar();
            aux.GrabarEnDisco();
            return 1;
        }



    }

    return -1;
}
int listarPagoporDNI(){
    pagos aux;
    int dni,pos=0;
    cout<<"INGRESE DNI DE SOCIO : "<<endl;
    cin>>dni;


        while(aux.LeerEnDisco(pos)==1){
            if(aux.getdni()==dni){
            cout<<"PAGO N"<<(char)186<<aux.getidpagos()<<endl;
            cout<<"--------------- "<<endl;
            aux.Mostrar();
            cout<<"--------------- "<<endl;
            cout<<endl<<endl;




        }

        pos++;
    }

    return pos;


}
void submenuListarPagos(){

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
        cout<<"MENU DE LISTADOS";
        locate(POSMENUX+14,POSMENUY+4);
        cout<<" LISTAR PAGOS POR DNI DE SOCIO"<<endl<<endl;
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" VOLVER AL MENU ANTERIOR"<<endl;
        locate(POSMENUX+12,POSMENUY+4);

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
            if(opc < 1){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 1){
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
            if(listarPagoporDNI()<0){
                cout<<"NO SE ENCONTRO PAGOS DE CUOTAS PARA ESE DNI: ";
            }
        system("pause");
        break;

    case 1: estado =false;
    break;

        }
}
}


void menuPagoMes()
{
   system("cls");
    pagos aux;
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
        cout<<"MENU PAGOS MENSUALES ";
        locate(POSMENUX+14,POSMENUY+4);
        cout<<" INGRESAR VALOR DE CUOTA"<<endl;
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" MENU DE LISTADOS"<<endl;
        locate(POSMENUX+14,POSMENUY+6);
        cout<<" VOLVER AL MENU PRINCIPAL"<<endl;
       locate(POSMENUX+12,POSMENUY+7);

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
        if(agregarPagos(aux)==1){
                gotoxy(46,15);
                cout<<"EL PAGO FUE AGREGADO CON EXITO"<<endl;
        }else{
            gotoxy(46,15);
                cout<<"EL PAGO NO PUDO SER AGREGADO"<<endl;

        }
            gotoxy(42,17);
            system("pause");
        break;
        case 1: system("cls");
            submenuListarPagos();

        break;

    case 2: estado=false;
        break;
        }

       }
       system("cls");
}


#endif // PAGOSMES_H_INCLUDED
