#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2proc - stored procedure for toolkit call

This stored procedure is called when using toolkit (libtk400.a). 
The stored procedure argument is a blob that contains the 'layout' of an ILE PGM or SRVPGM call.

# overview 

This stored procedure interface enables IBM i scripting languages using the driver to share QTEMP in QSQSRVR job proxy. 
That is, both toolkit operations and DB2 operations will run in QSQSRVR proxy, therefore QTEMP is 'shared'.
Also, same single QTEMP rules will apply when folks call this stored procedure remote 
from LUW (db2, rest, odbc, ssl/ssh, etc.).

PGM is always by ref. Any PGM pass by ref works in toolkit "as is" up to 255 parameters.

```
       dcl-pi Main;
         paramCount int(10);
         p1 char(5);
         p2 char(5) options(*nopass);
         p3 char(5) options(*nopass);
       end-pi;
         paramCount = %parms();
       return;

       dcl-ds innerDS qualified;
          field1 char(10);
          field2 char(15);
          field3 char(25);
          field4 char(5);
       end-ds;
```

PGM pass complex nested DS structures 'by ref' is also supported.

```

       dcl-ds outDS qualified;
          out1 int(10);
          out2 varchar(5:2);
          outTable likeds(innerDS) dim(30);
          out3 varchar(10:2);
       end-ds;

       dcl-pr Main extpgm;
         val int(10);
         outCount int(10);
         output likeds(outDS) dim(200);
         last char(10);
       end-pr;

       dcl-pi Main;
         val int(10);
         outCount int(10);
         output likeds(outDS) dim(200);
         last char(10);
       end-pi;

```

SRVPGM pass by ref works in toolkit "as is" up to 255 parameters.

```
       dcl-proc happy9 export;
       dcl-pi  *N;
         o1 packed(16:2);
         o2 packed(15:2);
         o3 int(5);
         o4 char(7);
         o5 char(16);
         o6 packed(4:2);
         o7 char(8);
         o8 packed(12:2);
         o9 packed(4:2);
       end-pi;
```

# SRVPGM pass by value (MI workaround)

Only SRVPGM have concern about pass by value. Most readers can simply ignore 
remaining of 'by value' discussion.

SRVPGM with pass by 'value' arguments is not popular on IBM i (rarely used). 
In fact, for toolkit calls you should not use pass by value to
eliminate toolkit complexity (below).

```
       dcl-pr rainpack31;
         a1 packed(31:2) value; <- pass by value (not recommended)
         a2 packed(31:2) value;
         a3 packed(31:2) value;
         a4 packed(31:2) value;
         o1 packed(31:2); <- pass by ref (most)
         o2 packed(31:2);
         o3 packed(31:2);
         o4 packed(31:2);
       end-pr;
```

Recently, some SRVPGMs started using 'const' correctness, aka, by 'value' arguments/parameters.
Most of the following 'confusing' discussion deals with working around restrictions 
due to blocked MI instructions for 'dynamic' pass by value. 

Few people really understand pass by value rules. As toolkit author, 
I almost decided not to support at all. Made worse, no un-blocked instructions are 
available to really do 'toolkit' right (generated code needed).
However, 'by value' toolkit can be done, and, following method works.


## full toolkit

The toolkit stored procedure will be both conventional (yet another) and unconventional (creative).


## conventional toolkit 

The conventional toolkit interface will support arguments/parameters pass by reference "as is".
The conventional dynamic or runtime resolve and activation of PGM, SRVPGM programs typical
of many toolkits is included in this interface. This will fill 80-90% of toolkit needs
at good performance.

Addition, "some" pass by value arguments/parameters patterns are also supported "as is".
These will follow Call Service Program Procedure (QZRUCLSP) API of max 8 arguments/parameters. 
As with QZRUCLSP, if value arguments are all the same size, 
default toolkit can handle call task by simple 16 possible length 'pattern'.

Technically, pass 'by value' is all about size. You need to match size for default call to work.
If all your pass by value arguments are same size, default toolkit will handle (ibyval*.c). 
You may have many different types (char and packed below), but they must be same length (all fool16_t, etc.).
SRVPGM interface 'by value' QZRUCLSP limits to only bin(4) for pass by value 8 arguments/parameters. 
This toolkit will take most other non-floating point sizes for pass by value 8 arguments/parameters (length 1-16).


```
=== match basic Call Service Program Procedure (QZRUCLSP) API (bin(4) only) ===
       dcl-pr rainint4;
         a1 int(10) value; <-- fool4_t
         a2 int(10) value;
         a3 int(10) value;
         a4 int(10) value;
         o1 int(10);
         o2 int(10);
         o3 int(10);
         o4 int(10);
       end-pr;
== also works default any combination fool16_t (any type, but same size) ===
       dcl-pr rainpack31;
         a1 packed(31:2) value; <-- fool16_t
         a2 packed(31:2) value;
         a3 packed(31:2) value;
         a4 packed(31:2) value;
         o1 packed(31:2);
         o2 packed(31:2);
         o3 packed(31:2);
         o4 packed(31:2);
       end-pr;
       dcl-pr rainchar16;
         a1 char(16) value; <-- fool16_t
         a2 char(16) value;
         a3 char(16) value;
         a4 char(16) value;
         o1 char(16);
         o2 char(16);
         o3 char(16);
         o4 char(16);
       end-pr;
```

## warning (by value zoned)

Passing 'by value' zoned may not work (4s2, 12s2, etc.). That is, most other types 'by value' seem to work fine, but zone 'by value' has issues.
I recommend stay away from 'by value' zone until the problem can be understood.

## unconventional toolkit (ILE-PROC-USER)

This is an Open Source project. As such we are not bound by constraints of everything comes from Rochester IBM.
To wit, unconventional toolkit interface will allow you to compile your specific call into this stored procedure. 
A supplemental module named 'db2user' is included to allow you to handle any sort of
call to your existing code. Specifically, you can use techniques copied from the conventional toolkit (above),
or, you may also include your own custom calls directly compiled into "the stored procedure driver".

Why? Speed. The fastest load time for any call is a compile time set 'load/activate'. Conventional
toolkit interface will exist, and, will probably be fine for 80% of all calls (above). 
This unconventional do it yourself compile interface will really
give you ultimate control over performance. That is, everyone complains about speed and/or limitations of
every toolkit ever written for IBM i. This unconventional interface can directly link your RPG programs 
into the stored procedure, so they will be loaded immediately when the toolkit call occurs. 
Great! Instant performance boost for your IBM i scripting languages at levels comparable with 
RPG-2-RPG compiled calls (because it is compiled). This is a good thing! Don't let unconventional
stop you from thinking this idea through (see WIP). 

Work In Progress -- (not done yet)

User 'db2user' is a c module, possibly difficult for some to understand. I will likely add another 'db2rpg'
to allow RPGers to participate within the framework of 'everything RPG'.

## technical registers (pass by value)

Technically, anything 16 bytes or less marked as 'value' will be placed in up to two 8 byte registers. 
Therefore, toolkit, we need only get the correct size 'hole' and you can pass any type through the 'value'
(int - fool4_t, packed - fool1_t to fool16_t, char - fool1_t to fool16_t, ds -  fool1_t to fool16_t,
so on), with exception of floating point registers (4f, 8f, etc.).

For those wondering about any pass by value 17+ bytes (ds, etc.). Greater 17+ 'value' is actually accomplished by 
compiler copy argument/parameter, where 'value' is promoted to pass by reference to the copy. Basically, 
folks thinking they were improving performance using aggregates 17+ bytes by 'value', 
are actually making things perform worse via compiler 'temp' copy (ILE c, C++, RPG, etc.). 
However, good side, 'temp' copy does not reflect changes in caller object made by callee (meaning copy), 
but most folks did not even know a copy occurred ( ... and slowed things down ... now you know).

##db2user - user special add handler module (dynamic loaded ILE SRVPGM).

The db2user module is provided to add other user custom call SRVRPGM by value.
The pattern can be seen in example in db2user sample_crazy9.
Simply add you own signatures following the pattern up to ILE_PGM_MAX_ARGS (259 args).

You may follow the dynamic/runtime load/activate, or, you may simply code
your call into db2user using conventional ILE call techniques. Aka,
you may dierctly control the performance of your call from PASE. 

Pattern:
```
'I' - float(8), 8f, floating point
'H' - float(4), 4f, floating point
'G' - typedef struct fool16 {char hole[16]; } fool16_t;
'F' - typedef struct fool15 {char hole[15]; } fool15_t;
'E' - typedef struct fool14 {char hole[14]; } fool14_t;
'D' - typedef struct fool13 {char hole[13]; } fool13_t;
'C' - typedef struct fool12 {char hole[12]; } fool12_t;
'B' - typedef struct fool11 {char hole[11]; } fool11_t;
'A' - typedef struct fool10 {char hole[10]; } fool10_t;
'9' - typedef struct fool9 {char hole[9]; } fool9_t;
'8' - typedef struct fool8 {char hole[8]; } fool8_t;
'7' - typedef struct fool7 {char hole[7]; } fool7_t;
'6' - typedef struct fool6 {char hole[6]; } fool6_t;
'5' - typedef struct fool5 {char hole[5]; } fool5_t;
'4' - typedef struct fool4 {char hole[4]; } fool4_t;
'3' - typedef struct fool3 {char hole[3]; } fool3_t;
'2' - typedef struct fool2 {char hole[2]; } fool2_t;
'1' - typedef struct fool1 {char hole[1]; } fool1_t;
'0' - pointer (pass by ref)

(cut/paste from ILE-PROC-USER/db2user.c)

/*
Sample of many different by value arguments with by ref output

mask
       dcl-pr crazy9;
9         a1 packed(16:2) value;
8         a2 packed(15:2) value;
2         a3 int(5) value;
7         a4 char(7) value;
G         a5 char(16) value;
3         a6 packed(4:2) value;
8         a7 char(8) value;
7         a8 packed(12:2) value;
3         a9 packed(4:2) value;
0         o1 packed(16:2);
0         o2 packed(15:2);
0         o3 int(5);
0         o4 char(7);
0         o5 char(16);
0         o6 packed(4:2);
0         o7 char(8);
0         o8 packed(12:2);
0         o9 packed(4:2);
       end-pr;
*/
bighole_t sample_crazy9(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern, int * isDone)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  *isDone = 1;
  return os_fct_ptr(
    *(fool9_t *)  iNextVal(layout, 0),
    *(fool8_t *)  iNextVal(layout, 1),
    *(fool2_t *)  iNextVal(layout, 2),
    *(fool7_t *)  iNextVal(layout, 3),
    *(fool16_t *) iNextVal(layout, 4),
    *(fool3_t *)  iNextVal(layout, 5),
    *(fool8_t *)  iNextVal(layout, 6),
    *(fool7_t *)  iNextVal(layout, 7),
    *(fool3_t *)  iNextVal(layout, 8),
    iNextPtr(layout, 9),
    iNextPtr(layout, 10),
    iNextPtr(layout, 11),
    iNextPtr(layout, 12),
    iNextPtr(layout, 13),
    iNextPtr(layout, 14),
    iNextPtr(layout, 15),
    iNextPtr(layout, 16),
    iNextPtr(layout, 17)
    );

}


bighole_t UserCallSrvPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern, int * isDone)
{
  // add your own custom iCallFctByValxxxxx pattern
  if (!strcmp(myPgm,"RAINSRV") && !strcmp(myFunc,"CRAZY9")) {
    return sample_crazy9(layout, myPgm, myLib, myFunc, lenFunc, pattern, isDone);
  }
  return;
}

void UserCallPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, int * isDone)
{
  // add your own custom iCallPgmByRefxxxxx
  return;
}


```

## modules (incomplete)

ILE modules:
```
db2proc - SRVPGM main stored procedure iCall400(blob)
db2user - user edit special add handler module (dynamic loaded ILE SRVPGM).
== python gen.py (generated code - do not edit) ==
ibyref*.c - call PGM and SRVPGM by reference (80% case)
ibyval*.c - call SRVPGM by value all by value arguments same size (up to 8 argumanets)
```
Note (gen.py): We are not using MI CALLPGM, CALLPGMV, etc., because these fall short of 
mark for a full toolkit (without using blocked MI instructions).


## PASE _ILECALL

There were/are alternatives starting PASE in db2proc and using _ILECALL.
In fact, XMLSERVICE uses _ILECALL from ILE RPG code.
While _ILECALL is appealing for simplicity (do it all), 'staring PASE' will
slow down performance as experienced with XMLSERVICE (nobody likes slow).
However, to complete toolkiit 'call anything' including SRVPGM with
pass by value, this option may be implemented in db2proc as the last 
ditch 'slower' call path (TBD).


## Last word

Ultimately we may require something better than QZRUCLSP(ish) style API out of IBM i OS (above). 
Something new, to avoid pass by value 'mess' caused by blocked MI instructions (limiting). 
Aka, perhaps something like _ILECALL for PASE, but ILE API. Anyway, by changing IBM i OS, 
we would set a stake in version supported (undesirable for a driver 'toolkit').
 
Note: Do not expect any action IBM i OS. 
This is my personal observation, and, bit of frustration with blocked MI instructions.
 
