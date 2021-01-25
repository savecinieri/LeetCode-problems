/*
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n),
either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

*/


class Solution {
public:
    
    vector<int> values;
    vector<int> solution;
    vector<int> marked;
    int N;
    
    int countArrangement(int n) {
        N = n;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
           values.push_back(i + 1); 
           marked.push_back(0);
           solution.push_back(-1); 
        }
        
        /*
        for (int i = 0; i < n; i++)
        {
           std::cout << values[i] << "\n"; 
        }
        */
        f(&result, 0);
        
        return result;
    }
    
    
    void f(int* res, int ind)
    {
        if (ind >= N)
        {
            
            // evaluate sol
            /*
            int valid = 1;
            for (int i = 0; i < N; i++)
            {
                // position i + 1
                // sol[i]
                if (solution[i] % (i + 1) == 0)
                {
                    // OK
                    continue;
                }
                else if (solution[i] % (i + 1) != 0 && ((i + 1) % solution[i] == 0))
                {
                    // OK
                    continue;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            
            if (valid == 1)
                (*res)++;
            */
            
            if (solution[ind - 1] % ind != 0)
            {   
                if (ind % solution[ind - 1] != 0)
                {
                   return;
                }
                else
                   (*res)++; 
            }  
            else
                (*res)++;
            return;
        }
        
        // check the previous move
        if (ind >= 1 && (solution[ind - 1] % ind) != 0)
        {   
            if (ind >= 1 && ind % solution[ind - 1] != 0)
            {
               return;
            }
        }  
        
        for (int i = 0; i < N; i++)
        {
            if (marked[i] == 0)
            { 
                marked[i] = 1;
                solution[ind] = values[i];
                f(res, ind + 1);
                marked[i] = 0;
            }
        }
    }
    
    
    
    
    
    
};
