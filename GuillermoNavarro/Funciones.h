#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///         FUNCIONES PRINCIPALES:

void MenuPrincipal();                                                    /// Dirije a partida para un jugador, dos jugadores o salir.
void MenuJugadores(string&, int&, int&, string&, int&, int&, int);       /// Segun el 'tipo'. para '0' dirije a un jugador, para '1' dirije a dos jugadores.
int Partida(string&, int&, int&, string&, int&, int&, int);             /// Segun el 'tipo'. para '0' dirije a partida de un jugador, para '1' dirije a partida de dos jugadores.
bool PartidaLanzamiento(string, int[], int&, int&, int&, int&, int&);   /// Contiene la interfaz del juego usada para uno o dos jugadores, es usada desde 'Partida(...).' y escribe en las variables que recibe.

/*-----------------------------------------------------------*/
//          Lanzamiento y evaluaciones:
void Lanzamiento(int[]);
bool EvaluarEscalera(int[]);
void MostrarPuntajeDados(int[]);
int PuntajeLanzamiento(int[]);

/*-----------------------------------------------------------*/
//          Carteles:
void InterfazPartida(string, int, int, int, int, int);
void EntreTurno(string, int, int, string, int, int, int&, int);
/*-----------------------------------------------------------*/
//          Animaciones:
int AnimacionesPantallaMenu(int);
void AnimacionesNombre(string&, string&, int);
void AnimacionesEntreTurnos(int);
void AnimacionesEscalera(string);
void AnimacionesGanarPartida(string);
void bailarin(int);
void MostrarDados(int[]);
void AnimacionesMenuSecundario(string, int, int, string, int, int, int);
void BenjaD();
/*-----------------------------------------------------------*/
///         Funcion final:
void Firma();
/*-----------------------------------------------------------*/



///         FUNCIONES PRINCIPALES:

///             Menu principal:

void MenuPrincipal(){/// Dirije a partida para un jugador, dos jugadores o salir.

// Variables para poder escribirlas en funciones UnJugador y DosJugadores:
    string nombreJugador;
    int numeroRonda, maximoPuntajeRonda;
    // Segundo jugador:
    string nombreJugadorDos;
    int numeroRondaDos, maximoPuntajeRondaDos;
    numeroRonda=maximoPuntajeRonda=numeroRondaDos=maximoPuntajeRondaDos=0;

    int eleccion;

    rlutil::hidecursor();

    do {

    AnimacionesPantallaMenu(0);               // Logo Quinientos!
    eleccion=AnimacionesPantallaMenu(1);      // Imprime Menu rincipal.

        switch (eleccion) {
            case 1:
                system("cls");
                // Funcion que dirige a un jugador:
                MenuJugadores(nombreJugador, numeroRonda, maximoPuntajeRonda,
                              nombreJugadorDos, numeroRondaDos, maximoPuntajeRondaDos, 0);  // Tipo '0';
                break;
            case 2:
                // Dos jugadores:
                system("cls");
                // Funcion que dirige a dos jugadores:
                MenuJugadores(nombreJugador, numeroRonda, maximoPuntajeRonda,
                              nombreJugadorDos, numeroRondaDos, maximoPuntajeRondaDos, 1);  // Tipo '1';
                break;
            case 3:
                // Gracias Benja!:
                system("cls");
                BenjaD();
                break;
            case 4:
                // PRUEBAS:
                system("cls");
                // Espacio de pruebas:
//                AnimacionesEntreTurnos(1);
                break;
            case 0:
                // Salir:
                system("cls");
                break;
            default:
                // Salir:
                system("cls");
                break;
        }
    } while (eleccion != 0);
}


void MenuJugadores(string& nombreJugador, int& numeroRonda, int& maximoPuntajeRonda,
                  string& nombreJugadorDos, int& numeroRondaDos, int& maximoPuntajeRondaDos, int tipo){/// Segun el 'tipo'. para '0' dirije a un jugador, para '1' dirije a dos jugadores.

    int eleccion;

    if(tipo==0){///                                     Menu un jugador.

        do {
            eleccion=AnimacionesPantallaMenu(2);

            switch (eleccion) {
                case 1:                 // iniciar partida.
                        system("cls");
                        Partida(nombreJugador, numeroRonda, maximoPuntajeRonda,
                                nombreJugadorDos, numeroRondaDos, maximoPuntajeRondaDos, 0);         // Tipo '0'.
                    break;
                case 2:                 // Puntaje maximo.
                        system("cls");
                        AnimacionesMenuSecundario(nombreJugador, numeroRonda, maximoPuntajeRonda,
                                                  nombreJugador, numeroRonda, maximoPuntajeRonda, 0); // tipo '0'.
                    break;
                case 3:                 // Salon escalera!.
                        system("cls");
                        AnimacionesMenuSecundario(nombreJugador, numeroRonda, maximoPuntajeRonda,
                                                  nombreJugador, numeroRonda, maximoPuntajeRonda, 1); // tipo '1'.
                    break;
                case 4:                 // Reglas para un jugador.
                        system("cls");
                        AnimacionesMenuSecundario(nombreJugador, numeroRonda, maximoPuntajeRonda,
                                                  nombreJugador, numeroRonda, maximoPuntajeRonda, 2); // tipo '2'.
                    break;
                case 0:
                        system("cls");
                    break;
                default:
                        system("cls");
                    break;
            }
        } while (eleccion != 0);
    }


    if(tipo==1){///                                     Menu dos Jugadores.

        do {

            eleccion=AnimacionesPantallaMenu(3);

            switch (eleccion) {
                case 1:                 // iniciar partida:
                    system("cls");
                    Partida(nombreJugador, numeroRonda, maximoPuntajeRonda,
                            nombreJugadorDos, numeroRondaDos, maximoPuntajeRondaDos, 1);    // Tipo '1'.
                    break;
                case 2:                 // Puntaje maximo:
                    system("cls");
                    AnimacionesMenuSecundario(nombreJugador, numeroRonda, maximoPuntajeRonda,
                                              nombreJugadorDos, numeroRondaDos, maximoPuntajeRondaDos, 3); // tipo '3'.
                    break;
                case 3:                 // Salon escalera!:
                        system("cls");
                        AnimacionesMenuSecundario(nombreJugador, numeroRonda, maximoPuntajeRonda,
                                                  nombreJugadorDos, numeroRondaDos, maximoPuntajeRondaDos, 4); // tipo '4'.
                    break;
                case 4:                 // Reglas para dos jugadores:
                        system("cls");
                        AnimacionesMenuSecundario(nombreJugador, numeroRonda, maximoPuntajeRonda,
                                                  nombreJugadorDos, numeroRondaDos, maximoPuntajeRondaDos, 2); // tipo '2'.
                    break;
                case 0:
                    system("cls");
                    break;
            }

        } while (eleccion != 0);
    }
}

int Partida(string& nombreJugador, int& numeroRonda, int& maximoPuntajeRonda,
            string& nombreJugadorDos, int& numeroRondaDos, int& maximoPuntajeRondaDos, int tipo){/// Segun el 'tipo'. para '0' dirije a partida de un jugador, para '1' dirije a partida de dos jugadores.

    int puntajeActual, puntajeTotal, lanzamiento;
    int puntajeActualDos, puntajeTotalDos, lanzamientoDos;

    puntajeActual=puntajeTotal=0;
    numeroRonda=lanzamiento=1;
    puntajeActualDos=puntajeTotalDos=0;
    numeroRondaDos=lanzamientoDos=1;

    const int dados=6;
    int cubilete[dados];
    int contadorTurnos=1;

    int puntajeGanador=500;

    maximoPuntajeRonda=0;
    maximoPuntajeRondaDos=0;

    bool partidaEnCurso=true;

    if(tipo==0){ ///                                 Partida para un jugador.

        AnimacionesNombre(nombreJugador, nombreJugador, 0);

        while(partidaEnCurso){

///---- Jugador uno ---------------------------------------------------------------------------------------------------------------+

            while(PartidaLanzamiento(nombreJugador, cubilete, numeroRonda, puntajeActual, puntajeTotal, maximoPuntajeRonda, lanzamiento));

            lanzamiento=1;

            if(EvaluarEscalera(cubilete)) return 0; /// Caso de escalera.

            puntajeTotal+=maximoPuntajeRonda;

            if(puntajeTotal>=puntajeGanador){AnimacionesGanarPartida(nombreJugador); return 0;} /// Caso de alcanzar puntaje ganador.

            numeroRonda++;

            puntajeTotalDos=500;    /// Bandera para que 'EntreTurno' reciba que el juego es para un jugador.

            EntreTurno(nombreJugador, numeroRonda, puntajeTotal, nombreJugadorDos, numeroRondaDos, puntajeTotalDos, contadorTurnos, maximoPuntajeRonda);
        }
    }



    if(tipo==1){ ///                                 Partida para dos jugadores.

        AnimacionesNombre(nombreJugador, nombreJugadorDos, 1);

        while(partidaEnCurso){

///---- Jugador uno ---------------------------------------------------------------------------------------------------------------+

            while(PartidaLanzamiento(nombreJugador, cubilete, numeroRonda, puntajeActual, puntajeTotal, maximoPuntajeRonda, lanzamiento));

            lanzamiento=1;

            if(EvaluarEscalera(cubilete)) return 0; /// Caso de escalera.

            puntajeTotal+=maximoPuntajeRonda;

            if(puntajeTotal>=puntajeGanador){AnimacionesGanarPartida(nombreJugador); return 0;} /// Caso de alcanzar puntaje ganador.

            numeroRonda++;

            EntreTurno(nombreJugador, numeroRonda, puntajeTotal, nombreJugadorDos, numeroRondaDos, puntajeTotalDos, contadorTurnos, maximoPuntajeRonda);

///---- Jugador dos ---------------------------------------------------------------------------------------------------------------+


            while(PartidaLanzamiento(nombreJugadorDos, cubilete, numeroRondaDos, puntajeActualDos, puntajeTotalDos, maximoPuntajeRondaDos, lanzamientoDos));

            lanzamientoDos=1;

            if(EvaluarEscalera(cubilete)) return 0; /// Escalera.

            puntajeTotalDos+=maximoPuntajeRondaDos;

            if(puntajeTotalDos>=puntajeGanador){AnimacionesGanarPartida(nombreJugadorDos); return 0;}   /// Puntaje ganador.

            numeroRondaDos++;

            EntreTurno(nombreJugador, numeroRonda, puntajeTotal, nombreJugadorDos, numeroRondaDos, puntajeTotalDos, contadorTurnos, maximoPuntajeRondaDos);

        }
    }
    return 0;
}

bool PartidaLanzamiento(string nombreJugador, int cubilete[], int& numeroRonda, int& puntajeActual, int& puntajeTotal, int& maximoPuntajeRonda, int& lanzamiento){/// Contiene la interfaz del juego usada para uno o dos jugadores, es usada desde 'Partida(...).' y escribe en las variables que recibe.

    system("cls");

    InterfazPartida(nombreJugador, numeroRonda, puntajeActual, puntajeTotal, maximoPuntajeRonda, lanzamiento);

    Lanzamiento(cubilete);

    MostrarDados(cubilete);

    if(EvaluarEscalera(cubilete)){AnimacionesEscalera(nombreJugador); maximoPuntajeRonda=500/* <--------- Bandera para habilitar 'Salon Escalera!' */; return false;}

    MostrarPuntajeDados(cubilete);

    rlutil::anykey();

    lanzamiento++;

    if(PuntajeLanzamiento(cubilete)==-1){maximoPuntajeRonda=0;}// Sexteto seis.

    if(PuntajeLanzamiento(cubilete)>maximoPuntajeRonda)maximoPuntajeRonda=PuntajeLanzamiento(cubilete);

    if(lanzamiento>3) return false;

}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
///                                                                                                         Lanzamiento y evaluaciones:


void Lanzamiento(int cubilete[]){

    const int dados=6;
    char lanzar;
    int ColumnaX, filaY;

    ColumnaX=16;
    filaY=17;

    gotoxy(ColumnaX, filaY);
        cout<<"      _       \n";
    filaY++;
    gotoxy(ColumnaX, filaY);
        cout<<"    _|_|_     \n";
    filaY++;
    gotoxy(ColumnaX, filaY);
        cout<<"    (o o)     \n";
    filaY++;
    gotoxy(ColumnaX, filaY);
        cout<<"ooO--(_)--Ooo- Presiona una tecla para lanzar!";
    rlutil::anykey(lanzar);

    srand(time(nullptr));

    for(int i=0; i<dados; i++){                                                 // Carga aleatorio el cubilete.
        cubilete[i]=((rand()+lanzar)%6)+1;
    }

    for(int i=0; i<dados-1; i++){                                               // Ordena el cubilete.
        int posicionMinima=i;
        for(int j=i+1;j<dados;j++){
            if(cubilete[j]<cubilete[posicionMinima]) posicionMinima=j;
        }
        int auxiliar=cubilete[i];
        cubilete[i]=cubilete[posicionMinima];
        cubilete[posicionMinima]=auxiliar;
    }

/// ------------------> Pruebas de valor:

///                       Suma de dados:
//    for(int i=0; i<2; i++)cubilete[i]=1; for(int i=2; i<4; i++)cubilete[i]=2; for(int i=4; i<6; i++)cubilete[i]=3;
///                       Trio X:
    for(int i=0; i<3; i++)cubilete[i]=1; for(int i=3; i<6; i++)cubilete[i]=5;
///                       Dos trio X:
//    cubilete[0]=cubilete[1]=cubilete[2]=1;
//    cubilete[3]=cubilete[4]=cubilete[5]=2;
///                       Sexteto X:
//    for(int i=0; i<6; i++)cubilete[i]=5;
///                       Sexteto Seis:
//    for(int i=0; i<6; i++)cubilete[i]=6;
///                       Escalera!:
//    int valor=1; for(int i=0; i<dados; i++){cubilete[i]=valor; valor++;}
}

bool EvaluarEscalera(int cubilete[]){

    const int dados=6;
    int contadorEscalera=1;
    for(int i=0; i<dados; i++){if(cubilete[i]==contadorEscalera)contadorEscalera++;}
    if(contadorEscalera==7){return true;} else{return false;}
}



void MostrarPuntajeDados(int cubilete[]){

    if(PuntajeLanzamiento(cubilete)==-1){gotoxy(10, 15);cout<<" Sexteto seis! Pierdes todos los puntos de la ronda! _o/_/_";}
    else cout<<"Puntaje: "<<PuntajeLanzamiento(cubilete);
}

int PuntajeLanzamiento(int cubilete[]){

    const int dados=6;
    int numeroDadoPuntaje=0;;
    int puntaje=0;
    int contador = 0;
    int evaluarCubilete[dados];





       for(int i=0; i<dados; i++){             // Cargar vector evaluarCubilete a 0
            evaluarCubilete[i]=0;
        }

        /*for(int=0; i<dados; i++){

            evaluarCubilete[cubilete[i]-1++;

        }*/


        for(int i=0; i<dados; i++){             // contar dados en evaluarCubilete

            switch(cubilete[i]){
        case 1:
            evaluarCubilete[0]++;
            break;
        case 2:
            evaluarCubilete[1]++;
            break;
        case 3:
            evaluarCubilete[2]++;
            break;
        case 4:
            evaluarCubilete[3]++;
            break;
        case 5:
            evaluarCubilete[4]++;
            break;
        case 6:
            evaluarCubilete[5]++;
            break;
            }
        }

        // Si se da dos trio 'X' entonces se borra el primer trio para no contabilizar:
        int contadorDobleTrio=0;
        int posicionPrimerTrio, posicionSegundoTrio, bandera;
        bandera=0;
        for(int i=0; i<dados; i++){
            if (evaluarCubilete[i]==3 && bandera==0){contadorDobleTrio++; posicionPrimerTrio=i; bandera=1;}
            else if (evaluarCubilete[i]==3 && bandera==1){contadorDobleTrio++; posicionSegundoTrio=i;}
        }
        if(contadorDobleTrio==2)evaluarCubilete[posicionPrimerTrio]=0;

        // Escribir cantidad de veces salidas y numero 'X':
        for(int i=0; i<dados; i++){

            if(evaluarCubilete[i]>contador){
                contador=evaluarCubilete[i];
                numeroDadoPuntaje=i+1;
            }
        }
    // Evaluacion del puntaje:
    if(contador==2){for(int i=0; i<dados; i++)puntaje+=cubilete[i];}            // Suma de dados
    else if(contador>=3 && contador<6)puntaje=numeroDadoPuntaje*10;             // Trio X++
    else if(contador==6 && numeroDadoPuntaje!=6)puntaje=numeroDadoPuntaje*50;   // Sexteto X
    else if(contador==6 && numeroDadoPuntaje==6)puntaje=-1;                     // Sexteto seis
    else{puntaje=0;}

    return puntaje;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
///                                                                                                         Carteles:


void InterfazPartida(string nombreJugador, int numeroRonda, int puntajeActual, int puntajeTotal, int maximoPuntajeRonda, int lanzamiento){

    int columnaX, filaY;

    gotoxy(1, 2); printf("%c", 201);
    for(columnaX=2; columnaX<80; columnaX++){   // Fila superior.

        gotoxy(columnaX, 2); printf("%c", 205);
    }

    gotoxy(80, 2); printf("%c", 187);
    for(filaY=3; filaY<6; filaY++){             // Columnas.
        gotoxy(1, filaY); printf("%c", 186);
        gotoxy(80, filaY); printf("%c", 186);
        if(lanzamiento==1)rlutil::msleep(15);
    }

    gotoxy(1, filaY); printf("%c", 200);
    gotoxy(columnaX, filaY); printf("%c", 188);

    for(int columnaX1=2, columnaX=79; columnaX1<40,
        columnaX>40; columnaX1++, columnaX--){

        gotoxy(columnaX1, filaY); printf("%c", 205);
        gotoxy(columnaX, filaY); printf("%c", 205); // Fila inferior.
        if(lanzamiento==1)rlutil::msleep(1);
    }

    int velocidad=1;
    char mensaje1[9]="Turno de";
    char mensaje2[16]="Numero de ronda";
    char mensaje3[14]="Puntaje total";
    char mensaje4[27]="Maximo puntaje de la ronda";
    char mensaje5[7]="Puntos";
    char mensaje6[22]="Numero de lanzamiento";

    columnaX=4;
    filaY=3;
    for(int i=0; i<9; i++){gotoxy(columnaX, filaY); cout<<mensaje1[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<nombreJugador;
    columnaX=32;
    for(int i=0; i<16; i++){gotoxy(columnaX, filaY); cout<<mensaje2[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<numeroRonda;
    columnaX=58;
    for(int i=0; i<14; i++){gotoxy(columnaX, filaY); cout<<mensaje3[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<puntajeTotal;

    columnaX=4;
    filaY=4;
    for(int i=0; i<27; i++){gotoxy(columnaX, filaY); cout<<mensaje4[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<maximoPuntajeRonda;
    columnaX=34;
    for(int i=0; i<7; i++){gotoxy(columnaX, filaY); cout<<mensaje5[i]; rlutil::msleep(velocidad); columnaX++;}
    columnaX=4;
    filaY=5;
    for(int i=0; i<22; i++){gotoxy(columnaX, filaY); cout<<mensaje6[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<lanzamiento;

    filaY=7;
    gotoxy(1, filaY);

}

void EntreTurno(string nombreJugador, int numeroRonda, int puntajeTotal, string nombreJugadorDos,
                 int numeroRondaDos, int puntajeTotalDos, int& contadorTurnos, int maximoPuntajeRonda){

    int puntajeGanador=500;
    int columnaX, filaY;
    system("cls");

    gotoxy(1, 2); printf("%c", 201);
    for(columnaX=2; columnaX<80; columnaX++){   // Fila superior.

        gotoxy(columnaX, 2); printf("%c", 205);
    }

    gotoxy(80, 2); printf("%c", 187);
    for(filaY=3; filaY<7; filaY++){             // Columnas.
        gotoxy(1, filaY); printf("%c", 186);
        gotoxy(80, filaY); printf("%c", 186);
        rlutil::msleep(15);
    }

    gotoxy(1, filaY); printf("%c", 200);
    gotoxy(columnaX, filaY); printf("%c", 188);

    for(int columnaX1=2, columnaX=79; columnaX1<40,
        columnaX>40; columnaX1++, columnaX--){

        gotoxy(columnaX1, filaY); printf("%c", 205);
        gotoxy(columnaX, filaY); printf("%c", 205); // Fila inferior.
        rlutil::msleep(1);
    }    int velocidad=1;

    char mensaje1[16]="Numero de ronda";
    char mensaje2[14]="Proximo turno";
    char mensaje3[11]="Puntaje de";
    char mensaje4[31]="pts para que ganes la partida!";

    filaY=3;
    columnaX=32;
    for(int i=0; i<16; i++){gotoxy(columnaX, filaY); cout<<mensaje1[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<numeroRonda;
    columnaX=58;

    if(puntajeTotalDos==500){    /// Un jugador.
    filaY=4;
    columnaX=27;
    for(int i=0; i<14; i++){gotoxy(columnaX, filaY); cout<<mensaje2[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<nombreJugador;

    filaY=5;
    columnaX=27;
    for(int i=0; i<11; i++){gotoxy(columnaX, filaY); cout<<mensaje3[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY); cout<<nombreJugador<<": "<<puntajeTotal;

    columnaX=22;
    filaY=6;
    gotoxy(columnaX, filaY); cout<<"Restan "<<puntajeGanador-puntajeTotal;
    columnaX=32;
    for(int i=0; i<31; i++){gotoxy(columnaX, filaY); cout<<mensaje4[i]; rlutil::msleep(velocidad); columnaX++;}
    }



    if(contadorTurnos%2!=0 && puntajeTotalDos<500){                   /// jugador dos.

    filaY=4;
    columnaX=27;
    for(int i=0; i<14; i++){gotoxy(columnaX, filaY); cout<<mensaje2[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<nombreJugadorDos;

    filaY=5;
    columnaX=22;
    for(int i=0; i<11; i++){gotoxy(columnaX, filaY); cout<<mensaje3[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY); cout<<nombreJugador<<": "<<puntajeTotal<<" - puntaje de "<<nombreJugadorDos<<": "<<puntajeTotalDos;

    columnaX=4;
    filaY=6;
    gotoxy(columnaX, filaY); cout<<"Restan "<<puntajeGanador-puntajeTotal<<"pts a "<<nombreJugador<<" y "<<puntajeGanador-puntajeTotalDos<<" pts a "<<nombreJugadorDos<<" para que finalice la partida!";
    }
    else if (puntajeTotalDos<500){
    filaY=4;
    columnaX=27;
    for(int i=0; i<14; i++){gotoxy(columnaX, filaY); cout<<mensaje2[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY);cout<<nombreJugador;
    filaY=5;
    columnaX=22;
    for(int i=0; i<11; i++){gotoxy(columnaX, filaY); cout<<mensaje3[i]; rlutil::msleep(velocidad); columnaX++;}
    gotoxy(columnaX, filaY); cout<<nombreJugador<<": "<<puntajeTotal<<" - puntaje de "<<nombreJugadorDos<<": "<<puntajeTotalDos;

    columnaX=4;
    filaY=6;
    gotoxy(columnaX, filaY); cout<<"Restan "<<puntajeGanador-puntajeTotal<<"pts a "<<nombreJugador<<" y "<<puntajeGanador-puntajeTotalDos<<" pts a "<<nombreJugadorDos<<" para que finalice la partida!";
    }

    contadorTurnos++;

    cout<<endl<<endl;

    AnimacionesEntreTurnos(maximoPuntajeRonda);

rlutil::anykey();
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
///                                                                                                         Animaciones:


int AnimacionesPantallaMenu(int tipo){

// Variables a utilizar en cada estrategia de animacion:
    int columnaX, filaY;
    int eleccion;
    int velocidad;

    if(tipo==0){    /// Titulo Quinientos!

    char titulo[13]=" Quinientos!";

//  Estrategia para determinar centro de pantalla:
//    int longitudTitulo=strlen(titulo);
//    int cartelCentro=(((80-longitudTitulo)/2)+1);
//    cout<<cartelCentro; // Resultado: 32.

    for(columnaX=2; columnaX<33; columnaX++){

    gotoxy(columnaX, 3); printf(titulo);
    rlutil::msleep(1);
    }


    gotoxy(1, 2); printf("%c", 201);
    gotoxy(1, 3); printf("%c", 186);
    gotoxy(1, 4); printf("%c", 200);

    for(columnaX=2; columnaX<80; columnaX++){

    gotoxy(columnaX, 2); printf("%c", 205);
    gotoxy(columnaX, 4); printf("%c", 205);
    rlutil::msleep(3);
    }

    gotoxy(80, 2); printf("%c", 187);
    gotoxy(80, 3); printf("%c", 186);
    gotoxy(80, 4); printf("%c", 188);

    }
/*---------------------------------------------------------------------------*/
    if(tipo==1){    /// Menu principal:

    columnaX=20;
    filaY=7;

    gotoxy(columnaX, filaY); printf("%c", 218);     // Borde superior izq.
    for(columnaX=21; columnaX<60; columnaX++){
        gotoxy(columnaX, filaY); printf("%c", 196); // Linea superior.
    }
    gotoxy(columnaX, filaY); printf("%c", 191);     // Borde superior der.

    for(filaY+=1; filaY<18; filaY++){
        gotoxy(20, filaY); printf("%c", 179);       // Linea izq.

        if(filaY==8)cout<<"\t\tMENU PRINCIPAL"<<endl;
        if(filaY==11)cout<<"\to '1' Un jugador."<<endl;
        if(filaY==13)cout<<"\to '2' Dos jugadores."<<endl;
        if(filaY==15)cout<<"\to '0' Salir."<<endl;

        gotoxy(columnaX, filaY); printf("%c", 179); // Linea der.
        rlutil::msleep(15);
    }
    columnaX=20;
    gotoxy(columnaX, filaY); printf("%c", 192);     // Borde inferior izq.

    for(columnaX+=1; columnaX<60; columnaX++){
        gotoxy(columnaX, filaY); printf("%c", 196); // Linea inferior.
        rlutil::msleep(7);
    }
    gotoxy(columnaX, filaY); printf("%c", 217);     // Borde inferior izq.

    gotoxy(26, 17);
    rlutil::showcursor();
        cout<<"Eleccion --> ";
        cin>>eleccion;
    rlutil::hidecursor();

    return eleccion;
    }
/*---------------------------------------------------------------------------*/
    if(tipo==2){    /// Menu Un jugador:

    char titulo[12]=" Un jugador";

//    Estrategia para determinar centro de pantalla:
//    int longitudTitulo=strlen(titulo);
//    int cartelCentro=(((80-longitudTitulo)/2)+1);
//    cout<<cartelCentro; // Resultado: 35.

    AnimacionesPantallaMenu(100);// Cartel superior.

    for(columnaX=2; columnaX<36; columnaX++){

    gotoxy(columnaX, 3); printf(titulo);
    rlutil::msleep(1);
    }

    columnaX=20;
    filaY=8;

    AnimacionesPantallaMenu(101);// Cartel inferior.

    velocidad=15;
    gotoxy(columnaX, filaY); rlutil::msleep(velocidad);
    cout<<"\to '1' Iniciar partida."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '2' Puntaje maximo."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '3' Salon Escalera!."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '4' Reglas del juego: Un jugador."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '0' Atras."<<endl;

    gotoxy(26, 17);
    rlutil::showcursor();
        cout<<"Eleccion --> ";
        cin>>eleccion;
    rlutil::hidecursor();

    return eleccion;
    }

    if(tipo==3){    /// Menu Dos jugadores:
    char titulo[15]=" Dos Jugadores";

/* Estrategia para determinar centro de pantalla: */
//    int longitudTitulo=strlen(titulo);
//    int cartelCentro=(((80-longitudTitulo)/2)+1);
//    cout<<cartelCentro; // Resultado: 34.


    AnimacionesPantallaMenu(100);// Cartel superior.

    for(columnaX=2; columnaX<35; columnaX++){

    gotoxy(columnaX, 3); printf(titulo);
    rlutil::msleep(1);
    }

    columnaX=20;
    filaY=8;

    AnimacionesPantallaMenu(101);// Cartel inferior.

    velocidad=15;
    gotoxy(columnaX, filaY); rlutil::msleep(velocidad);
    cout<<"\to '1' Iniciar partida."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '2' Puntaje maximo."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '3' Salon Escalera!."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '4' Reglas para dos jugadores."<<endl;
    gotoxy(columnaX, filaY+=2); rlutil::msleep(velocidad);
    cout<<"\to '0' Atras."<<endl;

    gotoxy(26, 17);
    rlutil::showcursor();
        cout<<"Eleccion --> ";
        cin>>eleccion;
    rlutil::hidecursor();

    return eleccion;



    }
/*---------------------------------------------------------------------------*/
///     Objetos de pantalla:

    if(tipo==100){// Cartel superior menu.
    gotoxy(1, 2); printf("%c", 201);
    gotoxy(1, 3); printf("%c", 186);
    gotoxy(1, 4); printf("%c", 200);

    for(columnaX=2; columnaX<80; columnaX++){

    gotoxy(columnaX, 2); printf("%c", 205);
    gotoxy(columnaX, 4); printf("%c", 205);
    }

    gotoxy(80, 2); printf("%c", 187);
    gotoxy(80, 3); printf("%c", 186);
    gotoxy(80, 4); printf("%c", 188);
    }
    if(tipo==101){// Cartel inferior menu.
    columnaX=20;
    filaY=7;

    gotoxy(columnaX, filaY); printf("%c", 218);     // Borde superior izq.
    for(columnaX=21; columnaX<60; columnaX++){
        gotoxy(columnaX, filaY); printf("%c", 196); // Linea superior.
    }
    gotoxy(columnaX, filaY); printf("%c", 191);     // Borde superior der.

    for(filaY+=1; filaY<18; filaY++){
        gotoxy(20, filaY); printf("%c", 179);       // Linea izq.
        gotoxy(columnaX, filaY); printf("%c", 179); // Linea der.
        rlutil::msleep(15);
    }
    columnaX=20;
    gotoxy(columnaX, filaY); printf("%c", 192);     // Borde inferior izq.

    for(columnaX+=1; columnaX<60; columnaX++){
        gotoxy(columnaX, filaY); printf("%c", 196); // Linea inferior.
        rlutil::msleep(7);
    }
    gotoxy(columnaX, filaY); printf("%c", 217);     // Borde inferior izq.
    }

//return eleccion;
}

void AnimacionesNombre(string& nombreJugador,string& nombreJugadorDos, int tipo){

        int columnaX, filaY;
        int velocidad;

        gotoxy(1, 2); printf("%c", 201);
        for(columnaX=2; columnaX<80; columnaX++){   // Fila superior.

        gotoxy(columnaX, 2); printf("%c", 205);
        }

        gotoxy(80, 2); printf("%c", 187);
        for(filaY=3; filaY<6; filaY++){             // Columnas.
            gotoxy(1, filaY); printf("%c", 186);
            gotoxy(80, filaY); printf("%c", 186);
            rlutil::msleep(15);
        }

        gotoxy(1, filaY); printf("%c", 200);
        gotoxy(columnaX, filaY); printf("%c", 188);

        for(int columnaX1=2, columnaX=79; columnaX1<40, columnaX>40; columnaX1++, columnaX--){
            gotoxy(columnaX1, filaY); printf("%c", 205);
            gotoxy(columnaX, filaY); printf("%c", 205); // Fila inferior.
            rlutil::msleep(10);
        }

        velocidad=30;
        char mensaje1[24]="Muy bien jugador uno...";
        char mensaje2[19]="ingresa tu nombre:";
        char mensaje3[17]="...Buena suerte!";

        columnaX=4;
        filaY=3;

        rlutil::showcursor();
        for(int i=0; i<24; i++){
            gotoxy(columnaX, filaY);
                cout<<mensaje1[i];
            rlutil::msleep(velocidad);
            columnaX++;
        }

        columnaX=27;
        filaY++;

        for(int i=0; i<19; i++){
            gotoxy(columnaX, filaY);
                cout<<mensaje2[i];
            rlutil::msleep(velocidad);
            columnaX++;
        }
        gotoxy(46, 4);
        cin>>nombreJugador;

        columnaX=62;
        filaY++;

        for(int i=0; i<17; i++){
            gotoxy(columnaX, filaY);
                cout<<mensaje3[i];
            rlutil::msleep(velocidad);
            columnaX++;
        }
        rlutil::hidecursor();

    if(tipo==0){

            cout<<endl<<endl;
         system("pause");

        filaY++;

        for(int columnaX1=41, columnaX=40; columnaX1>3, columnaX<80; columnaX1--, columnaX++){
            gotoxy(columnaX1, filaY); printf(" ");
            gotoxy(columnaX, filaY); printf(" ");  // Fila inferior desvanecimiento.
            int filaYBORRAR=3;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");
            rlutil::msleep(15);
        }
    }

    if(tipo==1){    // Dos jugadores.

        for(filaY=6; filaY<10; filaY++){             // Columnas.
            gotoxy(1, filaY); printf("%c", 186);
            gotoxy(80, filaY); printf("%c", 186);
            rlutil::msleep(15);
        }

        gotoxy(1, filaY); printf("%c", 200);
        gotoxy(80, filaY); printf("%c", 188);

        for(int columnaX1=2, columnaX=79; columnaX1<40, columnaX>40; columnaX1++, columnaX--){
            gotoxy(columnaX1, filaY); printf("%c", 205);
            gotoxy(columnaX, filaY); printf("%c", 205); // Fila inferior.
            rlutil::msleep(10);
        }



        velocidad=30;
        char mensaje1[21]="Ahora jugador dos...";
        char mensaje2[19]="ingresa tu nombre:";
        char mensaje3[17]="...Buena suerte!";

        columnaX=4;
        filaY=7;

        rlutil::showcursor();
        for(int i=0; i<21; i++){
            gotoxy(columnaX, filaY);
                cout<<mensaje1[i];
            rlutil::msleep(velocidad);
            columnaX++;
        }

        columnaX=27;
        filaY++;

        for(int i=0; i<19; i++){
            gotoxy(columnaX, filaY);
                cout<<mensaje2[i];
            rlutil::msleep(velocidad);
            columnaX++;
        }
        gotoxy(46, filaY);
        cin>>nombreJugadorDos;

        columnaX=62;
        filaY++;

        for(int i=0; i<17; i++){
            gotoxy(columnaX, filaY);
                cout<<mensaje3[i];
            rlutil::msleep(velocidad);
            columnaX++;

        }
        rlutil::hidecursor();
            cout<<endl<<endl;
        system("pause");

        for(int columnaX1=41, columnaX=40; columnaX1>3, columnaX<80; columnaX1--, columnaX++){

            int filaYBORRAR=3;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje1.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje2.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje3.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // Fila media.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje1.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje2.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje3.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" -");  // Fila inferior dos jugadores.
            rlutil::msleep(15);
        }

        for(filaY=10; filaY>2; filaY--){             // Columnas desvanecimiento.
            gotoxy(1, filaY); printf(" ");
            gotoxy(80, filaY); printf(" ");
            rlutil::msleep(20);
        }
    }
}

void AnimacionesEntreTurnos(int maximoPuntajeronda){

    int columnaX, filaY;
    int velocidad;

    filaY=17;
    columnaX=1;
    velocidad=10;

///pruebas de animaciones:
//    maximoPuntajeronda=50;

    if(maximoPuntajeronda>=60){bailarin(0); bailarin(4);}
    else if(maximoPuntajeronda>=50){bailarin(0); bailarin(3);}
    else if(maximoPuntajeronda>=40){bailarin(0); bailarin(2);}
    else if(maximoPuntajeronda>=30){bailarin(0); bailarin(1);}

        columnaX=2;
        velocidad=30;
        for(columnaX; columnaX<28; columnaX++){

            filaY=14;
            gotoxy(columnaX, filaY); cout<<" + "<<maximoPuntajeronda<<" _____ _____   __ __\n"; filaY++;
            gotoxy(columnaX, filaY);                      cout<<"     ||_//  ||    ((  ||\n"; filaY++;
            gotoxy(columnaX, filaY);                      cout<<"     ||     ||   \\_)) ..\n";
            rlutil::msleep(velocidad);

        }
}

void AnimacionesEscalera(string nombreJugador){

        int columnaX, filaY;

        for(int columnaX1=41, columnaX=40; columnaX1>3, columnaX<80; columnaX1--, columnaX++){

            int filaYBORRAR=17;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje1.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje2.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // mensaje3.
            filaYBORRAR++;
            gotoxy(columnaX1, filaYBORRAR); printf(" ");
            gotoxy(columnaX, filaYBORRAR); printf(" ");  // Fila media.
            rlutil::msleep(15);
        }

        columnaX=2;
        filaY=13;
        rlutil::msleep(20);
        gotoxy(columnaX, filaY); cout<<"        o O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O O \n"; filaY++;
        rlutil::msleep(20);
        gotoxy(columnaX, filaY); cout<<"       o           ___                       _                         _   \n"; filaY++;
        rlutil::msleep(20);
        gotoxy(columnaX, filaY); cout<<" ____[O]          | __|  ___   __    __ _   | |   ___    _ _   __ _   | |  \n"; filaY++;
        rlutil::msleep(20);
        gotoxy(columnaX, filaY); cout<<"{======|_|------| | _|  (_-<  / _|  / _` |  | |  / -_)  | '_| / _` |  |_|  \n"; filaY++;
        rlutil::msleep(20);
        gotoxy(columnaX, filaY); cout<<"/o--000'-'-0-0-0' |___| /__/_ \\__|_ \\__,_| _|_|_ \\___| _|_|_  \\__,_| _(_)_ \n";

        columnaX=29;
        filaY+=2;
        gotoxy(columnaX, filaY); cout<<"FELICIDADES "<<nombreJugador<<"!";
        filaY++;
        gotoxy(columnaX, filaY); cout<<"GANASTE LA PARTIDA!";

        rlutil::anykey();

        system("cls");
}

void AnimacionesGanarPartida(string nombreJugador){

    int columnaX;
    int filaY;
    int velocidad=1;

    columnaX=80;
    filaY=20;
    velocidad=10;
    for(columnaX=80; columnaX>28; columnaX--){

        gotoxy(columnaX, filaY); cout<<" ";
        rlutil::msleep(velocidad);
    }

    columnaX=29;
    cout<<"FELICIDADES "<<nombreJugador<<"! GANASTE LA PARTIDA!";

    rlutil::anykey();
    system("cls");
}

void bailarin(int tipo){


    int columnaX=2;
    int filaY=14;
    int velocidad=1;

    if(tipo==0){        // Piso.

        columnaX=1;
        filaY=17;
        velocidad=10;
        for(int i=2; i<80; i++){

            gotoxy(i, filaY);
            printf("%c", 178);
            rlutil::msleep(velocidad);
        }

    }

    if(tipo==1){

        columnaX=78;
        velocidad=50;


        for(int i=80; i>74; i--){

            filaY=14;
            gotoxy(columnaX, filaY); cout<<" o__ \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"<|   \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"< >  \n";

            rlutil::msleep(velocidad);
            columnaX--;
            filaY=14;
            gotoxy(columnaX, filaY); cout<<"__o  \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"  |> \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<" < > \n";

            rlutil::msleep(velocidad);
            columnaX--;
            filaY=14;
            gotoxy(columnaX, filaY); cout<<"  o   \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"_<|>_ \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"      \n";

            rlutil::msleep(velocidad);
            columnaX--;
            filaY=14;
            gotoxy(columnaX, filaY); cout<<"       \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"  o    \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"_<|>_  \n";

            rlutil::msleep(velocidad);
            columnaX--;
            filaY=14;
            gotoxy(columnaX, filaY); cout<<"\\o/ \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<" |  \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"/ \\   \n";
        }
    }

        if(tipo==2){

        velocidad=50;
        columnaX=80;

        for(int i=80; i>66; i--){

            filaY=14;
            gotoxy(columnaX, filaY); cout<<"\\o  \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<" |> \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"< > \n";

            rlutil::msleep(velocidad);
            columnaX--;
            filaY=14;
            gotoxy(columnaX, filaY); cout<<"\\o \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<" |> \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"//  \n";
            rlutil::msleep(velocidad);
            columnaX--;

        }
    }

        if(tipo==3){

        velocidad=50;
        columnaX=73;


        for(int i=80; i>70; i--){

            filaY=8;
            gotoxy(columnaX, filaY); cout<<".------. \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"|A.--. | \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"| (\\/) | \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"| :\\/: | \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"| '--'A| \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"`------' \n"; filaY++;

            gotoxy(columnaX, filaY); cout<<"  \\o/ \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"   |  \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"  < > \n";

            rlutil::msleep(velocidad);
            columnaX--;
            filaY=8;
            gotoxy(columnaX, filaY); cout<<".------. \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"|A.--. | \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"| (\\/) | \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"| :\\/: | \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"| '--'A| \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"`------' \n"; filaY++;

            gotoxy(columnaX, filaY); cout<<"  \\o/ \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"   |  \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"  / \\ \n";
            rlutil::msleep(velocidad);
            columnaX--;

        }
        columnaX+=7;
        filaY-=2;
        gotoxy(columnaX, filaY); cout<<"----UPPS! \n";

    }

        if(tipo==4){

        velocidad=50;
        columnaX=55;


        for(int i=80; i>76; i--){

            filaY=12;
            gotoxy(columnaX, filaY); cout<<"        o O O O O O O O O  \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"       o                   \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<" ____[O]                   \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"{======|_|------|_|------| \n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"/o--000'-`-0-0-0'-`-0-0-0' \n";

            rlutil::msleep(velocidad);
            columnaX--;
        }
    }
}

void MostrarDados(int cubilete[]){

    const int dados=6;

    int filaY;
    int columnaX;

    columnaX=3;

    for(int i=0; i<dados;i++){
        int velocidadAparicion=50;
        int velocidad=30;

        filaY=7;

        switch(cubilete[i]){


        case 1:
            rlutil::msleep(velocidadAparicion);
            gotoxy(columnaX, filaY);    // Linea Superior.
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c\n", 220);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 1.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf(" ");
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 2.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf("%c", 220);
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 3.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf(" ");
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Linea inferior.
            printf("%c", 219); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 219);

            break;

        case 2:
            rlutil::msleep(velocidadAparicion);
            gotoxy(columnaX, filaY);    // Linea Superior.
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c\n", 220);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 1.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf(" ");
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 2.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf("%c", 223);
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 3.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf("%c", 254);
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Linea inferior.
            printf("%c", 219); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 219);

            break;

        case 3:
            rlutil::msleep(velocidadAparicion);
            gotoxy(columnaX, filaY);    // Linea Superior.
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c\n", 220);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 1.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf(" ");
            printf(" "); printf("%c", 220); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 2.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf("%c", 220);
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 3.
            printf("%c", 219); printf(" "); printf("%c", 220); printf(" "); printf(" ");
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Linea inferior.
            printf("%c", 219); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 219);

            break;

        case 4:
            rlutil::msleep(velocidadAparicion);
            gotoxy(columnaX, filaY);    // Linea Superior.
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c\n", 220);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 1.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf(" ");
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 2.
            printf("%c", 219); printf(" "); printf(" "); printf("%c", 223); printf(" ");
            printf("%c", 223); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 3.
            printf("%c", 219); printf(" "); printf(" "); printf("%c", 223); printf(" ");
            printf("%c", 223); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Linea inferior.
            printf("%c", 219); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 219);

            break;

        case 5:
            rlutil::msleep(velocidadAparicion);
            gotoxy(columnaX, filaY);    // Linea Superior.
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c\n", 220);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 1.
            printf("%c", 219); printf(" "); printf("%c", 220); printf(" "); printf(" ");
            printf(" "); printf("%c", 220); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 2.
            printf("%c", 219); printf(" "); printf(" "); printf(" "); printf("%c", 220);
            printf(" "); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 3.
            printf("%c", 219); printf(" "); printf("%c", 220); printf(" "); printf(" ");
            printf(" "); printf("%c", 220); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Linea inferior.
            printf("%c", 219); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 219);

            break;

        case 6:
            rlutil::msleep(velocidadAparicion);
            gotoxy(columnaX, filaY);    // Linea Superior.
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c\n", 220);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 1.
            printf("%c", 219); printf(" "); printf(" "); printf("%c", 220); printf(" ");
            printf("%c", 220); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 2.
            printf("%c", 219); printf(" "); printf(" "); printf("%c", 220); printf(" ");
            printf("%c", 220); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Fila 3.
            printf("%c", 219); printf(" "); printf(" "); printf("%c", 220); printf(" ");
            printf("%c", 220); printf(" "); printf(" "); printf("%c\n", 219);

            filaY++;
            rlutil::msleep(velocidad);
            gotoxy(columnaX, filaY);    // Linea inferior.
            printf("%c", 219); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 220); printf("%c", 220); printf("%c", 220); printf("%c", 220);
            printf("%c", 219);

            break;
        }
        columnaX+=13;
    }
    gotoxy(35, 15);
}

void AnimacionesMenuSecundario(string nombreJugador, int numeroRonda, int maximoPuntajeRonda,
                               string nombreJugadorDos, int numeroRondaDos, int maximoPuntajeRondaDos, int tipo){


    int columnaX, filaY;

    if(tipo==0){                /// Puntaje maximo un solo jugador.
        filaY=3;
        columnaX=21;
        AnimacionesPantallaMenu(100);// Cartel superior.
        gotoxy(columnaX, filaY); cout<<"Puntaje maximo para un solo jugador";

        if(maximoPuntajeRonda>0){
            filaY=7;
            gotoxy(columnaX, filaY); cout<<"o Jugador "<<nombreJugador; filaY++;
            gotoxy(columnaX, filaY); cout<<"o Maximo puntaje por ronda "<<maximoPuntajeRonda<<" puntos.\n\n";
        }
        else{
            filaY=10;
            columnaX=29;
            gotoxy(columnaX, filaY); cout<<"<o "; filaY++;
            gotoxy(columnaX, filaY); cout<<" |>"; filaY++; columnaX-=22;
            gotoxy(columnaX, filaY); cout<<"...Nada que mostrar.  / \\ ";
        }
    }


    if(tipo==1){                /// Salon Escalera! un solo jugador.
        filaY=3;
        columnaX=32;
        AnimacionesPantallaMenu(100);// Cartel superior.
        gotoxy(columnaX, filaY); cout<<"Salon Escalera!";

        columnaX=29;
        if(maximoPuntajeRonda==500){
            filaY=7;
            gotoxy(columnaX, filaY); cout<<"o Jugador "<<nombreJugador; filaY++;
            gotoxy(columnaX, filaY); cout<<"o Cantidad de rondas "<<numeroRonda<<".\n\n";
        }
        else{
            filaY=10;
            gotoxy(columnaX, filaY); cout<<"<o "; filaY++;
            gotoxy(columnaX, filaY); cout<<" |>"; filaY++; columnaX-=22;
            gotoxy(columnaX, filaY); cout<<"...Nada que mostrar.  / \\ ";
        }
    }
    if(tipo==2){                /// Reglas para un jugador.
        filaY=3;
        columnaX=31;

        system("mode con cols=80 lines=38");

        AnimacionesPantallaMenu(100);// Cartel superior.
        gotoxy(columnaX, filaY); cout<<"Reglas del juego";

        filaY+=3;
        columnaX=10;
        gotoxy(columnaX, filaY); cout<<"Las reglas... no?\n"; filaY++;
        gotoxy(columnaX, filaY); cout<<"Las reglas son las siguientes:"; filaY++; columnaX+=3;
        gotoxy(columnaX, filaY); cout<<"-> El objetivo del juego es obtener al menos 500"; filaY++; columnaX+=3;
        gotoxy(columnaX, filaY); cout<<"puntos en la menor cantidad posible de rondas"; filaY++;
        gotoxy(columnaX, filaY); cout<<"o sacar una escalera en un lanzamiento.\n"; filaY+=2; columnaX-=3;
        gotoxy(columnaX, filaY); cout<<"-> El puntaje final de la ronda sera el valor maximo"; filaY++; columnaX+=3;
        gotoxy(columnaX, filaY); cout<<"obtenido entre los tres lanzamientos, a exepcion de:"; filaY++; columnaX++;
        gotoxy(columnaX, filaY); cout<<"o Si en un lazamiento el jugador obtiene escalera"; filaY++; columnaX+=2;
        gotoxy(columnaX, filaY); cout<<"GANA EL PARTIDO en ese momento."; filaY++; columnaX-=2;
        gotoxy(columnaX, filaY); cout<<"o Si en un lanzamiento se obtiene una combinacion"; filaY++; columnaX+=2;
        gotoxy(columnaX, filaY); cout<<"de seis dados con valor 6, el puntaje de la ronda"; filaY++;
        gotoxy(columnaX, filaY); cout<<"entera sera 0."; filaY+=2; columnaX-=6;
        gotoxy(columnaX, filaY); cout<<"-> Combinaciones ganadoras:"; filaY++; columnaX+=3;
        gotoxy(columnaX, filaY); cout<<"o Suma de dados."; filaY++; columnaX+=2;
        gotoxy(columnaX, filaY); cout<<"Menos de 3 dados con valores iguales (1,2,2,5,5,6)"; filaY++;
        gotoxy(columnaX, filaY); cout<<"Suma de todos los valores: 1+2+2+5+5+6='21' Puntos."; filaY++; columnaX-=2;
        gotoxy(columnaX, filaY); cout<<"o trio 'X'."; filaY++; columnaX+=2;
        gotoxy(columnaX, filaY); cout<<"De 3 hasta 5 dados con valores iguales (1,1,1,5,5,5)"; filaY++;
        gotoxy(columnaX, filaY); cout<<"5*10 puntos = '50' Puntos."; filaY++;
        gotoxy(columnaX, filaY); cout<<"Se debe elegir la terna de mayor valor."; filaY++; columnaX-=2;
        gotoxy(columnaX, filaY); cout<<"o Sexteto 'X'."; filaY++; columnaX+=2;
        gotoxy(columnaX, filaY); cout<<"6 dados iguales excepto con el numero de dado 6"; filaY++;
        gotoxy(columnaX, filaY); cout<<"X*50 puntos."; filaY++; columnaX-=2;
        gotoxy(columnaX, filaY); cout<<"o Sexteto seis."; filaY++; columnaX+=2;
        gotoxy(columnaX, filaY); cout<<"6 dados iguales con el numero de dado 6"; filaY++;
        gotoxy(columnaX, filaY); cout<<"Pierde todos los puntos de la ronda."; filaY++; columnaX-=2;
        gotoxy(columnaX, filaY); cout<<"o Escalera."; filaY++; columnaX+=2;
        gotoxy(columnaX, filaY); cout<<"1,2,3,4,5,6."; filaY++;
        gotoxy(columnaX, filaY); cout<<"Gana la partida en esa ronda."; filaY+=2; columnaX-=8;
        gotoxy(columnaX, filaY);
    }

    if(tipo==3){                /// Maximo puntaje dos jugadores.
        filaY=3;
        columnaX=32;
        AnimacionesPantallaMenu(100);// Cartel superior.
        gotoxy(columnaX, filaY); cout<<"Puntajes maximos.";

        if(maximoPuntajeRondaDos!=0){
            filaY+=3;
            columnaX=19;
            gotoxy(columnaX, filaY); cout<<"o Jugador "<<nombreJugador<<" obtuvo "<<maximoPuntajeRonda<<" puntos.\n"; filaY++;
            gotoxy(columnaX, filaY); cout<<"o Jugador "<<nombreJugadorDos<<" obtuvo "<<maximoPuntajeRondaDos<<" puntos.\n\n";
        }
        else{
            filaY=10;
            columnaX=29;
            gotoxy(columnaX, filaY); cout<<"<o "; filaY++;
            gotoxy(columnaX, filaY); cout<<" |>"; filaY++; columnaX-=22;
            gotoxy(columnaX, filaY); cout<<"...Nada que mostrar.  / \\ ";
        }
    }

    if(tipo==4){                /// Salon Escalera! dos jugadores.
        filaY=3;
        columnaX=32;
        AnimacionesPantallaMenu(100);// Cartel superior.
        gotoxy(columnaX, filaY); cout<<"Salon Escalera!";

        columnaX=29;
        if(maximoPuntajeRonda==500){
            filaY=7;
            gotoxy(columnaX, filaY); cout<<"o Jugador "<<nombreJugador; filaY++;
            gotoxy(columnaX, filaY); cout<<"o Cantidad de rondas "<<numeroRonda<<".\n\n";
        }
        else if(maximoPuntajeRondaDos==500){
            filaY=7;
            gotoxy(columnaX, filaY); cout<<"o Jugador "<<nombreJugadorDos; filaY++;
            gotoxy(columnaX, filaY); cout<<"o Cantidad de rondas "<<numeroRonda<<".\n\n";
        }
        else{
            filaY=10;
            gotoxy(columnaX, filaY); cout<<"<o "; filaY++;
            gotoxy(columnaX, filaY); cout<<" |>"; filaY++; columnaX-=22;
            gotoxy(columnaX, filaY); cout<<"...Nada que mostrar.  / \\ ";
        }
    }

    system("pause");
    system("cls");
    if(tipo==2) system("mode con cols=80 lines=20");
}

void BenjaD(){                          /// Gracias Benja por tu apoyo aun fuera del proyecto!!

    system("mode con cols=115 lines=60");
    rlutil::setColor(3);

        cout<<"               ................                       .*(%@@&&&&&&%&&%                               				 \n";
        cout<<"               ................        .,(&@@@&#(,               .&&%%%&                             				 \n";
        cout<<"               ............. ....(@@#.                             &%%%%@                            				 \n";
        cout<<"               .............(@&.                                    &%%%%%                           				 \n";
        cout<<"               .......... .@...                                     (%%%%%#                          				 \n";
        cout<<"               ...........@,. .                                      &%%%%&&                         				 \n";
        cout<<"               ..........,@....                                      (%%%%%&%/                       				 \n";
        cout<<"               ..........@*....                                      *%%%%%%%%%%%%%&&&/              				 \n";
        cout<<"               ..........@.....                                ./(%&&%&%%%%%%%%%%&%.                 				 \n";
        cout<<"               .........,@.....                     ./&&&&&&&&&&&&&%%%%%%%%%&                        				 \n";
        cout<<"               ........./&.....             ,#&@&&&&&&&&&&&&&&&&&&&%%%%%%%%%%&                       				 \n";
        cout<<"               .........&(....        *&@&&&&&&&&&&&&&&&&&&%/*     ,%&%%%%%%%%(  ,*                  				 \n";
        cout<<"               .........@. ..... ,&&&&@&&&&&&&&&&&@%*                 &%%%%%%&&                      				 \n";
        cout<<"               ........@@.. .*@&&@&&&&&&&&&&@(                        &%%%%&                         				 \n";
        cout<<"               ....@&&.(@,@&&&&&&&&&&@&*                             &%%*                            				 \n";
        cout<<"               . . &&&#..(@&&&&@@&&@%..                             *&&&&                                		     \n";
        cout<<"               (@&&&&&@@&&@&@@&,...                            .%&&&%.                                     			 \n";
        cout<<"               .@&&&&&@&@&(,.#@......                       .%&&&&%.                                     			 \n";
        cout<<"               .........@... . ..                  #@&&&%,                                            				 \n";
        cout<<"               .......(#....(&@#.            *@&&@#                                                  				 \n";
        cout<<"               .......@.......  @        ,@&&&*                                                      				 \n";
        cout<<"               .......&.. /&&(        #@&@*                                                          				 \n";
        cout<<"               ............. #%.   &&&&                                                              				 \n";
        cout<<"               ...............@%#&&%                                                                 				 \n";
        cout<<"               ............. .@@&.                                                                   				 \n";
        cout<<"               ............*@@,                                                                      				 \n";
        cout<<"               ........../&&.                                                                        				 \n";
        cout<<"8 888888888o   8 8888888888   b.             8             8 8888       .8.                    8 888888888o.      \n";
        cout<<"8 8888    `88. 8 8888         888o.          8             8 8888      .888.                   8 8888    `^888.   \n";
        cout<<"8 8888     `88 8 8888         Y88888o.       8             8 8888     :88888.                  8 8888        `88. \n";
        cout<<"8 8888     ,88 8 8888         .`Y888888o.    8             8 8888    . `88888.                 8 8888         `88 \n";
        cout<<"8 8888.   ,88' 8 888888888888 8o. `Y888888o. 8             8 8888   .8. `88888.                8 8888          88 \n";
        cout<<"8 8888888888   8 8888         8`Y8o. `Y88888o8             8 8888  .8`8. `88888.               8 8888          88 \n";
        cout<<"8 8888    `88. 8 8888         8   `Y8o. `Y8888  88.        8 8888 .8' `8. `88888.              8 8888         ,88 \n";
        cout<<"8 8888      88 8 8888         8      `Y8o. `Y8  `88.       8 888'.8'   `8. `88888.             8 8888        ,88' \n";
        cout<<"8 8888    ,88' 8 8888         8         `Y8o.`    `88o.    8 88'.888888888. `88888.            8 8888    ,o88P'   \n";
        cout<<"8 888888888P   8 888888888888 8            `Yo     `Y888888 ' .8'       `8. `88888.           8 888888888P'      \n";

    rlutil::anykey();
    rlutil::setColor(15);
    system("cls");
    system("mode con cols=80 lines=20");

}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
///                                                                                                         Funcion final:

void Firma(){

    int velocidad=25;

        cout<<endl<<endl;
        cout<<"________________________________________________________________________________"<<endl;
    rlutil::msleep(velocidad);
        cout<<"             __                                                       /         "<<endl;
    rlutil::msleep(velocidad);
        cout<<"           /    )          ,         ,                               /          "<<endl;
    rlutil::msleep(velocidad);
        cout<<"----------/----/---------------__--------__----__--_/_----__---__---/-----------"<<endl;
    rlutil::msleep(velocidad);
        cout<<"         /  \\ /   /   /  /   /   ) /   /___) /   ) /    /   ) (_ ` /           "<<endl;
    rlutil::msleep(velocidad);
        cout<<"________(____X___(___(__/___/___/_/___(___ _/___/_(_ __(___/_(__)_o_____________"<<endl;
    rlutil::msleep(velocidad);
        cout<<"              \\                                                                "<<endl;
    rlutil::msleep(velocidad);

        cout<<endl<<endl;
        cout<<" ______________________________________________________________________________"<<endl;
    rlutil::msleep(velocidad);
        cout<<"|                                                                              |"<<endl;
    rlutil::msleep(velocidad);
        cout<<"|                      'Quinientos!' V 1.5 / BasiliscX                         |"<<endl;
    rlutil::msleep(velocidad);
        cout<<"|______________________________________________________________________________|"<<endl;
        cout<<endl<<endl;

    rlutil::anykey();
}

#endif // FUNCIONES_H_INCLUDED
