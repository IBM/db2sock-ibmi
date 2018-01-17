     H AlwNull(*UsrCtl)

       dcl-pr Main extpgm;
         outone char(64000);
       end-pr;

       dcl-pi Main;
         outone char(64000);
       end-pi;
       outone = '{"title":"Hello World","content":"<span ' +                     
                'class="subheading">Subhead</span>","footer":' +                       
                '{"links":["www.google.com","www.mysite.co"],"height":50}}';
       return;  

