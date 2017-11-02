// 顺序表
// 创建一个空顺序表
function createArray():any[] {
  var array = new Array()
  return array
}

// 初始化一个顺序表
function initArray(list: any[]): number[] {
  if (list instanceof Array) {
    var length = 15
    for (let i = 0; i < length; i++) {
      list[i] = i + 1
    }
    return list
  }
}

function getElem(list: number[], index: number):number {
  if (index > list.length + 1 || index < 1) {
    return -1
  }
  
  return list[index - 1]
}

function getIndex(list: number[], value: number): number {
  let i: number = 0
  for (; i < getLength(list); i++) {
    if (list[i] === value) {
      return i
    }
  }
}

function insertElem(list: number[], index:number, item: number): number[] {
  let i: number
  let len = getLength(list)
  for (i = len - 1; i >= index - 1; i--){
    list[i+1] = list[i]
  }
  list[index - 1] = item
  return list
}

function deleteElem(list: number[], index: number): number {
  if (index > getLength(list) + 1 || index < 1) {
    return -1
  }
  let i: number = index - 1
  let len: number = getLength(list)
  let e = list[i]
  for (; i < len; i++){
    list[i] = list[i + 1]
  }
  list.length--
  return e
}

function getLength(list: number[]): number{
  let len: number = list.length ? list.length : -1
  return len
}

function consAll(list: number[]): void {
  for (let i: number = 0; i < getLength(list); i++) {
    console.log(list[i])
  }
}


// 测试函数

function test():void {
  let sqList = createArray()
  console.log('创建空顺序表：' + sqList)
  initArray(sqList)
  console.log('初始化一个数字类型顺序表：' + sqList)
  let elem = getElem(sqList, 5)
  console.log('获取第五个元素：' + elem)
  let index = getIndex(sqList, 6)
  console.log('获取值为6的游标：' + index)
  insertElem(sqList, 4, 999)
  console.log('在第四个位置插入999：' + sqList)
  let e = deleteElem(sqList, 4)
  console.log('删除第四个位置的元素：' + sqList, '被删除的元素：' + e)
  console.log('表长为：' + getLength(sqList))
  console.log('所有元素为：')
  consAll(sqList)
}


test()




