INSERT INTO mysql.user(Host,User,Password,ssl_cipher,x509_issuer,x509_subject)values('localhost','zhc',PASSWORD("123456"),'','','');
update mysql.user set PASSWORD = PASSWORD("123456") where User='zhc'and Host = 'localhost';
select *from mysql.user ;
drop user 'zhc'@'localhost';