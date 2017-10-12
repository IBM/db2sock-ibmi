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

typedef bighole_t (os_fct_32_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32
);

typedef bighole_t (os_fct_33_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33
);

typedef bighole_t (os_fct_34_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34
);

typedef bighole_t (os_fct_35_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35
);

typedef bighole_t (os_fct_36_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36
);

typedef bighole_t (os_fct_37_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37
);

typedef bighole_t (os_fct_38_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38
);

typedef bighole_t (os_fct_39_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39
);

typedef bighole_t (os_fct_40_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40
);

typedef bighole_t (os_fct_41_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41
);

typedef bighole_t (os_fct_42_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42
);

typedef bighole_t (os_fct_43_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43
);

typedef bighole_t (os_fct_44_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44
);

typedef bighole_t (os_fct_45_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45
);

typedef bighole_t (os_fct_46_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46
);

typedef bighole_t (os_fct_47_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47
);

typedef bighole_t (os_fct_48_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48
);

typedef bighole_t (os_fct_49_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49
);

typedef bighole_t (os_fct_50_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50
);

typedef bighole_t (os_fct_51_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51
);

typedef bighole_t (os_fct_52_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52
);

typedef bighole_t (os_fct_53_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53
);

typedef bighole_t (os_fct_54_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54
);

typedef bighole_t (os_fct_55_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55
);

typedef bighole_t (os_fct_56_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56
);

typedef bighole_t (os_fct_57_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57
);

typedef bighole_t (os_fct_58_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58
);

typedef bighole_t (os_fct_59_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59
);

typedef bighole_t (os_fct_60_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60
);

typedef bighole_t (os_fct_61_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61
);

typedef bighole_t (os_fct_62_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62
);

typedef bighole_t (os_fct_63_t)
(
char * p1, char * p2, char * p3, char * p4, char * p5, char * p6, char * p7, 
char * p8, char * p9, char * p10, char * p11, char * p12, char * p13, char * p14, 
char * p15, char * p16, char * p17, char * p18, char * p19, char * p20, char * p21, 
char * p22, char * p23, char * p24, char * p25, char * p26, char * p27, char * p28, 
char * p29, char * p30, char * p31, char * p32, char * p33, char * p34, char * p35, 
char * p36, char * p37, char * p38, char * p39, char * p40, char * p41, char * p42, 
char * p43, char * p44, char * p45, char * p46, char * p47, char * p48, char * p49, 
char * p50, char * p51, char * p52, char * p53, char * p54, char * p55, char * p56, 
char * p57, char * p58, char * p59, char * p60, char * p61, char * p62, char * p63
);

bighole_t iCallFctByRef32(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_32_t *os_fct_ptr = NULL;
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
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31]
    );
}

bighole_t iCallFctByRef33(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_33_t *os_fct_ptr = NULL;
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
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32]
    );
}

bighole_t iCallFctByRef34(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_34_t *os_fct_ptr = NULL;
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
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33]
    );
}

bighole_t iCallFctByRef35(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_35_t *os_fct_ptr = NULL;
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
    layout->argv[28], layout->argv[29], layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34]
    );
}

bighole_t iCallFctByRef36(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_36_t *os_fct_ptr = NULL;
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
    layout->argv[35]
    );
}

bighole_t iCallFctByRef37(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_37_t *os_fct_ptr = NULL;
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
    layout->argv[35], layout->argv[36]
    );
}

bighole_t iCallFctByRef38(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_38_t *os_fct_ptr = NULL;
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
    layout->argv[35], layout->argv[36], layout->argv[37]
    );
}

bighole_t iCallFctByRef39(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_39_t *os_fct_ptr = NULL;
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
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38]
    );
}

bighole_t iCallFctByRef40(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_40_t *os_fct_ptr = NULL;
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
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39]
    );
}

bighole_t iCallFctByRef41(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_41_t *os_fct_ptr = NULL;
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
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40]
    );
}

bighole_t iCallFctByRef42(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_42_t *os_fct_ptr = NULL;
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
    layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39], layout->argv[40], layout->argv[41]
    );
}

bighole_t iCallFctByRef43(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_43_t *os_fct_ptr = NULL;
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
    layout->argv[42]
    );
}

bighole_t iCallFctByRef44(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_44_t *os_fct_ptr = NULL;
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
    layout->argv[42], layout->argv[43]
    );
}

bighole_t iCallFctByRef45(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_45_t *os_fct_ptr = NULL;
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
    layout->argv[42], layout->argv[43], layout->argv[44]
    );
}

bighole_t iCallFctByRef46(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_46_t *os_fct_ptr = NULL;
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
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45]
    );
}

bighole_t iCallFctByRef47(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_47_t *os_fct_ptr = NULL;
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
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46]
    );
}

bighole_t iCallFctByRef48(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_48_t *os_fct_ptr = NULL;
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
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47]
    );
}

bighole_t iCallFctByRef49(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_49_t *os_fct_ptr = NULL;
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
    layout->argv[42], layout->argv[43], layout->argv[44], layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48]
    );
}

bighole_t iCallFctByRef50(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_50_t *os_fct_ptr = NULL;
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
    layout->argv[49]
    );
}

bighole_t iCallFctByRef51(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_51_t *os_fct_ptr = NULL;
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
    layout->argv[49], layout->argv[50]
    );
}

bighole_t iCallFctByRef52(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_52_t *os_fct_ptr = NULL;
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
    layout->argv[49], layout->argv[50], layout->argv[51]
    );
}

bighole_t iCallFctByRef53(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_53_t *os_fct_ptr = NULL;
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
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52]
    );
}

bighole_t iCallFctByRef54(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_54_t *os_fct_ptr = NULL;
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
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53]
    );
}

bighole_t iCallFctByRef55(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_55_t *os_fct_ptr = NULL;
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
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54]
    );
}

bighole_t iCallFctByRef56(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_56_t *os_fct_ptr = NULL;
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
    layout->argv[49], layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54], layout->argv[55]
    );
}

bighole_t iCallFctByRef57(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_57_t *os_fct_ptr = NULL;
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
    layout->argv[56]
    );
}

bighole_t iCallFctByRef58(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_58_t *os_fct_ptr = NULL;
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
    layout->argv[56], layout->argv[57]
    );
}

bighole_t iCallFctByRef59(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_59_t *os_fct_ptr = NULL;
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
    layout->argv[56], layout->argv[57], layout->argv[58]
    );
}

bighole_t iCallFctByRef60(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_60_t *os_fct_ptr = NULL;
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
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59]
    );
}

bighole_t iCallFctByRef61(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_61_t *os_fct_ptr = NULL;
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
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60]
    );
}

bighole_t iCallFctByRef62(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_62_t *os_fct_ptr = NULL;
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
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61]
    );
}

bighole_t iCallFctByRef63(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_63_t *os_fct_ptr = NULL;
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
    layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59], layout->argv[60], layout->argv[61], layout->argv[62]
    );
}

bighole_t iCallFctByRefSub2(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  switch(layout->argc) {
  case 32:
    return iCallFctByRef32(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 33:
    return iCallFctByRef33(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 34:
    return iCallFctByRef34(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 35:
    return iCallFctByRef35(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 36:
    return iCallFctByRef36(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 37:
    return iCallFctByRef37(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 38:
    return iCallFctByRef38(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 39:
    return iCallFctByRef39(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 40:
    return iCallFctByRef40(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 41:
    return iCallFctByRef41(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 42:
    return iCallFctByRef42(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 43:
    return iCallFctByRef43(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 44:
    return iCallFctByRef44(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 45:
    return iCallFctByRef45(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 46:
    return iCallFctByRef46(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 47:
    return iCallFctByRef47(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 48:
    return iCallFctByRef48(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 49:
    return iCallFctByRef49(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 50:
    return iCallFctByRef50(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 51:
    return iCallFctByRef51(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 52:
    return iCallFctByRef52(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 53:
    return iCallFctByRef53(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 54:
    return iCallFctByRef54(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 55:
    return iCallFctByRef55(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 56:
    return iCallFctByRef56(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 57:
    return iCallFctByRef57(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 58:
    return iCallFctByRef58(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 59:
    return iCallFctByRef59(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 60:
    return iCallFctByRef60(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 61:
    return iCallFctByRef61(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 62:
    return iCallFctByRef62(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 63:
    return iCallFctByRef63(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  default:
    break;
  }
}
