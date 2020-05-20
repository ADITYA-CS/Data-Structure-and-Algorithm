#
#   Stack : List implementation
#

import os

class Stack:

    def __init__(self):
        self.st = []
        self.top_ = -1

    def push(self,data):
        self.st.append(data)
        self.top_ += 1

    def top(self):
        try:
            if self.st != []:
                return self.st[self.top_]
        except:
            print("called the top() when stack is empty")
            os.abort()

    def pop(self):
        if self.st != []:
            self.st.pop()

    def empty(self):
        return self.st == []

my_stack = Stack()
my_stack.push(10)
my_stack.push(20)

print("my_stack top() : ", my_stack.top())

my_stack.push(30)
my_stack.push(40)
print("my_stack empty() :", my_stack.empty())
my_stack.pop()
my_stack.push(50)
print("my_stack top() : ", my_stack.top())
