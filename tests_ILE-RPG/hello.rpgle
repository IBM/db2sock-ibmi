     H AlwNull(*UsrCtl)

       // ****************************************************          
       // prototypes
       // ****************************************************          
       dcl-pr Main extpgm;
         hello char(128);
       end-pr;

       // ****************************************************          
       // main(): Control flow
       // ****************************************************          
       dcl-pi Main;
         hello char(128);
       end-pi;
         hello = 'Hello World';
       return;

