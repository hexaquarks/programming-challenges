impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut res = vec![1; n];
       
        let mut acc = 1;
        for i in (0..n) {
            res[i] = acc;
            acc *= nums[i];
        }

        acc = 1;
        for i in (0..n).rev() {
            res[i] *= acc;
            acc *= nums[i];
        }

        res
    }
}

