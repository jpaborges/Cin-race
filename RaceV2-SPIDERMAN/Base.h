/*
 *  Base.h
 *  AllegroJogo
 *
 *  Created by Joao Paulo Borges on 9/23/10.
 *  Copyright 2010 Dord. All rights reserved.
 *
 */

#ifndef BASE_H
#define	BASE_H
#include <allegro.h>
#include <time.h>
#include <iostream>
#define TIME_LIMITE 120000
#define MAX_X 535
#define MIN_X 85
#define VELOCIDADE_PISTA 10
#define VELOCIDADE_TIRO 50
#define VELOCIDADEMAX 30
#define VELOCIDADE_MINIMA 1
#define INTERVALO_MOVIMENTO 50
#define PERSONAGEM 0
#define OBSTACULO 1
#define TIRO 2


typedef struct dimensao
{
    int x;
    int y;
}Dimensao;

typedef enum erros
{
    COLIDIU_COM_OBJETO_TELA,
    NUMERO_MAXIMO_DE_PERSONAGENS,
    IMAGEM_NAO_ENCONTRADA
}Erros;

typedef enum direcao
{
    CIMA,
    BAIXO,
    ESQUERDA,
	DIREITA,
	NENHUMA
}Direcao;

static Dimensao dimensao(int x, int y)
{
	Dimensao ret;
	ret.x = x;
	ret.y = y;
	return ret;
}

static volatile unsigned long int temporizador;
static unsigned int nivel;
static bool pausado;

#endif	/* BASE_H */
