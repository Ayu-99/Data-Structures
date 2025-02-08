class NumberContainers {

    Map<Integer, PriorityQueue<Integer>> numberToIndex;
    Map<Integer, Integer> indexToNumber;
    public NumberContainers() {
        numberToIndex = new HashMap<>();
        indexToNumber = new HashMap<>();
    }
    
    public void change(int index, int number) {
        indexToNumber.put(index, number);
        if(!numberToIndex.containsKey(number)) {
            numberToIndex.put(number, new PriorityQueue<>());
        }
        numberToIndex.get(number).add(index);
    }
    
    public int find(int number) {
        if(!numberToIndex.containsKey(number)) {
            return -1;
        }
         PriorityQueue<Integer> minHeap = numberToIndex.get(number);
         while (!minHeap.isEmpty()) {
            int index = minHeap.peek();
            if (indexToNumber.get(index) == number) {
                return index;
            }
            minHeap.poll();
         }
         return -1;
    }
}

// class NumberContainers {

//     Map<Integer, TreeSet<Integer>> numberToIndex;
//     Map<Integer, Integer> indexToNumber;
//     public NumberContainers() {
//         numberToIndex = new HashMap<>();
//         indexToNumber = new HashMap<>();
//     }
    
//     public void change(int index, int number) {
//         if(indexToNumber.containsKey(index)) {
//             int prevNumber = indexToNumber.get(index);
//             numberToIndex.get(prevNumber).remove(index);
//             if (numberToIndex.get(prevNumber).isEmpty()) {
//                 numberToIndex.remove(prevNumber);
//             }
//         } 
//         indexToNumber.put(index, number);
//         numberToIndex.putIfAbsent(number, new TreeSet<>());
//         numberToIndex.get(number).add(index);
//     }
    
//     public int find(int number) {
//         if (numberToIndex.containsKey(number)) {
//             int index = numberToIndex.get(number).first();
//             return index;
//         }
//         return -1;
//     }
// }

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */
