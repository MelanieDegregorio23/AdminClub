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
        const int ANCHO_MENU = 50;
        const int ALTO_MENU = 20;
        const int POSMENUX = 33;
        const int POSMENUY = 3;
        system("cls");
        setColor(LETRA);
        setBackgroundColor(FONDO);
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+18,POSMENUY+1);
        cout<<"INSTRUCTOR";
        locate(POSMENUX+16,POSMENUY+4);
         cout<<"FECHA DE INGRESO: ";
         locate(POSMENUX+16,POSMENUY+5);
        fechaDeIngreso.fechaHoy();
        fechaDeIngreso.Mostrar();
        locate(POSMENUX+16,POSMENUY+6);
        cout<< "INGRESE ID DE INSTRUCTOR : ";
        locate(POSMENUX+16,POSMENUY+7);
        cin>>IDinstructor;
        locate(POSMENUX+16,POSMENUY+8);
        cout<<"INGRESE CODIGO DE DEPORTE : ";
        locate(POSMENUX+16,POSMENUY+9);
        cin>>CodigoDep;


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
void submenuListarInstructores();


///DESARROLLO
int modificarApellidoInstructores(){
    instructor aux;
    int dni, pos;
    char apellido[20];
    separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU+17,LETRA,FONDO);
    locate(POSMENUX+20,POSMENUY+1);
    cout<<"DATOS DEL INSTRUCTOR";
    locate(POSMENUX+16,POSMENUY+4);
    cout<<"INGRESAR DNI DEL INSTRUCTOR : ";
    cin>>dni;
    pos = buscarDNI(dni);
    if(pos>=0)
    {
        locate(POSMENUX+16,POSMENUY+5);
        cout<<"INGRESAR NUEVO APELLIDO : ";
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
    int key, cursorX, cursorY;
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 10;
    while (estado==true)
    {
        cursorX=POSMENUX+11;
        cursorY=POSMENUY + 4;
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        opc=0;
        system("cls");
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+14,POSMENUY+1);
        cout<<"MENU MODIFICACION INSTRUCTORES";
        locate(POSMENUX+14,POSMENUY+4);

        cout<<" MODIFICAR APELLIDO";
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" VOLVER AL MENU ANTERIOR";
        locate(POSMENUX+12,POSMENUY+4);

        hidecursor();
        locate(cursorX,cursorY);
        cout<<">>";
        key = getkey();
        while(key != KEY_ENTER)
        {
            locate(cursorX,cursorY);
            cout<<" ";
            cout<<" ";
            switch(key)
            {
            case KEY_DOWN:
                if(opc < 1)
                {
                    opc++;
                }
                else
                {
                    opc=0;
                }
                break;
            case KEY_UP:
                if(opc > 1)
                {
                    opc--;
                }
                else
                {
                    opc=0;
                }
                break;
            }
            if(opc != 0)
            {
                cursorY = opc + POSMENUY + 4;
            }
            else
            {
                cursorY = POSMENUY + 4;
            }
            locate(cursorX,cursorY);
            cout<<">>";
            key = getkey();
        }
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        showcursor();


        switch(opc)
        {
        case 0:
            system("cls");
            if( modificarApellidoInstructores()>=0)
            {
                gotoxy(49,10);
                cout<<"MODIFICACION EXITOSA "<<endl;
            }
            else
            {
                gotoxy(49,10);

                cout<<"NO SE PUDO REALIZAR LA MODIFICACION "<<endl;
            }
            gotoxy(49,12);
            system("pause");
            break;
        case 1:
            estado =false;
            break;

        }
    }
}
void mostrarVectorInstructor( instructor *v, int cant){
    for(int pos=0; pos<cant; pos++)
    {
        v[pos].Mostrar();
        cout<<endl;
    }
}

void ordenarInstructor(instructor *vec, int cantReg){
    int i, j, posMin=0;
    instructor aux;
    for(i=0; i<cantReg-1; i++)
    {
        posMin=i;
        for(j=i+1; j<cantReg; j++)
        {
            if(strcmp(vec[j].getApellido(), vec[posMin].getApellido())<0)
            {
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
    while(aux.leerEnDisco(pos)==1)
    {
        if(aux.getCodigoDep()==codigo)
        {
            cout<<"INSTRUCTOR N"<<(char)186<<contador+1<<endl;
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
        cout<<"INSTRUCTOR N"<<(char)186<<aux.getIDinstructor()<<endl;
        cout<<"--------------- "<<endl;
        aux.Mostrar();
        cout<<"--------------- "<<endl;
        cout<<endl;
    }
}

void listarPorID( instructor aux){
    int id, pos;
    cout<<"INGRESE EL ID DEL INSTRUCTOR QUE DECIA BUSCAR : ";
    cin>>id;
    system("cls");
    pos = buscarID(id);
    if(pos>=0)
    {
        mostrarPorPosicion(pos, aux);

    }
    else
    {
        cout<<"NO SE ENCONTRO INSTRUCTOR CON ESE ID "<<endl;
    }

}

void  listarPorDNI( instructor aux){
    int dni, pos;
    cout<<"INGRESE EL DNI DEL INSTRUCTOR QUE DECIA BUSCAR : ";
    cin>>dni;
    system("cls");
    pos = buscarDNI(dni);
    if(pos>=0)
    {
        mostrarPorPosicion(pos, aux);

    }
    else
    {
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
    if(pos>=0)
    {
        mostrarPorPosicion(pos, aux);
        cout<<endl;
        cout<<"QUIERE ELIMINAR ESTE INSTRUCTOR ?  (S / N) ";
        cin>> confirmo;
        switch(confirmo)
        {
        case 's':
            aux.setEstado(false);
            aux.modificarEnDisco(pos);
            return 1;
            break;
        case 'n':
            return 2;
            break;
        }

    }
    return -1;
}

int buscarID(int id)
{
    instructor aux;
    int pos = 0;
    while(aux.leerEnDisco(pos)==1)
    {
        if(aux.getIDinstructor()==id)
        {
            return pos;
        }

        pos++;
    }
    return -1;
}


int listarInstructores(instructor aux){
    int pos=0, lectura=0, contador=0;
    while(aux.leerEnDisco(pos)==1)
    {
        lectura =1;
        if(aux.getEstado()==1)
        {
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
    separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU+17,LETRA,FONDO);
    locate(POSMENUX+20,POSMENUY+1);
    cout<<"DATOS DEL INSTRUCTOR";
    locate(POSMENUX+12,POSMENUY+5);
    cout<<"INGRESE EL DNI DE LA PERSONA QUE QUIERE AGREGAR: ";
    locate(POSMENUX+12,POSMENUY+7);
    cout<<"DNI: ";
    cin>>dni;
    if(buscarDNI(dni)<0)
    {
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
    while(aux.leerEnDisco(pos)==1)
    {
        if(aux.getDNI()==dni)
        {
            return pos;

        }

        pos++;
    }
    return -1;
}




void submenuListarInstructores(){

    system("cls");
    instructor aux;
    const int ANCHO_MENU = 52;
    const int ALTO_MENU = 13;
    bool estado = true;
    int key, opc, cursorX, cursorY;
    while (estado==true)
    {
        cursorX=POSMENUX+13;
        cursorY=POSMENUY + 4;
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        opc=0;
        setColor(LETRA);
        setBackgroundColor(FONDO);
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+18,POSMENUY+1);
        cout<<"MENU DE LISTADOS"<<endl;
        locate(POSMENUX+15,POSMENUY+4);

        cout<<" LISTAR INSTRUCTORES"<<endl;
        locate(POSMENUX+15,POSMENUY+5);
        cout<<" LISTAR INSTRUCTORES ALFABETICAMENTE"<<endl;
        locate(POSMENUX+15,POSMENUY+6);///
        cout<<" LISTAR INSCTRUCTORES POR ACTIVIDAD"<<endl;
        locate(POSMENUX+15,POSMENUY+7);
        cout<<" LISTAR INSTRUCTOR POR ID  "<<endl;
        locate(POSMENUX+15,POSMENUY+8);
        cout<<" LISTAR INSTRUCTOR POR DNI  "<<endl;
        locate(POSMENUX+15,POSMENUY+9);
        cout<<" VOLVER AL MENU ANTERIOR"<<endl;
        locate(POSMENUX+15,POSMENUY+10);
        hidecursor();
        locate(cursorX,cursorY);
        cout<<">>";
        key = getkey();
        while(key != KEY_ENTER)
        {
            locate(cursorX,cursorY);
            cout<<" ";
            cout<<" ";
            switch(key)
            {
            case KEY_DOWN:
                if(opc < 5)
                {
                    opc++;
                }
                else
                {
                    opc=0;
                }
                break;
            case KEY_UP:
                if(opc > 5)
                {
                    opc--;
                }
                else
                {
                    opc=0;
                }
                break;
            }
            if(opc != 0)
            {
                cursorY = opc + POSMENUY + 4;
            }
            else
            {
                cursorY = POSMENUY + 4;
            }
            locate(cursorX,cursorY);
            cout<<">>";
            key = getkey();
        }
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        showcursor();

        switch(opc)
        {
        case 0:
            system("cls");
            if( listarInstructores(aux)==0)
            {
                cout<<"NO HAY INSTRUCTORES REGISTRADOS "<<endl;
            }
            system("pause");
            break;
        case 1:
            system("cls");
            listarInstrucDinamico();
            system("pause");
            break;

        case 2:
            system("cls");
            listarPorActividad(aux);
            system("pause");
            break;
        case 3:
            system("cls");
            listarPorID(aux);
            system("pause");
            break;
        case 4:
            system("cls");
            listarPorDNI(aux);
            system("pause");
            break;
        case 5:
            estado =false;
            break;

        }
    }
}


void menuInstructores(){
    instructor aux;
    const int ANCHO_MENU = 50;
    const int ALTO_MENU = 10;
    bool estado = true;
    int key, opc, cursorX, cursorY;
    while (estado==true)
    {
        cursorX=POSMENUX+13;
        cursorY=POSMENUY + 4;
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        opc=0;
        setColor(LETRA);
        setBackgroundColor(FONDO);
        recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
        separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
        locate(POSMENUX+18,POSMENUY+1);
        cout<<"MENU INSTRUCTORES"<<endl;
        locate(POSMENUX+15,POSMENUY+4);
        cout<<" AGREGAR INSTRUCTOR "<<endl;
        locate(POSMENUX+15,POSMENUY+5);
        cout<<" DAR DE BAJA INSTRUCTOR"<<endl;
        locate(POSMENUX+15,POSMENUY+6);
        cout<<" MENU DE LISTADOS"<<endl;
        locate(POSMENUX+15,POSMENUY+7);
        cout<<" MODIFICAR CAMPOS "<<endl;
        locate(POSMENUX+15,POSMENUY+8);
        cout<<" VOLVER AL MENU PRINCIPAL"<<endl;
        locate(POSMENUX+15,POSMENUY+9);

        hidecursor();
        locate(cursorX,cursorY);
        cout<<">>";
        key = getkey();
        while(key != KEY_ENTER)
        {
            locate(cursorX,cursorY);
            cout<<" ";
            cout<<" ";
            switch(key)
            {
            case KEY_DOWN:
                if(opc < 4)
                {
                    opc++;
                }
                else
                {
                    opc=0;
                }
                break;
            case KEY_UP:
                if(opc > 4)
                {
                    opc--;
                }
                else
                {
                    opc=0;
                }
                break;
            }
            if(opc != 0)
            {
                cursorY = opc + POSMENUY + 4;
            }
            else
            {
                cursorY = POSMENUY + 4;
            }
            locate(cursorX,cursorY);
            cout<<">>";
            key = getkey();
        }
        setBackgroundColor(COLOR_PANTALLA);
        cls();
        showcursor();
        switch(opc)
        {
        case 0:
            system("cls");

            if( cargarInstructor(aux)==1)
            {
                gotoxy(46,15);
                cout<<"NUEVO INSTRUCTOR REGISTRADO "<<endl;
            }
            else
            {
                gotoxy(46,15);
                cout<<"NO SE PUDO REGISTRAR AL INSTRUCTOR"<<endl;
            }
            gotoxy(42,17);
            system("pause");

            break;
        case 1:
            if(eliminarInstructor(aux)==1)
            {
                cout<<"INSTRUCTOR ELIMINADO"<<endl;
                system("pause");
            }
            else
            {
                cout<<"NO SE PUDO ELIMINAR AL INSTRUCTOR"<<endl;
                system("pause");
            }

            break;
        case 2:
            submenuListarInstructores();

            break;
        case 3:
            system("cls");
            menuInstructoresMod();
            system("pause");
            break;
        case 4:
            estado=false;
            break;
        }

    }
    system("cls");
}

#endif // INSTRUCTORES_H_INCLUDED
