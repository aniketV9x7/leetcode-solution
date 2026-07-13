class Solution:
    def sequentialDigits(self, low: int, high: int) -> list[int]:
        result = []
        digits = "123456789"
        for length in range(2, 10):
            for start in range(10 - length):
                num = int(digits[start:start + length])
                if low <= num <= high:
                    result.append(num)

        return result