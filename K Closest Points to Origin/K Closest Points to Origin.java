import java.util.PriorityQueue;

class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> closestPoints = new PriorityQueue<>((p1, p2) ->
            (p2[0] * p2[0] + p2[1] * p2[1]) - (p1[0] * p1[0] + p1[1] * p1[1])
        );
        
        for (int[] point : points) {
            closestPoints.offer(point);
            
            if (closestPoints.size() > k) {
                closestPoints.poll();
            }
        }
        
        int[][] result = new int[k][2];
        int index = k - 1;
        
        while (index >= 0) {
            result[index--] = closestPoints.poll();
        }
        
        return result;
    }
}
