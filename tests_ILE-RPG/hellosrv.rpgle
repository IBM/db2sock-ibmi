     H NOMAIN          
     H AlwNull(*UsrCtl)          

       // ****************************************************          
       // prototypes
       // ****************************************************          
       dcl-pr hello;
         hello char(128);
       end-pr;

       dcl-pr helloAgain char(128);
         hello char(128);
       end-pr;

       dcl-ds hello_ds_t qualified based(Template);
         hello char(128);
       end-ds;
       dcl-pr helloDS likeds(hello_ds_t);
         hello likeds(hello_ds_t);
       end-pr;

       // ****************************************************          
       // hello
       // ****************************************************          
       dcl-proc hello export;
       dcl-pi  *N;
         hello char(128);
       end-pi;
         hello = 'Hello World';
       end-proc;


       // ****************************************************          
       // helloAgain
       // ****************************************************          
       dcl-proc helloAgain export;
       dcl-pi  *N char(128);
         hello char(128);
       end-pi;
         hello = 'Hello World';
         return 'Hello World Again';
       end-proc;

       // ****************************************************          
       // helloDS
       // ****************************************************          
       dcl-proc helloDS export;
       dcl-pi  *N likeds(hello_ds_t);
         hello likeds(hello_ds_t);
       end-pi;
         dcl-ds helloDS likeds(hello_ds_t);
         hello.hello = 'Hello World';
         helloDS.hello = 'Hello World Again';
         return helloDS;
       end-proc;


