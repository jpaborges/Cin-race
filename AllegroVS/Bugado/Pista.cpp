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
    //this->imagem = NULL;
    this->numero_Personagens = 0;
    this->numero_Obstaculos = 0;
    this->posAtual = -3000;
    this->AcabarJogo = false;
    this->DoisJogadores = true;
    this->imgAtual = 1;
    this->strcomecoCaminho = caminho;
    this->mudarImagem();
}

std::string Pista::getPathImg()
{ 
	return this->pathImg;
}

void Pista::mudarImagem()
{
    this->posAtual = -3000;
    tamanho.x = 800;
    tamanho.y = 3600;
    std::string aux = strcomecoCaminho;

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

    this->pathImg = aux;
	this->imgAtual++;
}


Pista::~Pista()
{
	this->pathImg = "NULL";
	/*if (this->imagem != NULL)
	{
		destroy_bitmap(this->imagem);
		this->imagem = NULL;
	}*/
}

bool Pista::criarPista(std::string caminho)
{
	this->numero_Personagens = 0;
    this->numero_Obstaculos = 0;
    this->posAtual = -3000;
    this->AcabarJogo = false;
    this->DoisJogadores = true;
    this->imgAtual = 1;
    this->strcomecoCaminho = caminho;
    this->mudarImagem();

	return true;
}
std::vector<Objeto*> Pista::getObjetos()
{
	return this->objetos;
}
void Pista::setDimValida(Dimensao DimValida)
{
	this->dimValida = DimValida;
}
bool Pista::getAcabarJogo()
{
	return this->AcabarJogo;
}
void Pista::setAcabarJogo(bool acabarJogo)
{
	this->AcabarJogo = acabarJogo;
}
int Pista::getPosAtual()
{
	return this->posAtual;
}
void Pista::setPosAtual(int posAtual)
{
	this->posAtual = posAtual;
}

bool Pista::getPausar()
{
	return this->pausado;
}
void Pista::setPausar(bool pausado)
{
	this->pausado = pausado;
}
bool Pista::Refresh(int tempo) //Testa as colisoes e altera a posAtual da pista
{
	Dimensao dimAux;
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
        if(aux1->getAtivo())
        {
            if (aux1->getTipo() == OBSTACULO)
            {
				dimAux = aux1->getPosicao();
                dimAux.y += 10 + 5*aux1->getAceleracao();
				aux1->setPosicao(dimAux);
				
            }
            if (aux1->getTipo() == TIRO)
            {
				dimAux = aux1->getPosicao();
                dimAux.y -= VELOCIDADE_TIRO;
				aux1->setPosicao(dimAux);
                if (aux1->getPosicao().y < -10)
                {
                    aux1->Morrer();
                }
                else
                {
                    testarColisoes(aux1);
                }
            }
            if(aux1->getTipo() == PERSONAGEM)
            {
                if(aux1->getPosicao().x < MIN_X)
                {
                    ((Personagem*)aux1)->frear();
                    ((Personagem*)aux1)->ir_direita();
                }
                else if( aux1->getPosicao().x > dimValida.x)
                {
                    ((Personagem*)aux1)->frear();
                    ((Personagem*)aux1)->ir_esquerda();
                }

                this->testarColisoes(((Personagem*)aux1));
            }

            if(aux1->getPosicao().y + aux1->getTamanho().y*0.4 >= this->dimValida.y)
            {
                if (aux1->getTipo() == PERSONAGEM)
                {
                    ((Personagem *)aux1)->MorrerPersonagem(tempo);
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
            if (obj->getTipo() == PERSONAGEM)
            {
                ((Personagem*)obj)->ColidirPersonagem(this->objetos[i]);
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
        this->objetos[i]->setAceleracao(nivel);
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

    if (obj->getAtivo())
    {
        for (i = 0; !colidiu && (i < (numero_Personagens + numero_Obstaculos)); i++ )
        {
            if ((this->objetos[i]->getAtivo()) && (this->objetos[i]->Colidir(obj) != NENHUMA))
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
        if (obj->getTipo() == PERSONAGEM)
        {
            numero_Personagens++;
        }
        if (obj->getTipo() == OBSTACULO)
        {
            numero_Obstaculos++;
        }
    }
}


int Pista::getNumeroJogador()
{
	return numero_Personagens;
}