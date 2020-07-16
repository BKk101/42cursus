#!/bin/bash

file="/var/www/html/index.nginx-debian.html"

if [ -f ${file} ];then
    rm /var/www/html/index.nginx-debian.html
fi