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


/*
 * Base interface for class IObjeto
 */

ICorba::IObjeto::~IObjeto()
{
}

void *
ICorba::IObjeto::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:ICorba/IObjeto:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

ICorba::IObjeto_ptr
ICorba::IObjeto::_narrow( CORBA::Object_ptr _obj )
{
  ICorba::IObjeto_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:ICorba/IObjeto:1.0" )))
      return _duplicate( (ICorba::IObjeto_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:ICorba/IObjeto:1.0") || _obj->_is_a_remote ("IDL:ICorba/IObjeto:1.0")) {
      _o = new ICorba::IObjeto_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

ICorba::IObjeto_ptr
ICorba::IObjeto::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_ICorba_IObjeto : public ::CORBA::StaticTypeInfo {
    typedef ICorba::IObjeto_ptr _MICO_T;
  public:
    ~_Marshaller_ICorba_IObjeto();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_ICorba_IObjeto::~_Marshaller_ICorba_IObjeto()
{
}

::CORBA::StaticValueType _Marshaller_ICorba_IObjeto::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_ICorba_IObjeto::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::ICorba::IObjeto::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_ICorba_IObjeto::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_ICorba_IObjeto::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_ICorba_IObjeto::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::ICorba::IObjeto::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_ICorba_IObjeto::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_ICorba_IObjeto;


/*
 * Stub interface for class IObjeto
 */

ICorba::IObjeto_stub::~IObjeto_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_ICorba::IObjeto::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:ICorba/IObjeto:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_ICorba::IObjeto *
POA_ICorba::IObjeto::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:ICorba/IObjeto:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_ICorba::IObjeto *) p;
  }
  return NULL;
}

ICorba::IObjeto_stub_clp::IObjeto_stub_clp ()
{
}

ICorba::IObjeto_stub_clp::IObjeto_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

ICorba::IObjeto_stub_clp::~IObjeto_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

ICorba::Direcao ICorba::IObjeto_stub::Colidir( ICorba::IObjeto_ptr _par_obj )
{
  CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj );
  ICorba::Direcao _res;
  CORBA::StaticAny __res( _marshaller_ICorba_Direcao, &_res );

  CORBA::StaticRequest __req( this, "Colidir" );
  __req.add_in_arg( &_sa_obj );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

ICorba::Direcao
ICorba::IObjeto_stub_clp::Colidir( ICorba::IObjeto_ptr _par_obj )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      ICorba::Direcao __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->Colidir(_par_obj);
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

  return ICorba::IObjeto_stub::Colidir(_par_obj);
}

#endif // MICO_CONF_NO_POA

void ICorba::IObjeto_stub::Morrer()
{
  CORBA::StaticRequest __req( this, "Morrer" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IObjeto_stub_clp::Morrer()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->Morrer();
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

  ICorba::IObjeto_stub::Morrer();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IObjeto_stub::getAtivo()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "getAtivo" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IObjeto_stub_clp::getAtivo()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getAtivo();
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

  return ICorba::IObjeto_stub::getAtivo();
}

#endif // MICO_CONF_NO_POA

void ICorba::IObjeto_stub::setAtivo( CORBA::Boolean _par_ativo )
{
  CORBA::StaticAny _sa_ativo( CORBA::_stc_boolean, &_par_ativo );
  CORBA::StaticRequest __req( this, "setAtivo" );
  __req.add_in_arg( &_sa_ativo );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IObjeto_stub_clp::setAtivo( CORBA::Boolean _par_ativo )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setAtivo(_par_ativo);
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

  ICorba::IObjeto_stub::setAtivo(_par_ativo);
}

#endif // MICO_CONF_NO_POA

char* ICorba::IObjeto_stub::getStrSprite()
{
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "getStrSprite" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
ICorba::IObjeto_stub_clp::getStrSprite()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getStrSprite();
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

  return ICorba::IObjeto_stub::getStrSprite();
}

#endif // MICO_CONF_NO_POA

void ICorba::IObjeto_stub::setStrSprite( const char* _par_sprite )
{
  CORBA::StaticAny _sa_sprite( CORBA::_stc_string, &_par_sprite );
  CORBA::StaticRequest __req( this, "setStrSprite" );
  __req.add_in_arg( &_sa_sprite );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IObjeto_stub_clp::setStrSprite( const char* _par_sprite )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setStrSprite(_par_sprite);
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

  ICorba::IObjeto_stub::setStrSprite(_par_sprite);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IObjeto_stub::getTipo()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getTipo" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IObjeto_stub_clp::getTipo()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getTipo();
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

  return ICorba::IObjeto_stub::getTipo();
}

#endif // MICO_CONF_NO_POA

void ICorba::IObjeto_stub::setTipo( CORBA::Long _par_tipo )
{
  CORBA::StaticAny _sa_tipo( CORBA::_stc_long, &_par_tipo );
  CORBA::StaticRequest __req( this, "setTipo" );
  __req.add_in_arg( &_sa_tipo );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IObjeto_stub_clp::setTipo( CORBA::Long _par_tipo )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setTipo(_par_tipo);
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

  ICorba::IObjeto_stub::setTipo(_par_tipo);
}

#endif // MICO_CONF_NO_POA

ICorba::Dimensao ICorba::IObjeto_stub::getPosicao()
{
  ICorba::Dimensao _res;
  CORBA::StaticAny __res( _marshaller_ICorba_Dimensao, &_res );

  CORBA::StaticRequest __req( this, "getPosicao" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

ICorba::Dimensao
ICorba::IObjeto_stub_clp::getPosicao()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      ICorba::Dimensao __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getPosicao();
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

  return ICorba::IObjeto_stub::getPosicao();
}

#endif // MICO_CONF_NO_POA

void ICorba::IObjeto_stub::setPosicao( const ICorba::Dimensao& _par_Posicao )
{
  CORBA::StaticAny _sa_Posicao( _marshaller_ICorba_Dimensao, &_par_Posicao );
  CORBA::StaticRequest __req( this, "setPosicao" );
  __req.add_in_arg( &_sa_Posicao );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IObjeto_stub_clp::setPosicao( const ICorba::Dimensao& _par_Posicao )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setPosicao(_par_Posicao);
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

  ICorba::IObjeto_stub::setPosicao(_par_Posicao);
}

#endif // MICO_CONF_NO_POA

ICorba::Dimensao ICorba::IObjeto_stub::getTamanho()
{
  ICorba::Dimensao _res;
  CORBA::StaticAny __res( _marshaller_ICorba_Dimensao, &_res );

  CORBA::StaticRequest __req( this, "getTamanho" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

ICorba::Dimensao
ICorba::IObjeto_stub_clp::getTamanho()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      ICorba::Dimensao __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getTamanho();
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

  return ICorba::IObjeto_stub::getTamanho();
}

#endif // MICO_CONF_NO_POA

void ICorba::IObjeto_stub::setTamanho( const ICorba::Dimensao& _par_Tamanho )
{
  CORBA::StaticAny _sa_Tamanho( _marshaller_ICorba_Dimensao, &_par_Tamanho );
  CORBA::StaticRequest __req( this, "setTamanho" );
  __req.add_in_arg( &_sa_Tamanho );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IObjeto_stub_clp::setTamanho( const ICorba::Dimensao& _par_Tamanho )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setTamanho(_par_Tamanho);
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

  ICorba::IObjeto_stub::setTamanho(_par_Tamanho);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IObjeto_stub::getAceleracao()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getAceleracao" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IObjeto_stub_clp::getAceleracao()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getAceleracao();
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

  return ICorba::IObjeto_stub::getAceleracao();
}

#endif // MICO_CONF_NO_POA

void ICorba::IObjeto_stub::setAceleracao( CORBA::Long _par_Aceleracao )
{
  CORBA::StaticAny _sa_Aceleracao( CORBA::_stc_long, &_par_Aceleracao );
  CORBA::StaticRequest __req( this, "setAceleracao" );
  __req.add_in_arg( &_sa_Aceleracao );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IObjeto_stub_clp::setAceleracao( CORBA::Long _par_Aceleracao )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObjeto * _myserv = POA_ICorba::IObjeto::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setAceleracao(_par_Aceleracao);
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

  ICorba::IObjeto_stub::setAceleracao(_par_Aceleracao);
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class IObstaculo
 */

ICorba::IObstaculo::~IObstaculo()
{
}

void *
ICorba::IObstaculo::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:ICorba/IObstaculo:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = ICorba::IObjeto::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

ICorba::IObstaculo_ptr
ICorba::IObstaculo::_narrow( CORBA::Object_ptr _obj )
{
  ICorba::IObstaculo_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:ICorba/IObstaculo:1.0" )))
      return _duplicate( (ICorba::IObstaculo_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:ICorba/IObstaculo:1.0") || _obj->_is_a_remote ("IDL:ICorba/IObstaculo:1.0")) {
      _o = new ICorba::IObstaculo_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

ICorba::IObstaculo_ptr
ICorba::IObstaculo::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_ICorba_IObstaculo : public ::CORBA::StaticTypeInfo {
    typedef ICorba::IObstaculo_ptr _MICO_T;
  public:
    ~_Marshaller_ICorba_IObstaculo();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_ICorba_IObstaculo::~_Marshaller_ICorba_IObstaculo()
{
}

::CORBA::StaticValueType _Marshaller_ICorba_IObstaculo::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_ICorba_IObstaculo::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::ICorba::IObstaculo::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_ICorba_IObstaculo::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_ICorba_IObstaculo::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_ICorba_IObstaculo::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::ICorba::IObstaculo::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_ICorba_IObstaculo::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_ICorba_IObstaculo;


/*
 * Stub interface for class IObstaculo
 */

ICorba::IObstaculo_stub::~IObstaculo_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_ICorba::IObstaculo::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:ICorba/IObstaculo:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_ICorba::IObjeto::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_ICorba::IObstaculo *
POA_ICorba::IObstaculo::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:ICorba/IObstaculo:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_ICorba::IObstaculo *) p;
  }
  return NULL;
}

ICorba::IObstaculo_stub_clp::IObstaculo_stub_clp ()
{
}

ICorba::IObstaculo_stub_clp::IObstaculo_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

ICorba::IObstaculo_stub_clp::~IObstaculo_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IObstaculo_stub::criarObstaculo( CORBA::Boolean _par_ativo, const char* _par_sprite, const ICorba::Dimensao& _par_posicao, const ICorba::Dimensao& _par_tamanho, CORBA::Double _par_funcionalidade )
{
  CORBA::StaticAny _sa_ativo( CORBA::_stc_boolean, &_par_ativo );
  CORBA::StaticAny _sa_sprite( CORBA::_stc_string, &_par_sprite );
  CORBA::StaticAny _sa_posicao( _marshaller_ICorba_Dimensao, &_par_posicao );
  CORBA::StaticAny _sa_tamanho( _marshaller_ICorba_Dimensao, &_par_tamanho );
  CORBA::StaticAny _sa_funcionalidade( CORBA::_stc_double, &_par_funcionalidade );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "criarObstaculo" );
  __req.add_in_arg( &_sa_ativo );
  __req.add_in_arg( &_sa_sprite );
  __req.add_in_arg( &_sa_posicao );
  __req.add_in_arg( &_sa_tamanho );
  __req.add_in_arg( &_sa_funcionalidade );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IObstaculo_stub_clp::criarObstaculo( CORBA::Boolean _par_ativo, const char* _par_sprite, const ICorba::Dimensao& _par_posicao, const ICorba::Dimensao& _par_tamanho, CORBA::Double _par_funcionalidade )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObstaculo * _myserv = POA_ICorba::IObstaculo::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->criarObstaculo(_par_ativo, _par_sprite, _par_posicao, _par_tamanho, _par_funcionalidade);
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

  return ICorba::IObstaculo_stub::criarObstaculo(_par_ativo, _par_sprite, _par_posicao, _par_tamanho, _par_funcionalidade);
}

#endif // MICO_CONF_NO_POA

CORBA::Double ICorba::IObstaculo_stub::getFuncionalidade()
{
  CORBA::Double _res;
  CORBA::StaticAny __res( CORBA::_stc_double, &_res );

  CORBA::StaticRequest __req( this, "getFuncionalidade" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Double
ICorba::IObstaculo_stub_clp::getFuncionalidade()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IObstaculo * _myserv = POA_ICorba::IObstaculo::_narrow (_serv);
    if (_myserv) {
      CORBA::Double __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getFuncionalidade();
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

  return ICorba::IObstaculo_stub::getFuncionalidade();
}

#endif // MICO_CONF_NO_POA


/*
 * Base interface for class IPersonagem
 */

ICorba::IPersonagem::~IPersonagem()
{
}

void *
ICorba::IPersonagem::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:ICorba/IPersonagem:1.0" ) == 0 )
    return (void *)this;
  {
    void *_p;
    if ((_p = ICorba::IObjeto::_narrow_helper( _repoid )))
      return _p;
  }
  return NULL;
}

ICorba::IPersonagem_ptr
ICorba::IPersonagem::_narrow( CORBA::Object_ptr _obj )
{
  ICorba::IPersonagem_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:ICorba/IPersonagem:1.0" )))
      return _duplicate( (ICorba::IPersonagem_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:ICorba/IPersonagem:1.0") || _obj->_is_a_remote ("IDL:ICorba/IPersonagem:1.0")) {
      _o = new ICorba::IPersonagem_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

ICorba::IPersonagem_ptr
ICorba::IPersonagem::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_ICorba_IPersonagem : public ::CORBA::StaticTypeInfo {
    typedef ICorba::IPersonagem_ptr _MICO_T;
  public:
    ~_Marshaller_ICorba_IPersonagem();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_ICorba_IPersonagem::~_Marshaller_ICorba_IPersonagem()
{
}

::CORBA::StaticValueType _Marshaller_ICorba_IPersonagem::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_ICorba_IPersonagem::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::ICorba::IPersonagem::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_ICorba_IPersonagem::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_ICorba_IPersonagem::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_ICorba_IPersonagem::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::ICorba::IPersonagem::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_ICorba_IPersonagem::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_ICorba_IPersonagem;


/*
 * Stub interface for class IPersonagem
 */

ICorba::IPersonagem_stub::~IPersonagem_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_ICorba::IPersonagem::_narrow_helper (const char * repoid)
{
  void * p;
  if (strcmp (repoid, "IDL:ICorba/IPersonagem:1.0") == 0) {
    return (void *) this;
  }
  if ((p = POA_ICorba::IObjeto::_narrow_helper (repoid)) != NULL) 
  {
    return p;
  }
  return NULL;
}

POA_ICorba::IPersonagem *
POA_ICorba::IPersonagem::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:ICorba/IPersonagem:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_ICorba::IPersonagem *) p;
  }
  return NULL;
}

ICorba::IPersonagem_stub_clp::IPersonagem_stub_clp ()
{
}

ICorba::IPersonagem_stub_clp::IPersonagem_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

ICorba::IPersonagem_stub_clp::~IPersonagem_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

ICorba::Direcao ICorba::IPersonagem_stub::ColidirPersonagem( ICorba::IObjeto_ptr _par_obj )
{
  CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj );
  ICorba::Direcao _res;
  CORBA::StaticAny __res( _marshaller_ICorba_Direcao, &_res );

  CORBA::StaticRequest __req( this, "ColidirPersonagem" );
  __req.add_in_arg( &_sa_obj );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

ICorba::Direcao
ICorba::IPersonagem_stub_clp::ColidirPersonagem( ICorba::IObjeto_ptr _par_obj )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      ICorba::Direcao __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->ColidirPersonagem(_par_obj);
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

  return ICorba::IPersonagem_stub::ColidirPersonagem(_par_obj);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::criarPersonagem( CORBA::Boolean _par_ativo, const char* _par_sprite, const ICorba::Dimensao& _par_posicao, const ICorba::Dimensao& _par_tamanho, CORBA::Long _par_velocidadeInicial, CORBA::Long _par_municaoInicial, CORBA::Boolean _par_spider )
{
  CORBA::StaticAny _sa_ativo( CORBA::_stc_boolean, &_par_ativo );
  CORBA::StaticAny _sa_sprite( CORBA::_stc_string, &_par_sprite );
  CORBA::StaticAny _sa_posicao( _marshaller_ICorba_Dimensao, &_par_posicao );
  CORBA::StaticAny _sa_tamanho( _marshaller_ICorba_Dimensao, &_par_tamanho );
  CORBA::StaticAny _sa_velocidadeInicial( CORBA::_stc_long, &_par_velocidadeInicial );
  CORBA::StaticAny _sa_municaoInicial( CORBA::_stc_long, &_par_municaoInicial );
  CORBA::StaticAny _sa_spider( CORBA::_stc_boolean, &_par_spider );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "criarPersonagem" );
  __req.add_in_arg( &_sa_ativo );
  __req.add_in_arg( &_sa_sprite );
  __req.add_in_arg( &_sa_posicao );
  __req.add_in_arg( &_sa_tamanho );
  __req.add_in_arg( &_sa_velocidadeInicial );
  __req.add_in_arg( &_sa_municaoInicial );
  __req.add_in_arg( &_sa_spider );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::criarPersonagem( CORBA::Boolean _par_ativo, const char* _par_sprite, const ICorba::Dimensao& _par_posicao, const ICorba::Dimensao& _par_tamanho, CORBA::Long _par_velocidadeInicial, CORBA::Long _par_municaoInicial, CORBA::Boolean _par_spider )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->criarPersonagem(_par_ativo, _par_sprite, _par_posicao, _par_tamanho, _par_velocidadeInicial, _par_municaoInicial, _par_spider);
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

  return ICorba::IPersonagem_stub::criarPersonagem(_par_ativo, _par_sprite, _par_posicao, _par_tamanho, _par_velocidadeInicial, _par_municaoInicial, _par_spider);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::ir_esquerda()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "ir_esquerda" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::ir_esquerda()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->ir_esquerda();
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

  return ICorba::IPersonagem_stub::ir_esquerda();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::ir_direita()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "ir_direita" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::ir_direita()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->ir_direita();
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

  return ICorba::IPersonagem_stub::ir_direita();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::acelerar()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "acelerar" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::acelerar()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->acelerar();
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

  return ICorba::IPersonagem_stub::acelerar();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::ir_baixo()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "ir_baixo" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::ir_baixo()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->ir_baixo();
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

  return ICorba::IPersonagem_stub::ir_baixo();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::ir_cima()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "ir_cima" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::ir_cima()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->ir_cima();
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

  return ICorba::IPersonagem_stub::ir_cima();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::frear()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "frear" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::frear()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->frear();
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

  return ICorba::IPersonagem_stub::frear();
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::atirar()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "atirar" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::atirar()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->atirar();
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

  return ICorba::IPersonagem_stub::atirar();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::MorrerPersonagem( CORBA::Long _par_tempo )
{
  CORBA::StaticAny _sa_tempo( CORBA::_stc_long, &_par_tempo );
  CORBA::StaticRequest __req( this, "MorrerPersonagem" );
  __req.add_in_arg( &_sa_tempo );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::MorrerPersonagem( CORBA::Long _par_tempo )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->MorrerPersonagem(_par_tempo);
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

  ICorba::IPersonagem_stub::MorrerPersonagem(_par_tempo);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::mudarImagem()
{
  CORBA::StaticRequest __req( this, "mudarImagem" );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::mudarImagem()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->mudarImagem();
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

  ICorba::IPersonagem_stub::mudarImagem();
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPersonagem_stub::getScore()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getScore" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPersonagem_stub_clp::getScore()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getScore();
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

  return ICorba::IPersonagem_stub::getScore();
}

#endif // MICO_CONF_NO_POA

CORBA::Double ICorba::IPersonagem_stub::getVelocidade()
{
  CORBA::Double _res;
  CORBA::StaticAny __res( CORBA::_stc_double, &_res );

  CORBA::StaticRequest __req( this, "getVelocidade" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Double
ICorba::IPersonagem_stub_clp::getVelocidade()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Double __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getVelocidade();
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

  return ICorba::IPersonagem_stub::getVelocidade();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::setVelocidade( CORBA::Double _par_velocidade )
{
  CORBA::StaticAny _sa_velocidade( CORBA::_stc_double, &_par_velocidade );
  CORBA::StaticRequest __req( this, "setVelocidade" );
  __req.add_in_arg( &_sa_velocidade );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::setVelocidade( CORBA::Double _par_velocidade )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setVelocidade(_par_velocidade);
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

  ICorba::IPersonagem_stub::setVelocidade(_par_velocidade);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPersonagem_stub::getMunicao()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getMunicao" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPersonagem_stub_clp::getMunicao()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getMunicao();
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

  return ICorba::IPersonagem_stub::getMunicao();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::setMunicao( CORBA::Long _par_municao )
{
  CORBA::StaticAny _sa_municao( CORBA::_stc_long, &_par_municao );
  CORBA::StaticRequest __req( this, "setMunicao" );
  __req.add_in_arg( &_sa_municao );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::setMunicao( CORBA::Long _par_municao )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setMunicao(_par_municao);
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

  ICorba::IPersonagem_stub::setMunicao(_par_municao);
}

#endif // MICO_CONF_NO_POA

ICorba::IObstaculo_ptr ICorba::IPersonagem_stub::getTiro()
{
  ICorba::IObstaculo_ptr _res = ICorba::IObstaculo::_nil();
  CORBA::StaticAny __res( _marshaller_ICorba_IObstaculo, &_res );

  CORBA::StaticRequest __req( this, "getTiro" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

ICorba::IObstaculo_ptr
ICorba::IPersonagem_stub_clp::getTiro()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      ICorba::IObstaculo_ptr __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getTiro();
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

  return ICorba::IPersonagem_stub::getTiro();
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPersonagem_stub::getTempoFim()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getTempoFim" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPersonagem_stub_clp::getTempoFim()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getTempoFim();
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

  return ICorba::IPersonagem_stub::getTempoFim();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::setTempoFim( CORBA::Long _par_tempoFim )
{
  CORBA::StaticAny _sa_tempoFim( CORBA::_stc_long, &_par_tempoFim );
  CORBA::StaticRequest __req( this, "setTempoFim" );
  __req.add_in_arg( &_sa_tempoFim );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::setTempoFim( CORBA::Long _par_tempoFim )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setTempoFim(_par_tempoFim);
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

  ICorba::IPersonagem_stub::setTempoFim(_par_tempoFim);
}

#endif // MICO_CONF_NO_POA

CORBA::Long ICorba::IPersonagem_stub::getObstaculosAtingidos()
{
  CORBA::Long _res;
  CORBA::StaticAny __res( CORBA::_stc_long, &_res );

  CORBA::StaticRequest __req( this, "getObstaculosAtingidos" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Long
ICorba::IPersonagem_stub_clp::getObstaculosAtingidos()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Long __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getObstaculosAtingidos();
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

  return ICorba::IPersonagem_stub::getObstaculosAtingidos();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::setObstaculosAtingidos( CORBA::Long _par_ObstaculosAtingidos )
{
  CORBA::StaticAny _sa_ObstaculosAtingidos( CORBA::_stc_long, &_par_ObstaculosAtingidos );
  CORBA::StaticRequest __req( this, "setObstaculosAtingidos" );
  __req.add_in_arg( &_sa_ObstaculosAtingidos );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::setObstaculosAtingidos( CORBA::Long _par_ObstaculosAtingidos )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setObstaculosAtingidos(_par_ObstaculosAtingidos);
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

  ICorba::IPersonagem_stub::setObstaculosAtingidos(_par_ObstaculosAtingidos);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::getGodMod()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "getGodMod" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::getGodMod()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getGodMod();
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

  return ICorba::IPersonagem_stub::getGodMod();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::setGodMod( CORBA::Boolean _par_godMod )
{
  CORBA::StaticAny _sa_godMod( CORBA::_stc_boolean, &_par_godMod );
  CORBA::StaticRequest __req( this, "setGodMod" );
  __req.add_in_arg( &_sa_godMod );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::setGodMod( CORBA::Boolean _par_godMod )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setGodMod(_par_godMod);
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

  ICorba::IPersonagem_stub::setGodMod(_par_godMod);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPersonagem_stub::getEhSpider()
{
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "getEhSpider" );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPersonagem_stub_clp::getEhSpider()
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->getEhSpider();
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

  return ICorba::IPersonagem_stub::getEhSpider();
}

#endif // MICO_CONF_NO_POA

void ICorba::IPersonagem_stub::setEhSpider( CORBA::Boolean _par_ehSpider )
{
  CORBA::StaticAny _sa_ehSpider( CORBA::_stc_boolean, &_par_ehSpider );
  CORBA::StaticRequest __req( this, "setEhSpider" );
  __req.add_in_arg( &_sa_ehSpider );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPersonagem_stub_clp::setEhSpider( CORBA::Boolean _par_ehSpider )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPersonagem * _myserv = POA_ICorba::IPersonagem::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setEhSpider(_par_ehSpider);
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

  ICorba::IPersonagem_stub::setEhSpider(_par_ehSpider);
}

#endif // MICO_CONF_NO_POA



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

void ICorba::IPista_stub::adicionarObjeto( ICorba::IObjeto_ptr _par_obj )
{
  CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj );
  CORBA::StaticRequest __req( this, "adicionarObjeto" );
  __req.add_in_arg( &_sa_obj );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::adicionarObjeto( ICorba::IObjeto_ptr _par_obj )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->adicionarObjeto(_par_obj);
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

  ICorba::IPista_stub::adicionarObjeto(_par_obj);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::testarColisoes( ICorba::IObjeto_ptr _par_obj )
{
  CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj );
  CORBA::StaticRequest __req( this, "testarColisoes" );
  __req.add_in_arg( &_sa_obj );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::testarColisoes( ICorba::IObjeto_ptr _par_obj )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->testarColisoes(_par_obj);
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

  ICorba::IPista_stub::testarColisoes(_par_obj);
}

#endif // MICO_CONF_NO_POA

CORBA::Boolean ICorba::IPista_stub::criarPista( const char* _par_caminho )
{
  CORBA::StaticAny _sa_caminho( CORBA::_stc_string, &_par_caminho );
  CORBA::Boolean _res;
  CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );

  CORBA::StaticRequest __req( this, "criarPista" );
  __req.add_in_arg( &_sa_caminho );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

CORBA::Boolean
ICorba::IPista_stub_clp::criarPista( const char* _par_caminho )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      CORBA::Boolean __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->criarPista(_par_caminho);
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

  return ICorba::IPista_stub::criarPista(_par_caminho);
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

void ICorba::IPista_stub::setPosAtual( CORBA::Long _par_posAtual )
{
  CORBA::StaticAny _sa_posAtual( CORBA::_stc_long, &_par_posAtual );
  CORBA::StaticRequest __req( this, "setPosAtual" );
  __req.add_in_arg( &_sa_posAtual );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::setPosAtual( CORBA::Long _par_posAtual )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setPosAtual(_par_posAtual);
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

  ICorba::IPista_stub::setPosAtual(_par_posAtual);
}

#endif // MICO_CONF_NO_POA

ICorba::IPista::vetor_objetos* ICorba::IPista_stub::getObjetos()
{
  CORBA::StaticAny __res( _marshaller__seq_ICorba_IObjeto );

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

void ICorba::IPista_stub::setObjetos( const ICorba::IPista::vetor_objetos& _par_objs )
{
  CORBA::StaticAny _sa_objs( _marshaller__seq_ICorba_IObjeto, &_par_objs );
  CORBA::StaticRequest __req( this, "setObjetos" );
  __req.add_in_arg( &_sa_objs );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::setObjetos( const ICorba::IPista::vetor_objetos& _par_objs )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setObjetos(_par_objs);
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

  ICorba::IPista_stub::setObjetos(_par_objs);
}

#endif // MICO_CONF_NO_POA

void ICorba::IPista_stub::setDimValida( const ICorba::Dimensao& _par_dimValida )
{
  CORBA::StaticAny _sa_dimValida( _marshaller_ICorba_Dimensao, &_par_dimValida );
  CORBA::StaticRequest __req( this, "setDimValida" );
  __req.add_in_arg( &_sa_dimValida );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
}


#ifndef MICO_CONF_NO_POA

void
ICorba::IPista_stub_clp::setDimValida( const ICorba::Dimensao& _par_dimValida )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_ICorba::IPista * _myserv = POA_ICorba::IPista::_narrow (_serv);
    if (_myserv) {
      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        _myserv->setDimValida(_par_dimValida);
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

  ICorba::IPista_stub::setDimValida(_par_dimValida);
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

class _Marshaller__seq_ICorba_IObjeto : public ::CORBA::StaticTypeInfo {
    typedef IfaceSequenceTmpl< ICorba::IObjeto_var,ICorba::IObjeto_ptr> _MICO_T;
  public:
    ~_Marshaller__seq_ICorba_IObjeto();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller__seq_ICorba_IObjeto::~_Marshaller__seq_ICorba_IObjeto()
{
}

::CORBA::StaticValueType _Marshaller__seq_ICorba_IObjeto::create() const
{
  return (StaticValueType) new _MICO_T;
}

void _Marshaller__seq_ICorba_IObjeto::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = *(_MICO_T*) s;
}

void _Marshaller__seq_ICorba_IObjeto::free( StaticValueType v ) const
{
  delete (_MICO_T*) v;
}

::CORBA::Boolean _Marshaller__seq_ICorba_IObjeto::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::ULong len;
  if( !dc.seq_begin( len ) )
    return FALSE;
  ((_MICO_T *) v)->length( len );
  for( ::CORBA::ULong i = 0; i < len; i++ ) {
    if( !_marshaller_ICorba_IObjeto->demarshal( dc, &(*(_MICO_T*)v)[i]._for_demarshal() ) )
      return FALSE;
  }
  return dc.seq_end();
}

void _Marshaller__seq_ICorba_IObjeto::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::ULong len = ((_MICO_T *) v)->length();
  ec.seq_begin( len );
  for( ::CORBA::ULong i = 0; i < len; i++ )
    _marshaller_ICorba_IObjeto->marshal( ec, &(*(_MICO_T*)v)[i].inout() );
  ec.seq_end();
}

::CORBA::StaticTypeInfo *_marshaller__seq_ICorba_IObjeto;

struct __tc_init_ICORBA {
  __tc_init_ICORBA()
  {
    _marshaller_ICorba_Dimensao = new _Marshaller_ICorba_Dimensao;
    _marshaller_ICorba_Direcao = new _Marshaller_ICorba_Direcao;
    _marshaller_ICorba_IObjeto = new _Marshaller_ICorba_IObjeto;
    _marshaller_ICorba_IObstaculo = new _Marshaller_ICorba_IObstaculo;
    _marshaller_ICorba_IPersonagem = new _Marshaller_ICorba_IPersonagem;
    _marshaller_ICorba_IPista = new _Marshaller_ICorba_IPista;
    _marshaller__seq_ICorba_IObjeto = new _Marshaller__seq_ICorba_IObjeto;
  }

  ~__tc_init_ICORBA()
  {
    delete static_cast<_Marshaller_ICorba_Dimensao*>(_marshaller_ICorba_Dimensao);
    delete static_cast<_Marshaller_ICorba_Direcao*>(_marshaller_ICorba_Direcao);
    delete static_cast<_Marshaller_ICorba_IObjeto*>(_marshaller_ICorba_IObjeto);
    delete static_cast<_Marshaller_ICorba_IObstaculo*>(_marshaller_ICorba_IObstaculo);
    delete static_cast<_Marshaller_ICorba_IPersonagem*>(_marshaller_ICorba_IPersonagem);
    delete static_cast<_Marshaller_ICorba_IPista*>(_marshaller_ICorba_IPista);
    delete static_cast<_Marshaller__seq_ICorba_IObjeto*>(_marshaller__seq_ICorba_IObjeto);
  }
};

static __tc_init_ICORBA __init_ICORBA;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface ICorba::IObjeto
POA_ICorba::IObjeto::~IObjeto()
{
}

::ICorba::IObjeto_ptr
POA_ICorba::IObjeto::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::ICorba::IObjeto::_narrow (obj);
}

CORBA::Boolean
POA_ICorba::IObjeto::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:ICorba/IObjeto:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_ICorba::IObjeto::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:ICorba/IObjeto:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_ICorba::IObjeto::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:ICorba/IObjeto:1.0");
}

CORBA::Object_ptr
POA_ICorba::IObjeto::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::ICorba::IObjeto_stub_clp (poa, obj);
}

bool
POA_ICorba::IObjeto::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 23)) {
    case 6:
      if( strcmp( __req->op_name(), "setTamanho" ) == 0 ) {
        ::ICorba::Dimensao _par_Tamanho;
        CORBA::StaticAny _sa_Tamanho( _marshaller_ICorba_Dimensao, &_par_Tamanho );

        __req->add_in_arg( &_sa_Tamanho );

        if( !__req->read_args() )
          return true;

        setTamanho( _par_Tamanho );
        __req->write_results();
        return true;
      }
      break;
    case 7:
      if( strcmp( __req->op_name(), "setAtivo" ) == 0 ) {
        CORBA::Boolean _par_ativo;
        CORBA::StaticAny _sa_ativo( CORBA::_stc_boolean, &_par_ativo );

        __req->add_in_arg( &_sa_ativo );

        if( !__req->read_args() )
          return true;

        setAtivo( _par_ativo );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getTamanho" ) == 0 ) {
        ::ICorba::Dimensao _res;
        CORBA::StaticAny __res( _marshaller_ICorba_Dimensao, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getTamanho();
        __req->write_results();
        return true;
      }
      break;
    case 9:
      if( strcmp( __req->op_name(), "getAtivo" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getAtivo();
        __req->write_results();
        return true;
      }
      break;
    case 11:
      if( strcmp( __req->op_name(), "setStrSprite" ) == 0 ) {
        CORBA::String_var _par_sprite;
        CORBA::StaticAny _sa_sprite( CORBA::_stc_string, &_par_sprite._for_demarshal() );

        __req->add_in_arg( &_sa_sprite );

        if( !__req->read_args() )
          return true;

        setStrSprite( _par_sprite.inout() );
        __req->write_results();
        return true;
      }
      break;
    case 12:
      if( strcmp( __req->op_name(), "Morrer" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        Morrer();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getTipo" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getTipo();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "setTipo" ) == 0 ) {
        CORBA::Long _par_tipo;
        CORBA::StaticAny _sa_tipo( CORBA::_stc_long, &_par_tipo );

        __req->add_in_arg( &_sa_tipo );

        if( !__req->read_args() )
          return true;

        setTipo( _par_tipo );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getAceleracao" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getAceleracao();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "setAceleracao" ) == 0 ) {
        CORBA::Long _par_Aceleracao;
        CORBA::StaticAny _sa_Aceleracao( CORBA::_stc_long, &_par_Aceleracao );

        __req->add_in_arg( &_sa_Aceleracao );

        if( !__req->read_args() )
          return true;

        setAceleracao( _par_Aceleracao );
        __req->write_results();
        return true;
      }
      break;
    case 16:
      if( strcmp( __req->op_name(), "Colidir" ) == 0 ) {
        ::ICorba::IObjeto_var _par_obj;
        CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj._for_demarshal() );

        ::ICorba::Direcao _res;
        CORBA::StaticAny __res( _marshaller_ICorba_Direcao, &_res );
        __req->add_in_arg( &_sa_obj );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = Colidir( _par_obj.inout() );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getStrSprite" ) == 0 ) {
        char* _res;
        CORBA::StaticAny __res( CORBA::_stc_string, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getStrSprite();
        __req->write_results();
        CORBA::string_free( _res );
        return true;
      }
      break;
    case 19:
      if( strcmp( __req->op_name(), "setPosicao" ) == 0 ) {
        ::ICorba::Dimensao _par_Posicao;
        CORBA::StaticAny _sa_Posicao( _marshaller_ICorba_Dimensao, &_par_Posicao );

        __req->add_in_arg( &_sa_Posicao );

        if( !__req->read_args() )
          return true;

        setPosicao( _par_Posicao );
        __req->write_results();
        return true;
      }
      break;
    case 20:
      if( strcmp( __req->op_name(), "getPosicao" ) == 0 ) {
        ::ICorba::Dimensao _res;
        CORBA::StaticAny __res( _marshaller_ICorba_Dimensao, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getPosicao();
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
POA_ICorba::IObjeto::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface ICorba::IObstaculo
POA_ICorba::IObstaculo::~IObstaculo()
{
}

::ICorba::IObstaculo_ptr
POA_ICorba::IObstaculo::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::ICorba::IObstaculo::_narrow (obj);
}

CORBA::Boolean
POA_ICorba::IObstaculo::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:ICorba/IObstaculo:1.0") == 0) {
    return TRUE;
  }
  if (POA_ICorba::IObjeto::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_ICorba::IObstaculo::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:ICorba/IObstaculo:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_ICorba::IObstaculo::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:ICorba/IObstaculo:1.0");
}

CORBA::Object_ptr
POA_ICorba::IObstaculo::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::ICorba::IObstaculo_stub_clp (poa, obj);
}

bool
POA_ICorba::IObstaculo::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "criarObstaculo" ) == 0 ) {
      CORBA::Boolean _par_ativo;
      CORBA::StaticAny _sa_ativo( CORBA::_stc_boolean, &_par_ativo );
      CORBA::String_var _par_sprite;
      CORBA::StaticAny _sa_sprite( CORBA::_stc_string, &_par_sprite._for_demarshal() );
      ::ICorba::Dimensao _par_posicao;
      CORBA::StaticAny _sa_posicao( _marshaller_ICorba_Dimensao, &_par_posicao );
      ::ICorba::Dimensao _par_tamanho;
      CORBA::StaticAny _sa_tamanho( _marshaller_ICorba_Dimensao, &_par_tamanho );
      CORBA::Double _par_funcionalidade;
      CORBA::StaticAny _sa_funcionalidade( CORBA::_stc_double, &_par_funcionalidade );

      CORBA::Boolean _res;
      CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
      __req->add_in_arg( &_sa_ativo );
      __req->add_in_arg( &_sa_sprite );
      __req->add_in_arg( &_sa_posicao );
      __req->add_in_arg( &_sa_tamanho );
      __req->add_in_arg( &_sa_funcionalidade );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = criarObstaculo( _par_ativo, _par_sprite.inout(), _par_posicao, _par_tamanho, _par_funcionalidade );
      __req->write_results();
      return true;
    }
    if( strcmp( __req->op_name(), "getFuncionalidade" ) == 0 ) {
      CORBA::Double _res;
      CORBA::StaticAny __res( CORBA::_stc_double, &_res );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = getFuncionalidade();
      __req->write_results();
      return true;
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

  if (POA_ICorba::IObjeto::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_ICorba::IObstaculo::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


// PortableServer Skeleton Class for interface ICorba::IPersonagem
POA_ICorba::IPersonagem::~IPersonagem()
{
}

::ICorba::IPersonagem_ptr
POA_ICorba::IPersonagem::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::ICorba::IPersonagem::_narrow (obj);
}

CORBA::Boolean
POA_ICorba::IPersonagem::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:ICorba/IPersonagem:1.0") == 0) {
    return TRUE;
  }
  if (POA_ICorba::IObjeto::_is_a (repoid)) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_ICorba::IPersonagem::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:ICorba/IPersonagem:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_ICorba::IPersonagem::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:ICorba/IPersonagem:1.0");
}

CORBA::Object_ptr
POA_ICorba::IPersonagem::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::ICorba::IPersonagem_stub_clp (poa, obj);
}

bool
POA_ICorba::IPersonagem::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    switch (mico_string_hash (__req->op_name(), 37)) {
    case 1:
      if( strcmp( __req->op_name(), "getVelocidade" ) == 0 ) {
        CORBA::Double _res;
        CORBA::StaticAny __res( CORBA::_stc_double, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getVelocidade();
        __req->write_results();
        return true;
      }
      break;
    case 3:
      if( strcmp( __req->op_name(), "ir_baixo" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = ir_baixo();
        __req->write_results();
        return true;
      }
      break;
    case 5:
      if( strcmp( __req->op_name(), "ir_esquerda" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = ir_esquerda();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "ir_cima" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = ir_cima();
        __req->write_results();
        return true;
      }
      break;
    case 7:
      if( strcmp( __req->op_name(), "getGodMod" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getGodMod();
        __req->write_results();
        return true;
      }
      break;
    case 8:
      if( strcmp( __req->op_name(), "setGodMod" ) == 0 ) {
        CORBA::Boolean _par_godMod;
        CORBA::StaticAny _sa_godMod( CORBA::_stc_boolean, &_par_godMod );

        __req->add_in_arg( &_sa_godMod );

        if( !__req->read_args() )
          return true;

        setGodMod( _par_godMod );
        __req->write_results();
        return true;
      }
      break;
    case 11:
      if( strcmp( __req->op_name(), "atirar" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = atirar();
        __req->write_results();
        return true;
      }
      break;
    case 13:
      if( strcmp( __req->op_name(), "setObstaculosAtingidos" ) == 0 ) {
        CORBA::Long _par_ObstaculosAtingidos;
        CORBA::StaticAny _sa_ObstaculosAtingidos( CORBA::_stc_long, &_par_ObstaculosAtingidos );

        __req->add_in_arg( &_sa_ObstaculosAtingidos );

        if( !__req->read_args() )
          return true;

        setObstaculosAtingidos( _par_ObstaculosAtingidos );
        __req->write_results();
        return true;
      }
      break;
    case 15:
      if( strcmp( __req->op_name(), "getObstaculosAtingidos" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getObstaculosAtingidos();
        __req->write_results();
        return true;
      }
      break;
    case 16:
      if( strcmp( __req->op_name(), "ColidirPersonagem" ) == 0 ) {
        ::ICorba::IObjeto_var _par_obj;
        CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj._for_demarshal() );

        ::ICorba::Direcao _res;
        CORBA::StaticAny __res( _marshaller_ICorba_Direcao, &_res );
        __req->add_in_arg( &_sa_obj );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = ColidirPersonagem( _par_obj.inout() );
        __req->write_results();
        return true;
      }
      break;
    case 17:
      if( strcmp( __req->op_name(), "acelerar" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = acelerar();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "setTempoFim" ) == 0 ) {
        CORBA::Long _par_tempoFim;
        CORBA::StaticAny _sa_tempoFim( CORBA::_stc_long, &_par_tempoFim );

        __req->add_in_arg( &_sa_tempoFim );

        if( !__req->read_args() )
          return true;

        setTempoFim( _par_tempoFim );
        __req->write_results();
        return true;
      }
      break;
    case 22:
      if( strcmp( __req->op_name(), "getTiro" ) == 0 ) {
        ::ICorba::IObstaculo_ptr _res;
        CORBA::StaticAny __res( _marshaller_ICorba_IObstaculo, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getTiro();
        __req->write_results();
        CORBA::release( _res );
        return true;
      }
      if( strcmp( __req->op_name(), "getTempoFim" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getTempoFim();
        __req->write_results();
        return true;
      }
      break;
    case 27:
      if( strcmp( __req->op_name(), "getMunicao" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getMunicao();
        __req->write_results();
        return true;
      }
      break;
    case 28:
      if( strcmp( __req->op_name(), "frear" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = frear();
        __req->write_results();
        return true;
      }
      break;
    case 29:
      if( strcmp( __req->op_name(), "getScore" ) == 0 ) {
        CORBA::Long _res;
        CORBA::StaticAny __res( CORBA::_stc_long, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getScore();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "setMunicao" ) == 0 ) {
        CORBA::Long _par_municao;
        CORBA::StaticAny _sa_municao( CORBA::_stc_long, &_par_municao );

        __req->add_in_arg( &_sa_municao );

        if( !__req->read_args() )
          return true;

        setMunicao( _par_municao );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "setEhSpider" ) == 0 ) {
        CORBA::Boolean _par_ehSpider;
        CORBA::StaticAny _sa_ehSpider( CORBA::_stc_boolean, &_par_ehSpider );

        __req->add_in_arg( &_sa_ehSpider );

        if( !__req->read_args() )
          return true;

        setEhSpider( _par_ehSpider );
        __req->write_results();
        return true;
      }
      break;
    case 30:
      if( strcmp( __req->op_name(), "criarPersonagem" ) == 0 ) {
        CORBA::Boolean _par_ativo;
        CORBA::StaticAny _sa_ativo( CORBA::_stc_boolean, &_par_ativo );
        CORBA::String_var _par_sprite;
        CORBA::StaticAny _sa_sprite( CORBA::_stc_string, &_par_sprite._for_demarshal() );
        ::ICorba::Dimensao _par_posicao;
        CORBA::StaticAny _sa_posicao( _marshaller_ICorba_Dimensao, &_par_posicao );
        ::ICorba::Dimensao _par_tamanho;
        CORBA::StaticAny _sa_tamanho( _marshaller_ICorba_Dimensao, &_par_tamanho );
        CORBA::Long _par_velocidadeInicial;
        CORBA::StaticAny _sa_velocidadeInicial( CORBA::_stc_long, &_par_velocidadeInicial );
        CORBA::Long _par_municaoInicial;
        CORBA::StaticAny _sa_municaoInicial( CORBA::_stc_long, &_par_municaoInicial );
        CORBA::Boolean _par_spider;
        CORBA::StaticAny _sa_spider( CORBA::_stc_boolean, &_par_spider );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_ativo );
        __req->add_in_arg( &_sa_sprite );
        __req->add_in_arg( &_sa_posicao );
        __req->add_in_arg( &_sa_tamanho );
        __req->add_in_arg( &_sa_velocidadeInicial );
        __req->add_in_arg( &_sa_municaoInicial );
        __req->add_in_arg( &_sa_spider );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = criarPersonagem( _par_ativo, _par_sprite.inout(), _par_posicao, _par_tamanho, _par_velocidadeInicial, _par_municaoInicial, _par_spider );
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "setVelocidade" ) == 0 ) {
        CORBA::Double _par_velocidade;
        CORBA::StaticAny _sa_velocidade( CORBA::_stc_double, &_par_velocidade );

        __req->add_in_arg( &_sa_velocidade );

        if( !__req->read_args() )
          return true;

        setVelocidade( _par_velocidade );
        __req->write_results();
        return true;
      }
      break;
    case 32:
      if( strcmp( __req->op_name(), "mudarImagem" ) == 0 ) {

        if( !__req->read_args() )
          return true;

        mudarImagem();
        __req->write_results();
        return true;
      }
      break;
    case 34:
      if( strcmp( __req->op_name(), "ir_direita" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = ir_direita();
        __req->write_results();
        return true;
      }
      if( strcmp( __req->op_name(), "getEhSpider" ) == 0 ) {
        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getEhSpider();
        __req->write_results();
        return true;
      }
      break;
    case 36:
      if( strcmp( __req->op_name(), "MorrerPersonagem" ) == 0 ) {
        CORBA::Long _par_tempo;
        CORBA::StaticAny _sa_tempo( CORBA::_stc_long, &_par_tempo );

        __req->add_in_arg( &_sa_tempo );

        if( !__req->read_args() )
          return true;

        MorrerPersonagem( _par_tempo );
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

  if (POA_ICorba::IObjeto::dispatch (__req)) {
    return true;
  }

  return false;
}

void
POA_ICorba::IPersonagem::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}


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
    switch (mico_string_hash (__req->op_name(), 29)) {
    case 0:
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
      if( strcmp( __req->op_name(), "setObjetos" ) == 0 ) {
        ::ICorba::IPista::vetor_objetos _par_objs;
        CORBA::StaticAny _sa_objs( _marshaller__seq_ICorba_IObjeto, &_par_objs );

        __req->add_in_arg( &_sa_objs );

        if( !__req->read_args() )
          return true;

        setObjetos( _par_objs );
        __req->write_results();
        return true;
      }
      break;
    case 1:
      if( strcmp( __req->op_name(), "setDimValida" ) == 0 ) {
        ::ICorba::Dimensao _par_dimValida;
        CORBA::StaticAny _sa_dimValida( _marshaller_ICorba_Dimensao, &_par_dimValida );

        __req->add_in_arg( &_sa_dimValida );

        if( !__req->read_args() )
          return true;

        setDimValida( _par_dimValida );
        __req->write_results();
        return true;
      }
      break;
    case 3:
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
    case 4:
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
    case 5:
      if( strcmp( __req->op_name(), "getObjetos" ) == 0 ) {
        ::ICorba::IPista::vetor_objetos* _res;
        CORBA::StaticAny __res( _marshaller__seq_ICorba_IObjeto );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = getObjetos();
        __res.value( _marshaller__seq_ICorba_IObjeto, _res );
        __req->write_results();
        delete _res;
        return true;
      }
      break;
    case 6:
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
    case 10:
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
      break;
    case 13:
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
      break;
    case 16:
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
      break;
    case 22:
      if( strcmp( __req->op_name(), "setPosAtual" ) == 0 ) {
        CORBA::Long _par_posAtual;
        CORBA::StaticAny _sa_posAtual( CORBA::_stc_long, &_par_posAtual );

        __req->add_in_arg( &_sa_posAtual );

        if( !__req->read_args() )
          return true;

        setPosAtual( _par_posAtual );
        __req->write_results();
        return true;
      }
      break;
    case 23:
      if( strcmp( __req->op_name(), "criarPista" ) == 0 ) {
        CORBA::String_var _par_caminho;
        CORBA::StaticAny _sa_caminho( CORBA::_stc_string, &_par_caminho._for_demarshal() );

        CORBA::Boolean _res;
        CORBA::StaticAny __res( CORBA::_stc_boolean, &_res );
        __req->add_in_arg( &_sa_caminho );
        __req->set_result( &__res );

        if( !__req->read_args() )
          return true;

        _res = criarPista( _par_caminho.inout() );
        __req->write_results();
        return true;
      }
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
    case 25:
      if( strcmp( __req->op_name(), "adicionarObjeto" ) == 0 ) {
        ::ICorba::IObjeto_var _par_obj;
        CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj._for_demarshal() );

        __req->add_in_arg( &_sa_obj );

        if( !__req->read_args() )
          return true;

        adicionarObjeto( _par_obj.inout() );
        __req->write_results();
        return true;
      }
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
    case 28:
      if( strcmp( __req->op_name(), "testarColisoes" ) == 0 ) {
        ::ICorba::IObjeto_var _par_obj;
        CORBA::StaticAny _sa_obj( _marshaller_ICorba_IObjeto, &_par_obj._for_demarshal() );

        __req->add_in_arg( &_sa_obj );

        if( !__req->read_args() )
          return true;

        testarColisoes( _par_obj.inout() );
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

