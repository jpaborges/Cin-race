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

    // get e set do Corba
	bool criarPista(std::string caminho);
	bool getAcabarJogo();
	void setAcabarJogo(bool);
	int getPosAtual();
	void setPosAtual(int);
	std::vector<Objeto*> getObjetos();
	void setObjetos(std::vector<Objeto*>);
	Dimensao getTamanho();
	void setTamanho(Dimensao);
	Dimensao getDimValida();
	void setDimValida(Dimensao);
	BITMAP* getImagem();
	void setImagem(BITMAP*);
    
private:
	bool AcabarJogo;
    int posAtual;
	bool DoisJogadores;
    int numero_Personagens;
    int numero_Obstaculos;
    void mudarImagem();
    int imgAtual;
    std::string pathImg;
	std::vector<Objeto*> objetos;
	Dimensao tamanho;
    Dimensao dimValida;
	BITMAP *imagem;
};

#endif	/* PISTA_H */
