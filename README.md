#IMPORTANT WARNING -------------------------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. When this warning disappears, APIs will be considered stable.


#db2sock
Welcome to the db2sock project.  Goal is PASE DB2 CLI asynchronous API helper driver (libdb400.a). Follow on project maybe socket based driver (tbd).

This project originated because of a need to create async DB2 requests for Node.js on IBM i, but it isn't just for Node.js and can instead be applied to all PASE langs (PHP, Ruby, Python, etc).

#Usage
- build   -- languages may compile using new PASE asynchronous API header (PaseCliAsync.h) 
- runtime -- place helper libdb400.a before PASE libdb400.a driver (use LIBPATH) 

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
- PaseCliAsync.h      -- header for asynchronous language extensions (php, ruby, node, etc.)
- PaseCliAsync_gen.c  -- asynchronous driver APIs
- libdb400.exp        -- all CLI export APIs

##human coding:
- PaseCliCustom.c      -- 'big function' APIs (experimental)
- PaseCliInit.c        -- db2 resource table manager (read)
- PaseCliInit.h        -- db2 resource table header

##examples
```
> cd tests
> ./xlcmakeall
```
Note: APIs are changing daily, therefore, tests may change significantly.


#License
BSD

