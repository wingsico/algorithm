function findSmallest(arr) {
  var smallest = arr[0]
  var smallestIndex = 0
  for (let i = 1, len = arr.length; i < len; i++){
    if (arr[i] < smallest) {
      smallest = arr[i]
      smallestIndex = i
    }
  }
  <re></re>turn smallestIndex
}

function selectionSort(arr) {
  var newArr = Array.of()
  for (let i = 0, len = arr.length; i < len; i++) {
    smallest = findSmallest(arr)
    newArr.push(...arr.splice(smallest, 1))
  }
  return newArr
}

let arr = [2, 5, 3, 5, 8, 3, 8, 4, 10, 7]

console.log(selectionSort(arr))