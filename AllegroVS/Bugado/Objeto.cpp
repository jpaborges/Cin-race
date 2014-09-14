#include "Objeto.h"

ICorba::Direcao Objeto::Colidir( ICorba::IObjeto* obj ){
	ICorba::Direcao retorno = ICorba::NENHUMA;
    bool colidiu = true;
    int alfa, beta;

    if (obj->getAtivo() && this->ativo)
    {
        if ( (obj->getPosicao().x + obj->getTamanho().x < this->posicao.x)
                || (this->posicao.x + this->tamanho.x < obj->getPosicao().x)
                || (obj->getPosicao().y + obj->getTamanho().y < this->posicao.y)
                || (this->posicao.y + this->getTamanho().y < obj->getPosicao().y)
           )
        {
            colidiu = false;
        }

        if (colidiu)
        {
            //Se o obj for um tiro e ele colidir com algum obstaculo entao o obstaculo morre
            if (this->tipo == TIRO)
            {
                if (obj->getTipo() == OBSTACULO)
                {
                    obj->Morrer();
                }
            }

            if (this->posicao.x <= obj->getPosicao().x)
            {
                if (this->posicao.y >= obj->getPosicao().y)
                {
                    alfa = this->posicao.x + this->tamanho.x - obj->getPosicao().x;
                    beta = obj->getPosicao().y + obj->getTamanho().y - this->posicao.y;
                    if (alfa >= beta)
                    {
                        retorno = ICorba::BAIXO;
                    }
                    else
                    {
                        retorno = ICorba::ESQUERDA;
                    }
                }
                else
                {
                    alfa = this->posicao.x + this->tamanho.x - obj->getPosicao().x;
                    beta = this->posicao.y + this->tamanho.y - obj->getPosicao().y;
                    if (alfa >= beta)
                    {
                        retorno = ICorba::CIMA;
                    }
                    else
                    {
                        retorno = ICorba::ESQUERDA;
                    }
                }
            }
            else
            {
                if (this->posicao.y >= obj->getPosicao().y)
                {
                    alfa = obj->getPosicao().x + obj->getTamanho().x - this->posicao.x;
                    beta = obj->getPosicao().y + obj->getTamanho().y - this->posicao.y;
                    if (alfa >= beta)
                    {
                        retorno = ICorba::BAIXO;
                    }
                    else
                    {
                        retorno = ICorba::DIREITA;
                    }
                }
                else
                {
                    alfa = obj->getPosicao().x + obj->getTamanho().x - this->posicao.x;
                    beta = this->posicao.y + this->tamanho.y - obj->getPosicao().y;
                    if (alfa >= beta)
                    {
                        retorno = ICorba::CIMA;
                    }
                    else
                    {
                        retorno = ICorba::DIREITA;
                    }
                }
            }
        }
    }
    return retorno; //- retângulos se colidem
}
void Objeto::Morrer(){
    this->ativo = false;
    if (this->tipo != TIRO)
    {
		this->strSprite = "NULL"; //Nenhuma imagem
    }
}

CORBA::Boolean Objeto::getAtivo(){
	return this->ativo;
}
void Objeto::setAtivo( CORBA::Boolean ativo ){
	this->ativo = ativo;
}
char* Objeto::getStrSprite(){
	return this->strSprite;
}
void Objeto::setStrSprite( const char* sprite ){
	strcpy(this->strSprite,sprite);
}
CORBA::Long Objeto::getTipo(){
	return this->tipo;
}
void Objeto::setTipo( CORBA::Long tipo ){
	this->tipo = tipo;
}
ICorba::Dimensao Objeto::getPosicao(){
	return this->posicao;
}
void Objeto::setPosicao( const ::ICorba::Dimensao& Posicao ){
	this->posicao = Posicao;
}
::ICorba::Dimensao Objeto::getTamanho(){
	return this->tamanho;
}

void Objeto::setTamanho( const ::ICorba::Dimensao& Tamanho ){
	this->tamanho = Tamanho;
}
CORBA::Long Objeto::getAceleracao(){
	return this->aceleracao;
}
void Objeto::setAceleracao( CORBA::Long Aceleracao ){
	this->aceleracao = Aceleracao;
}