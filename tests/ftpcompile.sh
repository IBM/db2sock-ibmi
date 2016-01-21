# bash ftpcompile.sh lp0364d adc
MYPWD=$(<$HOME/.ftprc)
ftp -i -n -v $1 << ftp_end
user $2 $MYPWD

quote namefmt 1
bin

mkdir /home/adc/PaseCliAsync/tests
cd /home/adc/PaseCliAsync/tests
mput *

quit

ftp_end

