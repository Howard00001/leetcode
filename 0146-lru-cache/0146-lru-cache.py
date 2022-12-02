# class Node:
#     def __init__(self, key, value):
#         self.key = key
#         self.value = value
#         self.prev = None
#         self.next = None

# class LRUCache:

#     def __init__(self, capacity: int):
#         self.capacity = capacity
#         self.cache = {}
#         self.left = Node('#','#')
#         self.right = Node('#','#')
#         self.left.next = self.right
#         self.right.prev = self.left
        
#     def splice(self, target):
#         # move target to first
#         target.prev.next = target.next
#         target.next.prev = target.prev
#         target.next = self.left.next
#         target.prev = self.left
#         self.left.next.prev = target
#         self.left.next = target
    
#     def erase(self, target):
#         target.prev.next = target.next
#         target.next.prev = target.prev
        
#     def push_front(self, target):
#         target.prev = self.left
#         target.next = self.left.next
#         self.left.next.prev = target
#         self.left.next = target

#     def get(self, key: int) -> int:
#         if key not in self.cache:
#             return -1
#         self.splice(self.cache[key])
#         return self.cache[key].value
        
#     def put(self, key: int, value: int) -> None:
#         print(len(self.cache))
#         if key in self.cache:
#             self.cache[key].value = value
#             self.splice(self.cache[key])
#             return
#         if self.capacity == len(self.cache):
#             d = self.right.prev
#             self.erase(d)
#             del self.cache[d.key]
#         self.cache[key] = Node(key, value)
#         self.push_front(self.cache[key])
class Node:
    def __init__(self, key, value):
        self.key, self.value = key, value
        self.prev = self.next = None
    
class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left
    
    def insert(self, node):
        prev, right = self.right.prev, self.right
        prev.next = right.prev = node
        node.next, node.prev = right, prev 
        
    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])
        
        if self.cap < len(self.cache):
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)