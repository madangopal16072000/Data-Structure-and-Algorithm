class Solution {
    public int findValidSplit(int[] nums) {
        
        BigInteger totProd, lProd;
        totProd = BigInteger.ONE;
        lProd = BigInteger.ONE;
        
        for(int x : nums)
        {
            BigInteger a = BigInteger.valueOf(x);
            totProd = totProd.mulitply(a);
        }
        
        int n = nums.length;
        for(int i = 0; i <= n-2; i++)
        {
            BigInteger a = BigInteger.valueOf(nums[i]);
            lProd = lProd.multiply(a);
            
            BigInteger b = totProd.divide(lProd);
            
            BigInteger x = lProd.gcd(b);
            
            String val = x.toString();
            
            if(val == "1")
                return i;
        }
        
        return -1;
    }
        public static void main(String args[]) throws Exception
    {
        int nums[] = {4 7 15 8 3 5};
    }
}

