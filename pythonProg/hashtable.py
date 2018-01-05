class HashTable(object):
    def __init__(self) :
        self.table = []
        
    def insert(self, key, val):
        if self.table[key] is None:
            self.table[key] = val
        else:
            if type(self.table[key]) == list:
                self.table[key].append(val)
            else:
                self.table[key] = [self.table[key], val]
        
    def lookup(self, key):
        if type(self.table[key]) == list:
            for l in self.table[key]:
                if l == val:
                    return val
            
            return -1
        else:
            return self.table[key]
        
        
    
    
  