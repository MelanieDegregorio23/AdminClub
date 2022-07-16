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

void Fecha::Cargar(){
    int d;
    locate(POSMENUX+16,POSMENUY+17);
    cout<<"DIA: ";
    locate(POSMENUX+16,POSMENUY+18);
    cin>>d;
    setDia(d);
    locate(POSMENUX+16,POSMENUY+19);
    cout<<"MES: ";
    locate(POSMENUX+16,POSMENUY+20);
    cin>>d;
    setMes(d);
    locate(POSMENUX+16,POSMENUY+21);
    cout<<"ANIO: ";
    locate(POSMENUX+16,POSMENUY+22);
    cin>>d;
    setAnio(d);
}



#endif // FECHA_H_INCLUDED
