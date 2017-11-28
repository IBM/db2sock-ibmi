#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock - libxml400.a (default)

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any JSON/XML parser can be used to call this interface.
The parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.
Warning - current version in project is only a test. This is not formal interface.

```
tool_ctor - callbacks for output formating
tool_run - parsed name, value pairs
tool_dtor - clean-up memory
```

The parsers are dynamically loaded via SQL400Json or SQL400Xml interfaces. 
Default parser is provided (toolkit-parser-json, toolkit-parser-xml).
An environment variable allows any override fo a parser your own.

```
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
> export DB2XMLPARSER32 libxml400.a(shr.o)
> export DB2XMLPARSER64 libxml400.a(shr_64.o)
```

