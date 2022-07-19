#ifndef DEPORTES_H_INCLUDED
#define DEPORTES_H_INCLUDED
#include "instructores.h"

class deporte{
private:
    int CodDep;
    int CantCupos;
    float ValorCuota;
    bool Estado;
    char Descripcion [30];
    char Horario[20];
public:
    void setCodDep (int cd){CodDep=cd;}

    void setCantCupos (int c){CantCupos=c;}
    void setValorCuota (float v){ValorCuota=v;}
    void setDescripcion (const char *d){strcpy(Descripcion,d);}
    void setHorario(const char *h){strcpy(Horario,h);}
    void setEstado (bool e){Estado=e;}

    int getCodDep(){return CodDep;}
    int getCantCupos(){return CantCupos;}
    float getValorCuota(){return ValorCuota;}
    const char *getDescripcion (){return Descripcion;}
    const char *getHorario(){return Horario;}
    bool getEstado(){return Estado;}

    void Cargar()
    {
    system("cls");
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 29;
    const int POSMENUX = 33;
    const int POSMENUY = 3;
    setColor(LETRA);
    setBackgroundColor(FONDO);
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
    separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
    locate(POSMENUX+18,POSMENUY+1);
        cout<<"DEPORTES"<<endl;
        locate(POSMENUX+16,POSMENUY+4);
        cout<<"INGRESAR CODIGO DE DEPORTE: ";
        locate(POSMENUX+16,POSMENUY+5);
        cin>>CodDep;
        locate(POSMENUX+16,POSMENUY+6);
        cout<<"NOMBRE DE DEPORTE: ";
        locate(POSMENUX+16,POSMENUY+7);
        cargarCadena(Descripcion, 29);
        locate(POSMENUX+16,POSMENUY+8);
        cout<<"INGRESAR CANTIDAD DE CUPOS: ";
        locate(POSMENUX+16,POSMENUY+9);
        cin>>CantCupos;
        locate(POSMENUX+16,POSMENUY+10);
        cout<<"AGREGAR VALOR DE CUOTA: ";
        locate(POSMENUX+16,POSMENUY+11);
        cin>>ValorCuota;
        locate(POSMENUX+16,POSMENUY+12);
        cout<<"INGRESAR EL HORARIO EN EL QUE SE DICTAN LAS CLASES: ";
        locate(POSMENUX+16,POSMENUY+13);
         cargarCadena(Horario, 19);
         Estado =true;





    };
    void Mostrar()
    {
        if (Estado==true)
        {
            cout<<"CODIGO DE DEPORTE: "<<endl<<CodDep<<endl;
            cout<<"DEPORTE: "<<endl<<Descripcion<<endl;
            cout<<"CANTIDAD DE CUPOS: "<<endl<<CantCupos<<endl;
            cout<<"VALOR DE LA CUOTA: "<<endl<<ValorCuota<<endl;
            cout<<"HORARIO DE CLASES: "<<endl<<Horario<<endl;
            ///mostrar

        }


    };
    int GrabarEnDisco()
    {
        FILE*p;
        int escribio;
        p= fopen("Deportes.dat", "ab");
        if(p==NULL) return -1;
        escribio= fwrite(this, sizeof(deporte),1,p);
        fclose(p);
        return escribio;

    }
int LeerEnDisco(int pos){
    FILE*p;
    int leyo;
    p = fopen("Deportes.dat", "rb");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(deporte),SEEK_SET);
    leyo = fread(this, sizeof(deporte), 1, p);

    fclose(p);
    return leyo;

}
    int ModificarEnDisco(int pos)
    {
        FILE*p;
        int escribio;
        p =fopen("Deportes.dat", "rb+");
        if(p==NULL) return -1;

        fseek(p, pos*sizeof(deporte), SEEK_CUR);
        escribio = fwrite(this, sizeof(deporte), 1,p);
        fclose(p);
        return escribio;



    }





};



///DECLARACIONES

void menuDeportes();
void listarDeporte();
int buscarporCod( int cod);
int listarPorcod(int cod);
int agregarDeporte(deporte aux);
int buscarPorCodigo( int codi, bool borrado=false);
int eliminarDeporte();
int listarPorInstructor();
int  modificarCuota();
int cantidadDeportes();

///DESARROLLO
int cantidadDeportes(){
    deporte aux;
    FILE * p;
    p = fopen("Deportes.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0, 2);
    int cant = ftell(p)/sizeof(deporte);
    return cant;
}

int  modificarCuota(){
    deporte reg;
    int codigo;
    float cuota;
    cout<<"INGRESE EL CODIGO DE DEPORTE"<<endl;
    cin>>codigo;
    int pos = buscarporCod(codigo);
    if(pos>=0){
        listarPorcod(codigo);
        cout<<endl;
        cout<<"INGRESE EL NUEVO VALOR DE CUOTA : ";
        cin>>cuota;
        reg.LeerEnDisco(pos);
        reg.setValorCuota(cuota);
        reg.ModificarEnDisco(pos);
        return pos;

    }
    return -1;
}

void listarDeporte()
{
    deporte aux;
    int pos=0;
    while(aux.LeerEnDisco(pos)==1)
    {
        if(aux.getEstado()==true)
        {
            aux.Mostrar();
            cout<<endl<<endl;
        }
        pos++;

    }
}



int agregarDeporte(deporte aux)
{
    int codi;
    aux.Cargar();
    codi=aux.getCodDep();
    if(buscarPorCodigo(codi)<0)
    {
        aux.GrabarEnDisco();
        return 1;
    }

    return -1;
}
int buscarPorCodigo( int codi, bool borrado)
{
    deporte aux;
    int pos=0;
    while(aux.LeerEnDisco(pos)==1)
    {
        if(aux.getCodDep()==codi)
        {
            if(aux.getEstado()==true)
            {
                return pos;
            }
            else
            {
                if(borrado==false)
                {
                    return -1;
                }
                else
                {
                    return -2;
                }
            }
        }
        pos++;
    }
    return -1;
}
void mostrarPosicion(int pos){
 deporte aux;
    if(aux.LeerEnDisco(pos)==1){
        aux.Mostrar();
    }
}
int eliminarDeporte()
{
    deporte aux;
    int codi, pos;
    char confirmo;
    const int POSMENUX = 0;
    const int POSMENUY = 0;
     cout<<"    DEPORTES    "<<endl;
    separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU+17,LETRA,FONDO);
    cout<<endl;
    cout<<"INGRESAR CODIGO DE DEPORTE: "<<endl;
    cin>>codi;
    pos=buscarporCod(codi);
    if(pos>=0){
        mostrarPosicion(pos);
        cout<<endl;
        cout<<"QUIERE ELIMINAR  EL DEPORTE?  (S/ N): "<<endl;
        cin>> confirmo;
        switch(confirmo){
        case 's':
            aux.setEstado(false);
            aux.ModificarEnDisco(pos);
            return 1;
            break;
        case 'n':  return 2;
            break;
        }

    }
    return -1;
}
int listarPorcod(int cod){
    deporte aux;
    int pos;
    pos = buscarporCod(cod);
    if(pos>=0){
        system("cls");
        aux.LeerEnDisco(pos);
        aux.Mostrar();
        return pos;
    }
    return -1;
}
int buscarporCod( int cod){
    deporte aux;
    int contador=0;
    while(aux.LeerEnDisco(contador)==1){
        if(aux.getCodDep()==cod){
            return contador;

        }
        contador++;
    }

    return -1;
}
int listarPorInstructor(){
    instructor aux;
    int pos=0, id, codep;
    cout<<"INGRESE ID DEL INSTRUCTOR : "<<endl;
    cin>>id;
    pos = buscarID(id);
    while(aux.leerEnDisco(pos)==1)
    {
        if(aux.getEstado()==true)
        {
            codep=aux.getCodigoDep();
            listarPorcod(codep);
            cout<<endl<<endl;

        }
        pos++;



    }
    return -1;




}
void submenuListarDeporte(){

    system("cls");
    deporte aux;
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
        locate(POSMENUX+14,POSMENUY+1);
        cout<<"      MENU DE LISTADOS";
        locate(POSMENUX+14,POSMENUY+4);
        cout<<" LISTAR DEPORTES ";
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" LISTAR DEPORTE POR INSTRUCTOR ";
        locate(POSMENUX+14,POSMENUY+6);
        cout<<" VOLVER AL MENU ANTERIOR";
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
    case 1:
            system("cls");
            listarDeporte();
            system("pause");

        break;
    case 2:
            system("cls");
            listarPorInstructor();
            system("pause");
        break;
    case 0: estado =false;
    break;

        }
}
}
void menuDeportes()
{
    deporte aux;
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
      locate(POSMENUX+15,POSMENUY+1);
        cout<<"      MENU DEPORTES"<<endl;
        locate(POSMENUX+15,POSMENUY+4);
        cout<<" AGREGAR DEPORTE";
        locate(POSMENUX+15,POSMENUY+5);
        cout<<" MENU DE LISTADOS";
        locate(POSMENUX+15,POSMENUY+6);
        cout<<" ELIMINAR DEPORTE ";
        locate(POSMENUX+15,POSMENUY+7);
        cout<<" MODIFICAR PAGO DE CUOTA";
        locate(POSMENUX+15,POSMENUY+8);
        cout<<" VOLVER AL MENU PRINCIPAL";

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
        switch(opc)
        {

        case 0: system("cls");
            if(agregarDeporte(aux)==1)
            {       gotoxy(46,26);
                cout<<"EL DEPORTE FUE AGREGADO CON EXITO"<<endl;
            }
            else
            {       gotoxy(46,26);
                cout<<"EL CODIGO, YA PERTENECE A UN  DEPORTE EXISTENTE"<<endl;

            }
            gotoxy(42,28);
            system("pause");


            break;
        case 1:submenuListarDeporte();
            break;
        case 2:system("cls");
            if(eliminarDeporte()==1)
            {
                cout<<"DEPORTE ELIMINADO"<<endl;
            }
            else
            {
                cout<<"NO SE ELIMINO EL DEPORTE"<<endl;
            }
            system("pause");
            break;
        case 3: system("cls");

            if(modificarCuota()>=0){cout<<"SE MODIFICO EL VALOR DE CUOTA CON EXITO "<<endl;}else{
                cout<<"NO SE PUDO MODIFICAR EL VALOR DE CUOTA "<<endl;
            }
            system("pause");

            break;
        case 4:
            estado=false;
            break;
        }

    }
    system("cls");
}

#endif // DEPORTES_H_INCLUDED
