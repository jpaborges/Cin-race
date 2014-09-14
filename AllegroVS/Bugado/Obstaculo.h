/*
 * File:   Obstaculo.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:12 PM
 */

#ifndef OBSTACULO_H
#define	OBSTACULO_H
#include "Objeto.h"


class Obstaculo : public ICorba::IObstaculo
{
public:
   /* Obstaculo(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, double funcionalidade);
    virtual ~Obstaculo();
	*/
	//Metodos usados para o Corba
	Obstaculo();
	CORBA::Boolean criarObstaculo( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Double funcionalidade );
    CORBA::Double getFuncionalidade();
private:
	 double funcionalidade; // Mostra em porcento o ganho ou perda que esse obstaculo fornece
};

#endif	/* OBSTACULO_H */

