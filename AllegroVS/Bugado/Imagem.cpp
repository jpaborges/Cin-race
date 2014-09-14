#include "Imagem.h"

Imagem::Imagem(std::string caminho, BITMAP* bmpImg)
{
	this->path = caminho;
	this->img = bmpImg;
}

Imagem::~Imagem(void)
{
	if (this->img != NULL)
		destroy_bitmap(this->img);

	this->img = NULL;

}

