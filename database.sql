/*
Navicat MySQL Data Transfer

Source Server         : 4GSmartHome
Source Server Version : 50740
Source Host           : 114.116.248.29:3306
Source Database       : smarthome

Target Server Type    : MYSQL
Target Server Version : 50740
File Encoding         : 65001

Date: 2023-04-17 22:42:59
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `air`
-- ----------------------------
DROP TABLE IF EXISTS `air`;
CREATE TABLE `air` (
  `Place` char(255) NOT NULL,
  `Temp` int(11) NOT NULL DEFAULT '25',
  `Mode` int(11) NOT NULL DEFAULT '0',
  `WindSpeed` int(11) NOT NULL DEFAULT '0',
  `flag` tinyint(4) NOT NULL,
  PRIMARY KEY (`Place`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of air
-- ----------------------------
INSERT INTO `air` VALUES ('1', '25', '2', '3', '0');
INSERT INTO `air` VALUES ('2', '25', '2', '3', '0');
INSERT INTO `air` VALUES ('3', '25', '2', '3', '0');

-- ----------------------------
-- Table structure for `alarm`
-- ----------------------------
DROP TABLE IF EXISTS `alarm`;
CREATE TABLE `alarm` (
  `type` char(255) NOT NULL DEFAULT '',
  `flag` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of alarm
-- ----------------------------
INSERT INTO `alarm` VALUES ('fire', '1');
INSERT INTO `alarm` VALUES ('invade', '1');

-- ----------------------------
-- Table structure for `changeflag`
-- ----------------------------
DROP TABLE IF EXISTS `changeflag`;
CREATE TABLE `changeflag` (
  `type` char(255) NOT NULL,
  `place` char(255) NOT NULL,
  `flag` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`type`,`place`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of changeflag
-- ----------------------------
INSERT INTO `changeflag` VALUES ('air', '1', '0');
INSERT INTO `changeflag` VALUES ('air', '2', '0');
INSERT INTO `changeflag` VALUES ('air', '3', '0');
INSERT INTO `changeflag` VALUES ('curtain', '0', '0');
INSERT INTO `changeflag` VALUES ('light', '1', '0');
INSERT INTO `changeflag` VALUES ('light', '2', '0');
INSERT INTO `changeflag` VALUES ('light', '3', '0');
INSERT INTO `changeflag` VALUES ('light', '4', '0');
INSERT INTO `changeflag` VALUES ('light', '5', '0');
INSERT INTO `changeflag` VALUES ('light', '6', '0');
INSERT INTO `changeflag` VALUES ('light', 'all', '0');
INSERT INTO `changeflag` VALUES ('light', 'invade', '0');
INSERT INTO `changeflag` VALUES ('light', 'LightSensing', '0');
INSERT INTO `changeflag` VALUES ('light', 'none', '0');
INSERT INTO `changeflag` VALUES ('lock', '0', '0');

-- ----------------------------
-- Table structure for `Curtain`
-- ----------------------------
DROP TABLE IF EXISTS `Curtain`;
CREATE TABLE `Curtain` (
  `Place` char(255) NOT NULL,
  `Mode` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Place`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of Curtain
-- ----------------------------
INSERT INTO `Curtain` VALUES ('0', '1');

-- ----------------------------
-- Table structure for `humiture`
-- ----------------------------
DROP TABLE IF EXISTS `humiture`;
CREATE TABLE `humiture` (
  `attribute` char(255) NOT NULL DEFAULT '',
  `data` float DEFAULT '15',
  PRIMARY KEY (`attribute`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of humiture
-- ----------------------------
INSERT INTO `humiture` VALUES ('humidity', '43.1');
INSERT INTO `humiture` VALUES ('temperature', '22.9');

-- ----------------------------
-- Table structure for `Light`
-- ----------------------------
DROP TABLE IF EXISTS `Light`;
CREATE TABLE `Light` (
  `Place` char(255) NOT NULL,
  `LightFlag` int(11) NOT NULL DEFAULT '0',
  `Mode` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Place`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of Light
-- ----------------------------
INSERT INTO `Light` VALUES ('1', '0', '0');
INSERT INTO `Light` VALUES ('2', '0', '0');
INSERT INTO `Light` VALUES ('3', '0', '0');
INSERT INTO `Light` VALUES ('4', '0', '0');
INSERT INTO `Light` VALUES ('5', '0', '0');

-- ----------------------------
-- Table structure for `Lock`
-- ----------------------------
DROP TABLE IF EXISTS `Lock`;
CREATE TABLE `Lock` (
  `Flag` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`Flag`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- ----------------------------
-- Records of Lock
-- ----------------------------
INSERT INTO `Lock` VALUES ('0');
