/*
 * File:   Jogo.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 6:44 PM
 */

#ifndef JOGO_H
#define	JOGO_H
#include "Pista.h"
#include <allegro.h>
#include <iostream>
#include <vector>
#include "Imagem.h"

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
    Jogo(Dimensao tela);
    virtual ~Jogo();
    CONTROLE status;
    void mudarStatus(CONTROLE novo_status);
    void exibirMenu();
	Imagem* criarImagem(Sprite obj);
    Pista* pista;

private:
    Dimensao tela;
	std::string strimgPista;
    bool temSom;
    void exibirSplash();
    void exibirAjuda();
    void novoJogo(int estagio);
    void finalizarJogo();
    void pausar();
    bool iniciarAllegro(std::string titulo,Dimensao tela );
    void imprimirObjetosTela();
    bool exibirPontuacao();
	void atualizarImgPista();
    void contagemRegressiva();
	BITMAP* encontrarImagem(char* caminho);
    SAMPLE* musica; //Ponteiro para musica.
	std::vector<Sprite> VetorSprites;
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
