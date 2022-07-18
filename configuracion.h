#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void menuConfiguracion()
{

    int opc;
    bool estado = true;
    while (estado==true)
    {
        system("cls");
        cout<<" ________________________"<<endl<<endl;
        cout<<"      MENU CONFIGURACION"<<endl;
        cout<<" ________________________"<<endl<<endl;

        cout<<" 1. COPIA DE SEGURIDAD DEL ARCHIVO DE SOCIOS "<<endl;
        cout<<" 2. COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUCTORES "<<endl;
        cout<<" 3. COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS "<<endl;
        cout<<" 4. COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS"<<endl;
        cout<<" 5. COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES "<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<" INGRESE LA OPCION DESEADA: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {

        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;

        case 0: estado=false;
            break;

        }
    }
}

#endif // CONFIGURACION_H_INCLUDED
