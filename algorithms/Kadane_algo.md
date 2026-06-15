KADANE'S ALGORITHM:
Add each element to sum, update answer with max(sum, answer), 
reset sum to 0 if it's negative (as it can't contribute to future maximum).

For example:
indices =  0  1  2  3  4  5  6  7  8
    arr = -2  1 -3  4 -1  2  1 -5  4

    ans = -inf
    sum = 0

    when i = 0 : 
        sum = -2
        ans = -2
        sum = 0

    when i = 1 :
        sum = 1
        ans = 1

        here, maximum sum of subarray is 1
            but, if we had not reset sum to 0, the sum would have been -1
            therefore, resetting sum to 0 is important
    
    when i = 2 :
        sum = -2
        ans = 1
        sum = 0

    when i = 3 :
        sum = 4
        ans = 4
    
    when i = 4 :
        sum = 3
        ans = 4
    
    when i = 5 :
        sum = 5
        ans = 5
    
    when i = 6 :
        sum = 6
        ans = 6
    
    when i = 7 :
        sum = 1
        ans = 6

    when i = 8 :
        sum = 5
        ans = 6
    
    hence, we return ans (which is 6 in this case), and it is the maximum sum of a subarray