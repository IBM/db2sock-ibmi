     H AlwNull(*UsrCtl)

       // ****************************************************          
       // prototypes
       // ****************************************************          
       dcl-pr Main extpgm;
         aint8 int(3);
         aint16 int(5);
         aint32 int(10);
         aint64 int(20);
         auint8 uns(3);
         auint16 uns(5);
         auint32 uns(10);
         auint64 uns(20);
         afloat float(4);
         adouble float(8);
         apacked packed(12:2);
         azonded zoned(12:2);
         achar char(32);
         avarchar2 varchar(32:2);
         avarchar4 varchar(32:4);
         abin4 bindec(4);
         abin9 bindec(9);
         ahex1 bindec(1);
         ahex2 bindec(2);
         ahex3 bindec(3);
         ahex4 bindec(4);
         ahex5 bindec(5);
         ahex6 bindec(6);
         ahex7 bindec(7);
         ahex8 bindec(8);
         ahex9 bindec(9);
         abuf12 char(12);
         adateusa date(*USA);
       end-pr;

       // ****************************************************          
       // main(): Control flow
       // ****************************************************          
       dcl-pi Main;
         aint8 int(3);
         aint16 int(5);
         aint32 int(10);
         aint64 int(20);
         auint8 uns(3);
         auint16 uns(5);
         auint32 uns(10);
         auint64 uns(20);
         afloat float(4);
         adouble float(8);
         apacked packed(12:2);
         azonded zoned(12:2);
         achar char(32);
         avarchar2 varchar(32:2);
         avarchar4 varchar(32:4);
         abin4 bindec(4);
         abin9 bindec(9);
         ahex1 bindec(1);
         ahex2 bindec(2);
         ahex3 bindec(3);
         ahex4 bindec(4);
         ahex5 bindec(5);
         ahex6 bindec(6);
         ahex7 bindec(7);
         ahex8 bindec(8);
         ahex9 bindec(9);
         abuf12 char(12);
         adateusa date(*USA);
       end-pi;
         dcl-s fdateusa date(*USA) inz(d'2017-09-14');
         aint8 += 1;
         aint16 += 1;
         aint32 += 1;
         aint64 += 1;
         auint8 += 1;
         auint16 += 1;
         auint32 += 1;
         auint64 += 1;
         afloat += 1.11;
         adouble += 1.111;
         apacked += 1.11;
         azonded += 1.11;
         achar = %trim(achar) + '+1';
         avarchar2 = %trim(avarchar2) + '+1';
         avarchar4 = %trim(avarchar4) + '+1';
         abin4 += 1;
         abin9 += 1;
         ahex1 += 1;
         ahex2 += 1;
         ahex3 += 1;
         ahex4 += 1;
         ahex5 += 1;
         ahex6 += 1;
         ahex7 += 1;
         ahex8 += 1;
         ahex9 += 1;
         abuf12 = %trim(abuf12) + '42';
         if adateusa = fdateusa;
           adateusa = d'2014-01-07';
         else;
           adateusa = d'2016-01-07';
         endif;
       return;

