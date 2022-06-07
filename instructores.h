#ifndef INSTRUCTORES_H_INCLUDED
#define INSTRUCTORES_H_INCLUDED

class instructor: public persona{
protected:
    int IDinstructor;
    int CodigoDep;
    bool estado;
    Fecha fechaDeIngreso;

public:
    //instructor();
    void Cargar();
    void Mostrar();
    int grabarEnDisco();
    int leerEnDisco(int pos);
    ///sets();
    void setEstado(bool e){estado=e;}
    ///gets()
    int getIDinstructor(){return IDinstructor;}
    int getCodigoDep(){return CodigoDep;}
    bool getEstado(){return estado;}
    Fecha getFechaIngreso(){return fechaDeIngreso;}

};

void instructor::Cargar(){
    persona::Cargar();
    cout<< "INGRESE ID DE INSTRUCTOR : ";
    cin>>IDinstructor;
    cout<<" INGRESE CODIGO DE DEPORTE : ";
    fechaDeIngreso.Cargar();
    estado = true;
}

void instructor::Mostrar(){
    persona::Mostrar();
    cout<<"ID DE INSTRUCTOR :  "<<IDinstructor<<endl;
    cout<<"CODIGO DE DEPORTE :  "<<CodigoDep<<endl;
    fechaDeIngreso.Mostrar();
}

int  instructor::grabarEnDisco(){
    FILE*p;
    int escribio;
    p= fopen("Instructores.dat", "ab");
    if(p==NULL) return -1;
    escribio= fwrite(this, sizeof(instructor),1,p);
    fclose(p);
    return escribio;

 }

 int instructor::leerEnDisco(int pos){
    FILE*p;
    int leyo ;
    p= fopen("Instructores.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, pos*sizeof(instructor),SEEK_SET);
    leyo = fread(this, sizeof(instructor),1,p);
    fclose(p);
    return leyo;
 }


///PROTOTIPOS
void menuInstructores();
int cargarInstructor();
int buscarDNI(int dni);
///DESARROLLO



int cargarInstructor(instructor aux){
   aux.Cargar();
    int dni = aux.getDNI();
    if(buscarDNI(dni)==1){ //verifico que no exista un socio con el mismo dni
        if(aux.grabarEnDisco()==1){
            cout<<" SE REGISTRO EXITOSAMENTE"<<endl;
        }else{
            cout<<" ERROR DE REGISTRO"<<endl;
        }

    }

    return -1;

}
int buscarDNI(int dni){}


void menuInstructores(){
    system("cls");
    instructor aux;
    int opc;
    bool estado = true;
       while (estado==true){
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU INSTRUCTORES"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1. AGREGAR INSTRUCTOR "<<endl;
        cout<<" 2. DAR DE BAJA INSTRUCTOR"<<endl;
        cout<<" 3. LISTAR INSTRUCTORES"<<endl;
        cout<<" 4. LISTAR INSTRUCTORES ALFABETICAMENTE"<<endl;
        cout<<" 5. LISTAR INSCTRUCTORES POR ACTIVIDAD"<<endl;
        cout<<" 6. BUSCAR INSTRUCTOR POR ID  "<<endl;
        cout<<" 7. BUSCAR INSTRUCTOR POR DNI  "<<endl;
        cout<<" 8. CONFIGURACION  "<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1:
        system("cls");

        if( cargarInstructor(aux)==1){
            cout<<"NUEVO INSTRUCTOR REGISTRADO "<<endl;
        }else{cout<<"NO SE PUDO REGISTRAR AL INSTRUCTOR"<<endl;}


    break;
    case 2:
        break;
    case 0:
         estado=false;
    break;
        }

       }
       system("cls");
}

#endif // INSTRUCTORES_H_INCLUDED
