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
    bool ativo;
    BITMAP *sprite;
    Dimensao posicao;
    Dimensao tamanho;
    Direcao Colidir(Objeto *obj);
    void Exibir(); //Exibe esse objeto na tela
    void Morrer();
    int tipo; // Se for personagem é 0, se for obastaculo é 1
    int aceleracao;
private:


};

#endif	/* OBJETO_H */

