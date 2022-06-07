#ifndef INSTRUCTORES_H_INCLUDED
#define INSTRUCTORES_H_INCLUDED

void menuInstructores();

void menuInstructores(){
    system("cls");
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
        cout<<" 6. BUSCAR INSTRUCTOR POR ID : "<<endl;
        cout<<" 7. BUSCAR INSTRUCTOR POR DNI : "<<endl;
        cout<<" 8. CONFIGURACION : "<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
    case 1:

        break;
    case 2:
        break;
    case 0: estado=false;
        break;
        }

       }
       system("cls");
}

#endif // INSTRUCTORES_H_INCLUDED
