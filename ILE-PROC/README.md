#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2proc - stored procedure for toolkit call

This stored procedure is called when using toolkit (libtk400.a). 
The stored procedure argument is a blob that contains the 'layout' of an ILE PGM or SRVPGM call.

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


#db2user - user special add handler module (dynamic loaded ILE SRVPGM).

First, recall, SRVPGM with pass by 'value' arguments is not overly popular on IBM i.
In fact, for this toolkit you will be much better served to not use 'value' to
eliminate complexity (see 'value' below). Technically, anything 16 bytes or less 
marked as 'value' will be placed in up to two 8 byte registers. Therefore,
we need only get the correct size 'hole' and you can pass any type through the 'value'
(int - fool4_t, packed - fool1_t to fool16_t, char - fool1_t to fool16_t, ds - fool4_t, 
so on). So few people really understand pass by value 16 bytes rules, that
as author, I almost decided not to support at all. Made even worse,
no un-blocked instructions are available to really do this right (gen code needed).
However, 'by value' toolkit can be done, and, here is a method that works.


Pass 'by value' is all about size. You need to match for call to work.
Note: If all your pass by value arguments are same size, the
default toolkit will handle (ibyval*.c). You may have many different types
(int, packed, char 'value), but they must be same length (all fool16_t, etc.).
```
=== match basic Call Service Program Procedure (QZRUCLSP) API ===
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
== also works default any combination fool16_t ===
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
       dcl-pr rainzone16;
         a1 zoned(16:2) value; <-- fool16_t
         a2 zoned(16:2) value;
         a3 zoned(16:2) value;
         a4 zoned(16:2) value;
         o1 zoned(16:2);
         o2 zoned(16:2);
         o3 zoned(16:2);
         o4 zoned(16:2);
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

The db2user module is provided to add other user custom call SRVRPGM by value.
The pattern can be seen in example in db2user iCallFctByVal2048F0.
Simply add you own signatures following the pattern up to ILE_PGM_MAX_ARGS (259 args).

Pattern:
```
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
```

BTW -- There were/are alternatives starting PASE in db2proc and using _ILECALL.
In fact, XMLSERVICE uses _ILECALL from the ILE RPG code.
While _ILECALL is appealing for simplicity (do it all), 'staring PASE' will
slow down performance experienced with XMLSERVICE (nobody likes slow).

