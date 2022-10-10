def breadth_first_print(graph, source):
    queue = [source]
    
    while len(queue) > 0:
        curr = queue.pop(0)
        print(curr)
        for ele in graph[curr]:
            queue.append(ele)


graph = {
    'a': ['c', 'b'],
    'b': ['d'],
    'c': ['e'],
    'd': ['f'],
    'e': [],
    'f': []
}

breadth_first_print(graph, 'a')
