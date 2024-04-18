def build_graph(edges):
  graph = {}
  for (a, b) in edges:
    graph[a] = graph.get(a, []) + [b]
    graph[b] = graph.get(b, []) + [a]
  return graph

def undirected_path(edges, node_A, node_B):
  graph = build_graph(edges)
  done = []
  stack = [node_A]
  while len(stack) > 0:
    curr = stack.pop(-1)
    if curr in done:
      continue
    done.append(curr)
    if curr == node_B:
      return True
    for ele in graph[curr]:
      stack.append(ele)
  return False
