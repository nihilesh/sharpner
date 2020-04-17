# Given a string with various open and closing parentheses/brackets, validate that a given string is complete.
# Example brackets/parentheses: {, }, [, ], (, ), <, >
from itertools import chain

C_PARENTHESES = {
    '}': '{',
    ']': '[',
    ')': '(',
    '>': '<'
}

O_PARENTHESES = {
    val: key for key, val in C_PARENTHESES.iteritems()
}


def is_complete(str_):
    stk = []
    for c in str_:
        if O_PARENTHESES.get(c):
            stk.append(c)
        elif C_PARENTHESES.get(c):
            if not stk:
                return False
            if stk[-1] != C_PARENTHESES[c]:
                return False
            stk.pop(-1)
    return not stk


def main():
    cases = {
        'case1': {
            'input': ' {, }, [, ], (, ), <, >',
            'output': True
        },
        'case2': {
            'input': ' {(, ), <, >',
            'output': False
        },
        'case3': {
            'input': ' {(}), <, >',
            'output': False
        },
        'case4': {
            'input': ' {dfasdf}()({({({})})}), <, >',
            'output': True
        },
    }
    for name, case in cases.iteritems():
        output = is_complete(case['input'])
        print name
        print 'Input: {}'.format(case['input'])
        print 'ExpetedOutput: {}'.format(case['output'])
        print 'Actual Output: {}'.format(output)
        print 'Result: {}'.format(
            'Success' if output == case['output'] else 'Fail')


if __name__ == '__main__':
    main()
