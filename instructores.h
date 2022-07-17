#ifndef INSTRUCTORES_H_INCLUDED
#define INSTRUCTORES_H_INCLUDED

class instructor: public persona{
protected:
    int IDinstructor;
    int CodigoDep;
    Fecha fechaDeIngreso;

public:
    void Cargar(){
        persona::Cargar();
        cout<< "INGRESE ID DE INSTRUCTOR : ";
        cin>>IDinstructor;
        ///deberian aparecer los deportes disponibles con sus respectivos códigos
        cout<<" INGRESE CODIGO DE DEPORTE : ";
        cin>>CodigoDep;
        cout<<"INGRESE FECHA DE INGRESO: "<<endl;
        fechaDeIngreso.Cargar();

    }
    void Mostrar(){
        if(Estado == true){
        persona::Mostrar();
        cout<<"ID DE INSTRUCTOR :  "<<IDinstructor<<endl;
        cout<<"CODIGO DE DEPORTE :  "<<CodigoDep<<endl;
        cout<<"FECHA DE INGRESO : ";
        fechaDeIngreso.Mostrar();

        }

    }
    int grabarEnDisco(){
        FILE*p;
        int escribio;
        p= fopen("Instructores.dat", "ab");
        if(p==NULL) return -1;
        escribio= fwrite(this, sizeof(instructor),1,p);
        fclose(p);
        return escribio;
    }
    int leerEnDisco(int pos){
         FILE*p;
        int leyo ;
        p= fopen("Instructores.dat", "rb");
        if(p==NULL)return -1;
        fseek(p, pos*sizeof(instructor),SEEK_SET);
        leyo = fread(this, sizeof(instructor),1,p);
        fclose(p);
        return leyo;
    }
    int modificarEnDisco(int pos){
        FILE*p;
        int escribio;
        p = fopen("Instructores.dat" , "rb+");
        if( p==NULL)return -1;
        fseek(p, pos*sizeof(instructor),SEEK_SET);
        escribio= fwrite(this, sizeof(instructor),1, p);
        fclose(p);
        return escribio;
    }


    ///sets()
    ///gets()
    int getIDinstructor(){return IDinstructor;}
    int getCodigoDep(){return CodigoDep;}
    Fecha getFechaIngreso(){return fechaDeIngreso;}

};





///PROTOTIPOS
void mostrarVectorInstructor( instructor *v, int cant);
void ordenarInstructor(instructor *vec, int cantReg);
void cargarArchivoInstructorVector(instructor *v, int cant);
int CantidadRegistrosInstructores();
void listarInstrucDinamico();
void menuInstructores();
int cargarInstructor(instructor aux);
int buscarDNI(int dni);
int buscarID(int id);
int listarInstructores(instructor aux);
int eliminarInstructor(instructor aux);
void listarPorDNI( instructor aux);
void listarPorID( instructor aux);
void mostrarPorPosicion(int pos);
void listarPorActividad(instructor aux);
int modificarApellidoInstructores();
void menuInstructoresMod();


///DESARROLLO
int modificarApellidoInstructores(){
 instructor aux;
    int dni, pos;
    char apellido[20];

    cout<<"INGRESAR DNI DEL INSTRUCTOR : ";
    cin>>dni;
    pos = buscarDNI(dni);
    if(pos>=0){

         cout<<"INGRESAR NUEVO APELLIDO : "<<endl;
         cin>>apellido;
         aux.leerEnDisco(pos);
         aux.setApellido(apellido);
         aux.modificarEnDisco(pos);
         return pos;


    }
return -1;
}

void menuInstructoresMod(){
    system("cls");
    socio aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ___________________________________"<<endl<<endl;
        cout<<"     MENU MODIFICACION INSTRUCTORES"<<endl;
        cout<<" ____________________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. MODIFICAR APELLIDO"<<endl;
        cout<<" 0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1:
        system("cls");
       if( modificarApellidoInstructores()>=0){cout<<"MODIFICACION EXITOSA "<<endl;}else{
        cout<<"NO SE PUDO REALIZAR LA MODIFICACION "<<endl;
       }
        system("pause");
        break;
    case 0: estado =false;
    break;

        }
}
}
void mostrarVectorInstructor( instructor *v, int cant){
    for(int pos=0;pos<cant;pos++){
        v[pos].Mostrar();
        cout<<endl;
    }
}

void ordenarInstructor(instructor *vec, int cantReg){
    int i, j, posMin=0;
    instructor aux;
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


void cargarArchivoInstructorVector(instructor *v, int cant){
    for(int pos=0;pos<cant;pos++){
        v[pos].leerEnDisco(pos);
    }
}


int CantidadRegistrosInstructores(){
    int pos=0;
    instructor reg;
    while(reg.leerEnDisco(pos))pos++;
    return pos;
}

void listarInstrucDinamico(){
    int cant = CantidadRegistrosInstructores();
    if(cant<=0) exit(1);
    instructor *vec;
    vec=new instructor[cant];
    if(vec==NULL) exit(2);
    cargarArchivoInstructorVector(vec,cant);
    ordenarInstructor(vec, cant);
    mostrarVectorInstructor(vec,cant);
    delete vec;
}

void listarPorActividad(instructor aux){
    system("cls");
    int codigo, pos=0, contador=0;
    ///(IDEA) MOSTRAR LOS DEPORTES ACTUALES Y SUS CODIGOS
    cout<<"INGRESAR CODIGO DE ACTIVIDAD : "<<endl;
    cin>>codigo;
    system("cls");
    while(aux.leerEnDisco(pos)==1){
            if(aux.getCodigoDep()==codigo){
                cout<<"INSTRUCTOR N"<<(char)167<<contador+1<<endl;
                cout<<"--------------- "<<endl;
                aux.Mostrar();
                cout<<"--------------- "<<endl;
                cout<<endl;
                contador++;
            }
        pos++;
    }



}

void mostrarPorPosicion(int pos, instructor aux){

    if(aux.leerEnDisco(pos)==1){
        aux.Mostrar();
    }
}

void listarPorID( instructor aux){
     int id, pos;
    cout<<"INGRESE EL ID DEL INSTRUCTOR QUE DECIA BUSCAR : ";
    cin>>id;
    system("cls");
    pos = buscarID(id);
    if(pos>=0){
        mostrarPorPosicion(pos, aux);

    }else{
        cout<<"NO SE ENCONTRO INSTRUCTOR CON ESE ID "<<endl;
    }

}

void  listarPorDNI( instructor aux){
    int dni, pos;
    cout<<"INGRESE EL DNI DEL INSTRUCTOR QUE DECIA BUSCAR : ";
    cin>>dni;
    system("cls");
    pos = buscarDNI(dni);
    if(pos>=0){
        mostrarPorPosicion(pos, aux);

    }else{
        cout<<"NO SE ENCONTRO INSTRUCTOR CON ESE DNI "<<endl;
    }

}

int eliminarInstructor(instructor aux){
    system("cls");
    int id, pos;
    char confirmo;
    cout<<"INGRESE ID DE INSTRUCTOR :  ";
    cin>>id;
    pos = buscarID(id);
    if(pos>=0){
        mostrarPorPosicion(pos, aux);
        cout<<endl;
        cout<<"QUIERE ELIMINAR ESTE INSTRUCTOR ?  (s / n) ";
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

    } else{
        cout<<"NO HAY INSTRUCTORES CON EL ID INGRESADO"<<endl;
    };
    return -1;
}

    int buscarID(int id){
    instructor aux;
    int pos = 0;
    while(aux.leerEnDisco(pos)==1){
        if(aux.getIDinstructor()==id){
            return pos;
        }

        pos++;
    }
    return -1;
}


int listarInstructores(instructor aux){
    int pos=0, lectura=0, contador=0;
    while(aux.leerEnDisco(pos)==1){
        lectura =1;
        if(aux.getEstado()==1){
        cout<<"INSTRUCTOR N"<<(char)167<<contador+1<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;
        cout<<endl;
        contador++;

        }
        pos++;
    }



    return lectura;
}


int cargarInstructor(instructor aux){ ///HASTA EL MOMENTO NO PERMITE AGREGAR INSTRUCTORES QUE YA FUERON ELIMINADOS
    int dni;
    cout<<"INGRESAR DNI : ";
    cin>>dni;
    if(buscarDNI(dni)<0){
        aux.setdni(dni);
        aux.Cargar();
        aux.grabarEnDisco();
        return 1;
    }
    return -1;
}


int buscarDNI(int dni){
    instructor aux;
    int pos = 0;
    while(aux.leerEnDisco(pos)==1){
        if(aux.getDNI()==dni){
         return pos;

        }

        pos++;
    }
    return -1;
}




void submenuListarInstructores(){

    system("cls");
    instructor aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ___________________________________"<<endl<<endl;
        cout<<"      MENU DE LISTADOS"<<endl;
        cout<<" ____________________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. LISTAR INSTRUCTORES"<<endl;
        cout<<" 2. LISTAR INSTRUCTORES ALFABETICAMENTE"<<endl;///
        cout<<" 3. LISTAR INSCTRUCTORES POR ACTIVIDAD"<<endl;
        cout<<" 4. LISTAR INSTRUCTOR POR ID  "<<endl;
        cout<<" 5. LISTAR INSTRUCTOR POR DNI  "<<endl;
        cout<<" 0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1:
        system("cls");
       if( listarInstructores(aux)==0){
        cout<<"NO HAY INSTRUCTORES REGISTRADOS "<<endl;
       }
        system("pause");
        break;
         case 2:
        system("cls");
        listarInstrucDinamico();
        system("pause");
        break;
        break;
            case 3:
        system("cls");
        listarPorActividad(aux);
        system("pause");
        break;
         case 4:
         system("cls");
        listarPorID(aux);
        system("pause");
        break;
        case 5:
        system("cls");
        listarPorDNI(aux);
        system("pause");
        break;
    case 0: estado =false;
    break;

        }
}
}


void menuInstructores(){
    instructor aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"    MENU INSTRUCTORES"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1. AGREGAR INSTRUCTOR "<<endl;
        cout<<" 2. DAR DE BAJA INSTRUCTOR"<<endl;
        cout<<" 3. MENU DE LISTADOS"<<endl;
        cout<<" 4. MODIFICAR CAMPOS "<<endl;
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
        system("pause");

    break;
    case 2:
        if(eliminarInstructor(aux)>0){
            cout<<"INSTRUCTOR ELIMINADO"<<endl;
            system("pause");
        }else{
            cout<<"ERROR AL ELIMINAR INSTRUCTOR"<<endl;
            system("pause");
        }

        break;
    case 3:submenuListarInstructores();

        break;
    case 4:
        system("cls");
        menuInstructoresMod();
        system("pause");
        break;
    case 0:
         estado=false;
    break;
        }

       }
       system("cls");
}

#endif // INSTRUCTORES_H_INCLUDED
