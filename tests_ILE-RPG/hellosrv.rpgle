     H NOMAIN          
     H AlwNull(*UsrCtl)          

       // ****************************************************          
       // prototypes
       // ****************************************************          
       dcl-pr hello;
         hello char(128);
       end-pr;

       // ****************************************************          
       // hello: hello world
       // ****************************************************          
       dcl-proc hello export;
       dcl-pi  *N;
         hello char(128);
       end-pi;
         hello = 'Hello World';
       end-proc;

