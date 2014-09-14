/*
 * File:   Personagem.cpp
 * Author: jpaborges
 *
 * Created on September 18, 2010, 3:50 PM
 */

#include "Personagem.h"
using namespace std;

Personagem::Personagem()
{
    this->tipo = PERSONAGEM;
}
/*
Personagem::Personagem(bool ativo, std::string sprite, Dimensao posicao, Dimensao tamanho, int velocidadeInicial, int municaoInicial, bool spider)
    : Objeto(ativo,sprite,posicao,tamanho)
{
    this->tipo = PERSONAGEM;
    this->velocidade = velocidadeInicial;
    this->municao = municaoInicial;
    this->tiro = new Obstaculo(false,"resources/tiro1.bmp",dimensao(400,-550),dimensao(25,25),-90);
	this->tiro->setTipo(TIRO);
    this->pathImg = sprite;
    this->imgAtual = 0;
    this->ehSpider = ehSpider;
    mudarImagem();
    obstaculoAtingidos = 0;
    tirosRecebidos = 0;
    bonus = 0;
    godmod = false;

}*/

CORBA::Double Personagem::getVelocidade()
{
    return this->velocidade;
}
void Personagem::setVelocidade(CORBA::Double velocidade)
{
    this->velocidade = velocidade;
}
CORBA::Long Personagem::getMunicao()
{
    return this->municao;
}
void Personagem::setMunicao(CORBA::Long municao)
{
    this->municao = municao;
}
ICorba::IObstaculo* Personagem::getTiro()
{
    return (ICorba::IObstaculo*)this->tiro;
}
CORBA::Long Personagem::getTempoFim()
{
    return this->tempoFim;
}
void Personagem::setTempoFim(CORBA::Long tempoFim)
{
    this->tempoFim = tempoFim;
}
CORBA::Long Personagem::getObstaculosAtingidos()
{
    return this->obstaculoAtingidos;
}
void Personagem::setObstaculosAtingidos(CORBA::Long ObstaculosAtingidos)
{
    this->obstaculoAtingidos = obstaculoAtingidos;
}
CORBA::Boolean Personagem::getGodMod()
{
    return this->godmod;
}
void Personagem::setGodMod(CORBA::Boolean godMod)
{
    this->godmod = godMod;
}
CORBA::Boolean Personagem::getEhSpider()
{
    return this->ehSpider;
}
void Personagem::setEhSpider(CORBA::Boolean ehSpider)
{
    this->ehSpider = ehSpider;
}

void Personagem::mudarImagem()
{
    string aux = pathImg;
    int x, y;



    if (ehSpider == true)
    {
        switch (imgAtual)
        {
            //subindo
        case 1:
            x = 43;
            y = 75;
            aux += "4.bmp";
            imgAtual++;
            break;
        case 2:
            x = 45;
            y = 76;
            aux += "1.bmp";
            imgAtual++;
            break;
        case 3:
            x = 43;
            y = 75;
            aux += "4.bmp";
            imgAtual++;
            break;
        case 4:
            x = 45;
            y = 76;
            aux += "12.bmp";
            imgAtual++;
            break;

        case 20:
            x = 54;
            y = 55;
            aux += "11.bmp";
            imgAtual++;
            break;
        case 21:
            x = 60;
            y = 55;
            aux += "10.bmp";
            imgAtual = 1;
            break;

            //direita -- 40
        case 40:
            x = 54;
            y = 55;
            aux += "7.bmp";
            imgAtual++;
            break;
        case 41:
            x = 60;
            y = 55;
            aux += "8.bmp";
            imgAtual = 1;
            break;

            //atiranado -- 60
        case 60:
            x = 47;
            y = 54;
            aux += "9.bmp";
            imgAtual++;
            break;
        case 61:
            x = 45;
            y = 84;
            aux += "13.bmp";
            imgAtual = 1;
            break;


        default:
            x = 43;
            y = 75;
            aux += "4.bmp";
            imgAtual = 2;
            break;
        }
    }
    else
    {
        switch (imgAtual)
        {
            //subindo
        case 1:
            x = 50;
            y = 76;
            aux += "8.bmp";
            imgAtual++;
            break;
        case 2:
            x = 50;
            y = 94;
            aux += "5.bmp";
            imgAtual++;
            break;
        case 3:
            x = 59;
            y = 91;
            aux += "4.bmp";
            imgAtual++;
            break;
        case 4:
            x = 50;
            y = 94;
            aux += "5.bmp";
            imgAtual++;
            break;
        case 5:
            x = 50;
            y = 76;
            aux += "8.bmp";
            imgAtual++;
            break;
        case 6:
            x = 50;
            y = 94;
            aux += "7.bmp";
            imgAtual++;
            break;
        case 7:
            x = 55;
            y = 91;
            aux += "6.bmp";
            imgAtual++;
            break;


            //esquerda -- 20
        case 20:
            x = 42;
            y = 111;
            aux += "2.bmp";
            imgAtual = 1;
            break;

            //direita -- 40
        case 40:
            x = 42;
            y = 111;
            aux += "3.bmp";
            imgAtual = 1;
            break;

            //atiranado -- 60
        case 60:
            x = 47;
            y = 119;
            aux += "1.bmp";
            imgAtual++;
            break;
        case 61:
            x = 47;
            y = 119;
            aux += "1.bmp";
            imgAtual = 1;
            break;


        default:
            x = 50;
            y = 76;
            aux += "8.bmp";
            imgAtual = 2;
            break;
        }
    }
	
	this->setStrSprite(aux.c_str());
	ICorba::Dimensao dim;
	dim.x = x;
	dim.y = y;
    this->setTamanho(dim);
}



ICorba::Direcao Personagem::ColidirPersonagem( ICorba::IObjeto* obj ) 
{
	ICorba::Direcao retorno = ICorba::IObjeto::Colidir(obj);
    int velocidadeFinal;
    if (!godmod)
    {
        if (retorno != ICorba::NENHUMA)
        {
            if (obj->getTipo() == PERSONAGEM)
            {
                if (retorno == ICorba::CIMA || retorno == ICorba::BAIXO)
                {
                    if (retorno == ICorba::CIMA)
                        this->ir_cima();
                    else
                        ir_baixo();


                    // Os personagens fream e igualam velocidade
					if (this->velocidade <= ((ICorba::IPersonagem*)obj)->getVelocidade())
                    {
                        velocidadeFinal = this->velocidade;
                    }
                    else
                    {
                        velocidadeFinal = ((Personagem*)obj)->getVelocidade();
                    }
                    this->velocidade = velocidadeFinal;
                    ((Personagem*)obj)->setVelocidade(velocidadeFinal);
                }
                else if (retorno == ICorba::DIREITA)
                {
                    ((Personagem*)obj)->ir_esquerda();
                    this->frear();
                    ((Personagem*)obj)->frear();
                }
                else if (retorno == ICorba::ESQUERDA)
                {
                    ((Personagem*)obj)->ir_direita();
                    this->frear();
                    ((Personagem*)obj)->frear();
                }

                if (((Personagem*)obj)->getVelocidade() < VELOCIDADE_MINIMA)
                    ((Personagem*)obj)->setVelocidade(VELOCIDADE_MINIMA);

            }
            else
            {
                //Objeto é do tipo obstaculo

                if ( ((Obstaculo*)obj)->getFuncionalidade() == -110) // Se a funcionalidade for -110 entao ganha municao
                {
                    municao++;
                }
                else
                {
                    this->velocidade += this->velocidade*0.01*((Obstaculo*)obj)->getFuncionalidade();//funcionalidade é dado em %
                    if(this->velocidade > 65)
                    this->velocidade = 65;
                    else if(this->velocidade < 0)
                    this->velocidade = 1;

                }

                ((Obstaculo*)obj)->Morrer();
                if (obj->getTipo() == TIRO)
                {
                    tirosRecebidos++;
                }
                else
                {
                    if (((Obstaculo*)obj)->getFuncionalidade() > 0)
                        bonus++;
                    else
                        obstaculoAtingidos++;
                }
            }

            if (this->velocidade < VELOCIDADE_MINIMA)
                this->velocidade = VELOCIDADE_MINIMA;
        }
    }
    return retorno;

}

CORBA::Boolean Personagem::ir_direita()
{
    this->posicao.x += this->velocidade;
    imgAtual = 40;
    mudarImagem();
    return true;
}

CORBA::Boolean Personagem::ir_esquerda()
{
    this->posicao.x -= this->velocidade;
    imgAtual = 20;
    mudarImagem();
    return true;
}
CORBA::Boolean Personagem::ir_baixo()
{
    this->posicao.y += this->velocidade;
    imgAtual = 1;
    return true;
}

void Personagem::MorrerPersonagem( CORBA::Long tempo ) 
{
	this->ativo = false;
    tempoFim = tempo;
}

CORBA::Boolean Personagem::ir_cima()
{
    this->posicao.y -= (int) this->velocidade;
    if(this->posicao.y < 0)
        this->posicao.y = 0;

    return true;
}

CORBA::Boolean Personagem::frear()
{
    this->velocidade--;
    if (this->velocidade <= VELOCIDADE_MINIMA)
        this->velocidade = VELOCIDADE_MINIMA;
    return true;

}

CORBA::Boolean Personagem::acelerar()
{
    if (this->velocidade <= VELOCIDADEMAX)
    {
        this->velocidade += 0.30;
    }
    return true;
}

CORBA::Boolean Personagem::atirar()
{
	ICorba::Dimensao dimAux;
    if (!tiro->getAtivo())
    {
        if (municao > 0)
        {
            this->tiro->setAtivo(true);
            dimAux.x = this->posicao.x + (this->tamanho.x - this->tiro->getTamanho().x)/2;
            dimAux.y = this->posicao.y  - this->tamanho.y*0.5;
			this->tiro->setPosicao(dimAux);
            municao--;
            imgAtual = 60;
            mudarImagem();
            return true;

        }
        else
            return false;
    }
    else
        return false;
}

void Personagem::girar()
{
    imgAtual = 20;
    mudarImagem();
}

CORBA::Long  Personagem::getScore()
{
    int retorno = 0;

    retorno += tempoFim/10; //Acrecenta 100 pontos por segundo.
    retorno -= obstaculoAtingidos*30; //retira 30 pontos por obstaculo errado.
    retorno += bonus*50; //Acrescenta 50 pontos por bonus

    if (retorno < 0 || tempoFim/1000 == 0)
        retorno = 0;
    return retorno;
}

CORBA::Boolean Personagem::criarPersonagem( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Long velocidadeInicial, CORBA::Long municaoInicial, CORBA::Boolean spider )
{
	this->strSprite = "NULL";
    this->ativo = ativo;
    if (sprite[strlen(sprite) -1 ] == 'p') //Para ver se a extensao da imagem termina em p. Ou seja é bmp
    {
		strcpy(this->strSprite,sprite);
    }

    this->posicao = posicao;
    this->tamanho = tamanho;
    this->aceleracao = 1;

	this->tipo = PERSONAGEM;
    this->velocidade = velocidadeInicial;
    this->municao = municaoInicial;
	//this->tiro1 = new Objeto();
	//this->tiro = new Obstaculo();
	//false,"resources/tiro1.bmp",dimensao(400,-550),dimensao(25,25),-90);
	this->tiro->setTipo(TIRO);
    this->pathImg = sprite;
    this->imgAtual = 0;
    this->ehSpider = ehSpider;
    mudarImagem();
    obstaculoAtingidos = 0;
    tirosRecebidos = 0;
    bonus = 0;
    godmod = false;
	return true;
}