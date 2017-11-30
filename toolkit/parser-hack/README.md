#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock - libhack400.a (default)

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any HACK parser can be used to call this interface.
The parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.

The parsers are dynamically loaded via SQL400Hack(API) interfaces. 
Default parser is provided (toolkit-parser-hack).
An environment variable allows any override any parser of your own (hack, xml, csv, etc.).

```
> export DB2HACKPARSER32 libhack400.a(shr.o)
> export DB2HACKPARSER64 libhack400.a(shr_64.o)
```

For hack examples see source/tests/hack.

See toolkit/README.md for post-parser toolkit interface details.

