function binary_search(list, item) {
  var low = 0, mid, guess
  var high = list.length - 1
  
  while (low <= high) {
    mid = Math.trunc((low + high) / 2)
    guess = list[mid]
    if (guess === item) {
      return mid
    }
    if (guess < item) {
      low = mid + 1
    } else {
      high = mid - 1
    }
  }
  return -1
}

var arr = [1, 2, 5, 7, 8, 9]
console.log(binary_search(arr, 8))