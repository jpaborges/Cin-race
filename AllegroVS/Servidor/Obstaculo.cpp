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
    if (this->sprite == NULL)
    {
    	std::cout << "ERRO IMG " << sprite.c_str();
    	this->ativo = false;
    }
}

bool Obstaculo::criarObstaculo(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, double funcionalidade) 
{
	this->sprite = NULL;
    this->ativo = ativo;
    if (sprite[sprite.length() -1 ] == 'p') //Para ver se a extensao da imagem termina em p. Ou seja é bmp
    {
        this->sprite = create_bitmap(tamanho.x, tamanho.y);
        this->sprite = load_bitmap(sprite.c_str(), NULL);
    }

    this->posicao = posicao;
    this->tamanho = tamanho;
    this->aceleracao = 1;

	this->tipo = OBSTACULO;
    this->funcionalidade = funcionalidade;
    if (this->sprite == NULL)
    {
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

