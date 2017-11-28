     H AlwNull(*UsrCtl)

       dcl-ds inputDS qualified;
            in1 varchar(5:2);
            in2 varchar(5:2);
       end-ds;

       dcl-ds outDS qualified;
            out1 varchar(5:2);
            out2 varchar(5:2);
            out3 varchar(10:2);
       end-ds;

       dcl-pr Main extpgm;
         inCount int(10);
         input likeds(inputDS) dim(20);
         outCount int(10);
         output likeds(outDS) dim(20);
         last char(10);
       end-pr;

       dcl-pi Main;
         inCount int(10);
         input likeds(inputDS) dim(20);
         outCount int(10);
         output likeds(outDS) dim(20);
         last char(10);
       end-pi;

         dcl-s i int(10);
         for i = 1 to inCount;
            output(i).out1 = input(i).in1;
            output(i).out2 = input(i).in2;
            output(i).out3 = input(i).in1 + input(i).in2;
         endfor;
         last = 'TEST';
         outCount = i - 1;
       return;

