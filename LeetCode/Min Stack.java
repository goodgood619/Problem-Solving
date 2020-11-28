class MinStack {
    Deque<Integer> stack;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new ArrayDeque<>();
    }
    
    public void push(int x) {
        stack.add(x);
    }
    
    public void pop() {
        stack.pollLast();
    }
    
    public int top() {
        return stack.peekLast();
    }
    
    public int getMin() {
        int min = Integer.MAX_VALUE;
        Deque<Integer> temp = new ArrayDeque<>(stack);
        while(!temp.isEmpty()) {
            if(min>temp.peekLast()) {
                min = temp.peekLast();
            }
            temp.pollLast();
        }
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */