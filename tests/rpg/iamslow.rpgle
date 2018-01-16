     H AlwNull(*UsrCtl)

       // ****************************************************          
       // prototypes
       // ****************************************************          
       dcl-pr Main extpgm;
         hello char(128);
       end-pr;

       dcl-pr sleep  extproc('sleep');
         nSecs int(10) Value;
       end-pr;

       // ****************************************************          
       // main(): Control flow
       // ****************************************************          
       dcl-pi Main;
         hello char(128);
       end-pi;
         sleep(5);
         hello = 'Hello Slow';
       return;

