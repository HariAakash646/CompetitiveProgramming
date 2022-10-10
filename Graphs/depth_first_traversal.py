def depth_first_print(graph, source):
    stack = [source]
    
    while len(stack) > 0:
        curr = stack.pop(-1)
        print(curr)
        for ele in graph[curr]:
            stack.append(ele)


graph = {
    'a': ['b', 'c'],
    'b': ['d'],
    'c': ['e'],
    'd': ['f'],
    'e': [],
    'f': []
}

depth_first_print(graph, 'a')
