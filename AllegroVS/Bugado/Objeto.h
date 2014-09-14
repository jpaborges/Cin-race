/*
 * File:   Objeto.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 2:27 PM
 */

#ifndef OBJETO_H
#define	OBJETO_H
#include "Base.h"

class Objeto : public ICorba::IObjeto
{
public:
    Objeto();
    virtual ~Objeto();
    
	 ::ICorba::Direcao Colidir( ICorba::IObjeto* obj );
     void Morrer();
     CORBA::Boolean getAtivo();
     void setAtivo( CORBA::Boolean ativo );
     char* getStrSprite();
     void setStrSprite( const char* sprite );
     CORBA::Long getTipo();
     void setTipo( CORBA::Long tipo );
     ::ICorba::Dimensao getPosicao();
     void setPosicao( const ::ICorba::Dimensao& Posicao );
     ::ICorba::Dimensao getTamanho();
     void setTamanho( const ::ICorba::Dimensao& Tamanho );
     CORBA::Long getAceleracao();
     void setAceleracao( CORBA::Long Aceleracao );

protected:
//esta no iobjeto
    
private:


};

#endif	/* OBJETO_H */

