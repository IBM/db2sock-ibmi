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

typedef bighole_t (os_fct_96_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96
);

typedef bighole_t (os_fct_97_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97
);

typedef bighole_t (os_fct_98_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98
);

typedef bighole_t (os_fct_99_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99
);

typedef bighole_t (os_fct_100_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100
);

typedef bighole_t (os_fct_101_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101
);

typedef bighole_t (os_fct_102_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102
);

typedef bighole_t (os_fct_103_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103
);

typedef bighole_t (os_fct_104_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104
);

typedef bighole_t (os_fct_105_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105
);

typedef bighole_t (os_fct_106_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106
);

typedef bighole_t (os_fct_107_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107
);

typedef bighole_t (os_fct_108_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108
);

typedef bighole_t (os_fct_109_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109
);

typedef bighole_t (os_fct_110_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110
);

typedef bighole_t (os_fct_111_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111
);

typedef bighole_t (os_fct_112_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112
);

typedef bighole_t (os_fct_113_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113
);

typedef bighole_t (os_fct_114_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114
);

typedef bighole_t (os_fct_115_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115
);

typedef bighole_t (os_fct_116_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116
);

typedef bighole_t (os_fct_117_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117
);

typedef bighole_t (os_fct_118_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118
);

typedef bighole_t (os_fct_119_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119
);

typedef bighole_t (os_fct_120_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120
);

typedef bighole_t (os_fct_121_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120, char * p121
);

typedef bighole_t (os_fct_122_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120, char * p121, char * p122
);

typedef bighole_t (os_fct_123_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120, char * p121, char * p122, char * p123
);

typedef bighole_t (os_fct_124_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120, char * p121, char * p122, char * p123, char * p124
);

typedef bighole_t (os_fct_125_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120, char * p121, char * p122, char * p123, char * p124, char * p125
);

typedef bighole_t (os_fct_126_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120, char * p121, char * p122, char * p123, char * p124, char * p125, char * p126
);

typedef bighole_t (os_fct_127_t)
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
char * p92, char * p93, char * p94, char * p95, char * p96, char * p97, char * p98, 
char * p99, char * p100, char * p101, char * p102, char * p103, char * p104, char * p105, 
char * p106, char * p107, char * p108, char * p109, char * p110, char * p111, char * p112, 
char * p113, char * p114, char * p115, char * p116, char * p117, char * p118, char * p119, 
char * p120, char * p121, char * p122, char * p123, char * p124, char * p125, char * p126, 
char * p127
);

bighole_t iCallFctByRef96(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_96_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95]
    );
}

bighole_t iCallFctByRef97(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_97_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96]
    );
}

bighole_t iCallFctByRef98(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_98_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97]
    );
}

bighole_t iCallFctByRef99(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_99_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98]
    );
}

bighole_t iCallFctByRef100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_100_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99]
    );
}

bighole_t iCallFctByRef101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_101_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100]
    );
}

bighole_t iCallFctByRef102(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_102_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101]
    );
}

bighole_t iCallFctByRef103(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_103_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102]
    );
}

bighole_t iCallFctByRef104(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_104_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103]
    );
}

bighole_t iCallFctByRef105(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_105_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104]
    );
}

bighole_t iCallFctByRef106(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_106_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105]
    );
}

bighole_t iCallFctByRef107(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_107_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106]
    );
}

bighole_t iCallFctByRef108(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_108_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107]
    );
}

bighole_t iCallFctByRef109(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_109_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108]
    );
}

bighole_t iCallFctByRef110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_110_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109]
    );
}

bighole_t iCallFctByRef111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_111_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110]
    );
}

bighole_t iCallFctByRef112(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_112_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111]
    );
}

bighole_t iCallFctByRef113(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_113_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112]
    );
}

bighole_t iCallFctByRef114(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_114_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113]
    );
}

bighole_t iCallFctByRef115(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_115_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114]
    );
}

bighole_t iCallFctByRef116(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_116_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115]
    );
}

bighole_t iCallFctByRef117(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_117_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116]
    );
}

bighole_t iCallFctByRef118(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_118_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117]
    );
}

bighole_t iCallFctByRef119(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_119_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118]
    );
}

bighole_t iCallFctByRef120(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_120_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119]
    );
}

bighole_t iCallFctByRef121(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_121_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119], layout->argv[120]
    );
}

bighole_t iCallFctByRef122(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_122_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119], layout->argv[120], layout->argv[121]
    );
}

bighole_t iCallFctByRef123(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_123_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119], layout->argv[120], layout->argv[121], layout->argv[122]
    );
}

bighole_t iCallFctByRef124(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_124_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119], layout->argv[120], layout->argv[121], layout->argv[122], layout->argv[123]
    );
}

bighole_t iCallFctByRef125(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_125_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119], layout->argv[120], layout->argv[121], layout->argv[122], layout->argv[123], layout->argv[124]
    );
}

bighole_t iCallFctByRef126(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_126_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119], layout->argv[120], layout->argv[121], layout->argv[122], layout->argv[123], layout->argv[124], layout->argv[125]
    );
}

bighole_t iCallFctByRef127(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_127_t *os_fct_ptr = NULL;
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
    layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94], layout->argv[95], layout->argv[96], layout->argv[97], 
    layout->argv[98], layout->argv[99], layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104], 
    layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109], layout->argv[110], layout->argv[111], 
    layout->argv[112], layout->argv[113], layout->argv[114], layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], 
    layout->argv[119], layout->argv[120], layout->argv[121], layout->argv[122], layout->argv[123], layout->argv[124], layout->argv[125], 
    layout->argv[126]
    );
}

bighole_t iCallFctByRefSub4(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  switch(layout->argc) {
  case 96:
    return iCallFctByRef96(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 97:
    return iCallFctByRef97(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 98:
    return iCallFctByRef98(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 99:
    return iCallFctByRef99(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 100:
    return iCallFctByRef100(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 101:
    return iCallFctByRef101(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 102:
    return iCallFctByRef102(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 103:
    return iCallFctByRef103(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 104:
    return iCallFctByRef104(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 105:
    return iCallFctByRef105(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 106:
    return iCallFctByRef106(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 107:
    return iCallFctByRef107(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 108:
    return iCallFctByRef108(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 109:
    return iCallFctByRef109(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 110:
    return iCallFctByRef110(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 111:
    return iCallFctByRef111(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 112:
    return iCallFctByRef112(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 113:
    return iCallFctByRef113(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 114:
    return iCallFctByRef114(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 115:
    return iCallFctByRef115(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 116:
    return iCallFctByRef116(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 117:
    return iCallFctByRef117(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 118:
    return iCallFctByRef118(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 119:
    return iCallFctByRef119(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 120:
    return iCallFctByRef120(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 121:
    return iCallFctByRef121(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 122:
    return iCallFctByRef122(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 123:
    return iCallFctByRef123(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 124:
    return iCallFctByRef124(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 125:
    return iCallFctByRef125(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 126:
    return iCallFctByRef126(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 127:
    return iCallFctByRef127(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  default:
    break;
  }
}
