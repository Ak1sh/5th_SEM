combinations = [(True,True, True), (True,True,False),(True,False,True),(True,False, False),
                (False,True, True),(False,True, False),(False, False,True),(False,False, False)]
variable = {'p': 0,'q': 1, 'r': 2}
kb = ''           
q = ''
priority = {'~': 3, 'v': 1, '^': 2} 

def input_rules():
    global kb, q
    kb = (input("Enter rule: "))
    q = input("Enter the Query: ")

def entailment(): 
    global kb, q 
    print("TRUTH TABLE REFERENCE")
    print('kb','alpha')
    print('*'*10)
    for comb in combinations:
        s = evaluatePostfix(InfixtoPostfix(kb), comb)
        f = evaluatePostfix(InfixtoPostfix(q), comb)
        print(s, f) 
        print('-'*10) 
        if s and not f:
            return False
    return True

def isOperand(c):
    return c.isalpha() and c!='v' 

def isLeftParanthesis(c):
    return c == '(' 

def isRightParanthesis(c):
    return c == ')'

def isEmpty(stack): 
    return len(stack) == 0

def peek(stack):
    return stack[-1] 

def Prioritycheck(b1, b2):
    try:
        return priority[b1]<=priority[b2]
    except KeyError:
        return False


def InfixtoPostfix(infix):
    stack = [] 
    postfix = ''
    for c in infix:
        if isOperand(c):
            postfix += c
        else:
            if isLeftParanthesis(c):
                stack.append(c)
            elif isRightParanthesis(c):
                operator = stack.pop()
                while not isLeftParanthesis(operator):
                    postfix += operator
                    operator = stack.pop()
            else:
                while (not isEmpty(stack)) and Prioritycheck(c, peek(stack)):
                    postfix += stack.pop()
                stack.append(c)
    while (not isEmpty(stack)):
        postfix += stack.pop()

    return postfix

def evaluatePostfix(exp, comb):
    stack = [] 
    for i in exp:
        if isOperand(i):
            stack.append(comb[variable[i]])
        elif i == '~':
            val1 = stack.pop() 
            stack.append(not val1)
        else:
            val1 = stack.pop() 
            val2 = stack.pop()
            stack.append(_eval(i,val2,val1))
    return stack.pop()


def _eval(i, val1, val2):
    if i == '^': 
        return val2 and val1      
    return val2 or val1


input_rules()
ans = entailment()
if ans: 
    print("The Knowledge Base entails query")
else:
    print("The Knowledge Base does not entail query")




'''

#Output
Enter rule: (~pvq)^(q^r)
Enter the Query: q
TRUTH TABLE REFERENCE
kb alpha
**********
True True
----------
False True
----------
False False
----------
False False
----------
True True
----------
False True
----------
False False
----------
False False
----------
The Knowledge Base entails query

'''
