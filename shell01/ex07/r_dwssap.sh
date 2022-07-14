#!/bin/sh
cat /etc/passwd | sed '1~2d' | sed  's/:.*$//g' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | sed -z 's/\n/, /g' | sed -z 's/\(.*\), /\1\./'
