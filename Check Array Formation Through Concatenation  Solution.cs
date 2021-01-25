/*
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct.
Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.
*/


public class Solution {
    
    // Variables declared outside so that they don't have to be creatged for each recursive execution
    /*
    private Dictionary<int, int[]> association = new Dictionary<int, int[]>();
    private List<int> values = new List<int>();
    private List<int> marked = new List<int>();
    private List<int> solution = new List<int>();
    private int arrDim;
    */
    
    public bool CanFormArray(int[] arr, int[][] pieces) {
        
        // A is arr
        int indA = 0;
        int countEq = 0;
        foreach (int v in arr)
        {
            if (indA < arr.Length && v == arr[indA])
            {
                int found = 0;
                //Console.WriteLine("Value in arr " + v);
                foreach (int[] p in pieces)
                {
                    //Console.WriteLine("First value in p " + p[0]);
                    if (p[0] == v)
                    {
                        countEq++;
                        found = 1;
                        int ind, i;
                        for (i = 1, ind = indA + 1; i < p.Length; i++, ind++) // i index on p
                        {
                            //Console.WriteLine("Val in arr e in p " + arr[ind] + "  " + p[i]);
                            if (arr[ind] != p[i])
                            {    
                                return false;
                            }
                            else
                                countEq++;
                        }
                        indA = ind;
                        break; // go to the next value in arr
                    }
                }
                if (found == 0)
                    return false;
            }
            
            if(indA >= arr.Length && countEq == arr.Length)
                return true;
        }
         return true;
    }
    
    
   
    
    
    
    
}
