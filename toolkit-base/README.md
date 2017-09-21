#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock - libtkit400.a

Welcome to db2sock project. This 'toolkit' is a dynamically loaded toolkit interface. 
Any parser can be used to call this toolkit interface.
Parser can be XML, JSON, CSV, (anything protocol imaginable). 
Any parser simply includes PaseTool.h, compile with -ltkit400, calls toolkit APIs.
The goal of any parser is to map it's protocol to toolkit key[], value[], level[] for input (tool_run). 
The toolkit constructor requires parser callbacks to output 'callback' result data into any format (xml, json, csv, etc.).
 
Three functions exported from toolkit library (libtkit400.a).
```
tool_ctor - callbacks for output formating (parser specific output callbacks json, xml, csv, etc.)
tool_dtor - clean-up memory
tool_node_beg - parser add elem beg node to link list
tool_node_sep - parser normalize json array elem link list (complex)
tool_node_end - parser add elem end node to link list
tool_node_attr - parser add attribute node to link list
tool_key_range - parser helper
tool_key_match_beg_2_end - parser helper
tool_key_match_end_2_beg - parser helper
tool_key_match_attr_2_beg - parser helper
tool_run  - run link list
```

The parsers are dynamically loaded via SQL400Json or SQL400Xml interfaces (maybe others - tbd). 
Default parser is provided (toolkit-parser-json, toolkit-parser-xml).
An environment variable allows any override fo a parser your own.

```
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
> export DB2XMLPARSER32 libxml400.a(shr.o)
> export DB2XMLPARSER64 libxml400.a(shr_64.o)
```


