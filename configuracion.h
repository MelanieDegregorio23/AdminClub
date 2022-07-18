#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

bool backupsocio(){
    FILE *p;
    p=fopen("socios.bkp", "wb");
    if(p==NULL) return false;
    socio reg;
    int pos=0;
    while(reg.LeerEnDisco(pos)==1){
        fwrite(&reg, sizeof reg, 1, p);

        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}
bool backupinstructores(){
    FILE *p;
    p=fopen("instructores.bkp", "wb");
    if(p==NULL) return false;
    instructor reg;
    int pos=0;
    while(reg.leerEnDisco(pos)==1){
        fwrite(&reg, sizeof reg, 1, p);

        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}
bool backuparticulos(){
    FILE *p;
    p=fopen("Articulos.bkp", "wb");
    if(p==NULL) return false;
    Articulo reg;
    int pos=0;
    while(reg.leerEnDisco(pos)==1){
        fwrite(&reg, sizeof reg, 1, p);

        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}
bool backupventas(){
    FILE *p;
    p=fopen("Ventas.bkp", "wb");
    if(p==NULL) return false;
    Venta reg;
    int pos=0;
    while(reg.leerEnDisco(pos)==1){
        fwrite(&reg, sizeof reg, 1, p);

        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}
bool backupdepo(){
    FILE *p;

    p=fopen("Deportes.bkp", "wb");
    if(p==NULL) return false;
    deporte aux;
    int pos=0;
    while(aux.LeerEnDisco(pos)==1){
        fwrite(&aux, sizeof aux, 1, p);
        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}

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
            system("cls");
                if(backupsocio()) cout<<"COPIA DE SEGURIDAD DE SOCIOS REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
            system("pause");
            break;
        case 2:  system("cls");
                if(backupinstructores()) cout<<"COPIA DE SEGURIDAD  DE INSTRUCTORES REALIZADA"<<endl;
                    else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
            system("pause");
            break;
        case 3:system("cls");
                if(backuparticulos()) cout<<"COPIA DE SEGURIDAD ARTICULOS REALIZADA"<<endl;
                else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                 system("pause");
            break;
        case 4:
                system("cls");
                if( backupventas()) cout<<"COPIA DE SEGURIDAD DE VENTAS  REALIZADA"<<endl;
                else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                 system("pause");
            break;
        case 5:
               system("cls");
                if(backupdepo()==true) cout<<"COPIA DE SEGURIDAD DE DEPORTES REALIZADA"<<endl;
                else cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD"<<endl;
                 system("pause");
            break;

        case 0: estado=false;
            break;

        }
    }
}

#endif // CONFIGURACION_H_INCLUDED
