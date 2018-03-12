     H AlwNull(*UsrCtl)
       dcl-ds oDS qualified;
         outputA char(7);
         outputB char(1);
       end-ds;
       dcl-pr Main extpgm;
         inputOne packed(8:0);
         outArray packed(8:0) dim(100);
         bothArray packed(8:0) dim(100);
         outDS likeds(oDS) dim(100);
         outCount int(10);
         last char(8);
       end-pr;
       dcl-pi Main;
         inputOne packed(8:0);
         outArray packed(8:0) dim(100);
         bothArray packed(8:0) dim(100);
         outDS likeds(oDS) dim(100);
         outCount int(10);
         last char(8);
       end-pi;
       last = 'last';
       outCount = 1;
       return;

