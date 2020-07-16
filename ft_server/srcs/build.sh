#!/bin/bash

service mysql start

#SSL
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=bykim/CN=bykim" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt /etc/ssl/certs/
mv localhost.dev.key /etc/ssl/private/
chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

cat default > /etc/nginx/sites-available/default
echo "<?php phpinfo(); ?>" > /var/www/html/phpinfo.php
mv /var/www/html/index.nginx-debian.html /ft_server

#phpMyAdmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/

cp -rp /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php 
cat phpconfig.php > /var/www/html/phpmyadmin/config.inc.php

mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password

echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' IDENTIFIED BY '123';" | mysql -u root -p'123'
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root -p'123'
echo "FLUSH PRIVILEGES;" | mysql -u root -p'123'

#wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cat wpconfig.php > /var/www/html/wordpress/wp-config.php

service php7.3-fpm start
service nginx start