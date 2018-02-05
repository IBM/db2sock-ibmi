     H AlwNull(*UsrCtl)

       dcl-pr Main extpgm;
         aint8 int(3);
         aint16 int(5);
         aint32 int(10);
         aint64 int(20);
         afloat float(4);
         adouble float(8);
         apacked packed(12:2);
         azonded zoned(12:2);
       end-pr;

       dcl-pi Main;
         aint8 int(3);
         aint16 int(5);
         aint32 int(10);
         aint64 int(20);
         afloat float(4);
         adouble float(8);
         apacked packed(12:2);
         azonded zoned(12:2);
       end-pi;
         aint8 -= 10;
         aint16 -= 10;
         aint32 -= 10;
         aint64 -= 10;
         afloat -= 10.11;
         adouble -= 10.111;
         apacked -= 10.11;
         azonded -= 10.11;
       return;

