     H AlwNull(*UsrCtl)

       dcl-pr Main extpgm;
         paramCount int(10);
         p1 char(5);
         p2 char(5) options(*nopass);
         p3 char(5) options(*nopass);
       end-pr;

       dcl-pi Main;
         paramCount int(10);
         p1 char(5);
         p2 char(5) options(*nopass);
         p3 char(5) options(*nopass);
       end-pi;
         paramCount = %parms();
       return;
