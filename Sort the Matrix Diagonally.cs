/*
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the
matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
*/


public class Solution {
    public int[][] DiagonalSort(int[][] mat) {
        Dictionary<int, List<int>> reverseindVals = new Dictionary<int, List<int>>();
        
        int i;
        int j;
        int k;

        int columnSize = mat[0].GetLength(0);
        int rowSize = mat.GetLength(0);
        int[][] result = new int[rowSize][];
        for (i = 0; i < rowSize; i++)
            result[i] = new int[columnSize];

        // xy
        // **
        // ogni volta che inserisco un valore lo inserisco nella giusta posizione ed evito quindi di fare il .Sort
        // ** ** //
        
        // prima per le colonne
        for (j = 0; j < columnSize; j++) // 0 1 ... column-1
        {
            k = j;
            int start = 1;
            for (i = 0; i < rowSize && k < columnSize; i++, k++)
            {
                if (start == 1)
                {
                    start = 0;
                    reverseindVals[i - k] = new List<int>();
                }
                
                //InsertElementAscending(reverseindVals[i - k], mat[i][k]); //xy
                reverseindVals[i - k].Add(mat[i][k]); //xy
            }
            reverseindVals[i - k].Sort(); //xy
        }
        
        
        // poi per le righe
        for (j = 1; j < rowSize; j++) // 0 1 ... column-1
        {
            k = j;
            int start = 1;
            for (i = 0; k < rowSize && i < columnSize; i++, k++)
            {
                if (start == 1)
                {
                    start = 0;
                    reverseindVals[k - i] = new List<int>();
                }
                
                //InsertElementAscending(reverseindVals[k - i], mat[k][i]); 
                reverseindVals[k - i].Add(mat[k][i]); //xy
            }
            reverseindVals[k - i].Sort();  //xy
        }

        
        
        
        
        for (j = 0; j < columnSize; j++) // 0 1 ... column-1
        {
            k = j;
            int useThis = 0 - k; // per accedere al dizionario
            int indexInList = 0; // per accedere ai valori del dizionario
            List<int> tmpList = reverseindVals[useThis]; 
            for (i = 0; i < rowSize && k < columnSize; i++, k++)
            {
                result[i][k] = tmpList[indexInList];
                indexInList++;
            }
        }
        
        for (j = 1; j < rowSize; j++) // 0 1 ... column-1
        {
            k = j;
            int useThis = k; // per accedere al dizionario
            int indexInList = 0; // per accedere ai valori del dizionario
            List<int> tmpList = reverseindVals[useThis];
            for (i = 0; k < rowSize && i < columnSize; i++, k++)
            {
                result[k][i] = tmpList[indexInList];
                indexInList++;
            }
        }

        
        
        
        // stampo il dizionario
        /*
        foreach (KeyValuePair<int, List<int>> kvp in reverseindVals)
        {
            Console.WriteLine("Key = {0}", kvp.Key);
            foreach (var val in kvp.Value)
            {    
                Console.WriteLine(val);
            }
            Console.WriteLine("-----------------------------");
        }
        */
        
        //stampo la nuova matrice
        /*
        Console.WriteLine("-----------------------------");
        Console.WriteLine("-----------------------------");
        for (i = 0; i < rowSize; i++)
        {
            for (j = 0; j < columnSize; j++)
            {
                Console.Write(result[i, j] + "  ");
            }
            Console.WriteLine("-----------------------------");
        }
        */
        
        
        return result;
    }
    
    
    //////////
    
    public static void InsertElementAscending(List<int> source, int element)
    {
        /////  1 2 4 5 6
        int insertHere = 0;
        bool flag = false;
        int i;
        for (i = 0; i < source.Count; i++)
        {
            if (element <= source[i])
            {
                insertHere = i;
                flag = true;
                break;
            }   
        }
        if (flag == false && i != 0)
            insertHere = source.Count;
        source.Insert(insertHere, element);
        return;  
    }
    
    /////////
}
