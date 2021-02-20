/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians.
That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

*/


class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        
        
        Map<Integer, Integer> unsortedMap = new HashMap<Integer, Integer>();
        int m = mat.length;
        int n = mat[0].length;
        List<Integer> keys = new ArrayList<Integer>();
        List<Integer> values = new ArrayList<Integer>();
        
        for (int i = 0; i < m; i++)
        {
            int countOnes = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                    countOnes++;
            }
            unsortedMap.put(i, countOnes);
        }
        
        boolean noElements = true;
        for (Map.Entry<Integer, Integer> entry : unsortedMap.entrySet()) 
        {
            //System.out.println(entry.getKey() + "/" + entry.getValue());
            if (noElements == true)
            {
                values.add(entry.getValue());
                keys.add(entry.getKey());
                noElements = false;
            }    
            else
            {
                int toBeInsert = entry.getValue();
                int toBeInsertK = entry.getKey();
                boolean inserted = false;
                int tmpLenght = values.size();
                int tmpInd = 0;
                while (tmpInd < tmpLenght && inserted == false)
                {
                    if (toBeInsert < values.get(tmpInd))
                    {
                        //insert before tmpInd at position tmpInd
                        //insert in keys too
                        values.add(tmpInd, toBeInsert);
                        keys.add(tmpInd, toBeInsertK);
                        inserted = true;    
                    }
                    
                    tmpInd++;
                }
                
                if (inserted == false)
                {
                    // insert in the last position of the list that is tmpInd
                    values.add(tmpInd, toBeInsert);
                    keys.add(tmpInd, toBeInsertK);
                }
            }
        }

        
        
        // return the first k elements in keys
        return keys.subList(0, k).stream().mapToInt(i->i).toArray();
        
        
    }
}
