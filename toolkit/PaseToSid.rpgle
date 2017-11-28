     H NOMAIN
     H AlwNull(*UsrCtl)
     H BNDDIR('QC2LE')

       // ****************************************************          
       //  includes          
       // ****************************************************          
      /copy PaseType_h          

       // ----------------------
       // USC2 convert job ccsid          
       // |  !  ¬  \  `  #  ~  [  ]  ^  {  }  ¢  $  @
       // 4f 5a 5f e0 79 7b a1 ba bb b0 c0 d0 4a 5b 7c
       // ----------------------
       dcl-s s_ccsid_bar char(1) inz(*BLANKS);
       dcl-s s_ccsid_bang char(1) inz(*BLANKS);
       dcl-s s_ccsid_not char(1) inz(*BLANKS);
       dcl-s s_ccsid_backslash char(1) inz(*BLANKS);
       dcl-s s_ccsid_backtick char(1) inz(*BLANKS);
       dcl-s s_ccsid_pound char(1) inz(*BLANKS);
       dcl-s s_ccsid_tilde char(1) inz(*BLANKS);
       dcl-s s_ccsid_open_brace char(1) inz(*BLANKS);
       dcl-s s_ccsid_close_brace char(1) inz(*BLANKS);
       dcl-s s_ccsid_caret char(1) inz(*BLANKS);
       dcl-s s_ccsid_open_bracket char(1) inz(*BLANKS);
       dcl-s s_ccsid_close_bracket char(1) inz(*BLANKS);
       dcl-s s_ccsid_cent char(1) inz(*BLANKS);
       dcl-s s_ccsid_dollar char(1) inz(*BLANKS);
       dcl-s s_ccsid_at char(1) inz(*BLANKS);

       // ----------------------
       // prototype
       // ----------------------
       dcl-pr ccsid_bar char(1) extproc('ccsid_bar');
       end-pr;
       dcl-pr ccsid_bang char(1) extproc('ccsid_bang');
       end-pr;
       dcl-pr ccsid_not char(1) extproc('ccsid_not');
       end-pr;
       dcl-pr ccsid_backslash char(1) extproc('ccsid_backslash');
       end-pr;
       dcl-pr ccsid_backtick char(1) extproc('ccsid_backtick');
       end-pr;
       dcl-pr ccsid_pound char(1) extproc('ccsid_pound');
       end-pr;
       dcl-pr ccsid_tilde char(1) extproc('ccsid_tilde');
       end-pr;
       dcl-pr ccsid_open_brace char(1) extproc('ccsid_open_brace');
       end-pr;
       dcl-pr ccsid_close_brace char(1) extproc('ccsid_close_brace');
       end-pr;
       dcl-pr ccsid_caret char(1) extproc('ccsid_caret');
       end-pr;
       dcl-pr ccsid_open_bracket char(1) extproc('ccsid_open_bracket');
       end-pr;
       dcl-pr ccsid_close_bracket char(1) extproc('ccsid_close_bracket');
       end-pr;
       dcl-pr ccsid_cent char(1) extproc('ccsid_cent');
       end-pr;
       dcl-pr ccsid_dollar char(1) extproc('ccsid_dollar');
       end-pr;
       dcl-pr ccsid_at char(1) extproc('ccsid_at');
       end-pr;

       // ----------------------
       // functions
       // ----------------------
       dcl-proc ccsid_bar export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_bar = *BLANKS;          
         s_ccsid_bar = %char(%UCS2(x'4f'));          
       endif;          
       return s_ccsid_bar;          
       end-proc;

       dcl-proc ccsid_bang export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_bang = *BLANKS;          
         s_ccsid_bang = %char(%UCS2(x'5a'));          
       endif;          
       return s_ccsid_bang;          
       end-proc;

       dcl-proc ccsid_not export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_not = *BLANKS;          
         s_ccsid_not = %char(%UCS2(x'5f'));          
       endif;          
       return s_ccsid_not;          
       end-proc;

       dcl-proc ccsid_backslash export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_backslash = *BLANKS;          
         s_ccsid_backslash = %char(%UCS2(x'e0'));          
       endif;          
       return s_ccsid_backslash;          
       end-proc;

       dcl-proc ccsid_backtick export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_backtick = *BLANKS;          
         s_ccsid_backtick = %char(%UCS2(x'79'));          
       endif;          
       return s_ccsid_backtick;          
       end-proc;

       dcl-proc ccsid_pound export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_pound = *BLANKS;          
         s_ccsid_pound = %char(%UCS2(x'7b'));          
       endif;          
       return s_ccsid_pound;          
       end-proc;

       dcl-proc ccsid_tilde export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_tilde = *BLANKS;          
         s_ccsid_tilde = %char(%UCS2(x'a1'));          
       endif;          
       return s_ccsid_tilde;          
       end-proc;

       dcl-proc ccsid_open_brace export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_open_brace = *BLANKS;          
         s_ccsid_open_brace = %char(%UCS2(x'ba'));          
       endif;          
       return s_ccsid_open_brace;          
       end-proc;

       dcl-proc ccsid_close_brace export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_close_brace = *BLANKS;          
         s_ccsid_close_brace = %char(%UCS2(x'bb'));          
       endif;          
       return s_ccsid_close_brace;          
       end-proc;

       dcl-proc ccsid_caret export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_caret = *BLANKS;          
         s_ccsid_caret = %char(%UCS2(x'b0'));          
       endif;          
       return s_ccsid_caret;          
       end-proc;

       dcl-proc ccsid_open_bracket export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_open_bracket = *BLANKS;          
         s_ccsid_open_bracket = %char(%UCS2(x'c0'));          
       endif;          
       return s_ccsid_open_bracket;          
       end-proc;

       dcl-proc ccsid_close_bracket export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_close_bracket = *BLANKS;          
         s_ccsid_close_bracket = %char(%UCS2(x'd0'));          
       endif;          
       return s_ccsid_close_bracket;          
       end-proc;

       dcl-proc ccsid_cent export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_cent = *BLANKS;          
         s_ccsid_cent = %char(%UCS2(x'4a'));          
       endif;          
       return s_ccsid_cent;          
       end-proc;

       dcl-proc ccsid_dollar export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_dollar = *BLANKS;          
         s_ccsid_dollar = %char(%UCS2(x'5b'));          
       endif;          
       return s_ccsid_dollar;          
       end-proc;

       dcl-proc ccsid_at export;
       dcl-pi *N char(1);
       end-pi;
       if s_ccsid_at = *BLANKS;          
         s_ccsid_at = %char(%UCS2(x'7c'));          
       endif;          
       return s_ccsid_at;          
       end-proc;

