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
        cout<<"INGRESAR CODIGO DE DEPORTE"<<endl;
        cin>>CodDep;
        cout<<endl;
        cout<<"NOMBRE DE DEPORTE"<<endl;
        cargarCadena(Descripcion, 29);
        cout<<"INGRESAR CANTIDAD DE CUPOS"<<endl;
        cin>>CantCupos;
        cout<<endl;
        cout<<"AGREGAR VALOR DE CUOTA"<<endl;
        cin>>ValorCuota;
        cout<<"INGRESAR EL HORARIO EN EL QUE SE DICTAN LAS CLASES"<<endl;
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
int eliminarDeporte()
{
    deporte aux;
    int codi, pos;
    cout<<"INGRESAR CODIGO DE DEPORTE"<<endl;
    cin>>codi;
    pos=buscarPorCodigo(codi);
    if (pos>=0)
    {
        aux.LeerEnDisco(pos);
        aux.setEstado(false);
        aux.ModificarEnDisco(pos);
        return pos;

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
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<" ___________________________________"<<endl<<endl;
        cout<<"      MENU DE LISTADOS"<<endl;
        cout<<" ____________________________________"<<endl<<endl;

        cout<<endl;
        cout<<" 1. LISTAR DEPORTES "<<endl;
        cout<<" 2. LISTAR DEPORTE POR INSTRUCTOR "<<endl;
        cout<<" 0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
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
    int opc;
    bool estado = true;
    while (estado==true)
    {
        system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU DEPORTES"<<endl;
        cout<<" ________________________"<<endl<<endl;


        cout<<" 1. AGREGAR DEPORTE"<<endl;
        cout<<" 2. MENU DE LISTADOS"<<endl;
        cout<<" 3. ELIMINAR DEPORTE "<<endl;
        cout<<" 4. MODIFICAR PAGO DE CUOTA"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {

        case 1: system("cls");
            if(agregarDeporte(aux)==1)
            {
                cout<<"EL DEPORTE FUE AGREGADO CON EXITO"<<endl;
            }
            else
            {
                cout<<"EL CODIGO, YA PERTENECE A UN  DEPORTE EXISTENTE"<<endl;

            }
            system("pause");


            break;
        case 2:submenuListarDeporte();
            break;
        case 3:system("cls");
            if(eliminarDeporte()>=0)
            {
                cout<<"DEPORTE ELIMINADO"<<endl;
            }
            else
            {
                cout<<"NO SE ENCONTRO DEPORTE CON ESE CODIGO"<<endl;
            }
            system("pause");
            break;
        case 4: system("cls");

            if(modificarCuota()>=0){cout<<"SE MODIFICO EL VALOR DE CUOTA CON EXITO "<<endl;}else{
                cout<<"NO SE PUDO MODIFICAR EL VALOR DE CUOTA "<<endl;
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

#endif // DEPORTES_H_INCLUDED
