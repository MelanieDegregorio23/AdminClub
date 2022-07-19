#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


class Fecha{
    private:///sólo era accesible desde dentro de la clase
        int dia, mes, anio;///propiedades o variables de la clase
    public:///accesible dentro y fuera de la clase
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }
        void Mostrar();
        void Cargar();
        void fechaHoy();
        ///gets()
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///sets()
        void setDia(int d){dia=d;}
        void setMes(int m){if(m>=1 && m<=12) mes=m;}
        void setAnio(int a){anio=a;}
        ~Fecha(){};
};

void Fecha::Mostrar(){
    ///cout<<this<<endl;

    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}

void Fecha::fechaHoy(){
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    dia = fecha->tm_mday;
    mes = fecha->tm_mon+1;
    anio = fecha->tm_year+1900;
    //cout<<dia<<"/"<<mes<<"/"<<anio<<endl;

}

void Fecha::Cargar(){
    int d;
    locate(POSMENUX+16,POSMENUY+10);
    cout<<"DIA: ";
    locate(POSMENUX+16,POSMENUY+11);
    cin>>d;
    setDia(d);
    locate(POSMENUX+16,POSMENUY+12);
    cout<<"MES: ";
    locate(POSMENUX+16,POSMENUY+13);
    cin>>d;
    setMes(d);
    locate(POSMENUX+16,POSMENUY+14);
    cout<<"ANIO: ";
    locate(POSMENUX+16,POSMENUY+15);
    cin>>d;
    setAnio(d);
}

///PROTIPOS
int  generarEdad(Fecha x);
int calcularEdad(Fecha actual, Fecha y);

///DESARROLLO
int calcularEdad(Fecha actual, Fecha y){
     int edad = actual.getAnio() - y.getAnio();
    if(actual.getMes() < y.getMes()){
        edad = edad -1;
    }else if(actual.getDia() < y.getDia()){
        edad = edad -1;
    }
   return edad;
}

int generarEdad(Fecha x){
    Fecha actual;
    actual.fechaHoy();
   int edad = calcularEdad(actual, x);
   // cout<<"EDAD : "<<edad<<endl;
   return edad;

}



#endif // FECHA_H_INCLUDED
