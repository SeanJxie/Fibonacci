import random

"""YES it is UberSeal from reddit."""

computed = [0, 1]

'''Implement the Fermat Prime Test'''
def FermatPrimeTest(number):
    ''' if number != 1 '''
    if (number > 1):
        ''' repeat the test few times '''
        for time in range(3):
            ''' Draw a RANDOM number in range of number ( Z_number )  '''
            randomNumber = random.randint(2, number) - 1
            
            ''' Test if a^(n-1) = 1 mod n '''
            if (pow(randomNumber, number - 1, number) != 1):
                return False
        
        return True
    else:
        ''' case number == 1 '''
        return False  
            
    return True


'''Calculate the fibonacci seqeunce'''
def fibPrimes(n):
    for i in range(n):
        curr = computed[i] + computed[i + 1]
        computed.append(curr)

        if FermatPrimeTest(curr):
            print('p:', curr, 'n:', i + 2, '\n')


fibPrimes(n=1000000)
