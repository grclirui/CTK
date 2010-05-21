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

/// Qt includes
#include <QColor>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QtGlobal>
#include <QVariant>

/// CTK includes
#include "ctkTransferFunction.h"
#include "ctkTransferFunctionBarsItem.h"
#include "ctkTransferFunctionScene.h"

//-----------------------------------------------------------------------------
class ctkTransferFunctionBarsItemPrivate: public ctkPrivate<ctkTransferFunctionBarsItem>
{
public:
  ctkTransferFunctionBarsItemPrivate();
  qreal BarWidth;
};

ctkTransferFunctionBarsItemPrivate::ctkTransferFunctionBarsItemPrivate()
{
  this->BarWidth = 0.7;
}

//-----------------------------------------------------------------------------
ctkTransferFunctionBarsItem::ctkTransferFunctionBarsItem(QGraphicsItem* parentGraphicsItem)
  :ctkTransferFunctionItem(parentGraphicsItem)
{
  CTK_INIT_PRIVATE(ctkTransferFunctionBarsItem);
}

//-----------------------------------------------------------------------------
ctkTransferFunctionBarsItem::ctkTransferFunctionBarsItem(
  ctkTransferFunction* transferFunc, QGraphicsItem* parentItem)
  :ctkTransferFunctionItem(transferFunc, parentItem)
{
  CTK_INIT_PRIVATE(ctkTransferFunctionBarsItem);
}

//-----------------------------------------------------------------------------
ctkTransferFunctionBarsItem::~ctkTransferFunctionBarsItem()
{  
}

//-----------------------------------------------------------------------------
void ctkTransferFunctionBarsItem::setBarWidth(qreal newBarWidth)
{
  CTK_D(ctkTransferFunctionBarsItem);
  if (d->BarWidth == newBarWidth)
    {
    return;
    }
  d->BarWidth = newBarWidth;
  this->update();
}

//-----------------------------------------------------------------------------
qreal ctkTransferFunctionBarsItem::barWidth()const
{
  CTK_D(const ctkTransferFunctionBarsItem);
  return d->BarWidth;
}

//-----------------------------------------------------------------------------
void ctkTransferFunctionBarsItem::paint(
  QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
  CTK_D(ctkTransferFunctionBarsItem);
  int count = this->transferFunction() ? this->transferFunction()->count() : 0;
  if (count <= 0)
    {
    return;
    }

  ctkTransferFunctionScene* tfScene = dynamic_cast<ctkTransferFunctionScene*>(this->scene());
  Q_ASSERT(tfScene);
  const QList<QPointF>& points = tfScene->points();

  QPainterPath bars;
  QPen pen(QColor(255, 255, 255, 191), 1);
  pen.setCosmetic(true);
  painter->setPen(pen);
  painter->setBrush(QBrush(QColor(191, 191, 191, 127)));

  qreal barWidth = d->BarWidth * (this->rect().width() / (points.size() - 1)); 
  qDebug() << "WIDTH: " << barWidth;
  foreach(const QPointF& point, points)
    {
    qDebug() << point << point.x()-barWidth/2 << this->rect().height() - point.y();
    bars.addRect(point.x()-barWidth/2, this->rect().height() - point.y(),
                 barWidth, point.y());
    }
  painter->drawPath(bars);
}

