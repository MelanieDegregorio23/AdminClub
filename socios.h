#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

void menuSocios();
class socio:public persona{
protected:
    int Id;
    Fecha Fechaingreso;
    int IdDeporte;

public:
     void setId (int i){Id=i;}
     void setFechaingreso(Fecha f){Fechaingreso=f;}
     void setIdDeporte (int d){IdDeporte=d;}
     Fecha getFechaingreso(){return Fechaingreso;}
     int getId(){return Id;}
     int getIdDeporte(){return IdDeporte;}
     void Cargar();
     void Mostrar();







};
     void Cargar();
     void Mostrar();



void menuSocios(){
    system("cls");
    int opc;
    bool estado = true;
       while (estado==true){
        system("cls");
        cout<<"MENU SOCIOS"<<endl;
        cout<<"------------------"<<endl;
        cout<<endl;
        cout<<"1. AGREGAR SOCIO"<<endl;
        cout<<"2. DAR DE BAJA SOCIO "<<endl;
        cout<<"3. INGRESAR PAGO DEL MES"<<endl;
        cout<<"4. LISTAR SOCIOS "<<endl;
        cout<<"5. LISTAR SOCIOS ALFABETICAMENTE"<<endl;
        cout<<"6. LISTAR SOCIOS POR ACTIVIDAD"<<endl;
        cout<<"7. LISTAR SOCIOS POR ID"<<endl;
        cout<<"8. LISTAR SOCIOS POR DNI"<<endl;
        cout<<"9. CONFIGURAR"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<<"INGRESE LA OPCION DESEADA: "<<endl;
        cin>>opc;
        switch(opc){
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
    case 6:
        break;
    case 7:

        break;
    case 8:
        break;
    case 9:
        break;
    case 0: estado=false;
        break;
        }

       }
}

#endif // SOCIOS_H_INCLUDED
