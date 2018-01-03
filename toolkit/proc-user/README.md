#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock/toolkit - db2proc (stored procedure for toolkit call)

Please see README.md in toolkit/proc directory, custom usage of db2user.c should be clearer after reading.

##db2sock/toolkit/proc-user db2user (user special add handler module - dynamic loaded ILE SRVPGM).

The db2user module is provided to add other user custom call SRVRPGM by value.
The pattern can be seen in example in db2user sample_crazy9.
Simply add you own signatures following the pattern up to ILE_PGM_MAX_ARGS (259 args).


