/*
 * File:   Jogo.cpp
 * Author: jpaborges
 *
 * Created on September 18, 2010, 6:44 PM
 */

#include "Jogo.h"
using namespace std;

Jogo::Jogo(Dimensao tela)
{
	imgPista = NULL;
	entrada1 = NULL;
	help = NULL;
	tiro = NULL;
	tres = NULL;
	dois = NULL;
	um = NULL;
	musica = NULL;
	ready = NULL;

    pausado = true;
    pista = NULL;
    temporizador = 0;
    this->tela = tela;
    if (iniciarAllegro("Extreme Climbing",this->tela))
    {
        status = NAO_INICIADO;
    }
    else
        std::cout << "Erro ao inicializar o allegro";
}

Imagem* Jogo::criarImagem(Objeto* obj){
	BITMAP* retorno = NULL;
	if (obj->getAtivo() && (obj->getStrSprite().compare("NULL") != 0))
	{
		retorno = create_bitmap(obj->getTamanho().x, obj->getTamanho().y);
		retorno = load_bitmap(obj->getStrSprite().c_str(), NULL);
	}
	return new Imagem(obj->getStrSprite(),retorno);
}

Jogo::~Jogo()
{
    if (pista != NULL)
        delete pista;
    allegro_exit();
}

void Jogo::exibirMenu()
{
    while (!key[KEY_ESC])
    {
        if (status == NAO_INICIADO)
            exibirSplash();
        else if (status == SPLASH)
        {
            if(key[KEY_C])
            {
                mudarStatus(NOVO_JOGO);
            }
            else if(key[KEY_H])
            {
                mudarStatus(AJUDA);
            }
            else if (key[KEY_P])
            {
                mudarStatus(CHEAT);
            }
        }
        else
        {
            if (key[KEY_ENTER] || key[KEY_B] || key[KEY_SPACE])
                status = NAO_INICIADO;
        }
    }

}

void Jogo::exibirSplash()
{
    status = SPLASH;
	if (entrada1 == NULL)
	{
		entrada1 = create_bitmap(800,600);
		entrada1 = load_bitmap("resources/entrada.bmp",NULL);
	}
    draw_sprite(buffer, entrada1, 0, 0);
    draw_sprite(screen, buffer, 0, 0);
}

bool Jogo::iniciarAllegro(std::string titulo,Dimensao tela )
{
    bool retorno = true;

    allegro_init();    //inicializa biblioteca do allegro
    set_window_title(titulo.c_str());  //titulo da janela

    install_keyboard(); //teclado
    install_timer();  //temporizador

    temSom = install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != -1; // Som
    if (!temSom)
    {
        temSom = install_sound(1330860868,DIGI_NONE, NULL) != -1;
    }

    set_color_depth(32);  //cor
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, tela.x, tela.y, 0, 0);  //resolucao da janela
    this->buffer = create_bitmap(tela.x,tela.y);
    clear(this->buffer);
    draw_sprite(screen,this->buffer,0,0);
    LOCK_VARIABLE(this->temporizador);
    LOCK_VARIABLE(this->nivel);
    LOCK_FUNCTION(jogo_atualiza_tempo);
    install_int_ex(&Jogo::jogo_atualiza_tempo,MSEC_TO_TIMER(1));

    return retorno;
}


BITMAP* Jogo::encontrarImagem(std::string caminho){
	BITMAP* retorno = NULL;
	unsigned int i, total = imgsObjetos.size();
	
	for (i = 0 ; i < total; i++)
	{
		if (imgsObjetos[i]->path.compare(caminho) == 0)
		{
			retorno = imgsObjetos[i]->img;
			break;
		}
	}
	return retorno;
}

void Jogo::imprimirObjetosTela()
{
    unsigned int i, total;
	BITMAP* bmpAuxiliar;
	std::vector<Objeto*> objetos =  pista->getObjetos();
	

	total = objetos.size();

    draw_sprite(screen,buffer,0,0);
    clear(buffer);
	atualizarImgPista();
	draw_sprite (buffer, imgPista->img,0, pista->getPosAtual());
    draw_sprite (buffer, imgmenu, 670,0);
    textprintf_ex(buffer, font, 680, 10, makecol(255, 255, 255), -1, "Time: %d s",(int) temporizador/1000);
    for (i = 0; i < total; i++)	
    {
        if (objetos[i] == personagem2)
        {
            textprintf_ex(buffer, font, 700, 300, makecol(255, 255, 255),
                          -1, "Player 1:");
            textprintf_ex(buffer, font, 700, 330, makecol(255, 255, 255),
                          -1, "Speed %.2f",((Personagem*)objetos[i])->getVelocidade());
            textprintf_ex(buffer, font, 700, 360, makecol(255, 255, 255),
                          -1, "Shoots %d",((Personagem*)objetos[i])->getMunicao());
        }

        if (objetos[i] == personagem1)
        {
            textprintf_ex(buffer, font, 700, 200, makecol(255, 255, 255),
                          -1, "Player 2:");
            textprintf_ex(buffer, font, 700, 230, makecol(255, 255, 255),
                          -1, "Speed %.2f",((Personagem*)objetos[i])->getVelocidade());
            textprintf_ex(buffer, font, 700, 260, makecol(255, 255, 255),
                          -1, "Shoots %d",((Personagem*)objetos[i])->getMunicao());
        }
		
		if (objetos[i]->getTipo() != TIRO)
		{
			bmpAuxiliar = encontrarImagem(objetos[i]->getStrSprite());
			if (bmpAuxiliar == NULL)
			{
				imgsObjetos.push_back(criarImagem(objetos[i]));
				bmpAuxiliar = imgsObjetos[imgsObjetos.size() - 1]->img;
			}
		}
		else
			bmpAuxiliar = tiro;

       if (objetos[i]->getAtivo())
		   draw_sprite(buffer, bmpAuxiliar ,objetos[i]->getPosicao().x, objetos[i]->getPosicao().y);
    }
}

void Jogo::contagemRegressiva()
{
	if (tres == NULL)
	{
		tres = create_bitmap(72,98);
		tres = load_bitmap("resources/3.bmp",NULL);
		dois = create_bitmap(74,100);
		dois = load_bitmap("resources/2.bmp",NULL);
		um = create_bitmap(73,100);
		um = load_bitmap("resources/1.bmp",NULL);
		ready = create_bitmap(274,97);
		ready = load_bitmap("resources/ready.bmp",NULL);
	}

    draw_sprite(buffer, tres, 300, 50);
    draw_sprite(screen, buffer, 0, 0);
    rest (800);
    draw_sprite(buffer, dois, 300, 150);
    draw_sprite(screen, buffer, 0, 0);
    rest (800);
    draw_sprite(buffer, um, 300, 250);
    draw_sprite(screen, buffer, 0, 0);
    rest (800);
    draw_sprite(buffer, ready, 250, 350);
    draw_sprite(screen, buffer, 0, 0);

    rest (400);
}


void Jogo::atualizarImgPista(){
	BITMAP* aux;
	
	if ((imgPista == NULL) || (imgPista->path.compare(pista->getPathImg()) != 0))
	{
		if (imgPista != NULL)
		{
			if (imgPista->img != NULL)
				destroy_bitmap(imgPista->img);
			imgPista->img = NULL;
			delete imgPista;
			imgPista = NULL;
		}
		aux = create_bitmap(800,3600);
		aux = load_bitmap(pista->getPathImg().c_str(), NULL);
		imgPista = new Imagem(pista->getPathImg(),aux);
	}


}

void Jogo::novoJogo(int estagio)
{
    bool mudarEstagio = false;
    bool veiodeEsc = false;
	Dimensao dimAux;
    int count = 0;
    if (estagio == 1)
    {
        pista = new Pista("resources/pista1_");
		pista->setDimValida(dimensao(600,600));
    }
    else
    {
        pista = new Pista("resources/pista2_");
        pista->setDimValida(dimensao(500,600));
    }

	atualizarImgPista();
	if (tiro == NULL)
	{
		tiro = create_bitmap(25,25);
		tiro = load_bitmap("resources/tiro1.bmp", NULL);
	}
	
	

    imgmenu = load_bitmap("resources/menu.bmp",NULL);

    //SOM
    if (temSom)
    {
		if (musica == NULL)
			 musica = load_sample("resources/som.wav");

        if (musica)
            play_sample(musica,255,90,1000,true);
        // play_midi(musica, TRUE); //Toca a musica.
    }

    //Personagens
    personagem1 = new Personagem(true,"resources/spiderman0",dimensao(490,400),dimensao(47,125),20,3, true);
    personagem2 = new Personagem(true,"resources/venom0",dimensao(90,400),dimensao(50,119),20,3,false);

    pista->adicionarObjeto(personagem1);
    pista->adicionarObjeto(personagem2);

    this->carregaJogo(estagio);


    //Tiro
    pista->adicionarObjeto(personagem1->getTiro());
    pista->adicionarObjeto(personagem2->getTiro());

    //Comeca o jogo propriamente dito...
    unsigned long int  tempoC1 = 0;
    unsigned long int  tempoC2  = 0;
    unsigned long int  tempoPista  = 0;
    unsigned long int  tempoImg1  = 0;
    unsigned long int  tempoImg2  = 0;
    pausado = false;

	while (!pista->getAcabarJogo())
    {
		if (pista->getPausar() == true)
		{
			this->pausar();
		}

        if (count == 2)
        {
            this->contagemRegressiva();
            temporizador = 0;
        }
        if (count <= 2)
        {
            count++;
        }

        if (key[KEY_SPACE])
        {
            this->pausar();
        }

        if (key[KEY_P])
        {
            mudarEstagio = true;
            break; //sai do laço
        }

        if (key[KEY_ESC])
        {
            veiodeEsc = true;
        }

        if ( veiodeEsc || pista->getAcabarJogo() || temporizador >= TIME_LIMITE)
        {
            pista->setAcabarJogo(true);
        }
        else
        {
            if (key[KEY_J])
				personagem2->setGodMod(true);  //cheat para nao colidir

            if (key[KEY_K])
                personagem1->setGodMod(true);  //cheat para nao colidir

            if (personagem1->getAtivo())
            {
                if (temporizador - tempoC1 >= INTERVALO_MOVIMENTO)
                {
                    if (key[KEY_RIGHT]) //carrinho pra direita
                    {
                        personagem1->ir_direita();
                    }
                    if (key[KEY_LEFT]) //carrinho pra esquerda
                    {
                        personagem1->ir_esquerda();
                    }
                    if (key[KEY_UP]) //carrinho pra cima
                    {
                        personagem1->ir_cima();
                        personagem1->acelerar();
                    }
                    if (key[KEY_DOWN]) //carrinho pra baixo
                    {
                        personagem1->ir_baixo();
                    }
                    if (key[KEY_RSHIFT])
                    {
                        personagem1->atirar();
                    }

                    tempoC1 = temporizador;
                    if (count > 2)
                    {
                        pista->testarColisoes(personagem1);
						dimAux = personagem1->getPosicao();
						dimAux.y +=  VELOCIDADE_PISTA;
						personagem1->setPosicao(dimAux);

                        if (temporizador - tempoImg1 >= (10 + INTERVALO_MOVIMENTO + INTERVALO_MOVIMENTO/personagem1->getVelocidade()))
                        {
                            personagem1->mudarImagem();
                            tempoImg1 = temporizador;

                        }
                    }
                }
            }

            if (personagem2->getAtivo())
            {
                if (temporizador - tempoC2 >= INTERVALO_MOVIMENTO)
                {
                    if (key[KEY_D]) //carrinho pra direita
                    {
                        personagem2->ir_direita();
                    }
                    if (key[KEY_A]) //carrinho pra esquerda
                    {
                        personagem2->ir_esquerda();
                    }
                    if (key[KEY_W]) //carrinho pra cima
                    {
                        personagem2->ir_cima();
                        personagem2->acelerar();
                    }
                    if (key[KEY_S]) //carrinho pra baixo
                    {
                        personagem2->ir_baixo();
                    }
                    if (key[KEY_Q]) //carrinho pra baixo
                    {
                        personagem2->atirar();
                    }
                    tempoC2 = temporizador;

                    if (count > 2)
                    {
                        pista->testarColisoes(personagem2);
                        dimAux = personagem2->getPosicao();
						dimAux.y +=  VELOCIDADE_PISTA;
						personagem2->setPosicao(dimAux);
                        if (temporizador - tempoImg2 >= (10 + INTERVALO_MOVIMENTO + INTERVALO_MOVIMENTO/personagem2->getVelocidade()))
                        {
                            personagem2->mudarImagem();
                            tempoImg2 = temporizador;
                        }
                    }
                }
            }

            if (temporizador - tempoPista > INTERVALO_MOVIMENTO)
            {
                pista->alterarAceleracao(nivel);
                pista->Refresh(temporizador);
                tempoPista = temporizador;
            }
            imprimirObjetosTela();

        }

    }

    if (!mudarEstagio)
    {
        if (personagem1->getAtivo())
            personagem1->MorrerPersonagem(temporizador);

        if (personagem2->getAtivo())
            personagem2->MorrerPersonagem(temporizador);

        if (!veiodeEsc)
        {
            veiodeEsc =	this->exibirPontuacao();
        }

        this->finalizarJogo();
        if (!veiodeEsc)
        {
            if (estagio == 1)
            {
                mudarStatus(CHEAT); //muda para a fase 2
            }
            else
            {
                status = NAO_INICIADO; // volta para  o menu principal
            }
        }
        else
        {
            status = NAO_INICIADO;
        }
    }
    else
    {
        this->finalizarJogo();
        novoJogo((estagio % 2) + 1);
    }


}

void Jogo::pausar()
{
    CONTROLE estadoAnterior = this->status;
	pista->setPausar(true);
    BITMAP* pause = create_bitmap(800,600);
    pause = load_bitmap("resources/pausa.bmp",NULL);
    draw_sprite(buffer, pause, 0, 0);
    draw_sprite(screen, buffer, 0, 0);

    this->status = PAUSA;
    pausado = true;

    rest(200);
    while (!key[KEY_SPACE]);
    rest(200); //Isso é para evitar condicoes de corrida

    pausado = false;
	destroy_bitmap(pause);
    this->status = estadoAnterior;
    pista->setPausar(false);
}

void Jogo::finalizarJogo()
{
    if (temSom)
        stop_sample(musica);

	delete imgPista;
	imgPista = NULL;
}

bool Jogo::exibirPontuacao()
{
    bool retorno = false;
    rest(200); //evita condicao de corrida;
    BITMAP* fase = create_bitmap(800,600);
    fase = load_bitmap("resources/fase.bmp",NULL);
    draw_sprite(buffer, fase, 0, 0);
    textprintf_ex(buffer, font, 212, 347, makecol(255, 255, 255),-1, "%d s",personagem2->getTempoFim()/1000);
    textprintf_ex(buffer, font, 493, 347, makecol(255, 255, 255),-1, "%d s",personagem1->getTempoFim()/1000);
	textprintf_ex(buffer, font, 263, 389, makecol(255, 255, 255),-1, "%d",personagem2->getObstaculosAtingidos());
    textprintf_ex(buffer, font, 544, 389, makecol(255, 255, 255),-1, "%d",personagem1->getObstaculosAtingidos());
    textprintf_ex(buffer, font, 223, 463, makecol(255, 255, 255),-1, "%d Points",personagem2->getScore());
    textprintf_ex(buffer, font, 502, 463, makecol(255, 255, 255),-1, "%d Points",personagem1->getScore());
    draw_sprite(screen, buffer, 0, 0);

    while (!key[KEY_C])// espera ate a tecla c ser apertada
    {
        if(key[KEY_ESC])
        {
            retorno = true;
            break;
        }
    }

    rest(200); //evita condicao de corrida;
	destroy_bitmap(fase);
    return retorno;
}

void Jogo::exibirAjuda()
{
	if (help == NULL)
	{
		help = create_bitmap(800,600);
		help = load_bitmap("resources/manual0.bmp",NULL);
	}
    draw_sprite(buffer, help, 0, 0);
    draw_sprite(screen, buffer, 0, 0);
}

void Jogo::mudarStatus(CONTROLE novo_status)
{

    if (novo_status == NOVO_JOGO)
    {
        status = NOVO_JOGO;
        // finalizarJogo();
        novoJogo(1);
    }
    else if (novo_status == MULTIPLAYER)
    {
        status = MULTIPLAYER;
        std::cout << "\nComecando jogo multiplayer\n";
    }
    else if (novo_status == RECORDES)
    {
        status = RECORDES;
        exibirPontuacao();
    }
    else if (novo_status == CHEAT)
    {
        status = CHEAT;
        //	finalizarJogo();
        novoJogo(2);
    }
    else if (novo_status == AJUDA)
    {
        status = AJUDA;
        exibirAjuda();
    }

}

void Jogo::carregaJogo(int estagio)
{
    //Adiciona todos os objetos da pista
    //os objetos com 110 sao bonus de tiro, os outros afetam a velocidade...
    //Obstaculos

    if(estagio == 1)
    {
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(100,-800),dimensao(40,52),-30)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-850),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-950),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-850),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-800),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-1300),dimensao(40,52),-40)); //parede diagonal direita
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-1350),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-1400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-1450),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-1500),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-1550),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-2800),dimensao(40,40),-110)); //random
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-2850),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-2950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-2950),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-2950),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-2950),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-3100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-3150),dimensao(40,52),50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-3200),dimensao(40,52),50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-3250),dimensao(40,52),50));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-3600),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-3750),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-3800),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-3825),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-3850),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-3875),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-3900),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-4300),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-4350),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-4700),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-4750),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-4900),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(500,-4950),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(550,-5200),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-5300),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-5400),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-5700),dimensao(40,52),20));

        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(100,-7000),dimensao(40,40),-110)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(150,-7050),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-7100),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(250,-7150),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(400,-7150),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(450,-7100),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-7050),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-7000),dimensao(40,40),-110));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-8500),dimensao(40,52),-50)); //funil reverso
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-8450),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-8400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-8300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-8350),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-8400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-8450),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-8500),dimensao(40,52),-60));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-10500),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-10550),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-10600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-10650),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-10650),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-10750),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-10800),dimensao(40,52),-50));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-11300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-11350),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-11400),dimensao(40,52),50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-11450),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-11500),dimensao(40,52),50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-11550),dimensao(40,52),-60));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-13000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-13100),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-13200),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-13300),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-13400),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-13500),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-13600),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-13900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-13950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-14000),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-14800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-14900),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-15000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-15100),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-15200),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-15300),dimensao(40,40),-110));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-15800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-15800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-15800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-15800),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-15800),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-16300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-16350),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-16400),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-16450),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-16500),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-16550),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-17000),dimensao(40,52),-50)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-17050),dimensao(40,52),70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-17100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-17150),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-17150),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-17100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(500,-17050),dimensao(40,52),70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-17000),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-17800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-17800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-17800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-17800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-17800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-17800),dimensao(40,40),-110));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-18200),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-18300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-18400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-18500),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-18600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-18700),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-18800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-18900),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-19000),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-19100),dimensao(40,52),-20));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-19900),dimensao(40,52),-30)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-19950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-20000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-20050),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-20050),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-20000),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-19950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-19900),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(50,-20700),dimensao(40,40),-110)); //parede diagonal direita
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(100,-20750),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(150,-20800),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-20850),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(250,-20900),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-20950),dimensao(40,40),-110));

        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-21800),dimensao(40,40),-110)); //random
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-21850),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-21950),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-21950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-21950),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-21950),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-22100),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-22150),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-22200),dimensao(40,52),-10));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-22250),dimensao(40,52),-20));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-23600),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-23750),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-23800),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(500,-23825),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-23850),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-23875),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-23900),dimensao(40,52),40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-24300),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-24350),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-24700),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-24750),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-24900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-24950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-25200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-25300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-25400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-25700),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-25600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-25700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-25800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-25900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-26000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-26100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-26200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-26300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-26400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-26600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-26700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-26800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-26900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-27000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-27100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-27200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-27300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-27400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-27600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-27700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-27800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-27900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-28000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-28100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-28200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-28300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-28400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-28600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-28700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-28800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-28900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-29000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-29100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-29200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-29300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-29400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-29600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-29700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-29800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-29900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-30000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-30100),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-30200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-30300),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-30400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-30600),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-30700),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-30800),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-30900),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-31000),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(350,-31100),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-31200),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-31300),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(500,-31400),dimensao(40,52),40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(100,-31600),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(150,-31700),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-31800),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(250,-31900),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-32000),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(350,-32100),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(400,-32200),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(450,-32300),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-32400),dimensao(40,40),-110));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-32600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-32700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-32800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-32900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-33000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-33100),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-33200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-33300),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-33400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-33600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-33700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-33800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-33900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-34000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-34100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-34200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-34300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-34400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-34600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-34700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-34800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-34900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-35000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-35100),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-35200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-35300),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-35400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-35600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-35700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-35800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-35900),dimensao(40,52),-20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-36000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-36100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-36200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-36300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-36400),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-36600),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-36700),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-36800),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-36900),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-37000),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(350,-37100),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-37200),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-37300),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(500,-37400),dimensao(40,52),40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-37600),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-37700),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(200,-37800),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-37900),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(300,-38000),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(350,-38100),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-38200),dimensao(40,52),30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-38300),dimensao(40,52),20));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(500,-38400),dimensao(40,52),40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-38800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-38800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-38800),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-38800),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-38800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-38800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-38800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-38800),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-38800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-38800),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-39300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-39300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-39300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-39300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-39300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-39300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-39300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-39300),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-39300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-39300),dimensao(40,52),-40));

    }

    if(estagio == 2)
    {
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-800),dimensao(40,52),-50)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-850),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-950),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-950),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-850),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-800),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-1300),dimensao(40,52),-50)); //parede diagonal direita
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-1350),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-1400),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-1450),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-1500),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-1550),dimensao(40,52),-60));

        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-2800),dimensao(40,40),-110)); //random
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-2850),dimensao(40,52),-90));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-2950),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-2950),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-2950),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-2950),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-3100),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-3150),dimensao(40,52),-10));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-3200),dimensao(40,52),-10));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(450,-3250),dimensao(40,52),60));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-3600),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-3750),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-3800),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-3825),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-3850),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-3875),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(450,-3900),dimensao(40,52),70));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-4300),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-4350),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-4700),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-4750),dimensao(40,52),-90));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-4900),dimensao(40,52),-90));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-4950),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-5200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-5300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-5400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-5700),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-7000),dimensao(40,52),-70)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-7050),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-7100),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-7150),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-7150),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-7100),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-7050),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(550,-7000),dimensao(40,52),-70));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-8500),dimensao(40,52),-60)); //funil reverso
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-8450),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-8400),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-8300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-8350),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-8400),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-8450),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-8500),dimensao(40,52),-70));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(50,-10500),dimensao(40,52),-75));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-10550),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-10600),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(500,-10650),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-10650),dimensao(40,52),80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-10750),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(250,-10800),dimensao(40,52),-70));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(50,-11300),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-11350),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-11400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-11450),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-11500),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-11550),dimensao(40,52),-70));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-13000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-13100),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-13200),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-13300),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-13400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-13500),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(550,-13600),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-13900),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-13950),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-14000),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(50,-14800),dimensao(40,52),50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-14900),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-15000),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-15100),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-15200),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-15300),dimensao(40,40),-110));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-15800),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-15800),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-15800),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-15800),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-15800),dimensao(40,52),-80));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-16300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-16350),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-16400),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-16450),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-16500),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-16550),dimensao(40,52),-60));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-17000),dimensao(40,52),-80)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-17050),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-17100),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-17150),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-17150),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-17100),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-17050),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-17000),dimensao(40,52),-80));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-17800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(100,-17800),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster2.bmp",dimensao(150,-17800),dimensao(40,52),80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-17800),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-17800),dimensao(40,52),-90));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(300,-17800),dimensao(40,40),-110));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-18200),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-18300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-18400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-18500),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-18600),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-18700),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-18800),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-18900),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-19000),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-19100),dimensao(40,52),-70));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-19900),dimensao(40,52),-30)); //funil
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-19950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-20000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-20050),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-20050),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-20000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-19950),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-19900),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(50,-20700),dimensao(40,52),-50)); //parede diagonal direita
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-20750),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-20800),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-20850),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-20900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-20950),dimensao(40,52),-50));

        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(200,-21800),dimensao(40,40),-110)); //random
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-21850),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-21950),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-21950),dimensao(40,52),-80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-21950),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-21950),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster3.bmp",dimensao(550,-22100),dimensao(40,52),40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-22150),dimensao(40,52),-10));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-22200),dimensao(40,52),-10));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-22250),dimensao(40,52),-10));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-23600),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-23750),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/ammo.bmp",dimensao(550,-23800),dimensao(40,40),-110));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-23825),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-23850),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-23875),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-23900),dimensao(40,52),-70));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-24300),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-24350),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-24700),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-24750),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-24900),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(500,-24950),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-25200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-25300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-25400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-25700),dimensao(40,52),-50));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-25900),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(300,-26000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-26100),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-26200),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-26300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-26400),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(550,-26900),dimensao(40,52),50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-26500),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-26600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-26700),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-27400),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-27600),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-27700),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-27800),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-28000),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-28200),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(200,-28300),dimensao(40,52),50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-28400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-28600),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-28700),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-28900),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-29000),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-29100),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-29200),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(150,-29300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-29400),dimensao(40,52),-70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(400,-29500),dimensao(40,52),70));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-29600),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-29700),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-29800),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-29900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-30000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-30100),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-30300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-30400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(200,-30500),dimensao(40,52),80));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-30600),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(100,-30700),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-30800),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-30900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-31000),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-31100),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-31300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-31400),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-31500),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-31600),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-31700),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(450,-31800),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-32300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(200,-32400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-32500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-32600),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(450,-32700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-32800),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-32900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-33000),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-33100),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-33200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-33400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-33500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-33600),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-33700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-33800),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-33900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-34000),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-34100),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-34200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-34400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-34500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-34600),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-34700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-34800),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-34900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-35000),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-35100),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(350,-35200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(400,-35400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-35500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-35600),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-35700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(250,-35800),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(300,-35900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(350,-36000),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-36100),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(100,-36200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(150,-36400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-36500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-36600),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-36700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(350,-36800),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(400,-36900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-37000),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(4350,-37100),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(550,-37200),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(500,-37400),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-37500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-37600),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-37700),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(150,-37800),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker3.bmp",dimensao(200,-37900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker2.bmp",dimensao(250,-38000),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(300,-38100),dimensao(40,52),-30));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-38500),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-38500),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-38500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-38500),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-38500),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-38500),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-38500),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-38500),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-38500),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-38500),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-38900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-38900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-38900),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-38900),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-38900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-38900),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-38900),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-38900),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-38900),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-38900),dimensao(40,52),-40));

        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(550,-39300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(500,-39300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(450,-39300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(400,-39300),dimensao(40,52),-60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(350,-39300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Booster1.bmp",dimensao(300,-39300),dimensao(40,52),60));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(250,-39300),dimensao(40,52),-50));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(200,-39300),dimensao(40,52),-40));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(150,-39300),dimensao(40,52),-30));
        pista->adicionarObjeto(new Obstaculo(true,"resources/Breaker1.bmp",dimensao(100,-39300),dimensao(40,52),-40));

    }
}
