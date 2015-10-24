SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

CREATE SCHEMA IF NOT EXISTS `TheSQD` DEFAULT CHARACTER SET utf8 ;
USE `TheSQD` ;

-- -----------------------------------------------------
-- Table `TheSQD`.`KintAdmin`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `TheSQD`.`KintAdmin` (
  `idadmin` INT NOT NULL AUTO_INCREMENT COMMENT '管理员ID' ,
  `TheAdminID` VARCHAR(45) NOT NULL COMMENT '管理员ID号码' ,
  `TheAdminName` VARCHAR(45) NOT NULL COMMENT '管理员真实姓名' ,
  `TheAdminIDpassword` VARCHAR(45) NULL COMMENT '管理员密码' ,
  `TheAdminIDTimes` INT NOT NULL COMMENT '管理员登录次数' ,
  PRIMARY KEY (`idadmin`, `TheAdminID`) ,
  UNIQUE INDEX `idadmin_UNIQUE` (`idadmin` ASC) ,
  UNIQUE INDEX `TheAdminID_UNIQUE` (`TheAdminID` ASC) )
ENGINE = InnoDB
COMMENT = '管理员表';


-- -----------------------------------------------------
-- Table `TheSQD`.`KintAuser`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `TheSQD`.`KintAuser` (
  `iduser` INT NOT NULL AUTO_INCREMENT COMMENT '一般用户初始ID' ,
  `TheUserID` VARCHAR(45) NOT NULL COMMENT '一般用户ID' ,
  `TheUserName` VARCHAR(45) NOT NULL COMMENT '一般用户真实姓名' ,
  `TheUserIDpassword` VARCHAR(45) NULL COMMENT '一般用户密码' ,
  `TheUserIDDaytime` DATETIME NOT NULL COMMENT '一般用户注册时间' ,
  `TheUserIDTimes` INT NOT NULL COMMENT '一般用户使用次数' ,
  PRIMARY KEY (`iduser`, `TheUserID`) ,
  UNIQUE INDEX `iduser_UNIQUE` (`iduser` ASC) ,
  UNIQUE INDEX `TheUserID_UNIQUE` (`TheUserID` ASC) )
ENGINE = InnoDB
COMMENT = '一般用户表';


-- -----------------------------------------------------
-- Table `TheSQD`.`TheWorkshopMessage`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `TheSQD`.`TheWorkshopMessage` (
  `idworkshop` INT NOT NULL AUTO_INCREMENT COMMENT '车间信息编码' ,
  `TheWorkshopID` VARCHAR(45) NOT NULL COMMENT '车间ID码' ,
  `TheWorkshopName` VARCHAR(45) NOT NULL COMMENT '车间名称' ,
  `TheWorkshopMessage1` VARCHAR(45) NULL ,
  `TheWorkshopMessage2` VARCHAR(45) NULL ,
  PRIMARY KEY (`idworkshop`, `TheWorkshopID`) ,
  UNIQUE INDEX `idworkshop_UNIQUE` (`idworkshop` ASC) ,
  UNIQUE INDEX `TheWorkshopID_UNIQUE` (`TheWorkshopID` ASC) )
ENGINE = InnoDB
COMMENT = '车间信息表';


-- -----------------------------------------------------
-- Table `TheSQD`.`TheEquipmentMessage`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `TheSQD`.`TheEquipmentMessage` (
  `idequipment` INT NOT NULL AUTO_INCREMENT COMMENT '设备原始ID' ,
  `TheEquipmentID` VARCHAR(45) NOT NULL COMMENT '设备ID' ,
  `TheEquipmentName` VARCHAR(45) NOT NULL COMMENT '设备名称' ,
  `TheEquipmentType` VARCHAR(45) NOT NULL COMMENT '设备类型' ,
  `TheEquipmentJX` FLOAT NOT NULL COMMENT '设备绩效值' ,
  `TheEquipmentWorkshop` VARCHAR(45) NOT NULL COMMENT '设备所述车间' ,
  `TheEquipmentMessage1` VARCHAR(45) NULL ,
  `TheEquipmentMessage2` VARCHAR(45) NULL ,
  PRIMARY KEY (`idequipment`, `TheEquipmentID`) ,
  UNIQUE INDEX `TheEquipmentID_UNIQUE` (`TheEquipmentID` ASC) ,
  INDEX `Workshop` (`TheEquipmentWorkshop` ASC) ,
  UNIQUE INDEX `idequipment_UNIQUE` (`idequipment` ASC) ,
  INDEX `EquipemntName` (`TheEquipmentName` ASC) ,
  CONSTRAINT `Workshop`
    FOREIGN KEY (`TheEquipmentWorkshop` )
    REFERENCES `TheSQD`.`TheWorkshopMessage` (`TheWorkshopID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
COMMENT = '设备信息表\n';


-- -----------------------------------------------------
-- Table `TheSQD`.`TheWorkerMessage`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `TheSQD`.`TheWorkerMessage` (
  `idworker` INT NOT NULL AUTO_INCREMENT COMMENT '员工原始编码' ,
  `TheWorkerID` VARCHAR(45) NOT NULL COMMENT '员工ID号码' ,
  `TheWorkerName` VARCHAR(45) NULL COMMENT '员工姓名' ,
  `TheWorkerSex` VARCHAR(45) NULL COMMENT '员工性别' ,
  `TheWorkerOld` INT NULL COMMENT '员工年龄' ,
  `TheWorkerRFID` VARCHAR(45) NOT NULL COMMENT '员工RFID卡号码' ,
  `TheWorkerRFIDPassword` VARCHAR(45) NULL COMMENT '员工RFID卡密码' ,
  `TheWorkerPicture` BLOB NULL COMMENT '员工照片' ,
  `TheWorkerStatus` VARCHAR(45) NULL COMMENT '员工在职状态' ,
  `TheWorkerTelephone` VARCHAR(45) NULL COMMENT '员工联系电话' ,
  `TheworkMessage1` VARCHAR(45) NULL ,
  `TheworkMessage2` VARCHAR(45) NULL ,
  PRIMARY KEY (`idworker`, `TheWorkerID`, `TheWorkerRFID`) ,
  UNIQUE INDEX `TheWorkerID_UNIQUE` (`TheWorkerID` ASC) ,
  UNIQUE INDEX `idworker_UNIQUE` (`idworker` ASC) ,
  UNIQUE INDEX `TheWorkerRFID_UNIQUE` (`TheWorkerRFID` ASC) ,
  INDEX `WorkerName` (`TheWorkerName` ASC) )
ENGINE = InnoDB
COMMENT = '员工信息表';


-- -----------------------------------------------------
-- Table `TheSQD`.`TheProductionMessage`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `TheSQD`.`TheProductionMessage` (
  `idproduction` INT NOT NULL AUTO_INCREMENT COMMENT '生产原始记录码' ,
  `TheProductionDaytime` VARCHAR(45) NOT NULL COMMENT '生产记录时间' ,
  `ThrProductionEquipmentID` VARCHAR(45) NOT NULL COMMENT '生产设备ID号码' ,
  `ThrProductionWorkerRFID` VARCHAR(45) NOT NULL COMMENT '员工ID码' ,
  `ThrProductionWorkergoorback` VARCHAR(45) NOT NULL COMMENT '员工上班签到还是下班签到' ,
  `ThrProductionNumber` BIGINT NOT NULL COMMENT '生产数目' ,
  PRIMARY KEY (`idproduction`) ,
  INDEX `WorkerRFID` (`ThrProductionWorkerRFID` ASC) ,
  INDEX `EquipmentID` (`ThrProductionEquipmentID` ASC) ,
  CONSTRAINT `WorkerRFID`
    FOREIGN KEY (`ThrProductionWorkerRFID` )
    REFERENCES `TheSQD`.`TheWorkerMessage` (`TheWorkerRFID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `EquipmentID`
    FOREIGN KEY (`ThrProductionEquipmentID` )
    REFERENCES `TheSQD`.`TheEquipmentMessage` (`TheEquipmentID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
COMMENT = '生产记录信息表';


-- -----------------------------------------------------
-- Table `TheSQD`.`TheEnvironmentMessage`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `TheSQD`.`TheEnvironmentMessage` (
  `idenvironment` INT NOT NULL ,
  `TheEnvironmentDaytime` DATETIME NOT NULL COMMENT '登记时间' ,
  `TheEnvironmentEquipmentID` VARCHAR(45) NOT NULL COMMENT '设备ID号码' ,
  `TheEnvironmentWorkerRFID` VARCHAR(45) NOT NULL COMMENT '操作人员RFID卡号码' ,
  `TheEnvironmentTemperature` VARCHAR(45) NULL COMMENT '设别环境温度' ,
  `TheEnvironmentHnmidity` VARCHAR(45) NULL COMMENT '设备环境湿度' ,
  `TheEnvironmentNumber` BIGINT NOT NULL ,
  PRIMARY KEY (`idenvironment`) ,
  INDEX `EnvironmentDaytime` (`TheEnvironmentDaytime` ASC) ,
  INDEX `EnEquipmentID` (`TheEnvironmentEquipmentID` ASC) ,
  INDEX `EnWorkerRFID` (`TheEnvironmentWorkerRFID` ASC) ,
  CONSTRAINT `EnEquipmentID`
    FOREIGN KEY (`TheEnvironmentEquipmentID` )
    REFERENCES `TheSQD`.`TheEquipmentMessage` (`TheEquipmentID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `EnWorkerRFID`
    FOREIGN KEY (`TheEnvironmentWorkerRFID` )
    REFERENCES `TheSQD`.`TheWorkerMessage` (`TheWorkerRFID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
COMMENT = '车间环境记录信息表';


-- -----------------------------------------------------
-- Placeholder table for view `TheSQD`.`Workshopmonitoring`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `TheSQD`.`Workshopmonitoring` (`"TheEquipmentID_view"` INT, `"TheEquipmentName_view"` INT, `"TheEnvironmentDaytime_view"` INT, `"TheWorkerRFID_view"` INT, `"TheWorkerName_view"` INT, `"TheEnvironmentTemperature_view"` INT, `"TheEnvironmentHnmidity_view"` INT, `"TheEnvironmentNumber_view"` INT);

-- -----------------------------------------------------
-- Placeholder table for view `TheSQD`.`ProductionInformation`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `TheSQD`.`ProductionInformation` (`"WorkerRFID"` INT, `"WorkerID"` INT, `"WorkerName"` INT, `"EquipmentID"` INT, `"EquipmentName"` INT, `"EquipmentDaytime"` INT, `"ProductionNumber"` INT);

-- -----------------------------------------------------
-- procedure enviromentiformation
-- -----------------------------------------------------

DELIMITER $$
USE `TheSQD`$$
CREATE PROCEDURE `TheSQD`.`enviromentiformation` (EquipmentID  Varchar(45),WorkerRFID Varchar(45),Temperature Varchar(45),Hnmidity Varchar(45),Number Varchar(45))
MODIFIES SQL DATA
BEGIN
    insert into TheSQD.TheEnvironmentMessage(TheEnvironmentDaytime,TheEnvironmentEquipmentID ,TheEnvironmentWorkerRFID,TheEnvironmentTemperature,TheEnvironmentHnmidity,TheEnvironmentNumber)
    values (Now(),EquipmentID,WorkerRFID,Temperature,Hnmidity,Number)
    ;
END

$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure ProductionInformation
-- -----------------------------------------------------

DELIMITER $$
USE `TheSQD`$$
CREATE PROCEDURE `TheSQD`.`ProductionInformation` (EquipmentID varchar(45),WorkerRFID varchar(45),Workergoorback varchar(45),ProductionNumber varchar(45))
MODIFIES SQL DATA
BEGIN
    insert into TheSQD.TheProductionMessage(TheProductionDaytime,ThrProductionEquipmentID,ThrProductionWorkerRFID,ThrProductionWorkergoorback,ThrProductionNumber)
    values(now(),EquipmentID,WorkerRFID,Workergoorback,ProductionNumber)
    ;
END

$$

DELIMITER ;

-- -----------------------------------------------------
-- View `TheSQD`.`Workshopmonitoring`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `TheSQD`.`Workshopmonitoring`;
USE `TheSQD`;
CREATE  OR REPLACE VIEW `TheSQD`.`Workshopmonitoring` AS
select TheEquipmentMessage.TheEquipmentID as "TheEquipmentID_view",
        TheEquipmentMessage.TheEquipmentName as "TheEquipmentName_view",
        TheEnvironmentMessage.TheEnvironmentDaytime as "TheEnvironmentDaytime_view",
        TheWorkerMessage.TheWorkerRFID as "TheWorkerRFID_view",
        TheWorkerMessage.TheWorkerName as "TheWorkerName_view",
        TheEnvironmentMessage.TheEnvironmentTemperature as "TheEnvironmentTemperature_view",
        TheEnvironmentMessage.TheEnvironmentHnmidity as "TheEnvironmentHnmidity_view",
        TheEnvironmentMessage.TheEnvironmentNumber as "TheEnvironmentNumber_view"
From    TheEnvironmentMessage,TheEquipmentMessage,TheWorkerMessage
Where   TheEquipmentMessage.TheEquipmentID = TheEnvironmentMessage.TheEnvironmentEquipmentID and TheWorkerMessage.TheWorkerRFID = TheEnvironmentMessage.TheEnvironmentWorkerRFID ;
;

-- -----------------------------------------------------
-- View `TheSQD`.`ProductionInformation`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `TheSQD`.`ProductionInformation`;
USE `TheSQD`;
CREATE  OR REPLACE VIEW `TheSQD`.`ProductionInformation` AS
select  TheWorkerMessage.TheWorkerRFID as "WorkerRFID",
        TheWorkerMessage.TheWorkerID as "WorkerID",
        TheWorkerMessage.TheWorkerName as "WorkerName" ,
        TheEquipmentMessage.TheEquipmentID as "EquipmentID",
        TheEquipmentMessage.TheEquipmentName as "EquipmentName",
        TheProductionMessage.TheProductionDaytime as "EquipmentDaytime",
        TheProductionMessage.ThrProductionNumber as "ProductionNumber"
FROM    TheWorkerMessage,TheEquipmentMessage,TheProductionMessage
where   TheWorkerMessage.TheWorkerRFID =  TheProductionMessage.ThrProductionWorkerRFID and TheEquipmentMessage.TheEquipmentID = TheProductionMessage.ThrProductionEquipmentID ;
;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
