#!/bin/bash

find . -type f ! -name "*.c" ! -name "*.sh" -exec rm -f {} \;

echo "All non-.c and non-.sh files have been deleted."