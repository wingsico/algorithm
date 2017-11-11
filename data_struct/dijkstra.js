var graph = {}
var costs = {}
var parents = {}

graph.start = {}
graph.start.a = 6
graph.start.b = 2

graph.a = {}
graph.a.fin = 1

graph.b = {}
graph.b.a = 3
graph.b.fin = 5

graph.fin = {}

costs.a = 6
costs.b = 2
costs.fin = Infinity

parents.a = 'start'
parents.b = 'start'
parents.fin = null

var processed = []

function dijkstra() {
  var node = findLowestCostNode(costs)
  while (node) {
    var cost = costs[node]
    var neibghbors = graph[node]
    for (let key of Object.keys(neibghbors)) {
      var new_cost = cost + neibghbors[key]
      if (costs[key] > new_cost) {
        costs[key] = new_cost
        parents[key] = node
      }
    }
    processed.push(node)
    node = findLowestCostNode(costs)
  }
}

function findLowestCostNode(costs) {
  var lowestCost = Infinity
  var lowestCostNode = null
  for (let node of Object.keys(costs)) {
    let cost = costs[node]
    if (cost < lowestCost && !(processed.includes(node))) {
      lowestCost = cost
      lowestCostNode = node
    }
  }
  return lowestCostNode
}

function printPath(node) {
  if (node === 'start') {
    return 'start'
  }
  return printPath(parents[node]) + '->' + node
}

dijkstra()
console.log(printPath('fin'))