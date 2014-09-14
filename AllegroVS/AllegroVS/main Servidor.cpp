#include "Pista.h"
#include <coss/CosNaming.h>
#include <CORBA.h>
#include <fstream>

using namespace std;

int main(){

	char *argv[] = { "ABC", "-ORBInitRef",
		"NameService=corbaloc::"};
	int argc = 3;
	char ip[255], aux[] = "NameService=corbaloc::";
	
	do{
		cout << "\nDigite o ip do SN: ";
		cin >> ip;
	}while( (ip[0] != '0') &&  (ip[0] != '1') && (ip[0] != '2') && (ip[0] != 'l'));

	strcat(ip,":9001/NameService");
	strcat(aux,ip);
	argv[2] = aux;


	CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
	CORBA::Object_var poaobj = orb->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(poaobj);
	PortableServer::POAManager_var mgr = poa->the_POAManager();
	PortableServer::Servant pista_servent = (PortableServer::Servant)new Pista;
	CORBA::Object_var acesso_pista = pista_servent->_this();
	CORBA::Object_var nsobj = orb->resolve_initial_references("NameService");
	CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow (nsobj);

	cout << "O servidor esta ativo\n";
	CosNaming::Name nome;
	nome.length (1);
	nome[0].id = (const char*)"ExtremeClimbing"; 
	nome[0].kind = (const char*)"";

	nc->rebind(nome, acesso_pista);


	mgr->activate(); //ative o POAManager
	orb->run(); 

	poa->destroy (TRUE, TRUE);
	delete pista_servent;

	return 0;
}