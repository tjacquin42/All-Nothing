ldapsearch -xLLL uid="z*" cn | grep -i "^cn:" | sort -r | cut -c5-
