#
#   Stack : List implementation
#

class Stack:
    def __init__(self):
        self._st = []

    def push(self, data):
        self._st.append(data)

    def top(self):
        return self._st[-1]

    def pop(self):
        self._st.pop()

    def empty(self):
        return self._st == []
