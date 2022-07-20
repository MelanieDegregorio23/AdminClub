#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
///prototipos
bool backupsocio();
bool backupinstructores();
bool backuparticulos();
bool backupventas();
bool backupdepo();
bool backupPagos();

///desarrollo
bool backupsocio(){
    FILE *p;
    p=fopen("socios.bkp", "wb");
    if(p==NULL) return false;
    socio reg;
    int pos=0;
    while(reg.LeerEnDisco(pos)==1)
    {
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
    while(reg.leerEnDisco(pos)==1)
    {
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
    while(reg.leerEnDisco(pos)==1)
    {
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
    while(reg.leerEnDisco(pos)==1)
    {
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
    while(aux.LeerEnDisco(pos)==1)
    {
        fwrite(&aux, sizeof aux, 1, p);
        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}
bool backupPagos(){
    FILE *p;

    p=fopen("Pagos.bkp", "wb");
    if(p==NULL) return false;
    pagos aux;
    int pos=0;
    while(aux.LeerEnDisco(pos)==1)
    {
        fwrite(&aux, sizeof aux, 1, p);
        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}

void menuConfiguracion()
{
    const int ANCHO_MENU = 65;
    const int ALTO_MENU = 14;
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
        locate(POSMENUX+22,POSMENUY+1);
        cout<<"MENU CONFIGURACION";
        locate(POSMENUX+14,POSMENUY+4);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE SOCIOS."<<endl;
        locate(POSMENUX+14,POSMENUY+5);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUCTORES."<<endl;
        locate(POSMENUX+14,POSMENUY+6);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS."<<endl;
        locate(POSMENUX+14,POSMENUY+7);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS."<<endl;
        locate(POSMENUX+14,POSMENUY+8);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES."<<endl;
        locate(POSMENUX+14,POSMENUY+9);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE PAGOS."<<endl;
        locate(POSMENUX+14,POSMENUY+10);
        cout<<" VOLVER AL MENU PRINCIPAL."<<endl;
        locate(POSMENUX+13,POSMENUY+11);
        cout<<endl;
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
                if(opc < 6)
                {
                    opc++;
                }
                else
                {
                    opc=0;
                }
                break;
            case KEY_UP:
                if(opc > 6)
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
            separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
            locate(POSMENUX+25,POSMENUY+1);
            cout<<"BACKUP SOCIO";
            if(backupsocio())
            {
                gotoxy(46,6);
                cout<<"COPIA DE SEGURIDAD DE SOCIOS REALIZADA."<<endl;
            }
            else
            {
                gotoxy(46,6);
                cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD."<<endl;
            }
            gotoxy(46,9);
            system("pause");
            break;
        case 1:
            system("cls");
            separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
            locate(POSMENUX+25,POSMENUY+1);
            cout<<"BACKUP INSTRUCTORES";
            if(backupinstructores())
            {
                gotoxy(46,6);
                cout<<"COPIA DE SEGURIDAD  DE INSTRUCTORES REALIZADA."<<endl;
            }
            else
            {
                gotoxy(46,6);
                cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD."<<endl;
            }
            gotoxy(46,9);
            system("pause");
            break;
        case 2:
            system("cls");
            separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
            locate(POSMENUX+25,POSMENUY+1);
            cout<<"BACKUP ARTICULOS";
            if(backuparticulos())
            {
                gotoxy(46,6);
                cout<<"COPIA DE SEGURIDAD ARTICULOS REALIZADA."<<endl;
            }
            else
            {
                gotoxy(46,6);
                cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD."<<endl;
            }
            gotoxy(46,9);
            system("pause");
            break;
        case 3:
            system("cls");
            separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
            locate(POSMENUX+25,POSMENUY+1);
            cout<<"BACKUP VENTAS";
            if( backupventas())
            {
                gotoxy(46,6);
                cout<<"COPIA DE SEGURIDAD DE VENTAS  REALIZADA."<<endl;
            }
            else
            {
                gotoxy(46,6);
                cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD."<<endl;
            }
            gotoxy(46,9);
            system("pause");
            break;
        case 4:
            system("cls");
            separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
            locate(POSMENUX+25,POSMENUY+1);
            cout<<"BACKUP DEPORTES";
            if(backupdepo()==true)
            {
                gotoxy(46,6);
                cout<<"COPIA DE SEGURIDAD DE DEPORTES REALIZADA."<<endl;
            }

            else
            {
                gotoxy(46,6);
                cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD."<<endl;
            }
            gotoxy(46,9);
            system("pause");
            break;
        case 5:
            system("cls");
            separadorx(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
            locate(POSMENUX+24,POSMENUY+1);
            cout<<"BACKUP PAGOS COUTA";
            if(backupPagos()==true)
            {
                gotoxy(46,6);
                cout<<"COPIA DE SEGURIDAD DE PAGOS REALIZADA."<<endl;
            }

            else
            {
                gotoxy(46,6);
                cout<<"NO SE PUDO HACER LA COPIA DE SEGURIDAD."<<endl;
            }
            gotoxy(46,9);
            system("pause");
            break;

        case 6:
            estado=false;
            break;

        }
    }
}

#endif // CONFIGURACION_H_INCLUDED
