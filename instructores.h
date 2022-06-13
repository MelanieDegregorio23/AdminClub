#ifndef INSTRUCTORES_H_INCLUDED
#define INSTRUCTORES_H_INCLUDED

class instructor: public persona{
protected:
    int IDinstructor;
    int CodigoDep;
    bool estado;
    Fecha fechaDeIngreso;

public:
    instructor(bool e=1 ){ estado =e;}
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
        if(estado == 1){
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


    ///sets
    void setEstado(bool e){estado=e;}
    ///gets()
    int getIDinstructor(){return IDinstructor;}
    int getCodigoDep(){return CodigoDep;}
    bool getEstado(){return estado;}
    Fecha getFechaIngreso(){return fechaDeIngreso;}

};





///PROTOTIPOS
void menuInstructores();
int cargarInstructor();
int buscarDNI(int dni);
int buscarID(int id);
int  listarInstructores(instructor aux);
int eliminarInstructor(instructor aux);

///DESARROLLO
int eliminarInstructor(instructor aux){
    system("cls");
    int id, pos;
    cout<<"INGRESE ID DE INSTRUCTOR :  ";
    cin>>id;
    // (IDEA ) mostrar el instructor correspondiente a ese id y pedir confirmación
    system("pause");
    pos = buscarID(id);
    if(pos>=0){
        aux.setEstado(0);
        aux.modificarEnDisco(pos);
        return 1;
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


int cargarInstructor(instructor aux){
    int dni;
    aux.Cargar();
    dni = aux.getDNI();
    if(buscarDNI(dni)>0){
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
        system("pause");

    break;
    case 2:
        if(eliminarInstructor(aux)==1){
            cout<<"INSTRUCTOR ELIMINADO"<<endl;
            system("pause");
        }else{
            cout<<"ERROR AL ELIMINAR INSTRUCTOR"<<endl;
            system("pause");
        }

        break;
    case 3:
        system("cls");
       if( listarInstructores(aux)==0){
        cout<<"NO HAY INSTRUCTORES REGISTRADOS "<<endl;
       }
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
