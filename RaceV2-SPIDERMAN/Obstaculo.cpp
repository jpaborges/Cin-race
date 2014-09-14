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
    	std::cout << "ERRO IMG " << sprite;
    	this->ativo = false;
    }
}


Obstaculo::~Obstaculo()
{
}

