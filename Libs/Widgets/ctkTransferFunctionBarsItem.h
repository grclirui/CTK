/*=========================================================================

  Library:   CTK
 
  Copyright (c) 2010  Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 
=========================================================================*/

#ifndef __ctkTransferFunctionBarsItem_h
#define __ctkTransferFunctionBarsItem_h

/// Qt includes
#include <QGraphicsObject>

/// CTK includes
#include "ctkPimpl.h"
#include "ctkTransferFunctionItem.h"
#include "CTKWidgetsExport.h"

class ctkTransferFunction;
class ctkTransferFunctionBarsItemPrivate;

//-----------------------------------------------------------------------------
class CTK_WIDGETS_EXPORT ctkTransferFunctionBarsItem: public ctkTransferFunctionItem
{
  Q_OBJECT
  Q_PROPERTY(qreal barWidth READ barWidth WRITE setBarWidth)
public:
  ctkTransferFunctionBarsItem(QGraphicsItem* parent = 0);
  ctkTransferFunctionBarsItem(ctkTransferFunction* transferFunc, 
                              QGraphicsItem* parent = 0);
  virtual ~ctkTransferFunctionBarsItem();
  
  void setBarWidth(qreal newBarWidth);  
  qreal barWidth()const;

  virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
private:
  CTK_DECLARE_PRIVATE(ctkTransferFunctionBarsItem);
};

#endif
