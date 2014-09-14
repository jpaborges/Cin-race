#define USE_CONSOLE 
#define ALLEGRO_STATICLINK
#include "ICorba.h"
#include <iostream>
#include <fstream>
#include <coss/CosNaming.h>
#include "Jogo.h"

using namespace std;



int main(){
	char ip[255];
	do{
		cout << "\nDigite o ip do SN: ";
		cin >> ip;
	}while( (ip[0] != '0') &&  (ip[0] != '1') && (ip[0] != '2') && (ip[0] != 'l'));

	char *argv[] = { "ABC", "-ORBInitRef","NameService=corbaloc::172.16.0.4:9001 /NameService"};
	int argc = 3;
	
	char aux[] = "NameService=corbaloc::";
	
	strcat(ip,":9001/NameService");
	strcat(aux,ip);
	argv[2] = aux;


	try{
		CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
		CORBA::Object_var nsobj = orb->resolve_initial_references ("NameService");
		CosNaming::NamingContext_var nc =
		CosNaming::NamingContext::_narrow (nsobj);
		CosNaming::Name name;
		name.length (1);
		name[0].id = (const char*) "ExtremeClimbing";
		CORBA::Object_var obj;
		obj = nc->resolve (name);
		ICorba::IPista_var pista = ICorba::IPista::_narrow (obj);
		ICorba::Dimensao dim;
		dim.x = 800;
		dim.y = 600;
		try{
		pista->setAcabarJogo(false);
		Jogo * jogo = new Jogo(dim,pista);
		jogo->exibirMenu();
		delete jogo;
		}catch(...){
			pista->setAcabarJogo(true);
		}
	}catch(CORBA::Exception e)
	{
		cout << "\nERRO!!!\n\nVerifique se o servidor de nomes e o servidor está online.\nVerifique tambem os IPS\n";
	
	}

	system("PAUSE");
	
	return 0;
}
END_OF_MAIN()
