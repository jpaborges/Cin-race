/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include "ICorba.h"


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------
#ifdef HAVE_EXPLICIT_STRUCT_OPS
ICorba::Dimensao::Dimensao()
{
}

ICorba::Dimensao::Dimensao( const Dimensao& _s )
{
  x = ((Dimensao&)_s).x;
  y = ((Dimensao&)_s).y;
}

ICorba::Dimensao::~Dimensao()
{
}

ICorba::Dimensao&
ICorba::Dimensao::operator=( const Dimensao& _s )
{
  x = ((Dimensao&)_s).x;
  y = ((Dimensao&)_s).y;
  return *this;
}
#endif

class _Marshaller_ICorba_Dimensao : public ::CORBA::StaticTypeInfo {
    typedef ICorba::Dimensao _MICO_T;
  public:
    ~_Marshaller_ICorba_Dimensao();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_ICorba_Dimensao::~_Marshaller_ICorba_Dimensao()
{
}

::CORBA::StaticValueType _Marshaller_ICorba_Dimensao::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ICorba_Dimensao::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ICorba_Dimensao::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ICorba_Dimensao::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->x ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->y ) &&
    dc.struct_end();
}

void _Marshaller_ICorba_Dimensao::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->x );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->y );
  ec.struct_end();
}

::CORBA::StaticTypeInfo *_marshaller_ICorba_Dimensao;


class _Marshaller_ICorba_Direcao : public ::CORBA::StaticTypeInfo {
    typedef ICorba::Direcao _MICO_T;
  public:
    ~_Marshaller_ICorba_Direcao();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_ICorba_Direcao::~_Marshaller_ICorba_Direcao()
{
}

::CORBA::StaticValueType _Marshaller_ICorba_Direcao::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ICorba_Direcao::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ICorba_Direcao::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ICorba_Direcao::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong ul;
  if( !dc.enumeration( ul ) )
    return FALSE;
  *(_MICO_T*) v = (_MICO_T) ul;
  return TRUE;
}

void _Marshaller_ICorba_Direcao::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.enumeration( (::CORBA::ULong) *(_MICO_T *) v );
}

::CORBA::StaticTypeInfo *_marshaller_ICorba_Direcao;

#ifdef HAVE_EXPLICIT_STRUCT_OPS
ICorba::Sprite::Sprite()
{
}

ICorba::Sprite::Sprite( const Sprite& _s )
{
  posicao = ((Sprite&)_s).posicao;
  tamanho = ((Sprite&)_s).tamanho;
  strImagem = ((Sprite&)_s).strImagem;
  tipo = ((Sprite&)_s).tipo;
  ativo = ((Sprite&)_s).ativo;
}

ICorba::Sprite::~Sprite()
{
}

ICorba::Sprite&
ICorba::Sprite::operator=( const Sprite& _s )
{
  posicao = ((Sprite&)_s).posicao;
  tamanho = ((Sprite&)_s).tamanho;
  strImagem = ((Sprite&)_s).strImagem;
  tipo = ((Sprite&)_s).tipo;
  ativo = ((Sprite&)_s).ativo;
  return *this;
}
#endif

class _Marshaller_ICorba_Sprite : public ::CORBA::StaticTypeInfo {
    typedef ICorba::Sprite _MICO_T;
  public:
    ~_Marshaller_ICorba_Sprite();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_ICorba_Sprite::~_Marshaller_ICorba_Sprite()
{
}

::CORBA::StaticValueType _Marshaller_ICorba_Sprite::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller_ICorba_Sprite::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller_ICorba_Sprite::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller_ICorba_Sprite::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  return
    dc.struct_begin() &&
    _marshaller_ICorba_Dimensao->demarshal( dc, &((_MICO_T*)v)->posicao ) &&
    _marshaller_ICorba_Dimensao->demarshal( dc, &((_MICO_T*)v)->tamanho ) &&
    _marshaller__a255_char->demarshal( dc, &((_MICO_T*)v)->strImagem ) &&
    CORBA::_stc_long->demarshal( dc, &((_MICO_T*)v)->tipo ) &&
    CORBA::_stc_boolean->demarshal( dc, &((_MICO_T*)v)->ativo ) &&
    dc.struct_end();
}

void _Marshaller_ICorba_Sprite::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.struct_begin();
  _marshaller_ICorba_Dimensao->marshal( ec, &((_MICO_T*)v)->posicao );
  _marshaller_ICorba_Dimensao->marshal( ec, &((_MICO_T*)v)->tamanho );
  _marshaller__a255_char->marshal( ec, &((_MICO_T*)v)->strImagem );
  CORBA::_stc_long->marshal( ec, &((_MICO_T*)v)->tipo );
  CORBA::_stc_boolean->marshal( ec, &((_MICO_T*)v)->ativo );
  ec.struct_end();
}

::CORBA::StaticTypeInfo *_marshaller_ICorba_Sprite;



/*
 * Base interface for class IPista
 */

ICorba::IPista::~IPista()
{
}

void *
ICorba::IPista::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:ICorba/IPista:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

ICorba::IPista_ptr
ICorba::IPista::_narrow( CORBA::Object_ptr _obj )
{
  ICorba::IPista_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:ICorba/IPista:1.0" )))
      return _duplicate( (ICorba::IPista_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:ICorba/IPista:1.0") || _obj->_is_a_remote ("IDL:ICorba/IPista:1.0")) {
      _o = new ICorba::IPista_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

ICorba::IPista_ptr
ICorba::IPista::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_ICorba_IPista : public ::CORBA::StaticTypeInfo {
    typedef ICorba::IPista_ptr _MICO_T;
  public:
    ~_Marshaller_ICorba_IPista();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_ICorba_IPista::~_Marshaller_ICorba_IPista()
{
}

::CORBA::StaticValueType _Marshaller_ICorba_IPista::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_ICorba_IPista::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::ICorba::IPista::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_ICorba_IPista::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_ICorba_IPista::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_ICorba_IPista::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::ICorba::IPista::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_ICorba_IPista::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_ICorba_IPista;


/*
 * Stub interface for class IPista
 */

ICorba::IPista_stub::~IPista_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_ICorba::IPista::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:ICorba/IPista:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_ICorba::IPista *
POA_ICorba::IPista::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:ICorba/IPista:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_ICorba::IPista *) p;
  }
  return NULL;
}

ICorba::IPista_stub_clp::IPista_stub_clp ()
{
}

ICorba::IPista_stub_clp::IPista_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

ICorba::IPista_stub_clp::~IPista_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPista_stub::Refresh( CORBA::Long _par_tempo )
{
  CORBA::StaticAny _sa_tempo( CORBA::_stc_long, &_par_tempo );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "Refresh" );
  __req.add_in_arg( &_sa_tempo );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPista_stub_clp::Refresh( CORBA::Long _par_tempo )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->Refresh(_par_tempo);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::Refresh(_par_tempo);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::alterarAceleracao( CORBA::Long _par_aceleracao )
{
  CORBA::StaticAny _sa_aceleracao( CORBA::_stc_long, &_par_aceleracao );
  CORBA::StaticRequest __req( this, "alterarAceleracao" );
  __req.add_in_arg( &_sa_aceleracao );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::alterarAceleracao( CORBA::Long _par_aceleracao )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->alterarAceleracao(_par_aceleracao);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::alterarAceleracao(_par_aceleracao);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPista_stub::criarPista( const char* _par_caminho, const ICorba::Dimensao& _par_dimValida )
{
  CORBA::StaticAny _sa_caminho( CORBA::_stc_string, &_par_caminho );
  CORBA::StaticAny _sa_dimValida( _marshaller_ICorba_Dimensao, &_par_dimValida );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "criarPista" );
  __req.add_in_arg( &_sa_caminho );
  __req.add_in_arg( &_sa_dimValida );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPista_stub_clp::criarPista( const char* _par_caminho, const ICorba::Dimensao& _par_dimValida )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->criarPista(_par_caminho, _par_dimValida);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::criarPista(_par_caminho, _par_dimValida);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPista_stub::getAcabarJogo()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "getAcabarJogo" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPista_stub_clp::getAcabarJogo()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getAcabarJogo();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getAcabarJogo();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::setAcabarJogo( CORBA::Boolean _par_acabarJogo )
{
  CORBA::StaticAny _sa_acabarJogo( CORBA::_stc_boolean, &_par_acabarJogo );
  CORBA::StaticRequest __req( this, "setAcabarJogo" );
  __req.add_in_arg( &_sa_acabarJogo );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::setAcabarJogo( CORBA::Boolean _par_acabarJogo )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setAcabarJogo(_par_acabarJogo);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::setAcabarJogo(_par_acabarJogo);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::getPosAtual()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getPosAtual" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::getPosAtual()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getPosAtual();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getPosAtual();
}

#endif // MICO_CONF_NO_POA

ICorba::IPista::vetor_objetos* ICorba::IPista_stub::getObjetos()
{
  CORBA::StaticAny __res( _marshaller__seq_ICorba_Sprite );

  CORBA::StaticRequest __req( this, "getObjetos" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return (ICorba::IPista::vetor_objetos*) __res._retn();
}


#ifndef MICO_CONF_NO_POA

ICorba::IPista::vetor_objetos*
ICorba::IPista_stub_clp::getObjetos()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      ICorba::IPista::vetor_objetos* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getObjetos();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getObjetos();
}

#endif // MICO_CONF_NO_POA

char* ICorba::IPista_stub::getPathImg()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getPathImg" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
ICorba::IPista_stub_clp::getPathImg()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getPathImg();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getPathImg();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPista_stub::getPausar()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "getPausar" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPista_stub_clp::getPausar()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getPausar();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getPausar();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::setPausar( CORBA::Boolean _par_pausado )
{
  CORBA::StaticAny _sa_pausado( CORBA::_stc_boolean, &_par_pausado );
  CORBA::StaticRequest __req( this, "setPausar" );
  __req.add_in_arg( &_sa_pausado );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::setPausar( CORBA::Boolean _par_pausado )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setPausar(_par_pausado);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::setPausar(_par_pausado);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::criarPersonagem()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "criarPersonagem" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::criarPersonagem()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->criarPersonagem();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::criarPersonagem();
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::getNumeroJogador()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getNumeroJogador" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::getNumeroJogador()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getNumeroJogador();
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getNumeroJogador();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::iniciarJogo( CORBA::Long _par_estagio )
{
  CORBA::StaticAny _sa_estagio( CORBA::_stc_long, &_par_estagio );
  CORBA::StaticRequest __req( this, "iniciarJogo" );
  __req.add_in_arg( &_sa_estagio );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::iniciarJogo( CORBA::Long _par_estagio )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->iniciarJogo(_par_estagio);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::iniciarJogo(_par_estagio);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::getMunicao( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getMunicao" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::getMunicao( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getMunicao(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getMunicao(_par_player);
}

#endif // MICO_CONF_NO_POA

CORBA::Double ICorba::IPista_stub::getVelocidadein( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::Double _res;
  CORBA::StaticAny __res( CORBA::_stc_double, &_res );

  CORBA::StaticRequest __req( this, "getVelocidadein" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Double
ICorba::IPista_stub_clp::getVelocidadein( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Double __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getVelocidadein(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getVelocidadein(_par_player);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::enviar_tecla( CORBA::Long _par_tecla, CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_tecla( CORBA::_stc_long, &_par_tecla );
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::StaticRequest __req( this, "enviar_tecla" );
  __req.add_in_arg( &_sa_tecla );
  __req.add_in_arg( &_sa_player );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::enviar_tecla( CORBA::Long _par_tecla, CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->enviar_tecla(_par_tecla, _par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::enviar_tecla(_par_tecla, _par_player);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::MorrerPersonagem( CORBA::Long _par_player, CORBA::Long _par_temporizador )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::StaticAny _sa_temporizador( CORBA::_stc_long, &_par_temporizador );
  CORBA::StaticRequest __req( this, "MorrerPersonagem" );
  __req.add_in_arg( &_sa_player );
  __req.add_in_arg( &_sa_temporizador );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::MorrerPersonagem( CORBA::Long _par_player, CORBA::Long _par_temporizador )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->MorrerPersonagem(_par_player, _par_temporizador);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::MorrerPersonagem(_par_player, _par_temporizador);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::setGodMod( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::StaticRequest __req( this, "setGodMod" );
  __req.add_in_arg( &_sa_player );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::setGodMod( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setGodMod(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::setGodMod(_par_player);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPista_stub::getAtivo( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "getAtivo" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPista_stub_clp::getAtivo( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getAtivo(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getAtivo(_par_player);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::testarColisoesPersonagem( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::StaticRequest __req( this, "testarColisoesPersonagem" );
  __req.add_in_arg( &_sa_player );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::testarColisoesPersonagem( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->testarColisoesPersonagem(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::testarColisoesPersonagem(_par_player);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::mudarImagemPersonagem( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::StaticRequest __req( this, "mudarImagemPersonagem" );
  __req.add_in_arg( &_sa_player );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::mudarImagemPersonagem( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->mudarImagemPersonagem(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return;
    }
    _postinvoke ();
  }

  ICorba::IPista_stub::mudarImagemPersonagem(_par_player);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::getTempoFim( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getTempoFim" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::getTempoFim( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getTempoFim(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getTempoFim(_par_player);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::getObstaculosAtingidos( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getObstaculosAtingidos" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::getObstaculosAtingidos( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getObstaculosAtingidos(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getObstaculosAtingidos(_par_player);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::getScore( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getScore" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::getScore( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getScore(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getScore(_par_player);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPista_stub::getID( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getID" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPista_stub_clp::getID( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getID(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getID(_par_player);
}

#endif // MICO_CONF_NO_POA

ICorba::Sprite ICorba::IPista_stub::getPersonagem( CORBA::Long _par_player )
{
  CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
  ICorba::Sprite _res;
  CORBA::StaticAny __res( _marshaller_ICorba_Sprite, &_res );

  CORBA::StaticRequest __req( this, "getPersonagem" );
  __req.add_in_arg( &_sa_player );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

ICorba::Sprite
ICorba::IPista_stub_clp::getPersonagem( CORBA::Long _par_player )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      ICorba::Sprite __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getPersonagem(_par_player);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return ICorba::IPista_stub::getPersonagem(_par_player);
}

#endif // MICO_CONF_NO_POA

class _Marshaller__a255_char : public ::CORBA::StaticTypeInfo {
    typedef CORBA::Char _MICO_T;
  public:
    ~_Marshaller__a255_char();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller__a255_char::~_Marshaller__a255_char()
{
}

::CORBA::StaticValueType _Marshaller__a255_char::create() const
{
  return (StaticValueType) new _MICO_T[ 255 ];
}

void _Marshaller__a255_char::assign( StaticValueType d, const StaticValueType s ) const
{
  for( int i = 0; i < 255; i++ )
    ((CORBA::Char *) d)[ i ] = ((CORBA::Char *) s)[ i ];
}

void _Marshaller__a255_char::free( StaticValueType v ) const
{
  delete[] (_MICO_T *) v;
}

::CORBA::Boolean _Marshaller__a255_char::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  if( !dc.arr_begin() )
    return FALSE;
  if (!dc.get_chars (&((_MICO_T *)v)[0], 255))
    return FALSE;
  return dc.arr_end();
}

void _Marshaller__a255_char::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ec.arr_begin();
  ec.put_chars (&((_MICO_T *)v)[0], 255);
  ec.arr_end();
}

::CORBA::StaticTypeInfo *_marshaller__a255_char;

class _Marshaller__seq_ICorba_Sprite : public ::CORBA::StaticTypeInfo {
    typedef SequenceTmpl< ICorba::Sprite,MICO_TID_DEF> _MICO_T;
  public:
    ~_Marshaller__seq_ICorba_Sprite();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller__seq_ICorba_Sprite::~_Marshaller__seq_ICorba_Sprite()
{
}

::CORBA::StaticValueType _Marshaller__seq_ICorba_Sprite::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_ICorba_Sprite::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_ICorba_Sprite::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_ICorba_Sprite::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_ICorba_Sprite->demarshal( dc, &(*(_MICO_T*)v)[i] ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_ICorba_Sprite::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_ICorba_Sprite->marshal( ec, &(*(_MICO_T*)v)[i] );
  ec.seq_end();
}

::CORBA::StaticTypeInfo *_marshaller__seq_ICorba_Sprite;

struct __tc_init_ICORBA {
  __tc_init_ICORBA()
  {
    _marshaller_ICorba_Dimensao = new _Marshaller_ICorba_Dimensao;
    _marshaller_ICorba_Direcao = new _Marshaller_ICorba_Direcao;
    _marshaller_ICorba_Sprite = new _Marshaller_ICorba_Sprite;
    _marshaller_ICorba_IPista = new _Marshaller_ICorba_IPista;
    _marshaller__a255_char = new _Marshaller__a255_char;
    _marshaller__seq_ICorba_Sprite = new _Marshaller__seq_ICorba_Sprite;
  }

  ~__tc_init_ICORBA()
  {
    delete static_cast<_Marshaller_ICorba_Dimensao*>(_marshaller_ICorba_Dimensao);
    delete static_cast<_Marshaller_ICorba_Direcao*>(_marshaller_ICorba_Direcao);
    delete static_cast<_Marshaller_ICorba_Sprite*>(_marshaller_ICorba_Sprite);
    delete static_cast<_Marshaller_ICorba_IPista*>(_marshaller_ICorba_IPista);
    delete static_cast<_Marshaller__a255_char*>(_marshaller__a255_char);
    delete static_cast<_Marshaller__seq_ICorba_Sprite*>(_marshaller__seq_ICorba_Sprite);
  }
};

static __tc_init_ICORBA __init_ICORBA;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface ICorba::IPista
POA_ICorba::IPista::~IPista()
{
}

::ICorba::IPista_ptr
POA_ICorba::IPista::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::ICorba::IPista::_narrow (obj);
}

CORBA::Boolean
POA_ICorba::IPista::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:ICorba/IPista:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_ICorba::IPista::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:ICorba/IPista:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_ICorba::IPista::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:ICorba/IPista:1.0");
}

CORBA::Object_ptr
POA_ICorba::IPista::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::ICorba::IPista_stub_clp (poa, obj);
}

bool
POA_ICorba::IPista::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 41)) {
    case 1:
      if( strcmp( __req->op_name(), "getTempoFim" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getTempoFim( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 5:
      if( strcmp( __req->op_name(), "Refresh" ) == 0 ) {
        CORBA::Long _par_tempo;
        CORBA::StaticAny _sa_tempo( CORBA::_stc_long, &_par_tempo );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_tempo );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = Refresh( _par_tempo );
        __req->write_results();
        return true;
      }
      break;
    case 7:
      if( strcmp( __req->op_name(), "iniciarJogo" ) == 0 ) {
        CORBA::Long _par_estagio;
        CORBA::StaticAny _sa_estagio( CORBA::_stc_long, &_par_estagio );

        __req->add_in_arg( &_sa_estagio );

        if( !__req->read_args() )
          return true;

        iniciarJogo( _par_estagio );
        __req->write_results();
        return true;
      }
      break;
    case 9:
      if( strcmp( __req->op_name(), "criarPista" ) == 0 ) {
        CORBA::String_var _par_caminho;
        CORBA::StaticAny _sa_caminho( CORBA::_stc_string, &_par_caminho._for_demarshal() );
        ::ICorba::Dimensao _par_dimValida;
        CORBA::StaticAny _sa_dimValida( _marshaller_ICorba_Dimensao, &_par_dimValida );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_caminho );
        __req->add_in_arg( &_sa_dimValida );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = criarPista( _par_caminho.inout(), _par_dimValida );
        __req->write_results();
        return true;
      }
      break;
    case 14:
      if( strcmp( __req->op_name(), "getObjetos" ) == 0 ) {
        ::ICorba::IPista::vetor_objetos* _res;
        CORBA::StaticAny __res( _marshaller__seq_ICorba_Sprite );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getObjetos();
        __res.value( _marshaller__seq_ICorba_Sprite, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 15:
      if( strcmp( __req->op_name(), "mudarImagemPersonagem" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        __req->add_in_arg( &_sa_player );

        if( !__req->read_args() )
          return true;

        mudarImagemPersonagem( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 16:
      if( strcmp( __req->op_name(), "setGodMod" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        __req->add_in_arg( &_sa_player );

        if( !__req->read_args() )
          return true;

        setGodMod( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 20:
      if( strcmp( __req->op_name(), "MorrerPersonagem" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );
        CORBA::Long _par_temporizador;
        CORBA::StaticAny _sa_temporizador( CORBA::_stc_long, &_par_temporizador );

        __req->add_in_arg( &_sa_player );
        __req->add_in_arg( &_sa_temporizador );

        if( !__req->read_args() )
          return true;

        MorrerPersonagem( _par_player, _par_temporizador );
        __req->write_results();
        return true;
      }
      break;
    case 21:
      if( strcmp( __req->op_name(), "getNumeroJogador" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getNumeroJogador();
        __req->write_results();
        return true;
      }
      break;
    case 22:
      if( strcmp( __req->op_name(), "getAtivo" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getAtivo( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 23:
      if( strcmp( __req->op_name(), "enviar_tecla" ) == 0 ) {
        CORBA::Long _par_tecla;
        CORBA::StaticAny _sa_tecla( CORBA::_stc_long, &_par_tecla );
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        __req->add_in_arg( &_sa_tecla );
        __req->add_in_arg( &_sa_player );

        if( !__req->read_args() )
          return true;

        enviar_tecla( _par_tecla, _par_player );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getObstaculosAtingidos" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getObstaculosAtingidos( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 24:
      if( strcmp( __req->op_name(), "getMunicao" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getMunicao( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 25:
      if( strcmp( __req->op_name(), "criarPersonagem" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = criarPersonagem();
        __req->write_results();
        return true;
      }
      break;
    case 27:
      if( strcmp( __req->op_name(), "setAcabarJogo" ) == 0 ) {
        CORBA::Boolean _par_acabarJogo;
        CORBA::StaticAny _sa_acabarJogo( CORBA::_stc_boolean, &_par_acabarJogo );

        __req->add_in_arg( &_sa_acabarJogo );

        if( !__req->read_args() )
          return true;

        setAcabarJogo( _par_acabarJogo );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getPosAtual" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getPosAtual();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "testarColisoesPersonagem" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        __req->add_in_arg( &_sa_player );

        if( !__req->read_args() )
          return true;

        testarColisoesPersonagem( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 29:
      if( strcmp( __req->op_name(), "setPausar" ) == 0 ) {
        CORBA::Boolean _par_pausado;
        CORBA::StaticAny _sa_pausado( CORBA::_stc_boolean, &_par_pausado );

        __req->add_in_arg( &_sa_pausado );

        if( !__req->read_args() )
          return true;

        setPausar( _par_pausado );
        __req->write_results();
        return true;
      }
      break;
    case 31:
      if( strcmp( __req->op_name(), "getPathImg" ) == 0 ) {
        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getPathImg();
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      break;
    case 32:
      if( strcmp( __req->op_name(), "getPausar" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getPausar();
        __req->write_results();
        return true;
      }
      break;
    case 33:
      if( strcmp( __req->op_name(), "getID" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getID( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 34:
      if( strcmp( __req->op_name(), "getAcabarJogo" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getAcabarJogo();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getVelocidadein" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        CORBA::Double _res;
        CORBA::StaticAny __res( CORBA::_stc_double, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getVelocidadein( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 38:
      if( strcmp( __req->op_name(), "getPersonagem" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        ::ICorba::Sprite _res;
        CORBA::StaticAny __res( _marshaller_ICorba_Sprite, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getPersonagem( _par_player );
        __req->write_results();
        return true;
      }
      break;
    case 39:
      if( strcmp( __req->op_name(), "alterarAceleracao" ) == 0 ) {
        CORBA::Long _par_aceleracao;
        CORBA::StaticAny _sa_aceleracao( CORBA::_stc_long, &_par_aceleracao );

        __req->add_in_arg( &_sa_aceleracao );

        if( !__req->read_args() )
          return true;

        alterarAceleracao( _par_aceleracao );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getScore" ) == 0 ) {
        CORBA::Long _par_player;
        CORBA::StaticAny _sa_player( CORBA::_stc_long, &_par_player );

        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->add_in_arg( &_sa_player );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getScore( _par_player );
        __req->write_results();
        return true;
      }
      break;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_ICorba::IPista::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

