/*
 * File:   Jogo.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 6:44 PM
 */

#ifndef JOGO_H
#define	JOGO_H
#include <allegro.h>
#include <iostream>
#include <vector>
#include "Imagem.h"
#include "base.h"

typedef enum controle
{
    NOVO_JOGO,
    MULTIPLAYER,
    AJUDA,
    RECORDES,
    PAUSA,
    NAO_INICIADO,
    SPLASH,
    CHEAT //comeca no estagio 2

} CONTROLE;

class Jogo
{
public:
	Jogo(ICorba::Dimensao tela,ICorba::IPista* pista_servidor);
    virtual ~Jogo();
    CONTROLE status;
    void mudarStatus(CONTROLE novo_status);
    void exibirMenu();
	Imagem* criarImagem(ICorba::Sprite obj);
	ICorba::IPista* pista;

private:
    ICorba::Dimensao tela;
	ICorba::Dimensao dimensao(int x, int y);
	std::string strimgPista;
    bool temSom;
    void exibirSplash();
    void exibirAjuda();
    void novoJogo(int estagio);
    void finalizarJogo();
    void pausar();
    bool iniciarAllegro(std::string titulo,ICorba::Dimensao tela );
    void imprimirObjetosTela();
    bool exibirPontuacao();
	void atualizarImgPista();
    void contagemRegressiva();
	BITMAP* encontrarImagem(char* caminho);
    SAMPLE* musica; //Ponteiro para musica.
	ICorba::IPista::vetor_objetos_slice* VetorSprites;
	//Imagens utilizadas no jogo
	std::vector <Imagem*> imgsObjetos;
	BITMAP* buffer;
    BITMAP* imgmenu;
	BITMAP* entrada1;
	BITMAP* help;
	BITMAP* tiro;
	BITMAP* tres;
	BITMAP* dois;
	BITMAP* um;
	BITMAP* ready; 
	BITMAP* waitp2;
	Imagem* imgPista;

    static void jogo_atualiza_tempo()
    {
        if (!pausado)
        {
            temporizador++;
            if (temporizador <= 2)
            {
                nivel = 1;
            }
            else if (temporizador%5000 == 0 && temporizador != 5000)
            {
                nivel++;
            }
        }
    } END_OF_FUNCTION(&Jogo::jogo_atualiza_tempo);
};

#endif	/* JOGO_H */
