/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

/*!
  \class SoTextureCoordinateObject SoTextureCoordinateObject.h Inventor/nodes/SoTextureCoordinateObject.h
  \brief The SoTextureCoordinateObject class generates texture coordinates by...
  \ingroup nodes

  FIXME: not implemented yet. pederb, 2005-04-20

*/

#include <Inventor/nodes/SoTextureCoordinateObject.h>
#include <Inventor/nodes/SoSubNodeP.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/elements/SoGLTextureCoordinateElement.h>
#include <Inventor/elements/SoGLCacheContextElement.h>
#include <Inventor/elements/SoGLMultiTextureCoordinateElement.h>
#include <Inventor/elements/SoTextureUnitElement.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif // HAVE_CONFIG_H
#include <Inventor/system/gl.h>
#include <Inventor/C/glue/gl.h>

/*!
  \var SoSFVec3f SoTextureCoordinateObject::factorS
  
  FIXME doc.
*/
/*!
  \var SoSFVec3f SoTextureCoordinateObject::factorT
  
  FIXME doc.
*/
/*!
  \var SoSFVec3f SoTextureCoordinateObject::factorR
  
  FIXME doc.
*/
/*!
  \var SoSFVec3f SoTextureCoordinateObject::factorQ
  
  FIXME doc.
*/

// *************************************************************************

SO_NODE_SOURCE(SoTextureCoordinateObject);

/*!
  Constructor.
*/
SoTextureCoordinateObject::SoTextureCoordinateObject()
{
  SO_NODE_INTERNAL_CONSTRUCTOR(SoTextureCoordinateObject);

  SO_NODE_ADD_FIELD(factorS, (1.0f, 0.0f, 0.0f, 0.0f));
  SO_NODE_ADD_FIELD(factorT, (0.0f, 1.0f, 0.0f, 0.0f));
  SO_NODE_ADD_FIELD(factorR, (0.0f, 0.0f, 1.0f, 0.0f));
  SO_NODE_ADD_FIELD(factorQ, (0.0f, 0.0f, 0.0f, 1.0f));
}

/*!
  Destructor.
*/
SoTextureCoordinateObject::~SoTextureCoordinateObject()
{
}

// doc from parent
void
SoTextureCoordinateObject::initClass(void)
{
  SO_NODE_INTERNAL_INIT_CLASS(SoTextureCoordinateObject, SO_FROM_INVENTOR_2_0);
}

// generates texture coordinates for callback and raypick action
const SbVec4f &
SoTextureCoordinateObject::generate(void * userdata,
                                    const SbVec3f &p ,
                                    const SbVec3f & n)
{
  SoTextureCoordinateObject *thisp =
    (SoTextureCoordinateObject*) userdata;

  return thisp->dummy_object;
}

// doc from parent
void
SoTextureCoordinateObject::doAction(SoAction * action)
{
  SoState * state = action->getState();
  int unit = SoTextureUnitElement::get(state);
  if (unit == 0) {
    SoTextureCoordinateElement::setFunction(action->getState(), this,
                                            SoTextureCoordinateObject::generate,
                                            this);
  }
  else {
    SoMultiTextureCoordinateElement::setFunction(action->getState(), this, unit,
                                                 SoTextureCoordinateObject::generate,
                                                 this);
  }
}

// doc from parent
void
SoTextureCoordinateObject::GLRender(SoGLRenderAction * action)
{
  SoState * state = action->getState();
  int unit = SoTextureUnitElement::get(state);

  if (unit == 0) {
    SoTextureCoordinateObject::doAction((SoAction *)action);
    SoGLTextureCoordinateElement::setTexGen(action->getState(),
                                            this,
                                            SoTextureCoordinateObject::handleTexgen,
                                            this,
                                            SoTextureCoordinateObject::generate,
                                            this);
  }
  else {
    const cc_glglue * glue = cc_glglue_instance(SoGLCacheContextElement::get(state));
    int maxunits = cc_glglue_max_texture_units(glue);
    if (unit < maxunits) {        
      SoGLMultiTextureCoordinateElement::setTexGen(action->getState(),
                                                   this, unit,
                                                   SoTextureCoordinateObject::handleTexgen,
                                                   this,
                                                   SoTextureCoordinateObject::generate,
                                                   this);
    }
  }
}

// doc from parent
void
SoTextureCoordinateObject::callback(SoCallbackAction * action)
{
  SoTextureCoordinateObject::doAction((SoAction *)action);
}

// doc from parent
void
SoTextureCoordinateObject::pick(SoPickAction * action)
{
  SoTextureCoordinateObject::doAction((SoAction *)action);
}

// texgen callback. Turns on plane texgen in OpenGL
void
SoTextureCoordinateObject::handleTexgen(void *data)
{
}
