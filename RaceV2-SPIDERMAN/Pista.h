/*
 * File:   Pista.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:14 PM
 */

#ifndef PISTA_H
#define	PISTA_H
#include "Objeto.h"
#include "Personagem.h"
#include <vector>

class Pista {
public:
    bool Refresh(int tempo);
    void alterarAceleracao(int);
    void adicionarObjeto(Objeto* obj) throw(Erros);
    void terminar();
    Pista(std::string caminho);
    virtual ~Pista();
    void testarColisoes(Objeto* obj);

    int posAtual;
    Dimensao tamanho;
    Dimensao dimValida;
    bool AcabarJogo;
    BITMAP *imagem;
    std::vector<Objeto*> objetos;
private:
    bool DoisJogadores;
    int numero_Personagens;
    int numero_Obstaculos;
    void mudarImagem();
    int imgAtual;
    std::string pathImg;
};

#endif	/* PISTA_H */
