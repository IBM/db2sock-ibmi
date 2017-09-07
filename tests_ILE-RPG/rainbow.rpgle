     H AlwNull(*UsrCtl)

       // ****************************************************          
       // prototypes
       // ****************************************************          
       dcl-pr Main extpgm;
         aint8 int(3);
         aint16 int(5);
         aint32 int(10);
         aint64 int(20);
         afloat float(4);
         adouble float(8);
         apacked packed(12:2);
         azonded zoned(12:2);
         achar char(32);
         avarchar2 varchar(32:2);
         avarchar4 varchar(32:4);
         abin bindec(3);
       end-pr;

       // ****************************************************          
       // main(): Control flow
       // ****************************************************          
       dcl-pi Main;
         aint8 int(3);
         aint16 int(5);
         aint32 int(10);
         aint64 int(20);
         afloat float(4);
         adouble float(8);
         apacked packed(12:2);
         azonded zoned(12:2);
         achar char(32);
         avarchar2 varchar(32:2);
         avarchar4 varchar(32:4);
         abin bindec(3);
       end-pi;
         aint8 = 1;
         aint16 = 2;
         aint32 = 3;
         aint64 = 4;
         afloat = 5.5;
         adouble = 6.6;
         apacked = 7.77;
         azonded = 8.88;
         achar = '999';
         avarchar2 = 'AAA';
         avarchar4 = 'BBB';
         abin = 12;
       return;

