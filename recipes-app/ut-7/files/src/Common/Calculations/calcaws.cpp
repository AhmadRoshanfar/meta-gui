#include "calcaws.h"
#include "../Helpers/constants.h"
#include <QtMath>
#include "../Helpers/qmlintegrator.h"
#include <QDebug>

double CalcAWS::yRef, CalcAWS::gainRef;


CalcAWS::CalcAWS(QObject *parent) : QObject(parent)
{
    aws_table[0][0][0] = 5;
    aws_table[0][0][1] = 6;
    aws_table[0][0][2] = 7;
    aws_table[0][0][3] = 8;
    aws_table[0][1][0] = 2;
    aws_table[0][1][1] = 3;
    aws_table[0][1][2] = 4;
    aws_table[0][1][3] = 5;
    aws_table[0][2][0] = -2;
    aws_table[0][2][1] = 0;
    aws_table[0][2][2] = 2;
    aws_table[0][2][3] = 3;
    aws_table[0][3][0] = 1;
    aws_table[0][3][1] = 3;
    aws_table[0][3][2] = 5;
    aws_table[0][3][3] = 6;
    aws_table[0][4][0] = 3;
    aws_table[0][4][1] = 5;
    aws_table[0][4][2] = 7;
    aws_table[0][4][3] = 8;
    aws_table[0][5][0] = -5;
    aws_table[0][5][1] = -3;
    aws_table[0][5][2] = 2;
    aws_table[0][5][3] = 3;
    aws_table[0][6][0] = -2;
    aws_table[0][6][1] = 0;
    aws_table[0][6][2] = 2;
    aws_table[0][6][3] = 3;
    aws_table[0][7][0] = 0;
    aws_table[0][7][1] = 2;
    aws_table[0][7][2] = 4;
    aws_table[0][7][3] = 5;
    aws_table[0][8][0] = -7;
    aws_table[0][8][1] = -5;
    aws_table[0][8][2] = 2;
    aws_table[0][8][3] = 3;
    aws_table[0][9][0] = -4;
    aws_table[0][9][1] = -2;
    aws_table[0][9][2] = 2;
    aws_table[0][9][3] = 3;
    aws_table[0][10][0] = -1;
    aws_table[0][10][1] = 1;
    aws_table[0][10][2] = 3;
    aws_table[0][10][3] = 4;
    aws_table[1][0][0] = 10;
    aws_table[1][0][1] = 11;
    aws_table[1][0][2] = 12;
    aws_table[1][0][3] = 13;
    aws_table[1][1][0] = 8;
    aws_table[1][1][1] = 9;
    aws_table[1][1][2] = 10;
    aws_table[1][1][3] = 11;
    aws_table[1][2][0] = 4;
    aws_table[1][2][1] = 6;
    aws_table[1][2][2] = 8;
    aws_table[1][2][3] = 9;
    aws_table[1][3][0] = 7;
    aws_table[1][3][1] = 9;
    aws_table[1][3][2] = 11;
    aws_table[1][3][3] = 12;
    aws_table[1][4][0] = 9;
    aws_table[1][4][1] = 11;
    aws_table[1][4][2] = 13;
    aws_table[1][4][3] = 14;
    aws_table[1][5][0] = 1;
    aws_table[1][5][1] = 3;
    aws_table[1][5][2] = 5;
    aws_table[1][5][3] = 6;
    aws_table[1][6][0] = 4;
    aws_table[1][6][1] = 6;
    aws_table[1][6][2] = 8;
    aws_table[1][6][3] = 9;
    aws_table[1][7][0] = 6;
    aws_table[1][7][1] = 8;
    aws_table[1][7][2] = 10;
    aws_table[1][7][3] = 11;
    aws_table[1][8][0] = -2;
    aws_table[1][8][1] = 0;
    aws_table[1][8][2] = 2;
    aws_table[1][8][3] = 3;
    aws_table[1][9][0] = 1;
    aws_table[1][9][1] = 3;
    aws_table[1][9][2] = 5;
    aws_table[1][9][3] = 6;
    aws_table[1][10][0] = 3;
    aws_table[1][10][1] = 5;
    aws_table[1][10][2] = 7;
    aws_table[1][10][3] = 8;

    aws_lim[0][0] = 8;
    aws_lim[0][1] = 20;
    aws_lim[0][2] = 70;
    aws_lim[1][0] = 20;
    aws_lim[1][1] = 38;
    aws_lim[1][2] = 70;
    aws_lim[2][0] = 38;
    aws_lim[2][1] = 65;
    aws_lim[2][2] = 70;
    aws_lim[3][0] = 38;
    aws_lim[3][1] = 65;
    aws_lim[3][2] = 60;
    aws_lim[4][0] = 38;
    aws_lim[4][1] = 65;
    aws_lim[4][2] = 45;
    aws_lim[5][0] = 65;
    aws_lim[5][1] = 100;
    aws_lim[5][2] = 70;
    aws_lim[6][0] = 65;
    aws_lim[6][1] = 100;
    aws_lim[6][2] = 60;
    aws_lim[7][0] = 65;
    aws_lim[7][1] = 100;
    aws_lim[7][2] = 45;
    aws_lim[8][0] = 100;
    aws_lim[8][1] = 200;
    aws_lim[8][2] = 70;
    aws_lim[9][0] = 100;
    aws_lim[9][1] = 200;
    aws_lim[9][2] = 60;
    aws_lim[10][0] = 100;
    aws_lim[10][1] = 200;
    aws_lim[10][2] = 45;
}

Enums::AWSClass CalcAWS::findClass(double d, double angle,int table_no,double thickness){
    int i,j;
    Enums::AWSClass AwsClass = Enums::AWSClass::AWSC_NONE;
    int loop_iteration = 0;
//    angle = angle/3.1416*180;
    if (table_no == 0)
        i = 0;
    else
        i=1;
    j = -1;
    for (loop_iteration = 0; loop_iteration < 11 ; loop_iteration++)
    {
        if ( ((thickness+0.5)>= aws_lim[loop_iteration][0]) && ((thickness+0.5)<=aws_lim[loop_iteration][1]))
        {
            if ( ((angle-aws_lim[loop_iteration][2]) <= 2) && ((angle-aws_lim[loop_iteration][2]) >= -2) )
                j= loop_iteration;
        }
    }
    if (j>=0)
    {
        if((d+0.5) <= (aws_table[i][j][0]+1))
            AwsClass = Enums::AWSClass::AWSC_A;
        else
        {
            for (loop_iteration = 2 ; loop_iteration > 0 ; loop_iteration--)
            {
                if((d+0.5) <= (aws_table[i][j][loop_iteration]+1)){
                    if(loop_iteration == 1)
                        AwsClass = Enums::AWSClass::AWSC_B;
                    else if(loop_iteration == 2)
                        AwsClass = Enums::AWSClass::AWSC_C;
                }
            }
            if ((d+0.5) > (aws_table[i][j][3]))
                AwsClass = Enums::AWSClass::AWSC_D;
        }
    }
    return AwsClass;
}

std::tuple<double,double,double> CalcAWS::calc(double y,double gain, double s_mm){
    //TODO: add inch calcuations
    double a= 20*log10(qAbs(CalcAWS::yRef/y)) + gain;
    double c = (2/Constants::INCH_TO_MM)*(s_mm-Constants::INCH_TO_MM);
    return {a,c,qRound(a- CalcAWS::gainRef-c)};

}


