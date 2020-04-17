
def get_overlap(ll):
    found = False
    result = []
    ll.sort(key=lambda r: r[0])
    for r1, r2 in zip(ll[:-1], ll[1:]):
        if r1[1] >= r2[0]:
            if found:
                result.append(r2)
            else:
                result.extend([r1, r2])
            found = True
        else:
            found = False
    return result


def main():
    cases = {
        'case1': {
            'input': [[4, 8], [7, 9], [10, 16], [6, 8]],
            'output': [[4, 8], [7, 9], [6, 8]]
        },
        'case2': {
            'input': [[4, 8], [4, 8], [4, 9], [4, 8]],
            'output': [[4, 8], [4, 8], [4, 9], [4, 8]],
        },
    }

    for name, case in cases.iteritems():
        output = get_overlap(case['input'])
        output.sort(key=lambda r: r[0])
        case['output'].sort(key=lambda r: r[0])
        success = output == case['output']
        print name
        print 'Input: {}'.format(case['input'])
        print 'Expected output: {}'.format(case['output'])
        print 'Actual output: {}'.format(output)
        print 'Result: {}'.format('Success' if success else 'Failed')


if __name__ == '__main__':
    main()
