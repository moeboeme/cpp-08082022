#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//Estructura nodo de lista
struct jugador{
    string nombre;
    int numeroDeCamiseta;
    struct jugador* next;
};

//Un equipo es una lista de jugadores
jugador* equipo = nullptr;

//Constructor de jugadores
struct jugador* initJugador(string name, int num){
    struct jugador* ptr=new jugador;
    ptr->nombre=name;
    ptr->numeroDeCamiseta=num;
    ptr->next=nullptr;
    return ptr;
}

//Función que cuenta las ocurrencias de los jugadores cuyo nombre empieza con C
int contarOcurrenciasNameStartsWithC(){
    jugador* equipoAux = equipo;
    int counter = 0 ;
    for(;equipoAux != nullptr;equipoAux=equipoAux->next)
        if(equipoAux->nombre[0]=='C')
            counter++;
    return counter;
}

//Salida por pantalla de los datos de un jugador determinado.
void mostrarJugador(const jugador player){
    cout << "nombre: " << player.nombre <<'\t';
    cout << "Número de casaca: " << player.numeroDeCamiseta << endl;
}

//Se añade jugador a la lista
void addJugador(jugador *player){
    if(equipo==nullptr){
        equipo=player;
    }
    else{
        jugador* equipoAux=equipo;
        for(;equipoAux->next != nullptr;equipoAux=equipoAux->next)
            ; //do nothing
        equipoAux->next=player;
    }
}


void printVectorGenerico(const vector<int>& v, const string name){
    cout << "Tamaño del vector \"" << name  << "\": "<< v.size() << endl;

    vector<int>::const_iterator i;

    for(i=v.begin(); i!=v.end(); i++){
        cout << (*i) << '\t';
    }
    cout << endl;

}



int main(){
    vector meses {1,2,3,4,5,6,7,8,9,10,11,12};
    vector imparesOneDigit {1,3,5,7,9};

    jugador* juanca = initJugador("Juan Carlos", 9);
    jugador* rolfi = initJugador("Rolfi", 7);
    jugador* cacho = initJugador("Cacho", 2);
    jugador* collin = initJugador("Collin", 3);

    addJugador(juanca);
    addJugador(rolfi);
    addJugador(cacho);
    addJugador(collin);

    cout << "Cantidad de jugadores cuyo nombre empieza con C: "<<contarOcurrenciasNameStartsWithC()<<endl;

    jugador* equipoAux=equipo;
    for(;equipoAux != nullptr;equipoAux=equipoAux->next){
        mostrarJugador(*equipoAux);
    }
    
    // double *d = nullptr;

    int *p = &meses[3];

    cout << *p << '\n';
    cout << p << '\n';
    *p=int(7); // esta es la manera en la que utilizando aritmetica de punteros se modifica una posición de mem
    cout << *p << '\n';
    cout << p << '\n';

    for (auto& x: imparesOneDigit){
        x++;
    }

    printVectorGenerico(imparesOneDigit, "imparesOneDigit");

    //no tiene sentido si la función printVectorGenerico ya hace lo mismo con iterator
    printVectorGenerico(meses, "meses");
    /*for(auto& v: meses){
        cout << v << '\t';
    }
    cout << '\n';*/

}

/**
 * T a[n]; se lee, a es un vector de n T's.
    T& r; reference to T ... not address of T
    T f(a); se lee, la función que recibe un argumento de tipo 'a' devuelve un tipo T
 * 
 */