/*
 * File:   Pista.h
 * Author: jpaborges
 *
 * Created on September 18, 2010, 4:14 PM
 */

#ifndef PISTA_H
#define	PISTA_H
#include "Objeto.h"
#include "Personagem.h"
#include <vector>

class Pista : POA_ICorba::IPista {
public:
	Pista();
	Pista(std::string caminho);
    virtual ~Pista();

    CORBA::Boolean Refresh( CORBA::Long tempo );
    void alterarAceleracao( CORBA::Long aceleracao );
    CORBA::Boolean criarPista( const char* caminho, const ::ICorba::Dimensao& dimValida );
    CORBA::Boolean getAcabarJogo();
    void setAcabarJogo( CORBA::Boolean acabarJogo );
    CORBA::Long getPosAtual();
    ::ICorba::IPista::vetor_objetos_slice* getObjetos();
    char* getPathImg();
    CORBA::Boolean getPausar();
    void setPausar( CORBA::Boolean pausado );
    CORBA::Long criarPersonagem();
    CORBA::Long getNumeroJogador();
    void iniciarJogo( CORBA::Long estagio );
    CORBA::Long getMunicao( CORBA::Long player );
    CORBA::Double getVelocidadein( CORBA::Long player );
    void enviar_tecla( CORBA::Long tecla, CORBA::Long player );
    void MorrerPersonagem( CORBA::Long player, CORBA::Long temporizador );
    void setGodMod( CORBA::Long player );
    CORBA::Boolean getAtivo( CORBA::Long player );
    void testarColisoesPersonagem( CORBA::Long player );
    void mudarImagemPersonagem( CORBA::Long player );
    CORBA::Long getTempoFim( CORBA::Long player );
    CORBA::Long getObstaculosAtingidos( CORBA::Long player );
    CORBA::Long getScore( CORBA::Long player );
    CORBA::Long getID( CORBA::Long player );
    ::ICorba::Sprite getPersonagem( CORBA::Long player );

private:
    void adicionarObjeto(Objeto* obj) throw(Erros);
    void terminar();
    void testarColisoes(Objeto* obj);
	void setPosAtual(int);	
	void setPathImg (std::string PathImg);
	int player1ID;
	int player2ID;

	bool AcabarJogo;
	bool pausado;
    int posAtual;
	bool DoisJogadores;
    int numero_Personagens;
    int numero_Obstaculos;
    void mudarImagem();
	std::string strcomecoCaminho;
    int imgAtual;
	int numVetorSprite;
    char pathImg[255];
	std::vector<Objeto*> objetos;
	::ICorba::IPista::vetor_objetos_slice VetorSprites[400];
	Personagem* player1;
	Personagem* player2;
	Dimensao tamanho;
    Dimensao dimValida;
	//BITMAP *imagem;
};

#endif	/* PISTA_H */
