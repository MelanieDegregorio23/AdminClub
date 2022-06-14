#ifndef DEPORTES_H_INCLUDED
#define DEPORTES_H_INCLUDED
class deporte{
private:
    int CodDep;
    int CantCupos;
    float ValorCuota;
    bool Estado;
    char Descripcion [30];
    char Horario[20];
public:
    deporte(int cd=0, int c=0, float v=0, const char *d="No existe en la base de datos", const char *h="No existe en la base de datos", bool e=true){
    CodDep=cd;
    CantCupos=c;
    ValorCuota=v;
    strcpy(Descripcion, d);
    strcpy(Horario,h);
    Estado=e;
}


void Cargar(){
     system("cls");
     cout<<"INGRESAR CODIGO DE DEPORTE"<<endl;
     cin>>CodDep;
     cout<<endl;
     cout<<"INGRESAR CANTIDAD DE CUPOS"<<endl;
     cin>>CantCupos;
     cout<<endl;
     cout<<"DESCRIPCION DEL DEPORTE"<<endl;
     cin>>Descripcion;
     cout<<"INGRESAR EL HORARIO EN EL QUE SE DICTAN LAS CLASES"<<endl;
     cin>>Horario;



};
void Mostrar(){
        if (Estado==true){
        cout<<"CODIGO DE DEPORTE: "<<endl<<CodDep<<endl;
        cout<<"CANTIDAD DE CUPOS: "<<endl<<CantCupos<<endl;
        cout<<"DESCRIPCION: "<<endl<<Descripcion<<endl;
        cout<<"HORARIO DE CLASES: "<<endl<<Horario<<endl;
        }


};
int GrabarEnDisco(){
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
int ModificarEnDisco(int pos){
    FILE*p;
    int escribio;
    p =fopen("Deportes.dat", "rb+");
    if(p==NULL) return -1;

    fseek(p, pos*sizeof(deporte), SEEK_CUR);
    escribio = fwrite(this, sizeof(deporte), 1 ,p);
    fclose(p);
    return escribio;



}
    void setCodDep (int cd){CodDep=cd;}
    void setCantCupos (int c){CantCupos=c;}
    void setValorCuota (float v){ValorCuota=v;}
    void setDescripcion (const char *d){strcpy(Descripcion,d);}
    void setHorario(const char *h){strcpy(Horario,h);}
    void setEstado (bool e){Estado=e;}

    int getCodDep() {return CodDep;}
    int getCantCupos(){return CantCupos;}
    float getValorCuota(){return ValorCuota;}
    const char *getDescripcion (){return Descripcion;}
    const char *getHorario(){return Horario;}
    bool getEstado(){return Estado;}




};





void menuDeportes();
void listarDeporte();
int agregarDeporte(deporte aux);
int buscarPorCodigo( int codi, bool borrado=false);
int eliminarDeporte();



void listarDeporte(){
    deporte aux;
    int pos=0;
    while(aux.LeerEnDisco(pos)==1){
        if(aux.getEstado()==true){
        aux.Mostrar();
        cout<<endl<<endl;
        }
        pos++;

    }
}



int agregarDeporte(deporte aux){
    int codi;
    aux.Cargar();
    codi=aux.getCodDep();
    if(buscarPorCodigo(codi)<0){///si encuentra que no esta el dni, lo carga y lo agrega
        aux.GrabarEnDisco();
        return 1;
    }

    return -1;
}
int buscarPorCodigo( int codi, bool borrado){
    deporte aux;
    int pos=0;
    while(aux.LeerEnDisco(pos)==1){
        if(aux.getCodDep()==codi){
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
int eliminarDeporte(){
    deporte aux;
    int codi, pos;
    cout<<"INGRESAR CODIGO DE DEPORTE"<<endl;
    cin>>codi;
    pos=buscarPorCodigo(codi);
    if (pos>=0){
        aux.LeerEnDisco(pos);
        aux.setEstado(false);
        aux.ModificarEnDisco(pos);
        return pos;

    }
    return -1;
}
void menuDeportes(){

    deporte aux;
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU DEPORTES"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1. LISTAR DEPORTES "<<endl;
        cout<<" 2. LISTAR DEPORTES ALFABETICAMENTE "<<endl;
        cout<<" 3. LISTAR DEPORTE POR INSTRUCTOR "<<endl;
        cout<<" 4. AGREGAR DEPORTE"<<endl;
        cout<<" 5. ELIMINAR DEPORTE "<<endl;
        cout<<" 6. CONFIGURACION"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        system("cls");
        switch(opc){

    case 1:system("cls");
            listarDeporte();
            system("pause");

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:system("cls");
         if(agregarDeporte(aux)==1){
                cout<<"EL DEPORTE FUE AGREGADO CON EXITO"<<endl;
        }else{
                cout<<"EL CODIGO, YA PERTENECE A UN  DEPORTE EXISTENTE"<<endl;

        }
        system("pause");
        break;
    case 5: system("cls");
         if(eliminarDeporte()>=0){
            cout<<"DEPORTE ELIMINADO"<<endl;
         }else {cout<<"NO SE ENCONTRO DEPORTE CON ESE CODIGO"<<endl;}
         system("pause");
        break;
    case 6:
        break;
    case 0: estado=false;
        break;
        }

       }
       system("cls");
}

#endif // DEPORTES_H_INCLUDED
