/*
 * File:   Objeto.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 2:27 PM
 */

#ifndef OBJETO_H
#define	OBJETO_H
#include "Base.h"

class Objeto
{
public:
    Objeto();

    Objeto(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho);


    virtual ~Objeto();
    
    virtual Direcao Colidir(Objeto *obj);
    void Morrer();
    
	bool getAtivo();
	void setAtivo(bool);
	std::string getStrSprite();
	void setStrSprite(std::string sprite);
	int getTipo ();
	void setTipo(int);

	Dimensao getPosicao();
	void setPosicao(Dimensao Posicao);
	Dimensao getTamanho();
	void setTamanho(Dimensao Tamanho);

	int getAceleracao();
	void setAceleracao(int Aceleracao);

protected:
	int aceleracao;
	bool ativo;
	std::string strSprite;
    Dimensao posicao;
    Dimensao tamanho;
	int tipo; // Se for personagem é 0, se for obastaculo é 1
    
private:


};

#endif	/* OBJETO_H */

