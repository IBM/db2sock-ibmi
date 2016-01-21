#db2sock
Welcome to the db2sock project.  Goal is PASE DB2 CLI asynchronous API helper driver (libdb400.a). Follow on project maybe socket based driver (tbd).

This project originated because of a need to create async DB2 requests for Node.js on IBM i, but it isn't just for Node.js and can instead be applied to all PASE langs (PHP, Ruby, Python, etc).

#Usage
- build   -- languages may compile using new PASE asynchronous API header (PaseCliAsync.h) 
- runtime -- place helper libdb400.a before PASE libdb400.a driver (use LIBPATH) 

#Follow Along
We will be discussing things in the [Issues](http://bit.ly/db2sock-issues) section of this repo.  

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
- PaseCliAsync.h      -- header for building asynchronous language extensions (php, ruby, node, etc.)
- PaseCliAsync_gen.c  -- internal use asynchronous driver      (build helper libdb400.a)
- libdb400.exp        -- internal use asynchronous export APIs (build helper libdb400.a)

##human coding:
- PaseCliCustom.c      -- internal use asynchronous custom APIs            (build helper libdb400.a)
- PaseCliInit.c        -- internal use asynchronous resource table manager (build helper libdb400.a)
- PaseCliInit.h        -- internal use asynchronous resource table header  (build helper libdb400.a)


#License
BSD

