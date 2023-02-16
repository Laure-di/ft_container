#!/bin/bash

make re
./ft > ft_rslt
./std > std_rslt
sdiff -l -s -I '0x[0-9a-fA-F]\+' <(sed 's/0x[0-9a-f]\{12\}/0xADDR/g' ft_rslt) <(sed 's/0x[0-9a-f]\{12\}/0xADDR/g' std_rslt)  | cat -n | grep -v -e '($' 


