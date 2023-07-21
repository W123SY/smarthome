# -*- coding: UTF-8 -*-
from flask import Flask, request, render_template, jsonify
import pymysql.cursors
from sqlalchemy import func
import json
from flask_cors import *

app = Flask(__name__)


def func(sql, m='r'):
    py = pymysql.connect(host='localhost',
                         user='root',
                         password='dD392817',
                         database='smarthome',
                         charset='utf8',
                         cursorclass=pymysql.cursors.DictCursor)
    cursor = py.cursor()
    try:
        cursor.execute(sql)
        if m == 'r':
            data = cursor.fetchall()
        elif m == 'w':
            py.commit()
            data = cursor.rowcount
    except:
        data = m
        py.rollback()
    py.close()
    return data


@app.route("/light", methods=["POST", "GET"])
@cross_origin()
def light():
    # data = {"place":"xxx"}
    data = dict(request.get_json())
    if data['place'] == 'all':
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'light' AND Place = '{place}';".format(**data)
        func(sql, 'w')
        sql = "UPDATE Light SET LightFlag=1;"
    elif data['place'] == 'none':
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'light' AND Place = '{place}';".format(**data)
        func(sql, 'w')
        sql = "UPDATE Light SET LightFlag=0;"
    elif data['place'] == 'intellgence':
        sql = "UPDATE changeflag SET flag = 0 WHERE type = 'light' AND Place = '{place}';".format(**data)
        func(sql, 'w')
        sql = "SELECT Mode FROM Light WHERE Place = '5';"
        check = func(sql, 'r')
        check2 = check[0]
        if check2['Mode'] == 0:
            sql = "UPDATE Light SET Mode=1 WHERE Place = '5';"
            func(sql, 'w')
        else:
            sql = "UPDATE Light SET Mode=0 WHERE Place = '5';"
            func(sql, 'w')
        sql = "UPDATE Light SET LightFlag=0 WHERE Place = '5';"
    elif data['place'] == 'LightSensing':
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'light' AND Place = '{place}';".format(**data)
        func(sql, 'w')
        sql = "SELECT Mode FROM Light WHERE Place = '1';"
        check = func(sql, 'r')
        check2 = check[0]
        if check2['Mode'] == 0:
            sql = "UPDATE Light SET Mode=2 WHERE Place = '3' OR Place = '2' OR Place = '1';"
            func(sql, 'w')
        else:
            sql = "UPDATE Light SET Mode=0 WHERE Place = '3' OR Place = '2' OR Place = '1';"
            func(sql, 'w')
        sql = "UPDATE Light SET LightFlag=1 WHERE Place = '3' OR Place = '2' OR Place = '1';"
    else:
        sql = "UPDATE changeflag SET flag = 1 WHERE Place = '{place}' AND type = 'light';".format(**data)
        func(sql, 'w')
        sql = "UPDATE Light SET LightFlag=1-LightFlag WHERE Place = '{place}';".format(**data)
    func(sql, m='w')
    sql = "SELECT * FROM Light;"
    return json.dumps(func(sql, 'r'))


@app.route("/air", methods=["POST", "GET"])
@cross_origin()
def air():
    # data = {"changeflag":xxx, "temp":xxx or "mode":xxx or "wind":xxx, "place":"xxx"}
    data = dict(request.get_json())
    if data['place'] == 'all':
        sql = "UPDATE air SET Flag=1;"
        func(sql, 'w')
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'air';".format(**data)
        func(sql, 'w')
        sql = "SELECT * FROM air;"
        return json.dumps(func(sql, 'r'))
    elif data['place'] == 'none':
        sql = "UPDATE air SET Flag=0;"
        func(sql, 'w')
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'air';".format(**data)
        func(sql, 'w')
        sql = "SELECT * FROM air;"
        func(sql, 'r')
        return json.dumps(func(sql, 'r'))
    else:
        sql = "UPDATE changeflag SET flag = 1 WHERE Place = '{place}' AND type = 'air';".format(**data)
        func(sql, 'w')
        # changeflag 0:开关空调 1：调整温度 2：调整模式 3：调整风速
        if data['changeflag'] == 1:
            # temp 1：上升 其它：下降
            if data['temp'] == 1:
                sql = "UPDATE air SET Temp = Temp+1 WHERE Place = '{place}';".format(**data)
            else:
                sql = "UPDATE air SET Temp = Temp-1 WHERE Place = '{place}';".format(**data)
        elif data['changeflag'] == 2:
            # mode 1:制冷 2：制热 3：通风
            sql = "UPDATE air SET Mode = {mode} WHERE Place = '{place}';".format(**data)
        elif data['changeflag'] == 3:
            # wind 1：低风 2：中风 3：高风
            sql = "UPDATE air SET WindSpeed = {wind} WHERE Place = '{place}';".format(**data)
        elif data['changeflag'] == 0:
            sql = "UPDATE air SET Flag=1-Flag WHERE Place = '{place}';".format(**data)
        func(sql, 'w')
        sql = "SELECT * FROM air WHERE place = '{place}';".format(**data)
        return json.dumps(func(sql, 'r'))


@app.route("/curtain",  methods=["POST", "GET"])
@cross_origin()
def curtain():
    # data = {"place":"xxx", "mode":xxx}
    data = dict(request.get_json())
    sql = "SELECT Mode FROM Curtain;"
    check = func(sql, 'r')
    check2 = check[0]
    if data['mode'] == 2:
        if check2['Mode'] == 1:
            sql = "UPDATE Curtain SET Mode = 2 WHERE Place = '0';"
            func(sql, 'w')
            sql = "UPDATE changeflag SET flag = 1 WHERE Place = '0' AND type = 'curtain';"
            func(sql, 'w')
    if data['mode'] == 1:
        if check2['Mode'] == 2:
            sql = "UPDATE Curtain SET Mode = 1 WHERE Place = '0';"
            func(sql, 'w')
            sql = "UPDATE changeflag SET flag = 1 WHERE Place = '0' AND type = 'curtain';"
            func(sql, 'w')
    # mode 1:下降,窗帘关闭 2：上升，窗帘打开
    sql = "SELECT * FROM curtain;"
    return json.dumps(func(sql, 'r'))


@app.route("/lock",  methods=["POST", "GET"])
@cross_origin()
def lock():
    # data = {"flag":xxx}
    data = dict(request.get_json())
    sql = "UPDATE changeflag SET flag = 1 WHERE type = 'lock';".format(**data)
    func(sql, 'w')
    # flag 0:开锁 1：上锁
    sql = "UPDATE lock SET flag = {flag};".format(**data)
    func(sql, 'w')
    sql = "SELECT * FROM Lock;"
    return json.dumps(func(sql, 'r'))


@app.route("/camera",  methods=["POST", "GET"])
def camera():
    # data = {"flag":xxx}
    data = dict(request.get_json())
    sql = "UPDATE changeflag SET flag = 1 WHERE type = 'camera';".format(**data)
    func(sql, 'w')
    # flag 0:关闭摄像头 1：打开摄像头
    sql = "UPDATE camera SET flag = {flag};".format(**data)
    func(sql, 'w')
    return sql


@app.route("/global", methods=["POST"])
def glo():
        # data = {"mode":"xxx"}
    data = dict(request.get_json())
    if data['mode'] == 'sleep':
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'light' AND Place = 'none';"
        func(sql, 'w')
        sql = "SELECT Mode FROM Light WHERE Place = '5';"
        check = func(sql, 'r')
        check2 = check[0]
        if check2['Mode'] == 0:
            sql = "UPDATE Light SET Mode=1 WHERE Place = '5';"
            func(sql, 'w')
            sql = "UPDATE changeflag SET flag = 1 WHERE Place = 'intellgence' AND type = 'light';"
            func(sql, 'w')
        sql = "UPDATE Light SET LightFlag=0;"
        func(sql, 'w')
        sql = "SELECT Mode FROM Curtain;"
        check = func(sql, 'r')
        check2 = check[0]
        if check2['Mode'] == 2:
            sql = "UPDATE Curtain SET Mode = 1 WHERE Place = '0';"
            func(sql, 'w')
            sql = "UPDATE changeflag SET flag = 1 WHERE Place = '0' AND type = 'curtain';"
            func(sql, 'w')
    if data['mode'] == 'leave':
        sql = "UPDATE air SET Flag=0;"
        func(sql, 'w')
        sql = "UPDATE Light SET LightFlag=0;"
        func(sql, 'w')
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'light' AND Place = 'none';"
        func(sql, 'w')
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'air';"
        func(sql, 'w')
        sql = "UPDATE changeflag SET flag = 1 WHERE type = 'light' AND Place = 'invade';"
        func(sql,'w')
    return sql


@app.route("/humiture")
@cross_origin()
def humiture():
    sql = "SELECT * FROM humiture"
    return json.dumps(func(sql, 'r'))


@app.route("/alarm")
@cross_origin()
def alarm():
    sql = "SELECT * FROM alarm"
    return json.dumps(func(sql, 'r'))


app.run(host="0.0.0.0")

