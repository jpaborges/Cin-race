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

}

double Personagem::getVelocidade()
{
    return this->velocidade;
}
void Personagem::setVelocidade(double velocidade)
{
    this->velocidade = velocidade;
}
int Personagem::getMunicao()
{
    return this->municao;
}
void Personagem::setMunicao(int municao)
{
    this->municao = municao;
}
Obstaculo* Personagem::getTiro()
{
    return this->tiro;
}
void Personagem::setTiro(Obstaculo* tiro)
{
    this->tiro = tiro;
}
int Personagem::getTempoFim()
{
    return this->tempoFim;
}
void Personagem::setTempoFim(int tempoFim)
{
    this->tempoFim = tempoFim;
}
int Personagem::getObstaculosAtingidos()
{
    return this->obstaculoAtingidos;
}
void Personagem::setObstaculosAtingidos(int ObstaculosAtingidos)
{
    this->obstaculoAtingidos = obstaculoAtingidos;
}
bool Personagem::getGodMod()
{
    return this->godmod;
}
void Personagem::setGodMod(bool godMod)
{
    this->godmod = godMod;
}
bool Personagem::getEhSpider()
{
    return this->ehSpider;
}
void Personagem::setEhSpider(bool ehSpider)
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

    this->sprite = create_bitmap(x, y);
    this->sprite = load_bitmap(aux.c_str(), NULL);

    if (sprite == NULL)
		std::cout << "ERRO DE IMAGEM do PERSONAGEM:  " << aux.c_str();

    tamanho.x = x;
    tamanho.y = y;
}


Personagem::~Personagem()
{
}

Direcao Personagem::Colidir(Objeto* obj)
{
    Direcao retorno = Objeto::Colidir(obj);
    int velocidadeFinal;
    if (!godmod)
    {
        if (retorno != NENHUMA)
        {
            if (obj->getTipo() == PERSONAGEM)
            {
                if (retorno == CIMA || retorno == BAIXO)
                {
                    if (retorno == CIMA)
                        ir_cima();
                    else
                        ir_baixo();


                    // Os personagens fream e igualam velocidade
                    if (this->velocidade <= ((Personagem*)obj)->velocidade)
                    {
                        velocidadeFinal = this->velocidade;
                    }
                    else
                    {
                        velocidadeFinal = ((Personagem*)obj)->velocidade;
                    }
                    this->velocidade = velocidadeFinal;
                    ((Personagem*)obj)->velocidade = velocidadeFinal;
                }
                else if (retorno == DIREITA)
                {
                    ((Personagem*)obj)->ir_esquerda();
                    this->frear();
                    ((Personagem*)obj)->frear();
                }
                else if (retorno == ESQUERDA)
                {
                    ((Personagem*)obj)->ir_direita();
                    this->frear();
                    ((Personagem*)obj)->frear();
                }

                if (((Personagem*)obj)->velocidade < VELOCIDADE_MINIMA)
                    ((Personagem*)obj)->velocidade = VELOCIDADE_MINIMA;

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


int Personagem::intColidir(Objeto* obj)
{
    Direcao d = Colidir(obj);
    return d;
}

bool Personagem::ir_direita()
{
    this->posicao.x += this->velocidade;
    imgAtual = 40;
    mudarImagem();
    return true;
}

bool Personagem::ir_esquerda()
{
    this->posicao.x -= this->velocidade;
    imgAtual = 20;
    mudarImagem();
    return true;
}
bool Personagem::ir_baixo()
{
    this->posicao.y += this->velocidade;
    imgAtual = 1;
    return true;
}

void Personagem::Morrer(int tempo)
{
    Objeto::Morrer();
    tempoFim = tempo;
}

bool Personagem::ir_cima()
{
    this->posicao.y -= (int) this->velocidade;
    if(this->posicao.y < 0)
        this->posicao.y = 0;

    return true;
}

bool Personagem::frear()
{
    this->velocidade--;
    if (this->velocidade <= VELOCIDADE_MINIMA)
        this->velocidade = VELOCIDADE_MINIMA;
    return true;

}

bool Personagem::acelerar()
{
    if (this->velocidade <= VELOCIDADEMAX)
    {
        this->velocidade += 0.30;
    }
    return true;
}

bool Personagem::atirar()
{
    if (!tiro->getAtivo())
    {
        if (municao > 0)
        {
            this->tiro->setAtivo(true);
            this->tiro->posicao.x = this->posicao.x + (this->tamanho.x - this->tiro->tamanho.x)/2;
            this->tiro->posicao.y = this->posicao.y  - this->tamanho.y*0.5;
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

int Personagem::getScore()
{
    int retorno = 0;

    retorno += tempoFim/10; //Acrecenta 100 pontos por segundo.
    retorno -= obstaculoAtingidos*30; //retira 30 pontos por obstaculo errado.
    retorno += bonus*50; //Acrescenta 50 pontos por bonus

    if (retorno < 0 || tempoFim/1000 == 0)
        retorno = 0;
    return retorno;
}
