/*
MySQL Workbench 5.2 CE 
MySQL - 5.6.24-log : Database - TheSQD
Creat by 张海超 内蒙古工业大学
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

CREATE DATABASE /*!32312 IF NOT EXISTS*/`TheSQD` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE TheSQD;

/*Table structure for table `KintAdmin` */

DROP TABLE IF EXISTS `KintAdmin`;

CREATE  TABLE `TheSQD`.`KintAdmin` (

  `idadmin` INT UNSIGNED NOT NULL COMMENT '管理员原始编号' ,

  `TheAdminID` VARCHAR(45) NOT NULL COMMENT '管理员iD' ,

  `TheAdminIDpassword` VARCHAR(45) NOT NULL COMMENT '管理员密码' ,

  `TheAdminIdDaytime` DATETIME NOT NULL COMMENT '管理员注册时间' ,

  `TheAdminIDTimes` INT NULL COMMENT '管理员登录次数' ,

  PRIMARY KEY (`idadmin`) ,

  UNIQUE INDEX `idadmin_UNIQUE` (`idadmin` ASC, `TheAdminID` ASC) ,

  UNIQUE INDEX `TheAdminID_UNIQUE` (`TheAdminID` ASC),
  
  INDEX `TheAdminID` (`TheAdminID` ASC))

ENGINE = InnoDB

DEFAULT CHARACTER SET = utf8

COMMENT = '管理员用户表';



/*Table structure for table `KintAuser */

DROP TABLE IF EXISTS `KintAuser`;

CREATE  TABLE `TheSQD`.`KintAuser` (

  `iduser` INT NOT NULL COMMENT '一般用户原始编号' ,

  `TheUserID` VARCHAR(45) NOT NULL COMMENT '一般用户ID' ,

  `TheUserIDpassword` VARCHAR(45) NOT NULL COMMENT '一般用户密码' ,

  `TheUserIDDaytime` DATETIME NOT NULL COMMENT '一般用户注册时间' ,

  `TheUserIDTimes` INT NULL COMMENT '一般用户登录次数' ,

  PRIMARY KEY (`iduser`) ,

  UNIQUE INDEX `iduser_UNIQUE` (`iduser` ASC) ,

  UNIQUE INDEX `TheUserID_UNIQUE` (`TheUserID` ASC) ,

  INDEX `TheUserId` (`TheUserID` ASC) )

ENGINE = InnoDB

DEFAULT CHARACTER SET = utf8

COMMENT = '一般用户表';



