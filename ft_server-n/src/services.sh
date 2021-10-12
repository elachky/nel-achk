#!bin/bash
#service nginx start
#if [ $? -ne 0 ]; then
#    echo "fail to start nginx service"
#fi
#service mysql start
#if [ $? -ne 0 ]; then
#    echo "fail to start mysql service"
#fi
#while true 
#do sleep 1000
#done

service php7.3-fpm start && service mysql start && service nginx start && tail -f /var/log/nginx/access.log
