/*
 * File:   Pista.cpp
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:14 PM
 */

#include <iostream>
#include "Pista.h"
#include "Obstaculo.h"

Pista::Pista(std::string caminho)
{
    this->imagem = NULL;
    this->numero_Personagens = 0;
    this->numero_Obstaculos = 0;
    this->posAtual = -3000;
    this->AcabarJogo = false;
    this->DoisJogadores = true;
    this->imgAtual = 1;
    this->pathImg = caminho;
    this->mudarImagem();
}

void Pista::mudarImagem()
{
    this->posAtual = -3000;
    tamanho.x = 800;
    tamanho.y = 3600;
    this->imagem = create_bitmap(800,3600);
    std::string aux = pathImg;

    if (imgAtual == 1)
    {
        aux += "1.bmp";
    }
    else if (imgAtual == 4)
    {
        aux += "3.bmp";
    }
    else
        aux += "2.bmp";

    this->imagem = load_bitmap(aux.c_str(), NULL);
    this->imgAtual++;
}


Pista::~Pista()
{
	if (this->imagem != NULL)
	{
		destroy_bitmap(this->imagem);
		this->imagem = NULL;
	}
}

bool Pista::Refresh(int tempo) //Testa as colisoes e altera a posAtual da pista
{
    if (this->posAtual < 0)
    {
        this->posAtual += VELOCIDADE_PISTA;
    }
    else
    {
        if (imgAtual == 5)
            this->AcabarJogo = true;
        else
            mudarImagem();
    }

    unsigned int i;
    Objeto* aux1;
    for (i = 0; i < this->objetos.size(); i++) //verifica se os objetos ativos nao foram comidos pela pista por baixo
    {
        aux1 = this->objetos[i];
        if(aux1->ativo)
        {
            if (aux1->tipo == OBSTACULO)
            {
                aux1->posicao.y += 10 + 5*aux1->aceleracao;
            }
            if (aux1->tipo == TIRO)
            {
                aux1->posicao.y -= VELOCIDADE_TIRO;
                if (aux1->posicao.y < -10)
                {
                    aux1->Morrer();
                }
                else
                {
                    testarColisoes(aux1);
                }
            }
            if(aux1->tipo == PERSONAGEM)
            {
                if(aux1->posicao.x < MIN_X)
                {
                    ((Personagem*)aux1)->frear();
                    ((Personagem*)aux1)->ir_direita();
                }
                else if( aux1->posicao.x > dimValida.x)
                {
                    ((Personagem*)aux1)->frear();
                    ((Personagem*)aux1)->ir_esquerda();
                }

                this->testarColisoes(((Personagem*)aux1));
            }

            if(aux1->posicao.y + aux1->tamanho.y*0.4 >= this->dimValida.y)
            {
                if (aux1->tipo == PERSONAGEM)
                {
                    ((Personagem *)aux1)->Morrer(tempo);
                    if (!this->DoisJogadores)
                    {
                        this->AcabarJogo = true;
                    }
                    else
                    {
                        this->DoisJogadores = false;
                    }
                }
                else
                    aux1->Morrer();
            }
        }
    }
    return true;
}

void Pista::testarColisoes(Objeto* obj)
{
    unsigned int i;
    for (i = 0; i < this->objetos.size(); i++)
    {
        if (this->objetos[i] != obj )
        {
            if (obj->tipo == PERSONAGEM)
            {
                ((Personagem*)obj)->Colidir(this->objetos[i]);
            }
            else
            {
                obj->Colidir(this->objetos[i]);
            }
        }
    }
}

void Pista::alterarAceleracao(int nivel)
{
    unsigned int i;
    for (i = 0; i < this->objetos.size(); i++)
    {
        this->objetos[i]->aceleracao = nivel;
    }
}

void Pista::terminar()
{
    int i, total = this->objetos.size();
    for (i = total - 1; i >= 0; i-- )
    {
    	if (this->objetos[i])
    		delete this->objetos[i];
    }

    std::cout << "\nTerminou o jogo";
}

void Pista::adicionarObjeto(Objeto* obj) throw(Erros)
{
    //testa se colide com algum outro obj ja existente na pista
    int i;
    bool colidiu = false;

    if (obj->ativo)
    {
        for (i = 0; !colidiu && (i < (numero_Personagens + numero_Obstaculos)); i++ )
        {
            if ((this->objetos[i]->ativo) && (this->objetos[i]->Colidir(obj) != NENHUMA))
            {
                std::cout << this->objetos[i]->Colidir(obj);
                throw COLIDIU_COM_OBJETO_TELA; //gera excecao, para pegar no try catch
                colidiu = true;
            }
        }
    }

    if (!colidiu)
    {
        this->objetos.push_back(obj);
        if (obj->tipo == PERSONAGEM)
        {
            numero_Personagens++;
        }
        if (obj->tipo == OBSTACULO)
        {
            numero_Obstaculos++;
        }
    }
}

