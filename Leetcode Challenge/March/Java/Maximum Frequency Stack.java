class FreqStack {

    Map<Integer, Integer> map;
    PriorityQueue<Tuple> heap;
    int order;
    
    public FreqStack() {
        this.map = new HashMap<>();
        this.heap = new PriorityQueue<>();
        this.order = 0;
    }
    
    public void push(int val) {
        map.put(val, map.getOrDefault(val, 0) + 1);
        heap.add(new Tuple(val, map.get(val), ++order));
    }
    
    public int pop() {
        Tuple tuple = heap.poll();
        int val = tuple.val;
        map.put(val, map.get(val) - 1);
        return val;
    }
}

class Tuple implements Comparable<Tuple> {
    
    Integer val;
    Integer freq;
    Integer order;
    
    Tuple(Integer val, Integer freq, Integer order) {
        this.val = val;
        this.freq = freq;
        this.order = order;
    }
    
    public int compareTo(Tuple other){
        int freqCompare = other.freq.compareTo(this.freq);
        return freqCompare != 0 ? freqCompare : other.order.compareTo(this.order);
    }
}
