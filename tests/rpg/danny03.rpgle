     H AlwNull(*UsrCtl)

       dcl-pr Main extpgm;
         outone char(64000);
         flag int(10);
       end-pr;

       dcl-pi Main;
         outone char(64000);
         flag int(10);
       end-pi;
       // partial escaped json ... argh (subheading)
       if flag = 1;
         outone = '{"title":"Hello World","content":"<span ' +                     
                'class=\"subheading\">Subhead</span>","footer":' +                       
                '{"links":["www.google.com","www.mysite.co"],"height":50}}';
       // not escaped json (yes)
       else;
         outone = '{"title":"Hello World","content":"<span ' +                     
                'class="subheading">Subhead</span>","footer":' +                       
                '{"links":["www.google.com","www.mysite.co"],"height":50}}';
       endif;
       return;  

