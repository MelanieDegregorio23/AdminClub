#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#include "rlutil.h"
#include "utilidades.h"

void menuSocios();

class socio:public persona{
protected:
    int Id;
    Fecha Fechaingreso;
    int IdDeporte;



public:

    socio(int i=0, int d=0,int p={0}){

        Id=i;
        IdDeporte=d;




    }


     void setId (int i){Id=i;}
     void setFechaingreso(Fecha f){Fechaingreso=f;}
     void setIdDeporte (int d){IdDeporte=d;}
     void setNombre(const char *v){strcpy(Nombre, v);}



     Fecha getFechaingreso(){return Fechaingreso;}
     int getId(){return Id;}
     int getIdDeporte(){return IdDeporte;}



void Cargar(){
     system("cls");
     persona::Cargar();
     system("cls");
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 20;
    const int POSMENUX = 33;
    const int POSMENUY = 10;
    setColor(LETRA);
    setBackgroundColor(FONDO);
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
    separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
    locate(POSMENUX+16,POSMENUY+1);
    cout<<"DATOS DEL SOCIO: "<<endl;
     locate(POSMENUX+16,POSMENUY+5);
     cout<<"INGRESAR ID DEL SOCIO"<<endl;
     locate(POSMENUX+16,POSMENUY+6);
     cin>>Id;
     locate(POSMENUX+16,POSMENUY+7);
     cout<<"INGRESAR EL ID DEL DEPORTE:"<<endl;
     locate(POSMENUX+16,POSMENUY+8);
     cin>>IdDeporte;
     locate(POSMENUX+16,POSMENUY+9);
     cout<<"CARGAR FECHA DE INGRESO AL CLUB"<<endl;
     Fechaingreso.fechaHoy();
     Fechaingreso.Mostrar();



};
void MostrarSocio(){
        if (Estado==true){
        persona::Mostrar();
        cout<<"ID DE SOCIO: "<<endl<<Id<<endl;
        cout<<"ID DE DEPORTE: "<<endl<<IdDeporte<<endl;
        cout<<"FECHA DE INGRESO: "<<endl;
        Fechaingreso.Mostrar();
        }


};
int GrabarEnDisco(){
    FILE*p;
    int escribio;
    p= fopen("Socios.dat", "ab");
    if(p==NULL) return -1;
    escribio= fwrite(this, sizeof(socio),1,p);
    fclose(p);
    return escribio;

}
int LeerEnDisco(int pos){
    FILE*p;
    int leyo;
    p = fopen("Socios.dat", "rb");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(socio),SEEK_SET);
    leyo = fread(this, sizeof(socio), 1, p);

    fclose(p);
    return leyo;

}
int ModificarEnDisco(int pos){
    FILE*p;
    int escribio;
    p =fopen("Socios.dat", "rb+");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(socio), SEEK_CUR);
    escribio = fwrite(this, sizeof(socio), 1 ,p);
    fclose(p);
    return escribio;



}


};

///PROTOTIPOS

void menuSocios();
int agregarSocio(socio aux);
int eliminarSocio();
int buscarporDNI(int DNI);
void PagoMes();
void listarSocio();
int listarSociosPorDNI();
int buscarporId( int Id);
int listarSociosPorId(socio aux);
int contarRegistrosSocio();
void cargarArchivosocioEnVector(socio *v, int cant);
void mostrarVectorSocio(socio *v, int cant);
void listarSocioDinamico();
void ordenarSocios(socio *v, int);
void menuSociosMod();
int modificarNombreSocios();

///DESARROLLO
int modificarNombreSocios(){
    socio aux;
    int dni, pos;
    char nombre[20];

    pos = listarSociosPorDNI();
    if(pos>=0){

         cout<<"INGRESAR NUEVO NOMBRE : "<<endl;
         cin>>nombre;
         aux.LeerEnDisco(pos);
         aux.setNombre(nombre);
         aux.ModificarEnDisco(pos);
         return pos;


    }
return -1;
}

void menuSociosMod(){
    system("cls");
    socio aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ___________________________________"<<endl<<endl;
        cout<<"      MENU MODIFICACION SOCIOS"<<endl;
        cout<<" ____________________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. MODIFICAR NOMBRE"<<endl;
        cout<<" 0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1:
        system("cls");
       if( modificarNombreSocios()>=0){cout<<"MODIFICACION EXITOSA "<<endl;}else{
        cout<<"NO SE PUDO REALIZAR LA MODIFICACION "<<endl;
       }
        system("pause");
        break;
    case 0: estado =false;
    break;

        }
}
}
int agregarSocio(socio aux){
    int dni;
    cout<<"INGRESE EL DNI, DE LA PERSONA QUE QUIERE AGREGAR: "<<endl;
    cin>>dni;
    if(buscarporDNI(dni)<=0){
        aux.setdni(dni);
        aux.Cargar();
        aux.GrabarEnDisco();
        return 1;
    }
    else{
        cout<<"EL DNI, YA PERTENECE A UN SOCIO: "<<endl;
    }

    return -1;
}
int eliminarSocio(){
    socio aux;
    int dni, pos;
    cout<<"INGRESAR DNI SOCIO"<<endl;
    cin>>dni;
    pos=buscarporDNI(dni);
    if (pos>=0){
        aux.LeerEnDisco(pos);
        aux.setEstado(false);
        aux.ModificarEnDisco(pos);
        return pos;

    }
    return -1;
}
int buscarporDNI( int DNI){
    socio aux;

    int pos=0;
    while(aux.LeerEnDisco(pos)==1){
        if(aux.getDNI()==DNI){
               if(aux.getEstado()==true){

                    return pos;
                }

        }
            pos++;
    }
    return -1;
}




void listarSocio(){
    socio aux;
    int pos=0;
    while(aux.LeerEnDisco(pos)==1){
        aux.MostrarSocio();
        cout<<endl<<endl;
        pos++;
    }
}

int listarSociosPorDNI(){
    socio aux;
    int dni, pos;
    cout<<"INGRESE DNI : "<<endl;
    cin>>dni;
    pos = buscarporDNI(dni);
    if(pos>=0){
        system("cls");
        aux.LeerEnDisco(pos);
        aux.MostrarSocio();
        return pos;
    }
    return -1;
}

int buscarporId( int Id){
    socio aux;
    int contador=0;
    while(aux.LeerEnDisco(contador)==1){
        if(aux.getId()==Id){
            return contador;

        }
        contador++;
    }

    return -1;
}
int listarSociosPorId(){
    socio aux;
    int id, pos;
    cout<<"INGRESE ID : "<<endl;
    cin>>id;
    pos = buscarporId(id);
    if(pos>=0){
        system("cls");
        aux.LeerEnDisco(pos);
        aux.MostrarSocio();
        return pos;
    }
    return -1;
}
int contarRegistrosSocio(){
    int pos=0;
    socio reg;
    while(reg.LeerEnDisco(pos))pos++;
    return pos;
}
int contarRegistrosSocioBis(){
    FILE *p;
    p=fopen("Socios.dat","rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cant=ftell(p)/sizeof(socio);
    fclose(p);
    return cant;
}



void cargarArchivosocioEnVector(socio *v, int cant){
    for(int pos=0;pos<cant;pos++){
        v[pos].LeerEnDisco(pos);
    }
}

void mostrarVectorSocio(socio *v, int cant){
    for(int pos=0;pos<cant;pos++){
        v[pos].Mostrar();
        cout<<endl;
    }
}

void listarSocioDinamico(){
    int cant=contarRegistrosSocioBis();
    if(cant<=0) exit(1);
    socio *vec;
    vec=new socio[cant];
    if(vec==NULL) exit(2);
    cargarArchivosocioEnVector(vec,cant);
    ordenarSocios(vec, cant);
    mostrarVectorSocio(vec,cant);
    delete vec;
}

void ordenarSocios(socio *vec, int cantReg){
    int i, j, posMin=0;
    socio aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(strcmp(vec[j].getApellido(), vec[posMin].getApellido())<0){
               posMin=j;
               }
        }
        aux=vec[i];
        vec[i]=vec[posMin];
        vec[posMin]=aux;
    }

}




void submenuListar(){

    system("cls");
    socio aux;
    int opc;
    bool estado = true;
       while (estado==true){

        system("cls");
        cout<<" ___________________________________"<<endl<<endl;
        cout<<"      MENU DE LISTADOS"<<endl;
        cout<<" ____________________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. LISTAR SOCIOS "<<endl;
        cout<<" 2. LISTAR SOCIOS POR DNI"<<endl;
        cout<<" 3. LISTAR SOCIOS POR ID"<<endl;
        cout<<" 4. LISTAR SOCIOS ALFABETICAMENTE"<<endl;
        cout<<" 0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1:
        system("cls");
        listarSocio();
        system("pause");
        break;
         case 2:
        system("cls");
        if(listarSociosPorDNI()<0){
            cout<<"NO SE ENCONTRO CLIENTE CON EL DNI INGRESADO"<<endl;
            }
        system("pause");
        break;
            case 3:
        system("cls");
                if(listarSociosPorId()<0){
                cout<<"NO SE ENCONTRO CLIENTE CON EL ID INGRESADO"<<endl;
            }
        system("pause");
        break;
         case 4:
        system("cls");
           listarSocioDinamico();
        system("pause");
        break;
    case 0: estado =false;
    break;

        }
}
}




void menuSocios(){

    socio aux;
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
        cout<<"      MENU SOCIOS"<<endl;

        cout<<endl;
        locate(POSMENUX+15,POSMENUY+4);
        cout<<" 1. AGREGAR SOCIO"<<endl;
        locate(POSMENUX+15,POSMENUY+5);
        cout<<" 2. DAR DE BAJA SOCIO"<<endl;
        locate(POSMENUX+15,POSMENUY+6);
        cout<<" 3. MENU DE LISTADOS"<<endl;
        locate(POSMENUX+15,POSMENUY+7);
        cout<<" 4. MODIFICAR CAMPOS"<<endl;
        locate(POSMENUX+15,POSMENUY+8);
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        locate(POSMENUX+15,POSMENUY+9);
        cout<<endl;
         hidecursor();
      //cin>>opc;
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
    case 0:

        if(agregarSocio(aux)==1){
                 gotoxy(36,26);
                cout<<">>EL SOCIO FUE AGREGADO CON EXITO<<"<<endl;
        }else{

                gotoxy(36,26);
                cout<<"EL DNI, YA PERTENECE A UN  SOCIO EXISTENTE"<<endl;

        }
            gotoxy(36,28);
            system("pause");
        break;
    case 1: system("cls");
         if(eliminarSocio()>=0){
            cout<<"SOCIO ELIMINADO"<<endl;
         }else {cout<<"NO SE ENCONTRO SOCIO CON ESE DNI"<<endl;}
         system("pause");
        break;
    case 2: system("cls");
            submenuListar();
            system("pause");

        break;
    case 3:
        system("cls");
        menuSociosMod();
        system("pause");
        break;
    case 4: estado=false;
        break;
        }

       }
       system("cls");
}

#endif // SOCIOS_H_INCLUDED
