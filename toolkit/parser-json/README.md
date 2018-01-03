#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock/toolkit/parser-json - libjson400.a (default)

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any JSON/XML parser can be used to call this interface.
The parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.
See db2sock/toolkit/README.md for generic toolkit interface details.

The parsers are dynamically loaded via SQL400Json or SQL400Xml interfaces. 
Default parser is provided (toolkit-parser-json, toolkit-parser-xml).
An environment variable allows any override any parser of your own (json, xml, csv, etc.).

```
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
```

## examples (best source sytax)

For json examples see db2sock/tests/json.

