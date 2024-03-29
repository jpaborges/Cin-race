/*
 * File:   Objeto.cpp
 * Author: jpaborges
 *
 * Created on September 18, 2010, 2:27 PM
 */

#include "Objeto.h"

Objeto::Objeto()
{
    // std::cout << "criado obj";
}

Objeto::~Objeto()
{
    this->Morrer();
}

Dimensao Objeto::getTamanho()
{
	return this->tamanho;
}

Dimensao Objeto::getPosicao()
{
	return this->posicao;
}

void Objeto::setTamanho(Dimensao Tamanho)
{
	this->tamanho = Tamanho;
}

void Objeto::setPosicao(Dimensao Posicao)
{
	this->posicao = Posicao;
}

int  Objeto::getAceleracao(){
	return this->aceleracao;
}
void  Objeto::setAceleracao(int Aceleracao)
{
	this->aceleracao = Aceleracao;
}
bool Objeto::getAtivo()
{
	return this->ativo;
}
void Objeto::setAtivo(bool ativo)
{
	this->ativo = ativo;
}

std::string Objeto::getStrSprite(){
	return this->strSprite;
}

void Objeto::setStrSprite(std::string sprite){
	this->strSprite = sprite;
}

int Objeto::getTipo ()
{
	return this->tipo;
}
void Objeto::setTipo(int tipo)
{
	this->tipo = tipo;
}

Objeto::Objeto(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho)
{
	this->strSprite = "NULL";
    this->ativo = ativo;
    if (sprite[sprite.length() -1 ] == 'p') //Para ver se a extensao da imagem termina em p. Ou seja é bmp
    {
		this->strSprite = sprite;
    }

    this->posicao = posicao;
    this->tamanho = tamanho;
    this->aceleracao = 1;
}

void Objeto::Morrer()
{
    this->ativo = false;
    if (this->tipo != TIRO)
    {
		this->strSprite = "NULL"; //Nenhuma imagem
    }
}

Direcao Objeto::Colidir(Objeto *obj)
{

    Direcao retorno = NENHUMA;
    bool colidiu = true;
    int alfa, beta;

    if (obj->ativo && this->ativo)
    {
        if ( (obj->posicao.x + obj->tamanho.x < this->posicao.x)
                || (this->posicao.x + this->tamanho.x < obj->posicao.x)
                || (obj->posicao.y + obj->tamanho.y < this->posicao.y)
                || (this->posicao.y + this->tamanho.y < obj->posicao.y)
           )
        {
            colidiu = false;
        }

        if (colidiu)
        {
            //Se o obj for um tiro e ele colidir com algum obstaculo entao o obstaculo morre
            if (this->tipo == TIRO)
            {
                if (obj->tipo == OBSTACULO)
                {
                    obj->Morrer();
                }
            }

            if (this->posicao.x <= obj->posicao.x)
            {
                if (this->posicao.y >= obj->posicao.y)
                {
                    alfa = this->posicao.x + this->tamanho.x - obj->posicao.x;
                    beta = obj->posicao.y + obj->tamanho.y - this->posicao.y;
                    if (alfa >= beta)
                    {
                        retorno = BAIXO;
                    }
                    else
                    {
                        retorno = ESQUERDA;
                    }
                }
                else
                {
                    alfa = this->posicao.x + this->tamanho.x - obj->posicao.x;
                    beta = this->posicao.y + this->tamanho.y - obj->posicao.y;
                    if (alfa >= beta)
                    {
                        retorno = CIMA;
                    }
                    else
                    {
                        retorno = ESQUERDA;
                    }
                }
            }
            else
            {
                if (this->posicao.y >= obj->posicao.y)
                {
                    alfa = obj->posicao.x + obj->tamanho.x - this->posicao.x;
                    beta = obj->posicao.y + obj->tamanho.y - this->posicao.y;
                    if (alfa >= beta)
                    {
                        retorno = BAIXO;
                    }
                    else
                    {
                        retorno = DIREITA;
                    }
                }
                else
                {
                    alfa = obj->posicao.x + obj->tamanho.x - this->posicao.x;
                    beta = this->posicao.y + this->tamanho.y - obj->posicao.y;
                    if (alfa >= beta)
                    {
                        retorno = CIMA;
                    }
                    else
                    {
                        retorno = DIREITA;
                    }
                }
            }
        }
    }
    return retorno; //- retângulos se colidem
}

