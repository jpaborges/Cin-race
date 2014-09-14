#include <iostream>
#include <time.h>
#include "Jogo.h"

int main()
{
	Jogo * jogo = new Jogo(dimensao(800, 600));
	jogo->exibirMenu();
    delete jogo;

    return 0;
}
END_OF_MAIN()
