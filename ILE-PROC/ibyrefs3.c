#include <miptrnam.h>
#include <miptrnam.h>
#include <mih/rslvsp.h>
#include <mih/miobjtyp.h>
#include <leawi.h>
#include <qleawi.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <qtqiconv.h>
#include <qp2user.h>
#include <except.h>
#include "../toolkit-base/PaseTool.h"
#include "iconf.h" /* see Makefile */
#include "ibyref.h"

typedef bighole_t (os_fct_64_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64
);

typedef bighole_t (os_fct_65_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65
);

typedef bighole_t (os_fct_66_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66
);

typedef bighole_t (os_fct_67_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67
);

typedef bighole_t (os_fct_68_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68
);

typedef bighole_t (os_fct_69_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69
);

typedef bighole_t (os_fct_70_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70
);

typedef bighole_t (os_fct_71_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71
);

typedef bighole_t (os_fct_72_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72
);

typedef bighole_t (os_fct_73_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73
);

typedef bighole_t (os_fct_74_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74
);

typedef bighole_t (os_fct_75_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75
);

typedef bighole_t (os_fct_76_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76
);

typedef bighole_t (os_fct_77_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77
);

typedef bighole_t (os_fct_78_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78
);

typedef bighole_t (os_fct_79_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79
);

typedef bighole_t (os_fct_80_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80
);

typedef bighole_t (os_fct_81_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81
);

typedef bighole_t (os_fct_82_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82
);

typedef bighole_t (os_fct_83_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83
);

typedef bighole_t (os_fct_84_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84
);

typedef bighole_t (os_fct_85_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85
);

typedef bighole_t (os_fct_86_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86
);

typedef bighole_t (os_fct_87_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87
);

typedef bighole_t (os_fct_88_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88
);

typedef bighole_t (os_fct_89_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88, char * p89
);

typedef bighole_t (os_fct_90_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88, char * p89, char * p90
);

typedef bighole_t (os_fct_91_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88, char * p89, char * p90, char * p91
);

typedef bighole_t (os_fct_92_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88, char * p89, char * p90, char * p91, 
char * p92
);

typedef bighole_t (os_fct_93_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88, char * p89, char * p90, char * p91, 
char * p92, char * p93
);

typedef bighole_t (os_fct_94_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88, char * p89, char * p90, char * p91, 
char * p92, char * p93, char * p94
);

typedef bighole_t (os_fct_95_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63, 
char * p64, char * p65, char * p66, char * p67, char * p68, char * p69, char * p70, 
char * p71, char * p72, char * p73, char * p74, char * p75, char * p76, char * p77, 
char * p78, char * p79, char * p80, char * p81, char * p82, char * p83, char * p84, 
char * p85, char * p86, char * p87, char * p88, char * p89, char * p90, char * p91, 
char * p92, char * p93, char * p94, char * p95
);

bighole_t iCallFctByRef64(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_64_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63]
    );
}

bighole_t iCallFctByRef65(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_65_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64]
    );
}

bighole_t iCallFctByRef66(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_66_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65]
    );
}

bighole_t iCallFctByRef67(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_67_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66]
    );
}

bighole_t iCallFctByRef68(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_68_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67]
    );
}

bighole_t iCallFctByRef69(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_69_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68]
    );
}

bighole_t iCallFctByRef70(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_70_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69]
    );
}

bighole_t iCallFctByRef71(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_71_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70]
    );
}

bighole_t iCallFctByRef72(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_72_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71]
    );
}

bighole_t iCallFctByRef73(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_73_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72]
    );
}

bighole_t iCallFctByRef74(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_74_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73]
    );
}

bighole_t iCallFctByRef75(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_75_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74]
    );
}

bighole_t iCallFctByRef76(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_76_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75]
    );
}

bighole_t iCallFctByRef77(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_77_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76]
    );
}

bighole_t iCallFctByRef78(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_78_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77]
    );
}

bighole_t iCallFctByRef79(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_79_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78]
    );
}

bighole_t iCallFctByRef80(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_80_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79]
    );
}

bighole_t iCallFctByRef81(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_81_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80]
    );
}

bighole_t iCallFctByRef82(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_82_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81]
    );
}

bighole_t iCallFctByRef83(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_83_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82]
    );
}

bighole_t iCallFctByRef84(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_84_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83]
    );
}

bighole_t iCallFctByRef85(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_85_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84]
    );
}

bighole_t iCallFctByRef86(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_86_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85]
    );
}

bighole_t iCallFctByRef87(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_87_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86]
    );
}

bighole_t iCallFctByRef88(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_88_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87]
    );
}

bighole_t iCallFctByRef89(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_89_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88]
    );
}

bighole_t iCallFctByRef90(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_90_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89]
    );
}

bighole_t iCallFctByRef91(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_91_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89], layout->argv[90]
    );
}

bighole_t iCallFctByRef92(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_92_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89], layout->argv[90], 
    layout->argv[91]
    );
}

bighole_t iCallFctByRef93(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_93_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89], layout->argv[90], 
    layout->argv[91], layout->argv[92]
    );
}

bighole_t iCallFctByRef94(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_94_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89], layout->argv[90], 
    layout->argv[91], layout->argv[92], layout->argv[93]
    );
}

bighole_t iCallFctByRef95(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_95_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(
    layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4], layout->argv[5], layout->argv[6], 
    layout->argv[7], layout->argv[8], layout->argv[9], layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], 
    layout->argv[14], layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19], layout->argv[20], 
    layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24], layout->argv[25], layout->argv[26], layout->argv[27], 
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34], 
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41], 
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], 
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55], 
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62], 
    layout->argv[63], layout->argv[64], layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69], 
    layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74], layout->argv[75], layout->argv[76], 
    layout->argv[77], layout->argv[78], layout->argv[79], layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], 
    layout->argv[84], layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89], layout->argv[90], 
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94]
    );
}

bighole_t iCallFctByRefSub3(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  switch(layout->argc) {
  case 64:
    return iCallFctByRef64(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 65:
    return iCallFctByRef65(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 66:
    return iCallFctByRef66(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 67:
    return iCallFctByRef67(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 68:
    return iCallFctByRef68(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 69:
    return iCallFctByRef69(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 70:
    return iCallFctByRef70(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 71:
    return iCallFctByRef71(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 72:
    return iCallFctByRef72(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 73:
    return iCallFctByRef73(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 74:
    return iCallFctByRef74(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 75:
    return iCallFctByRef75(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 76:
    return iCallFctByRef76(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 77:
    return iCallFctByRef77(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 78:
    return iCallFctByRef78(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 79:
    return iCallFctByRef79(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 80:
    return iCallFctByRef80(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 81:
    return iCallFctByRef81(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 82:
    return iCallFctByRef82(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 83:
    return iCallFctByRef83(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 84:
    return iCallFctByRef84(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 85:
    return iCallFctByRef85(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 86:
    return iCallFctByRef86(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 87:
    return iCallFctByRef87(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 88:
    return iCallFctByRef88(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 89:
    return iCallFctByRef89(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 90:
    return iCallFctByRef90(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 91:
    return iCallFctByRef91(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 92:
    return iCallFctByRef92(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 93:
    return iCallFctByRef93(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 94:
    return iCallFctByRef94(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 95:
    return iCallFctByRef95(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  default:
    break;
  }
}
