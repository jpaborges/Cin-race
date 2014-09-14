/*
 * File:   Obstaculo.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:12 PM
 */

#ifndef OBSTACULO_H
#define	OBSTACULO_H
#include "Objeto.h"



class Obstaculo : public Objeto
{
public:
    Obstaculo(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, double funcionalidade);
    virtual ~Obstaculo();
    double funcionalidade; // Mostra em porcento o ganho ou perda que esse obstaculo fornece
private:

};

#endif	/* OBSTACULO_H */

