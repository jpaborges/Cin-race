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

class IObjeto;
typedef IObjeto *IObjeto_ptr;
typedef IObjeto_ptr IObjetoRef;
typedef ObjVar< IObjeto > IObjeto_var;
typedef ObjOut< IObjeto > IObjeto_out;

class IObstaculo;
typedef IObstaculo *IObstaculo_ptr;
typedef IObstaculo_ptr IObstaculoRef;
typedef ObjVar< IObstaculo > IObstaculo_var;
typedef ObjOut< IObstaculo > IObstaculo_out;

class IPersonagem;
typedef IPersonagem *IPersonagem_ptr;
typedef IPersonagem_ptr IPersonagemRef;
typedef ObjVar< IPersonagem > IPersonagem_var;
typedef ObjOut< IPersonagem > IPersonagem_out;

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


/*
 * Base class and common definitions for interface IObjeto
 */

class IObjeto : 
  virtual public CORBA::Object
{
  public:
    virtual ~IObjeto();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IObjeto_ptr _ptr_type;
    typedef IObjeto_var _var_type;
    #endif

    static IObjeto_ptr _narrow( CORBA::Object_ptr obj );
    static IObjeto_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IObjeto_ptr _duplicate( IObjeto_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IObjeto_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::ICorba::Direcao Colidir( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual void Morrer() = 0;
    virtual CORBA::Boolean getAtivo() = 0;
    virtual void setAtivo( CORBA::Boolean ativo ) = 0;
    virtual char* getStrSprite() = 0;
    virtual void setStrSprite( const char* sprite ) = 0;
    virtual CORBA::Long getTipo() = 0;
    virtual void setTipo( CORBA::Long tipo ) = 0;
    virtual ::ICorba::Dimensao getPosicao() = 0;
    virtual void setPosicao( const ::ICorba::Dimensao& Posicao ) = 0;
    virtual ::ICorba::Dimensao getTamanho() = 0;
    virtual void setTamanho( const ::ICorba::Dimensao& Tamanho ) = 0;
    virtual CORBA::Long getAceleracao() = 0;
    virtual void setAceleracao( CORBA::Long Aceleracao ) = 0;

  protected:
    IObjeto() {};
  private:
    IObjeto( const IObjeto& );
    void operator=( const IObjeto& );
};

// Stub for interface IObjeto
class IObjeto_stub:
  virtual public IObjeto
{
  public:
    virtual ~IObjeto_stub();
    ::ICorba::Direcao Colidir( ::ICorba::IObjeto_ptr obj );
    void Morrer();
    CORBA::Boolean getAtivo();
    void setAtivo( CORBA::Boolean ativo );
    char* getStrSprite();
    void setStrSprite( const char* sprite );
    CORBA::Long getTipo();
    void setTipo( CORBA::Long tipo );
    ::ICorba::Dimensao getPosicao();
    void setPosicao( const ::ICorba::Dimensao& Posicao );
    ::ICorba::Dimensao getTamanho();
    void setTamanho( const ::ICorba::Dimensao& Tamanho );
    CORBA::Long getAceleracao();
    void setAceleracao( CORBA::Long Aceleracao );

  private:
    void operator=( const IObjeto_stub& );
};

#ifndef MICO_CONF_NO_POA

class IObjeto_stub_clp :
  virtual public IObjeto_stub,
  virtual public PortableServer::StubBase
{
  public:
    IObjeto_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~IObjeto_stub_clp ();
    ::ICorba::Direcao Colidir( ::ICorba::IObjeto_ptr obj );
    void Morrer();
    CORBA::Boolean getAtivo();
    void setAtivo( CORBA::Boolean ativo );
    char* getStrSprite();
    void setStrSprite( const char* sprite );
    CORBA::Long getTipo();
    void setTipo( CORBA::Long tipo );
    ::ICorba::Dimensao getPosicao();
    void setPosicao( const ::ICorba::Dimensao& Posicao );
    ::ICorba::Dimensao getTamanho();
    void setTamanho( const ::ICorba::Dimensao& Tamanho );
    CORBA::Long getAceleracao();
    void setAceleracao( CORBA::Long Aceleracao );

  protected:
    IObjeto_stub_clp ();
  private:
    void operator=( const IObjeto_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface IObstaculo
 */

class IObstaculo : 
  virtual public ::ICorba::IObjeto
{
  public:
    virtual ~IObstaculo();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IObstaculo_ptr _ptr_type;
    typedef IObstaculo_var _var_type;
    #endif

    static IObstaculo_ptr _narrow( CORBA::Object_ptr obj );
    static IObstaculo_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IObstaculo_ptr _duplicate( IObstaculo_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IObstaculo_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual CORBA::Boolean criarObstaculo( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Double funcionalidade ) = 0;
    virtual CORBA::Double getFuncionalidade() = 0;

  protected:
    IObstaculo() {};
  private:
    IObstaculo( const IObstaculo& );
    void operator=( const IObstaculo& );
};

// Stub for interface IObstaculo
class IObstaculo_stub:
  virtual public IObstaculo,
  virtual public ::ICorba::IObjeto_stub
{
  public:
    virtual ~IObstaculo_stub();
    CORBA::Boolean criarObstaculo( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Double funcionalidade );
    CORBA::Double getFuncionalidade();

  private:
    void operator=( const IObstaculo_stub& );
};

#ifndef MICO_CONF_NO_POA

class IObstaculo_stub_clp :
  virtual public IObstaculo_stub,
  virtual public ::ICorba::IObjeto_stub_clp
{
  public:
    IObstaculo_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~IObstaculo_stub_clp ();
    CORBA::Boolean criarObstaculo( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Double funcionalidade );
    CORBA::Double getFuncionalidade();

  protected:
    IObstaculo_stub_clp ();
  private:
    void operator=( const IObstaculo_stub_clp & );
};

#endif // MICO_CONF_NO_POA


/*
 * Base class and common definitions for interface IPersonagem
 */

class IPersonagem : 
  virtual public ::ICorba::IObjeto
{
  public:
    virtual ~IPersonagem();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef IPersonagem_ptr _ptr_type;
    typedef IPersonagem_var _var_type;
    #endif

    static IPersonagem_ptr _narrow( CORBA::Object_ptr obj );
    static IPersonagem_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static IPersonagem_ptr _duplicate( IPersonagem_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static IPersonagem_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual ::ICorba::Direcao ColidirPersonagem( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual CORBA::Boolean criarPersonagem( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Long velocidadeInicial, CORBA::Long municaoInicial, CORBA::Boolean spider ) = 0;
    virtual CORBA::Boolean ir_esquerda() = 0;
    virtual CORBA::Boolean ir_direita() = 0;
    virtual CORBA::Boolean acelerar() = 0;
    virtual CORBA::Boolean ir_baixo() = 0;
    virtual CORBA::Boolean ir_cima() = 0;
    virtual CORBA::Boolean frear() = 0;
    virtual CORBA::Boolean atirar() = 0;
    virtual void MorrerPersonagem( CORBA::Long tempo ) = 0;
    virtual void mudarImagem() = 0;
    virtual CORBA::Long getScore() = 0;
    virtual CORBA::Double getVelocidade() = 0;
    virtual void setVelocidade( CORBA::Double velocidade ) = 0;
    virtual CORBA::Long getMunicao() = 0;
    virtual void setMunicao( CORBA::Long municao ) = 0;
    virtual ::ICorba::IObstaculo_ptr getTiro() = 0;
    virtual CORBA::Long getTempoFim() = 0;
    virtual void setTempoFim( CORBA::Long tempoFim ) = 0;
    virtual CORBA::Long getObstaculosAtingidos() = 0;
    virtual void setObstaculosAtingidos( CORBA::Long ObstaculosAtingidos ) = 0;
    virtual CORBA::Boolean getGodMod() = 0;
    virtual void setGodMod( CORBA::Boolean godMod ) = 0;
    virtual CORBA::Boolean getEhSpider() = 0;
    virtual void setEhSpider( CORBA::Boolean ehSpider ) = 0;

  protected:
    IPersonagem() {};
  private:
    IPersonagem( const IPersonagem& );
    void operator=( const IPersonagem& );
};

// Stub for interface IPersonagem
class IPersonagem_stub:
  virtual public IPersonagem,
  virtual public ::ICorba::IObjeto_stub
{
  public:
    virtual ~IPersonagem_stub();
    ::ICorba::Direcao ColidirPersonagem( ::ICorba::IObjeto_ptr obj );
    CORBA::Boolean criarPersonagem( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Long velocidadeInicial, CORBA::Long municaoInicial, CORBA::Boolean spider );
    CORBA::Boolean ir_esquerda();
    CORBA::Boolean ir_direita();
    CORBA::Boolean acelerar();
    CORBA::Boolean ir_baixo();
    CORBA::Boolean ir_cima();
    CORBA::Boolean frear();
    CORBA::Boolean atirar();
    void MorrerPersonagem( CORBA::Long tempo );
    void mudarImagem();
    CORBA::Long getScore();
    CORBA::Double getVelocidade();
    void setVelocidade( CORBA::Double velocidade );
    CORBA::Long getMunicao();
    void setMunicao( CORBA::Long municao );
    ::ICorba::IObstaculo_ptr getTiro();
    CORBA::Long getTempoFim();
    void setTempoFim( CORBA::Long tempoFim );
    CORBA::Long getObstaculosAtingidos();
    void setObstaculosAtingidos( CORBA::Long ObstaculosAtingidos );
    CORBA::Boolean getGodMod();
    void setGodMod( CORBA::Boolean godMod );
    CORBA::Boolean getEhSpider();
    void setEhSpider( CORBA::Boolean ehSpider );

  private:
    void operator=( const IPersonagem_stub& );
};

#ifndef MICO_CONF_NO_POA

class IPersonagem_stub_clp :
  virtual public IPersonagem_stub,
  virtual public ::ICorba::IObjeto_stub_clp
{
  public:
    IPersonagem_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~IPersonagem_stub_clp ();
    ::ICorba::Direcao ColidirPersonagem( ::ICorba::IObjeto_ptr obj );
    CORBA::Boolean criarPersonagem( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Long velocidadeInicial, CORBA::Long municaoInicial, CORBA::Boolean spider );
    CORBA::Boolean ir_esquerda();
    CORBA::Boolean ir_direita();
    CORBA::Boolean acelerar();
    CORBA::Boolean ir_baixo();
    CORBA::Boolean ir_cima();
    CORBA::Boolean frear();
    CORBA::Boolean atirar();
    void MorrerPersonagem( CORBA::Long tempo );
    void mudarImagem();
    CORBA::Long getScore();
    CORBA::Double getVelocidade();
    void setVelocidade( CORBA::Double velocidade );
    CORBA::Long getMunicao();
    void setMunicao( CORBA::Long municao );
    ::ICorba::IObstaculo_ptr getTiro();
    CORBA::Long getTempoFim();
    void setTempoFim( CORBA::Long tempoFim );
    CORBA::Long getObstaculosAtingidos();
    void setObstaculosAtingidos( CORBA::Long ObstaculosAtingidos );
    CORBA::Boolean getGodMod();
    void setGodMod( CORBA::Boolean godMod );
    CORBA::Boolean getEhSpider();
    void setEhSpider( CORBA::Boolean ehSpider );

  protected:
    IPersonagem_stub_clp ();
  private:
    void operator=( const IPersonagem_stub_clp & );
};

#endif // MICO_CONF_NO_POA


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

    typedef IfaceSequenceTmpl< IObjeto_var,IObjeto_ptr> vetor_objetos;
    typedef TSeqVar< IfaceSequenceTmpl< IObjeto_var,IObjeto_ptr> > vetor_objetos_var;
    typedef TSeqOut< IfaceSequenceTmpl< IObjeto_var,IObjeto_ptr> > vetor_objetos_out;

    virtual CORBA::Boolean Refresh( CORBA::Long tempo ) = 0;
    virtual void alterarAceleracao( CORBA::Long aceleracao ) = 0;
    virtual void adicionarObjeto( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual void testarColisoes( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual CORBA::Boolean criarPista( const char* caminho ) = 0;
    virtual CORBA::Boolean getAcabarJogo() = 0;
    virtual void setAcabarJogo( CORBA::Boolean acabarJogo ) = 0;
    virtual CORBA::Long getPosAtual() = 0;
    virtual void setPosAtual( CORBA::Long posAtual ) = 0;
    virtual ::ICorba::IPista::vetor_objetos* getObjetos() = 0;
    virtual void setObjetos( const ::ICorba::IPista::vetor_objetos& objs ) = 0;
    virtual void setDimValida( const ::ICorba::Dimensao& dimValida ) = 0;
    virtual char* getPathImg() = 0;
    virtual CORBA::Boolean getPausar() = 0;
    virtual void setPausar( CORBA::Boolean pausado ) = 0;
    virtual CORBA::Long getNumeroJogador() = 0;

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
    void adicionarObjeto( ::ICorba::IObjeto_ptr obj );
    void testarColisoes( ::ICorba::IObjeto_ptr obj );
    CORBA::Boolean criarPista( const char* caminho );
    CORBA::Boolean getAcabarJogo();
    void setAcabarJogo( CORBA::Boolean acabarJogo );
    CORBA::Long getPosAtual();
    void setPosAtual( CORBA::Long posAtual );
    ::ICorba::IPista::vetor_objetos* getObjetos();
    void setObjetos( const ::ICorba::IPista::vetor_objetos& objs );
    void setDimValida( const ::ICorba::Dimensao& dimValida );
    char* getPathImg();
    CORBA::Boolean getPausar();
    void setPausar( CORBA::Boolean pausado );
    CORBA::Long getNumeroJogador();

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
    void adicionarObjeto( ::ICorba::IObjeto_ptr obj );
    void testarColisoes( ::ICorba::IObjeto_ptr obj );
    CORBA::Boolean criarPista( const char* caminho );
    CORBA::Boolean getAcabarJogo();
    void setAcabarJogo( CORBA::Boolean acabarJogo );
    CORBA::Long getPosAtual();
    void setPosAtual( CORBA::Long posAtual );
    ::ICorba::IPista::vetor_objetos* getObjetos();
    void setObjetos( const ::ICorba::IPista::vetor_objetos& objs );
    void setDimValida( const ::ICorba::Dimensao& dimValida );
    char* getPathImg();
    CORBA::Boolean getPausar();
    void setPausar( CORBA::Boolean pausado );
    CORBA::Long getNumeroJogador();

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

class IObjeto : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~IObjeto ();
    ICorba::IObjeto_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static IObjeto * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::ICorba::Direcao Colidir( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual void Morrer() = 0;
    virtual CORBA::Boolean getAtivo() = 0;
    virtual void setAtivo( CORBA::Boolean ativo ) = 0;
    virtual char* getStrSprite() = 0;
    virtual void setStrSprite( const char* sprite ) = 0;
    virtual CORBA::Long getTipo() = 0;
    virtual void setTipo( CORBA::Long tipo ) = 0;
    virtual ::ICorba::Dimensao getPosicao() = 0;
    virtual void setPosicao( const ::ICorba::Dimensao& Posicao ) = 0;
    virtual ::ICorba::Dimensao getTamanho() = 0;
    virtual void setTamanho( const ::ICorba::Dimensao& Tamanho ) = 0;
    virtual CORBA::Long getAceleracao() = 0;
    virtual void setAceleracao( CORBA::Long Aceleracao ) = 0;

  protected:
    IObjeto () {};

  private:
    IObjeto (const IObjeto &);
    void operator= (const IObjeto &);
};

class IObstaculo : 
  virtual public POA_ICorba::IObjeto
{
  public:
    virtual ~IObstaculo ();
    ICorba::IObstaculo_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static IObstaculo * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual CORBA::Boolean criarObstaculo( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Double funcionalidade ) = 0;
    virtual CORBA::Double getFuncionalidade() = 0;

  protected:
    IObstaculo () {};

  private:
    IObstaculo (const IObstaculo &);
    void operator= (const IObstaculo &);
};

class IPersonagem : 
  virtual public POA_ICorba::IObjeto
{
  public:
    virtual ~IPersonagem ();
    ICorba::IPersonagem_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static IPersonagem * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual ::ICorba::Direcao ColidirPersonagem( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual CORBA::Boolean criarPersonagem( CORBA::Boolean ativo, const char* sprite, const ::ICorba::Dimensao& posicao, const ::ICorba::Dimensao& tamanho, CORBA::Long velocidadeInicial, CORBA::Long municaoInicial, CORBA::Boolean spider ) = 0;
    virtual CORBA::Boolean ir_esquerda() = 0;
    virtual CORBA::Boolean ir_direita() = 0;
    virtual CORBA::Boolean acelerar() = 0;
    virtual CORBA::Boolean ir_baixo() = 0;
    virtual CORBA::Boolean ir_cima() = 0;
    virtual CORBA::Boolean frear() = 0;
    virtual CORBA::Boolean atirar() = 0;
    virtual void MorrerPersonagem( CORBA::Long tempo ) = 0;
    virtual void mudarImagem() = 0;
    virtual CORBA::Long getScore() = 0;
    virtual CORBA::Double getVelocidade() = 0;
    virtual void setVelocidade( CORBA::Double velocidade ) = 0;
    virtual CORBA::Long getMunicao() = 0;
    virtual void setMunicao( CORBA::Long municao ) = 0;
    virtual ::ICorba::IObstaculo_ptr getTiro() = 0;
    virtual CORBA::Long getTempoFim() = 0;
    virtual void setTempoFim( CORBA::Long tempoFim ) = 0;
    virtual CORBA::Long getObstaculosAtingidos() = 0;
    virtual void setObstaculosAtingidos( CORBA::Long ObstaculosAtingidos ) = 0;
    virtual CORBA::Boolean getGodMod() = 0;
    virtual void setGodMod( CORBA::Boolean godMod ) = 0;
    virtual CORBA::Boolean getEhSpider() = 0;
    virtual void setEhSpider( CORBA::Boolean ehSpider ) = 0;

  protected:
    IPersonagem () {};

  private:
    IPersonagem (const IPersonagem &);
    void operator= (const IPersonagem &);
};

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
    virtual void adicionarObjeto( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual void testarColisoes( ::ICorba::IObjeto_ptr obj ) = 0;
    virtual CORBA::Boolean criarPista( const char* caminho ) = 0;
    virtual CORBA::Boolean getAcabarJogo() = 0;
    virtual void setAcabarJogo( CORBA::Boolean acabarJogo ) = 0;
    virtual CORBA::Long getPosAtual() = 0;
    virtual void setPosAtual( CORBA::Long posAtual ) = 0;
    virtual ::ICorba::IPista::vetor_objetos* getObjetos() = 0;
    virtual void setObjetos( const ::ICorba::IPista::vetor_objetos& objs ) = 0;
    virtual void setDimValida( const ::ICorba::Dimensao& dimValida ) = 0;
    virtual char* getPathImg() = 0;
    virtual CORBA::Boolean getPausar() = 0;
    virtual void setPausar( CORBA::Boolean pausado ) = 0;
    virtual CORBA::Long getNumeroJogador() = 0;

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

extern CORBA::StaticTypeInfo *_marshaller_ICorba_IObjeto;

extern CORBA::StaticTypeInfo *_marshaller_ICorba_IObstaculo;

extern CORBA::StaticTypeInfo *_marshaller_ICorba_IPersonagem;

extern CORBA::StaticTypeInfo *_marshaller_ICorba_IPista;

extern CORBA::StaticTypeInfo *_marshaller__seq_ICorba_IObjeto;

#endif
