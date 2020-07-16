#!/bin/bash

file="/var/www/html/index.nginx-debian.html"

if [ ! -f ${file} ];then
    cp /ft_server/index.nginx-debian.html /var/www/html/
fi