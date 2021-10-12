FROM debian:buster

COPY ./srcs/services.sh /tmp
COPY ./srcs/mysql-conf.sql /tmp
COPY ./srcs/wp-conf.sql /tmp

RUN apt-get -y update && apt-get -y upgrade && apt-get -y install nginx
RUN apt-get -y install mariadb-server mariadb-client
RUN service mysql start && mysql -u root < /tmp/mysql-conf.sql
#phpmyadmin config
RUN apt-get -y install php-fpm php-mysql php-mbstring php-zip php-gd \
    php-xml php-pear php-gettext php-cgi wget procps
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.4/phpMyAdmin-4.9.4-english.tar.gz
RUN mkdir var/www/html/phpmyadmin
RUN tar xzf phpMyAdmin-4.9.4-english.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin
RUN chmod 660 /var/www/html/phpmyadmin/config.inc.php
RUN chown -R www-data:www-data /var/www/html/phpmyadmin
RUN service mysql start && mysql -u root < /var/www/html/phpmyadmin/sql/create_tables.sql && mysql -u root < /tmp/wp-conf.sql

###WP

RUN apt-get -y install php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip
RUN wget https://wordpress.org/latest.tar.gz -P /tmp
RUN mkdir /var/www/html/wordpress
COPY ./srcs/wp-config.php /var/www/html/wordpress
RUN tar xzf /tmp/latest.tar.gz --strip-components=1 -C /var/www/html/wordpress
RUN chown -R www-data:www-data /var/www/html/wordpress

#SSL

RUN mkdir /etc/nginx/ssl && chmod 700 /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/" -keyout /etc/nginx/ssl/localssl.key -out /etc/nginx/ssl/localssl.crt

RUN service nginx restart
ADD ./srcs/default /etc/nginx/sites-available/
RUN service nginx reload
RUN chmod -R 755 /var/www/*
RUN chmod 700 /tmp/services.sh
CMD /tmp/services.sh
EXPOSE 80 443
