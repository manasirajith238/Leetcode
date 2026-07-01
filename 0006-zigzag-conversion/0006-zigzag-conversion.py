class Solution(object):
    def convert(self, s, numRows):
    
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [""] * numRows

        currRow = 0
        goingDown = False

        for ch in s:

            rows[currRow] += ch

            # Change direction at the top or bottom
            if currRow == 0 or currRow == numRows - 1:
                goingDown = not goingDown

            # Move to the next row
            if goingDown:
                currRow += 1
            else:
                currRow -= 1

        return "".join(rows)