/*
 * File:   Pista.cpp
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:14 PM
 */

#include <iostream>
#include "Pista.h"
#include "Obstaculo.h"

Pista::Pista()
{
    //this->imagem = NULL;
    this->numero_Personagens = 0;
    this->numero_Obstaculos = 0;
}

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





void Pista::setPosAtual(int posAtual)
{
	this->posAtual = posAtual;
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
		//Usado para criar a struct
		Sprite spriteAux;
		spriteAux.posicao = obj->getPosicao();
		spriteAux.tamanho = obj->getTamanho();
		strcpy(spriteAux.strImagem,obj->getStrSprite().c_str());
		spriteAux.ativo = obj->getAtivo();
		spriteAux.tipo = obj->getTipo();
		this->VetorSprites.push_back(spriteAux);

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

//Classes Realmente usadas pelo Cliente
void Pista::enviar_tecla(int tecla, int player){ //envia para ser processado para o servidor qual tecla foi precionada
	Personagem* aux = NULL;
	if (player == 1)
	{
		aux = player1;
	}

	if (player == 2)
	{
		aux = player2;
	}

	if (aux != NULL)
	{
		if (tecla == 0)
		{
			aux->ir_direita();
		}
		if (tecla == 1) //carrinho pra esquerda
        {
            aux->ir_esquerda();
        }
        if (tecla == 2) //carrinho pra cima
        {
            aux->ir_cima();
            aux->acelerar();
        }
        if (tecla == 3) //carrinho pra baixo
        {
            aux->ir_baixo();
        }
        if (tecla == 4)
        {
            aux->atirar();
        }
	}
}
void Pista::MorrerPersonagem(int player, int temporizador){
	if (player == 1)
	{
		player1->MorrerPersonagem(temporizador);
	}
	else
	{
		player2->MorrerPersonagem(temporizador);
	}
}
void Pista::setGodMod(int player){
	if (player == 1)
	{
		player1->setGodMod(true);
	}
	else
	{
		player2->setGodMod(true);
	}
}
bool Pista::getAtivo(int player)
{
	if (player == 1)
	{
		return player1->getAtivo();
	}
	else
	{
		return player2->getAtivo();
	}
}
void Pista::mudarImagemPersonagem(int player){
	if (player == 1)
	{
		return player1->mudarImagem();
	}
	else
	{
		return player2->mudarImagem();
	}
}
int Pista::getTempoFim(int player){
	if (player == 1)
	{
		return player1->getTempoFim();
	}
	else
	{
		return player2->getTempoFim();
	}
}
int	Pista::getObstaculosAtingidos(int player){
	if (player == 1)
	{
		return player1->getObstaculosAtingidos();
	}
	else
	{
		return player2->getObstaculosAtingidos();
	}
}
int	Pista::getScore(int player){
	if (player == 1)
	{
		return player1->getScore();
	}
	else
	{
		return player2->getScore();
	}
}
void Pista::testarColisoesPersonagem(int player){
	Personagem* aux = NULL;
	Dimensao dimAux;
	if (player == 1)
	{
		aux = player1;
	}

	if (player == 2)
	{
		aux = player2;
	}

	if (aux != NULL)
	{
		testarColisoes(aux);
		dimAux = aux->getPosicao();
		dimAux.y +=  VELOCIDADE_PISTA;
		aux->setPosicao(dimAux);
	}
}



std::string Pista::getPathImg()
{ 
	return this->pathImg;
}

bool Pista::getAcabarJogo()
{
	return this->AcabarJogo;
}
void Pista::setAcabarJogo(bool acabarJogo)
{
	this->AcabarJogo = acabarJogo;
}
int Pista::criarPersonagem()
{
	if (numero_Personagens == 0)
	{
		player1 = new Personagem(true,"resources/spiderman0",dimensao(490,400),dimensao(47,125),20,3, true);
		this->adicionarObjeto(player1);
		player1ID = this->objetos.size() - 1;
		this->adicionarObjeto(player1->getTiro());
		return 1;
	}
	else if (numero_Personagens == 1)
	{
		player2 = new Personagem(true,"resources/venom0",dimensao(90,400),dimensao(50,119),20,3,false);
		this->adicionarObjeto(player2);
		player2ID = this->objetos.size() - 1;
		this->adicionarObjeto(player2->getTiro());
		return 2;
	}
	else
	{
		return -1;
	}
}
bool Pista::getPausar()
{
	return this->pausado;
}
int Pista::getPosAtual()
{
	return this->posAtual;
}
void Pista::setPausar(bool pausado)
{
	this->pausado = pausado;
}
std::vector<Sprite> Pista::getObjetos()
{
	return VetorSprites;
}
int Pista::getID(int player)
{
	if (player == 1)
		return player1ID;
	else
		return player2ID;
}
Sprite Pista::getPersonagem(int player)
{
	Sprite spriteAux;
	Personagem* obj = NULL;

	if (player == 1)
		obj = player1;
	else
		obj = player2;

//Usado para criar a struct
	
	spriteAux.posicao = obj->getPosicao();
	spriteAux.tamanho = obj->getTamanho();
	strcpy(spriteAux.strImagem,obj->getStrSprite().c_str());
	spriteAux.ativo = obj->getAtivo();
	spriteAux.tipo = obj->getTipo();

	return spriteAux;

}

void Pista::criarPista(std::string caminho, Dimensao dimValida)
{
	this->numero_Personagens = 0;
    this->numero_Obstaculos = 0;
    this->posAtual = -3000;
    this->AcabarJogo = false;
    this->DoisJogadores = true;
    this->imgAtual = 1;
    this->strcomecoCaminho = caminho;
	this->dimValida = dimValida;
    this->mudarImagem();
}
int Pista::getNumeroJogador()
{
	return numero_Personagens;
}

int Pista::getMunicao(int player)
{
	if (player == 1)
		return player1->getMunicao();
	else
		return player2->getMunicao();
}

double Pista::getVelocidade(int player)
{
	if (player == 1)
		return player1->getVelocidade();
	else
		return player2->getVelocidade();
}

void Pista::iniciarJogo(int estagio)
{
	if (estagio == 1)
	{
		this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(100,-800),dimensao(40,52),-30)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-850),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-950),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-850),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-800),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-1300),dimensao(40,52),-40)); //parede diagonal direita
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-1350),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-1400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-1450),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-1500),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-1550),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-2800),dimensao(40,40),-110)); //random
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-2850),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-2950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-2950),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-2950),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-2950),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-3100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-3150),dimensao(40,52),50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-3200),dimensao(40,52),50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-3250),dimensao(40,52),50));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-3600),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-3750),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-3800),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-3825),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-3850),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-3875),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-3900),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-4300),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-4350),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-4700),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-4750),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-4900),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(500,-4950),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(550,-5200),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-5300),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-5400),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-5700),dimensao(40,52),20));

        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(100,-7000),dimensao(40,40),-110)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(150,-7050),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-7100),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(250,-7150),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(400,-7150),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(450,-7100),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-7050),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-7000),dimensao(40,40),-110));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-8500),dimensao(40,52),-50)); //funil reverso
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-8450),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-8400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-8300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-8350),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-8400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-8450),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-8500),dimensao(40,52),-60));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-10500),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-10550),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-10600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-10650),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-10650),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-10750),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-10800),dimensao(40,52),-50));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-11300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-11350),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-11400),dimensao(40,52),50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-11450),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-11500),dimensao(40,52),50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-11550),dimensao(40,52),-60));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-13000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-13100),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-13200),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-13300),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-13400),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-13500),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-13600),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-13900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-13950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-14000),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-14800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-14900),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-15000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-15100),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-15200),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-15300),dimensao(40,40),-110));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-15800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-15800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-15800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-15800),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-15800),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-16300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-16350),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-16400),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-16450),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-16500),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-16550),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-17000),dimensao(40,52),-50)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-17050),dimensao(40,52),70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-17100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-17150),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-17150),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-17100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(500,-17050),dimensao(40,52),70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-17000),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-17800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-17800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-17800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-17800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-17800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-17800),dimensao(40,40),-110));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-18200),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-18300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-18400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-18500),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-18600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-18700),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-18800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-18900),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-19000),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-19100),dimensao(40,52),-20));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-19900),dimensao(40,52),-30)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-19950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-20000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-20050),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-20050),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-20000),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-19950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-19900),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(50,-20700),dimensao(40,40),-110)); //parede diagonal direita
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(100,-20750),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(150,-20800),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-20850),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(250,-20900),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-20950),dimensao(40,40),-110));

        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-21800),dimensao(40,40),-110)); //random
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-21850),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-21950),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-21950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-21950),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-21950),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-22100),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-22150),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-22200),dimensao(40,52),-10));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-22250),dimensao(40,52),-20));

        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-23600),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-23750),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-23800),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(500,-23825),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-23850),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-23875),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-23900),dimensao(40,52),40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-24300),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-24350),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-24700),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-24750),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-24900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-24950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-25200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-25300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-25400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-25700),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-25600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-25700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-25800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-25900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-26000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-26100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-26200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-26300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-26400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-26600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-26700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-26800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-26900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-27000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-27100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-27200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-27300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-27400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-27600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-27700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-27800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-27900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-28000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-28100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-28200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-28300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-28400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-28600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-28700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-28800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-28900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-29000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-29100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-29200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-29300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-29400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-29600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-29700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-29800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-29900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-30000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-30100),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-30200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-30300),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-30400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-30600),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-30700),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-30800),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-30900),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-31000),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(350,-31100),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-31200),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-31300),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(500,-31400),dimensao(40,52),40));

        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(100,-31600),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(150,-31700),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-31800),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(250,-31900),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-32000),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(350,-32100),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(400,-32200),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(450,-32300),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-32400),dimensao(40,40),-110));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-32600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-32700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-32800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-32900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-33000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-33100),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-33200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-33300),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-33400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-33600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-33700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-33800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-33900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-34000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-34100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-34200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-34300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-34400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-34600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-34700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-34800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-34900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-35000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-35100),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-35200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-35300),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-35400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-35600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-35700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-35800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-35900),dimensao(40,52),-20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-36000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-36100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-36200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-36300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-36400),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-36600),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-36700),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-36800),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-36900),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-37000),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(350,-37100),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-37200),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-37300),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(500,-37400),dimensao(40,52),40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-37600),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-37700),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-37800),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-37900),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-38000),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(350,-38100),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-38200),dimensao(40,52),30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-38300),dimensao(40,52),20));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(500,-38400),dimensao(40,52),40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-38800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-38800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-38800),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-38800),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-38800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-38800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-38800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-38800),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-38800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-38800),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-39300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-39300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-39300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-39300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-39300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-39300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-39300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-39300),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-39300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-39300),dimensao(40,52),-40));
	}

	 if(estagio == 2)
    {
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-800),dimensao(40,52),-50)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-850),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-950),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-950),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-850),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-800),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-1300),dimensao(40,52),-50)); //parede diagonal direita
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-1350),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-1400),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-1450),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-1500),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-1550),dimensao(40,52),-60));

        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-2800),dimensao(40,40),-110)); //random
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-2850),dimensao(40,52),-90));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-2950),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-2950),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-2950),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-2950),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-3100),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-3150),dimensao(40,52),-10));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-3200),dimensao(40,52),-10));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-3250),dimensao(40,52),60));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-3600),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-3750),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-3800),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-3825),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-3850),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-3875),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-3900),dimensao(40,52),70));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-4300),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-4350),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-4700),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-4750),dimensao(40,52),-90));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-4900),dimensao(40,52),-90));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-4950),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-5200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-5300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-5400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-5700),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-7000),dimensao(40,52),-70)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-7050),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-7100),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-7150),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-7150),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-7100),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-7050),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-7000),dimensao(40,52),-70));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-8500),dimensao(40,52),-60)); //funil reverso
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-8450),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-8400),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-8300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-8350),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-8400),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-8450),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-8500),dimensao(40,52),-70));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(50,-10500),dimensao(40,52),-75));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-10550),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-10600),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-10650),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-10650),dimensao(40,52),80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-10750),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-10800),dimensao(40,52),-70));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(50,-11300),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-11350),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-11400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-11450),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-11500),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-11550),dimensao(40,52),-70));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-13000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-13100),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-13200),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-13300),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-13400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-13500),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(550,-13600),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-13900),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-13950),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-14000),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(50,-14800),dimensao(40,52),50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-14900),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-15000),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-15100),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-15200),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-15300),dimensao(40,40),-110));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-15800),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-15800),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-15800),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-15800),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-15800),dimensao(40,52),-80));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-16300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-16350),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-16400),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-16450),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-16500),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-16550),dimensao(40,52),-60));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-17000),dimensao(40,52),-80)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-17050),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-17100),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-17150),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-17150),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-17100),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-17050),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-17000),dimensao(40,52),-80));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-17800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-17800),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-17800),dimensao(40,52),80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-17800),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-17800),dimensao(40,52),-90));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-17800),dimensao(40,40),-110));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-18200),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-18300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-18400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-18500),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-18600),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-18700),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-18800),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-18900),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-19000),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-19100),dimensao(40,52),-70));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-19900),dimensao(40,52),-30)); //funil
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-19950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-20000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-20050),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-20050),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-20000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-19950),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-19900),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-20700),dimensao(40,52),-50)); //parede diagonal direita
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-20750),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-20800),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-20850),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-20900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-20950),dimensao(40,52),-50));

        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-21800),dimensao(40,40),-110)); //random
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-21850),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-21950),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-21950),dimensao(40,52),-80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-21950),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-21950),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(550,-22100),dimensao(40,52),40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-22150),dimensao(40,52),-10));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-22200),dimensao(40,52),-10));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-22250),dimensao(40,52),-10));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-23600),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-23750),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-23800),dimensao(40,40),-110));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-23825),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-23850),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-23875),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-23900),dimensao(40,52),-70));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-24300),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-24350),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-24700),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-24750),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-24900),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-24950),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-25200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-25300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-25400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-25700),dimensao(40,52),-50));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-25900),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-26000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-26100),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-26200),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-26300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-26400),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(550,-26900),dimensao(40,52),50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-26500),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-26600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-26700),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-27400),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-27600),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-27700),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-27800),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-28000),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-28200),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(200,-28300),dimensao(40,52),50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-28400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-28600),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-28700),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-28900),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-29000),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-29100),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-29200),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-29300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-29400),dimensao(40,52),-70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-29500),dimensao(40,52),70));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-29600),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-29700),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-29800),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-29900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-30000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-30100),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-30300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-30400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(200,-30500),dimensao(40,52),80));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-30600),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-30700),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-30800),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-30900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-31000),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-31100),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-31300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-31400),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-31500),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-31600),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-31700),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-31800),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-32300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-32400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-32500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-32600),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-32700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-32800),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-32900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-33000),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-33100),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-33200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-33400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-33500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-33600),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-33700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-33800),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-33900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-34000),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-34100),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-34200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-34400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-34500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-34600),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-34700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-34800),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-34900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-35000),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-35100),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-35200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-35400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-35500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-35600),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-35700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-35800),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-35900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-36000),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-36100),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(100,-36200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-36400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-36500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-36600),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-36700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-36800),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-36900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-37000),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(4350,-37100),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-37200),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-37400),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-37500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-37600),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-37700),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-37800),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-37900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-38000),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-38100),dimensao(40,52),-30));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-38500),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-38500),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-38500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-38500),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-38500),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-38500),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-38500),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-38500),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-38500),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-38500),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-38900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-38900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-38900),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-38900),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-38900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-38900),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-38900),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-38900),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-38900),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-38900),dimensao(40,52),-40));

        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-39300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-39300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-39300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-39300),dimensao(40,52),-60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-39300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-39300),dimensao(40,52),60));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-39300),dimensao(40,52),-50));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-39300),dimensao(40,52),-40));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-39300),dimensao(40,52),-30));
        this->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-39300),dimensao(40,52),-40));
    }
}
