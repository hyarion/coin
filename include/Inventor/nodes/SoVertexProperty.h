/**************************************************************************\
 *
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

#ifndef __SOVERTEXPROPERTY_H__
#define __SOVERTEXPROPERTY_H__

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/fields/SoMFUInt32.h>
#include <Inventor/fields/SoMFVec3f.h>
#include <Inventor/fields/SoMFVec2f.h>
#include <Inventor/fields/SoSFEnum.h>

#if defined(COIN_EXCLUDE_SOVERTEXPROPERTY)
#error Configuration settings disrespected -- do not include this file!
#endif // COIN_EXCLUDE_SOVERTEXPROPERTY


class SoVertexProperty : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoVertexProperty);

public:
  static void initClass(void);
  SoVertexProperty(void);

  // These must match 100% with the enum in SoMaterialBindingElement.
  enum Binding {
    OVERALL = 2,
    PER_PART,
    PER_PART_INDEXED,
    PER_FACE,
    PER_FACE_INDEXED,
    PER_VERTEX,
    PER_VERTEX_INDEXED
  };

  SoMFVec3f vertex;
  SoMFVec2f texCoord;
  SoMFVec3f normal;
  SoSFEnum normalBinding;
  SoMFUInt32 orderedRGBA;
  SoSFEnum materialBinding;

#if !defined(COIN_EXCLUDE_SOACTION)
  virtual void doAction(SoAction * action);
#endif // !COIN_EXCLUDE_SOACTION
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION)
  virtual void GLRender(SoGLRenderAction * action);
#endif // !COIN_EXCLUDE_SOGLRENDERACTION
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION)
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION
#if !defined(COIN_EXCLUDE_SOCALLBACKACTION)
  virtual void callback(SoCallbackAction * action);
#endif // !COIN_EXCLUDE_SOCALLBACKACTION
#if !defined(COIN_EXCLUDE_SOPICKACTION)
  virtual void pick(SoPickAction * action);
#endif // !COIN_EXCLUDE_SOPICKACTION
#if !defined(COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION)
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
#endif // !COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION

protected:
  virtual ~SoVertexProperty();
};

#endif // !__SOVERTEXPROPERTY_H__
