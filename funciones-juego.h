#ifndef FUNCIONES-JUEGO_H_INCLUDED
#define FUNCIONES-JUEGO_H_INCLUDED

void InterfazManual(int v[], int tam);
int InterfazJugador(int v[], int tam, string usuario, int apuesta, int rondas, int conRondas, int maxi, int sumaDados, int ptosTot);
void cargarManual(int v[], int tam);
void cargarAleatorio(int v[], int tam);
int maximoVector(int v[], int tam);
int sumarVector(int v[], int tam );
void mostrarJugador(string usuario, int apuesta, int rondas);
string cargarUsuario(string usuario);
int cargarRondas(int rondas);
int cargarApuesta(int apuesta, string usuario);
void lineaHorizontal(int x, int y, int ancho, int simb);
void lineaVertical(int x, int y, int alto, int simb);
void Recuadro(int x0, int y0, int alto, int ancho);
void Recuadro2(int x0, int y0, int alto, int ancho);
void Recuadro3(int x0, int y0, int alto, int ancho);
void Subrayado(int x0, int y0);
int sumaMaximos(int maxi, int tam, int sumaDados);
int puntosRondaNeg(int apuesta, int ptosTot);
int puntosRondaPos(int sumaDados, int apuesta, int punRef);
int conRondaSinPtos(int ptosRonda, int rondaCeroPtos);
int conRondaPtosNeg(int ptosRonda, int rondaPtosNeg);
int sumarPuntos(int ptosRonda, int ptosTot);
int InterfazFinalRonda(int conRondas, int v[], int tam, int apuesta, int ptosTot, int sumaDados);
void InterfazFinal1(int conRondas, int ptosTot, string usuario);
int calcularGanadorPtos(int ptosTot, int ptosTot2, int ptosGan);
int calcularGanadorUsu(string usuario, string usuario2, string usuMax, int ptosTot, int ptosTot2, int ptosGan);
void InterfazFinal2(string usuario, string usuario2, string usuMax, int ptosTot, int ptosTot2, int ptosGan, int conRondas);
int MostrarMax(string usuario, string usuario2, int ptosGan, int maxPunt);
void InterfazCaso0();

/*-------------------------------------------------------*/
int InterfazManual(int v[], int tam, string usuario, int apuesta, int rondas, int conRondas, int sumaDados, int ptosTot){

    int i, maxi;
        sumaDados = 0;

        for(i=1; i<=5; i++){
            Recuadro3(1, 9, 14, 119);
            Recuadro2(1, 7, 2, 119);
            mostrarJugador(usuario, apuesta, rondas);

                gotoxy(2,10);
                cout<<(char)262<<" RONDA "<<conRondas;
                gotoxy(100, 10);
                cout<<"PUNTOS ACTUALES: "<<ptosTot;

                    lineaHorizontal(2, 11, 117, 196);
                    gotoxy(2,13);
                    cout<<(char)261<<" TIRADA N"<<char(167)<<" "<<i;

            gotoxy(3, 15);
            cargarManual(v, tam);

            tam = tam-1;
            maxi = maximoVector(v, tam);

                lineaHorizontal(2, 17, 117, 196);
                gotoxy(2, 18);
                cout<<(char)260<<" EL VALOR MAS ALTO ES: "<< maxi <<endl<<endl;
                sumaDados = sumaMaximos(maxi, tam, sumaDados);
                lineaVertical(33, 18, 0, 179);
                gotoxy(40, 18);
                cout<<"SUMA ACTUAL: "<< sumaDados <<endl;

            lineaHorizontal(2, 19, 117, 196);
            gotoxy(2, 21);
            cout<<(char)272<<" ";
            system("pause");
            system("cls");

    }

    return sumaDados;
}
/*-------------------------------------------------------*/
int InterfazJugador(int v[], int tam, string usuario, int apuesta, int rondas, int conRondas, int sumaDados, int ptosTot){

    int i, maxi;
        sumaDados = 0;

        for(i=1; i<=5; i++){
            Recuadro3(1, 9, 14, 119);
            Recuadro2(1, 7, 2, 119);
            mostrarJugador(usuario, apuesta, rondas);

                gotoxy(2,10);
                cout<<(char)262<<" RONDA "<<conRondas;
                gotoxy(100, 10);
                cout<<"PUNTOS ACTUALES: "<<ptosTot;

                    lineaHorizontal(2, 11, 117, 196);
                    gotoxy(35,13);
                    cout<<(char)261<<" TIRADA N"<<char(167)<<" "<<i;

            gotoxy(50, 15);
            cargarAleatorio(v, tam);

            tam = tam-1;
            maxi = maximoVector(v, tam);

                lineaHorizontal(2, 17, 117, 196);
                gotoxy(2, 18);
                cout<<(char)260<<" EL VALOR MAS ALTO ES: "<< maxi <<endl<<endl;
                sumaDados = sumaMaximos(maxi, tam, sumaDados);
                lineaVertical(33, 18, 0, 179);
                gotoxy(40, 18);
                cout<<"SUMA ACTUAL: "<< sumaDados <<endl;

            lineaHorizontal(2, 19, 117, 196);
            gotoxy(2, 21);
            cout<<(char)272<<" ";
            system("pause");
            system("cls");

    }

    return sumaDados;
}
/*-------------------------------------------------------*/
void cargarManual(int v[], int tam){
     int i;
     int x = 26;
        cout<<"INGRESE LOS DADOS: ";
        for(i=0;i<tam;i++){
            cin>>v[i];
            gotoxy(x, 15);
            x+=4;
        }
}
/*-------------------------------------------------------*/
void cargarAleatorio(int v[], int tam){
    int i;
    srand(time(NULL));
        for(i=0;i<tam;i++){
            v[i]=(rand()%6)+1;
            cout<<v[i]<<"\t";
                    }
    }
/*-------------------------------------------------------*/
int maximoVector(int v[], int tam){
    int i, maxi=0;
    for(i=0;i<=tam;i++){
    if(v[i] > maxi) {
        maxi = v[i];
    }
}
return maxi;
}
/*-------------------------------------------------------*/
int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}
/*-------------------------------------------------------*/
void mostrarJugador(string usuario, int apuesta, int rondas){
    gotoxy(38, 8);
    cout<<"JUGADOR: "<<usuario;
    cout<<"    "<<(char)186<<"    APUESTA: "<<apuesta;
    cout<<"    "<<(char)186<<"    RONDAS: "<<rondas;
}
/*-------------------------------------------------------*/
string cargarUsuario(string usuario){
        gotoxy(3,11);
        cout<<(char)272<<" INGRESA TU NOMBRE: ";
        cin>>usuario;
        system("cls");
        return usuario;
}
/*-------------------------------------------------------*/
int cargarRondas(int rondas){
        gotoxy(3,11);
        cout<<(char)272<<" INGRESA LAS RONDAS A JUGAR: ";
        cin>>rondas;
        system("cls");
        return rondas;
}
/*-------------------------------------------------------*/
int cargarApuesta(int apuesta, string usuario){
    gotoxy(3,11);
        cout<<(char)261<<" JUGADOR: "<<usuario;
    gotoxy(3, 13);
        cout<<(char)272<<" DE CUANTO VA A SER TU APUESTA ESTA RONDA?: ";
        cin>>apuesta;
        system("cls");
        return apuesta;
}
/*-------------------------------------------------------*/
void lineaHorizontal(int x, int y, int ancho, int simb){
    int i;
        for(i=0; i<=ancho; i++){
        gotoxy(x + i, y);
        cout<<(char)simb;
        }
}
/*-------------------------------------------------------*/
void lineaVertical(int x, int y, int alto, int simb){
    int i;
        for(i=0; i<=alto; i++){
            gotoxy(x, y + i);
            cout<<(char)simb;
        }
}
/*-------------------------------------------------------*/
void Recuadro(int x0, int y0, int alto, int ancho){
    int i;

    for(i=0; i<=ancho; i++){
        gotoxy(x0 + i, y0);
        cout<<(char)177;

        gotoxy(x0 + i, y0 + alto);
        cout<<(char)177;
    }

    for(i=0; i<=alto; i++){
        gotoxy(x0, y0 + i);
        cout<<(char)177;

        gotoxy(x0 + ancho, y0 + i);
        cout<<(char)177;
    }
}
/*-------------------------------------------------------*/
void Recuadro2(int x0, int y0, int alto, int ancho){
    int i;
    for(i=0; i<=ancho; i++){
        gotoxy(x0 + i, y0);
        cout<<(char)205;

        gotoxy(x0 + i, y0 + alto);
        cout<<(char)205;
    }

    for(i=0; i<=alto; i++){
        gotoxy(x0, y0 + i);
        cout<<(char)186;

        gotoxy(x0 + ancho, y0 + i);
        cout<<(char)186;
    }

    gotoxy(x0, y0);
    cout<<(char)201;

    gotoxy(x0 + ancho, y0);
    cout<<(char)187;

    gotoxy(x0, y0 + alto);
    cout<<(char)200;

    gotoxy(x0 + ancho, y0 + alto);
    cout<<(char)188;
}
/*-------------------------------------------------------*/
void Recuadro3(int x0, int y0, int alto, int ancho){
  int i;
    for(i=0; i<=ancho; i++){
        gotoxy(x0 + i, y0);
        cout<<(char)196;

        gotoxy(x0 + i, y0 + alto);
        cout<<(char)196;
    }

    for(i=0; i<=alto; i++){
        gotoxy(x0, y0 + i);
        cout<<(char)179;

        gotoxy(x0 + ancho, y0 + i);
        cout<<(char)179;
    }

    gotoxy(x0, y0);
    cout<<(char)218;

    gotoxy(x0 + ancho, y0);
    cout<<(char)191;

    gotoxy(x0, y0 + alto);
    cout<<(char)192;

    gotoxy(x0 + ancho, y0 + alto);
    cout<<(char)217;
}
/*-------------------------------------------------------*/
void Subrayado(int x0, int y0){
    int i;
    gotoxy(x0, y0);
    for(i=1; i<32; i++){
        cout<<(char)238;
    }
}
/*-------------------------------------------------------*/
int sumaMaximos(int maxi, int tam, int sumaDados){
            sumaDados+= maxi;
        return sumaDados;
}
/*-------------------------------------------------------*/
int puntosRondaNeg(int apuesta, int ptosTot, int ptosRonda){
     lineaVertical(45, 8, 0, 186);
        gotoxy(50, 8);
            cout<<"TIRO DE PUNTAJE: NO DISPONIBLE "<<(char)257;
        gotoxy(2, 13);
            cout<<(char)262<<" PUNTOS QUE SE RESTAN AL TOTAL: "<<apuesta;
        ptosRonda-=apuesta;

    return ptosRonda;
}
/*-------------------------------------------------------*/
int puntosRondaPos(int sumaDados, int apuesta, int punRef){
    int genAux = 1, nGen, i;

        for(i=1; i<=5; i++){

            if(sumaDados==punRef){
                nGen = genAux;
                lineaVertical(39, 8, 0, 186);
                gotoxy(45, 8);
                cout<<"TIRO DE PUNTAJE: DISPONIBLE "<<(char)258;
                lineaVertical(79, 8, 0, 186);
                gotoxy(85, 8);
                cout<<"NUMERO GENERADOR: "<<nGen;

                        }
            genAux+=1;
            punRef+=1;
        }

            if(sumaDados>=punRef){
                nGen = 6;
                lineaVertical(39, 8, 0, 186);
                gotoxy(45, 8);
                cout<<"TIRO DE PUNTAJE: DISPONIBLE "<<(char)258;
                lineaVertical(79, 8, 0, 186);
                gotoxy(85, 8);
                cout<<"NUMERO GENERADOR: "<<nGen;
            }
    return nGen;
}
/*-------------------------------------------------------*/
int conRondaSinPtos(int ptosRonda, int rondaCeroPtos){

    if(ptosRonda==0){
        rondaCeroPtos+=1;
    }

    return rondaCeroPtos;
}
/*-------------------------------------------------------*/
int conRondaPtosNeg(int ptosRonda, int rondaPtosNeg){
     if(ptosRonda<0){
        rondaPtosNeg+=1;
     }

    return rondaPtosNeg;
}
/*-------------------------------------------------------*/
int sumarPuntos(int ptosRonda, int ptosTot){

    ptosTot+=ptosRonda;

    return ptosTot;
}
/*-------------------------------------------------------*/
int InterfazFinalRonda(int conRondas, int v[], int tam, int apuesta, int ptosTot, int sumaDados){

    int punRef = 20, nGen, i, numRepe = 0, ptosRonda = 0;

        gotoxy(57,6);
        cout<<"Ronda "<<conRondas;
        Recuadro3(1, 9, 12, 119);
        Recuadro2(1, 7, 2, 119);
        gotoxy(20, 8);
        cout<<"SUMA TOTAL: "<<sumaDados;

           if(sumaDados<punRef){
                ptosRonda = puntosRondaNeg(apuesta, ptosTot, ptosRonda);
           }
           else{
                nGen = puntosRondaPos(sumaDados, apuesta, punRef);

                    gotoxy(40, 11);
                    cout<<"TIRADA: ";

                    gotoxy(50, 13);
                    for(i=0;i<5;i++){

                        v[i]=(rand()%6)+1;
                        cout<<v[i]<<"\t";

                        if(v[i] == nGen){
                            numRepe+=1;
                        }
                    }

                    ptosRonda = apuesta*numRepe;
                    lineaHorizontal(2, 15, 117, 196);
                    gotoxy(2, 16);
                    cout<<(char)262;
                    cout<<" PUNTOS GANADOS ESTA RONDA: "<<ptosRonda;
           }

        lineaHorizontal(2, 17, 117, 196);
        gotoxy(2, 19);
        cout<<(char)272<<" ";

        system("pause");
        system("cls");

        return ptosRonda;
}
/*-------------------------------------------------------*/
void InterfazFinal1(int conRondas, int ptosTot, string usuario, int rondaCeroPtos, int rondaPtosNeg){
    Recuadro2(30, 5, 17, 60);
    gotoxy(50, 7);
    cout<<"JUGADOR: "<<usuario;
    gotoxy(50, 9);
    cout<<"PUNTOS: "<<ptosTot;
    gotoxy(50, 11);
    cout<<"RONDAS JUGADAS: "<<conRondas;
    gotoxy(50, 13);
    cout<<"RONDAS SIN PUNTOS: "<<rondaCeroPtos;
    gotoxy(50, 15);
    cout<<"RONDAS NEGATIVAS: "<<rondaPtosNeg;

    gotoxy(32, 20);
    cout<<(char)272<<" ";
    system("pause");
    system("cls");
}
/*-------------------------------------------------------*/
int calcularGanadorPtos(int ptosTot, int ptosTot2, int ptosGan){
    ptosGan = 0;

    if(ptosTot>=ptosTot2){
        ptosGan = ptosTot;
    }
    else{
        ptosGan = ptosTot2;
    }

    return ptosGan;
}
/*-------------------------------------------------------*/
string calcularGanadorUsu(string usuario, string usuario2, string usuGan, int ptosTot, int ptosTot2){

    if(ptosTot>=ptosTot2){
        usuGan = usuario;
    }
    else{
        usuGan = usuario2;
    }

    return usuGan;
}
/*-------------------------------------------------------*/
void InterfazFinal2(string usuario, string usuario2, string usuGan, int ptosTot, int ptosTot2, int ptosGan, int conRondas){
    Recuadro2(30, 5, 12, 55);
    gotoxy(50, 7);
    if(ptosGan == ptosTot && ptosGan == ptosTot2){
        cout<<"GANADOR: NINGUNO(EMPATE)";
    }
    else{
        cout<<"GANADOR: "<<usuGan;
    }
    gotoxy(50, 9);
        cout<<"PUNTAJE : "<<ptosGan;

    gotoxy(50, 11);
    cout<<"RONDAS JUGADAS: "<<conRondas;

    gotoxy(32, 15);
    cout<<(char)272<<" ";

    system("pause");
    system("cls");
}
/*-------------------------------------------------------*/
void MostrarMax(string usuGan, string maxUsu, int ptosGan, int maxPunt, bool entOp3){
    bool priEnt = true;

    Recuadro2(30, 6, 10, 60);
    Recuadro2(30, 4, 2, 60);
        gotoxy(50, 5);
        cout<<"PUNTUACION MAS ALTA";
    if(entOp3 == false){
        gotoxy(45, 9);
        cout<<"TODAVIA NO SE REGISTRAN PUNTAJES";
    }
    else{

        if(priEnt==true){
            maxUsu = usuGan;
            maxPunt = ptosGan;
            priEnt = false;
        }
        else if(ptosGan>maxPunt){
            maxUsu = usuGan;
            maxPunt = ptosGan;
        }
        gotoxy(50, 9);
        cout<<"JUGADOR: "<<maxUsu;
        gotoxy(50, 11);
        cout<<"PUNTAJE: "<<maxPunt;
    }

    gotoxy(32, 14);
    cout<<(char)272<<" ";

    system("pause");
    system("cls");
}
/*-------------------------------------------------------*/
void InterfazCaso0(){
    Recuadro2(38, 3, 13, 49);
        Recuadro3(39, 4, 11, 47);
        Recuadro2(40, 5, 9, 45);
        gotoxy(45, 9);
        cout<<(char)258<<" GRACIAS POR USAR NUESTRO PROGRAMA "<<(char)258;

        gotoxy(1, 18);
        cout<<(char)272<<" ";
        system("pause");

}
/*-------------------------------------------------------*/
#endif FUNCIONES-JUEGO_H_INCLUDED
