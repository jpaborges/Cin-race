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
    bool criarPersonagem (bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, int velocidadeInicial, int municaoInicial, bool spider);
    virtual ~Personagem();
    Direcao ColidirPersonagem(Objeto* obj);
    bool ir_esquerda();
    bool ir_direita();
    bool acelerar();
    bool ir_baixo();
    bool ir_cima();
    bool frear();
    bool atirar();
    void MorrerPersonagem(int tempo);
    void mudarImagem();

    //Metodos get e set por causa do Corba.
    int getScore();
    double getVelocidade();
    void setVelocidade(double velocidade);
    int getMunicao();
    void setMunicao(int municao);
    Obstaculo* getTiro();
    void setTiro(Obstaculo* tiro);
    int getTempoFim();
    void setTempoFim(int tempoFim);
    int getObstaculosAtingidos();
    void setObstaculosAtingidos(int ObstaculosAtingidos);
    bool getGodMod();
    void setGodMod(bool godMod);
    bool getEhSpider();
    void setEhSpider(bool ehSpider);

private:
    void girar();

    double velocidade;
    int municao;
    Obstaculo* tiro;
    int tempoFim;
    int obstaculoAtingidos;
    bool godmod;
    bool ehSpider;
    int imgAtual;
    std::string pathImg;

    int tirosRecebidos;
    int bonus;
};

#endif	/* PERSONAGEM_H */
