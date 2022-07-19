#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "rlutil.h"
#include "utilidades.h"


class persona{
protected:
    int DNI;
    int Edad;
    char Nombre[20];
    char Apellido[20];
    char Correo[35];
    char Telefono[15];
    bool Estado=true;
    Fecha fechaDeNacimiento;
public:
    personas(int d=0, int e=0, const char *n="No existe en la base de datos", const char *a="No existe en la base de datos", const char *c="No existe en la base de datos", const char *t="No existe en la base de datos"){
    DNI=d;
    Edad=e;
    strcpy(Nombre, n);
    strcpy(Apellido,a);
    strcpy(Correo,c);
    strcpy (Telefono,c);
}

    void Cargar();
    void Mostrar();
    void setdni(int d){DNI=d;}
    void setEdad(int e){Edad=e;}
    void setfechaDeNacimiento(Fecha f){fechaDeNacimiento=f;}
    void setNombre(const char *n){strcpy(Nombre, n);}
    void setApellido (const char *a){strcpy(Apellido,a);}
    void setCorreo(const char *c){strcpy(Correo,c);}
    void setTelefono(const char *t){strcpy(Telefono,t);}
    void setEstado(bool es){Estado=es;}



    Fecha getfechanacimiento(){return fechaDeNacimiento;}
    int getDNI(){return DNI;}
    int getEdad(){return Edad;}

    const char *getNombre(){return Nombre;}
    const char *getApellido(){return Apellido;}
    const char *getCorreo(){return Correo;}
    const char *getTelefono(){return Telefono;}
    bool getEstado() {return Estado;}

};


void persona::Cargar(){
    const int ANCHO_MENU = 52;
    const int ALTO_MENU = 30;
    setColor(LETRA);
    setBackgroundColor(FONDO);
    recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
    separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
    locate(POSMENUX+16,POSMENUY+1);
    cout<<"CARGA DE DATOS: "<<endl;
    locate(POSMENUX+16,POSMENUY+4);
    cout<<"INGRESAR NOMBRE : ";
    locate(POSMENUX+16,POSMENUY+5);
    cargarCadena(Nombre, 19);
    locate(POSMENUX+16,POSMENUY+6);
    cout<<"INGRESAR APELLIDO : ";
    locate(POSMENUX+16,POSMENUY+7);
    cargarCadena(Apellido, 19);
    locate(POSMENUX+16,POSMENUY+8);
    cout<<"INGERSAR FECHA DE NACIMIENTO : ";
    locate(POSMENUX+16,POSMENUY+9);
    fechaDeNacimiento.Cargar();
    locate(POSMENUX+16,POSMENUY+16);
    Edad = generarEdad(fechaDeNacimiento);
    cout<<"EDAD : "<<Edad;
    locate(POSMENUX+16,POSMENUY+17);
    cout<<"INGRESAR CORREO : ";
    locate(POSMENUX+16,POSMENUY+18);
    cargarCadena(Correo, 34);
    locate(POSMENUX+16,POSMENUY+19);
    cout<<"INGRESE NUMERO DE TELEFONO :  ";
    locate(POSMENUX+16,POSMENUY+20);
    cargarCadena(Telefono, 14);


}

void persona::Mostrar(){

        if(Estado==true){
            cout<<"NOMBRE :  "<<Nombre<<endl;
            cout<<"APELLIDO :  "<<Apellido<<endl;
            cout<<"DNI :  "<<DNI<<endl;
            cout<<"EDAD :  "<<Edad<<endl;
            cout<<"CORREO :  "<<Correo<<endl;
            cout<<"TELEFONO :  "<<Telefono<<endl;
            cout<<"FECHA DE NACIMIENTO: ";
            fechaDeNacimiento.Mostrar();
            cout<<endl<<endl;




    }

}


#endif // PERSONA_H_INCLUDED
