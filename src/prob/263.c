bool isUgly(int num)
{
    int primes[] = {2, 3, 5};
    for (int i = 0; i < 3; ++i){
        if (num == 1)
            return true;
        while (num > 1)
            if (num % primes[i] == 0)
                num /= primes[i];
            else
                if (num == 1)
                    return true;
                else
                    break; 
    }
    if (num == 1)
        return true;
    else
        return false;
}
