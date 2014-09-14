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

class Personagem : public Objeto {
public:
    Personagem();
    Personagem(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, int velocidadeInicial, int municaoInicial, bool spider);
    virtual ~Personagem();
    bool ir_esquerda();
    bool ir_direita();
    bool acelerar();
    bool ir_baixo();
    bool ir_cima();
    bool frear();
    bool atirar();
    bool godmod;
    void Morrer(int tempo);
    void mudarImagem();
    int getScore();

    double velocidade;
    int municao;
    Direcao Colidir(Objeto* obj);
    Obstaculo* tiro;
    int tempoFim;
    int obstaculoAtingidos;
    bool ehSpider;
private:
    void girar();

    int imgAtual;
    std::string pathImg;

    int tirosRecebidos;
    int bonus;
};

#endif	/* PERSONAGEM_H */
