class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.left = Node('#','#')
        self.right = Node('#','#')
        self.left.next = self.right
        self.right.prev = self.left
        
    def splice(self, target):
        # move target to first
        target.prev.next = target.next
        target.next.prev = target.prev
        target.next = self.left.next
        target.prev = self.left
        self.left.next.prev = target
        self.left.next = target
    
    def erase(self, target):
        target.prev.next = target.next
        target.next.prev = target.prev
        
    def push_front(self, target):
        target.prev = self.left
        target.next = self.left.next
        self.left.next.prev = target
        self.left.next = target

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.splice(self.cache[key])
        return self.cache[key].value
        
    def put(self, key: int, value: int) -> None:
        print(len(self.cache))
        if key in self.cache:
            self.cache[key].value = value
            self.splice(self.cache[key])
            return
        if self.capacity == len(self.cache):
            d = self.right.prev
            self.erase(d)
            del self.cache[d.key]
        self.cache[key] = Node(key, value)
        self.push_front(self.cache[key])


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)