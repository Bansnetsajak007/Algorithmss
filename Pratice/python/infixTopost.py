
precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '$': 3}

def is_operator(c):
    return c in precedence

def infix_to_postfix(expression):
    stack = []  # holds the operators
    output = []  # final output list

    for char in expression:
        if char.isalnum():
            output.append(char)
        elif char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()  # pop the '('
        else:
            while stack and stack[-1] != '(' and precedence[char] <= precedence[stack[-1]]:
                output.append(stack.pop())
            stack.append(char)

    while stack:
        output.append(stack.pop())
    
    return ''.join(output)  # converting to string

expression_ = "((A-(B+C))*D)$(E+F)"
print("Infix Expression:", expression_)
print("Postfix Expression:", infix_to_postfix(expression_))
