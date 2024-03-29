class CircularQueue:
  """
  A class implementing a circular queue using a list.
  """

  def __init__(self, size):
    """
    Initializes the circular queue with a specified size.
    """
    self.size = size
    self.queue = [None] * size
    self.front = self.rear = -1

  def is_empty(self):
    """
    Checks if the queue is empty.
    """
    return self.front == -1

  def is_full(self):
    """
    Checks if the queue is full.
    """
    return (self.rear + 1) % self.size == self.front

  def enqueue(self, data):
    """
    Inserts an element into the queue.
    """
    if self.is_full():
      print("Queue Overflow")
      return
    # Handle the first element being added
    elif self.front == -1:
      self.front = 0
    self.rear = (self.rear + 1) % self.size
    self.queue[self.rear] = data

  def dequeue(self):
    """
    Removes and returns the element from the front of the queue.
    """
    if self.is_empty():
      print("Queue Underflow")
      return None
    data = self.queue[self.front]
    if self.front == self.rear:
      # Reset front and rear if only one element was present
      self.front = self.rear = -1
    else:
      self.front = (self.front + 1) % self.size
    return data

# Example usage
my_queue = CircularQueue(5)
my_queue.enqueue(10)
my_queue.enqueue(20)
my_queue.enqueue(30)

print(my_queue.dequeue())  # Output: 10
print(my_queue.dequeue())  # Output: 20
