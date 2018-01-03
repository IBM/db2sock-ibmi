#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock/toolkit - libtkit400.a (generic toolkit IBM i calls)

This module provides generic toolkit service to call IBM i CMD, PGM, SRVPGM, QSH, DB2, etc. 
The toolkit binary (libtkit400.a), provides a callback constructor allowing any parser to control protocol syntax.
The toolkit binary receives an array of input generic 'ordinals' as defined by PaseTool.h,
Any parser can can use toolkit (xml, json, cvs, etc.). However, default parsers provided under toolkit directory (parser-protocol).

## interface PaseTool.h (see toolkit/parser-json example)

A protocol parser maps any chosen syntax to generic toolkit ordinals found in PaseTool.h. 
The module header (PaseTool.h), defines parser callback constructor (tool_ctor), destructor (tool_dtor), and run (tool_run).
The module header (PaseTool.h), defines ordinals for generic toolkit actions (TOOL400_KEY_CMD, TOOL400_KEY_PGM. etc.), 
and generic toolkit attributes for actions (TOOL400_PGM_NAME, TOOL400_PGM_LIB, TOOL400_PGM_FUNC, etc.).
The parser must build the generic ordinal nodes by calling toolkit provided node add interfaces (tool_node_beg, tool_node_sep, tool_node_end, tool_node_attr).
All protocol input/output syntax operations are controlled by the parser. Aka, toolkit simply uses 'callback' for desired output formating (anything you like).

## run toolkit

DB2 db2sock driver libdb400.a CLI new toolkit API SQL400Json(injson, outjson) dynamically loads json parser responsible for input/output (below).
The same simple toolkit API will be true for any other protocol we decide to implement, SQL400Xml(inxml, outxml), SQL400Cvs(incvs, outcvs), etc.

```
json parser (see toolkit/parser-json)
> export DB2JSONPARSER32 libjson400.a(shr.o)
> export DB2JSONPARSER64 libjson400.a(shr_64.o)
* Note: Default is libjson400.a, env vars are not required.
```


