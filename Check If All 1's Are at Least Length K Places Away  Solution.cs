/*
Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.
*/


public class Solution {
    public bool KLengthApart(int[] nums, int k) {
        
        bool valid = true;
        for (int i = 0; i < nums.Length; )
        {
            if (i == nums.Length - 1)
                break;
            if (nums[i] == 1)
            {
                //Console.WriteLine("Current element " + nums[i] + "   -   " + i);
                int posDiff = 0;
                bool newI = false;
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[j] == 1)
                    {
                        //Console.WriteLine("Found " + nums[j] + "   -   " + j);
                        if (posDiff < k)
                        {
                            //Console.WriteLine("NOT VALID: " + posDiff + " with at least " + k);
                            valid = false;
                        }
                        else
                        {
                            //Console.WriteLine("VALID: " + posDiff + " with at least " + k);
                            newI = true;
                            i = j;
                        }
                        
                        break;
                    }
                    else
                        posDiff++;
                } // END INTERNAL FOR
                
                if (valid == false)
                    break;
                
                if (newI == false)
                    i++;
            } // END IF 
            else
                i++;
        } // END EXTERNAL FOR
        
        return valid;
    }
}
