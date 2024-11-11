class Solution
{
private:
    int findLowerPrime(const int primes[], int primesCount, int target)
    {
        // std::lower_bound를 이용해 target 이상이 처음 나타나는 위치를 찾음
        auto it = std::lower_bound(primes, primes + primesCount, target);

        // 이진 탐색으로 target이 배열에 존재하는지 확인
        if (it != primes + primesCount && *it == target)
        {
            return *it; // 정확히 일치하는 소수가 있다면 반환
        }

        // target보다 작거나 같은 소수를 찾기 위해 --it
        if (it != primes)
        {
            --it;
        }

        return *it; // 찾은 소수를 반환
    }

public:
    bool primeSubOperation(vector<int>& nums)
    {
        int primes[] = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
            73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
            179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
            283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
            419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
            547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
            661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
            811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
            947, 953, 967, 971, 977, 983, 991, 997
        };

        int past = 0;
        int primesCount = sizeof(primes) / sizeof(primes[0]);

        for (int i = 0; i < nums.size(); ++i)
        {
            int target = nums[i] - past - 1;
            if (target >= 2)
            {
                int prime = findLowerPrime(primes, primesCount, target);
                past = nums[i] - prime;
            }
            else if (past < nums[i])
            {
                past = nums[i];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
