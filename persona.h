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

    Fecha getfechanacimiento(){return fechaDeNacimiento;}
    int getDNI(){return DNI;}
    int getEdad(){return Edad;}
    const char *getNombre(){return Nombre;}
    const char *getApellido(){return Apellido;}
    const char *getCorreo(){return Correo;}
    const char *getTelefono(){return Telefono;}

};


void persona::Cargar(){
    cout<<"INGRESAR NOMBRE : ";
    cargarCadena(Nombre, 19);
    cout<<"INGRESAR APELLIDO : ";
    cargarCadena(Apellido, 19);
    cout<<"INGRESAR DNI : ";
    cin>> DNI;
    cout<<"INGRESAR EDAD : ";
    cin>>Edad;
    cout<<"INGRESAR CORREO : ";
    cargarCadena(Correo, 34);
    cout<<"INGRESE NUMERO DE TELEFONO :  ";
    cargarCadena(Telefono, 14);
    fechaDeNacimiento.Cargar();
}

void persona::Mostrar(){

cout<<"NOMBRE :  "<<Nombre<<endl;
cout<<"APELLIDO :  "<<Nombre<<endl;
cout<<"DNI :  "<<Nombre<<endl;
cout<<"EDAD :  "<<Nombre<<endl;
cout<<"CORREO :  "<<Nombre<<endl;
cout<<"TELEFONO :  "<<Nombre<<endl;
fechaDeNacimiento.Mostrar();

}

#endif // PERSONA_H_INCLUDED
