/*
 * File:   Personagem.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 3:50 PM
 */

#ifndef PERSONAGEM_H
#define	PERSONAGEM_H
#include "Objeto.h"
#include "Obstaculo.h"

class Personagem : public ICorba::IPersonagem {
public:
    /*Personagem();
    Personagem(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, int velocidadeInicial, int municaoInicial, bool spider);
   */
	 Personagem();
	 ICorba::Direcao ColidirPersonagem( ICorba::IObjeto* obj ) ;
     CORBA::Boolean criarPersonagem( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Long velocidadeInicial, CORBA::Long municaoInicial, CORBA::Boolean spider ) ;
     CORBA::Boolean ir_esquerda() ;
     CORBA::Boolean ir_direita() ;
     CORBA::Boolean acelerar() ;
     CORBA::Boolean ir_baixo() ;
     CORBA::Boolean ir_cima() ;
     CORBA::Boolean frear() ;
     CORBA::Boolean atirar() ;
     void MorrerPersonagem( CORBA::Long tempo ) ;
     void mudarImagem() ;
     CORBA::Long getScore() ;
     CORBA::Double getVelocidade() ;
     void setVelocidade( CORBA::Double velocidade ) ;
     CORBA::Long getMunicao() ;
     void setMunicao( CORBA::Long municao ) ;
	 ICorba::IObstaculo* getTiro() ;
     CORBA::Long getTempoFim() ;
     void setTempoFim( CORBA::Long tempoFim ) ;
     CORBA::Long getObstaculosAtingidos() ;
     void setObstaculosAtingidos( CORBA::Long ObstaculosAtingidos ) ;
     CORBA::Boolean getGodMod() ;
     void setGodMod( CORBA::Boolean godMod ) ;
     CORBA::Boolean getEhSpider() ;
     void setEhSpider( CORBA::Boolean ehSpider ) ;




private:
    void girar();

    double velocidade;
    int municao;
	ICorba::IObstaculo* tiro;
	Objeto* tiro1;
    CORBA::Long tempoFim;
    int obstaculoAtingidos;
    bool godmod;
    bool ehSpider;
    int imgAtual;
    std::string pathImg;
	
    int tirosRecebidos;
    int bonus;
};

#endif	/* PERSONAGEM_H */
