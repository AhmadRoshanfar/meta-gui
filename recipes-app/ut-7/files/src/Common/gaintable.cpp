#include "gaintable.h"

const double* GainTable::_gainTable = initTable();

GainTable::GainTable()
{

}

double* GainTable::initTable(){
    double* table = new double[256];
    table[0] = 0;
    table[1] = 0.22;
    table[2] = 0.45;
    table[3] = 0.67;
    table[4] = 0.89;
    table[5] = 1.12;
    table[6] = 1.34;
    table[7] = 1.56;
    table[8] = 1.78;
    table[9] = 2.01;
    table[10] = 2.23;
    table[11] = 2.45;
    table[12] = 2.68;
    table[13] = 2.9;
    table[14] = 3.12;
    table[15] = 3.35;
    table[16] = 3.57;
    table[17] = 3.79;
    table[18] = 4.01;
    table[19] = 4.24;
    table[20] = 4.46;
    table[21] = 4.68;
    table[22] = 4.91;
    table[23] = 5.13;
    table[24] = 5.35;
    table[25] = 5.58;
    table[26] = 5.81;
    table[27] = 6.05;
    table[28] = 6.29;
    table[29] = 6.52;
    table[30] = 6.76;
    table[31] = 7;
    table[32] = 7.24;
    table[33] = 7.47;
    table[34] = 7.71;
    table[35] = 7.95;
    table[36] = 8.19;
    table[37] = 8.42;
    table[38] = 8.66;
    table[39] = 8.9;
    table[40] = 9.14;
    table[41] = 9.37;
    table[42] = 9.61;
    table[43] = 9.85;
    table[44] = 10.09;
    table[45] = 10.32;
    table[46] = 10.56;
    table[47] = 10.8;
    table[48] = 11.04;
    table[49] = 11.27;
    table[50] = 11.51;
    table[51] = 11.73;
    table[52] = 11.95;
    table[53] = 12.17;
    table[54] = 12.38;
    table[55] = 12.6;
    table[56] = 12.82;
    table[57] = 13.04;
    table[58] = 13.26;
    table[59] = 13.47;
    table[60] = 13.69;
    table[61] = 13.91;
    table[62] = 14.13;
    table[63] = 14.35;
    table[64] = 14.57;
    table[65] = 14.78;
    table[66] = 15;
    table[67] = 15.22;
    table[68] = 15.44;
    table[69] = 15.66;
    table[70] = 15.87;
    table[71] = 16.09;
    table[72] = 16.31;
    table[73] = 16.53;
    table[74] = 16.75;
    table[75] = 16.99;
    table[76] = 17.23;
    table[77] = 17.48;
    table[78] = 17.72;
    table[79] = 17.96;
    table[80] = 18.2;
    table[81] = 18.45;
    table[82] = 18.69;
    table[83] = 18.93;
    table[84] = 19.18;
    table[85] = 19.42;
    table[86] = 19.66;
    table[87] = 19.91;
    table[88] = 20.15;
    table[89] = 20.39;
    table[90] = 20.64;
    table[91] = 20.88;
    table[92] = 21.12;
    table[93] = 21.36;
    table[94] = 21.61;
    table[95] = 21.85;
    table[96] = 22.09;
    table[97] = 22.34;
    table[98] = 22.58;
    table[99] = 22.79;
    table[100] = 23.01;
    table[101] = 23.22;
    table[102] = 23.44;
    table[103] = 23.65;
    table[104] = 23.87;
    table[105] = 24.08;
    table[106] = 24.3;
    table[107] = 24.51;
    table[108] = 24.73;
    table[109] = 24.94;
    table[110] = 25.16;
    table[111] = 25.37;
    table[112] = 25.59;
    table[113] = 25.8;
    table[114] = 26.02;
    table[115] = 26.23;
    table[116] = 26.45;
    table[117] = 26.66;
    table[118] = 26.88;
    table[119] = 27.09;
    table[120] = 27.31;
    table[121] = 27.52;
    table[122] = 27.74;
    table[123] = 27.95;
    table[124] = 28.17;
    table[125] = 28.41;
    table[126] = 28.66;
    table[127] = 28.91;
    table[128] = 29.15;
    table[129] = 29.4;
    table[130] = 29.65;
    table[131] = 29.9;
    table[132] = 30.14;
    table[133] = 30.39;
    table[134] = 30.64;
    table[135] = 30.88;
    table[136] = 31.13;
    table[137] = 31.38;
    table[138] = 31.63;
    table[139] = 31.87;
    table[140] = 32.12;
    table[141] = 32.37;
    table[142] = 32.61;
    table[143] = 32.86;
    table[144] = 33.11;
    table[145] = 33.36;
    table[146] = 33.6;
    table[147] = 33.85;
    table[148] = 34.1;
    table[149] = 34.3;
    table[150] = 34.51;
    table[151] = 34.72;
    table[152] = 34.92;
    table[153] = 35.13;
    table[154] = 35.34;
    table[155] = 35.54;
    table[156] = 35.75;
    table[157] = 35.95;
    table[158] = 36.16;
    table[159] = 36.37;
    table[160] = 36.57;
    table[161] = 36.78;
    table[162] = 36.99;
    table[163] = 37.19;
    table[164] = 37.4;
    table[165] = 37.61;
    table[166] = 37.81;
    table[167] = 38.02;
    table[168] = 38.22;
    table[169] = 38.43;
    table[170] = 38.64;
    table[171] = 38.84;
    table[172] = 39.05;
    table[173] = 39.26;
    table[174] = 39.46;
    table[175] = 39.69;
    table[176] = 39.92;
    table[177] = 40.15;
    table[178] = 40.38;
    table[179] = 40.6;
    table[180] = 40.83;
    table[181] = 41.06;
    table[182] = 41.29;
    table[183] = 41.52;
    table[184] = 41.75;
    table[185] = 41.97;
    table[186] = 42.2;
    table[187] = 42.43;
    table[188] = 42.66;
    table[189] = 42.89;
    table[190] = 43.12;
    table[191] = 43.35;
    table[192] = 43.57;
    table[193] = 43.8;
    table[194] = 44.03;
    table[195] = 44.26;
    table[196] = 44.49;
    table[197] = 44.72;
    table[198] = 44.94;
    table[199] = 45.17;
    table[200] = 45.32;
    table[201] = 45.47;
    table[202] = 45.62;
    table[203] = 45.77;
    table[204] = 45.92;
    table[205] = 46.07;
    table[206] = 46.22;
    table[207] = 46.37;
    table[208] = 46.52;
    table[209] = 46.67;
    table[210] = 46.82;
    table[211] = 46.97;
    table[212] = 47.12;
    table[213] = 47.27;
    table[214] = 47.42;
    table[215] = 47.57;
    table[216] = 47.72;
    table[217] = 47.87;
    table[218] = 48.02;
    table[219] = 48.17;
    table[220] = 48.32;
    table[221] = 48.47;
    table[222] = 48.62;
    table[223] = 48.77;
    table[224] = 48.92;
    table[225] = 49.07;
    table[226] = 49.22;
    table[227] = 49.37;
    table[228] = 49.57;
    table[229] = 49.78;
    table[230] = 49.98;
    table[231] = 50.18;
    table[232] = 50.39;
    table[233] = 50.59;
    table[234] = 50.8;
    table[235] = 51;
    table[236] = 51.2;
    table[237] = 51.41;
    table[238] = 51.61;
    table[239] = 51.82;
    table[240] = 52.02;
    table[241] = 52.23;
    table[242] = 52.43;
    table[243] = 52.63;
    table[244] = 52.84;
    table[245] = 53.04;
    table[246] = 53.25;
    table[247] = 53.45;
    table[248] = 53.65;
    table[249] = 53.86;
    table[250] = 54.06;
    table[251] = 54.27;
    table[252] = 54.47;
    table[253] = 54.68;
    table[254] = 54.88;
    table[255] = 55.1;
    return table;
}

uint16_t GainTable::getCode(double gaindb){
    return 4095.0*gaindb/76.5;
    int GainCode =0;

    int first = 0;
    int index = 0;

    if (gaindb > _gainTable[255])
    {
        GainCode = 255;
    }
    else
    {
        for (index= 0 ; index < 256; index++)
        {
            if ( (gaindb <= _gainTable[index]) && (first == 0) )
            {
                first = 1;
                if ( index >0)
                {
                    if ( (_gainTable[index] - gaindb) > (gaindb - _gainTable[index-1]) )
                    {
                        GainCode = index-1;
                    }
                    else
                    {
                        GainCode = index;
                    }
                }
                else
                {
                    GainCode = 0;
                }
            }
        }
    }
    return GainCode;
}
