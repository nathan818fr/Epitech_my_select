#!/bin/bash
echo "Cloning C_Lib_MyUtils and remove .git folder."
echo "We don't use git submodules because cloning is not recursive for the final render at epitech."
rm -rf C_Lib_MyUtils
git clone git@github.com:nathan818fr/C_Lib_MyUtils.git
rm -rf C_Lib_MyUtils/.git
