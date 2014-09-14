/*
 * File:   Jogo.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 6:44 PM
 */

#ifndef JOGO_H
#define	JOGO_H
#include "Pista.h"

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
    Pista* pista;
    Personagem* personagem1;
    Personagem* personagem2;

private:
    Dimensao tela;
    BITMAP* buffer;
    BITMAP* imgmenu;
    bool temSom;
    void exibirSplash();
    void exibirAjuda();
    void novoJogo(int estagio);
    void finalizarJogo();
    void pausar();
    void carregaJogo(int);
    bool iniciarAllegro(std::string titulo,Dimensao tela );
    void imprimirObjetosTela();
    bool exibirPontuacao();
    void contagemRegressiva();
    SAMPLE* musica; //Ponteiro para musica.

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
