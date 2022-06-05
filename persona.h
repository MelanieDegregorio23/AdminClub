#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED



class persona{
protected:
    int DNI;
    int Edad;
    char Nombre[20];
    char Apellido[20];
    char Correo[35];
    char Telefono[15];
    Fecha fechaDeNacimiento;
public:
    void Cargar();
    void Mostar();
    void setdni(int d){DNI=d;}
    void setEdad(int e){Edad=e;}
    void setfechaDeNacimiento(Fecha f){fechaDeNacimiento=f;}
    void setNombre(const char *n){strcpy(Nombre, n);}
    void setApellido (const char *n){strcpy(Apellido,n);}
    void setCorreo(const char *n){strcpy(Correo,n);}
    void setTelefono(const char *n){strcpy(Telefono,n);}

    Fecha getfechanacimiento(){return fechaDeNacimiento;}
    int getDNI(){return DNI;}
    int getEdad(){return Edad;}
    const char *getNombre(){return Nombre;}
    const char *getApellido(){return Apellido;}
    const char *getCorreo(){return Correo;}
    const char *getTelefono(){return Telefono;}

};


void persona:Cargar(){
cout<<"INGRESAR NOMBRE : ";
cin>> cargarCadena(Nombre, 19);
cout<<"INGRESAR APELLIDO : ";
cin>>cargarCadena( Apellido, 19);
cout<<"INGRESAR DNI : ";
cin>> DNI;
cout<<"INGRESAR EDAD : ";
cin>>edad;
cout<<"INGRESAR CORREO : ";
cin>> cargarCadena( Correo, 34);
cout<<"INGRESE NUMERO DE TELEFONO :  ";
cin>>cargarCadena( Telefono, 14);
fechaDeNacimiento.cargar();
}

void persona:Mostrar(){

cout<<"NOMBRE :  "<<Nombre<<endl;
cout<<"APELLIDO :  "<<Nombre<<endl;
cout<<"DNI :  "<<Nombre<<endl;
cout<<"EDAD :  "<<Nombre<<endl;
cout<<"CORREO :  "<<Nombre<<endl;
cout<<"TELEFONO :  "<<Nombre<<endl;
fechaDeNacimiento.mostrar();

}

#endif // PERSONA_H_INCLUDED
