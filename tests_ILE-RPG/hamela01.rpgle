     H AlwNull(*UsrCtl)

       dcl-ds itemDS qualified;
            field1 char(5);
            field2 char(5);
            field3 char(5);
            field4 char(5);
       end-ds;

       dcl-pr Main extpgm;
         rows zoned(5:0);
         items likeds(itemDS) dim(20);
         last char(10);
       end-pr;

       dcl-pi Main;
         rows zoned(5:0);
         items likeds(itemDS) dim(20);
         last char(10);
       end-pi;

         dcl-s i int(10);
         for i = 1 to rows;
           items(i).field1 = 'a' + %char(i);
           items(i).field2 = 'b' + %char(i);
           items(i).field3 = 'c' + %char(i);
           items(i).field4 = 'd' + %char(i);
         endfor;
         last = 'TEST';

       return;


