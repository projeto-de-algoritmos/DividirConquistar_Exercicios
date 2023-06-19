class Solution {
    public String multiply(String num1, String num2) {
        char[] ch1 = num1.toCharArray();
        char[] ch2 = num2.toCharArray();
        int l1 = ch1.length, l2 = ch2.length;
        char[] ans = new char[l1 + l2];
        Arrays.fill(ans, '0');
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                int mul = (ch1[i] - '0') * (ch2[j] - '0');
                int temp = ans[i + j + 1] - '0' + mul;
                ans[i + j + 1] = (char) (temp % 10 + '0');
                ans[i + j] = (char) ((ans[i + j] - '0' + temp / 10) + '0');
            }
        }
        StringBuilder s = new StringBuilder();
        boolean check = false;
        for (char c : ans) {
            if (c == '0' && !check) {
                continue;
            }
            s.append(c);
            check = true;
        }
        return s.length() == 0 ? "0" : s.toString();
    }
}
