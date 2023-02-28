#include <iostream>
#define TAM 5

//plantillas
template <class T>

class ListaEstatica{

private:
    T datos[TAM];
    T aux[TAM];
    int ult =  1;
    T elem;
    int pos = TAM - 1;

public:
    bool operator==(const ListaEstatica<T>& otro) const { return datos == otro.datos; }
    bool operator!=(const ListaEstatica<T>& otro) const { return !(*this == otro); }
    void Inicializa(){ ult = -1; }
    int Inserta(T , int);
    int Agrega(T);
    int Buscar(T);
    int Elimina(int);
    bool Vacia()const;
    bool Llena()const;
    int Muestra();
    void Imprime()const;

};

template <class T>
int ListaEstatica<T>::Elimina(int p){
    p = p - 1;
    for(int i = p; i <= TAM - 1; i++)
    {
        datos[i] = datos[i + 1];
    }
    ult--;
    return p;
}

template <class T>
int ListaEstatica<T>::Agrega(T elem)
{
    int i = 0;
    //recorremos todos los datos para agregar el nuevo
    for(i = 0; i < TAM - 1; i++)
    {
        datos[i] = datos[i + 1];
    }
    datos[pos] = elem;

    ult++;
    return i;
}

template <class T>
int ListaEstatica<T>::Buscar(T elem){
    int i = 0;
    for(i=0; i<=TAM - 1; i++)
    {
        if(elem == datos[i])
        {
            std::cout<<"El Dato se encuentra en la posicion No.-\t"<<i + 1<<std::endl;
        }
    }
    std::cout<<"no hubo resultados en la busqueda"<<std::endl;
    return i;
}

template <class T>
void ListaEstatica<T>::Imprime()const{
    for(int i=0; i < TAM; i++)
        {
            std::cout<<"Datos Gato No.-"<<i+1<<"\t"<<datos[i]<<std::endl;
        }
}

template <class T>
bool ListaEstatica<T>::Vacia()const{
    return ult == -1;
}

template <class T>
bool ListaEstatica<T>::Llena()const{
    return ult==TAM-1;
}

template <class T>
int ListaEstatica<T>::Inserta(T elem, int p){

    if(p > TAM)
    {
        std::cout<<"no se puede insertar el objeto GatoDomestico en tal posicion"<<std::endl;
    }
    else
    {
        int i=ult+1;
        p = p -1;
        while(i>p){
            datos[i]=datos[i-1];
            i--;
        }
        datos[p]=elem;
        ult++;
        return true;
    }
    return p;

}

int main()
{
    int opc,p;
    ListaEstatica<std::string> letras;
    ListaEstatica<int> numeros;
    std::string elem;
    letras.Inicializa();
    do
    {
        std::cout<<"1. Agrega\n"
        "2. Buscar\n"
        "3. Elimina\n"
        "4. Inserta\n"
        "5. Muestra\n"
        "6. Salir\n"<<std::endl;
        std::cin>>opc;
        switch(opc)
        {
            case 1:
                if(letras.Llena())
                {
                    std::cout<<"\n No se pudo agregar. Lista llena"<<std::endl;
                }
                else
                {
                    std::cout<<"Ingrese el nuevo Gato"<<std::endl;
                    std::cin>>elem;
                    letras.Agrega(elem);
                }
            break;

            case 2:
                if(letras.Vacia())
                {
                    std::cout<<"La lista no tiene elementos guardados aun."<<std::endl;
                }
                else
                {
                    std::cout<<"Ingrese el Gato a buscar"<<std::endl;
                    std::cin>>elem;
                    letras.Buscar(elem);
                }
            break;

            case 3:
                if(letras.Vacia())
                {
                    std::cout<<"La lista no tiene elementos guardados aun"<<std::endl;
                }
                else
                {
                    std::cout<<"Dame el GatoDomestico a eliminar"<<std::endl;
                    std::cin>>p;
                    letras.Elimina(p);
                }
            break;

            case 4:
                if(letras.Llena())
                {
                    std::cout<<"No se pudo insertar por que la lista esta llena"<<std::endl;
                }
                else
                {
                    std::cout<<"Dame el GatoDomestico a insertar"<<std::endl;
                    std::cin>>elem;
                    std::cout<<"Dame la posicion donde se debe insertar el objeto GatoDomestico"<<std::endl;
                    std::cin>>p;
                    letras.Inserta(elem, p);
                }
            break;

            case 5:
                if(!letras.Vacia())
                {
                    letras.Imprime();
                }
                else
                {
                    std::cout<<"Lista vacia"<<std::endl;
                }
            break;

            case 6:
                std::cout<<"Saliendo del programa"<<std::endl;
                system("exit");
            break;
        }

    }while(opc < 6);


}
