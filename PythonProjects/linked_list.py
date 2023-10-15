class LinkedNode(object):

    def __init__(self, data=None):
        self.data = data
        self.next = None

    def __str__(self):
        return str(self.data)


class LinkedList(object):

    def __init__(self, head=None):
        self.head = head

    def __str__(self):
        node = self.head
        connector = ' -> '
        s = ''
        if node is None:
            return 'Empty List'
        while node.next is not None:
            if type(node.data) is LinkedList:
                var = '[' + str(node.data) + ']'
                s += var + connector
            else:
                s += str(node.data) + connector
            node = node.next
        if type(node.data) is LinkedList:
            var = '[' + str(node.data) + ']'
            s += var
        else:
            s += str(node.data)
        return s

    # fill an empty list with a list of element
    def fill(self, element_list: list):
        if self.head is None:
            self.head = LinkedNode(element_list[0])
            var_node = self.head
            for element in element_list[1:]:
                temp_node = LinkedNode(element)
                var_node.next = temp_node
                var_node = var_node.next
        else:
            raise IndexError

    # append any element to the last element of the list
    def append(self, other):
        if type(other) is not LinkedNode:
            node = LinkedNode(other)
        else:
            node = other
        if self.head is None:
            self.head = node
        else:
            var_node = self.head
            while var_node.next is not None:
                var_node = var_node.next
            var_node.next = node

    # remove and return the first element of the list
    def pop(self):
        if self.head is None:
            raise IndexError
        data = self.head.data
        self.head.next = self.head
        return data



