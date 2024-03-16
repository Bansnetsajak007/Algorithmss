def isFull(stack,top):
    if top >= len(stack):
        print("Stack is Full")
        return True
    else:
        return False

def isEmpty(top):
    if top == -1:
        print("Stack is Empty")
        return True
    else:
        return False


def push(stack, value, top):
    if(isFull(stack,top)):
        return
    else:
        top+=1
        stack.append(value)
        return top , stack

def pop(stack,top):
    if(isEmpty(top)):
        return True
    else:
        item = stack.pop()
        top-=1
        return top, stack , item
        
if __name__ == "__main__":
    stack = []
    top = -1
    top, stack = push(stack, 10, top)
    top, stack = push(stack, 3, top)
    top, stack = push(stack, 20, top)
    print("Stack after pushing elements:", stack)
    top, stack, popped_item = pop(stack, top)
    print("Popped item:", popped_item)
    print("Stack after popping element:", stack)
