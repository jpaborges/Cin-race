/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __ICORBA_H__
#define __ICORBA_H__






namespace ICorba
{

class IPista;
typedef IPista *IPista_ptr;
typedef IPista_ptr IPistaRef;
typedef ObjVar< IPista > IPista_var;
typedef ObjOut< IPista > IPista_out;

}






namespace ICorba
{

struct Dimensao;
typedef TFixVar< Dimensao > Dimensao_var;
typedef Dimensao& Dimensao_out;


struct Dimensao {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef Dimensao_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  Dimensao();
  ~Dimensao();
  Dimensao( const Dimensao& s );
  Dimensao& operator=( const Dimensao& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  CORBA::Long x;
  CORBA::Long y;
};

enum Direcao {
  CIMA = 0,
  BAIXO,
  ESQUERDA,
  DIREITA,
  NENHUMA
};

typedef Direcao& Direcao_out;

struct Sprite;
typedef TFixVar< Sprite > Sprite_var;
typedef Sprite& Sprite_out;


struct Sprite {
  #ifdef HAVE_TYPEDEF_OVERLOAD
  typedef Sprite_var _var_type;
  #endif
  #ifdef HAVE_EXPLICIT_STRUCT_OPS
  Sprite();
  ~Sprite();
  Sprite( const Sprite& s );
  Sprite& operator=( const Sprite& s );
  #endif //HAVE_EXPLICIT_STRUCT_OPS

  Dimensao posicao;
  Dimensao tamanho;
  CORBA::Char strImagem[ 255 ];
  CORBA::Long tipo;
  CORBA::Boolean ativo;
};


/*
 * Base class and common definitions for interface IPista
 */

class IPista : 
  virtual public CORBA::Object
{
  public:
    virtual ~IPista();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IPista_ptr _ptr_type;
    typedef IPista_var _var_type;
    #endif

    static IPista_ptr _narrow( CORBA::Object_ptr obj );
    static IPista_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IPista_ptr _duplicate( IPista_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IPista_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    typedef Sprite vetor_objetos[ 400 ];
    typedef Sprite vetor_objetos_slice;
    typedef ArrayFixVar< Sprite,vetor_objetos_slice,vetor_objetos,400 > vetor_objetos_var;
    typedef vetor_objetos vetor_objetos_out;
    enum _dummy_vetor_objetos { _dummy_vetor_objetos_0 };
    typedef ArrayFixForAny < Sprite,vetor_objetos_slice,vetor_objetos,400,_dummy_vetor_objetos> vetor_objetos_forany;
    #undef MICO_ARRAY_ARG
    #define MICO_ARRAY_ARG Sprite
    DECLARE_ARRAY_ALLOC(vetor_objetos,MICO_ARRAY_ARG,vetor_objetos_slice,400)
    DECLARE_ARRAY_DUP(vetor_objetos,MICO_ARRAY_ARG,vetor_objetos_slice,400)
    DECLARE_ARRAY_FREE(vetor_objetos,MICO_ARRAY_ARG,vetor_objetos_slice,400)
    DECLARE_ARRAY_COPY(vetor_objetos,MICO_ARRAY_ARG,vetor_objetos_slice,400)
    virtual CORBA::Boolean Refresh( CORBA::Long tempo ) = 0;
    virtual void alterarAceleracao( CORBA::Long aceleracao ) = 0;
    virtual CORBA::Boolean criarPista( const char* caminho, const ::ICorba::Dimensao& dimValida ) = 0;
    virtual CORBA::Boolean getAcabarJogo() = 0;
    virtual void setAcabarJogo( CORBA::Boolean acabarJogo ) = 0;
    virtual CORBA::Long getPosAtual() = 0;
    virtual ::ICorba::IPista::vetor_objetos_slice* getObjetos() = 0;
    virtual char* getPathImg() = 0;
    virtual CORBA::Boolean getPausar() = 0;
    virtual void setPausar( CORBA::Boolean pausado ) = 0;
    virtual CORBA::Long criarPersonagem() = 0;
    virtual CORBA::Long getNumeroJogador() = 0;
    virtual void iniciarJogo( CORBA::Long estagio ) = 0;
    virtual CORBA::Long getMunicao( CORBA::Long player ) = 0;
    virtual CORBA::Double getVelocidadein( CORBA::Long player ) = 0;
    virtual void enviar_tecla( CORBA::Long tecla, CORBA::Long player ) = 0;
    virtual void MorrerPersonagem( CORBA::Long player, CORBA::Long temporizador ) = 0;
    virtual void setGodMod( CORBA::Long player ) = 0;
    virtual CORBA::Boolean getAtivo( CORBA::Long player ) = 0;
    virtual void testarColisoesPersonagem( CORBA::Long player ) = 0;
    virtual void mudarImagemPersonagem( CORBA::Long player ) = 0;
    virtual CORBA::Long getTempoFim( CORBA::Long player ) = 0;
    virtual CORBA::Long getObstaculosAtingidos( CORBA::Long player ) = 0;
    virtual CORBA::Long getScore( CORBA::Long player ) = 0;
    virtual CORBA::Long getID( CORBA::Long player ) = 0;
    virtual ::ICorba::Sprite getPersonagem( CORBA::Long player ) = 0;

  protected:
    IPista() {};
  private:
    IPista( const IPista& );
    void operator=( const IPista& );
};

// Stub for interface IPista
class IPista_stub:
  virtual public IPista
{
  public:
    virtual ~IPista_stub();
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
    void operator=( const IPista_stub& );
};

#ifndef MICO_CONF_NO_POA

class IPista_stub_clp :
  virtual public IPista_stub,
  virtual public PortableServer::StubBase
{
  public:
    IPista_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~IPista_stub_clp ();
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

  protected:
    IPista_stub_clp ();
  private:
    void operator=( const IPista_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


#ifndef MICO_CONF_NO_POA



namespace POA_ICorba
{

class IPista : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~IPista ();
    ICorba::IPista_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static IPista * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual CORBA::Boolean Refresh( CORBA::Long tempo ) = 0;
    virtual void alterarAceleracao( CORBA::Long aceleracao ) = 0;
    virtual CORBA::Boolean criarPista( const char* caminho, const ::ICorba::Dimensao& dimValida ) = 0;
    virtual CORBA::Boolean getAcabarJogo() = 0;
    virtual void setAcabarJogo( CORBA::Boolean acabarJogo ) = 0;
    virtual CORBA::Long getPosAtual() = 0;
    virtual ::ICorba::IPista::vetor_objetos_slice* getObjetos() = 0;
    virtual char* getPathImg() = 0;
    virtual CORBA::Boolean getPausar() = 0;
    virtual void setPausar( CORBA::Boolean pausado ) = 0;
    virtual CORBA::Long criarPersonagem() = 0;
    virtual CORBA::Long getNumeroJogador() = 0;
    virtual void iniciarJogo( CORBA::Long estagio ) = 0;
    virtual CORBA::Long getMunicao( CORBA::Long player ) = 0;
    virtual CORBA::Double getVelocidadein( CORBA::Long player ) = 0;
    virtual void enviar_tecla( CORBA::Long tecla, CORBA::Long player ) = 0;
    virtual void MorrerPersonagem( CORBA::Long player, CORBA::Long temporizador ) = 0;
    virtual void setGodMod( CORBA::Long player ) = 0;
    virtual CORBA::Boolean getAtivo( CORBA::Long player ) = 0;
    virtual void testarColisoesPersonagem( CORBA::Long player ) = 0;
    virtual void mudarImagemPersonagem( CORBA::Long player ) = 0;
    virtual CORBA::Long getTempoFim( CORBA::Long player ) = 0;
    virtual CORBA::Long getObstaculosAtingidos( CORBA::Long player ) = 0;
    virtual CORBA::Long getScore( CORBA::Long player ) = 0;
    virtual CORBA::Long getID( CORBA::Long player ) = 0;
    virtual ::ICorba::Sprite getPersonagem( CORBA::Long player ) = 0;

  protected:
    IPista () {};

  private:
    IPista (const IPista &);
    void operator= (const IPista &);
};

}


#endif // MICO_CONF_NO_POA

extern CORBA::StaticTypeInfo *_marshaller_ICorba_Dimensao;

extern CORBA::StaticTypeInfo *_marshaller_ICorba_Direcao;

extern CORBA::StaticTypeInfo *_marshaller_ICorba_Sprite;

extern CORBA::StaticTypeInfo *_marshaller_ICorba_IPista;

extern CORBA::StaticTypeInfo *_marshaller__a255_char;

extern CORBA::StaticTypeInfo *_marshaller__a400_ICorba_Sprite;

#endif
