
number_test_cases = int(input())
rectangles_pow_values = [pow(2, i) for i in range(0, 26)]
for test_case in range(number_test_cases):
    line_input = input().split()
    n, w = int(line_input[0]), int(line_input[1])
    i = 1
    rectangles_bucket = [0 for i in range(0 ,26)]
    for i in input().split():
        rectangle_value = int(i)
        rectangles_bucket[rectangles_pow_values.index(rectangle_value)] += 1

    rectangles_left = n
    answer = 1
    while True:
        width = w
        rectangle_pow_position = 25
        while rectangle_pow_position >= 0:
            if rectangles_bucket[rectangle_pow_position] >= 1:
                if rectangles_pow_values[rectangle_pow_position] <= width:
                    width -= rectangles_pow_values[rectangle_pow_position]
                    rectangles_bucket[rectangle_pow_position] -= 1
                    rectangles_left -= 1
                    if rectangles_left == 0:
                        break
                else:
                    rectangle_pow_position -= 1
            else:
                rectangle_pow_position -= 1
        if rectangles_left == 0:
            break
        answer += 1
    print(answer)