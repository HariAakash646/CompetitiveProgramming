# depth first
def has_path(graph, src, dst):
  if src == dst:
    return True
  for i in graph[src]:
    if has_path(graph, i, dst):
      return True
  return False

# breadth first
def has_path(graph, src, dst):
  queue = [src]
  while len(queue) > 0:
    curr = queue.pop(0)
    if curr == dst:
      return True
    for ele in graph[curr]:
      queue.append(ele)
  return False
    
