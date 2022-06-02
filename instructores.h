#ifndef INSTRUCTORES_H_INCLUDED
#define INSTRUCTORES_H_INCLUDED

void menuInstructores();

void menuInstructores(){
    system("cls");
    int opc;
    bool estado = true;
       while (estado==true){
        cout<<"1. "<<endl;
        cout<<"2. "<<endl;
        cout<<"3. "<<endl;
        cout<<"4. "<<endl;
        cout<<"5. "<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<"INGRESE LA OPCION DESEADA: "<<endl;
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
}

#endif // INSTRUCTORES_H_INCLUDED
