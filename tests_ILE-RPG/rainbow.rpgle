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
       end-pi;
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
       return;

