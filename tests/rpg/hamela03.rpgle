     D Parm1           S              1A             
     D Parm2           S             18A             
     D Parm3           S              2A             
     D Parm4           S             10A             
     D Arr1Count       S              3S 0           
     D Arr1            DS                  Occurs(10)
     D  Arr1P1                        7A             
     D  Arr1P2                      132A             
     D  Arr1P3                       30A             
     D  Arr1P4                        1S 0           
     D Parm5           S              1A             
     D Parm6           S              4A             
     D Parm7           S             18A             
     D Parm8           S            100A             
     D Parm9           S              3S 0           
     D Parm10          S              3S 0           
     D Arr2Count       S              5S 0           
     D Arr2            DS                  Occurs(10)
     D  Arr2P1                        1A             
     D  Arr2P2                       30A                  
     D  Arr2P3                        4A                  
     D  Arr2P4                       18A                  
     D  Arr2P5                      100A                  
     D Parm11          S             30A                  

     D i               S              5P 0                

     C     *Entry        Plist                            
     C                   Parm                    Parm1    
     C                   Parm                    Parm2    
     C                   Parm                    Parm3    
     C                   Parm                    Parm4    
     C                   Parm                    Arr1Count
     C                   Parm                    Arr1     
     C                   Parm                    Parm5    
     C                   Parm                    Parm6    
     C                   Parm                    Parm7    
     C                   Parm                    Parm8    
     C                   Parm                    Parm9    
     C                   Parm                    Parm10               
     C                   Parm                    Arr2Count            
     C                   Parm                    Arr2                 
     C                   Parm                    Parm11               

     C                   For       i             = 1 To Arr2Count By 1
     C                   Eval      %occur(Arr2)  = i                  
     C                   Eval      Arr2P5        = %trim(Arr2P1) +    
     C                                             %trim(Arr2P2) +    
     C                                             %trim(Arr2P3)      
     C                   Endfor                                       
     C                                                                
     C                   Eval      Parm11        = %trim(Parm2)       
     C                                                                
     C                   Eval      %occur(Arr1)  = 1                  
     C                   Eval      Arr1P2        = %trim(Parm8)
     C                   Eval      Arr1Count     = 1           
     C                                                         
     C                   Eval      *Inlr         = '1'         
     C                   Return                                

