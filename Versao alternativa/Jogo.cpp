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

Imagem* Jogo::criarImagem(Sprite obj){
	BITMAP* retorno = NULL;
	if (obj.ativo && (strcmp(obj.strImagem,"NULL") != 0))
	{
		retorno = create_bitmap(obj.tamanho.x, obj.tamanho.y);
		retorno = load_bitmap(obj.strImagem, NULL);
	}
	return new Imagem(obj.strImagem,retorno);
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


BITMAP* Jogo::encontrarImagem(char* caminho){
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
	std::vector<Sprite> objetos =  this->VetorSprites;
	objetos[pista->getID(1)] = pista->getPersonagem(1);
	objetos[pista->getID(2)] = pista->getPersonagem(2);

	total = objetos.size();

    draw_sprite(screen,buffer,0,0);
    clear(buffer);
	atualizarImgPista();
	draw_sprite (buffer, imgPista->img,0, pista->getPosAtual());
    draw_sprite (buffer, imgmenu, 670,0);
    textprintf_ex(buffer, font, 680, 10, makecol(255, 255, 255), -1, "Time: %d s",(int) temporizador/1000);
    
	//Texto Player 1
	  textprintf_ex(buffer, font, 700, 300, makecol(255, 255, 255),
                          -1, "Player 1:");
      textprintf_ex(buffer, font, 700, 330, makecol(255, 255, 255),
                          -1, "Speed %.2f",pista->getVelocidade(1));
      textprintf_ex(buffer, font, 700, 360, makecol(255, 255, 255),
                          -1, "Shoots %d",pista->getMunicao(1));
  //Texto Player 2
	 textprintf_ex(buffer, font, 700, 200, makecol(255, 255, 255),
                          -1, "Player 2:");
     textprintf_ex(buffer, font, 700, 230, makecol(255, 255, 255),
                          -1, "Speed %.2f",pista->getVelocidade(2));
     textprintf_ex(buffer, font, 700, 260, makecol(255, 255, 255),
                          -1, "Shoots %d",pista->getMunicao(2));
	
	for (i = 0; i < total; i++)	
    {

		if (objetos[i].tipo != TIRO)
		{
			bmpAuxiliar = encontrarImagem(objetos[i].strImagem);
			if (bmpAuxiliar == NULL)
			{
				imgsObjetos.push_back(criarImagem(objetos[i]));
				bmpAuxiliar = imgsObjetos[imgsObjetos.size() - 1]->img;
			}
		}
		else
			bmpAuxiliar = tiro;

       if (objetos[i].ativo)
		   draw_sprite(buffer, bmpAuxiliar ,objetos[i].posicao.x, objetos[i].posicao.y);
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
	int numPersonagem;
	Dimensao dimAux;
    int count = 0;

    if (estagio == 1)
    {
        pista = new Pista();
		pista->criarPista("resources/pista1_",dimensao(600,600));
    }
    else
    {
        pista = new Pista();
        pista->criarPista("resources/pista2_",dimensao(500,600));
    }
	pista->iniciarJogo(estagio);
	

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
	//Comeca o jogo propriamente dito...
	if (pista->getNumeroJogador() > 2) //já tem 2 jogadores jogando
	{
		//Fazer uma rotina de tratamento de erro
		std::cout << "ERRO!!!Excedido numero de jogadore\n";
	}
	else
	{
		numPersonagem = pista->criarPersonagem();
		pista->criarPersonagem();

		while (pista->getNumeroJogador() != 2);//Espera Ocupada

		VetorSprites = pista->getObjetos();

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
				if (key[KEY_G])
					pista->setGodMod(numPersonagem);

				if (pista->getAtivo(numPersonagem))
				{
					if (temporizador - tempoC1 >= INTERVALO_MOVIMENTO)
					{
						if (key[KEY_RIGHT]) //carrinho pra direita -- 0
						{
							pista->enviar_tecla(0,numPersonagem);
						}
						if (key[KEY_LEFT]) //carrinho pra esquerda -- 1
						{
							pista->enviar_tecla(1,numPersonagem);
						}
						if (key[KEY_UP]) //carrinho pra cima -- 2
						{
							pista->enviar_tecla(2,numPersonagem);
						}
						if (key[KEY_DOWN]) //carrinho pra baixo -- 3
						{
							pista->enviar_tecla(3,numPersonagem);
						}
						if (key[KEY_RSHIFT]) //Atirar -- 4
						{
							pista->enviar_tecla(4,numPersonagem);
						}

						tempoC1 = temporizador;
						if (count > 2)
						{
							pista->testarColisoesPersonagem(1);
							pista->testarColisoesPersonagem(2);

							if (temporizador - tempoImg1 >= (10 + INTERVALO_MOVIMENTO + INTERVALO_MOVIMENTO/pista->getVelocidade(numPersonagem)))
							{
								pista->mudarImagemPersonagem(numPersonagem);
								tempoImg1 = temporizador;
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
			if (pista->getAtivo(numPersonagem))
				pista->MorrerPersonagem(numPersonagem,temporizador);

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
    textprintf_ex(buffer, font, 212, 347, makecol(255, 255, 255),-1, "%d s",pista->getTempoFim(2)/1000);
    textprintf_ex(buffer, font, 493, 347, makecol(255, 255, 255),-1, "%d s",pista->getTempoFim(1)/1000);
	textprintf_ex(buffer, font, 263, 389, makecol(255, 255, 255),-1, "%d",pista->getObstaculosAtingidos(2));
    textprintf_ex(buffer, font, 544, 389, makecol(255, 255, 255),-1, "%d",pista->getObstaculosAtingidos(1));
    textprintf_ex(buffer, font, 223, 463, makecol(255, 255, 255),-1, "%d Points",pista->getScore(2));
    textprintf_ex(buffer, font, 502, 463, makecol(255, 255, 255),-1, "%d Points",pista->getScore(1));
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


