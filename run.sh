#!/bin/bash

rm a.out
gcc main.c module_reader.c acquire_modinfo.c -g
./a.out  