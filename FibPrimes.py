import random

computed = [0, 1]

'''Implement the Fermat Prime Test'''
def FermatPrimeTest(number):
    if (number > 1):
        for _ in range(3):
            randomNumber = random.randint(2, number) - 1
            if (pow(randomNumber, number - 1, number) != 1):
                return False
        return True
    else:
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
