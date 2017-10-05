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

#pragma datamodel(p128)
typedef void (os_pgm_128_t)
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
char * p127, char * p128
);
#pragma linkage(os_pgm_128_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef128(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_129_t)
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
char * p127, char * p128, char * p129
);
#pragma linkage(os_pgm_129_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef129(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_130_t)
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
char * p127, char * p128, char * p129, char * p130
);
#pragma linkage(os_pgm_130_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef130(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_131_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131
);
#pragma linkage(os_pgm_131_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef131(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_132_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132
);
#pragma linkage(os_pgm_132_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef132(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_133_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133
);
#pragma linkage(os_pgm_133_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef133(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_134_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134
);
#pragma linkage(os_pgm_134_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef134(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_135_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135
);
#pragma linkage(os_pgm_135_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef135(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_136_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136
);
#pragma linkage(os_pgm_136_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef136(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_137_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137
);
#pragma linkage(os_pgm_137_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef137(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_138_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138
);
#pragma linkage(os_pgm_138_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef138(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_139_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139
);
#pragma linkage(os_pgm_139_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef139(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_140_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140
);
#pragma linkage(os_pgm_140_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef140(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_141_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141
);
#pragma linkage(os_pgm_141_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef141(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_142_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142
);
#pragma linkage(os_pgm_142_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef142(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_143_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143
);
#pragma linkage(os_pgm_143_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef143(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_144_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144
);
#pragma linkage(os_pgm_144_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef144(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_145_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145
);
#pragma linkage(os_pgm_145_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef145(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_146_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146
);
#pragma linkage(os_pgm_146_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef146(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_147_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147
);
#pragma linkage(os_pgm_147_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef147(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_148_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148
);
#pragma linkage(os_pgm_148_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef148(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_149_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149
);
#pragma linkage(os_pgm_149_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef149(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_150_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150
);
#pragma linkage(os_pgm_150_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef150(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_151_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151
);
#pragma linkage(os_pgm_151_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef151(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_152_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152
);
#pragma linkage(os_pgm_152_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef152(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_153_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152, char * p153
);
#pragma linkage(os_pgm_153_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef153(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_154_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152, char * p153, char * p154
);
#pragma linkage(os_pgm_154_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef154(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_155_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152, char * p153, char * p154, 
char * p155
);
#pragma linkage(os_pgm_155_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef155(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_156_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152, char * p153, char * p154, 
char * p155, char * p156
);
#pragma linkage(os_pgm_156_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef156(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_157_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152, char * p153, char * p154, 
char * p155, char * p156, char * p157
);
#pragma linkage(os_pgm_157_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef157(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_158_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152, char * p153, char * p154, 
char * p155, char * p156, char * p157, char * p158
);
#pragma linkage(os_pgm_158_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef158(ile_pgm_call_t* layout, char * myPgm, char * myLib);

#pragma datamodel(p128)
typedef void (os_pgm_159_t)
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
char * p127, char * p128, char * p129, char * p130, char * p131, char * p132, char * p133, 
char * p134, char * p135, char * p136, char * p137, char * p138, char * p139, char * p140, 
char * p141, char * p142, char * p143, char * p144, char * p145, char * p146, char * p147, 
char * p148, char * p149, char * p150, char * p151, char * p152, char * p153, char * p154, 
char * p155, char * p156, char * p157, char * p158, char * p159
);
#pragma linkage(os_pgm_159_t,OS)
#pragma datamodel(pop)
void iCallPgmByRef159(ile_pgm_call_t* layout, char * myPgm, char * myLib);

void iCallPgmByRef128(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_128_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127]
    );
}

void iCallPgmByRef129(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_129_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128]
    );
}

void iCallPgmByRef130(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_130_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129]
    );
}

void iCallPgmByRef131(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_131_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130]
    );
}

void iCallPgmByRef132(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_132_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131]
    );
}

void iCallPgmByRef133(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_133_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132]
    );
}

void iCallPgmByRef134(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_134_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133]
    );
}

void iCallPgmByRef135(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_135_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134]
    );
}

void iCallPgmByRef136(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_136_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135]
    );
}

void iCallPgmByRef137(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_137_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136]
    );
}

void iCallPgmByRef138(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_138_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137]
    );
}

void iCallPgmByRef139(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_139_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138]
    );
}

void iCallPgmByRef140(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_140_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139]
    );
}

void iCallPgmByRef141(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_141_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140]
    );
}

void iCallPgmByRef142(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_142_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141]
    );
}

void iCallPgmByRef143(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_143_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142]
    );
}

void iCallPgmByRef144(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_144_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143]
    );
}

void iCallPgmByRef145(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_145_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144]
    );
}

void iCallPgmByRef146(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_146_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145]
    );
}

void iCallPgmByRef147(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_147_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146]
    );
}

void iCallPgmByRef148(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_148_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147]
    );
}

void iCallPgmByRef149(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_149_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148]
    );
}

void iCallPgmByRef150(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_150_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149]
    );
}

void iCallPgmByRef151(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_151_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150]
    );
}

void iCallPgmByRef152(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_152_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151]
    );
}

void iCallPgmByRef153(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_153_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151], layout->argv[152]
    );
}

void iCallPgmByRef154(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_154_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151], layout->argv[152], layout->argv[153]
    );
}

void iCallPgmByRef155(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_155_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151], layout->argv[152], layout->argv[153], 
    layout->argv[154]
    );
}

void iCallPgmByRef156(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_156_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151], layout->argv[152], layout->argv[153], 
    layout->argv[154], layout->argv[155]
    );
}

void iCallPgmByRef157(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_157_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151], layout->argv[152], layout->argv[153], 
    layout->argv[154], layout->argv[155], layout->argv[156]
    );
}

void iCallPgmByRef158(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_158_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151], layout->argv[152], layout->argv[153], 
    layout->argv[154], layout->argv[155], layout->argv[156], layout->argv[157]
    );
}

void iCallPgmByRef159(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_159_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_pfct_ptr(
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
    layout->argv[126], layout->argv[127], layout->argv[128], layout->argv[129], layout->argv[130], layout->argv[131], layout->argv[132], 
    layout->argv[133], layout->argv[134], layout->argv[135], layout->argv[136], layout->argv[137], layout->argv[138], layout->argv[139], 
    layout->argv[140], layout->argv[141], layout->argv[142], layout->argv[143], layout->argv[144], layout->argv[145], layout->argv[146], 
    layout->argv[147], layout->argv[148], layout->argv[149], layout->argv[150], layout->argv[151], layout->argv[152], layout->argv[153], 
    layout->argv[154], layout->argv[155], layout->argv[156], layout->argv[157], layout->argv[158]
    );
}

void iCallPgmByRefSub5(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  switch(layout->argc) {
  case 128:
    iCallPgmByRef128(layout, myPgm, myLib);
    break;
  case 129:
    iCallPgmByRef129(layout, myPgm, myLib);
    break;
  case 130:
    iCallPgmByRef130(layout, myPgm, myLib);
    break;
  case 131:
    iCallPgmByRef131(layout, myPgm, myLib);
    break;
  case 132:
    iCallPgmByRef132(layout, myPgm, myLib);
    break;
  case 133:
    iCallPgmByRef133(layout, myPgm, myLib);
    break;
  case 134:
    iCallPgmByRef134(layout, myPgm, myLib);
    break;
  case 135:
    iCallPgmByRef135(layout, myPgm, myLib);
    break;
  case 136:
    iCallPgmByRef136(layout, myPgm, myLib);
    break;
  case 137:
    iCallPgmByRef137(layout, myPgm, myLib);
    break;
  case 138:
    iCallPgmByRef138(layout, myPgm, myLib);
    break;
  case 139:
    iCallPgmByRef139(layout, myPgm, myLib);
    break;
  case 140:
    iCallPgmByRef140(layout, myPgm, myLib);
    break;
  case 141:
    iCallPgmByRef141(layout, myPgm, myLib);
    break;
  case 142:
    iCallPgmByRef142(layout, myPgm, myLib);
    break;
  case 143:
    iCallPgmByRef143(layout, myPgm, myLib);
    break;
  case 144:
    iCallPgmByRef144(layout, myPgm, myLib);
    break;
  case 145:
    iCallPgmByRef145(layout, myPgm, myLib);
    break;
  case 146:
    iCallPgmByRef146(layout, myPgm, myLib);
    break;
  case 147:
    iCallPgmByRef147(layout, myPgm, myLib);
    break;
  case 148:
    iCallPgmByRef148(layout, myPgm, myLib);
    break;
  case 149:
    iCallPgmByRef149(layout, myPgm, myLib);
    break;
  case 150:
    iCallPgmByRef150(layout, myPgm, myLib);
    break;
  case 151:
    iCallPgmByRef151(layout, myPgm, myLib);
    break;
  case 152:
    iCallPgmByRef152(layout, myPgm, myLib);
    break;
  case 153:
    iCallPgmByRef153(layout, myPgm, myLib);
    break;
  case 154:
    iCallPgmByRef154(layout, myPgm, myLib);
    break;
  case 155:
    iCallPgmByRef155(layout, myPgm, myLib);
    break;
  case 156:
    iCallPgmByRef156(layout, myPgm, myLib);
    break;
  case 157:
    iCallPgmByRef157(layout, myPgm, myLib);
    break;
  case 158:
    iCallPgmByRef158(layout, myPgm, myLib);
    break;
  case 159:
    iCallPgmByRef159(layout, myPgm, myLib);
    break;
  default:
    break;
  }
}
