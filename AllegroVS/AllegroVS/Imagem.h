#pragma once
#include <iostream>
#include <allegro.h>
class Imagem
{
public:
	BITMAP* img;
	std::string path;
	Imagem(std::string caminho, BITMAP* bmpImg);
	~Imagem(void);
};
