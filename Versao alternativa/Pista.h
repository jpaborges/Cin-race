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
	Pista();
	Pista(std::string caminho);
    virtual ~Pista();
    
	//Funcoes que vao para o CORBA
	std::string getPathImg();
	bool getAcabarJogo();
	void setAcabarJogo(bool);
	int criarPersonagem();
	void criarPista(std::string caminho, Dimensao dimValida);
	int getPosAtual();
	bool getPausar();
	void setPausar(bool pausado);
	int getNumeroJogador(); //funcao usada para saber quantos jogadores estao jogando agora
	void iniciarJogo(int estagio);
	std::vector<Sprite> getObjetos();
	int getMunicao(int player);
	double getVelocidade(int player);
	void enviar_tecla(int tecla, int player); //envia para ser processado para o servidor qual tecla foi precionada
	void MorrerPersonagem(int player, int temporizador);
	void setGodMod(int player);
	bool getAtivo(int player);
	void testarColisoesPersonagem(int player); /*		Colocar isso nessa funcao
											   dimAux = personagem1->getPosicao();
							dimAux.y +=  VELOCIDADE_PISTA;
							personagem1->setPosicao(dimAux); */
	void mudarImagemPersonagem(int player);
	int getTempoFim(int player);
	int	getObstaculosAtingidos(int player);
	int	getScore(int player);
	bool Refresh(int tempo);
    void alterarAceleracao(int);
	int getID(int player);
	Sprite getPersonagem(int player);
private:
    void adicionarObjeto(Objeto* obj) throw(Erros);
    void terminar();
    void testarColisoes(Objeto* obj);
	void setPosAtual(int);	
	void setPathImg (std::string PathImg);
	int player1ID;
	int player2ID;

	bool AcabarJogo;
	bool pausado;
    int posAtual;
	bool DoisJogadores;
    int numero_Personagens;
    int numero_Obstaculos;
    void mudarImagem();
	std::string strcomecoCaminho;
    int imgAtual;
    std::string pathImg;
	std::vector<Objeto*> objetos;
	std::vector<Sprite> VetorSprites;
	Personagem* player1;
	Personagem* player2;
	Dimensao tamanho;
    Dimensao dimValida;
	//BITMAP *imagem;
};

#endif	/* PISTA_H */
