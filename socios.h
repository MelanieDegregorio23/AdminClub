#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

void menuSocios();

class socio:public persona{
protected:
    int Id;
    Fecha Fechaingreso;
    int IdDeporte;
    int PagosMes[12];


public:

    socio(int i=0, int d=0,int p={0}){

        Id=i;
        IdDeporte=d;
        PagosMes[12]=p;



    }
     void Cargar();
     void MostrarSocio();
     int GrabarEnDisco();
     int LeerEnDisco(int pos);
     int ModificarEnDisco(int pos);
     void PagoMes();

     void setId (int i){Id=i;}
     void setFechaingreso(Fecha f){Fechaingreso=f;}
     void setIdDeporte (int d){IdDeporte=d;}
     void setPagosMes (int p){PagosMes[12]=p;}



     Fecha getFechaingreso(){return Fechaingreso;}
     int getId(){return Id;}
     int getIdDeporte(){return IdDeporte;}
     int getPagosMes(){return PagosMes[12];}





};
void socio::Cargar(){
     system("cls");
     persona::Cargar();
     cout<<"INGRESAR ID DEL SOCIO"<<endl;
     cin>>Id;
     cout<<endl;
     cout<<"INGRESAR EL ID DEL DEPORTE AL QUE ESTA INSCRIPTO"<<endl;
     cin>>IdDeporte;
     cout<<endl;
     cout<<"CARGAR FECHA DE INGRESO AL CLUB"<<endl;
     Fechaingreso.Cargar();



};
void socio::MostrarSocio(){
        if (Estado==true){
        persona::Mostrar();
        cout<<"ID DE SOCIO: "<<endl<<Id<<endl;
        cout<<"ID DE DEPORTE: "<<endl<<IdDeporte<<endl;
        cout<<"FECHA DE INGRESO: "<<endl;
        Fechaingreso.Mostrar();
        }


};
int socio::GrabarEnDisco(){
    FILE*p;
    int escribio;
    p= fopen("Socios.dat", "ab");
    if(p==NULL) return -1;
    escribio= fwrite(this, sizeof(socio),1,p);
    fclose(p);
    return escribio;

}
int socio::LeerEnDisco(int pos){
    FILE*p;
    int leyo;
    p = fopen("Socios.dat", "rb");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(socio),SEEK_SET);
    leyo = fread(this, sizeof(socio), 1, p);

    fclose(p);
    return leyo;

}
int socio::ModificarEnDisco(int pos){
    FILE*p;
    int escribio;
    p =fopen("Socios.dat", "rb+");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(socio), SEEK_CUR);
    escribio = fwrite(this, sizeof(socio), 1 ,p);
    fclose(p);
    return escribio;



}
void menuSocios();
int agregarSocio(socio aux);
int eliminarSocio();
int buscarporDNI(int DNI, bool borrado=false);
void PagoMes();
void listarSocio();
int listarSociosPorDNI(socio aux);
int buscarporId( int Id);
int listarSociosPorId(socio aux);





int agregarSocio(socio aux){
    int dni;
    aux.Cargar();
    dni=aux.getDNI();
    if(buscarporDNI(dni)<0){///si encuentra que no esta el dni, lo carga y lo agrega
        aux.GrabarEnDisco();
        return 1;
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
int buscarporDNI( int DNI, bool borrado){
    socio aux;

    int pos=0;
    while(aux.LeerEnDisco(pos)==1){
        if(aux.getDNI()==DNI){
               if(aux.getEstado()==true){
                    return pos;
                }
                else{
                    if(borrado==false){
                        return -1;
                    }
                    else{
                        return -2;
                    }
                }
            }
            pos++;
    }
    return -1;
}

void socio::PagoMes(){
     cout<<"INGRESAR PAGO MENSUAL"<<endl;
     cin>>PagosMes[12];
     ///llamar a deportes mel hace esta funcion.
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




void menuSocios(){
    system("cls");
    socio aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU SOCIOS"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. AGREGAR SOCIO"<<endl;
        cout<<" 2. DAR DE BAJA SOCIO "<<endl;
        cout<<" 3. INGRESAR PAGO DEL MES"<<endl;
        cout<<" 4. LISTAR SOCIOS "<<endl;
        cout<<" 5. LISTAR SOCIOS POR DNI"<<endl;
        cout<<" 6. LISTAR SOCIOS POR ID"<<endl;
        cout<<" 7. LISTAR SOCIOS ALFABETICAMENTE"<<endl;
        cout<<" 8. CONFIGURAR"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1: if(agregarSocio(aux)==1){
                cout<<"EL SOCIO FUE AGREGADO CON EXITO";
        }else{
                cout<<"EL DNI, YA PERTENECE A UN  SOCIO EXISTENTE";

        }
            system("pause");
        break;
    case 2: system("cls");
         if(eliminarSocio()>=0){
            cout<<"SOCIO ELIMINADO";
         }else {cout<<"NO SE ENCONTRO CLIENTE CON ESE DNI"<<endl;}
         system("pause");
        break;
    case 3:/*system("cls");
            socio aux;
            PagoMes();

            system("pause");*/

        break;
    case 4: system("cls");
            listarSocio();
            system("pause");
        break;
    case 5: system("cls");
            if(listarSociosPorDNI()<0){
                cout<<"NO SE ENCONTRO CLIENTE CON EL DNI INGRESADO"<<endl;
            }
            system("pause");

        break;
    case 6:system("cls");
        if(listarSociosPorId()<0){
                cout<<"NO SE ENCONTRO CLIENTE CON EL DNI INGRESADO"<<endl;
            }
            system("pause");

        break;
    case 7:

        break;
    case 8:
        break;

    case 0: estado=false;
        break;
        }

       }
       system("cls");
}

#endif // SOCIOS_H_INCLUDED
