queue = {
    "back" : -1,
    "front" : -1,
    "size" : 4,
    "arr" : [],
}

def isEmpty(queue):
    if(queue['front'] == queue['back']):
        return True
    else:
        return False
    
def isFull(queue):
    if(queue['back'] == queue['size'] - 1):
        return True
    else:
        return False

def enqueue(queue, value):
    if(not isFull(queue)):
        queue['back'] += 1
        queue['arr'].append(value)
        print(f"The enqueued element is: {value}")

    else:
        print("Queue is full")

def dequeue(queue):
    removedVal = None
    if(not isEmpty(queue)):
        queue['front'] + 1
        removedVal=  queue['arr'].pop(0)
        print(f"The dequeued element is: {removedVal}")
    else:
        print("Cannot dequeue element form and empty queue")


if __name__ == "__main__":
    enqueue(queue, 10)
    enqueue(queue, 20)
    enqueue(queue, 30)
    enqueue(queue, 40)
    dequeue(queue)

    print(queue['arr'])


    
