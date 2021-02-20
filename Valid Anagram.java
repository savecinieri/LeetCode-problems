/*
Given two strings s and t , write a function to determine if t is an anagram of s.
*/

class Solution {
    
    
    public boolean isAnagram(String s, String t) {
        
        boolean result = true;
        //ArrayList<Integer> taken = new ArrayList<Integer>();
        
        //if (s.length() != t.length())
        //    return false;
        
        /*int size = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //char c = s.charAt(i); 
            size++;
            taken.add(0);
        }*/          
    
        String tmpString = s.substring(0, s.length());
        int sSize = s.length();
        int sSizeCopy = sSize;
        int count = 0;
        for (int i = 0; i < t.length(); i++)
        {
            boolean foundChar = false;
            for (int j = 0; j < sSize; j++) // USE SUBSTRING INSIDE THE FOLLOWING FOR
            {
                if (t.charAt(i) == tmpString.charAt(j)/*s.charAt(j) && taken.get(j) == 0*/)
                {
                    //taken.set(j, 1);
                    foundChar = true;
                    count++;
                    
                    if ( j == 0 && tmpString.length() > 1) 
                        tmpString =  tmpString.substring(1, tmpString.length());
                    //else if ( j == 0 && tmpString.length() == 1) 
                    //    tmpString =  tmpString.substring(1, tmpString.length());
                    else if(j == tmpString.length() - 1 && tmpString.length() > 1) 
                        tmpString = tmpString.substring(0, tmpString.length()-1);
                    else
                    {
                        tmpString = tmpString.substring(0, j) + tmpString.substring(j + 1, tmpString.length());
                    }
                    sSize--;
                    break;
                }   
            }  
            if (foundChar == false)
               return false;
        } 
           
        if (count != sSizeCopy/*size*/)
            return false;
        
        return result;
    }
}
 
