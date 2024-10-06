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

#include <Inventor/events/SoTouchEvent.h>

#include "SbBasicP.h"

#include <Inventor/SbName.h>
#include <cassert>


SO_EVENT_SOURCE(SoTouchEvent);

void
SoTouchEvent::initClass(void)
{
  SO_EVENT_INIT_CLASS(SoTouchEvent, SoButtonEvent);
}

SoTouchEvent::SoTouchEvent(void)
{
}

SoTouchEvent::~SoTouchEvent()
{
}

void
SoTouchEvent::setState(States state)
{
  this->states = states;
}

SoTouchEvent::States
SoTouchEvent::getState(void)
{
  return states;
}

void
SoTouchEvent::setFingerId(unsigned int fingerId)
{
  this->fingerId = fingerId;
}

unsigned int
SoTouchEvent::getFingerId(void) const
{
  return this->fingerId;
}


SbVec2s
SoTouchEvent::getPosition(void) const
{
  return SbVec2s(this->position);
}

SbVec2f
SoTouchEvent::getPositionFloat(void) const
{
  return this->position;
}

void
SoTouchEvent::setPosition(SbVec2f position)
{
  this->position = position;
}

void
SoTouchEvent::setPosition(SbVec2s position)
{
  this->position = SbVec2f(position);
}

SbVec2f
SoTouchEvent::getSpeed(void) const
{
  return this->speed;
}

void
SoTouchEvent::setSpeed(SbVec2f speed)
{
  this->speed = speed;
}

