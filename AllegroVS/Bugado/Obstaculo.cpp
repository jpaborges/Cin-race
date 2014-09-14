/*
 * File:   Obstaculo.cpp
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:12 PM
 */

#include "Obstaculo.h"

/*Obstaculo::Obstaculo(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, double funcionalidade)
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
}*/
Obstaculo::Obstaculo()
{
	this->tipo = OBSTACULO;
}

CORBA::Boolean Obstaculo::criarObstaculo( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, 
										 const ::ICorba::Dimensao& tamanho, CORBA::Double funcionalidade )
{
	this->setStrSprite("NULL");
    this->setAtivo(ativo);
    if (sprite[strlen(sprite) -1 ] == 'p') //Para ver se a extensao da imagem termina em p. Ou seja é bmp
    {
		strcpy(this->strSprite,sprite);
    }
    this->posicao = posicao;
    this->tamanho = tamanho;
    this->aceleracao = 1;

	this->tipo = OBSTACULO;
    this->funcionalidade = funcionalidade;
    if (strcmp(this->strSprite,"NULL") == 0)
    {
    	this->ativo = false;
    }
	return true;
}

CORBA::Double Obstaculo::getFuncionalidade()
{
	return funcionalidade;
}



