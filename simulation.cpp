#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <math.h>
#include <stdio.h>
#include "deltaneutral.h"
#include "uniformgenlc.h"
#include <QVector>
#include <QString>
#include <QTextStream>

// On définit une première fonction BrownGeom qui simule l'évolution d'un actif
QVector<double> BrownGeom(double S0, double sigma, double drift, double T, double N) {

/*
S0 : valeur initiale de l'actif
sigma : paramètre de volatilité
drift : paramètre de drift
T : on simule le mouvement brownien géométrique sur [0;T]
N : nombre de pas de temps en lequel on subdivise l'intervalle
*/

// On définit epsilon, la largeur d'un pas de discrétisation
double epsilon = T/N;

// On définit S qui contiendra les valeurs simulées
QVector<double> S(N+1);
for (int i=0 ; i<N+1 ; i++) {
    S[i]=0;
}
S[0]=S0;

// On initialise deux randunif qui seront généré aléatoirement selon U[0,1]
int seed = 17;
double randunif;
double randunif2;
UniformGenLC gen(seed);

// On initialise randnorm qui sera créé via la méthode de Box-Muller
double randnorm;

// On implémente à présent la méthode d'Euler stochastique
// "i" est l'indice du dernier point simulé dans la liste "S"/
for (int i=0; i<N; i++) {
    randunif=gen.NextDouble();
    randunif2=gen.NextDouble();
    double valuepi=atan(1)*4;
    randnorm=sqrt(-2*log(randunif))*cos(2*valuepi*randunif2);
    S[i+1]=S[i]+sqrt(pow(sigma,2)*epsilon)*randnorm;
}

// A présent, S contient une simulation de l'évolution de l'actif

// On pourrait définir array, liste des temps de discrétisation, pour éventuellement représenter l'évolution de S
// On décommenterait alors les lignes suivantes :
//QVector<double> array(N+1);
//for (int i=0 ; i<N+1 ; i++) {
//	array[i]=epsilon*i;
//}

return S;
}


// On définit une seconde fonction qui étudie l'effet (sur le pay-off) d'un delta-hedging effectué à certains instants

string SimulationHedge(double S0, double sigma, double drift, double T, double N, bool calll, bool loong, double K, double r, double Nb_Hedge) {
    /* Un point sur les paramètres :
    S0, sigma, drift, T, N, optiontype, position, K, r : cf. BrownGeom et DeltaNeutral
    Nb_Hedge : nombre de hedging opérés ; l'utilisateur doit impérativement choisir Nb_Hedge < N
    */

    // On commence par simuler l'évolution de l'actif
    QVector<double> S = BrownGeom(S0, sigma, drift, T, N);

    // On doit stocker à chaque instant de hedging combien d'actifs sont en portefeuille
    QVector<double> NbActifs(Nb_Hedge);
    for (int k=0; k<Nb_Hedge; k++) {
        NbActifs[k]=DeltaNeutral2(calll, loong, S[floor(k*N/Nb_Hedge)], K, T, r, sigma);
    }

    // On observe maintenant la situation du portefeuille à l'instant T
    double earnings;
    double SharesToBuy=0;
    double SharesToSell=0;
    // On distingue selon le type d'option et la position si l'option est exercée et, avec la composition du portefeuille, combien est gagné/perdu.
    if (calll) {
        if (!loong) {
            if (S[N]-K > 0) { // l'option a été exercée par l'acheteur
                SharesToBuy=1-NbActifs[Nb_Hedge-1];
                earnings=K-SharesToBuy*S[N];
            }
            else {
                earnings=-SharesToBuy*S[N];
            }
        }
        else  {
            if (S[N]-K > 0) { // vous exercez l'option achetée
                SharesToSell=1+NbActifs[Nb_Hedge-1];
                earnings=SharesToSell*S[N]-K;
            }
            else {
                earnings=SharesToSell*S[N];
            }
        }
    }
    else { 
        if (!loong) {
            if (K-S[N] > 0) {
                SharesToSell=1+NbActifs[Nb_Hedge-1];
                earnings=K-SharesToSell*S[N];
            }
            else {
                earnings=-SharesToSell*S[N];
            }
        }
        else {
            if (K-S[N] > 0) {
                SharesToBuy=1-NbActifs[Nb_Hedge-1];
                earnings=SharesToBuy*S[N]-K;
            }
        }
    }

    if (earnings > 0) {
        QString s = "With these parameters, you would earn: ";
        QTextStream stream(&s);
        stream << earnings;
        return(s.toStdString());
    }
    else {
        earnings=-earnings;
        QString s = "With these parameters, you would loose: ";
        QTextStream stream(&s);
        stream << earnings;
        return(s.toStdString());        
    
        
    }
    



}



