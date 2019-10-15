/*
    Copyright (c) 2008-2019 Jan W. Krieger (<jan@jkrieger.de>)

    

    This software is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License (LGPL) as published by
    the Free Software Foundation, either version 2.1 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License (LGPL) for more details.

    You should have received a copy of the GNU Lesser General Public License (LGPL)
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include "jkqtplotter/graphs/jkqtprange.h"
#include "jkqtplotter/jkqtpbaseplotter.h"
#include <stdlib.h>
#include <QDebug>
#include <iostream>
#include "jkqtplotter/jkqtptools.h"
#include "jkqtplotter/jkqtpimagetools.h"
#include "jkqtplotter/graphs/jkqtpimage.h"
#include "jkqtplotter/jkqtpbaseelements.h"
#include "jkqtplotter/jkqtplotter.h"
#define SmallestGreaterZeroCompare_xvsgz() if ((xvsgz>10.0*DBL_MIN)&&((smallestGreaterZero<10.0*DBL_MIN) || (xvsgz<smallestGreaterZero))) smallestGreaterZero=xvsgz;




JKQTPHorizontalRange::JKQTPHorizontalRange(JKQTBasePlotter* parent):
    JKQTPGraph(parent)
{
    centerColor=QColor("red");
    centerStyle=Qt::SolidLine;
    centerLineWidth=2;
    sizeMin=0;
    sizeMax=1;
    unlimitedSizeMin=true;
    unlimitedSizeMax=true;
    invertedRange=false;



    if (parent) { // get style settings from parent object
        initLineStyle(parent, parentPlotStyle);
        initFillStyle(parent, parentPlotStyle);
        centerColor=parent->getPlotStyle(parentPlotStyle).color();
    }

    rangeMin=rangeMax=0;
    rangeCenter=0;
    plotCenterLine=true;
    plotRange=true;
    plotRangeLines=true;
    fillRange=true;
}


JKQTPHorizontalRange::JKQTPHorizontalRange(JKQTPlotter* parent):
    JKQTPHorizontalRange(parent->getPlotter())
{

}

void JKQTPHorizontalRange::draw(JKQTPEnhancedPainter& painter) {
#ifdef JKQTBP_AUTOTIMER
    JKQTPAutoOutputTimer jkaaot("JKQTPHorizontalRange::draw");
#endif
    double c=transformY(rangeCenter);
    double cmi=transformY(rangeMin);
    double cma=transformY(rangeMax);
    double smi=transformY(parent->getYAxis()->getMin());
    double sma=transformY(parent->getYAxis()->getMax());
    double mi=transformX(parent->getXAxis()->getMin());
    double ma=transformX(parent->getXAxis()->getMax());
    if (!unlimitedSizeMin) mi=transformX(sizeMin);
    if (!unlimitedSizeMax) ma=transformX(sizeMax);
    //std::cout<<"hor: rangeMin="<<rangeMin<<" -> "<<cmi<<std::endl;
    //std::cout<<"hor: rangeMax="<<rangeMax<<" -> "<<cma<<std::endl;
    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    if (plotRange && (cmi!=cma) && JKQTPIsOKFloat(mi) && JKQTPIsOKFloat(ma)) {
        QPen p=getLinePen(painter, parent);
        QPen np(Qt::NoPen);
        QBrush nb(Qt::NoBrush);
        QBrush b=getFillBrush(painter, parent);
        QRectF rect(QPointF(mi, cmi), QPointF(ma, cma));
        if (fillRange) {
            painter.setPen(np);
            painter.setBrush(b);
            if (invertedRange) {
                if (JKQTPIsOKFloat(cmi)) {
                    QRectF rectl(QPointF(mi, smi), QPointF(ma, cmi));
                    painter.drawRect(rectl);
                }
                if (JKQTPIsOKFloat(cma)) {
                    QRectF rectr(QPointF(mi, cma), QPointF(ma, sma));
                    painter.drawRect(rectr);
                }
            } else {
                if (JKQTPIsOKFloat(cmi) && JKQTPIsOKFloat(cma)) painter.drawRect(rect);
            }
        }

        //std::cout<<"hor: rangeMin.rect.top="<<rect.top()<<std::endl;
        //std::cout<<"hor: rangeMax.rect.bottom="<<rect.bottom()<<std::endl;

        if (plotRangeLines && JKQTPIsOKFloat(cmi) && JKQTPIsOKFloat(cma)) {
            painter.setPen(p);
            painter.setBrush(nb);
            painter.drawLine(rect.left(), rect.top(), rect.right(), rect.top());
            painter.drawLine(rect.left(), rect.bottom(), rect.right(), rect.bottom());
        }

    }
    if (plotCenterLine && JKQTPIsOKFloat(c) && JKQTPIsOKFloat(mi) && JKQTPIsOKFloat(ma)) {
        QPen p=painter.pen();
        p.setColor(centerColor);
        p.setStyle(centerStyle);
        p.setWidthF(qMax(JKQTPlotterDrawingTools::ABS_MIN_LINEWIDTH, parent->pt2px(painter, centerLineWidth*parent->getLineWidthMultiplier())));
        painter.setPen(p);
        painter.drawLine(QLineF(mi, c, ma, c));
    }

}

void JKQTPHorizontalRange::drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) {
    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    QPen p=getLinePen(painter, parent);
    QPen np(Qt::NoPen);
    QBrush nb(Qt::NoBrush);
    QBrush b=getFillBrush(painter, parent);
    //int y=rect.top()+rect.height()/2.0;
    if (plotRange) {
        painter.setPen(np);
        painter.setBrush(b);
        if (fillRange) painter.drawRect(rect);
        painter.setPen(p);
        painter.setBrush(nb);
        if (plotRangeLines) {
            painter.drawLine(rect.left(), rect.top(), rect.right(), rect.top());
            painter.drawLine(rect.left(), rect.bottom(), rect.right(), rect.bottom());
        }
    }

    if (plotCenterLine) {
        QPen p=painter.pen();
        p.setColor(centerColor);
        p.setStyle(centerStyle);
        painter.setPen(p);
        int y=rect.top()+rect.height()/2.0;
        painter.drawLine(rect.left(), y, rect.right(), y);
    }

}

bool JKQTPHorizontalRange::getXMinMax(double &minx, double &maxx, double &smallestGreaterZero)
{
    smallestGreaterZero=minx=maxx=0;
    return false;
}

bool JKQTPHorizontalRange::getYMinMax(double &miny, double &maxy, double &smallestGreaterZero)
{
    miny=rangeMin;
    maxy=rangeMax;
    smallestGreaterZero=0;
    if (rangeMin>0) smallestGreaterZero=rangeMin;
    return true;
}

QColor JKQTPHorizontalRange::getKeyLabelColor() const
{
    return centerColor;
}

void JKQTPHorizontalRange::setDrawCenterLineOnly()
{
    plotCenterLine=true;
    plotRange=false;
}

void JKQTPHorizontalRange::setColor(QColor c)
{
    setLineColor(c);
    centerColor=c;
    setFillColor(JKQTPGetDerivedColor(parent->getCurrentPlotterStyle().graphFillColorDerivationMode, c));
}


void JKQTPHorizontalRange::setCenterColor(const QColor &__value)
{
    this->centerColor = __value;
}

QColor JKQTPHorizontalRange::getCenterColor() const
{
    return this->centerColor;
}

void JKQTPHorizontalRange::setCenterStyle(Qt::PenStyle __value)
{
    this->centerStyle = __value;
}

Qt::PenStyle JKQTPHorizontalRange::getCenterStyle() const
{
    return this->centerStyle;
}

void JKQTPHorizontalRange::setCenterLineWidth(double __value)
{
    this->centerLineWidth = __value;
}

double JKQTPHorizontalRange::getCenterLineWidth() const
{
    return this->centerLineWidth;
}

void JKQTPHorizontalRange::setRangeMin(double __value)
{
    this->rangeMin = __value;
}

double JKQTPHorizontalRange::getRangeMin() const
{
    return this->rangeMin;
}

void JKQTPHorizontalRange::setRangeMax(double __value)
{
    this->rangeMax = __value;
}

double JKQTPHorizontalRange::getRangeMax() const
{
    return this->rangeMax;
}

void JKQTPHorizontalRange::setSizeMin(double __value)
{
    this->sizeMin = __value;
}

double JKQTPHorizontalRange::getSizeMin() const
{
    return this->sizeMin;
}

void JKQTPHorizontalRange::setSizeMax(double __value)
{
    this->sizeMax = __value;
}

double JKQTPHorizontalRange::getSizeMax() const
{
    return this->sizeMax;
}

void JKQTPHorizontalRange::setUnlimitedSizeMin(bool __value)
{
    this->unlimitedSizeMin = __value;
}

bool JKQTPHorizontalRange::getUnlimitedSizeMin() const
{
    return this->unlimitedSizeMin;
}

void JKQTPHorizontalRange::setUnlimitedSizeMax(bool __value)
{
    this->unlimitedSizeMax = __value;
}

bool JKQTPHorizontalRange::getUnlimitedSizeMax() const
{
    return this->unlimitedSizeMax;
}

void JKQTPHorizontalRange::setRangeCenter(double __value)
{
    this->rangeCenter = __value;
}

double JKQTPHorizontalRange::getRangeCenter() const
{
    return this->rangeCenter;
}

void JKQTPHorizontalRange::setPlotCenterLine(bool __value)
{
    this->plotCenterLine = __value;
}

bool JKQTPHorizontalRange::getPlotCenterLine() const
{
    return this->plotCenterLine;
}

void JKQTPHorizontalRange::setInvertedRange(bool __value)
{
    this->invertedRange = __value;
}

bool JKQTPHorizontalRange::getInvertedRange() const
{
    return this->invertedRange;
}

void JKQTPHorizontalRange::setPlotRange(bool __value)
{
    this->plotRange = __value;
}

bool JKQTPHorizontalRange::getPlotRange() const
{
    return this->plotRange;
}

void JKQTPHorizontalRange::setFillRange(bool __value)
{
    this->fillRange = __value;
}

bool JKQTPHorizontalRange::getFillRange() const
{
    return this->fillRange;
}

void JKQTPHorizontalRange::setPlotRangeLines(bool __value)
{
    this->plotRangeLines = __value;
}

bool JKQTPHorizontalRange::getPlotRangeLines() const
{
    return this->plotRangeLines;
}










JKQTPVerticalRange::JKQTPVerticalRange(JKQTBasePlotter* parent):
    JKQTPHorizontalRange(parent)
{
}

JKQTPVerticalRange::JKQTPVerticalRange(JKQTPlotter* parent):
    JKQTPHorizontalRange(parent)
{
}

void JKQTPVerticalRange::draw(JKQTPEnhancedPainter& painter) {
#ifdef JKQTBP_AUTOTIMER
    JKQTPAutoOutputTimer jkaaot("JKQTPVerticalRange::draw");
#endif
    double c=transformX(rangeCenter);
    double cmi=transformX(rangeMin);
    double cma=transformX(rangeMax);
    double mi=transformY(parent->getYAxis()->getMin());
    double ma=transformY(parent->getYAxis()->getMax());
    double smi=transformX(parent->getXAxis()->getMin());
    double sma=transformX(parent->getXAxis()->getMax());
    if (!unlimitedSizeMin) mi=transformY(sizeMin);
    if (!unlimitedSizeMax) ma=transformY(sizeMax);
    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    if (plotRange && (cmi!=cma) && JKQTPIsOKFloat(mi) && JKQTPIsOKFloat(ma)) {
        QPen p=getLinePen(painter, parent);
        QPen np(Qt::NoPen);
        QBrush nb(Qt::NoBrush);
        QBrush b=getFillBrush(painter, parent);
        QRectF rect(QPointF(cmi, mi), QPointF(cma, ma));
        if (fillRange) {
            painter.setPen(np);
            painter.setBrush(b);
            if (invertedRange) {
                if (JKQTPIsOKFloat(cmi)) {
                    QRectF rectl(QPointF(smi,mi), QPointF(cmi,ma));
                    painter.drawRect(rectl);
                }
                if (JKQTPIsOKFloat(cma)) {
                    QRectF rectr(QPointF(cma,mi), QPointF(sma,ma));
                    painter.drawRect(rectr);
                }
            } else {
                if (JKQTPIsOKFloat(cmi) && JKQTPIsOKFloat(cma)) painter.drawRect(rect);
            }
        }
        if (plotRangeLines && JKQTPIsOKFloat(cmi) && JKQTPIsOKFloat(cma)) {
            painter.setPen(p);
            painter.setBrush(nb);
            painter.drawLine(rect.left(), rect.top(), rect.left(), rect.bottom());
            painter.drawLine(rect.right(), rect.top(), rect.right(), rect.bottom());
        }

    }
    if (plotCenterLine&& JKQTPIsOKFloat(c) && JKQTPIsOKFloat(ma) && JKQTPIsOKFloat(mi)) {
        QPen p=painter.pen();
        p.setColor(centerColor);
        p.setStyle(centerStyle);
        p.setWidthF(qMax(JKQTPlotterDrawingTools::ABS_MIN_LINEWIDTH, parent->pt2px(painter, centerLineWidth*parent->getLineWidthMultiplier())));
        painter.setPen(p);
        painter.drawLine(QLineF(c, mi, c, ma));
    }

}

void JKQTPVerticalRange::drawKeyMarker(JKQTPEnhancedPainter& painter, QRectF& rect) {
    painter.save(); auto __finalpaint=JKQTPFinally([&painter]() {painter.restore();});
    QPen p=getLinePen(painter, parent);
    QPen np(Qt::NoPen);
    QBrush nb(Qt::NoBrush);
    QBrush b=getFillBrush(painter, parent);
    //int y=rect.top()+rect.height()/2.0;
    if (plotRange) {
        painter.setPen(np);
        painter.setBrush(b);
        if (fillRange) painter.drawRect(rect);
        painter.setPen(p);
        painter.setBrush(nb);
        if (plotRangeLines) {
            painter.drawLine(rect.left(), rect.top(), rect.left(), rect.bottom());
            painter.drawLine(rect.right(), rect.top(), rect.right(), rect.bottom());
        }
    }
    if (plotCenterLine) {
        QPen p=painter.pen();
        p.setColor(centerColor);
        p.setStyle(centerStyle);
        painter.setPen(p);
        int y=rect.left()+rect.width()/2.0;
        painter.drawLine(y, rect.top(), y, rect.bottom());
    }

}

bool JKQTPVerticalRange::getXMinMax(double &minx, double &maxx, double &smallestGreaterZero)
{
    minx=rangeMin;
    maxx=rangeMax;
    smallestGreaterZero=0;
    if (rangeMin>0) smallestGreaterZero=rangeMin;
    return true;
}

bool JKQTPVerticalRange::getYMinMax(double &miny, double &maxy, double &smallestGreaterZero)
{
    smallestGreaterZero=miny=maxy=0;
    return false;
}



