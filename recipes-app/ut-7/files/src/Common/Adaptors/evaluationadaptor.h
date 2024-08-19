#ifndef EVALUATIONADAPTOR_H
#define EVALUATIONADAPTOR_H

#include <QObject>
#include <QVector>
#include <QPointF>
#include "../Models/enums.h"
#include "../Calculations/calccalibration.h"
#include "../Calculations/calcdac.h"
#include "../Calculations/calcaws.h"
#include "../Calculations/calctcg.h"
#include "../Models/evalmethod.h"
#include "../Helpers/qmlintegrator.h"

class EvaluationAdaptor : public QObject
{
    Q_OBJECT


    void remove(QVector<QPointF> &points, int idx);
    void add(QVector<QPointF> &points);
//    method_t calMethod;
//    method_t awsMethod;
//    method_t tcgMethod;
//    method_t dacMethod;
//    method_t norMethod;
    CalcTCG _calcTcg;
    CalcDAC _calcDac;
    CalcAWS _calcAws;
    bool doDAC(QVector<QPointF>);
    bool doAWS();
    bool doTCG();
    QmlIntegrator& _qmlIntegrator = QmlIntegrator::instance();

    void remove(QVector<double> &points, int idx);
public:
    explicit EvaluationAdaptor(QObject *parent = nullptr);
    EvaluationAdaptor(const QmlIntegrator&) = delete;
    EvaluationAdaptor & operator= (const QmlIntegrator &) = delete;
    EvaluationAdaptor(QmlIntegrator &&) = delete;
    EvaluationAdaptor & operator= (EvaluationAdaptor &&) = delete;
    static EvaluationAdaptor& instance(){
        static EvaluationAdaptor test;
        return test;
    }
    QMap<Enums::EvaluationMode,EvalMethod> _map;
    QVector<double> _DACGains;
//    static void declareQML();
signals:

private slots:
    void deactivate();
    void renewDac();
    void DACRefreshPoints();
public slots:
    void getPosition();
    void deleteList();
    void activate();
    void refreshPoints();

    void removePoint();

};

#endif // EVALUATIONADAPTOR_H
