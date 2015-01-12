#!/bin/bash

RESULT=`../my_select -V="|" "Nathan|poirie_n" "Tim|greil_t" "Lucas|onillo_l" "Pierre|monge_p" "Raph|perche_r" "Jerem|octeau_j" "Johan|gangai_j"`

echo "Selected login:"
for i in $RESULT
do
    echo $i
done
