// 顺序表
// 创建一个空顺序表
function createArray() {
    var array = new Array();
    return array;
}
// 初始化一个顺序表
function initArray(list) {
    if (list instanceof Array) {
        var length = 15;
        for (var i = 0; i < length; i++) {
            list[i] = i + 1;
        }
        return list;
    }
}
function getElem(list, index) {
    if (index > list.length + 1 || index < 1) {
        return -1;
    }
    return list[index - 1];
}
function getIndex(list, value) {
    var i = 0;
    for (; i < getLength(list); i++) {
        if (list[i] === value) {
            return i;
        }
    }
}
function insertElem(list, index, item) {
    var i;
    var len = getLength(list);
    for (i = len - 1; i >= index - 1; i--) {
        list[i + 1] = list[i];
    }
    list[index - 1] = item;
    return list;
}
function deleteElem(list, index) {
    if (index > getLength(list) + 1 || index < 1) {
        return -1;
    }
    var i = index - 1;
    var len = getLength(list);
    var e = list[i];
    for (; i < len; i++) {
        list[i] = list[i + 1];
    }
    list.length--;
    return e;
}
function getLength(list) {
    var len = list.length ? list.length : -1;
    return len;
}
function consAll(list) {
    for (var i = 0; i < getLength(list); i++) {
        console.log(list[i]);
    }
}
// 测试函数
function test() {
    var sqList = createArray();
    console.log('创建空顺序表：' + sqList);
    initArray(sqList);
    console.log('初始化一个数字类型顺序表：' + sqList);
    var elem = getElem(sqList, 5);
    console.log('获取第五个元素：' + elem);
    var index = getIndex(sqList, 6);
    console.log('获取值为6的游标：' + index);
    insertElem(sqList, 4, 999);
    console.log('在第四个位置插入999：' + sqList);
    var e = deleteElem(sqList, 4);
    console.log('删除第四个位置的元素：' + sqList, e);
    console.log('表长为：' + getLength(sqList));
    console.log('所有元素为：');
    consAll(sqList);
}
test();
