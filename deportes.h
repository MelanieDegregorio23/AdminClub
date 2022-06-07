#ifndef DEPORTES_H_INCLUDED
#define DEPORTES_H_INCLUDED

void menuDeportes();

void menuDeportes(){
    system("cls");
    int opc;
    bool estado = true;
       while (estado==true){
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU DEPORTES"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1. "<<endl;
        cout<<" 2. "<<endl;
        cout<<" 3. "<<endl;
        cout<<" 4. "<<endl;
        cout<<" 5. "<<endl;
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

#endif // DEPORTES_H_INCLUDED
