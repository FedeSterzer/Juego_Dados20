#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>

using namespace std;
#include "rlutil.h"
#include "funciones-juego.h"

int main(){

    string usuario, usuario2, usuGan, maxUsu;
    int i, opc, apuesta, rondas, apuesta2, conRondas, sumaDados, ptosTot, ptosTot2, ptosRonda;
    int rondaCeroPtos, rondaPtosNeg, ptosGan, maxPunt = 0;
    int vec[5]={0};
    bool entOp3 = false;

    while (true){

            rlutil::setBackgroundColor(rlutil::GREEN);
            system("cls");
            rondaCeroPtos = 0;
            rondaPtosNeg = 0;
            conRondas = 0;
            ptosTot = 0;
            ptosTot2 = 0;
            Recuadro(3, 7, 14, 115);

                gotoxy(50,9);
                cout<<"BIENVENIDOS AL JUEGO DEL 20";
                Subrayado(48, 10);
                gotoxy(5, 11);
                cout<<"1) JUEGO NUEVO PARA UN JUGADOR";
                gotoxy(5,12);
                cout<<"2) JUEGO NUEVO PARA DOS JUGADORES";
                gotoxy(5,13);
                cout<<"3) MOSTRAR PUNTAJE MAS ALTO";
                gotoxy(5,14);
                cout<<"4) MODO SIMULADO";
                gotoxy(5,15);
                cout<<"0) FIN DEL PROGRAMA";
                gotoxy(5,19);
                cout<<(char)272<<" INGRESE UNA OPCION: ";
                cin>>opc;
                system("cls");

    switch(opc){
    case 1:
        entOp3 = true;
        Recuadro2(1, 10, 2, 119);
        usuario = cargarUsuario(usuario);
        Recuadro2(1, 10, 2, 119);
        rondas = cargarRondas(rondas);

        for(i=1; i<=rondas; i++){
            Recuadro2(1, 10, 4, 119);
            lineaHorizontal(2, 12, 117, 205);
            apuesta = cargarApuesta(apuesta, usuario);
            conRondas+=1;

                sumaDados = InterfazJugador(vec, 5, usuario,  apuesta, rondas, conRondas, sumaDados, ptosTot);
                ptosRonda = InterfazFinalRonda(conRondas, vec, 5, apuesta, ptosTot, sumaDados);
                ptosTot = sumarPuntos(ptosRonda, ptosTot);
                rondaCeroPtos = conRondaSinPtos(ptosRonda, rondaCeroPtos);
                rondaPtosNeg = conRondaPtosNeg(ptosRonda, rondaPtosNeg);

        }
            InterfazFinal1(conRondas, ptosTot, usuario, rondaCeroPtos, rondaPtosNeg);
            ptosGan = ptosTot;
            usuGan = usuario;

    break;

    case 2:
        entOp3 = true;
        Recuadro2(1, 10, 2, 119);
        usuario = cargarUsuario(usuario);
        Recuadro2(1, 10, 2, 119);
        usuario2 = cargarUsuario(usuario);
        Recuadro2(1, 10, 2, 119);
        rondas = cargarRondas(rondas);

        for(i=1; i<=rondas; i++){
            Recuadro2(1, 10, 4, 119);
            lineaHorizontal(2, 12, 117, 205);
            apuesta = cargarApuesta(apuesta, usuario);
            Recuadro2(1, 10, 4, 119);
            lineaHorizontal(2, 12, 117, 205);
            apuesta2 = cargarApuesta(apuesta, usuario2);

            conRondas+=1;

            sumaDados = InterfazJugador(vec, 5, usuario,  apuesta, rondas, conRondas, sumaDados, ptosTot);
            ptosRonda = InterfazFinalRonda(conRondas, vec, 5, apuesta, ptosTot, sumaDados);
            ptosTot = sumarPuntos(ptosRonda, ptosTot);
            sumaDados = InterfazJugador(vec, 5, usuario2,  apuesta2, rondas, conRondas, sumaDados, ptosTot2);
            ptosRonda = InterfazFinalRonda(conRondas, vec, 5, apuesta2, ptosTot2, sumaDados);
            ptosTot2 = sumarPuntos(ptosRonda, ptosTot2);

        }
            ptosGan = calcularGanadorPtos(ptosTot, ptosTot2, ptosGan);
            usuGan = calcularGanadorUsu(usuario, usuario2, usuGan, ptosTot, ptosTot2);
            InterfazFinal2(usuario, usuario2, usuGan, ptosTot, ptosTot2, ptosGan, conRondas);

    break;

    case 3:
        MostrarMax(usuGan, maxUsu, ptosGan, maxPunt, entOp3);
    break;

    case 4:
        entOp3 = true;
        Recuadro2(1, 10, 2, 118);
        usuario = cargarUsuario(usuario);
        Recuadro2(1, 10, 2, 118);
        rondas = cargarRondas(rondas);

        for(i=1; i<=rondas; i++){
            Recuadro2(1, 10, 4, 119);
            lineaHorizontal(2, 12, 117, 205);
            apuesta = cargarApuesta(apuesta, usuario);
            conRondas+=1;


            sumaDados = InterfazManual(vec,5, usuario,  apuesta, rondas, conRondas, sumaDados, ptosTot);
            ptosRonda = InterfazFinalRonda(conRondas, vec, 5, apuesta, ptosTot, sumaDados);
            ptosTot = sumarPuntos(ptosRonda, ptosTot);
            rondaCeroPtos = conRondaSinPtos(ptosRonda, rondaCeroPtos);
            rondaPtosNeg = conRondaPtosNeg(ptosRonda, rondaPtosNeg);
        }

        InterfazFinal1(conRondas, ptosTot, usuario, rondaCeroPtos, rondaPtosNeg);
    break;

    case 0:
            InterfazCaso0();
            return 0;
    break;

    default:
        Recuadro2(40, 4, 10, 48);
        gotoxy(50, 6);
        cout<<(char)158<<" ESTA OPCION ES INCORRECTA "<<(char)158;
        gotoxy(55, 8);
        cout<<"INTENTA DE NUEVO";
        gotoxy(42, 12);
        cout<<(char)272<<" ";
        system("pause");
    }

    }
}
