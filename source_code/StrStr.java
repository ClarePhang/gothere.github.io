/* 
* @Author: Beinan
* @Date:   2015-01-08 18:04:08
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-08 19:36:38
*/

public class StrStr {

    /**
     * @param   source      the string being searched.
     * @param   target      the substring to search for
     * @return  the index of the first occurrence of the specified substring,
     *          starting at the specified index,
     *          or {@code -1} if there is no such occurrence.
     */
    public static int strStr(String source, String target){
      int max = source.length() - target.length();
      for(int i = 0; i <= max; i++){
        int matched_count = 0;
        for(/*nothing*/; 
          matched_count < target.length() 
          && source.charAt(i + matched_count) == target.charAt(matched_count); 
          matched_count++);
        if(matched_count == target.length())
          return i; //matched  

      }
      return -1;
    }
    
    //test script
    public static void main(String[] args) {
      System.out.println(strStr("abcde", "cde"));
      System.out.println(strStr("abcde", "cdef"));
      System.out.println(strStr("abcde", ""));
      System.out.println(strStr("", ""));
                    
    }


}