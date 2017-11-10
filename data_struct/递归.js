function quicksort(ary) {
  if (ary.length < 2) {
    return ary
  }
  var random = Math.floor(Math.random() * ary.length)
  var pivor = ary[random]
  console.log(pivor)
  ary.splice(random, 1)
  var less = ary.filter(aryItem => {
    return aryItem <= pivor
  })
  
  var greater = ary.filter(aryItem => {
    return aryItem > pivor
  })

  return [...quicksort(less), pivor, ...quicksort(greater)]
}

var array = [5, 4, 3, 2, 1]

console.log(quicksort([...array]))

function Sum(ary) {
  console.log(ary)
  if (ary.length < 2) {
    return ary[0]
  }
  return ary.pop() + Sum(ary)
}
console.log(Sum([...array]))


function Max(ary) {
  if (ary.length < 2) {
    return ary[0]
  }
  var val = ary.pop()
  var max = Max(ary)
  return (max > val ? max : val)
}

console.log(Max([...array]))

