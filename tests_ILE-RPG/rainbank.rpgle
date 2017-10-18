     H AlwNull(*UsrCtl)

       dcl-ds money qualified;
          my varchar(20:2);
          lot packed(5:2);
          sof packed(18:2);
          dough packed(31:2);
       end-ds;

       dcl-ds bio qualified;
          mr varchar(10:2);
          first varchar(15:2);
          last varchar(25:2);
          bank likeds(money) dim(2);
       end-ds;

       dcl-pr Main extpgm;
         maxCount int(10);
         outCount int(10);
         output likeds(bio) dim(10);
       end-pr;

       dcl-pi Main;
         maxCount int(10);
         outCount int(10);
         output likeds(bio) dim(10);
       end-pi;
         dcl-s i int(10) inz(0);
         dcl-s j int(10) inz(0);
         dcl-s doCount int(10) inz(0);
         if maxCount > 10;
           doCount = 10;
         elseif maxCount < 1;
           doCount = 1;
         else;
           doCount = maxCount;
         endif;
         for i = 1 to doCount;
           output(i).mr = 'mr' + %char(i);
           output(i).first = 'you' + %char(i);
           output(i).last = 'too' + %char(i);
           for j = 1 to 2;
             output(i).bank(j).my = 'bank' + %char(i+j);
             output(i).bank(j).lot = i * 10 + j;
             output(i).bank(j).sof = i * 10000 + j;
             output(i).bank(j).dough = i * 100000 + j;
           endfor;
         endfor;
         outCount = i - 1;
       return;

