class Node:
    def __init__(self, idx):
        self.idx = idx
        self.excess = 0
        self.height = 0
        self.neighbours = []

class Edge:
    def __init__(self, node_u, node_v, capacity):
        self.node_u = node_u
        self.node_v = node_v
        self.capacity = capacity
        self.flow = 0
        
class Graph:
    def __init__(self, N, M, nodes, edges, source, drain):
        self.N = N
        self.M = M
        self.nodes = nodes
        self.edges = edges
        self.source = source
        self.drain = drain
        self.excesses = []

def can_push(node, graph):
    for neighbour in node.neighbours:
        if node.height > neighbour.height:
            return neighbour
    return None

def push(graph, node_u, node_v):
    if node_u.idx < node_v.idx:
        edge = graph.edges[node_u.idx, node_v.idx]
        delta = min(node_u.excess, edge.capacity-edge.flow)
        edge.flow += delta
    else:
        edge = graph.edges[node_v.idx, node_u.idx]
        delta = min(node_u.excess, edge.flow)
        edge.flow -= delta
    node_u.excess -= delta
    node_v.excess += delta

def relabel(node_u):
    node_u.h += 1

def node_with_excess(graph):
    for i in range(1, graph.N-1):
        node = graph.nodes[i]
        if node.excess != 0:
            return node
    return None
    
def preflow_push(graph):
    source = graph.nodes[graph.source]
    source.height = graph.N
    for node in source.neighbours:
        print("enters shit")
        edge = graph.edges[(source.idx, node.idx)]
        edge.flow = edge.capacity 
        edge.node_v.excess = edge.capacity 
        # graph.excesses.append(edge.node_v)
        source.excess -= edge.capacity
    while node_with_excess(graph) != None:
        node = node_with_excess(graph)
        neighbour = can_push(node, graph)
        if neighbour != None:
            push(graph, node, neighbour)
        else:
            relabel(node)
    return graph

def main():
    N, M, C, P = map(int, input().split(" "))
    nodes = []
    edges = dict()
    for i in range(N):
        node = Node(i)
        nodes.append(node)

    for i in range(M):
        u, v, c = map(int, input().split(" "))
        node_u = Node(u)
        node_v = Node(v)
        edge = Edge(node_u, node_v, c)
        edges[(u,v)] = edge
        nodes[u].neighbours.append(node_v)
        nodes[v].neighbours.append(node_u)

    graph = Graph(N, M, nodes, edges, 0, N-1)
    graph2 = preflow_push(graph)
    for key in graph2.edges:  
        print(graph2.edges[key].node_u.idx, graph2.edges[key].node_v.idx)
        print(graph2.edges[key].flow)        

main()
