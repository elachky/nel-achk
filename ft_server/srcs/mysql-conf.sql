CREATE USER 'admin'@'localhost' IDENTIFIED BY '1111';
GRANT ALL PRIVILEGES ON *.* to 'admin'@'localhost';
FLUSH PRIVILEGES;