function locateElem(arr, e) {
  var i = arr[0].next
  while (i && arr[i].data !== e) {
    i = arr[i].next
  }
  return i
}

let LS = [
  {
    data: '3',
    next: 4
  },
  {
    data: '1',
    next: 2
  },
  {
    data: '2',
    next: 3
  },
  {
    data: '8',
    next: null
  },
  {
    data: '4',
    next: 1
  }
]

console.log(locateElem(LS, '4'))