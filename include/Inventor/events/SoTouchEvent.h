#ifndef COIN_TOUCHEVENT_H
#define COIN_TOUCHEVENT_H

/**************************************************************************\
 * Copyright (c) Benjamin Nauck
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#include <Inventor/events/SoButtonEvent.h>


class COIN_DLL_API SoTouchEvent : public SoEvent {
  typedef SoEvent inherited;

  SO_EVENT_HEADER();

public:
  static void initClass(void);

  enum class States {
    UNKNOWN, UP, DOWN, MOVE 
  };

  SoTouchEvent(void);
  virtual ~SoTouchEvent();

  void setState(States state);
  States getState(void) const;

  void setFingerId(unsigned int fingerId);
  unsigned int getFingerId(void) const;

  SbVec2s getPosition(void) const;
  SbVec2f getPositionFloat(void) const;
  SbVec2f getPreviousPosition(void) const;
  
  void setPosition(SbVec2f);
  void setPosition(SbVec2s);

  SbVec2f getSpeed(void) const;
  SbVec2f getPreviousSpeed(void) const;
  void setPreviousSpeed(void);
  void setSpeed(SbVec2f);

private:
  States states{};
  unsigned int fingerId{0};
  SbVec2f position{0,0};
  SbVec2f speed{0,0};

}; // SoTouchEvent

#endif // !COIN_TOUCHEVENT_H
