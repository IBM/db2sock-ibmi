     H AlwNull(*UsrCtl)

       dcl-ds innerDS qualified;
          field1 char(10);
          field2 char(15);
          field3 char(25);
          field4 char(5);
       end-ds;

       dcl-ds outDS qualified;
          out1 int(10);
          out2 varchar(5:2);
          outTable likeds(innerDS) dim(30);
          out3 varchar(10:2);
       end-ds;

       dcl-pr Main extpgm;
         val int(10);
         outCount int(10);
         output likeds(outDS) dim(200);
         last char(10);
       end-pr;

       dcl-pi Main;
         val int(10);
         outCount int(10);
         output likeds(outDS) dim(200);
         last char(10);
       end-pi;

         dcl-s i int(10);
         dcl-s parms int(10);
         val = %parms();
         for i = 1 to %elem(output);
            output(i).out1 = val*val;
            output(i).outTable(1).field2 = 'a' + %char(i);
            output(i).outTable(2).field1 = 'b' + %char(i);
            output(i).outTable(3).field1 = 'c' + %char(i);
            output(i).outTable(4).field2 = 'd' + %char(i);
            output(i).outTable(5).field2 = 'e' + %char(i);
         endfor;
         last = 'TEST';
         outCount = i - 1;
       return;

