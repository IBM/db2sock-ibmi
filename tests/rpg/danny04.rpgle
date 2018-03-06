     H AlwNull(*UsrCtl)

       dcl-ds inputDS qualified;
         in1 char(100);
         in2 char(100);
       end-ds;

       dcl-ds oDS qualified;
         o1 char(500);
         o2 char(500);
       end-ds;

       dcl-pr Main extpgm;
         inCount int(10);
         input likeds(inputDS) dim(20);
         outCount int(10);
         outputA likeds(oDS) dim(15000);
         last char(20);
       end-pr;

       dcl-pi Main;
         inCount int(10);
         input likeds(inputDS) dim(20);
         outCount int(10);
         outputA likeds(oDS) dim(15000);
         last char(20);
       end-pi;

       dcl-s i int(10);
       outCount = inCount;
       for i = 1 to inCount;
         outputA(i).o1 = 'silly frog doodle 01'
                       + ' silly frog doodle 02'
                       + ' silly frog doodle 03'
                       + ' silly frog doodle 04'
                       + ' silly frog doodle 05'
                       + ' silly frog doodle 06'
                       + ' silly frog doodle 07'
                       + ' silly frog doodle 08'
                       + ' silly frog doodle 09'
                       + ' silly frog doodle 10'
                       + ' silly frog doodle 11'
                       + ' silly frog doodle 12'
                       + ' silly frog doodle 13'
                       + ' silly frog doodle 14'
                       + ' silly frog doodle 15'
                       + ' silly frog doodle 16'
                       + ' silly frog doodle 17'
                       + ' silly frog doodle 18'
                       + ' silly frog doodle 19'
                       + ' silly frog doodle 20';
         outputA(i).o2 = 'value';
       endfor;
       last = '"quoted" text';
       outCount = i - 1;
       return;

