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
	
	//Metodos usados para o Corba
	bool criarObstaculo(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, double funcionalidade);
    double getFuncionalidade();
private:
	 double funcionalidade; // Mostra em porcento o ganho ou perda que esse obstaculo fornece
};

#endif	/* OBSTACULO_H */

