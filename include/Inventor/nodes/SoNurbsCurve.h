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

#ifndef __SONURBSCURVE_H__
#define __SONURBSCURVE_H__

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoShape.h>
#include <Inventor/fields/SoSFInt32.h>
#include <Inventor/fields/SoMFFloat.h>

#if defined(COIN_EXCLUDE_SONURBSCURVE)
#error Configuration settings disrespected -- do not include this file!
#endif // COIN_EXCLUDE_SONURBSCURVE

#ifndef _WIN32
#include <GL/glu.h>
#endif // !_WIN32

// *************************************************************************

class SoNurbsCurve : public SoShape {
    typedef SoShape inherited;

  SO_NODE_HEADER(SoNurbsCurve);

public:
  static void initClass(void);
  SoNurbsCurve(void);

  SoSFInt32 numControlPoints;
  SoMFFloat knotVector;

#if !defined(COIN_EXCLUDE_SOGLRENDERACTION)
  virtual void GLRender(SoGLRenderAction * action);
#endif // !COIN_EXCLUDE_SOGLRENDERACTION
#if !defined(COIN_EXCLUDE_SORAYPICKACTION)
  virtual void rayPick(SoRayPickAction * action);
#endif // !COIN_EXCLUDE_SORAYPICKACTION
#if !defined(COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION)
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
#endif // !COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION)
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION
#if !defined(COIN_EXCLUDE_SOACTION)
  void sendPrimitive(SoAction *,  SoPrimitiveVertex *);
#endif // !COIN_EXCLUDE_SOACTION

protected:
  virtual ~SoNurbsCurve();

#if !defined(COIN_EXCLUDE_SOACTION)
  virtual void generatePrimitives(SoAction * action);
#endif // !COIN_EXCLUDE_SOACTION
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION)
  virtual void computeBBox(SoAction * action, SbBox3f & box, SbVec3f & center);
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION

private:
#ifdef _WIN32
  class GLUnurbs * nurbsRenderer;
#else // !_WIN32
  GLUnurbsObj * nurbsRenderer;
#endif // !_WIN32
};

#endif // !__SONURBSCURVE_H__
