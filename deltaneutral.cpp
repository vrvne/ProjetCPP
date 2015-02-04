#include "deltaneutral.h"
#include "normaldistribution.h"
#include <iostream>
#include <string>
using namespace std;
#include <math.h>
#include <cmath>

#include <QString>
#include <QTextStream>


// DeltaNeutral envoie sous la forme d'un string l'instruction à l'utilisateur
string DeltaNeutral(bool calll, bool loong, double S0, double K, double T, double r, double sigma) {
    double d1;
    d1=(log(S0/K)+(r+0.5*pow(sigma,2))*T)/(sigma*sqrt(T));
    if (calll) {
        double delta=normalDistribution(d1);
        if (!loong) {
            QString s= "Number of shares to buy: " ;
            QTextStream stream(&s) ;
            stream << delta ;
            return (s.toStdString());
        }
        else {
            QString s= "Number of shares to sell: " ;
            QTextStream stream(&s) ;
            stream << delta ;
            return (s.toStdString());
        }
    }
    else {
        double delta=normalDistribution(d1)-1;
        if (!loong) {
            QString s= "Number of shares to sell: " ;
            QTextStream stream(&s) ;
            stream << delta ;
            return (s.toStdString());
        }
        else {
            QString s= "Number of shares to buy: " ;
            QTextStream stream(&s) ;
            stream << delta ;
            return (s.toStdString());
        }
    }
}


// DeltaNeutral2 envoie sous la forme d'un doube l'instruction à l'utilisateur (>0 : achat, <0 : vente)
double DeltaNeutral2(bool calll, bool loong, double S0, double K, double T, double r, double sigma) {
    double d1;
    d1=(log(S0/K)+(r+0.5*pow(sigma,2))*T)/(sigma*sqrt(T));
    if (calll) {
        double delta=normalDistribution(d1);
        if (!loong) {
            return (delta);
        }
        else {
            return(-delta);
        }
    }
    else {
        double delta=normalDistribution(d1)-1;
        if (!loong) {
            return(-delta);
        }
        else {
            return (delta);
        }
    }
}


