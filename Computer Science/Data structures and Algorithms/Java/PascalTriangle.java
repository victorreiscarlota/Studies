
/**
 * Exercise: Given an integer numRows, return the first numRows of Pascal's
 * triangle.
 * 
 * - still can't fully understand the algorithm, feel free to help me understand it with other solutions and/or comments in the code -
 * 
 */
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangulo = new ArrayList<>();
        if (numRows == 0)
            return triangulo;
        List<Integer> primeira_row = new ArrayList<>();
        primeira_row.add(1);
        triangulo.add(primeira_row);

        for (int i = 1; i < numRows; i++) {
            List<Integer> ant_row = triangulo.get(i - 1);
            List<Integer> row = new ArrayList<>();
            row.add(1);
            for (int j = 1; j < i; j++) {
                row.add(ant_row.get(j - 1) + ant_row.get(j));
            }
            row.add(1);
            triangulo.add(row);

        }
        return triangulo;
    }

}
