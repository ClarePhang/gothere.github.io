---
layout: post
title: MongoDB最佳实践笔记
published: true
category: nosql
tags: [mongodb, maizi]
---

主要还得看官网

1.  安装命令
•   sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 7F0CEB10
•   echo 'deb http://downloads-distro.mongodb.org/repo/ubuntu-upstart dist 10gen' | sudo tee /etc/apt/sources.list.d/mongodb.list
•   sudo apt-get update
•   sudo apt-get install -y mongodb-org

Try MongoDB: http://try.mongodb.org

              停止服务： 
                   sudo service mongod stop
              启动服务：
                   sudo service mongod start
              切换数据库
                   use  数据库名  

2.  插入命令

插入数据到students collection
db.students.insert({name: "张三", school: {name: "清华大学", city: "北京"}, age: 19, gpa: 3.97})

db.students.insert({name: "李四", school: {name: "北京大学", city: "北京"}, age: 20, gpa: 3.3})

db.students.insert({name: "王二", school: {name: "交通大学", city: "上海"}, age: 22, gpa: 3.68})

db.students.insert({name: "小牛", school: {name: "哈工大", city: "哈尔滨"}, age: 21, gpa: 3.50})

db.students.insert({name: "小马", school: {name: "交通大学", city: "西安"}, age: 21, gpa: 3.70})

db.students.insert({name: "小朱"})


3.  查询命令

值精确匹配的查询
db.students.find({name: "张三"})
两个条件（逻辑与）
db.students.find({"school.name": "交通大学", "school.city": "西安"})
通过ID
db.students.find({"_id" : ObjectId("542717c4a47ef7e2347ffbe0")})
逻辑或
db.students.find({$or: [{"school.name": "交通大学"}, {"school.city": "北京"}]})
逻辑与
db.students.find({$and: [{"school.name": "交通大学"}, {"school.city": "北京"}]})
大于小于等
db.students.find({age:{$lte:20}})
db.students.find({age:{$gte:20}})
db.students.find({age:{$lt:20}})
db.students.find({age:{$gt:20}})
db.students.find({age:{$ne:20}})

关于数据字段存在与否的查询
db.students.find({school:{$exists:false}})

基于正则表达式的逻辑查询
db.students.find({name: /^小/})
db.students.find({name: /.*四/})


3.  Update命令



4.  Bson Document
Data Model设计参考资料
http://docs.mongodb.org/manual/data-modeling/


6.  内嵌数组查询
db.students.insert({name: "张三", school: {name: "清华大学", city: "北京"}, courses:[{name:"MongoDB", grade:88, quiz:[9,8,9,10]},{name:"Java", grade:99,quiz:[3,2,1,5]}], age: 19, gpa: 3.97})

db.students.insert({name: "李四", school: {name: "北京大学", city: "北京"}, courses:[{name:"MongoDB", grade:86, quiz:[5,4,3,7]},{name:"Java", grade:92}, {name:"C++", grade:65}], age: 20, gpa: 3.3})

db.students.insert({name: "王二", school: {name: "交通大学", city: "上海"}, age: 22, gpa: 3.68})

db.students.insert({name: "小牛", school: {name: "哈工大", city: "哈尔滨"}, courses:[{name:"Java", grade:81}, {name:"C++", grade:99}], age: 21, gpa: 3.50})

db.students.insert({name: "小马", school: {name: "交通大学", city: "西安"}, courses:[{name:"MongoDB", grade:96, quiz:[5,4,3,7]}], age: 21, gpa: 3.70})

db.students.insert({name: "小朱"})


7.  地理位置查询
db.pois.insert({name:"AAA Store", loc:{type:"Point", coordinates:[70,30]}})
db.pois.insert({name:"BBB Bank", loc:{type:"Point", coordinates:[69.99,30.01]}})
db.pois.insert({name:"CCC Park", loc:{type:"Polygon", coordinates:[[[70,30],[71,31],[71,30],[70,30]]]}})
db.pois.insert({name:"DDD Forest", loc:{type:"Polygon", coordinates:[[[65,68],[67,68],[67,69],[65,68]]]}})

附近地点查询
db.pois.find({loc:{
  $near: {
     $geometry: {
        type: "Point" ,
        coordinates: [ 70 , 30 ]
     },
     $maxDistance: 1000000
  }
}})

区域内地点查询
db.pois.find({loc:{ 
    $geoWithin:{ 
        $geometry :{ 
            type : "Polygon",
                        coordinates : [[[70,30],[71,31],[71,30],[70,30]]]
                } 
    } 
}})

使用geoNear command
db.runCommand(
   {
     geoNear: "pois",
     near: { type: "Point", coordinates: [ 70, 30 ] },
     spherical: true,
     minDistance: 3000,
     maxDistance: 7000
   }
)

9.  全文搜索

db.text.insert({content:"text performs a text search on the content of the fields indexed with a text index."})
db.text.insert({content:"When dealing with a small number of documents, it is possible for the full-text-search engine to directly scan the contents of the documents with each query, a strategy called 'serial scanning.' This is what some rudimentary tools, such as grep, do when searching."})
db.text.insert({content:"Soros enjoys playing mongo."})
db.text.insert({content:"Why don't you use mongo-db?"})





10. 学生成绩Group命令
db.students.group({
        key:{age:1},
        cond: {age:{$exists:true}},
        reduce:function(cur, result) { result.count += 1; result.total_gpa += cur.gpa; result.ava_gpa = result.total_gpa / result.count;},
        initial: { count: 0 , total_gpa: 0}
    })

11. 数据聚合 -- 流水线
各年龄段平均GPA计算和排序

db.students.aggregate([
    {$match:{age:{$exists:true}}}, 
    {$group:{_id:"$age", count: {$sum:1}, total_gpa:{$sum:"$gpa"}}},
    {$project: {_id:1, ava_gpa:{$divide: ["$total_gpa", "$count"]}}},
    {$sort:{ava_gpa:1}}
    ])

选课数量统计
db.students.aggregate(
    [
        {$match: {age:{$exists:true},courses:{$exists:true}}},
        {$project: {age:1, courses_count:{$size:"$courses"}}},
        {$group: {_id:"$age", acc:{$avg:"$courses_count"}}},
        {$sort:{acc:-1}}
    ]
)

选课不同种类统计
db.students.aggregate(
    [
        {$match: {age:{$exists:true},courses:{$exists:true}}},
        {$project: {_id:-1, age:1, "courses.name":1}},
        {$unwind:"$courses"},
        {$group: {_id:"$age", courses:{$addToSet:"$courses.name"}}},
        {$project: {_id:1, cc:{$size:"$courses"}}},
        {$sort: {cc:-1}}
    ]
)


12 数据聚合MapReduce

按age分组计算平均gpa (错误)
db.students.mapReduce(
    function(){
        emit(this.age, this.gpa);
    },
    
    function(key, values){
        return Array.sum(values)/values.length;
    },
    
    {
        query : {age : {$exists : true}, gpa : {$exists : true}},
        out : {inline:1}
    }
)

按age分组计算平均gpa (正确)
db.students.mapReduce(
    function(){
        emit(this.age, {gpa:this.gpa, count:1});
    },    
    function(key, values){
    reducedVal = { gpa: 0, count: 0 };
        for (var i = 0; i < values.length; i++) {
            reducedVal.count += values[i].count;
                reducedVal.gpa += values[i].gpa;
        }
        return reducedVal;                  
    },    
    {
        query : {age : {$exists : true}, gpa : {$exists : true}},
        out : {inline:1},
    finalize:function(key, value){
        value.avg = value.gpa / value.count;
        return value;
    }   
    }
)

课程推荐
db.students.mapReduce(
    function(){
        var course_names = this.courses.map(
            function(course){
                return course.name
            });
        var intersection_names = course_names.filter(
            function(c_name){
                return params.indexOf(c_name) != -1
            });
        var diff_names = course_names.filter(
            function(c_name){
                return params.indexOf(c_name) == -1
            });
        diff_names.forEach(
            function(c_name){
                emit(c_name, intersection_names.length / course_names.length)
            });
    },    
    function(key, values){
    var total = values.reduce(function(p, c) {
            return p + c;
        });

        return total;                   
    },    
    {
        query : {courses : {$exists : true}},
        out : {inline:1},
    scope: {params: ["MongoDB"]}    
    }
)

推荐课程（使用Pipeline）
db.students.aggregate([
    {$project:{"c_names":{$map:{input: "$courses", as:"course", in:"$$course.name"}}}},
    {$project:{c_names:1, 
        intersection_names:{$setIntersection:[["MongoDB"], "$c_names"]},
        diff_names:{$setDifference:["$c_names", ["MongoDB"]]}
        }},
    {$unwind:"$diff_names"},
    {$project:{diff_names:1, score: {$divide:[{$size: "$intersection_names"}, {$size:"$c_names"}]}}},
    {$group: {_id:"$diff_names", score: {$sum: "$score"}}}
    
])


