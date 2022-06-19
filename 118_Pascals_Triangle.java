public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        for (int i = 0; i < numRows; i++) {
            List<Integer> list = new ArrayList<Integer>(Arrays.asList(1));
            
            for (int j = 1; j < i; j++) 
                list.add(res.get(i - 1).get(j - 1) + res.get(i - 1).get(j));
                
            if (i > 0) list.add(1);
            
            res.add(list);
        }
        
        return res;
    }
}