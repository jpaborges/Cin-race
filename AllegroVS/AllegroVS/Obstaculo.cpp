/*
 * File:   Obstaculo.cpp
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:12 PM
 */

#include "Obstaculo.h"

Obstaculo::Obstaculo(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, double funcionalidade)
    : Objeto(ativo,sprite,posicao,tamanho)
{
    this->tipo = OBSTACULO;
    this->funcionalidade = funcionalidade;
    if (this->strSprite.c_str() == "NULL")
    {
		//this->strSprite = "NULL";
    	std::cout << "ERRO IMG " << sprite.c_str();
    	this->ativo = false;
    }
}

bool Obstaculo::criarObstaculo(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, double funcionalidade) 
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

	this->tipo = OBSTACULO;
    this->funcionalidade = funcionalidade;
    if (this->strSprite.c_str() == "NULL")
    {
		//this->strSprite = "NULL";
    	std::cout << "ERRO IMG " << sprite.c_str();
    	this->ativo = false;
    }
	return true;
}

double Obstaculo::getFuncionalidade()
{
	return funcionalidade;
}

Obstaculo::~Obstaculo()
{
}

