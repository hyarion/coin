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

#ifndef __SOLIGHT_H__
#define __SOLIGHT_H__

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/fields/SoSFBool.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoSFColor.h>

#if defined(COIN_EXCLUDE_SOLIGHT)
#error Configuration settings disrespected -- do not include this file!
#endif // COIN_EXCLUDE_SOLIGHT

// *************************************************************************

class SoLight : public SoNode {
  typedef SoNode inherited;

  SO_NODE_ABSTRACT_HEADER(SoLight);

public:
  static void initClass(void);

  SoSFBool on;
  SoSFFloat intensity;
  SoSFColor color;

#if !defined(COIN_EXCLUDE_SOCALLBACKACTION)
  virtual void callback(SoCallbackAction * action);
#endif // !COIN_EXCLUDE_SOCALLBACKACTION

protected:
  SoLight(void);
  virtual ~SoLight();
};

#endif // !__SOLIGHT_H__
