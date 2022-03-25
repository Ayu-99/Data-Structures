class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, (a, b) -> {
            return (a[0] - a[1]) - (b[0] - b[1]);
        });
        
        int price = 0;
        for(int i = 0; i < costs.length / 2; i++){
            price += costs[i][0];
        }
        for(int i = costs.length / 2; i < costs.length; i++){
            price += costs[i][1];
        }
        return price;
    }
}
