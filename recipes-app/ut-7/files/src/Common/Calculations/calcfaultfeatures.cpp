#include "calcfaultfeatures.h"
#include "../Helpers/constants.h"
#include <QtMath>
CalcFaultFeatures::CalcFaultFeatures(QObject *parent) : QObject(parent)
{

}


CalcFaultFeatures::FaultFeatRes CalcFaultFeatures::calc(
        double soundPathMultiplier,
        double S_mm,
        double pipeDiameter,
        Enums::Shape shape,
        Enums::ProbeType probeType,
        //    int legSamples,
        Enums::Unit unit
        )
{
    int legNo = 0;
    double probeAngle = _qmlIntegrator.probeAngle()*M_PI/180.0;
    double oneLeg_mm = 0,x,a,b,c,delta,st_div_se,pt_div_pe,radian_to_acos;
    //    double S_mm = (soundSamples / Constants::SAMPLING_RATE) * _qmlIntegrator.velocity() / 1000 * soundPathMultiplier;
    double S,D,DA,S_AWS;
    //    S_mm = (soundSamples[0] / FS[0]) * _qmlIntegrator.velocity() / 1000 * soundPathMultiplier[0];
    switch (unit)
    {
    case Enums::Unit::UNIT_US:
        S = (S_mm/_qmlIntegrator.velocity()*1000.0);
        S_AWS = qQNaN();
        break;
    case Enums::Unit::UNIT_MM:
        S = S_mm;
        S_AWS = S_mm;
        break;
    case Enums::Unit::UNIT_INCH:
        S = S_mm / Constants::INCH_TO_MM;
        S_AWS = S_mm;
        break;
    default:
        break;
    }

    switch (probeType)
    {
    case Enums::ProbeType::PT_NORMAL :
    case Enums::ProbeType::PT_TR :
        switch (unit)
        {
        case Enums::Unit::UNIT_US:
            D = qQNaN();
            break;
        case Enums::Unit::UNIT_MM:
            D = S_mm;
            break;
        case Enums::Unit::UNIT_INCH:
            D = S_mm / Constants::INCH_TO_MM;
            break;
        default:
            break;
        }
        DA = qQNaN();
        //        legSamples = 0;
        break;
    case Enums::ProbeType::PT_ANGULAR :
        if (shape == Enums::Shape::SHAPE_PLATE)
        {
            oneLeg_mm =_qmlIntegrator.thickness() / cos(probeAngle);
            legNo = (int)round(double(ceil((S_mm) / oneLeg_mm)));
            if ((legNo % 2) == 1)
            {
                D = (S_mm - oneLeg_mm*floor(S_mm / oneLeg_mm)) * cos(probeAngle);
            }
            else
            {
                D =  _qmlIntegrator.thickness() - ((S_mm - oneLeg_mm*floor(S_mm / oneLeg_mm)) * cos(probeAngle));
            }
            DA = (S_mm * sin(probeAngle)) - _qmlIntegrator.probeIndex();

        }
        else
        {
            x =_qmlIntegrator.thickness() /pipeDiameter;
            a = pow(1.0 / cos(probeAngle), 2);
            b = -1.0 / x;
            c = 1.0 / x - 1.0;
            delta = pow(b, 2) - (4.0 * a * c);

            if (delta >= 0)
            {
                st_div_se = -1.0 * (b + sqrt(delta)) / (2.0 * a);
                radian_to_acos = (0.25 + pow(0.5 - x, 2) - pow(st_div_se / cos(probeAngle) * x, 2.0)) / (0.5 - x);
                if ((radian_to_acos >= -1) && (radian_to_acos <= 1))
                    pt_div_pe = acos(radian_to_acos) / (2.0 * x * tan(probeAngle));
                else
                    pt_div_pe = qQNaN();
            }
            else
            {
                st_div_se = qQNaN();
                pt_div_pe = qQNaN();
            }


            oneLeg_mm = _qmlIntegrator.thickness() / cos(probeAngle) * st_div_se;
            legNo = (int)qRound(double(qCeil((S_mm) / oneLeg_mm)));

            if ((legNo % 2) == 1)
            {
                D = (S_mm - oneLeg_mm*floor(S_mm / oneLeg_mm)) * cos(probeAngle) / st_div_se;
            }
            else
            {
                D = _qmlIntegrator.thickness() - ((S_mm - oneLeg_mm*floor(S_mm / oneLeg_mm)) * cos(probeAngle) / st_div_se);
            }
            DA = (S_mm * sin(probeAngle) / st_div_se * pt_div_pe) - _qmlIntegrator.probeIndex();
        }
        //        legSamples =(int) qRound((oneLeg_mm * Constants::SAMPLING_RATE) / ( _qmlIntegrator.velocity() /  1000.0 * soundPathMultiplier)) ;

        switch (unit)
        {
        case Enums::Unit::UNIT_US:
            D = qQNaN();
            DA = qQNaN();
            break;
        case Enums::Unit::UNIT_MM:
            //            D = D;
            //            DA = DA;
            break;
        case Enums::Unit::UNIT_INCH:
            D = D / Constants::INCH_TO_MM;
            DA = DA / Constants::INCH_TO_MM;
            break;
        default:
            break;
        }


        break;
    case Enums::ProbeType::PT_TRANSMISSION:
        S = qQNaN();
        D = qQNaN();
        DA = qQNaN();
        //        legSamples = 0;
        break;
    default :
        S = qQNaN();
        D = qQNaN();
        DA = qQNaN();
        //        legSamples = 0;
        break;
    }
    FaultFeatRes ret;
    ret.D = D;
    ret.S = S;
    ret.Da = DA;
    ret.leg = oneLeg_mm;
    return ret;
}
