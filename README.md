#IMPORTANT WARNING -------------------------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.


#db2sock
Welcome to the db2sock project.  
Goal is PASE DB2 CLI asynchronous API driver (libdb400.a).
This new libdb400.a default switch is replacement for PASE libdb400.a.
This was done to add the missing wide APIs to the driver.
In addition, old driver was less than optimal.
However, a chicken switch exists in generated code (not recommended)
Follow on project maybe socket based driver (tbd).

This project originated because of a need to create async DB2 requests for Node.js on IBM i, but it isn't just for Node.js and can instead be applied to all PASE langs (PHP, Ruby, Python, etc).

#Usage
- build   -- languages may xlc compile using new PASE asynchronous API header (PaseCliAsync.h) 
- runtime -- place helper libdb400.a before PASE libdb400.a driver (use LIBPATH) 

##Important
Only compiled with xlc using -qldbl128 -qalign=natural. 
Missing these options will result in ILE DB2 call failures.
if curious, see /usr/include/as400_types.h, type ILEpointer -- quadword align compiler issues
(i have no idea if gcc can be made to provide proper alignment -- tbd).


This is a unicode driver lib, UTF-8 or UTF16. 
New functions have been added to assist in UTF-8/UT-16 conversion.
Look at the include file PaseCliAsync.h to understand.
Also see the test files.

#Contributors
- Tony Cairns, IBM
- Aaron Bartell, Krengel Technology, Inc.

#Follow Along
We will be discussing things in the [Issues](http://bit.ly/db2sock-issues) section of this repo.  

# build
```
> python gen.py
> ./xlcmakeall
```

##gen.py creates: 
- PaseCliAsync.h      -- header asynchronous extensions (php, node, ...)
- PaseCliAsync_gen.c  -- asynchronous driver APIs
- libdb400.exp        -- all CLI export APIs

##human coding:
- PaseCliCustom.c      -- 'big function' APIs (experimental)
- PaseCliInit.c        -- db2 resource table manager (read)
- PaseCliInit.h        -- db2 resource table header

##examples
```
build
> cd tests
> python genmake.py
> ./xlcmakeall

optional set user profile
> export SQL_DB400="*LOCAL"
> export SQL_UID400="UID"
> export SQL_PWD400="PWD"

run 32-bit or 64-bit
> testnnnn_32
> testnnnn_64
```
Note: APIs are changing daily, therefore, tests may change significantly.


#License
BSD

