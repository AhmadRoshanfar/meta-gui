#include "calcdac.h"
#include <QPointF>
#include <QtMath>
#include "../Helpers/qmlintegrator.h"
#include "../Helpers/constants.h"
#include "../Calculations/chartscalculations.h"
#define _qmlIntegrator QmlIntegrator::instance()
CalcDAC::CalcDAC(QObject *parent) : QObject(parent)
{

}

std::tuple<QVector<double>, QVector<double>, QVector<double>,QVector<double>, QVector<double>, QVector<double>> CalcDAC::computeCurvePoints(QVector<QPointF> &dacPoints){
    if(dacPoints.count()<2)
        return {QVector<double>(),QVector<double>(),QVector<double>(),QVector<double>(),QVector<double>(),QVector<double>()};
    sort(dacPoints);
    auto [alpha,beta] = calcAlphaBeta(dacPoints);
    QVector<double> klist100, klist50, klist20, vlist100, vlist50, vlist20;
            double step = ChartsCalculations::lengthEplison();
    for(double i = dacPoints.first().x();i<dacPoints.last().x();i+=step){
        QPointF point;
        point.setX(i);
        point.setY(beta * qExp(-alpha * i));
        klist100.append(point.x());
        vlist100.append(point.y());
        klist50.append(point.x());
        vlist50.append(point.y()/2);
        klist20.append(point.x());
        vlist20.append(point.y()/5);
    }
    return {klist100,klist50,klist20, vlist100,vlist50,vlist20};
}

double CalcDAC::calcSingleAlpha(QPointF p1, QPointF p2){
    return qLn(p2.y()/p1.y())/(p1.x()-p2.x());
}

std::tuple<double, double>  CalcDAC::calcAlphaBeta(const QVector<QPointF> &dacPoints){
    if(dacPoints.count()==0)
        return {0,0};
    auto first = dacPoints.at(0);
    double max = 0;
    for(auto& point:dacPoints){
        double alpha = calcSingleAlpha(first,point);
        max = qMax(max,alpha);
    }
    double beta = first.y()/(qExp(-max*first.x()));
    return {max,beta};
}

void CalcDAC::sort(QVector<QPointF> &dacPoints){
    std::sort(dacPoints.begin(), dacPoints.end(),
            [](const QPointF& a, const QPointF& b)
            {
                return a.x() < b.x();
            });
}
